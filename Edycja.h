#ifndef EDYCJA_H
#define EDYCJA_H

//(*Headers(Edycja)
#include <wx/sizer.h>
#include <wx/textctrl.h>
#include <wx/panel.h>
#include <wx/choice.h>
#include <wx/button.h>
#include <wx/frame.h>
//*)

class Edycja: public wxFrame
{
	public:

		Edycja(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~Edycja();

		//(*Declarations(Edycja)
		wxTextCtrl* TextCtrl4;
		wxButton* Button1;
		wxTextCtrl* TextCtrl16;
		wxTextCtrl* TextCtrl6;
		wxTextCtrl* TextCtrl19;
		wxPanel* Panel1;
		wxButton* Button2;
		wxTextCtrl* TextCtrl18;
		wxTextCtrl* TextCtrl17;
		wxTextCtrl* TextCtrl14;
		wxTextCtrl* TextCtrl15;
		wxTextCtrl* TextCtrl13;
		wxTextCtrl* TextCtrl8;
		wxTextCtrl* TextCtrl2;
		wxTextCtrl* TextCtrl7;
		wxTextCtrl* TextCtrl1;
		wxTextCtrl* TextCtrl9;
		wxTextCtrl* TextCtrl5;
		wxTextCtrl* TextCtrl3;
		wxTextCtrl* TextCtrl10;
		wxTextCtrl* TextCtrl12;
		wxChoice* Choice1;
		wxTextCtrl* TextCtrl11;
		wxChoice* Choice2;
		//*)

	protected:

		//(*Identifiers(Edycja)
		static const long ID_TEXTCTRL1;
		static const long ID_TEXTCTRL2;
		static const long ID_TEXTCTRL3;
		static const long ID_TEXTCTRL4;
		static const long ID_TEXTCTRL5;
		static const long ID_TEXTCTRL6;
		static const long ID_TEXTCTRL7;
		static const long ID_CHOICE1;
		static const long ID_TEXTCTRL8;
		static const long ID_TEXTCTRL9;
		static const long ID_TEXTCTRL10;
		static const long ID_TEXTCTRL11;
		static const long ID_TEXTCTRL12;
		static const long ID_TEXTCTRL13;
		static const long ID_CHOICE2;
		static const long ID_TEXTCTRL14;
		static const long ID_TEXTCTRL15;
		static const long ID_TEXTCTRL16;
		static const long ID_TEXTCTRL17;
		static const long ID_TEXTCTRL18;
		static const long ID_TEXTCTRL19;
		static const long ID_BUTTON1;
		static const long ID_BUTTON2;
		static const long ID_PANEL1;
		//*)

	private:

		//(*Handlers(Edycja)
		void OnChoice1Select(wxCommandEvent& event);
		void OnChoice2Select(wxCommandEvent& event);
		void OnTextCtrl1Text(wxCommandEvent& event);
		void OnTextCtrl2Text(wxCommandEvent& event);
		void OnTextCtrl3Text(wxCommandEvent& event);
		void OnTextCtrl4Text(wxCommandEvent& event);
		void OnTextCtrl5Text(wxCommandEvent& event);
		void OnTextCtrl6Text(wxCommandEvent& event);
		void OnTextCtrl7Text(wxCommandEvent& event);
		void OnTextCtrl8Text(wxCommandEvent& event);
		void OnTextCtrl9Text(wxCommandEvent& event);
		void OnTextCtrl10Text(wxCommandEvent& event);
		void OnTextCtrl11Text(wxCommandEvent& event);
		void OnTextCtrl12Text(wxCommandEvent& event);
		void OnTextCtrl13Text(wxCommandEvent& event);
		void OnTextCtrl14Text(wxCommandEvent& event);
		void OnTextCtrl15Text(wxCommandEvent& event);
		void OnTextCtrl16Text(wxCommandEvent& event);
		void OnTextCtrl17Text(wxCommandEvent& event);
		void OnTextCtrl18Text(wxCommandEvent& event);
		void OnTextCtrl19Text(wxCommandEvent& event);
		void OnButton1Click(wxCommandEvent& event);
		void OnButton2ClickAnuluj(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
