#include "Edycja.h"
#include "Wyswietlanie.h"
#include "lista.h"
#include <sstream>
#include <wx/msgdlg.h>

using namespace std;

/*!
*Zmienna w ktorej zapisany jest nr ID zaznaczonego uzytkownika.
*Jest to odwolanie do deklaracji znajdujacej sie w innym pliku.
*/
extern string *zaznaczony;
/*!
*Zmienna w ktorej znajduja sie kontakty.
*Dane dodawane sa w niej w sposob dynamiczny.
*Jest to odwolanie do deklaracji znajdujacej sie w innym pliku.
*/
extern struct osoba *baza_kontaktow;
/*!
*Zmienna w ktorej zapisywane sa tymczasowe dane o osobie, ktore potem zostaja zapisane (edytowane).
*Poczatkowo pusta.
*/
struct osoba *jedna_osoba1=new osoba;
/*!
*Zmienna strukturalna oparta na liscie jednokierunkowej.
*W programie sluzy ona jako kopia oryginalnej listy kontakow na ktorej zostaja dokonane operacje w trakcie dzialania programu.
*Poczatkowo pusta.
*/
struct osoba *kopia_bazy=NULL;
/*!
*nazwa_pliku - przechowuje czesc nazwy pliku aktualnie uzywanego uzytkownika.
*odwolanie do deklaracji znajdujacej sie w innym pliku.
*/
extern string *nazwa_pliku;


//(*InternalHeaders(Edycja)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(Edycja)
const long Edycja::ID_TEXTCTRL1 = wxNewId();
const long Edycja::ID_TEXTCTRL2 = wxNewId();
const long Edycja::ID_TEXTCTRL3 = wxNewId();
const long Edycja::ID_TEXTCTRL4 = wxNewId();
const long Edycja::ID_TEXTCTRL5 = wxNewId();
const long Edycja::ID_TEXTCTRL6 = wxNewId();
const long Edycja::ID_TEXTCTRL7 = wxNewId();
const long Edycja::ID_CHOICE1 = wxNewId();
const long Edycja::ID_TEXTCTRL8 = wxNewId();
const long Edycja::ID_TEXTCTRL9 = wxNewId();
const long Edycja::ID_TEXTCTRL10 = wxNewId();
const long Edycja::ID_TEXTCTRL11 = wxNewId();
const long Edycja::ID_TEXTCTRL12 = wxNewId();
const long Edycja::ID_TEXTCTRL13 = wxNewId();
const long Edycja::ID_CHOICE2 = wxNewId();
const long Edycja::ID_TEXTCTRL14 = wxNewId();
const long Edycja::ID_TEXTCTRL15 = wxNewId();
const long Edycja::ID_TEXTCTRL16 = wxNewId();
const long Edycja::ID_TEXTCTRL17 = wxNewId();
const long Edycja::ID_TEXTCTRL18 = wxNewId();
const long Edycja::ID_TEXTCTRL19 = wxNewId();
const long Edycja::ID_BUTTON1 = wxNewId();
const long Edycja::ID_BUTTON2 = wxNewId();
const long Edycja::ID_PANEL1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(Edycja,wxFrame)
	//(*EventTable(Edycja)
	//*)
END_EVENT_TABLE()

