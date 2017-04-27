/***************************************************************
 * Name:      ProjektC2Main.cpp
 * Purpose:   Code for Application Frame
 * Author:    Sliwa ()
 * Created:   2016-12-02
 * Copyright: Sliwa ()
 * License:
 **************************************************************/

#include "ProjektC2Main.h"
#include <wx/msgdlg.h>
#include "Dodawanie.h"
#include "Wyswietlanie.h"
#include "Zarzadzanie.h"
#include "lista.h"
#include "uzytkownicy.h"

//(*InternalHeaders(ProjektC2Frame)
#include <wx/font.h>
#include <wx/intl.h>
#include <wx/string.h>
//*)

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(ProjektC2Frame)
const long ProjektC2Frame::ID_STATICTEXT1 = wxNewId();
const long ProjektC2Frame::ID_CHOICE1 = wxNewId();
const long ProjektC2Frame::ID_TEXTCTRL1 = wxNewId();
const long ProjektC2Frame::ID_STATICTEXT2 = wxNewId();
const long ProjektC2Frame::ID_BUTTON2 = wxNewId();
const long ProjektC2Frame::ID_BUTTON3 = wxNewId();
const long ProjektC2Frame::ID_BUTTON5 = wxNewId();
const long ProjektC2Frame::ID_BUTTON1 = wxNewId();
const long ProjektC2Frame::ID_BUTTON4 = wxNewId();
const long ProjektC2Frame::ID_RADIOBUTTON1 = wxNewId();
const long ProjektC2Frame::ID_RADIOBUTTON2 = wxNewId();
const long ProjektC2Frame::ID_RADIOBUTTON3 = wxNewId();
const long ProjektC2Frame::ID_RADIOBUTTON4 = wxNewId();
const long ProjektC2Frame::ID_RADIOBUTTON5 = wxNewId();
const long ProjektC2Frame::ID_RADIOBUTTON6 = wxNewId();
const long ProjektC2Frame::ID_RADIOBUTTON7 = wxNewId();
const long ProjektC2Frame::ID_RADIOBUTTON8 = wxNewId();
const long ProjektC2Frame::ID_RADIOBUTTON9 = wxNewId();
const long ProjektC2Frame::ID_SEARCHCTRL1 = wxNewId();
const long ProjektC2Frame::ID_PANEL1 = wxNewId();
const long ProjektC2Frame::ID_MENUITEM4 = wxNewId();
const long ProjektC2Frame::idMenuQuit = wxNewId();
const long ProjektC2Frame::ID_MENUITEM5 = wxNewId();
const long ProjektC2Frame::ID_MENUITEM6 = wxNewId();
const long ProjektC2Frame::ID_MENUITEM7 = wxNewId();
const long ProjektC2Frame::ID_MENUITEM1 = wxNewId();
const long ProjektC2Frame::ID_MENUITEM2 = wxNewId();
const long ProjektC2Frame::ID_MENUITEM3 = wxNewId();
const long ProjektC2Frame::idMenuAbout = wxNewId();
const long ProjektC2Frame::ID_STATUSBAR1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(ProjektC2Frame,wxFrame)
    //(*EventTable(ProjektC2Frame)
    //*)
END_EVENT_TABLE()

/*!
*Zmienna w ktorej przechowywany jest tekst ktory ma zostac wyszukany w bazie kontaktow.
*/
string *wyszukiwany=NULL;
/*!
*Zmienna w ktorej jest zapisana informacja o tym, po ktorym polu ma zostac wyszukany tekst.
*/
int zaznaczony_int;
/*!
*Zmienna ktora sluzy do sterowania czy okno wyswietlania bedzie sluzylo do wyswietlania wszystkich kontaktow czy tych wyszukanych.
*/
int wyswietlanie_wyszukiwanie;
/*!
*baza_kontaktow - w niej zapisywana jest cala baza kontaktow.
*Struktura opiera sie o liste jednokierunkowa.
*Dane w niej dodawane sa w sposob dynamiczy korzystajac z odpowiednio przygotowanej funkcji.
*Odwolanie do deklaracji znajdujacej sie w innym pliku.
*/
extern struct osoba *baza_kontaktow;
/*!
*uzytkownicy - zmnienna w ktorej przechowywane sa dane o uzytkownikach programu.
*Poczatkowo jest ona pusta.
*Dane w niej sa dodawane w sposob dynamiczny, korzysta ona z odpowiednio przygotowanej funckji.
*Jest to odwolanie do deklaracji znajdujacej sie w innym pliku.
*/
extern struct uzytkownik *uzytkownicy;
/*!
*Zmienna przechowuje numer ID wybranego uzytkownika do zalogowania.
*Poczatkowo inicjowana jest wartoscia -1 ktora oznacza, ze nie zostal wybrany zaden uzytkownik
*/
int szukane_u_main=-1;
/*!
*Zmienna przechowuje adres wybranego z listy uzytkownika do zalogowania.
*/
struct uzytkownik *sprawdzany_main=NULL;
/*!
*Zmienna w ktorej zostaje zapisane wprowadzone haslo.
*/
string *sprawdzane_haslo_main=new string;
/*!
*nazwa_pliku - przechowuje czesc nazwy pliku aktualnie uzywanego uzytkownika.
*/
string *nazwa_pliku=new string;

