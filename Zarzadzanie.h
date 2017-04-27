#ifndef ZARZADZANIE_H
#define ZARZADZANIE_H

//(*Headers(Zarzadzanie)
#include <wx/listctrl.h>
#include <wx/sizer.h>
#include <wx/button.h>
#include <wx/dialog.h>
//*)

class Zarzadzanie: public wxDialog
{
	public:

		Zarzadzanie(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~Zarzadzanie();

		//(*Declarations(Zarzadzanie)
		wxButton* Button1;
		wxButton* Button2;
		wxButton* Button3;
		wxListView* ListView1;
		//*)

	protected:

		//(*Identifiers(Zarzadzanie)
		static const long ID_LISTVIEW1;
		static const long ID_BUTTON1;
		static const long ID_BUTTON2;
		static const long ID_BUTTON3;
		//*)

	private:

		//(*Handlers(Zarzadzanie)
		void OnButton1Click_dodaj_uzytkownika(wxCommandEvent& event);
		void OnButton2Click_Edycja_uzytkownika(wxCommandEvent& event);
		void OnListView1ItemSelect_uzytkownik(wxListEvent& event);
		void OnButton3Click_Usun_uzytkownika(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
