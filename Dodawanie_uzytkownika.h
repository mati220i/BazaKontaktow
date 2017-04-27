#ifndef DODAWANIE_UZYTKOWNIKA_H
#define DODAWANIE_UZYTKOWNIKA_H

//(*Headers(Dodawanie_uzytkownika)
#include <wx/sizer.h>
#include <wx/textctrl.h>
#include <wx/button.h>
#include <wx/dialog.h>
//*)

class Dodawanie_uzytkownika: public wxDialog
{
	public:

		Dodawanie_uzytkownika(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~Dodawanie_uzytkownika();

		//(*Declarations(Dodawanie_uzytkownika)
		wxButton* Button1;
		wxButton* Button2;
		wxTextCtrl* TextCtrl2;
		wxTextCtrl* TextCtrl1;
		//*)

	protected:

		//(*Identifiers(Dodawanie_uzytkownika)
		static const long ID_TEXTCTRL1;
		static const long ID_TEXTCTRL2;
		static const long ID_BUTTON1;
		static const long ID_BUTTON2;
		//*)

	private:

		//(*Handlers(Dodawanie_uzytkownika)
		void OnButton2Click(wxCommandEvent& event);
		void OnTextCtrl1Text_Wpisz_nazwe(wxCommandEvent& event);
		void OnTextCtrl2Text_Wpisz_haslo(wxCommandEvent& event);
		void OnButton1Click_Dodaj_uzytkownika(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