/*!
*Konstruktor tworzacy okno edycji.
*Sa w niej tworzone przyciski, pola tekstowe, pola wyboru.
*/
Edycja::Edycja(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(Edycja)
	wxBoxSizer* BoxSizer4;
	wxStaticBoxSizer* StaticBoxSizer2;
	wxBoxSizer* BoxSizer5;
	wxStaticBoxSizer* StaticBoxSizer12;
	wxStaticBoxSizer* StaticBoxSizer4;
	wxStaticBoxSizer* StaticBoxSizer9;
	wxBoxSizer* BoxSizer2;
	wxStaticBoxSizer* StaticBoxSizer7;
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

	Create(parent, wxID_ANY, _("Edytuj Kontakt"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
	SetClientSize(wxSize(810,710));
	SetMinSize(wxSize(800,720));
	SetMaxSize(wxSize(800,720));
	Panel1 = new wxPanel(this, ID_PANEL1, wxPoint(400,480), wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
	StaticBoxSizer1 = new wxStaticBoxSizer(wxVERTICAL, Panel1, _("Edycja Kontaktu"));
	BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
	StaticBoxSizer2 = new wxStaticBoxSizer(wxHORIZONTAL, Panel1, _("Imie"));
	TextCtrl1 = new wxTextCtrl(Panel1, ID_TEXTCTRL1, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	StaticBoxSizer2->Add(TextCtrl1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(StaticBoxSizer2, 1, wxALL|wxEXPAND, 5);
	StaticBoxSizer3 = new wxStaticBoxSizer(wxHORIZONTAL, Panel1, _("Nazwisko"));
	TextCtrl2 = new wxTextCtrl(Panel1, ID_TEXTCTRL2, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
	StaticBoxSizer3->Add(TextCtrl2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(StaticBoxSizer3, 1, wxALL|wxEXPAND, 5);
	StaticBoxSizer1->Add(BoxSizer1, 0, wxALL|wxEXPAND, 5);
	BoxSizer2 = new wxBoxSizer(wxVERTICAL);
	BoxSizer3 = new wxBoxSizer(wxHORIZONTAL);
	StaticBoxSizer4 = new wxStaticBoxSizer(wxHORIZONTAL, Panel1, _("Miasto"));
	TextCtrl3 = new wxTextCtrl(Panel1, ID_TEXTCTRL3, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL3"));
	StaticBoxSizer4->Add(TextCtrl3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer3->Add(StaticBoxSizer4, 1, wxALL|wxEXPAND, 5);
	StaticBoxSizer5 = new wxStaticBoxSizer(wxHORIZONTAL, Panel1, _("Ulica"));
	TextCtrl4 = new wxTextCtrl(Panel1, ID_TEXTCTRL4, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL4"));
	StaticBoxSizer5->Add(TextCtrl4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer3->Add(StaticBoxSizer5, 1, wxALL|wxEXPAND, 5);
	StaticBoxSizer6 = new wxStaticBoxSizer(wxHORIZONTAL, Panel1, _("Nr Domu"));
	TextCtrl5 = new wxTextCtrl(Panel1, ID_TEXTCTRL5, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL5"));
	StaticBoxSizer6->Add(TextCtrl5, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer3->Add(StaticBoxSizer6, 1, wxALL|wxEXPAND, 5);
	BoxSizer2->Add(BoxSizer3, 1, wxALL|wxEXPAND, 5);
	BoxSizer4 = new wxBoxSizer(wxHORIZONTAL);
	StaticBoxSizer7 = new wxStaticBoxSizer(wxHORIZONTAL, Panel1, _("Kod Pocztowy"));
	TextCtrl6 = new wxTextCtrl(Panel1, ID_TEXTCTRL6, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL6"));
	StaticBoxSizer7->Add(TextCtrl6, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer4->Add(StaticBoxSizer7, 1, wxALL|wxEXPAND, 5);
	StaticBoxSizer8 = new wxStaticBoxSizer(wxHORIZONTAL, Panel1, _("Poczta"));
	TextCtrl7 = new wxTextCtrl(Panel1, ID_TEXTCTRL7, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL7"));
	StaticBoxSizer8->Add(TextCtrl7, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer4->Add(StaticBoxSizer8, 1, wxALL|wxEXPAND, 5);
	BoxSizer2->Add(BoxSizer4, 1, wxALL|wxEXPAND, 5);
	StaticBoxSizer1->Add(BoxSizer2, 1, wxALL|wxEXPAND, 5);
	StaticBoxSizer9 = new wxStaticBoxSizer(wxHORIZONTAL, Panel1, _("Nr Telefonu"));
	StaticBoxSizer10 = new wxStaticBoxSizer(wxHORIZONTAL, Panel1, _("Podaj ilosc nr telefonu"));
	Choice1 = new wxChoice(Panel1, ID_CHOICE1, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE1"));
	Choice1->Append(_("0"));
	Choice1->Append(_("1"));
	Choice1->Append(_("2"));
	Choice1->Append(_("3"));
	Choice1->Append(_("4"));
	Choice1->Append(_("5"));
	Choice1->Append(_("6"));
	Choice1->SetMaxSize(wxSize(370,-1));
	StaticBoxSizer10->Add(Choice1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	GridSizer1 = new wxGridSizer(0, 3, 0, 0);
	TextCtrl8 = new wxTextCtrl(Panel1, ID_TEXTCTRL8, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL8"));
	GridSizer1->Add(TextCtrl8, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	TextCtrl9 = new wxTextCtrl(Panel1, ID_TEXTCTRL9, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL9"));
	GridSizer1->Add(TextCtrl9, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	TextCtrl10 = new wxTextCtrl(Panel1, ID_TEXTCTRL10, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL10"));
	GridSizer1->Add(TextCtrl10, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	TextCtrl11 = new wxTextCtrl(Panel1, ID_TEXTCTRL11, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL11"));
	GridSizer1->Add(TextCtrl11, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	TextCtrl12 = new wxTextCtrl(Panel1, ID_TEXTCTRL12, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL12"));
	GridSizer1->Add(TextCtrl12, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	TextCtrl13 = new wxTextCtrl(Panel1, ID_TEXTCTRL13, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL13"));
	GridSizer1->Add(TextCtrl13, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer10->Add(GridSizer1, 1, wxALL|wxFIXED_MINSIZE, 5);
	StaticBoxSizer9->Add(StaticBoxSizer10, 1, wxALL|wxEXPAND, 5);
	StaticBoxSizer1->Add(StaticBoxSizer9, 0, wxALL|wxEXPAND, 5);
	StaticBoxSizer11 = new wxStaticBoxSizer(wxHORIZONTAL, Panel1, _("Adres Email"));
	StaticBoxSizer12 = new wxStaticBoxSizer(wxHORIZONTAL, Panel1, _("Podaj ilosc adresow email"));
	Choice2 = new wxChoice(Panel1, ID_CHOICE2, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE2"));
	Choice2->Append(_("0"));
	Choice2->Append(_("1"));
	Choice2->Append(_("2"));
	Choice2->Append(_("3"));
	Choice2->Append(_("4"));
	Choice2->Append(_("5"));
	Choice2->Append(_("6"));
	StaticBoxSizer12->Add(Choice2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	GridSizer2 = new wxGridSizer(0, 3, 0, 0);
	TextCtrl14 = new wxTextCtrl(Panel1, ID_TEXTCTRL14, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL14"));
	GridSizer2->Add(TextCtrl14, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	TextCtrl15 = new wxTextCtrl(Panel1, ID_TEXTCTRL15, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL15"));
	GridSizer2->Add(TextCtrl15, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	TextCtrl16 = new wxTextCtrl(Panel1, ID_TEXTCTRL16, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL16"));
	GridSizer2->Add(TextCtrl16, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	TextCtrl17 = new wxTextCtrl(Panel1, ID_TEXTCTRL17, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL17"));
	GridSizer2->Add(TextCtrl17, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	TextCtrl18 = new wxTextCtrl(Panel1, ID_TEXTCTRL18, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL18"));
	GridSizer2->Add(TextCtrl18, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	TextCtrl19 = new wxTextCtrl(Panel1, ID_TEXTCTRL19, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL19"));
	GridSizer2->Add(TextCtrl19, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer12->Add(GridSizer2, 1, wxALL|wxEXPAND, 5);
	StaticBoxSizer11->Add(StaticBoxSizer12, 1, wxALL|wxEXPAND, 5);
	StaticBoxSizer1->Add(StaticBoxSizer11, 0, wxALL|wxEXPAND, 5);
	BoxSizer5 = new wxBoxSizer(wxHORIZONTAL);
	Button1 = new wxButton(Panel1, ID_BUTTON1, _("Zapisz"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	BoxSizer5->Add(Button1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Button2 = new wxButton(Panel1, ID_BUTTON2, _("Anuluj"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
	BoxSizer5->Add(Button2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer1->Add(BoxSizer5, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Panel1->SetSizer(StaticBoxSizer1);
	StaticBoxSizer1->Fit(Panel1);
	StaticBoxSizer1->SetSizeHints(Panel1);

	Connect(ID_TEXTCTRL1,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&Edycja::OnTextCtrl1Text);
	Connect(ID_TEXTCTRL2,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&Edycja::OnTextCtrl2Text);
	Connect(ID_TEXTCTRL3,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&Edycja::OnTextCtrl3Text);
	Connect(ID_TEXTCTRL4,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&Edycja::OnTextCtrl4Text);
	Connect(ID_TEXTCTRL5,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&Edycja::OnTextCtrl5Text);
	Connect(ID_TEXTCTRL6,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&Edycja::OnTextCtrl6Text);
	Connect(ID_TEXTCTRL7,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&Edycja::OnTextCtrl7Text);
	Connect(ID_CHOICE1,wxEVT_COMMAND_CHOICE_SELECTED,(wxObjectEventFunction)&Edycja::OnChoice1Select);
	Connect(ID_TEXTCTRL8,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&Edycja::OnTextCtrl8Text);
	Connect(ID_TEXTCTRL9,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&Edycja::OnTextCtrl9Text);
	Connect(ID_TEXTCTRL10,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&Edycja::OnTextCtrl10Text);
	Connect(ID_TEXTCTRL11,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&Edycja::OnTextCtrl11Text);
	Connect(ID_TEXTCTRL12,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&Edycja::OnTextCtrl12Text);
	Connect(ID_TEXTCTRL13,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&Edycja::OnTextCtrl13Text);
	Connect(ID_CHOICE2,wxEVT_COMMAND_CHOICE_SELECTED,(wxObjectEventFunction)&Edycja::OnChoice2Select);
	Connect(ID_TEXTCTRL14,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&Edycja::OnTextCtrl14Text);
	Connect(ID_TEXTCTRL15,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&Edycja::OnTextCtrl15Text);
	Connect(ID_TEXTCTRL16,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&Edycja::OnTextCtrl16Text);
	Connect(ID_TEXTCTRL17,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&Edycja::OnTextCtrl17Text);
	Connect(ID_TEXTCTRL18,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&Edycja::OnTextCtrl18Text);
	Connect(ID_TEXTCTRL19,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&Edycja::OnTextCtrl19Text);
	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Edycja::OnButton1Click);
	Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Edycja::OnButton2ClickAnuluj);
	//*)



    /*!
    *Do zmiennej kopia_bazy zostaje skopiowana oryginalna lista bazy kontaktow korzystajc z funkcji pomocniczej.
    *Na tej liscie beda wykonywane operacje ktore nie wplyna na oryginalna liste kontaktow.
    */
    kopia_bazy=kopiowanie_listy(kopia_bazy,baza_kontaktow);

    /*!
    *Zostaje wyszukany kontakt ktory ma zostac edytowany.
    *Jego adres zostanie ostatecznie zapisany do zmiennej kopia_bazy ktora bedzie wykorzystywana w programie.
    */
    while(kopia_bazy){
        if(kopia_bazy->id==to_int(*zaznaczony))
            break;
        kopia_bazy=kopia_bazy->next;
    }

    /*!
    *Zostaja wypelnione pola tekstowe edytowanego kontaktu.
    */
    TextCtrl1->SetLabel(kopia_bazy->imie);
    TextCtrl2->SetLabel(kopia_bazy->nazwisko);
    TextCtrl3->SetLabel(kopia_bazy->miasto);
    TextCtrl4->SetLabel(kopia_bazy->ulica);
    TextCtrl5->SetLabel(kopia_bazy->nr_domu);
    TextCtrl6->SetLabel(kopia_bazy->kod_pocztowy);
    TextCtrl7->SetLabel(kopia_bazy->poczta);
    Choice1->SetSelection(kopia_bazy->ilosc_nr_telefonu);
    Choice2->SetSelection(kopia_bazy->ilosc_adresow_email);
    jedna_osoba1->id=kopia_bazy->id;
    jedna_osoba1->id_s=kopia_bazy->id_s;
    jedna_osoba1->nr_telefonu=new string[kopia_bazy->ilosc_nr_telefonu];
    jedna_osoba1->email=new string[kopia_bazy->ilosc_adresow_email];
    jedna_osoba1->ilosc_nr_telefonu=kopia_bazy->ilosc_nr_telefonu;
    jedna_osoba1->ilosc_adresow_email=kopia_bazy->ilosc_adresow_email;
    if(kopia_bazy->ilosc_nr_telefonu==0){
        TextCtrl8->Disable();
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
        TextCtrl14->Disable();
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

}

Edycja::~Edycja()
{
	//(*Destroy(Edycja)
	//*)
}


/*!
*Funkcja ktora w zaleznosci od wybranej wartosci pokazuje lub ukrywa pola tekstowe do edycji/wypisywania danych.
*w zaleznosci od tego ile dany kontakt ma miec numerow telefonu, tyle zostanie przydzielonej pamieci.
*/
void Edycja::OnChoice1Select(wxCommandEvent& event)
{
    if(event.GetString()=="0"){
        Edycja::TextCtrl8->Hide();
        Edycja::TextCtrl9->Hide();
        Edycja::TextCtrl10->Hide();
        Edycja::TextCtrl11->Hide();
        Edycja::TextCtrl12->Hide();
        Edycja::TextCtrl13->Hide();
        jedna_osoba1->ilosc_nr_telefonu=0;
        jedna_osoba1->nr_telefonu=new string[1];
    }if(event.GetString()=="1"){
        Edycja::TextCtrl8->Show(true);
        Edycja::TextCtrl8->Enable();
        Edycja::TextCtrl9->Hide();
        Edycja::TextCtrl10->Hide();
        Edycja::TextCtrl11->Hide();
        Edycja::TextCtrl12->Hide();
        Edycja::TextCtrl13->Hide();
        jedna_osoba1->ilosc_nr_telefonu=1;
        jedna_osoba1->nr_telefonu=new string[1];
    }
    if(event.GetString()=="2"){
        Edycja::TextCtrl8->Show(true);
        Edycja::TextCtrl8->Enable();
        Edycja::TextCtrl9->Show(true);
        Edycja::TextCtrl10->Hide();
        Edycja::TextCtrl11->Hide();
        Edycja::TextCtrl12->Hide();
        Edycja::TextCtrl13->Hide();
        jedna_osoba1->ilosc_nr_telefonu=2;
        jedna_osoba1->nr_telefonu=new string[2];
    }
    if(event.GetString()=="3"){
        Edycja::TextCtrl8->Show(true);
        Edycja::TextCtrl8->Enable();
        Edycja::TextCtrl9->Show(true);
        Edycja::TextCtrl10->Show(true);
        Edycja::TextCtrl11->Hide();
        Edycja::TextCtrl12->Hide();
        Edycja::TextCtrl13->Hide();
        jedna_osoba1->ilosc_nr_telefonu=3;
        jedna_osoba1->nr_telefonu=new string[3];
    }
    if(event.GetString()=="4"){
        Edycja::TextCtrl8->Show(true);
        Edycja::TextCtrl8->Enable();
        Edycja::TextCtrl9->Show(true);
        Edycja::TextCtrl10->Show(true);
        Edycja::TextCtrl11->Show(true);
        Edycja::TextCtrl12->Hide();
        Edycja::TextCtrl13->Hide();
        jedna_osoba1->ilosc_nr_telefonu=4;
        jedna_osoba1->nr_telefonu=new string[4];
    }
    if(event.GetString()=="5"){
        Edycja::TextCtrl8->Show(true);
        Edycja::TextCtrl8->Enable();
        Edycja::TextCtrl9->Show(true);
        Edycja::TextCtrl10->Show(true);
        Edycja::TextCtrl11->Show(true);
        Edycja::TextCtrl12->Show(true);
        Edycja::TextCtrl13->Hide();
        jedna_osoba1->ilosc_nr_telefonu=5;
        jedna_osoba1->nr_telefonu=new string[5];
    }
    if(event.GetString()=="6"){
        Edycja::TextCtrl8->Show(true);
        Edycja::TextCtrl8->Enable();
        Edycja::TextCtrl9->Show(true);
        Edycja::TextCtrl10->Show(true);
        Edycja::TextCtrl11->Show(true);
        Edycja::TextCtrl12->Show(true);
        Edycja::TextCtrl13->Show(true);
        jedna_osoba1->ilosc_nr_telefonu=6;
        jedna_osoba1->nr_telefonu=new string[6];
    }
}

/*!
*Funkcja ktora w zaleznosci od wybranej wartosci pokazuje lub ukrywa pola tekstowe do edycji/wypisywania danych.
*w zaleznosci od tego ile dany kontakt ma miec adresow email, tyle zostanie przydzielonej pamieci.
*/
void Edycja::OnChoice2Select(wxCommandEvent& event)
{
    if(event.GetString()=="0"){
        Edycja::TextCtrl14->Hide();
        Edycja::TextCtrl15->Hide();
        Edycja::TextCtrl16->Hide();
        Edycja::TextCtrl17->Hide();
        Edycja::TextCtrl18->Hide();
        Edycja::TextCtrl19->Hide();
        jedna_osoba1->ilosc_adresow_email=0;
        jedna_osoba1->email=new string[1];
    }
    if(event.GetString()=="1"){
        Edycja::TextCtrl14->Show(true);
        Edycja::TextCtrl14->Enable();
        Edycja::TextCtrl15->Hide();
        Edycja::TextCtrl16->Hide();
        Edycja::TextCtrl17->Hide();
        Edycja::TextCtrl18->Hide();
        Edycja::TextCtrl19->Hide();
        jedna_osoba1->ilosc_adresow_email=1;
        jedna_osoba1->email=new string[1];
    }
    if(event.GetString()=="2"){
        Edycja::TextCtrl14->Show(true);
        Edycja::TextCtrl14->Enable();
        Edycja::TextCtrl15->Show(true);
        Edycja::TextCtrl16->Hide();
        Edycja::TextCtrl17->Hide();
        Edycja::TextCtrl18->Hide();
        Edycja::TextCtrl19->Hide();
        jedna_osoba1->ilosc_adresow_email=2;
        jedna_osoba1->email=new string[2];
    }
    if(event.GetString()=="3"){
        Edycja::TextCtrl14->Show(true);
        Edycja::TextCtrl14->Enable();
        Edycja::TextCtrl15->Show(true);
        Edycja::TextCtrl16->Show(true);
        Edycja::TextCtrl17->Hide();
        Edycja::TextCtrl18->Hide();
        Edycja::TextCtrl19->Hide();
        jedna_osoba1->ilosc_adresow_email=3;
        jedna_osoba1->email=new string[3];
    }
    if(event.GetString()=="4"){
        Edycja::TextCtrl15->Show(true);
        Edycja::TextCtrl14->Enable();
        Edycja::TextCtrl16->Show(true);
        Edycja::TextCtrl17->Show(true);
        Edycja::TextCtrl18->Hide();
        Edycja::TextCtrl19->Hide();
        jedna_osoba1->ilosc_adresow_email=4;
        jedna_osoba1->email=new string[4];
    }
    if(event.GetString()=="5"){
        Edycja::TextCtrl14->Show(true);
        Edycja::TextCtrl14->Enable();
        Edycja::TextCtrl15->Show(true);
        Edycja::TextCtrl16->Show(true);
        Edycja::TextCtrl17->Show(true);
        Edycja::TextCtrl18->Show(true);
        Edycja::TextCtrl19->Hide();
        jedna_osoba1->ilosc_adresow_email=5;
        jedna_osoba1->email=new string[5];
    }
    if(event.GetString()=="6"){
        Edycja::TextCtrl14->Show(true);
        Edycja::TextCtrl14->Enable();
        Edycja::TextCtrl15->Show(true);
        Edycja::TextCtrl16->Show(true);
        Edycja::TextCtrl17->Show(true);
        Edycja::TextCtrl18->Show(true);
        Edycja::TextCtrl19->Show(true);
        jedna_osoba1->ilosc_adresow_email=6;
        jedna_osoba1->email=new string[6];
    }
}

/*!
*Funkcja ktora zczytuje dane z pola tekstowego TextCtrl1 do zmiennej tymczasowej jedna_osoba.
*Zostaje w niej zapisane imie osoby.
*/
void Edycja::OnTextCtrl1Text(wxCommandEvent& event)
{
    jedna_osoba1->imie=event.GetString();
}

/*!
*Funkcja ktora zczytuje dane z pola tekstowego TextCtrl2 do zmiennej tymczasowej jedna_osoba.
*Zostaje w niej zapisane nazwisko osoby.
*/
void Edycja::OnTextCtrl2Text(wxCommandEvent& event)
{
    jedna_osoba1->nazwisko=event.GetString();
}

/*!
*Funkcja ktora zczytuje dane z pola tekstowego TextCtrl3 do zmiennej tymczasowej jedna_osoba.
*Zostaje w niej zapisane miasto osoby.
*/
void Edycja::OnTextCtrl3Text(wxCommandEvent& event)
{
    jedna_osoba1->miasto=event.GetString();

}

/*!
*Funkcja ktora zczytuje dane z pola tekstowego TextCtrl4 do zmiennej tymczasowej jedna_osoba.
*Zostaje w niej zapisana ulica osoby.
*/
void Edycja::OnTextCtrl4Text(wxCommandEvent& event)
{
    jedna_osoba1->ulica=event.GetString();
}

/*!
*Funkcja ktora zczytuje dane z pola tekstowego TextCtrl5 do zmiennej tymczasowej jedna_osoba.
*Zostaje w niej zapisany numer domu osoby.
*/
void Edycja::OnTextCtrl5Text(wxCommandEvent& event)
{
    jedna_osoba1->nr_domu=event.GetString();
}

/*!
*Funkcja ktora zczytuje dane z pola tekstowego TextCtrl6 do zmiennej tymczasowej jedna_osoba.
*Zostaje w niej zapisany kod pocztowy osoby.
*/
void Edycja::OnTextCtrl6Text(wxCommandEvent& event)
{
    jedna_osoba1->kod_pocztowy=event.GetString();
}

/*!
*Funkcja ktora zczytuje dane z pola tekstowego TextCtrl7 do zmiennej tymczasowej jedna_osoba.
*Zostaje w niej zapisana poczta osoby.
*/
void Edycja::OnTextCtrl7Text(wxCommandEvent& event)
{
    jedna_osoba1->poczta=event.GetString();
}

/*!
*Funkcja ktora zczytuje dane z pola tekstowego TextCtrl8 do zmiennej tymczasowej jedna_osoba.
*Zostaje w niej zapisany 1 numer telefonu osoby.
*/
void Edycja::OnTextCtrl8Text(wxCommandEvent& event)
{
    jedna_osoba1->nr_telefonu[0]=event.GetString();
}

/*!
*Funkcja ktora zczytuje dane z pola tekstowego TextCtrl9 do zmiennej tymczasowej jedna_osoba.
*Zostaje w niej zapisany 2 numer telefonu osoby.
*/
void Edycja::OnTextCtrl9Text(wxCommandEvent& event)
{
    jedna_osoba1->nr_telefonu[1]=event.GetString();
}

/*!
*Funkcja ktora zczytuje dane z pola tekstowego TextCtrl10 do zmiennej tymczasowej jedna_osoba.
*Zostaje w niej zapisany 3 numer telefonu osoby.
*/
void Edycja::OnTextCtrl10Text(wxCommandEvent& event)
{
    jedna_osoba1->nr_telefonu[2]=event.GetString();
}

/*!
*Funkcja ktora zczytuje dane z pola tekstowego TextCtrl11 do zmiennej tymczasowej jedna_osoba.
*Zostaje w niej zapisany 4 numer telefonu osoby.
*/
void Edycja::OnTextCtrl11Text(wxCommandEvent& event)
{
    jedna_osoba1->nr_telefonu[3]=event.GetString();
}

/*!
*Funkcja ktora zczytuje dane z pola tekstowego TextCtrl12 do zmiennej tymczasowej jedna_osoba.
*Zostaje w niej zapisany 5 numer telefonu osoby.
*/
void Edycja::OnTextCtrl12Text(wxCommandEvent& event)
{
    jedna_osoba1->nr_telefonu[4]=event.GetString();
}

/*!
*Funkcja ktora zczytuje dane z pola tekstowego TextCtrl13 do zmiennej tymczasowej jedna_osoba.
*Zostaje w niej zapisany 6 numer telefonu osoby.
*/
void Edycja::OnTextCtrl13Text(wxCommandEvent& event)
{
    jedna_osoba1->nr_telefonu[5]=event.GetString();
}

/*!
*Funkcja ktora zczytuje dane z pola tekstowego TextCtrl14 do zmiennej tymczasowej jedna_osoba.
*Zostaje w niej zapisany 1 adres email osoby.
*/
void Edycja::OnTextCtrl14Text(wxCommandEvent& event)
{
    jedna_osoba1->email[0]=event.GetString();
}

/*!
*Funkcja ktora zczytuje dane z pola tekstowego TextCtrl15 do zmiennej tymczasowej jedna_osoba.
*Zostaje w niej zapisany 2 adres email osoby.
*/
void Edycja::OnTextCtrl15Text(wxCommandEvent& event)
{
    jedna_osoba1->email[1]=event.GetString();
}

/*!
*Funkcja ktora zczytuje dane z pola tekstowego TextCtrl16 do zmiennej tymczasowej jedna_osoba.
*Zostaje w niej zapisany 3 adres email osoby.
*/
void Edycja::OnTextCtrl16Text(wxCommandEvent& event)
{
    jedna_osoba1->email[2]=event.GetString();
}

/*!
*Funkcja ktora zczytuje dane z pola tekstowego TextCtrl17 do zmiennej tymczasowej jedna_osoba.
*Zostaje w niej zapisany 4 adres email osoby.
*/
void Edycja::OnTextCtrl17Text(wxCommandEvent& event)
{
    jedna_osoba1->email[3]=event.GetString();
}

/*!
*Funkcja ktora zczytuje dane z pola tekstowego TextCtrl18 do zmiennej tymczasowej jedna_osoba.
*Zostaje w niej zapisany 5 adres email osoby.
*/
void Edycja::OnTextCtrl18Text(wxCommandEvent& event)
{
    jedna_osoba1->email[4]=event.GetString();
}

/*!
*Funkcja ktora zczytuje dane z pola tekstowego TextCtrl19 do zmiennej tymczasowej jedna_osoba.
*Zostaje w niej zapisany 6 adres email osoby.
*/
void Edycja::OnTextCtrl19Text(wxCommandEvent& event)
{
    jedna_osoba1->email[5]=event.GetString();
}

/*!
*Funkcja ktora regauje na nacisniecie przycisku "Zapisz".
*Funkcja ta zapisuje do zmiennej baza_kontaktow juz zedytowany kontakt za pomoca odpowiedniej funkcji pomocniczej.
*Dodatkowo po calej opercji zostaje zaktualizowana baza kontakotw w postaci pliku *.txt nowymi danymi.
*Na koniec zostaje zwalaniana pamiec juz nieuzywanej zmiennej tymczasowej i zostaje zamkniete okno.
*/
void Edycja::OnButton1Click(wxCommandEvent& event)
{
    if(jedna_osoba1->nr_telefonu==NULL){
        jedna_osoba1->ilosc_nr_telefonu=1;
        jedna_osoba1->nr_telefonu=new string[1];
        jedna_osoba1->nr_telefonu[0]="";
    }
    if(jedna_osoba1->email==NULL){
        jedna_osoba1->ilosc_adresow_email=1;
        jedna_osoba1->email=new string[1];
        jedna_osoba1->email[0]="";
    }

    baza_kontaktow=edycja(&baza_kontaktow,jedna_osoba1->id,jedna_osoba1->id_s,jedna_osoba1->imie,jedna_osoba1->nazwisko,
                                     jedna_osoba1->miasto,jedna_osoba1->ulica,jedna_osoba1->nr_domu,jedna_osoba1->kod_pocztowy,
                                    jedna_osoba1->poczta,jedna_osoba1->ilosc_nr_telefonu,jedna_osoba1->nr_telefonu,
                                    jedna_osoba1->ilosc_adresow_email,jedna_osoba1->email,to_int(*zaznaczony));


    int blad=zapisywanie_do_pliku(baza_kontaktow,*nazwa_pliku);
    if(blad==-1){
        int Okno_bledu = wxMessageBox("Blad otwarcia pliku z do zapisu","Blad", wxYES_DEFAULT | wxICON_ERROR);
        if(Okno_bledu == wxYES)
            ;
    }

    jedna_osoba1->id_s="";
    jedna_osoba1->imie="";
    jedna_osoba1->nazwisko="";
    jedna_osoba1->miasto="";
    jedna_osoba1->ulica="";
    jedna_osoba1->nr_domu="";
    jedna_osoba1->kod_pocztowy="";
    jedna_osoba1->poczta="";
    kopia_bazy=NULL;
    free(jedna_osoba1->nr_telefonu);
    free(jedna_osoba1->email);
    free(jedna_osoba1);
    Close();
}

/*!
*Funkcja reaguje na nacisniecie przycisku "Anuluj".
*Funkcja zwalnia pamiec na zmienna tymczasowa.
*Dane nie zostaja zapisane i zostaje zamkniete okno edycji.
*/
void Edycja::OnButton2ClickAnuluj(wxCommandEvent& event)
{
    free(jedna_osoba1->email);
    free(jedna_osoba1->nr_telefonu);
    free(jedna_osoba1);
    Close();
}
