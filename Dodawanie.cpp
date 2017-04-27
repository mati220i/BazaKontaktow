#include "Dodawanie.h"
#include "ProjektC2Main.h"
#include "lista.h"
#include <wx/msgdlg.h>


//(*InternalHeaders(Dodawanie)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(Dodawanie)
const long Dodawanie::ID_TEXTCTRL1 = wxNewId();
const long Dodawanie::ID_TEXTCTRL2 = wxNewId();
const long Dodawanie::ID_TEXTCTRL3 = wxNewId();
const long Dodawanie::ID_TEXTCTRL4 = wxNewId();
const long Dodawanie::ID_TEXTCTRL5 = wxNewId();
const long Dodawanie::ID_TEXTCTRL6 = wxNewId();
const long Dodawanie::ID_TEXTCTRL7 = wxNewId();
const long Dodawanie::ID_CHOICE1 = wxNewId();
const long Dodawanie::ID_TEXTCTRL8 = wxNewId();
const long Dodawanie::ID_TEXTCTRL9 = wxNewId();
const long Dodawanie::ID_TEXTCTRL10 = wxNewId();
const long Dodawanie::ID_TEXTCTRL11 = wxNewId();
const long Dodawanie::ID_TEXTCTRL12 = wxNewId();
const long Dodawanie::ID_TEXTCTRL13 = wxNewId();
const long Dodawanie::ID_CHOICE2 = wxNewId();
const long Dodawanie::ID_TEXTCTRL14 = wxNewId();
const long Dodawanie::ID_TEXTCTRL15 = wxNewId();
const long Dodawanie::ID_TEXTCTRL16 = wxNewId();
const long Dodawanie::ID_TEXTCTRL17 = wxNewId();
const long Dodawanie::ID_TEXTCTRL18 = wxNewId();
const long Dodawanie::ID_TEXTCTRL19 = wxNewId();
const long Dodawanie::ID_BUTTON1 = wxNewId();
const long Dodawanie::ID_BUTTON2 = wxNewId();
const long Dodawanie::ID_PANEL1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(Dodawanie,wxFrame)
	//(*EventTable(Dodawanie)
	//*)
END_EVENT_TABLE()
/*!
*Zmienna wskznikowa ktora przechowuje informajce o pojedynczej osobie uzywanej w danym momencie.
*/
struct osoba *jedna_osoba=new osoba,
/*!
*baza_kontaktow - w niej zapisywana jest cala baza kontaktow.
*Struktura opiera sie o liste jednokierunkowa.
*Poczatkowo jest ona pusta.
*Dane w niej dodawane sa w sposob dynamiczy korzystajac z odpowiednio przygotowanej funkcji.
*/
*baza_kontaktow=NULL;
/*!
*nazwa_pliku - przechowuje czesc nazwy pliku aktualnie uzywanego uzytkownika.
*odwolanie do deklaracji znajdujacej sie w innym pliku.
*/
extern string *nazwa_pliku;

