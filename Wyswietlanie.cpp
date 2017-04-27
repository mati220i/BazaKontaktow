#include "Wyswietlanie.h"
#include "Edycja.h"
#include "lista.h"
#include <sstream>
#include <wx/msgdlg.h>

/*!
*Zmienna w ktorej zapisany jest nr ID zaznaczonego uzytkownika.
*/
string *zaznaczony=NULL;
/*!
*Zmienna w ktorej przechowywany jest tekst ktory ma zostac wyszukany w bazie kontaktow.
*/
extern string *wyszukiwany;
/*!
*Zmienna w ktorej jest zapisana informacja o tym, po ktorym polu ma zostac wyszukany tekst.
*/
extern int zaznaczony_int;
/*!
*Zmienna ktora sluzy do sterowania czy okno wyswietlania bedzie sluzylo do wyswietlania wszystkich kontaktow czy tych wyszukanych.
*/
extern int wyswietlanie_wyszukiwanie;
/*!
*baza_kontaktow - w niej zapisywana jest cala baza kontaktow.
*Struktura opiera sie o liste jednokierunkowa.
*Dane w niej dodawane sa w sposob dynamiczy korzystajac z odpowiednio przygotowanej funkcji.
*Odwolanie do deklaracji znajdujacej sie w innym pliku.
*/
extern struct osoba *baza_kontaktow;
/*!
*nazwa_pliku - przechowuje czesc nazwy pliku aktualnie uzywanego uzytkownika.
*/
extern string *nazwa_pliku;


//(*InternalHeaders(Wyswietlanie)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(Wyswietlanie)
const long Wyswietlanie::ID_LISTVIEW1 = wxNewId();
const long Wyswietlanie::ID_BUTTON3 = wxNewId();
const long Wyswietlanie::ID_BUTTON1 = wxNewId();
const long Wyswietlanie::ID_BUTTON2 = wxNewId();
const long Wyswietlanie::ID_BUTTON4 = wxNewId();
const long Wyswietlanie::ID_TEXTCTRL1 = wxNewId();
const long Wyswietlanie::ID_TEXTCTRL2 = wxNewId();
const long Wyswietlanie::ID_TEXTCTRL3 = wxNewId();
const long Wyswietlanie::ID_TEXTCTRL4 = wxNewId();
const long Wyswietlanie::ID_TEXTCTRL5 = wxNewId();
const long Wyswietlanie::ID_TEXTCTRL6 = wxNewId();
const long Wyswietlanie::ID_TEXTCTRL7 = wxNewId();
const long Wyswietlanie::ID_TEXTCTRL8 = wxNewId();
const long Wyswietlanie::ID_TEXTCTRL9 = wxNewId();
const long Wyswietlanie::ID_TEXTCTRL10 = wxNewId();
const long Wyswietlanie::ID_TEXTCTRL11 = wxNewId();
const long Wyswietlanie::ID_TEXTCTRL12 = wxNewId();
const long Wyswietlanie::ID_TEXTCTRL13 = wxNewId();
const long Wyswietlanie::ID_TEXTCTRL14 = wxNewId();
const long Wyswietlanie::ID_TEXTCTRL15 = wxNewId();
const long Wyswietlanie::ID_TEXTCTRL16 = wxNewId();
const long Wyswietlanie::ID_TEXTCTRL17 = wxNewId();
const long Wyswietlanie::ID_TEXTCTRL18 = wxNewId();
const long Wyswietlanie::ID_TEXTCTRL19 = wxNewId();
const long Wyswietlanie::ID_PANEL1 = wxNewId();
const long Wyswietlanie::ID_MENUITEM1 = wxNewId();
const long Wyswietlanie::ID_MENUITEM2 = wxNewId();
const long Wyswietlanie::ID_MENUITEM8 = wxNewId();
const long Wyswietlanie::ID_MENUITEM7 = wxNewId();
const long Wyswietlanie::ID_MENUITEM3 = wxNewId();
const long Wyswietlanie::ID_MENUITEM4 = wxNewId();
const long Wyswietlanie::ID_MENUITEM5 = wxNewId();
const long Wyswietlanie::ID_MENUITEM6 = wxNewId();
const long Wyswietlanie::ID_STATUSBAR1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(Wyswietlanie,wxFrame)
	//(*EventTable(Wyswietlanie)
	//*)
END_EVENT_TABLE()

