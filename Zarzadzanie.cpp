#include "Zarzadzanie.h"
#include "uzytkownicy.h"
#include "Dodawanie_uzytkownika.h"
#include "Sprawdzanie_hasla.h"
#include <sstream>
#include <wx/msgdlg.h>


/*!
*uzytkownicy - zmnienna w ktorej przechowywane sa dane o uzytkownikach programu.
*Dane w niej sa dodawane w sposob dynamiczny, korzysta ona z odpowiednio przygotowanej funckji.
*/
struct uzytkownik *uzytkownicy=NULL,
/*!
*Zmienna w ktorej przechowywany jest adres aktualnie edytowanego uzytkownika.
*Jest to odwolanie do deklaracji znajdujacej sie w innym pliku.
*/
*sprawdzany=NULL;
/*!
*Zmienna w ktorej przechowywany jest numer ID zaznaczonego uzytkownika.
*/
string *zaznaczony_uzytkownik=NULL;
/*!
*Zmienna w ktorej zapisana jest informacja o tym czy po wpisaniu poprawnego hasla program ma przekazac sterowanie do edytowania
*uzytkownika czy do jego usuwania.
*/
int edytowanie_usuwanie_uzytkownika;
/*!
*Zmienna w ktorej zapisany jest numer ID aktualnie uzywanego uzytkownika.
*/
int szukane_u;

//(*InternalHeaders(Zarzadzanie)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(Zarzadzanie)
const long Zarzadzanie::ID_LISTVIEW1 = wxNewId();
const long Zarzadzanie::ID_BUTTON1 = wxNewId();
const long Zarzadzanie::ID_BUTTON2 = wxNewId();
const long Zarzadzanie::ID_BUTTON3 = wxNewId();
//*)

BEGIN_EVENT_TABLE(Zarzadzanie,wxDialog)
	//(*EventTable(Zarzadzanie)
	//*)
END_EVENT_TABLE()

