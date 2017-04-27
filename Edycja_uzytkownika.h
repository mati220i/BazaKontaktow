#ifndef EDYCJA_UZYTKOWNIKA_H
#define EDYCJA_UZYTKOWNIKA_H

//(*Headers(Edycja_uzytkownika)
#include <wx/sizer.h>
#include <wx/textctrl.h>
#include <wx/button.h>
#include <wx/dialog.h>
//*)

class Edycja_uzytkownika: public wxDialog
{
	public:

		Edycja_uzytkownika(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~Edycja_uzytkownika();

		//(*Declarations(Edycja_uzytkownika)
		wxButton* Button1;
		wxButton* Button2;
		wxTextCtrl* TextCtrl2;
		wxTextCtrl* TextCtrl1;
		//*)

	protected:

		//(*Identifiers(Edycja_uzytkownika)
		static const long ID_TEXTCTRL1;
		static const long ID_TEXTCTRL2;
		static const long ID_BUTTON1;
		static const long ID_BUTTON2;
		//*)

	private:

		//(*Handlers(Edycja_uzytkownika)
		void OnButton1Click_Zapisz(wxCommandEvent& event);
		void OnTextCtrl1Text_Wpisz_nazwe(wxCommandEvent& event);
		void OnTextCtrl2Text_Wpisz_haslo(wxCommandEvent& event);
		void OnButton2Click_Anuluj(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
