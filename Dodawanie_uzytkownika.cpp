#include "Dodawanie_uzytkownika.h"
#include "uzytkownicy.h"
#include <wx/msgdlg.h>

/*!
*jeden_uzytkownik - zmienna wskznikowa ktora przechowuje informajce o pojedynczym uzytkowniku uzywanym w danym momencie
*/
struct uzytkownik *jeden_uzytkownik=new uzytkownik;
/*!
*uzytkownicy - zmnienna w ktorej przechowywane sa dane o uzytkownikach programu.
*Poczatkowo jest ona pusta.
*Dane w niej sa dodawane w sposob dynamiczny, korzysta ona z odpowiednio przygotowanej funckji.
*Jest to odwolanie do deklaracji znajdujacej sie w innym pliku.
*/
extern struct uzytkownik *uzytkownicy;

//(*InternalHeaders(Dodawanie_uzytkownika)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(Dodawanie_uzytkownika)
const long Dodawanie_uzytkownika::ID_TEXTCTRL1 = wxNewId();
const long Dodawanie_uzytkownika::ID_TEXTCTRL2 = wxNewId();
const long Dodawanie_uzytkownika::ID_BUTTON1 = wxNewId();
const long Dodawanie_uzytkownika::ID_BUTTON2 = wxNewId();
//*)

BEGIN_EVENT_TABLE(Dodawanie_uzytkownika,wxDialog)
	//(*EventTable(Dodawanie_uzytkownika)
	//*)
END_EVENT_TABLE()

Dodawanie_uzytkownika::Dodawanie_uzytkownika(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(Dodawanie_uzytkownika)
	wxStaticBoxSizer* StaticBoxSizer2;
	wxBoxSizer* BoxSizer2;
	wxBoxSizer* BoxSizer1;
	wxStaticBoxSizer* StaticBoxSizer1;

	Create(parent, wxID_ANY, _("Dodawanie Uzytkownika"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("wxID_ANY"));
	BoxSizer1 = new wxBoxSizer(wxVERTICAL);
	StaticBoxSizer1 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("Podaj Nazwe Uzytkownika"));
	TextCtrl1 = new wxTextCtrl(this, ID_TEXTCTRL1, wxEmptyString, wxDefaultPosition, wxSize(400,35), 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	StaticBoxSizer1->Add(TextCtrl1, 1, wxALL, 5);
	BoxSizer1->Add(StaticBoxSizer1, 1, wxALL, 5);
	StaticBoxSizer2 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("Podaj Haslo"));
	TextCtrl2 = new wxTextCtrl(this, ID_TEXTCTRL2, wxEmptyString, wxDefaultPosition, wxSize(400,35), wxTE_PASSWORD, wxDefaultValidator, _T("ID_TEXTCTRL2"));
	StaticBoxSizer2->Add(TextCtrl2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(StaticBoxSizer2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
	Button1 = new wxButton(this, ID_BUTTON1, _("Dodaj"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	BoxSizer2->Add(Button1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Button2 = new wxButton(this, ID_BUTTON2, _("Anuluj"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
	BoxSizer2->Add(Button2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(BoxSizer2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	SetSizer(BoxSizer1);
	BoxSizer1->Fit(this);
	BoxSizer1->SetSizeHints(this);

	Connect(ID_TEXTCTRL1,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&Dodawanie_uzytkownika::OnTextCtrl1Text_Wpisz_nazwe);
	Connect(ID_TEXTCTRL2,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&Dodawanie_uzytkownika::OnTextCtrl2Text_Wpisz_haslo);
	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Dodawanie_uzytkownika::OnButton1Click_Dodaj_uzytkownika);
	Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Dodawanie_uzytkownika::OnButton2Click);
	//*)
}

Dodawanie_uzytkownika::~Dodawanie_uzytkownika()
{
	//(*Destroy(Dodawanie_uzytkownika)
	//*)
}

/*!
*Funkcja ktora anuluje dodawanie nowego uzytkownika.
*Zamyka okno dodawania uzytkownika.
*/
void Dodawanie_uzytkownika::OnButton2Click(wxCommandEvent& event)
{
    EndModal(0);
}

/*!
*Funkcja odpowiedzialna za zczytywanie danych z pola tekstowego TextCtrl1 do zmiennej jeden_uzytkownik.
*Zapisuje nazwe uzytkownika.
*/
void Dodawanie_uzytkownika::OnTextCtrl1Text_Wpisz_nazwe(wxCommandEvent& event)
{
    jeden_uzytkownik->nazwa=event.GetString();
}

/*!
*Funkcja odpowiedzialna za zczytywanie danych z pola testowego TextCtrl2 do zmiennej jeden_uzytkownik.
*Zapisuje haslo uzytkownika.
*/
void Dodawanie_uzytkownika::OnTextCtrl2Text_Wpisz_haslo(wxCommandEvent& event)
{
    jeden_uzytkownik->haslo=event.GetString();
}

/*!
*Funkcja reaguje na wcisniecie przycisku "Dodaj".
*Poczatkowo sprawdza czy zostalo wprowadzone haslo, jesli nie to zostanie wyswietlony stosowny komunikat.
*Zapisuje do zmiennej "uzytkownicy" dane o uzytkowniku przy pomocy innej funkcji.
*Jesli zapis nie powiod sie powodzeniem zostaje wyswietlony komunikat.
*Dodatkowo zostaje zaktualizowany plik *.txt w ktorym sa zapisane dane o uzytkownikach.
*Na koniec zostaje zamkniete okno.
*/
void Dodawanie_uzytkownika::OnButton1Click_Dodaj_uzytkownika(wxCommandEvent& event)
{
    if(jeden_uzytkownik->haslo==""){
        int Okno_bledu_pustego_hasla = wxMessageBox("Musisz podac haslo","Blad", wxYES_DEFAULT | wxICON_WARNING);
        if(Okno_bledu_pustego_hasla == wxYES)
                ;
    }else{
        uzytkownicy=dodawanie(&uzytkownicy,jeden_uzytkownik->nazwa,jeden_uzytkownik->haslo);
        int blad=zapisywanie_do_pliku(uzytkownicy);
        if(blad==-1){
            int Okno_bledu = wxMessageBox("Blad otwarcia pliku z do zapisu","Blad", wxYES_DEFAULT | wxICON_ERROR);
            if(Okno_bledu == wxYES)
                ;
        }

        jeden_uzytkownik->nazwa="";
        jeden_uzytkownik->haslo="";
        EndModal(0);
    }
}