/*!
*Konstruktor ktory tworzy okno wraz z potrzebnymi elementami.
*/
Wyswietlanie::Wyswietlanie(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(Wyswietlanie)
	wxBoxSizer* BoxSizer4;
	wxStaticBoxSizer* StaticBoxSizer2;
	wxBoxSizer* BoxSizer6;
	wxBoxSizer* BoxSizer5;
	wxStaticBoxSizer* StaticBoxSizer12;
	wxStaticBoxSizer* StaticBoxSizer4;
	wxStaticBoxSizer* StaticBoxSizer9;
	wxBoxSizer* BoxSizer2;
	wxStaticBoxSizer* StaticBoxSizer7;
	wxStaticBoxSizer* StaticBoxSizer13;
	wxStaticBoxSizer* StaticBoxSizer10;
	wxStaticBoxSizer* StaticBoxSizer8;
	wxStaticBoxSizer* StaticBoxSizer3;
	wxGridSizer* GridSizer1;
	wxStaticBoxSizer* StaticBoxSizer6;
	wxStaticBoxSizer* StaticBoxSizer11;
	wxBoxSizer* BoxSizer1;
	wxStaticBoxSizer* StaticBoxSizer1;
	wxBoxSizer* BoxSizer3;
	wxStaticBoxSizer* StaticBoxSizer5;
	wxGridSizer* GridSizer2;

	Create(parent, wxID_ANY, _("Lista Kontaktow"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("wxID_ANY"));
	SetClientSize(wxSize(1200,720));
	SetMinSize(wxSize(1200,720));
	SetMaxSize(wxSize(1200,800));
	SetToolTip(_("Usuwa cala liste kontaktow"));
	Panel1 = new wxPanel(this, ID_PANEL1, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
	BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
	StaticBoxSizer1 = new wxStaticBoxSizer(wxVERTICAL, Panel1, _("Lista Kontaktow"));
	ListView1 = new wxListView(Panel1, ID_LISTVIEW1, wxDefaultPosition, wxDefaultSize, wxLC_REPORT, wxDefaultValidator, _T("ID_LISTVIEW1"));
	StaticBoxSizer1->Add(ListView1, 1, wxALL|wxEXPAND, 5);
	BoxSizer6 = new wxBoxSizer(wxHORIZONTAL);
	Button3 = new wxButton(Panel1, ID_BUTTON3, _("Usun"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON3"));
	Button3->SetToolTip(_("Usuwa wybrany kontakt"));
	BoxSizer6->Add(Button3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Button1 = new wxButton(Panel1, ID_BUTTON1, _("Usun Wszystko"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	Button1->SetToolTip(_("Usuwa cala liste kontaktow"));
	BoxSizer6->Add(Button1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Button2 = new wxButton(Panel1, ID_BUTTON2, _("Odswiez liste"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
	Button2->SetToolTip(_("Odswieza liste kontaktow"));
	BoxSizer6->Add(Button2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Button4 = new wxButton(Panel1, ID_BUTTON4, _("Edytuj"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON4"));
	Button4->SetToolTip(_("Edytuje wybrany kontakt"));
	BoxSizer6->Add(Button4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer1->Add(BoxSizer6, 0, wxALL|wxEXPAND, 5);
	BoxSizer1->Add(StaticBoxSizer1, 1, wxALL|wxEXPAND, 5);
	StaticBoxSizer2 = new wxStaticBoxSizer(wxHORIZONTAL, Panel1, _("Szczegoly Kontaktu"));
	BoxSizer2 = new wxBoxSizer(wxVERTICAL);
	StaticBoxSizer3 = new wxStaticBoxSizer(wxHORIZONTAL, Panel1, _("Imie i Nazwisko"));
	StaticBoxSizer7 = new wxStaticBoxSizer(wxHORIZONTAL, Panel1, _("Imie"));
	TextCtrl1 = new wxTextCtrl(Panel1, ID_TEXTCTRL1, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	StaticBoxSizer7->Add(TextCtrl1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer3->Add(StaticBoxSizer7, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer8 = new wxStaticBoxSizer(wxHORIZONTAL, Panel1, _("Nazwisko"));
	TextCtrl2 = new wxTextCtrl(Panel1, ID_TEXTCTRL2, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY, wxDefaultValidator, _T("ID_TEXTCTRL2"));
	StaticBoxSizer8->Add(TextCtrl2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer3->Add(StaticBoxSizer8, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer2->Add(StaticBoxSizer3, 0, wxALL|wxEXPAND, 5);
	StaticBoxSizer4 = new wxStaticBoxSizer(wxHORIZONTAL, Panel1, _("Adres"));
	BoxSizer3 = new wxBoxSizer(wxVERTICAL);
	BoxSizer4 = new wxBoxSizer(wxHORIZONTAL);
	StaticBoxSizer9 = new wxStaticBoxSizer(wxHORIZONTAL, Panel1, _("Miasto"));
	TextCtrl3 = new wxTextCtrl(Panel1, ID_TEXTCTRL3, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY, wxDefaultValidator, _T("ID_TEXTCTRL3"));
	StaticBoxSizer9->Add(TextCtrl3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxSHAPED, 5);
	BoxSizer4->Add(StaticBoxSizer9, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxSHAPED, 5);
	StaticBoxSizer10 = new wxStaticBoxSizer(wxHORIZONTAL, Panel1, _("Ulica"));
	TextCtrl4 = new wxTextCtrl(Panel1, ID_TEXTCTRL4, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY, wxDefaultValidator, _T("ID_TEXTCTRL4"));
	StaticBoxSizer10->Add(TextCtrl4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxSHAPED, 5);
	BoxSizer4->Add(StaticBoxSizer10, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxSHAPED, 5);
	StaticBoxSizer11 = new wxStaticBoxSizer(wxHORIZONTAL, Panel1, _("Nr Domu"));
	TextCtrl5 = new wxTextCtrl(Panel1, ID_TEXTCTRL5, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY, wxDefaultValidator, _T("ID_TEXTCTRL5"));
	StaticBoxSizer11->Add(TextCtrl5, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer4->Add(StaticBoxSizer11, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer3->Add(BoxSizer4, 1, wxALL|wxEXPAND, 5);
	BoxSizer5 = new wxBoxSizer(wxHORIZONTAL);
	StaticBoxSizer12 = new wxStaticBoxSizer(wxHORIZONTAL, Panel1, _("Kod Pocztowy"));
	TextCtrl6 = new wxTextCtrl(Panel1, ID_TEXTCTRL6, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY, wxDefaultValidator, _T("ID_TEXTCTRL6"));
	StaticBoxSizer12->Add(TextCtrl6, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxSHAPED, 5);
	BoxSizer5->Add(StaticBoxSizer12, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxSHAPED, 5);
	StaticBoxSizer13 = new wxStaticBoxSizer(wxHORIZONTAL, Panel1, _("Poczta"));
	TextCtrl7 = new wxTextCtrl(Panel1, ID_TEXTCTRL7, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY, wxDefaultValidator, _T("ID_TEXTCTRL7"));
	StaticBoxSizer13->Add(TextCtrl7, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxSHAPED, 5);
	BoxSizer5->Add(StaticBoxSizer13, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxSHAPED, 5);
	BoxSizer3->Add(BoxSizer5, 1, wxALL|wxEXPAND, 5);
	StaticBoxSizer4->Add(BoxSizer3, 1, wxALL|wxEXPAND, 5);
	BoxSizer2->Add(StaticBoxSizer4, 1, wxALL|wxEXPAND, 5);
	StaticBoxSizer5 = new wxStaticBoxSizer(wxHORIZONTAL, Panel1, _("Nr Telefonu"));
	GridSizer1 = new wxGridSizer(0, 3, 0, 0);
	TextCtrl8 = new wxTextCtrl(Panel1, ID_TEXTCTRL8, wxEmptyString, wxDefaultPosition, wxSize(130,-1), wxTE_READONLY, wxDefaultValidator, _T("ID_TEXTCTRL8"));
	GridSizer1->Add(TextCtrl8, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxSHAPED, 5);
	TextCtrl9 = new wxTextCtrl(Panel1, ID_TEXTCTRL9, wxEmptyString, wxDefaultPosition, wxSize(130,-1), wxTE_READONLY, wxDefaultValidator, _T("ID_TEXTCTRL9"));
	GridSizer1->Add(TextCtrl9, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxSHAPED, 5);
	TextCtrl10 = new wxTextCtrl(Panel1, ID_TEXTCTRL10, wxEmptyString, wxDefaultPosition, wxSize(130,-1), wxTE_READONLY, wxDefaultValidator, _T("ID_TEXTCTRL10"));
	GridSizer1->Add(TextCtrl10, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxSHAPED, 5);
	TextCtrl11 = new wxTextCtrl(Panel1, ID_TEXTCTRL11, wxEmptyString, wxDefaultPosition, wxSize(130,-1), wxTE_READONLY, wxDefaultValidator, _T("ID_TEXTCTRL11"));
	GridSizer1->Add(TextCtrl11, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxSHAPED, 5);
	TextCtrl12 = new wxTextCtrl(Panel1, ID_TEXTCTRL12, wxEmptyString, wxDefaultPosition, wxSize(130,-1), wxTE_READONLY, wxDefaultValidator, _T("ID_TEXTCTRL12"));
	GridSizer1->Add(TextCtrl12, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxSHAPED, 5);
	TextCtrl13 = new wxTextCtrl(Panel1, ID_TEXTCTRL13, wxEmptyString, wxDefaultPosition, wxSize(130,-1), wxTE_READONLY, wxDefaultValidator, _T("ID_TEXTCTRL13"));
	GridSizer1->Add(TextCtrl13, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxSHAPED, 5);
	StaticBoxSizer5->Add(GridSizer1, 1, wxALL|wxEXPAND, 5);
	BoxSizer2->Add(StaticBoxSizer5, 0, wxALL|wxEXPAND, 5);
	StaticBoxSizer6 = new wxStaticBoxSizer(wxHORIZONTAL, Panel1, _("Adres email"));
	GridSizer2 = new wxGridSizer(0, 3, 0, 0);
	TextCtrl14 = new wxTextCtrl(Panel1, ID_TEXTCTRL14, wxEmptyString, wxDefaultPosition, wxSize(130,-1), wxTE_READONLY, wxDefaultValidator, _T("ID_TEXTCTRL14"));
	GridSizer2->Add(TextCtrl14, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxSHAPED, 5);
	TextCtrl15 = new wxTextCtrl(Panel1, ID_TEXTCTRL15, wxEmptyString, wxDefaultPosition, wxSize(130,-1), wxTE_READONLY, wxDefaultValidator, _T("ID_TEXTCTRL15"));
	GridSizer2->Add(TextCtrl15, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxSHAPED, 5);
	TextCtrl16 = new wxTextCtrl(Panel1, ID_TEXTCTRL16, wxEmptyString, wxDefaultPosition, wxSize(130,-1), wxTE_READONLY, wxDefaultValidator, _T("ID_TEXTCTRL16"));
	GridSizer2->Add(TextCtrl16, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxSHAPED, 5);
	TextCtrl17 = new wxTextCtrl(Panel1, ID_TEXTCTRL17, wxEmptyString, wxDefaultPosition, wxSize(130,-1), wxTE_READONLY, wxDefaultValidator, _T("ID_TEXTCTRL17"));
	GridSizer2->Add(TextCtrl17, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxSHAPED, 5);
	TextCtrl18 = new wxTextCtrl(Panel1, ID_TEXTCTRL18, wxEmptyString, wxDefaultPosition, wxSize(130,-1), wxTE_READONLY, wxDefaultValidator, _T("ID_TEXTCTRL18"));
	GridSizer2->Add(TextCtrl18, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxSHAPED, 5);
	TextCtrl19 = new wxTextCtrl(Panel1, ID_TEXTCTRL19, wxEmptyString, wxDefaultPosition, wxSize(130,-1), wxTE_READONLY, wxDefaultValidator, _T("ID_TEXTCTRL19"));
	GridSizer2->Add(TextCtrl19, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxSHAPED, 5);
	StaticBoxSizer6->Add(GridSizer2, 1, wxALL|wxEXPAND, 5);
	BoxSizer2->Add(StaticBoxSizer6, 0, wxALL|wxEXPAND, 5);
	StaticBoxSizer2->Add(BoxSizer2, 1, wxALL|wxEXPAND, 5);
	BoxSizer1->Add(StaticBoxSizer2, 1, wxALL|wxEXPAND, 5);
	Panel1->SetSizer(BoxSizer1);
	BoxSizer1->Fit(Panel1);
	BoxSizer1->SetSizeHints(Panel1);
	MenuItem1 = new wxMenuItem((&Menu1), ID_MENUITEM1, _("Edytuj Kontakt\tE"), wxEmptyString, wxITEM_NORMAL);
	Menu1.Append(MenuItem1);
	MenuItem2 = new wxMenuItem((&Menu1), ID_MENUITEM2, _("Usun Kontakt\tU"), wxEmptyString, wxITEM_NORMAL);
	Menu1.Append(MenuItem2);
	MenuBar1 = new wxMenuBar();
	Menu3 = new wxMenu();
	MenuItem8 = new wxMenuItem(Menu3, ID_MENUITEM8, _("Zapisz Baze do plku\tCtrl+S"), _("Zapisuje Baze Kontaktow do pliku"), wxITEM_NORMAL);
	Menu3->Append(MenuItem8);
	MenuItem7 = new wxMenuItem(Menu3, ID_MENUITEM7, _("Zamknij\tAlt+F4"), _("Zamyka okno wyswietlania"), wxITEM_NORMAL);
	Menu3->Append(MenuItem7);
	MenuBar1->Append(Menu3, _("&Plik"));
	Menu2 = new wxMenu();
	MenuItem3 = new wxMenuItem(Menu2, ID_MENUITEM3, _("Usun\tCtrl+U"), _("Usuwa wybrany kontakt"), wxITEM_NORMAL);
	Menu2->Append(MenuItem3);
	MenuItem4 = new wxMenuItem(Menu2, ID_MENUITEM4, _("Usun Wszystko\tCtrl+W"), _("Usuwa cala liste kontaktow"), wxITEM_NORMAL);
	Menu2->Append(MenuItem4);
	MenuItem5 = new wxMenuItem(Menu2, ID_MENUITEM5, _("Odswiez\tCtrl+O"), _("Odswieza liste kontaktow"), wxITEM_NORMAL);
	Menu2->Append(MenuItem5);
	MenuItem6 = new wxMenuItem(Menu2, ID_MENUITEM6, _("Edytuj\tCtrl+E"), _("Edytuje wybrany kontakt"), wxITEM_NORMAL);
	Menu2->Append(MenuItem6);
	MenuBar1->Append(Menu2, _("&Opcje"));
	SetMenuBar(MenuBar1);
	StatusBar1 = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
	int __wxStatusBarWidths_1[1] = { -10 };
	int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
	StatusBar1->SetFieldsCount(1,__wxStatusBarWidths_1);
	StatusBar1->SetStatusStyles(1,__wxStatusBarStyles_1);
	SetStatusBar(StatusBar1);

	Connect(ID_LISTVIEW1,wxEVT_COMMAND_LIST_ITEM_SELECTED,(wxObjectEventFunction)&Wyswietlanie::OnListView1ItemSelect);
	Connect(ID_LISTVIEW1,wxEVT_COMMAND_LIST_ITEM_DESELECTED,(wxObjectEventFunction)&Wyswietlanie::OnListView1ItemDeselect);
	Connect(ID_LISTVIEW1,wxEVT_COMMAND_LIST_ITEM_RIGHT_CLICK,(wxObjectEventFunction)&Wyswietlanie::OnListView1ItemRClick);
	Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Wyswietlanie::OnMenuItem2SelectedUsun);
	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Wyswietlanie::OnButton1Click);
	Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Wyswietlanie::OnButton2Click);
	Connect(ID_BUTTON4,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Wyswietlanie::OnButton4ClickEdytuj);
	Connect(ID_MENUITEM1,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&Wyswietlanie::OnMenuItem1SelectedEdytuj);
	Connect(ID_MENUITEM2,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&Wyswietlanie::OnMenuItem2SelectedUsun);
	Connect(ID_MENUITEM8,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&Wyswietlanie::OnMenuItem8Selected_Zapisz_do_pliku);
	Connect(ID_MENUITEM7,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&Wyswietlanie::OnMenuItem7Selected_Zamknij);
	Connect(ID_MENUITEM3,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&Wyswietlanie::OnMenuItem2SelectedUsun);
	Connect(ID_MENUITEM4,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&Wyswietlanie::OnButton1Click);
	Connect(ID_MENUITEM5,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&Wyswietlanie::OnButton2Click);
	Connect(ID_MENUITEM6,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&Wyswietlanie::OnButton4ClickEdytuj);
	//*)
	/*!
	*Dla listy ListView1 zostaja tworzone kolumny.
	*/
	ListView1->AppendColumn("ID");
    ListView1->AppendColumn("Imie",wxLIST_FORMAT_LEFT,150);
    ListView1->AppendColumn("Nazwisko",wxLIST_FORMAT_LEFT,150);
    ListView1->AppendColumn("Miasto",wxLIST_FORMAT_LEFT,150);

    int i=0;
    struct osoba *kopia_bazy=NULL;
    struct osoba *kopia_listy_do_edycji=NULL;
    /*!
    *Zaleznie od wartosci przekazanej zmiennej wyswietlanie_wyszukiwanie zostaje tworzona kopia bazy kontaktow badz kopiowanie
    *bazy jak i wyszukiwanie elementow ktore zostaly przekazane do wyszukiwania.
    */
    if(wyswietlanie_wyszukiwanie==1)
        kopia_bazy=kopiowanie_listy(kopia_bazy,baza_kontaktow);
    if(wyswietlanie_wyszukiwanie==2){
        kopia_listy_do_edycji=kopiowanie_listy(kopia_listy_do_edycji,baza_kontaktow);
        /*!
        *W zmiennej kopia_bazy w przypadku wszyszukiwania zostaje zapisana lista jednokierunkowa ktora przechowuje elementy
        *ktore pasuje do tych ktore zostaly przekazane do wyszukiwania.
        */
        kopia_bazy=wyszukiwanie(kopia_listy_do_edycji,zaznaczony_int,*wyszukiwany);
    }


    /*!
    *Na koniec tworzenia okna zostaja wyswietlane wartosci na liscie ListView1
    */
    while(kopia_bazy){
        ListView1->InsertItem(i,to_string(kopia_bazy->id));
        if(kopia_bazy!=NULL){
            ListView1->SetItem(i,1,kopia_bazy->imie);
            ListView1->SetItem(i,2,kopia_bazy->nazwisko);
            ListView1->SetItem(i,3,kopia_bazy->miasto);
        }
        i++;
        kopia_bazy=kopia_bazy->next;
    }
    free(kopia_listy_do_edycji);
    free(kopia_bazy);
}

Wyswietlanie::~Wyswietlanie()
{
	//(*Destroy(Wyswietlanie)
	//*)
}

/*!
*Funkcja ktora reaguje na zaznaczenie konkretnego pola w liscie.
*Zostaje wczytany numer ID zaznaczonego kontaktu a potem zostaje zapiasny adres tego kontaktu.
*Na koniec zostaja wypisane jego dane w polach dostepnych w oknie.
*/
void Wyswietlanie::OnListView1ItemSelect(wxListEvent& event)
{
    wxString zaznaczony_ws=event.GetText();
    zaznaczony=new string;
    *zaznaczony=event.GetText();
    int szukane=wxAtoi(zaznaczony_ws);
    struct osoba *kopia_bazy=NULL;
    kopia_bazy=kopiowanie_listy(kopia_bazy,baza_kontaktow);
    kopia_bazy=szukaj_wybranego2(kopia_bazy,szukane);
    if(kopia_bazy){
        TextCtrl1->SetLabel(kopia_bazy->imie);
        TextCtrl2->SetLabel(kopia_bazy->nazwisko);
        TextCtrl3->SetLabel(kopia_bazy->miasto);
        TextCtrl4->SetLabel(kopia_bazy->ulica);
        TextCtrl5->SetLabel(kopia_bazy->nr_domu);
        TextCtrl6->SetLabel(kopia_bazy->kod_pocztowy);
        TextCtrl7->SetLabel(kopia_bazy->poczta);
        /*!
        *W zaleznosci od liczebnosci numerow telefonu jak i adresow email bedzie wyswietlane tylko tyle pol ile posiada dany kontakt.
        */
        if(kopia_bazy->ilosc_nr_telefonu==0){
            TextCtrl8->Hide();
            TextCtrl9->Hide();
            TextCtrl10->Hide();
            TextCtrl11->Hide();
            TextCtrl12->Hide();
            TextCtrl13->Hide();
        }if(kopia_bazy->ilosc_nr_telefonu==1){
            TextCtrl8->SetLabel(kopia_bazy->nr_telefonu[0]);
            TextCtrl9->Hide();
            TextCtrl10->Hide();
            TextCtrl11->Hide();
            TextCtrl12->Hide();
            TextCtrl13->Hide();
        }if(kopia_bazy->ilosc_nr_telefonu==2){
            TextCtrl8->SetLabel(kopia_bazy->nr_telefonu[0]);
            TextCtrl9->SetLabel(kopia_bazy->nr_telefonu[1]);
            TextCtrl10->Hide();
            TextCtrl11->Hide();
            TextCtrl12->Hide();
            TextCtrl13->Hide();
        }if(kopia_bazy->ilosc_nr_telefonu==3){
            TextCtrl8->SetLabel(kopia_bazy->nr_telefonu[0]);
            TextCtrl9->SetLabel(kopia_bazy->nr_telefonu[1]);
            TextCtrl10->SetLabel(kopia_bazy->nr_telefonu[2]);
            TextCtrl11->Hide();
            TextCtrl12->Hide();
            TextCtrl13->Hide();
        }if(kopia_bazy->ilosc_nr_telefonu==4){
            TextCtrl8->SetLabel(kopia_bazy->nr_telefonu[0]);
            TextCtrl9->SetLabel(kopia_bazy->nr_telefonu[1]);
            TextCtrl10->SetLabel(kopia_bazy->nr_telefonu[2]);
            TextCtrl11->SetLabel(kopia_bazy->nr_telefonu[3]);
            TextCtrl12->Hide();
            TextCtrl13->Hide();
        }if(kopia_bazy->ilosc_nr_telefonu==5){
            TextCtrl8->SetLabel(kopia_bazy->nr_telefonu[0]);
            TextCtrl9->SetLabel(kopia_bazy->nr_telefonu[1]);
            TextCtrl10->SetLabel(kopia_bazy->nr_telefonu[2]);
            TextCtrl11->SetLabel(kopia_bazy->nr_telefonu[3]);
            TextCtrl12->SetLabel(kopia_bazy->nr_telefonu[4]);
            TextCtrl13->Hide();
        }if(kopia_bazy->ilosc_nr_telefonu==6){
            TextCtrl8->SetLabel(kopia_bazy->nr_telefonu[0]);
            TextCtrl9->SetLabel(kopia_bazy->nr_telefonu[1]);
            TextCtrl10->SetLabel(kopia_bazy->nr_telefonu[2]);
            TextCtrl11->SetLabel(kopia_bazy->nr_telefonu[3]);
            TextCtrl12->SetLabel(kopia_bazy->nr_telefonu[4]);
            TextCtrl13->SetLabel(kopia_bazy->nr_telefonu[5]);
        }if(kopia_bazy->ilosc_adresow_email==0){
            TextCtrl14->Hide();
            TextCtrl15->Hide();
            TextCtrl16->Hide();
            TextCtrl17->Hide();
            TextCtrl18->Hide();
            TextCtrl19->Hide();
        }if(kopia_bazy->ilosc_adresow_email==1){
            TextCtrl14->SetLabel(kopia_bazy->email[0]);
            TextCtrl15->Hide();
            TextCtrl16->Hide();
            TextCtrl17->Hide();
            TextCtrl18->Hide();
            TextCtrl19->Hide();
        }if(kopia_bazy->ilosc_adresow_email==2){
            TextCtrl14->SetLabel(kopia_bazy->email[0]);
            TextCtrl15->SetLabel(kopia_bazy->email[1]);
            TextCtrl16->Hide();
            TextCtrl17->Hide();
            TextCtrl18->Hide();
            TextCtrl19->Hide();
        }if(kopia_bazy->ilosc_adresow_email==3){
            TextCtrl14->SetLabel(kopia_bazy->email[0]);
            TextCtrl15->SetLabel(kopia_bazy->email[1]);
            TextCtrl16->SetLabel(kopia_bazy->email[2]);
            TextCtrl17->Hide();
            TextCtrl18->Hide();
            TextCtrl19->Hide();
        }if(kopia_bazy->ilosc_adresow_email==4){
            TextCtrl14->SetLabel(kopia_bazy->email[0]);
            TextCtrl15->SetLabel(kopia_bazy->email[1]);
            TextCtrl16->SetLabel(kopia_bazy->email[2]);
            TextCtrl17->SetLabel(kopia_bazy->email[3]);
            TextCtrl18->Hide();
            TextCtrl19->Hide();
        }if(kopia_bazy->ilosc_adresow_email==5){
            TextCtrl14->SetLabel(kopia_bazy->email[0]);
            TextCtrl15->SetLabel(kopia_bazy->email[1]);
            TextCtrl16->SetLabel(kopia_bazy->email[2]);
            TextCtrl17->SetLabel(kopia_bazy->email[3]);
            TextCtrl18->SetLabel(kopia_bazy->email[4]);
            TextCtrl19->Hide();
        }if(kopia_bazy->ilosc_adresow_email==6){
            TextCtrl14->SetLabel(kopia_bazy->email[0]);
            TextCtrl15->SetLabel(kopia_bazy->email[1]);
            TextCtrl16->SetLabel(kopia_bazy->email[2]);
            TextCtrl17->SetLabel(kopia_bazy->email[3]);
            TextCtrl18->SetLabel(kopia_bazy->email[4]);
            TextCtrl19->SetLabel(kopia_bazy->email[5]);
        }

    }else
        TextCtrl1->SetLabel("NULL");
}

/*!
*Funkcja reaguje na odznaczenie kontakow.
*/
void Wyswietlanie::OnListView1ItemDeselect(wxListEvent& event)
{
    TextCtrl8->Show(true);
    TextCtrl9->Show(true);
    TextCtrl10->Show(true);
    TextCtrl11->Show(true);
    TextCtrl12->Show(true);
    TextCtrl13->Show(true);
    TextCtrl14->Show(true);
    TextCtrl15->Show(true);
    TextCtrl16->Show(true);
    TextCtrl17->Show(true);
    TextCtrl18->Show(true);
    TextCtrl19->Show(true);
    TextCtrl1->Clear();
    TextCtrl2->Clear();
    TextCtrl3->Clear();
    TextCtrl4->Clear();
    TextCtrl5->Clear();
    TextCtrl6->Clear();
    TextCtrl7->Clear();
    TextCtrl8->Clear();
    TextCtrl9->Clear();
    TextCtrl10->Clear();
    TextCtrl11->Clear();
    TextCtrl12->Clear();
    TextCtrl13->Clear();
    TextCtrl14->Clear();
    TextCtrl15->Clear();
    TextCtrl16->Clear();
    TextCtrl17->Clear();
    TextCtrl18->Clear();
    TextCtrl19->Clear();
}

/*!
*Funkcja reaguje na wcisniecie prawego przycisku myszy.
*W tej funkcji zostaje zapiany numer ID zaznaczonego kontaktu jak i wywolane menu popup.
*/
void Wyswietlanie::OnListView1ItemRClick(wxListEvent& event)
{
    zaznaczony=new string;
    *zaznaczony=event.GetText();
    PopupMenu(&Menu1);

}

/*!
*Funkcja ktora usuwa wybrany kontakt.
*Jesli wyrazimy na to zgode zostaje usuniety wybrany kontakt poprzez odpowiednia funkcje a nastepnie zostaje aktualizowana lista
*kontakow.
*Dodatkowo zostaje aktualizowana baza kontaktow w pliku *.txt
*/
void Wyswietlanie::OnMenuItem2SelectedUsun(wxCommandEvent& event)
{
    int Okno_usuwania = wxMessageBox("Usunac wybrany Kontakt?","Usuwanie", wxYES_NO | wxICON_QUESTION);
    if(Okno_usuwania == wxYES){
        baza_kontaktow=usuwanie(baza_kontaktow,to_int(*zaznaczony));
        ListView1->ClearAll();
        ListView1->AppendColumn("ID");
        ListView1->AppendColumn("Imie",wxLIST_FORMAT_LEFT,150);
        ListView1->AppendColumn("Nazwisko",wxLIST_FORMAT_LEFT,150);
        ListView1->AppendColumn("Miasto",wxLIST_FORMAT_LEFT,150);
        int i=0;
        struct osoba *kopia_bazy=NULL;
        kopia_bazy=kopiowanie_listy(kopia_bazy,baza_kontaktow);
        while(kopia_bazy){
            ListView1->InsertItem(i,to_string(kopia_bazy->id));
            if(kopia_bazy!=NULL){
                ListView1->SetItem(i,1,kopia_bazy->imie);
                ListView1->SetItem(i,2,kopia_bazy->nazwisko);
                ListView1->SetItem(i,3,kopia_bazy->miasto);
            }
            i++;
            kopia_bazy=kopia_bazy->next;
        }
        int blad=zapisywanie_do_pliku(baza_kontaktow,*nazwa_pliku);
        if(blad==-1){
            int Okno_bledu = wxMessageBox("Blad otwarcia pliku z do zapisu","Blad", wxYES_DEFAULT | wxICON_ERROR);
            if(Okno_bledu == wxYES)
                ;
        }

        wxListEvent event2;
        Wyswietlanie::OnListView1ItemDeselect(event2);
        free(kopia_bazy);
        zaznaczony=NULL;
    }
}

/*!
*Funkcja realizuje usuniecie calej listy kontaktow.
*Dodatkowo zostaje aktualizowana baza kontaktow w pliku *.txt jak i lista wyswietlana w oknie.
*/
void Wyswietlanie::OnButton1Click(wxCommandEvent& event)
{
    if(ListView1->GetItemCount()==0){
        wxMessageBox("Lista Pusta","Usuwanie", wxOK | wxICON_INFORMATION);
    }else{
        int Okno_usuwania = wxMessageBox("Usunac cala liste kontaktow?","Usuwanie", wxYES_NO | wxICON_QUESTION);
        if(Okno_usuwania == wxYES){
            baza_kontaktow=usuwanie(baza_kontaktow,-1);
            int blad=zapisywanie_do_pliku(baza_kontaktow,*nazwa_pliku);
            if(blad==-1){
                int Okno_bledu = wxMessageBox("Blad otwarcia pliku z do zapisu","Blad", wxYES_DEFAULT | wxICON_ERROR);
                if(Okno_bledu == wxYES)
                    ;
            }
            ListView1->ClearAll();
            ListView1->AppendColumn("ID");
            ListView1->AppendColumn("Imie",wxLIST_FORMAT_LEFT,150);
            ListView1->AppendColumn("Nazwisko",wxLIST_FORMAT_LEFT,150);
            ListView1->AppendColumn("Miasto",wxLIST_FORMAT_LEFT,150);
            wxListEvent event2;
            Wyswietlanie::OnListView1ItemDeselect(event2);
        }
    }
}

/*!
*Funkcja realizujaca odswierzanie listy kontaktow na ekranie.
*/
void Wyswietlanie::Odswiez(){
    ListView1->ClearAll();
    ListView1->AppendColumn("ID");
    ListView1->AppendColumn("Imie",wxLIST_FORMAT_LEFT,150);
    ListView1->AppendColumn("Nazwisko",wxLIST_FORMAT_LEFT,150);
    ListView1->AppendColumn("Miasto",wxLIST_FORMAT_LEFT,150);
    int i=0;
    struct osoba *kopia_bazy=NULL;
    kopia_bazy=kopiowanie_listy(kopia_bazy,baza_kontaktow);
    while(kopia_bazy){
        ListView1->InsertItem(i,to_string(kopia_bazy->id));
        if(kopia_bazy!=NULL){
            ListView1->SetItem(i,1,kopia_bazy->imie);
            ListView1->SetItem(i,2,kopia_bazy->nazwisko);
            ListView1->SetItem(i,3,kopia_bazy->miasto);
        }
        i++;
        kopia_bazy=kopia_bazy->next;
    }
    wxListEvent event2;
    Wyswietlanie::OnListView1ItemDeselect(event2);
    free(kopia_bazy);
}

/*!
*Funkcja reagujaca na wcisniecie przycisku edytowania kontaktu.
*Zostaje tworzone okno wyswietlania a potem jest ono wyswietlane.
*Dodatkowo w funkcji zostaje ustawiona ikona aplikacji.
*/

void Wyswietlanie::OnMenuItem1SelectedEdytuj(wxCommandEvent& event)
{
    Edycja *okno_edytowania=new Edycja(this);
    okno_edytowania->Show();
    okno_edytowania->SetIcon(wxICON(ikona_programu));
}

/*!
*Funkcja odpowiadajaca za odswiezanie listy w oknie z menu w gorze okna.
*/
void Wyswietlanie::OnButton2Click(wxCommandEvent& event)
{
    Odswiez();
}

/*!
*Funkcja odpowiadajaca za usuwanie kontaktu.
*/
void Wyswietlanie::OnButton3ClickUsun(wxCommandEvent& event)
{
    if(zaznaczony==NULL){
        int powiadomienie = wxMessageBox("Nie zaznaczyles kontaktu","Usuwanie", wxYES_DEFAULT | wxICON_INFORMATION);
        if(powiadomienie==wxYES)
            ;
    }else{
        wxListEvent event2;
        Wyswietlanie::OnMenuItem2SelectedUsun(event2);
    }
}

/*!
*Funkcja odpowiadajaca za edycje kontaktu.
*/
void Wyswietlanie::OnButton4ClickEdytuj(wxCommandEvent& event)
{
    if(zaznaczony==NULL){
        int powiadomienie = wxMessageBox("Nie zaznaczyles kontaktu","Edytowanie", wxYES_DEFAULT | wxICON_INFORMATION);
        if(powiadomienie==wxYES)
            ;
    }else{
        wxListEvent event2;
        Wyswietlanie::OnMenuItem1SelectedEdytuj(event2);
    }
}


/*!
*Funkcja odpowiadajaca za zamkniecie okna wyswietlania.
*/
void Wyswietlanie::OnMenuItem7Selected_Zamknij(wxCommandEvent& event)
{
    Close();
}

/*!
*Funkcja odpowiadajaca za zapisanie bazy kontaktow do pliku.
*/
void Wyswietlanie::OnMenuItem8Selected_Zapisz_do_pliku(wxCommandEvent& event)
{
    int blad=zapisywanie_do_pliku(baza_kontaktow,*nazwa_pliku);
    if(blad==-1){
        int Okno_bledu = wxMessageBox("Blad otwarcia pliku z do zapisu","Blad", wxYES_DEFAULT | wxICON_ERROR);
        if(Okno_bledu == wxYES)
            ;
    }
}
