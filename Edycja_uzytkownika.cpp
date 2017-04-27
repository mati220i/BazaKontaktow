#include "Edycja_uzytkownika.h"
#include "uzytkownicy.h"
#include "wx/msgdlg.h"


/*!
*uzytkownicy - zmnienna w ktorej przechowywane sa dane o uzytkownikach programu.
*Dane w niej sa dodawane w sposob dynamiczny, korzysta ona z odpowiednio przygotowanej funckji.
*Jest to odwolanie do deklaracji znajdujacej sie w innym pliku.
*/
extern struct uzytkownik *uzytkownicy;
/*!
*Zmienna strukturalna oparta na liscie jednokierunkowej.
*W programie sluzy ona jako kopia oryginalnej listy uzytkownikow na ktorej zostaja dokonane operacje w trakcie dzialania programu.
*Poczatkowo pusta.
*/
struct uzytkownik *kopia_uzytkownika=NULL;
/*!
*Zmienna w ktorej przechowywany jest adres aktualnie edytowanego uzytkownika.
*Jest to odwolanie do deklaracji znajdujacej sie w innym pliku.
*/
extern uzytkownik *sprawdzany;
/*!
*jeden_uzytkownik_edycja - zmienna wskznikowa ktora przechowuje informajce o pojedynczym uzytkowniku uzywanym w danym momencie.
*/
struct uzytkownik *jeden_uzytkownik_edycja=new uzytkownik;
/*!
*Zmienna w ktorej zapisany jest numer ID aktualnie uzywanego uzytkownika.
*Jest to odwolanie do deklaracji znajdujacej sie w innym pliku.
*/
extern int szukane_u;

//(*InternalHeaders(Edycja_uzytkownika)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(Edycja_uzytkownika)
const long Edycja_uzytkownika::ID_TEXTCTRL1 = wxNewId();
const long Edycja_uzytkownika::ID_TEXTCTRL2 = wxNewId();
const long Edycja_uzytkownika::ID_BUTTON1 = wxNewId();
const long Edycja_uzytkownika::ID_BUTTON2 = wxNewId();
//*)

BEGIN_EVENT_TABLE(Edycja_uzytkownika,wxDialog)
	//(*EventTable(Edycja_uzytkownika)
	//*)
END_EVENT_TABLE()

