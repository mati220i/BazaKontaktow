#ifndef WYSWIETLANIE_H
#define WYSWIETLANIE_H

//(*Headers(Wyswietlanie)
#include <wx/listctrl.h>
#include <wx/sizer.h>
#include <wx/menu.h>
#include <wx/textctrl.h>
#include <wx/panel.h>
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/statusbr.h>
//*)

class Wyswietlanie: public wxFrame
{
	public:

		Wyswietlanie(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		//static
		void Odswiez();
		virtual ~Wyswietlanie();

		//(*Declarations(Wyswietlanie)
		wxMenuItem* MenuItem8;
		wxTextCtrl* TextCtrl4;
		wxMenuItem* MenuItem7;
		wxMenu Menu1;
		wxButton* Button4;
		wxMenuItem* MenuItem5;
		wxMenuItem* MenuItem2;
		wxMenu* Menu3;
		wxButton* Button1;
		wxTextCtrl* TextCtrl16;
		wxTextCtrl* TextCtrl6;
		wxMenuItem* MenuItem1;
		wxMenuItem* MenuItem4;
		wxTextCtrl* TextCtrl19;
		wxPanel* Panel1;
		wxButton* Button2;
		wxTextCtrl* TextCtrl18;
		wxTextCtrl* TextCtrl17;
		wxMenuItem* MenuItem3;
		wxTextCtrl* TextCtrl14;
		wxButton* Button3;
		wxTextCtrl* TextCtrl15;
		wxTextCtrl* TextCtrl13;
		wxStatusBar* StatusBar1;
		wxListView* ListView1;
		wxMenuItem* MenuItem6;
		wxTextCtrl* TextCtrl8;
		wxTextCtrl* TextCtrl2;
		wxTextCtrl* TextCtrl7;
		wxTextCtrl* TextCtrl1;
		wxTextCtrl* TextCtrl9;
		wxMenuBar* MenuBar1;
		wxTextCtrl* TextCtrl5;
		wxMenu* Menu2;
		wxTextCtrl* TextCtrl3;
		wxTextCtrl* TextCtrl10;
		wxTextCtrl* TextCtrl12;
		wxTextCtrl* TextCtrl11;
		//*)

	protected:

		//(*Identifiers(Wyswietlanie)
		static const long ID_LISTVIEW1;
		static const long ID_BUTTON3;
		static const long ID_BUTTON1;
		static const long ID_BUTTON2;
		static const long ID_BUTTON4;
		static const long ID_TEXTCTRL1;
		static const long ID_TEXTCTRL2;
		static const long ID_TEXTCTRL3;
		static const long ID_TEXTCTRL4;
		static const long ID_TEXTCTRL5;
		static const long ID_TEXTCTRL6;
		static const long ID_TEXTCTRL7;
		static const long ID_TEXTCTRL8;
		static const long ID_TEXTCTRL9;
		static const long ID_TEXTCTRL10;
		static const long ID_TEXTCTRL11;
		static const long ID_TEXTCTRL12;
		static const long ID_TEXTCTRL13;
		static const long ID_TEXTCTRL14;
		static const long ID_TEXTCTRL15;
		static const long ID_TEXTCTRL16;
		static const long ID_TEXTCTRL17;
		static const long ID_TEXTCTRL18;
		static const long ID_TEXTCTRL19;
		static const long ID_PANEL1;
		static const long ID_MENUITEM1;
		static const long ID_MENUITEM2;
		static const long ID_MENUITEM8;
		static const long ID_MENUITEM7;
		static const long ID_MENUITEM3;
		static const long ID_MENUITEM4;
		static const long ID_MENUITEM5;
		static const long ID_MENUITEM6;
		static const long ID_STATUSBAR1;
		//*)

	private:

		//(*Handlers(Wyswietlanie)
		void OnListView1ItemSelect(wxListEvent& event);
		void OnListView1ItemDeselect(wxListEvent& event);
		void OnListView1ItemRClick(wxListEvent& event);
		void OnMenuItem2SelectedUsun(wxCommandEvent& event);
		void OnButton1Click(wxCommandEvent& event);
		void OnMenuItem1SelectedEdytuj(wxCommandEvent& event);
		void OnButton2Click(wxCommandEvent& event);
		void OnButton3ClickUsun(wxCommandEvent& event);
		void OnButton4ClickEdytuj(wxCommandEvent& event);
		void OnMenuItem7Selected_Zamknij(wxCommandEvent& event);
		void OnMenuItem8Selected_Zapisz_do_pliku(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