/*!
*Konstruktor ktory tworzy okno wraz z innymi detalami okna.
*/
ProjektC2Frame::ProjektC2Frame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(ProjektC2Frame)
    wxBoxSizer* BoxSizer4;
    wxStaticBoxSizer* StaticBoxSizer2;
    wxBoxSizer* BoxSizer6;
    wxBoxSizer* BoxSizer5;
    wxBoxSizer* BoxSizer7;
    wxBoxSizer* BoxSizer8;
    wxMenuItem* MenuItem2;
    wxMenuItem* MenuItem1;
    wxBoxSizer* BoxSizer2;
    wxMenu* Menu1;
    wxStaticBoxSizer* StaticBoxSizer3;
    wxGridSizer* GridSizer1;
    wxBoxSizer* BoxSizer1;
    wxMenuBar* MenuBar1;
    wxStaticBoxSizer* StaticBoxSizer1;
    wxBoxSizer* BoxSizer3;
    wxMenu* Menu2;

    Create(parent, wxID_ANY, _("Baza Kontaktow"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("wxID_ANY"));
    SetClientSize(wxSize(800,720));
    SetMinSize(wxSize(800,720));
    SetMaxSize(wxSize(800,720));
    Panel1 = new wxPanel(this, ID_PANEL1, wxDefaultPosition, wxSize(800,720), wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    Panel1->SetMinSize(wxSize(800,720));
    Panel1->SetMaxSize(wxSize(800,720));
    BoxSizer1 = new wxBoxSizer(wxVERTICAL);
    StaticText1 = new wxStaticText(Panel1, ID_STATICTEXT1, _("Baza Kontaktow"), wxDefaultPosition, wxSize(790,43), wxALIGN_CENTRE, _T("ID_STATICTEXT1"));
    wxFont StaticText1Font(18,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_T("Comic Sans MS"),wxFONTENCODING_DEFAULT);
    StaticText1->SetFont(StaticText1Font);
    BoxSizer1->Add(StaticText1, 0, wxALL, 5);
    BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
    BoxSizer3 = new wxBoxSizer(wxVERTICAL);
    BoxSizer5 = new wxBoxSizer(wxVERTICAL);
    StaticBoxSizer2 = new wxStaticBoxSizer(wxHORIZONTAL, Panel1, _("Uzytkownik"));
    Choice1 = new wxChoice(Panel1, ID_CHOICE1, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE1"));
    Choice1->SetToolTip(_("Wybierz uzytkownika"));
    StaticBoxSizer2->Add(Choice1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer5->Add(StaticBoxSizer2, 1, wxALL|wxEXPAND, 5);
    StaticBoxSizer3 = new wxStaticBoxSizer(wxHORIZONTAL, Panel1, _("Haslo"));
    TextCtrl1 = new wxTextCtrl(Panel1, ID_TEXTCTRL1, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_PASSWORD, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    TextCtrl1->SetToolTip(_("Wprowadz haslo"));
    StaticBoxSizer3->Add(TextCtrl1, 1, wxALL|wxEXPAND, 5);
    BoxSizer5->Add(StaticBoxSizer3, 1, wxALL|wxEXPAND, 5);
    StaticText2 = new wxStaticText(Panel1, ID_STATICTEXT2, _("Podaj Haslo aby sie zalogowac do konta"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
    BoxSizer5->Add(StaticText2, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer8 = new wxBoxSizer(wxHORIZONTAL);
    Button2 = new wxButton(Panel1, ID_BUTTON2, _("Zaloguj"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
    Button2->SetToolTip(_("Zalogowuje uzytkownika do jego konta"));
    BoxSizer8->Add(Button2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Button3 = new wxButton(Panel1, ID_BUTTON3, _("Wyloguj"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON3"));
    Button3->SetToolTip(_("Wylogowuje uzytkownika"));
    BoxSizer8->Add(Button3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer5->Add(BoxSizer8, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Button5 = new wxButton(Panel1, ID_BUTTON5, _("Zarzadzaj uzytkownikami"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON5"));
    Button5->SetToolTip(_("Pozwala zarzadzac uzytkownikami w programie"));
    BoxSizer5->Add(Button5, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer3->Add(BoxSizer5, 1, wxALL|wxEXPAND, 5);
    BoxSizer6 = new wxBoxSizer(wxHORIZONTAL);
    Button1 = new wxButton(Panel1, ID_BUTTON1, _("Dodaj Kontakt"), wxDefaultPosition, wxSize(-1,60), 0, wxDefaultValidator, _T("ID_BUTTON1"));
    Button1->SetToolTip(_("Dodaje nowa osobe do bazy kontaktow"));
    BoxSizer6->Add(Button1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Button4 = new wxButton(Panel1, ID_BUTTON4, _("Wyswietl kontakty"), wxDefaultPosition, wxSize(-1,60), 0, wxDefaultValidator, _T("ID_BUTTON4"));
    Button4->SetToolTip(_("Wyswietla cala baze kontaktow"));
    BoxSizer6->Add(Button4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer3->Add(BoxSizer6, 0, wxALL|wxEXPAND, 5);
    StaticBoxSizer1 = new wxStaticBoxSizer(wxHORIZONTAL, Panel1, _("Wyszukaj po polu"));
    BoxSizer4 = new wxBoxSizer(wxVERTICAL);
    GridSizer1 = new wxGridSizer(0, 3, 0, 0);
    RadioButton1 = new wxRadioButton(Panel1, ID_RADIOBUTTON1, _("Imie"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_RADIOBUTTON1"));
    RadioButton1->SetToolTip(_("Wyszukuj po imieniu"));
    GridSizer1->Add(RadioButton1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    RadioButton2 = new wxRadioButton(Panel1, ID_RADIOBUTTON2, _("Nazwisko"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_RADIOBUTTON2"));
    RadioButton2->SetToolTip(_("Wyszukuj po nazwisku"));
    GridSizer1->Add(RadioButton2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    RadioButton3 = new wxRadioButton(Panel1, ID_RADIOBUTTON3, _("Miasto"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_RADIOBUTTON3"));
    RadioButton3->SetToolTip(_("Wyszukuj po miescie"));
    GridSizer1->Add(RadioButton3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    RadioButton4 = new wxRadioButton(Panel1, ID_RADIOBUTTON4, _("Ulica"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_RADIOBUTTON4"));
    RadioButton4->SetToolTip(_("Wyszukuj po ulicy"));
    GridSizer1->Add(RadioButton4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    RadioButton5 = new wxRadioButton(Panel1, ID_RADIOBUTTON5, _("Nr domu"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_RADIOBUTTON5"));
    RadioButton5->SetToolTip(_("Wyszukuj po nr domu"));
    GridSizer1->Add(RadioButton5, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    RadioButton6 = new wxRadioButton(Panel1, ID_RADIOBUTTON6, _("Kod Poztowy"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_RADIOBUTTON6"));
    RadioButton6->SetToolTip(_("Wyszukuj po kodzie pocztowym"));
    GridSizer1->Add(RadioButton6, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    RadioButton7 = new wxRadioButton(Panel1, ID_RADIOBUTTON7, _("Poczta"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_RADIOBUTTON7"));
    RadioButton7->SetToolTip(_("Wyszukuj po poczcie"));
    GridSizer1->Add(RadioButton7, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    RadioButton8 = new wxRadioButton(Panel1, ID_RADIOBUTTON8, _("Nr Telefonu"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_RADIOBUTTON8"));
    RadioButton8->SetToolTip(_("Wyszukuj po nr telefonu"));
    GridSizer1->Add(RadioButton8, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    RadioButton9 = new wxRadioButton(Panel1, ID_RADIOBUTTON9, _("Adres email"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_RADIOBUTTON9"));
    RadioButton9->SetToolTip(_("Wyszukuj po adresie email"));
    GridSizer1->Add(RadioButton9, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer4->Add(GridSizer1, 1, wxALL|wxEXPAND, 5);
    BoxSizer7 = new wxBoxSizer(wxHORIZONTAL);
    SearchCtrl1 = new wxSearchCtrl(Panel1, ID_SEARCHCTRL1, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_SEARCHCTRL1"));
    SearchCtrl1->ShowCancelButton(true);
    SearchCtrl1->SetToolTip(_("Wyszukaj kontakt"));
    BoxSizer7->Add(SearchCtrl1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer4->Add(BoxSizer7, 0, wxALL|wxEXPAND, 5);
    StaticBoxSizer1->Add(BoxSizer4, 1, wxALL|wxEXPAND, 5);
    BoxSizer3->Add(StaticBoxSizer1, 1, wxALL|wxEXPAND, 5);
    BoxSizer2->Add(BoxSizer3, 1, wxALL|wxEXPAND, 5);
    BoxSizer1->Add(BoxSizer2, 1, wxALL|wxEXPAND, 5);
    Panel1->SetSizer(BoxSizer1);
    SetSizer(BoxSizer1);
    Layout();
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItem6 = new wxMenuItem(Menu1, ID_MENUITEM4, _("Zapisz Baze do pliku\tCtrl+S"), _("Zapisuje Baze Kontaktow do pliku"), wxITEM_NORMAL);
    Menu1->Append(MenuItem6);
    MenuItem1 = new wxMenuItem(Menu1, idMenuQuit, _("Zamknij\tAlt-F4"), _("Zamyka aplikacje"), wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    MenuBar1->Append(Menu1, _("&Plik"));
    Menu4 = new wxMenu();
    MenuItem7 = new wxMenuItem(Menu4, ID_MENUITEM5, _("Zaloguj\tCtrl+Z"), _("Zalogowuje uzytkownika do jego konta"), wxITEM_NORMAL);
    Menu4->Append(MenuItem7);
    MenuItem8 = new wxMenuItem(Menu4, ID_MENUITEM6, _("Wyloguj\tCtrl+L"), _("Wylogowuje uzytkownika"), wxITEM_NORMAL);
    Menu4->Append(MenuItem8);
    MenuItem9 = new wxMenuItem(Menu4, ID_MENUITEM7, _("Zarzadzanie Uzytkownikami\tCtrl+R"), _("Pozwala zarzadzac uzytkownikami w programie"), wxITEM_NORMAL);
    Menu4->Append(MenuItem9);
    MenuBar1->Append(Menu4, _("&Uzytkownicy"));
    Menu3 = new wxMenu();
    MenuItem3 = new wxMenuItem(Menu3, ID_MENUITEM1, _("Dodaj Kontakt\tCtrl+D"), _("Dodaje nowa osobe do bazy kontaktow"), wxITEM_NORMAL);
    Menu3->Append(MenuItem3);
    MenuItem4 = new wxMenuItem(Menu3, ID_MENUITEM2, _("Wyswietl Kontakt\tCtrl+W"), _("Wyswietla cala baze kontaktow"), wxITEM_NORMAL);
    Menu3->Append(MenuItem4);
    MenuItem5 = new wxMenuItem(Menu3, ID_MENUITEM3, _("Szukaj"), _("Wyszukaj kontakt"), wxITEM_NORMAL);
    Menu3->Append(MenuItem5);
    MenuBar1->Append(Menu3, _("&Kontakty"));
    Menu2 = new wxMenu();
    MenuItem2 = new wxMenuItem(Menu2, idMenuAbout, _("O programie\tF1"), _("Informacie o programie"), wxITEM_NORMAL);
    Menu2->Append(MenuItem2);
    MenuBar1->Append(Menu2, _("P&omoc"));
    SetMenuBar(MenuBar1);
    StatusBar1 = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
    int __wxStatusBarWidths_1[1] = { -1 };
    int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
    StatusBar1->SetFieldsCount(1,__wxStatusBarWidths_1);
    StatusBar1->SetStatusStyles(1,__wxStatusBarStyles_1);
    SetStatusBar(StatusBar1);

    Connect(ID_CHOICE1,wxEVT_COMMAND_CHOICE_SELECTED,(wxObjectEventFunction)&ProjektC2Frame::OnChoice1Select_Wybrany_uzytkownik);
    Connect(ID_TEXTCTRL1,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&ProjektC2Frame::OnTextCtrl1Text_Wpisz_Haslo);
    Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ProjektC2Frame::OnButton2Click2_Zaloguj);
    Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ProjektC2Frame::OnButton3Click_Wyloguj);
    Connect(ID_BUTTON5,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ProjektC2Frame::OnButton5Click);
    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ProjektC2Frame::OnButton1Click);
    Connect(ID_BUTTON4,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ProjektC2Frame::OnButton4Click);
    Connect(ID_RADIOBUTTON1,wxEVT_COMMAND_RADIOBUTTON_SELECTED,(wxObjectEventFunction)&ProjektC2Frame::OnRadioButton1Select_Imie);
    Connect(ID_RADIOBUTTON2,wxEVT_COMMAND_RADIOBUTTON_SELECTED,(wxObjectEventFunction)&ProjektC2Frame::OnRadioButton2Select_Nazwisko);
    Connect(ID_RADIOBUTTON3,wxEVT_COMMAND_RADIOBUTTON_SELECTED,(wxObjectEventFunction)&ProjektC2Frame::OnRadioButton3Select_Miasto);
    Connect(ID_RADIOBUTTON4,wxEVT_COMMAND_RADIOBUTTON_SELECTED,(wxObjectEventFunction)&ProjektC2Frame::OnRadioButton4Select_Ulica);
    Connect(ID_RADIOBUTTON5,wxEVT_COMMAND_RADIOBUTTON_SELECTED,(wxObjectEventFunction)&ProjektC2Frame::OnRadioButton5Select_Nr_Domu);
    Connect(ID_RADIOBUTTON6,wxEVT_COMMAND_RADIOBUTTON_SELECTED,(wxObjectEventFunction)&ProjektC2Frame::OnRadioButton6Select_Kod_Pocztowy);
    Connect(ID_RADIOBUTTON7,wxEVT_COMMAND_RADIOBUTTON_SELECTED,(wxObjectEventFunction)&ProjektC2Frame::OnRadioButton7Select_Poczta);
    Connect(ID_RADIOBUTTON8,wxEVT_COMMAND_RADIOBUTTON_SELECTED,(wxObjectEventFunction)&ProjektC2Frame::OnRadioButton8Select_Nr_Telefonu);
    Connect(ID_RADIOBUTTON9,wxEVT_COMMAND_RADIOBUTTON_SELECTED,(wxObjectEventFunction)&ProjektC2Frame::OnRadioButton9Select_Adres_email);
    Connect(ID_SEARCHCTRL1,wxEVT_COMMAND_SEARCHCTRL_SEARCH_BTN,(wxObjectEventFunction)&ProjektC2Frame::OnSearchCtrl1SearchClicked);
    Connect(ID_MENUITEM4,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&ProjektC2Frame::OnMenuItem6Selected_Zapisz_do_pliku);
    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&ProjektC2Frame::OnQuit);
    Connect(ID_MENUITEM5,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&ProjektC2Frame::OnButton2Click2_Zaloguj);
    Connect(ID_MENUITEM6,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&ProjektC2Frame::OnButton3Click_Wyloguj);
    Connect(ID_MENUITEM7,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&ProjektC2Frame::OnButton5Click);
    Connect(ID_MENUITEM1,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&ProjektC2Frame::OnButton1Click);
    Connect(ID_MENUITEM2,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&ProjektC2Frame::OnButton4Click);
    Connect(ID_MENUITEM3,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&ProjektC2Frame::OnSearchCtrl1SearchClicked);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&ProjektC2Frame::OnAbout);
    //*)
    /*!
    *Przy kazdym tworzeniu okna programu zostaja wczytani do bazy uztykownikow uzytkownicy oraz ich dane.
    */
    wczytywanie_z_pliku_uzytkowikow(&uzytkownicy);
    struct uzytkownik *kopia_uzytkownika_main=NULL;
    /*!
    *Zostaje tworzona kopia bazy uzytkownikow na ktorej zostaja wykonywane operacje.
    */
    kopia_uzytkownika_main=kopiowanie_listy(kopia_uzytkownika_main,uzytkownicy);
    /*!
    *Lista do wyboru uzytkownikow zostaje uzupelniona danymi z bazy uzytkownikow.
    */
    while(kopia_uzytkownika_main){
        Choice1->Append(kopia_uzytkownika_main->nazwa);
        kopia_uzytkownika_main=kopia_uzytkownika_main->next;
    }
    /*!
    *Poczatkowo przed zalogowaniem niektore funkcje nie sa dostepne.
    */
    MenuItem3->Enable(false);
    MenuItem4->Enable(false);
    MenuItem5->Enable(false);
    MenuItem6->Enable(false);
    MenuItem7->Enable(true);
    MenuItem8->Enable(false);
    Button1->Enable(false);
    Button3->Enable(false);
    Button4->Enable(false);
    RadioButton1->Enable(false);
    RadioButton2->Enable(false);
    RadioButton3->Enable(false);
    RadioButton4->Enable(false);
    RadioButton5->Enable(false);
    RadioButton6->Enable(false);
    RadioButton7->Enable(false);
    RadioButton8->Enable(false);
    RadioButton9->Enable(false);
    SearchCtrl1->Enable(false);

}

ProjektC2Frame::~ProjektC2Frame()
{
    //(*Destroy(ProjektC2Frame)
    //*)
}
/*!
*Funkcja do wylaczania programu.
*/
void ProjektC2Frame::OnQuit(wxCommandEvent& event)
{
    Close();
}

/*!
*Funkcja wyswietlajaca informacje o programie.
*/
void ProjektC2Frame::OnAbout(wxCommandEvent& event)
{
    wxMessageBox("Baza kontaktow\nWykonal:\nMateusz Sliwa\n2016", _("O programie"));
}

/*!
*Funkcja reagujaca na wcisniecie przycisku dodawania kontaktu.
*Zostaje tworzone okno Dodawania a potem jest ono wyswietlane.
*Dodatkowo w funkcji zostaje ustawiona ikona aplikacji.
*/
void ProjektC2Frame::OnButton1Click(wxCommandEvent& event)
{
    Dodawanie *okno_dodawania=new Dodawanie(this);
    okno_dodawania->Show();
    okno_dodawania->SetIcon(wxICON(ikona_programu));
}

/*!
*Funkcja reagujaca na wcisniecie przycisku wyswietlania kontaktow.
*Do zmiennej wyswietlanie_wyszukiwanie zostaje przypisana wartosc ktora informuje o tym czy okno bedzie
*wyswietlalo dane o wszystkih kontaktach czy tylko o tych ktore zostaly wpisane do wyszukania.
*Zostaje tworzone okno wyswietlania a potem jest ono wyswietlane.
*Dodatkowo w funkcji zostaje ustawiona ikona aplikacji.
*/
void ProjektC2Frame::OnButton4Click(wxCommandEvent& event)
{
    wyswietlanie_wyszukiwanie=1;
    Wyswietlanie *okno_wyswietlania=new Wyswietlanie(this);
    okno_wyswietlania->Show();
    okno_wyswietlania->SetIcon(wxICON(ikona_programu));
}

/*!
*Funkcja reaguje na wcisniecie przycisku wyszukiwania.
*Do zmiennej wyswietlanie_wyszukiwanie zostaje przypisana wartosc ktora informuje o tym czy okno bedzie
*wyswietlalo dane o wszystkich kontaktach czy tylko o tych ktore zostaly wpisane do wyszukiwania.
*Do zmiennej wyszukiwany zostaje przypisany tekst ktory ma zostac wyszukany.
*Zosteje tworzone okno wyswietlania a potem jest ono wyswietlane.
*Dodatkowo w funkcji zostaje ustawiona ikona aplikacji.
*/
void ProjektC2Frame::OnSearchCtrl1SearchClicked(wxCommandEvent& event)
{
    wyswietlanie_wyszukiwanie=2;
    wyszukiwany=new string;
    *wyszukiwany=event.GetString();
    Wyswietlanie *okno=new Wyswietlanie(this);
    okno->Show();
    okno->SetIcon(wxICON(ikona_programu));
}

/*!
*Funkcja reaguje na zaznaczenie przycisku. Jeśli zostanie zaznaczony zmienna zaznaczony_int przyjmie wartosc 1.
*/
void ProjektC2Frame::OnRadioButton1Select_Imie(wxCommandEvent& event)
{
    zaznaczony_int=1;
}

/*!
*Funkcja reaguje na zaznaczenie przycisku. Jeśli zostanie zaznaczony zmienna zaznaczony_int przyjmie wartosc 2.
*/
void ProjektC2Frame::OnRadioButton2Select_Nazwisko(wxCommandEvent& event)
{
    zaznaczony_int=2;
}

/*!
*Funkcja reaguje na zaznaczenie przycisku. Jeśli zostanie zaznaczony zmienna zaznaczony_int przyjmie wartosc 3.
*/
void ProjektC2Frame::OnRadioButton3Select_Miasto(wxCommandEvent& event)
{
    zaznaczony_int=3;
}

/*!
*Funkcja reaguje na zaznaczenie przycisku. Jeśli zostanie zaznaczony zmienna zaznaczony_int przyjmie wartosc 4.
*/
void ProjektC2Frame::OnRadioButton4Select_Ulica(wxCommandEvent& event)
{
    zaznaczony_int=4;
}

/*!
*Funkcja reaguje na zaznaczenie przycisku. Jeśli zostanie zaznaczony zmienna zaznaczony_int przyjmie wartosc 5.
*/
void ProjektC2Frame::OnRadioButton5Select_Nr_Domu(wxCommandEvent& event)
{
    zaznaczony_int=5;
}

/*!
*Funkcja reaguje na zaznaczenie przycisku. Jeśli zostanie zaznaczony zmienna zaznaczony_int przyjmie wartosc 6.
*/
void ProjektC2Frame::OnRadioButton6Select_Kod_Pocztowy(wxCommandEvent& event)
{
    zaznaczony_int=6;
}

/*!
*Funkcja reaguje na zaznaczenie przycisku. Jeśli zostanie zaznaczony zmienna zaznaczony_int przyjmie wartosc 7.
*/
void ProjektC2Frame::OnRadioButton7Select_Poczta(wxCommandEvent& event)
{
    zaznaczony_int=7;
}

/*!
*Funkcja reaguje na zaznaczenie przycisku. Jeśli zostanie zaznaczony zmienna zaznaczony_int przyjmie wartosc 8.
*/
void ProjektC2Frame::OnRadioButton8Select_Nr_Telefonu(wxCommandEvent& event)
{
    zaznaczony_int=8;
}

/*!
*Funkcja reaguje na zaznaczenie przycisku. Jeśli zostanie zaznaczony zmienna zaznaczony_int przyjmie wartosc 9.
*/
void ProjektC2Frame::OnRadioButton9Select_Adres_email(wxCommandEvent& event)
{
    zaznaczony_int=9;
}

/*!
*Funkcja zapisuje do pliku cala baze kontaktow. Jesli zapis sie nie powiedzie zostanie wyswietlony komunikat.
*/
void ProjektC2Frame::OnMenuItem6Selected_Zapisz_do_pliku(wxCommandEvent& event)
{
    int blad=zapisywanie_do_pliku(baza_kontaktow,*nazwa_pliku);
    if(blad==-1){
        int Okno_bledu = wxMessageBox("Blad otwarcia pliku z do zapisu","Blad", wxYES_DEFAULT | wxICON_ERROR);
        if(Okno_bledu == wxYES)
            ;
    }
}

/*!
*Funkcja reagujaca na wcisniecie przycisku zarzadzania kontaktami.
*Zostaje tworzone okno wyswietlania a potem jest ono wyswietlane.
*Dodatkowo po zamknieciu tamtego okna zostaje akutalizowana lista uzytkownikow do wyboru do logowania.
*/
void ProjektC2Frame::OnButton5Click(wxCommandEvent& event)
{
    Zarzadzanie *okno_zarzadzania=new Zarzadzanie(this);
    okno_zarzadzania->ShowModal();
    Choice1->Clear();
    struct uzytkownik *kopia_uzytkownika_main=NULL;
    kopia_uzytkownika_main=kopiowanie_listy(kopia_uzytkownika_main,uzytkownicy);
    while(kopia_uzytkownika_main){
        Choice1->Append(kopia_uzytkownika_main->nazwa);
        kopia_uzytkownika_main=kopia_uzytkownika_main->next;
    }
}

/*!
*Funkcja ktora zczytuje dane (haslo) ktore zostaje wpisane w pole TextCtrl1.
*Wartosc zostaje zapisana do zmiennej sprawdzane_haslo_main.
*Zostaje wykonana konwersja z wxString do std::string za pomoca funkcji ToStdString().
*/
void ProjektC2Frame::OnTextCtrl1Text_Wpisz_Haslo(wxCommandEvent& event)
{
    StaticText2->SetLabel("Podaj Haslo aby sie zalogowac do konta");
    wxString wxstr=event.GetString();
    *sprawdzane_haslo_main=wxstr.ToStdString();
}

/*!
*Funkcja reagujaca na przycisk "Zaloguj".
*Poczatkowo sprawdza czy zostal wybrany uzytkownik z listy a potem czy zostalo wpisane haslo.
*Nastepnie sprawdzane jest czy wpisane haslo jest odpowiadajace temu przypisanemu do konta uzytkownika.
*Jesli haslo jest poprawne to zostaje wczytana baza kontaktow danego uzytkownika.
*Dodatkowo wlaczany jest dostep do funkcji, ktore sa niedostepne jesli sie nie zalogujemy.
*/
void ProjektC2Frame::OnButton2Click2_Zaloguj(wxCommandEvent& event)
{
    if(szukane_u_main==-1){
        int Okno_bledu_niewybrangeo_uzytkownika = wxMessageBox("Musisz wybrac uzytkownika","Blad", wxYES_DEFAULT | wxICON_WARNING);
        if(Okno_bledu_niewybrangeo_uzytkownika == wxYES)
                ;
    }
    if(*sprawdzane_haslo_main==""){
        int Okno_bledu_pustego_hasla = wxMessageBox("Musisz podac haslo","Blad", wxYES_DEFAULT | wxICON_WARNING);
        if(Okno_bledu_pustego_hasla == wxYES)
                ;
    }
    if(szukane_u_main!=-1&&*sprawdzane_haslo_main!=""){
        if(*sprawdzane_haslo_main!=sprawdzany_main->haslo){
            StaticText2->SetLabel("Niepoprawne Haslo!");
        }
        else{
            StaticText2->SetLabel("Zalogowano");
            MenuItem3->Enable(true);
            MenuItem4->Enable(true);
            MenuItem5->Enable(true);
            MenuItem6->Enable(true);
            MenuItem7->Enable(false);
            MenuItem8->Enable(true);
            Button2->Enable(false);
            *nazwa_pliku=sprawdzany_main->nazwa+to_string(sprawdzany_main->id);
            wczytywanie_z_pliku(&baza_kontaktow,*nazwa_pliku);
            Button1->Enable(true);
            Button3->Enable(true);
            Button4->Enable(true);
            RadioButton1->Enable(true);
            RadioButton2->Enable(true);
            RadioButton3->Enable(true);
            RadioButton4->Enable(true);
            RadioButton5->Enable(true);
            RadioButton6->Enable(true);
            RadioButton7->Enable(true);
            RadioButton8->Enable(true);
            RadioButton9->Enable(true);
            SearchCtrl1->Enable(true);
        }
    }
}

/*!
*Funkcja zczytuje dane uzytkownika ktory zostal wybrany.
*Poczatkowo zostaje zapisany numer ID wybranego uzytkownika potem zostaje tworzona kopia bazy uzytkownika na ktorej zostaje
*wykonywana operacja a nastepnie zostaje zapisany adres wybranego uzytkownika do zmiennej sprawdzany_main.
*/
void ProjektC2Frame::OnChoice1Select_Wybrany_uzytkownik(wxCommandEvent& event)
{
    szukane_u_main=event.GetSelection();
    struct uzytkownik *kopia_uzytkownika=NULL;
    sprawdzany_main=new uzytkownik();
    kopia_uzytkownika=kopiowanie_listy(kopia_uzytkownika,uzytkownicy);
    sprawdzany_main=szukaj_wybranego2(kopia_uzytkownika,szukane_u_main+1);

}

/*!
*Funkcja reagujaca na wcisniecie przycisku "Wyloguj".
*Zostaja wylaczaone funkcje ktore nie sa dostepne bez zalogowania oraz zostaje usuwana baza kontaktow danego uzytkownika.
*/
void ProjektC2Frame::OnButton3Click_Wyloguj(wxCommandEvent& event)
{
    MenuItem3->Enable(false);
    MenuItem4->Enable(false);
    MenuItem5->Enable(false);
    MenuItem6->Enable(false);
    MenuItem7->Enable(true);
    MenuItem8->Enable(false);
    Button1->Enable(false);
    Button2->Enable(true);
    Button3->Enable(false);
    Button4->Enable(false);
    RadioButton1->Enable(false);
    RadioButton2->Enable(false);
    RadioButton3->Enable(false);
    RadioButton4->Enable(false);
    RadioButton5->Enable(false);
    RadioButton6->Enable(false);
    RadioButton7->Enable(false);
    RadioButton8->Enable(false);
    RadioButton9->Enable(false);
    SearchCtrl1->Enable(false);
    StaticText2->SetLabel("Wylogowano");
    baza_kontaktow=usuwanie(baza_kontaktow,-1);
}