/*!
*Konstruktor ktory tworzy okno wraz z potrzebnymi przyciskami i polami tekstowymi.
*Dodatkowo wpisuje w pola tekstowe dotychczasowe dane o uzytkowniku.
*/
Edycja_uzytkownika::Edycja_uzytkownika(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(Edycja_uzytkownika)
	wxStaticBoxSizer* StaticBoxSizer2;
	wxBoxSizer* BoxSizer2;
	wxBoxSizer* BoxSizer1;
	wxStaticBoxSizer* StaticBoxSizer1;

	Create(parent, id, _("Edycja Uzytkownika"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));
	SetClientSize(wxDefaultSize);
	Move(wxDefaultPosition);
	BoxSizer1 = new wxBoxSizer(wxVERTICAL);
	StaticBoxSizer1 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("Podaj nowa nazwe uzytkownika"));
	TextCtrl1 = new wxTextCtrl(this, ID_TEXTCTRL1, wxEmptyString, wxDefaultPosition, wxSize(400,35), 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	StaticBoxSizer1->Add(TextCtrl1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(StaticBoxSizer1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer2 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("Podaj nowe Haslo"));
	TextCtrl2 = new wxTextCtrl(this, ID_TEXTCTRL2, wxEmptyString, wxDefaultPosition, wxSize(400,35), wxTE_PASSWORD, wxDefaultValidator, _T("ID_TEXTCTRL2"));
	StaticBoxSizer2->Add(TextCtrl2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(StaticBoxSizer2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
	Button1 = new wxButton(this, ID_BUTTON1, _("Zapisz"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	BoxSizer2->Add(Button1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Button2 = new wxButton(this, ID_BUTTON2, _("Anuluj"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
	BoxSizer2->Add(Button2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(BoxSizer2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	SetSizer(BoxSizer1);
	BoxSizer1->Fit(this);
	BoxSizer1->SetSizeHints(this);

	Connect(ID_TEXTCTRL1,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&Edycja_uzytkownika::OnTextCtrl1Text_Wpisz_nazwe);
	Connect(ID_TEXTCTRL2,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&Edycja_uzytkownika::OnTextCtrl2Text_Wpisz_haslo);
	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Edycja_uzytkownika::OnButton1Click_Zapisz);
	Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Edycja_uzytkownika::OnButton2Click_Anuluj);
	//*)

	kopia_uzytkownika=kopiowanie_listy(kopia_uzytkownika,uzytkownicy);

	TextCtrl1->SetLabel(sprawdzany->nazwa);
	TextCtrl2->SetLabel(sprawdzany->haslo);

}

Edycja_uzytkownika::~Edycja_uzytkownika()
{
	//(*Destroy(Edycja_uzytkownika)
	//*)
}


/*!
*Funkcja reagujaca na przycisniecie przycisku "Zapisz".
*Poczatkowo sprawdza czy zostalo podane haslo, jesli nie to zostanie wyswietlony stosowny komunikat.
*Jesli wszystko przebiegnie pomyslnie to zostana edytowane dane uzytkownika za pomoca specjalnie przygotowanej do tego funkcji.
*Dodatkowo zostaja zauktualizowane dane o uzytkownikach w pliku *.txt po kazdej operacji.
*Na koniec zostaje zamkniete okno.
*/
void Edycja_uzytkownika::OnButton1Click_Zapisz(wxCommandEvent& event)
{
    if(jeden_uzytkownik_edycja->haslo==""){
        int Okno_bledu_pustego_hasla = wxMessageBox("Musisz podac haslo","Blad", wxYES_DEFAULT | wxICON_WARNING);
        if(Okno_bledu_pustego_hasla == wxYES)
                ;
    }else{
        uzytkownicy=edycja(&uzytkownicy,
                           jeden_uzytkownik_edycja->nazwa,
                           jeden_uzytkownik_edycja->haslo,
                           szukane_u,
                           sprawdzany->id);
        int blad=zapisywanie_do_pliku(uzytkownicy);
        if(blad==-1){
            int Okno_bledu = wxMessageBox("Blad otwarcia pliku z do zapisu","Blad", wxYES_DEFAULT | wxICON_ERROR);
            if(Okno_bledu == wxYES)
                ;
        }

        jeden_uzytkownik_edycja->nazwa="";
        jeden_uzytkownik_edycja->haslo="";
        EndModal(0);
    }
}

/*!
*Funkcja zczytuje dane z pola tekstowego TextCtrl1 do zmiennej tymczasowej.
*Zostaje w niej zapisana nazwa uzytkownika.
*/
void Edycja_uzytkownika::OnTextCtrl1Text_Wpisz_nazwe(wxCommandEvent& event)
{
    jeden_uzytkownik_edycja->nazwa=event.GetString();
}

/*!
*Funkcja zczytuje dane z pola tekstowego TextCtrl2 do zmiennej tymczasowej.
*Zostaje w niej zapisane haslo uzytkownika.
*/
void Edycja_uzytkownika::OnTextCtrl2Text_Wpisz_haslo(wxCommandEvent& event)
{
    jeden_uzytkownik_edycja->haslo=event.GetString();
}

/*!
*Funkcja reaguje na nacisniecie przycisku "Anuluj".
*Zostaje zwolniona pamiec na zmienna tymczasowa i zostaje zamykane okno.
*/
void Edycja_uzytkownika::OnButton2Click_Anuluj(wxCommandEvent& event)
{
    free(jeden_uzytkownik_edycja);
    EndModal(0);
}