/*!
Konstruktor tworzacy okno wraz z jego dodatkami w postaci przyciskow, pol tekstowych i pol wyboru.
*/
Dodawanie::Dodawanie(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(Dodawanie)
	wxBoxSizer* BoxSizer4;
	wxStaticBoxSizer* StaticBoxSizer2;
	wxBoxSizer* BoxSizer6;
	wxBoxSizer* BoxSizer5;
	wxStaticBoxSizer* StaticBoxSizer4;
	wxBoxSizer* BoxSizer2;
	wxStaticBoxSizer* StaticBoxSizer7;
	wxStaticBoxSizer* StaticBoxSizer3;
	wxGridSizer* GridSizer1;
	wxStaticBoxSizer* StaticBoxSizer6;
	wxBoxSizer* BoxSizer1;
	wxStaticBoxSizer* StaticBoxSizer1;
	wxBoxSizer* BoxSizer3;
	wxStaticBoxSizer* StaticBoxSizer5;
	wxGridSizer* GridSizer2;

	Create(parent, wxID_ANY, _("Dodaj Kontakt"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
	SetClientSize(wxSize(800,720));
	SetMinSize(wxSize(800,720));
	SetMaxSize(wxSize(800,720));
	Panel1 = new wxPanel(this, ID_PANEL1, wxPoint(376,480), wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
	StaticBoxSizer1 = new wxStaticBoxSizer(wxVERTICAL, Panel1, _("Dodawanie Kontaktu"));
	StaticBoxSizer2 = new wxStaticBoxSizer(wxHORIZONTAL, Panel1, _("Imie i Nazwisko"));
	TextCtrl1 = new wxTextCtrl(Panel1, ID_TEXTCTRL1, _("Wpisz Imie"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	StaticBoxSizer2->Add(TextCtrl1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	TextCtrl2 = new wxTextCtrl(Panel1, ID_TEXTCTRL2, _("Wpisz Nazwisko"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
	StaticBoxSizer2->Add(TextCtrl2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer1->Add(StaticBoxSizer2, 1, wxALL|wxEXPAND, 5);
	StaticBoxSizer3 = new wxStaticBoxSizer(wxHORIZONTAL, Panel1, _("Adres"));
	BoxSizer1 = new wxBoxSizer(wxVERTICAL);
	BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
	TextCtrl3 = new wxTextCtrl(Panel1, ID_TEXTCTRL3, _("Wpisz Miasto"), wxDefaultPosition, wxSize(200,-1), 0, wxDefaultValidator, _T("ID_TEXTCTRL3"));
	BoxSizer2->Add(TextCtrl3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	TextCtrl4 = new wxTextCtrl(Panel1, ID_TEXTCTRL4, _("Wpisz Ulice"), wxDefaultPosition, wxSize(200,-1), 0, wxDefaultValidator, _T("ID_TEXTCTRL4"));
	BoxSizer2->Add(TextCtrl4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	TextCtrl5 = new wxTextCtrl(Panel1, ID_TEXTCTRL5, _("Wpisz Nr Domu"), wxDefaultPosition, wxSize(200,-1), 0, wxDefaultValidator, _T("ID_TEXTCTRL5"));
	BoxSizer2->Add(TextCtrl5, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(BoxSizer2, 1, wxALL|wxEXPAND, 5);
	BoxSizer3 = new wxBoxSizer(wxHORIZONTAL);
	TextCtrl6 = new wxTextCtrl(Panel1, ID_TEXTCTRL6, _("Wpisz Kod Pocztowy"), wxDefaultPosition, wxSize(200,-1), 0, wxDefaultValidator, _T("ID_TEXTCTRL6"));
	BoxSizer3->Add(TextCtrl6, 1, wxALL|wxEXPAND, 5);
	TextCtrl7 = new wxTextCtrl(Panel1, ID_TEXTCTRL7, _("Wpisz Poczte"), wxDefaultPosition, wxSize(200,-1), 0, wxDefaultValidator, _T("ID_TEXTCTRL7"));
	BoxSizer3->Add(TextCtrl7, 1, wxALL|wxEXPAND, 5);
	BoxSizer1->Add(BoxSizer3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL, 5);
	StaticBoxSizer3->Add(BoxSizer1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer1->Add(StaticBoxSizer3, 1, wxALL|wxEXPAND, 5);
	StaticBoxSizer4 = new wxStaticBoxSizer(wxHORIZONTAL, Panel1, _("Nr Telefonu"));
	BoxSizer4 = new wxBoxSizer(wxHORIZONTAL);
	StaticBoxSizer5 = new wxStaticBoxSizer(wxHORIZONTAL, Panel1, _("Podaj ilosc nr telefonu"));
	Choice1 = new wxChoice(Panel1, ID_CHOICE1, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE1"));
	Choice1->Append(_("0"));
	Choice1->SetSelection( Choice1->Append(_("1")) );
	Choice1->Append(_("2"));
	Choice1->Append(_("3"));
	Choice1->Append(_("4"));
	Choice1->Append(_("5"));
	Choice1->Append(_("6"));
	StaticBoxSizer5->Add(Choice1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer4->Add(StaticBoxSizer5, 1, wxALL, 5);
	GridSizer1 = new wxGridSizer(0, 3, 0, 0);
	TextCtrl8 = new wxTextCtrl(Panel1, ID_TEXTCTRL8, _("1 Nr telefonu"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL8"));
	GridSizer1->Add(TextCtrl8, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	TextCtrl9 = new wxTextCtrl(Panel1, ID_TEXTCTRL9, _("2 Nr telefonu"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL9"));
	TextCtrl9->Hide();
	GridSizer1->Add(TextCtrl9, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	TextCtrl10 = new wxTextCtrl(Panel1, ID_TEXTCTRL10, _("3 Nr telefonu"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL10"));
	TextCtrl10->Hide();
	GridSizer1->Add(TextCtrl10, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	TextCtrl11 = new wxTextCtrl(Panel1, ID_TEXTCTRL11, _("4 Nr telefonu"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL11"));
	TextCtrl11->Hide();
	GridSizer1->Add(TextCtrl11, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	TextCtrl12 = new wxTextCtrl(Panel1, ID_TEXTCTRL12, _("5 Nr telefonu"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL12"));
	TextCtrl12->Hide();
	GridSizer1->Add(TextCtrl12, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	TextCtrl13 = new wxTextCtrl(Panel1, ID_TEXTCTRL13, _("6 Nr telefonu"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL13"));
	TextCtrl13->Hide();
	GridSizer1->Add(TextCtrl13, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer4->Add(GridSizer1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer4->Add(BoxSizer4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer1->Add(StaticBoxSizer4, 1, wxALL|wxEXPAND, 5);
	StaticBoxSizer6 = new wxStaticBoxSizer(wxHORIZONTAL, Panel1, _("Adres email"));
	BoxSizer5 = new wxBoxSizer(wxHORIZONTAL);
	StaticBoxSizer7 = new wxStaticBoxSizer(wxHORIZONTAL, Panel1, _("Podaj ilosc adresow email"));
	Choice2 = new wxChoice(Panel1, ID_CHOICE2, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE2"));
	Choice2->Append(_("0"));
	Choice2->SetSelection( Choice2->Append(_("1")) );
	Choice2->Append(_("2"));
	Choice2->Append(_("3"));
	Choice2->Append(_("4"));
	Choice2->Append(_("5"));
	Choice2->Append(_("6"));
	StaticBoxSizer7->Add(Choice2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	GridSizer2 = new wxGridSizer(0, 3, 0, 0);
	TextCtrl14 = new wxTextCtrl(Panel1, ID_TEXTCTRL14, _("1 email"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL14"));
	GridSizer2->Add(TextCtrl14, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	TextCtrl15 = new wxTextCtrl(Panel1, ID_TEXTCTRL15, _("2 email"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL15"));
	TextCtrl15->Hide();
	GridSizer2->Add(TextCtrl15, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	TextCtrl16 = new wxTextCtrl(Panel1, ID_TEXTCTRL16, _("3 email"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL16"));
	TextCtrl16->Hide();
	GridSizer2->Add(TextCtrl16, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	TextCtrl17 = new wxTextCtrl(Panel1, ID_TEXTCTRL17, _("4 email"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL17"));
	TextCtrl17->Hide();
	GridSizer2->Add(TextCtrl17, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	TextCtrl18 = new wxTextCtrl(Panel1, ID_TEXTCTRL18, _("5 email"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL18"));
	TextCtrl18->Hide();
	GridSizer2->Add(TextCtrl18, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	TextCtrl19 = new wxTextCtrl(Panel1, ID_TEXTCTRL19, _("6 email"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL19"));
	TextCtrl19->Hide();
	GridSizer2->Add(TextCtrl19, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer7->Add(GridSizer2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer5->Add(StaticBoxSizer7, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer6->Add(BoxSizer5, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer1->Add(StaticBoxSizer6, 1, wxALL|wxEXPAND, 5);
	BoxSizer6 = new wxBoxSizer(wxHORIZONTAL);
	Button1 = new wxButton(Panel1, ID_BUTTON1, _("Zapisz"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	BoxSizer6->Add(Button1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Button2 = new wxButton(Panel1, ID_BUTTON2, _("Anuluj"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
	BoxSizer6->Add(Button2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer1->Add(BoxSizer6, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Panel1->SetSizer(StaticBoxSizer1);
	StaticBoxSizer1->Fit(Panel1);
	StaticBoxSizer1->SetSizeHints(Panel1);

	Connect(ID_TEXTCTRL1,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&Dodawanie::OnTextCtrl1TextEnter);
	Connect(ID_TEXTCTRL2,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&Dodawanie::OnTextCtrl2Text);
	Connect(ID_TEXTCTRL3,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&Dodawanie::OnTextCtrl3Text);
	Connect(ID_TEXTCTRL4,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&Dodawanie::OnTextCtrl4Text);
	Connect(ID_TEXTCTRL5,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&Dodawanie::OnTextCtrl5Text);
	Connect(ID_TEXTCTRL6,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&Dodawanie::OnTextCtrl6Text);
	Connect(ID_TEXTCTRL7,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&Dodawanie::OnTextCtrl7Text);
	Connect(ID_CHOICE1,wxEVT_COMMAND_CHOICE_SELECTED,(wxObjectEventFunction)&Dodawanie::OnChoice1Select);
	Connect(ID_TEXTCTRL8,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&Dodawanie::OnTextCtrl8Text);
	Connect(ID_TEXTCTRL9,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&Dodawanie::OnTextCtrl9Text);
	Connect(ID_TEXTCTRL10,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&Dodawanie::OnTextCtrl10Text);
	Connect(ID_TEXTCTRL11,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&Dodawanie::OnTextCtrl11Text);
	Connect(ID_TEXTCTRL12,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&Dodawanie::OnTextCtrl12Text);
	Connect(ID_TEXTCTRL13,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&Dodawanie::OnTextCtrl13Text);
	Connect(ID_CHOICE2,wxEVT_COMMAND_CHOICE_SELECTED,(wxObjectEventFunction)&Dodawanie::OnChoice2Select);
	Connect(ID_TEXTCTRL14,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&Dodawanie::OnTextCtrl14Text);
	Connect(ID_TEXTCTRL15,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&Dodawanie::OnTextCtrl15Text);
	Connect(ID_TEXTCTRL16,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&Dodawanie::OnTextCtrl16Text);
	Connect(ID_TEXTCTRL17,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&Dodawanie::OnTextCtrl17Text);
	Connect(ID_TEXTCTRL18,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&Dodawanie::OnTextCtrl18Text);
	Connect(ID_TEXTCTRL19,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&Dodawanie::OnTextCtrl19Text);
	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Dodawanie::OnButton1Click);
	Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Dodawanie::OnButton2Click);
	//*)
    jedna_osoba->email=NULL;
    jedna_osoba->nr_telefonu=NULL;
}

Dodawanie::~Dodawanie()
{
	//(*Destroy(Dodawanie)
	//*)
}

/*!
*Funkcja ktora w zaleznosci od wybranej pozycji w Choice1 ukrywa lub pokazuje pola do wpisania numerow telefonu.
*W funkcji tej przydzielana jest pamiec na numer telefonu.
*/
void Dodawanie::OnChoice1Select(wxCommandEvent& event)
{
    if(event.GetString()=="0"){
        Dodawanie::TextCtrl8->Hide();
        Dodawanie::TextCtrl9->Hide();
        Dodawanie::TextCtrl10->Hide();
        Dodawanie::TextCtrl11->Hide();
        Dodawanie::TextCtrl12->Hide();
        Dodawanie::TextCtrl13->Hide();
        jedna_osoba->ilosc_nr_telefonu=0;
        jedna_osoba->nr_telefonu=new string[0];
    }if(event.GetString()=="1"){
        Dodawanie::TextCtrl8->Show(true);
        Dodawanie::TextCtrl9->Hide();
        Dodawanie::TextCtrl10->Hide();
        Dodawanie::TextCtrl11->Hide();
        Dodawanie::TextCtrl12->Hide();
        Dodawanie::TextCtrl13->Hide();
        jedna_osoba->ilosc_nr_telefonu=1;
        jedna_osoba->nr_telefonu=new string[1];
    }
    if(event.GetString()=="2"){
        Dodawanie::TextCtrl8->Show(true);
        Dodawanie::TextCtrl9->Show(true);
        Dodawanie::TextCtrl10->Hide();
        Dodawanie::TextCtrl11->Hide();
        Dodawanie::TextCtrl12->Hide();
        Dodawanie::TextCtrl13->Hide();
        jedna_osoba->ilosc_nr_telefonu=2;
        jedna_osoba->nr_telefonu=new string[2];
    }
    if(event.GetString()=="3"){
        Dodawanie::TextCtrl8->Show(true);
        Dodawanie::TextCtrl9->Show(true);
        Dodawanie::TextCtrl10->Show(true);
        Dodawanie::TextCtrl11->Hide();
        Dodawanie::TextCtrl12->Hide();
        Dodawanie::TextCtrl13->Hide();
        jedna_osoba->ilosc_nr_telefonu=3;
        jedna_osoba->nr_telefonu=new string[3];
    }
    if(event.GetString()=="4"){
        Dodawanie::TextCtrl8->Show(true);
        Dodawanie::TextCtrl9->Show(true);
        Dodawanie::TextCtrl10->Show(true);
        Dodawanie::TextCtrl11->Show(true);
        Dodawanie::TextCtrl12->Hide();
        Dodawanie::TextCtrl13->Hide();
        jedna_osoba->ilosc_nr_telefonu=4;
        jedna_osoba->nr_telefonu=new string[4];
    }
    if(event.GetString()=="5"){
        Dodawanie::TextCtrl8->Show(true);
        Dodawanie::TextCtrl9->Show(true);
        Dodawanie::TextCtrl10->Show(true);
        Dodawanie::TextCtrl11->Show(true);
        Dodawanie::TextCtrl12->Show(true);
        Dodawanie::TextCtrl13->Hide();
        jedna_osoba->ilosc_nr_telefonu=5;
        jedna_osoba->nr_telefonu=new string[5];
    }
    if(event.GetString()=="6"){
        Dodawanie::TextCtrl8->Show(true);
        Dodawanie::TextCtrl9->Show(true);
        Dodawanie::TextCtrl10->Show(true);
        Dodawanie::TextCtrl11->Show(true);
        Dodawanie::TextCtrl12->Show(true);
        Dodawanie::TextCtrl13->Show(true);
        jedna_osoba->ilosc_nr_telefonu=6;
        jedna_osoba->nr_telefonu=new string[6];
    }
}

/*!
*Funkcja ktora w zaleznosci od wybranej pozycji w Choice2 ukrywa lub pokazuje pola do wpisania adresu email.
*W funkcji tej przydzielana jest pamiec na adres email.
*/
void Dodawanie::OnChoice2Select(wxCommandEvent& event)
{
    if(event.GetString()=="0"){
        Dodawanie::TextCtrl14->Hide();
        Dodawanie::TextCtrl15->Hide();
        Dodawanie::TextCtrl16->Hide();
        Dodawanie::TextCtrl17->Hide();
        Dodawanie::TextCtrl18->Hide();
        Dodawanie::TextCtrl19->Hide();
        jedna_osoba->ilosc_adresow_email=0;
        jedna_osoba->email=new string[0];
    }
    if(event.GetString()=="1"){
        Dodawanie::TextCtrl14->Show(true);
        Dodawanie::TextCtrl15->Hide();
        Dodawanie::TextCtrl16->Hide();
        Dodawanie::TextCtrl17->Hide();
        Dodawanie::TextCtrl18->Hide();
        Dodawanie::TextCtrl19->Hide();
        jedna_osoba->ilosc_adresow_email=1;
        jedna_osoba->email=new string[1];
    }
    if(event.GetString()=="2"){
        Dodawanie::TextCtrl14->Show(true);
        Dodawanie::TextCtrl15->Show(true);
        Dodawanie::TextCtrl16->Hide();
        Dodawanie::TextCtrl17->Hide();
        Dodawanie::TextCtrl18->Hide();
        Dodawanie::TextCtrl19->Hide();
        jedna_osoba->ilosc_adresow_email=2;
        jedna_osoba->email=new string[2];
    }
    if(event.GetString()=="3"){
        Dodawanie::TextCtrl14->Show(true);
        Dodawanie::TextCtrl15->Show(true);
        Dodawanie::TextCtrl16->Show(true);
        Dodawanie::TextCtrl17->Hide();
        Dodawanie::TextCtrl18->Hide();
        Dodawanie::TextCtrl19->Hide();
        jedna_osoba->ilosc_adresow_email=3;
        jedna_osoba->email=new string[3];
    }
    if(event.GetString()=="4"){
        Dodawanie::TextCtrl14->Show(true);
        Dodawanie::TextCtrl15->Show(true);
        Dodawanie::TextCtrl16->Show(true);
        Dodawanie::TextCtrl17->Show(true);
        Dodawanie::TextCtrl18->Hide();
        Dodawanie::TextCtrl19->Hide();
        jedna_osoba->ilosc_adresow_email=4;
        jedna_osoba->email=new string[4];
    }
    if(event.GetString()=="5"){
        Dodawanie::TextCtrl14->Show(true);
        Dodawanie::TextCtrl15->Show(true);
        Dodawanie::TextCtrl16->Show(true);
        Dodawanie::TextCtrl17->Show(true);
        Dodawanie::TextCtrl18->Show(true);
        Dodawanie::TextCtrl19->Hide();
        jedna_osoba->ilosc_adresow_email=5;
        jedna_osoba->email=new string[5];
    }
    if(event.GetString()=="6"){
        Dodawanie::TextCtrl14->Show(true);
        Dodawanie::TextCtrl15->Show(true);
        Dodawanie::TextCtrl16->Show(true);
        Dodawanie::TextCtrl17->Show(true);
        Dodawanie::TextCtrl18->Show(true);
        Dodawanie::TextCtrl19->Show(true);
        jedna_osoba->ilosc_adresow_email=6;
        jedna_osoba->email=new string[6];
    }
}

/*!
*Funkcja ktora zamyka okno dodawania danych.
*/
void Dodawanie::OnButton2Click(wxCommandEvent& event)
{
    Close();
}

/*!
*Funkcja ktora zapisuje do tymczasowej zmiennej wskaznikowej dane zczytywane z pola tekstowego TextCtrl1.
*Wczytywanie imienia.
*/
void Dodawanie::OnTextCtrl1TextEnter(wxCommandEvent& event)
{
    jedna_osoba->imie=event.GetString();
}

/*!
*Funkcja ktora zapisuje do tymczasowej zmiennej wskaznikowej dane zczytywane z pola tekstowego TextCtrl2
*Wczytywanie nazwiska
*/
void Dodawanie::OnTextCtrl2Text(wxCommandEvent& event)
{
    jedna_osoba->nazwisko=event.GetString();
}


/*!
*Funkcja ktora zapisuje do tymczasowej zmiennej wskaznikowej dane zczytywane z pola tekstowego TextCtrl3.
*Wczytywanie miasta.
*/
void Dodawanie::OnTextCtrl3Text(wxCommandEvent& event)
{
    jedna_osoba->miasto=event.GetString();
}

/*!
*Funkcja ktora zapisuje do tymczasowej zmiennej wskaznikowej dane zczytywane z pola tekstowego TextCtrl4.
*Wczytywanie ulicy.
*/
void Dodawanie::OnTextCtrl4Text(wxCommandEvent& event)
{
    jedna_osoba->ulica=event.GetString();
}

/*!
*Funkcja ktora zapisuje do tymczasowej zmiennej wskaznikowej dane zczytywane z pola tekstowego TextCtrl5.
*Wczytywanie numeru domu.
*/
void Dodawanie::OnTextCtrl5Text(wxCommandEvent& event)
{
    jedna_osoba->nr_domu=event.GetString();
}

/*!
*Funkcja ktora zapisuje do tymczasowej zmiennej wskaznikowej dane zczytywane z pola tekstowego TextCtrl6.
*Wczytywanie kodu pocztowego.
*/
void Dodawanie::OnTextCtrl6Text(wxCommandEvent& event)
{
    jedna_osoba->kod_pocztowy=event.GetString();
}

/*!
*Funkcja ktora zapisuje do tymczasowej zmiennej wskaznikowej dane zczytywane z pola tekstowego TextCtrl7.
*Wczytywanie poczty.
*/
void Dodawanie::OnTextCtrl7Text(wxCommandEvent& event)
{
    jedna_osoba->poczta=event.GetString();
}

/*!
*Funkcja ktora zapisuje do tymczasowej zmiennej wskaznikowej dane zczytywane z pola tekstowego TextCtrl8.
*Wczytywanie pierwszego numeru telefonu.
*/
void Dodawanie::OnTextCtrl8Text(wxCommandEvent& event)
{
    if(Choice1->GetCurrentSelection()==1){
        jedna_osoba->ilosc_nr_telefonu=1;
        jedna_osoba->nr_telefonu=new string[1];
    }
    jedna_osoba->nr_telefonu[0]=event.GetString();
}

/*!
*Funkcja ktora zapisuje do tymczasowej zmiennej wskaznikowej dane zczytywane z pola tekstowego TextCtrl9.
*Wczytywanie drugiego numeru telefonu.
*/
void Dodawanie::OnTextCtrl9Text(wxCommandEvent& event)
{
    jedna_osoba->nr_telefonu[1]=event.GetString();
}

/*!
*Funkcja ktora zapisuje do tymczasowej zmiennej wskaznikowej dane zczytywane z pola tekstowego TextCtrl10.
*Wczytywanie trzeciego numeru telefonu.
*/
void Dodawanie::OnTextCtrl10Text(wxCommandEvent& event)
{
    jedna_osoba->nr_telefonu[2]=event.GetString();
}

/*!
*Funkcja ktora zapisuje do tymczasowej zmiennej wskaznikowej dane zczytywane z pola tekstowego TextCtrl11.
*Wczytywanie czwartego numeru telefonu.
*/
void Dodawanie::OnTextCtrl11Text(wxCommandEvent& event)
{
    jedna_osoba->nr_telefonu[3]=event.GetString();
}

/*!
*Funkcja ktora zapisuje do tymczasowej zmiennej wskaznikowej dane zczytywane z pola tekstowego TextCtrl12.
*Wczytywanie piatego numeru telefonu.
*/
void Dodawanie::OnTextCtrl12Text(wxCommandEvent& event)
{
    jedna_osoba->nr_telefonu[4]=event.GetString();
}

/*!
*Funkcja ktora zapisuje do tymczasowej zmiennej wskaznikowej dane zczytywane z pola tekstowego TextCtrl13.
*Wczytywanie szostego numeru telefonu.
*/
void Dodawanie::OnTextCtrl13Text(wxCommandEvent& event)
{
    jedna_osoba->nr_telefonu[5]=event.GetString();
}

/*!
*Funkcja ktora zapisuje do tymczasowej zmiennej wskaznikowej dane zczytywane z pola tekstowego TextCtrl14.
*Wczytywanie pierwszego adresu email.
*/
void Dodawanie::OnTextCtrl14Text(wxCommandEvent& event)
{
    if(Choice2->GetCurrentSelection()==1){
        jedna_osoba->ilosc_adresow_email=1;
        jedna_osoba->email=new string[1];
    }
    jedna_osoba->email[0]=event.GetString();
}

/*!
*Funkcja ktora zapisuje do tymczasowej zmiennej wskaznikowej dane zczytywane z pola tekstowego TextCtrl15.
*Wczytywanie drugiego adresu email.
*/
void Dodawanie::OnTextCtrl15Text(wxCommandEvent& event)
{
    jedna_osoba->email[1]=event.GetString();
}

/*!
*Funkcja ktora zapisuje do tymczasowej zmiennej wskaznikowej dane zczytywane z pola tekstowego TextCtrl16.
*Wczytywanie trzeciego adresu email.
*/
void Dodawanie::OnTextCtrl16Text(wxCommandEvent& event)
{
    jedna_osoba->email[2]=event.GetString();
}

/*!
*Funkcja ktora zapisuje do tymczasowej zmiennej wskaznikowej dane zczytywane z pola tekstowego TextCtrl17.
*Wczytywanie czwartego adresu email.
*/
void Dodawanie::OnTextCtrl17Text(wxCommandEvent& event)
{
    jedna_osoba->email[3]=event.GetString();
}

/*!
*Funkcja ktora zapisuje do tymczasowej zmiennej wskaznikowej dane zczytywane z pola tekstowego TextCtrl18.
*Wczytywanie piatego adresu email.
*/
void Dodawanie::OnTextCtrl18Text(wxCommandEvent& event)
{
    jedna_osoba->email[4]=event.GetString();
}

/*!
*Funkcja ktora zapisuje do tymczasowej zmiennej wskaznikowej dane zczytywane z pola tekstowego TextCtrl19.
*Wczytywanie szostego adresu email.
*/
void Dodawanie::OnTextCtrl19Text(wxCommandEvent& event)
{
    jedna_osoba->email[5]=event.GetString();
}

/*!
*Funkcja ta zapisuje dane do bazy kontaktow w zmiennej baza_kontaktow.
*Po tej operacji zostaje rowniez zauktualizowany plik z baza kontaktow w postaci pliku *.txt.
*Na koncu zostaje zwalniana pamiec po tymczasowej zmiennej i zostaje zamykane okno.
*/
void Dodawanie::OnButton1Click(wxCommandEvent& event)
{
    if(jedna_osoba->nr_telefonu==NULL){
        jedna_osoba->ilosc_nr_telefonu=1;
        jedna_osoba->nr_telefonu=new string[1];
        jedna_osoba->nr_telefonu[0]="";
    }
    if(jedna_osoba->email==NULL){
        jedna_osoba->ilosc_adresow_email=1;
        jedna_osoba->email=new string[1];
        jedna_osoba->email[0]="";
    }
    baza_kontaktow=dodawanie_danych(&baza_kontaktow,
                                    jedna_osoba->imie,
                                    jedna_osoba->nazwisko,
                                    jedna_osoba->miasto,
                                    jedna_osoba->ulica,
                                    jedna_osoba->nr_domu,
                                    jedna_osoba->kod_pocztowy,
                                    jedna_osoba->poczta,
                                    jedna_osoba->ilosc_nr_telefonu,
                                    jedna_osoba->nr_telefonu,
                                    jedna_osoba->ilosc_adresow_email,
                                    jedna_osoba->email);
    int blad=zapisywanie_do_pliku(baza_kontaktow,*nazwa_pliku);
    if(blad==-1){
        int Okno_bledu = wxMessageBox("Blad otwarcia pliku z do zapisu","Blad", wxYES_DEFAULT | wxICON_ERROR);
        if(Okno_bledu == wxYES)
            ;
    }

    jedna_osoba->id_s="";
    jedna_osoba->imie="";
    jedna_osoba->nazwisko="";
    jedna_osoba->miasto="";
    jedna_osoba->ulica="";
    jedna_osoba->nr_domu="";
    jedna_osoba->kod_pocztowy="";
    jedna_osoba->poczta="";
    free(jedna_osoba->nr_telefonu);
    free(jedna_osoba->email);
    free(jedna_osoba);
    Close();
}
