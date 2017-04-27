#ifndef SPRAWDZANIE_HASLA_H
#define SPRAWDZANIE_HASLA_H

//(*Headers(Sprawdzanie_hasla)
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/button.h>
#include <wx/dialog.h>
//*)

class Sprawdzanie_hasla: public wxDialog
{
	public:

		Sprawdzanie_hasla(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~Sprawdzanie_hasla();

		//(*Declarations(Sprawdzanie_hasla)
		wxButton* Button1;
		wxStaticText* StaticText1;
		wxTextCtrl* TextCtrl1;
		//*)

	protected:

		//(*Identifiers(Sprawdzanie_hasla)
		static const long ID_TEXTCTRL1;
		static const long ID_STATICTEXT1;
		static const long ID_BUTTON1;
		//*)

	private:

		//(*Handlers(Sprawdzanie_hasla)
		void OnTextCtrl1Text_sprawdz_haslo(wxCommandEvent& event);
		void OnTextCtrl1Text_wprowadz_haslo(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