/*!
*Konstruktor ktory tworzy okno wraz z innymi elementami okna.
*/
Zarzadzanie::Zarzadzanie(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(Zarzadzanie)
	wxBoxSizer* BoxSizer2;
	wxBoxSizer* BoxSizer1;
	wxStaticBoxSizer* StaticBoxSizer1;

	Create(parent, wxID_ANY, _("Zarzadzanie Uzytkownikami"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("wxID_ANY"));
	BoxSizer1 = new wxBoxSizer(wxVERTICAL);
	StaticBoxSizer1 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("Uzytkownicy"));
	ListView1 = new wxListView(this, ID_LISTVIEW1, wxDefaultPosition, wxSize(450,150), wxLC_REPORT, wxDefaultValidator, _T("ID_LISTVIEW1"));
	StaticBoxSizer1->Add(ListView1, 1, wxALL, 5);
	BoxSizer1->Add(StaticBoxSizer1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
	Button1 = new wxButton(this, ID_BUTTON1, _("Dodaj uzytkownika"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	BoxSizer2->Add(Button1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Button2 = new wxButton(this, ID_BUTTON2, _("Edytuj"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
	BoxSizer2->Add(Button2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Button3 = new wxButton(this, ID_BUTTON3, _("Usun uzytkownika"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON3"));
	BoxSizer2->Add(Button3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(BoxSizer2, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	SetSizer(BoxSizer1);
	BoxSizer1->Fit(this);
	BoxSizer1->SetSizeHints(this);

	Connect(ID_LISTVIEW1,wxEVT_COMMAND_LIST_ITEM_SELECTED,(wxObjectEventFunction)&Zarzadzanie::OnListView1ItemSelect_uzytkownik);
	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Zarzadzanie::OnButton1Click_dodaj_uzytkownika);
	Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Zarzadzanie::OnButton2Click_Edycja_uzytkownika);
	Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Zarzadzanie::OnButton3Click_Usun_uzytkownika);
	//*)

    /*!
    *Zostaja tworzone kolumny do wyswietlania dostepnych uzytkownikow w programie.
    */
    ListView1->AppendColumn("ID");
    ListView1->AppendColumn("Nazwa uzytkownika",wxLIST_FORMAT_LEFT,350);
    int i=0;
    /*!
    *Tworzona zostaje kopia bazy uzytkownikow na ktorej dokonywane beda operacje.
    */
    struct uzytkownik *kopia_uzytkownikow=NULL;
    kopia_uzytkownikow=kopiowanie_listy(kopia_uzytkownikow,uzytkownicy);
    /*!
    *Na koncu zostaja wyswietlone dane o uzytkownikach w programie.
    */
    while(kopia_uzytkownikow){
        ListView1->InsertItem(i,to_string(kopia_uzytkownikow->id));
        if(kopia_uzytkownikow!=NULL)
            ListView1->SetItem(i,1,kopia_uzytkownikow->nazwa);
        i++;
        kopia_uzytkownikow=kopia_uzytkownikow->next;
    }
    free(kopia_uzytkownikow);
}

Zarzadzanie::~Zarzadzanie()
{
	//(*Destroy(Zarzadzanie)
	//*)
}

/*!
*Fukcja ktora reaguje na wcisniecie przycisku "Dodaj Uzytkownika".
*Zostaje tworzone okno dodawania uzytkownika oraz zostaje ono wyswietlone a na koncu po zakonczeniu dzialania okna dodawania
*uzytkownika aktualizuje sie lista dostepnych uzytkownikow.
*/
void Zarzadzanie::OnButton1Click_dodaj_uzytkownika(wxCommandEvent& event)
{
    Dodawanie_uzytkownika *okno_dodawania_uzytkownika=new Dodawanie_uzytkownika(this);
    okno_dodawania_uzytkownika->ShowModal();
    ListView1->ClearAll();
    ListView1->AppendColumn("ID");
    ListView1->AppendColumn("Nazwa",wxLIST_FORMAT_LEFT,350);
    int i=0;
    struct uzytkownik *kopia_uzytkownikow=NULL;
    kopia_uzytkownikow=kopiowanie_listy(kopia_uzytkownikow,uzytkownicy);
    while(kopia_uzytkownikow){
        ListView1->InsertItem(i,to_string(kopia_uzytkownikow->id));
        if(kopia_uzytkownikow!=NULL){
            ListView1->SetItem(i,1,kopia_uzytkownikow->nazwa);
        }
        i++;
        kopia_uzytkownikow=kopia_uzytkownikow->next;
    }

}

/*!
*Funkcja reaguje na wcisniecie przycisku edycji uzytkownika.
*Poczatkowo do zmiennej edytowanie_usuwanie_uzytkownika zostaje zapisana wartosc ktora bedzie informowala czy sterowanie ma
*zostac przekazane do okna usuwania czy edycji.
*Nastepnie sprawdzany jest warunek czy zostal zaznaczony uzytkownik a nastepnie zostaje tworzone i wyswietlane okno sprawdzania
*hasla. Po zakonczeniu dzialania okna sprawdzania hasla i edycji zostaje aktualizowana lista danych o uzytkownikach.
*/
void Zarzadzanie::OnButton2Click_Edycja_uzytkownika(wxCommandEvent& event)
{
    edytowanie_usuwanie_uzytkownika=1;
    if(zaznaczony_uzytkownik==NULL){
        int powiadomienie = wxMessageBox("Nie zaznaczyles uzytkownika","Edytowanie", wxYES_DEFAULT | wxICON_INFORMATION);
        if(powiadomienie==wxYES)
            ;
    }else{
        Sprawdzanie_hasla *okno=new Sprawdzanie_hasla(this);
        okno->ShowModal();
        ListView1->ClearAll();
        ListView1->AppendColumn("ID");
        ListView1->AppendColumn("Nazwa uzytkownika",wxLIST_FORMAT_LEFT,350);
        int i=0;
        struct uzytkownik *kopia_uzytkownikow=NULL;
        kopia_uzytkownikow=kopiowanie_listy(kopia_uzytkownikow,uzytkownicy);
        while(kopia_uzytkownikow){
            ListView1->InsertItem(i,to_string(kopia_uzytkownikow->id));
            if(kopia_uzytkownikow!=NULL)
                ListView1->SetItem(i,1,kopia_uzytkownikow->nazwa);
            i++;
            kopia_uzytkownikow=kopia_uzytkownikow->next;
        }
    }
}

/*!
*Funkcja ta zapisuje numer ID zaznaczonego uzytkownika do zmiennej zaznaczony_wsu jak i zaznaczony_uzytkownik po czym do zmiennej
*sprawdzany zostaje zapisany adres wyszukanego uzytkownika.
*/
void Zarzadzanie::OnListView1ItemSelect_uzytkownik(wxListEvent& event)
{
    wxString zaznaczony_wsu=event.GetText();
    zaznaczony_uzytkownik=new string;
    *zaznaczony_uzytkownik=event.GetText();
    szukane_u=wxAtoi(zaznaczony_wsu);
    struct uzytkownik *kopia_uzytkownika=NULL;
    sprawdzany=new uzytkownik();
    kopia_uzytkownika=kopiowanie_listy(kopia_uzytkownika,uzytkownicy);
    sprawdzany=szukaj_wybranego2(kopia_uzytkownika,szukane_u);

}

/*!
*Funkcja reaguje na wcisniecie przycisku usuniecia uzytkownika.
*Poczatkowo do zmiennej edytowanie_usuwanie_uzytkownika zostaje zapisana wartosc ktora bedzie informowala czy sterowanie ma
*zostac przekazane do okna usuwania czy edycji.
*Nastepnie sprawdzany jest warunek czy zostal zaznaczony uzytkownik a nastepnie zostaje tworzone i wyswietlane okno sprawdzania
*hasla. Po zakonczeniu dzialania okna edycji zostaje aktualizowana lista danych o uzytkownikach.
*/
void Zarzadzanie::OnButton3Click_Usun_uzytkownika(wxCommandEvent& event)
{
    edytowanie_usuwanie_uzytkownika=2;
    if(zaznaczony_uzytkownik==NULL){
        int powiadomienie = wxMessageBox("Nie zaznaczyles uzytkownika","Usuwanie Uzytkownika", wxYES_DEFAULT | wxICON_INFORMATION);
        if(powiadomienie==wxYES)
            ;
    }else{
        Sprawdzanie_hasla *okno=new Sprawdzanie_hasla(this);
        okno->ShowModal();
        ListView1->ClearAll();
        ListView1->AppendColumn("ID");
        ListView1->AppendColumn("Nazwa uzytkownika",wxLIST_FORMAT_LEFT,350);
        int i=0;
        struct uzytkownik *kopia_uzytkownikow=NULL;
        kopia_uzytkownikow=kopiowanie_listy(kopia_uzytkownikow,uzytkownicy);
        while(kopia_uzytkownikow){
            ListView1->InsertItem(i,to_string(kopia_uzytkownikow->id));
            if(kopia_uzytkownikow!=NULL)
                ListView1->SetItem(i,1,kopia_uzytkownikow->nazwa);
            i++;
            kopia_uzytkownikow=kopia_uzytkownikow->next;
        }
    }
}
