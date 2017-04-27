#include "Sprawdzanie_hasla.h"
#include "uzytkownicy.h"
#include "Edycja_uzytkownika.h"
#include <wx/msgdlg.h>

/*!
*uzytkownicy - zmnienna w ktorej przechowywane sa dane o uzytkownikach programu.
*Poczatkowo jest ona pusta.
*Dane w niej sa dodawane w sposob dynamiczny, korzysta ona z odpowiednio przygotowanej funckji.
*Jest to odwolanie do deklaracji znajdujacej sie w innym pliku.
*/
extern struct uzytkownik *uzytkownicy;
/*!
*Zmienna w ktorej przechowywany jest adres aktualnie edytowanego uzytkownika.
*Jest to odwolanie do deklaracji znajdujacej sie w innym pliku.
*/
extern struct uzytkownik *sprawdzany;
/*!
*Zmienna w ktorej przechowywane bedzie wprowadzane haslo uzytkownika.
*/
string *sprawdzane_haslo=new string;
/*!
*Zmienna w ktorej zapisana jest informacja o tym czy po wpisaniu poprawnego hasla program ma przekazac sterowanie do edytowania
*uzytkownika czy do jego usuwania.
*/
extern int edytowanie_usuwanie_uzytkownika;
/*!
*Zmienna w ktorej zapisany jest numer ID aktualnie uzywanego uzytkownika.
*Jest to odwolanie do deklaracji znajdujacej sie w innym pliku.
*/
extern int szukane_u;

using namespace std;

//(*InternalHeaders(Sprawdzanie_hasla)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(Sprawdzanie_hasla)
const long Sprawdzanie_hasla::ID_TEXTCTRL1 = wxNewId();
const long Sprawdzanie_hasla::ID_STATICTEXT1 = wxNewId();
const long Sprawdzanie_hasla::ID_BUTTON1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(Sprawdzanie_hasla,wxDialog)
	//(*EventTable(Sprawdzanie_hasla)
	//*)
END_EVENT_TABLE()

Sprawdzanie_hasla::Sprawdzanie_hasla(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(Sprawdzanie_hasla)
	wxBoxSizer* BoxSizer1;
	wxStaticBoxSizer* StaticBoxSizer1;

	Create(parent, wxID_ANY, _("Wprowadz Haslo"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("wxID_ANY"));
	BoxSizer1 = new wxBoxSizer(wxVERTICAL);
	StaticBoxSizer1 = new wxStaticBoxSizer(wxVERTICAL, this, _("Podaj Haslo"));
	TextCtrl1 = new wxTextCtrl(this, ID_TEXTCTRL1, wxEmptyString, wxDefaultPosition, wxSize(400,35), wxTE_PASSWORD, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	StaticBoxSizer1->Add(TextCtrl1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Podaj Haslo aby dokonac zmian"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	StaticBoxSizer1->Add(StaticText1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(StaticBoxSizer1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Button1 = new wxButton(this, ID_BUTTON1, _("OK"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	BoxSizer1->Add(Button1, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	SetSizer(BoxSizer1);
	BoxSizer1->Fit(this);
	BoxSizer1->SetSizeHints(this);

	Connect(ID_TEXTCTRL1,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&Sprawdzanie_hasla::OnTextCtrl1Text_wprowadz_haslo);
	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Sprawdzanie_hasla::OnTextCtrl1Text_sprawdz_haslo);
	//*)
}

Sprawdzanie_hasla::~Sprawdzanie_hasla()
{
	//(*Destroy(Sprawdzanie_hasla)
	//*)
}

/*!
*Funkcja ktora reaguje na wcisniecie przycisku "OK".
*Funkcja poczatkowo sprawdza czy zostalo podane haslo, nastepnie sprawdza czy podane haslo jest takie samo jak w wybranym
*uzytkowniku.
*Nastepnie zaleznie od przekazanej wartosci w zmiennej edytowanie_usuwanie_uzytkownika jest tworzone okno edycji uzytkownika
*badz okno usuwania uzytkownika.
*/
void Sprawdzanie_hasla::OnTextCtrl1Text_sprawdz_haslo(wxCommandEvent& event)
{
    if(*sprawdzane_haslo==""){
        int Okno_bledu_pustego_hasla = wxMessageBox("Musisz podac haslo","Blad", wxYES_DEFAULT | wxICON_WARNING);
        if(Okno_bledu_pustego_hasla == wxYES)
                ;
    }else{
        if(*sprawdzane_haslo!=sprawdzany->haslo){
            StaticText1->SetLabel("Niepoprawne Haslo!");
        }else{
            if(edytowanie_usuwanie_uzytkownika==1){
                int Okno_edycji = wxMessageBox("Edytowac wybranego Uzytkownika?","Edytowanie", wxYES_NO | wxICON_QUESTION);
                if(Okno_edycji == wxYES){
                    Edycja_uzytkownika *okno_edycji_uzytkownika=new Edycja_uzytkownika(this);
                    okno_edycji_uzytkownika->ShowModal();
                    free(sprawdzane_haslo);
                    EndModal(0);
                }
            }if(edytowanie_usuwanie_uzytkownika==2){
                int Okno_usuwania = wxMessageBox("Usunac wybranego Uzytkownika?","Usuwanie", wxYES_NO | wxICON_QUESTION);
                if(Okno_usuwania == wxYES){
                    //string nazwa_pliku2=;
                    uzytkownicy=usuwanie(uzytkownicy,szukane_u,sprawdzany->nazwa+to_string(sprawdzany->id));
                    int blad=zapisywanie_do_pliku(uzytkownicy);
                    if(blad==-1){
                        int Okno_bledu = wxMessageBox("Blad otwarcia pliku z do zapisu","Blad", wxYES_DEFAULT | wxICON_ERROR);
                        if(Okno_bledu == wxYES)
                            ;
                    }
                    free(sprawdzane_haslo);
                    EndModal(0);
                }
            }
        }
    }
}

/*!
*Funkcja zczytuje wpisane dane w polu tekstowym TextCtrl1 do zmiennej wxstr ktorej wartosc jest przypisywana do zmiennej
*sprawdzane_haslo za pomoca funkcji do konwersji ToStdString().
*/
void Sprawdzanie_hasla::OnTextCtrl1Text_wprowadz_haslo(wxCommandEvent& event)
{
    StaticText1->SetLabel("Podaj Haslo aby dokonac zmian");
    wxString wxstr=event.GetString();
    *sprawdzane_haslo=wxstr.ToStdString();
}
