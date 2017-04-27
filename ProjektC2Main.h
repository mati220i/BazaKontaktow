/***************************************************************
 * Name:      ProjektC2Main.h
 * Purpose:   Defines Application Frame
 * Author:    Sliwa ()
 * Created:   2016-12-02
 * Copyright: Sliwa ()
 * License:
 **************************************************************/

#ifndef PROJEKTC2MAIN_H
#define PROJEKTC2MAIN_H

//(*Headers(ProjektC2Frame)
#include <wx/srchctrl.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/menu.h>
#include <wx/textctrl.h>
#include <wx/radiobut.h>
#include <wx/panel.h>
#include <wx/choice.h>
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/statusbr.h>
//*)

class ProjektC2Frame: public wxFrame
{
    public:

        ProjektC2Frame(wxWindow* parent,wxWindowID id = -1);
        virtual ~ProjektC2Frame();

    private:

        //(*Handlers(ProjektC2Frame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnButton1Click(wxCommandEvent& event);
        void OnSearchCtrl1Text(wxCommandEvent& event);
        void OnButton2Click(wxCommandEvent& event);
        void OnButton2Click1(wxCommandEvent& event);
        void OnButton4Click(wxCommandEvent& event);
        void OnSearchCtrl1SearchClicked(wxCommandEvent& event);
        void OnRadioButton1Select_Imie(wxCommandEvent& event);
        void OnRadioButton2Select_Nazwisko(wxCommandEvent& event);
        void OnRadioButton3Select_Miasto(wxCommandEvent& event);
        void OnRadioButton4Select_Ulica(wxCommandEvent& event);
        void OnRadioButton5Select_Nr_Domu(wxCommandEvent& event);
        void OnRadioButton6Select_Kod_Pocztowy(wxCommandEvent& event);
        void OnRadioButton7Select_Poczta(wxCommandEvent& event);
        void OnRadioButton8Select_Nr_Telefonu(wxCommandEvent& event);
        void OnRadioButton9Select_Adres_email(wxCommandEvent& event);
        void OnMenuItem6Selected_Zapisz_do_pliku(wxCommandEvent& event);
        void OnButton5Click(wxCommandEvent& event);
        void OnTextCtrl1Text_Wpisz_Haslo(wxCommandEvent& event);
        void OnButton2Click2_Zaloguj(wxCommandEvent& event);
        void OnChoice1Select_Wybrany_uzytkownik(wxCommandEvent& event);
        void OnButton3Click_Wyloguj(wxCommandEvent& event);
        //*)

        //(*Identifiers(ProjektC2Frame)
        static const long ID_STATICTEXT1;
        static const long ID_CHOICE1;
        static const long ID_TEXTCTRL1;
        static const long ID_STATICTEXT2;
        static const long ID_BUTTON2;
        static const long ID_BUTTON3;
        static const long ID_BUTTON5;
        static const long ID_BUTTON1;
        static const long ID_BUTTON4;
        static const long ID_RADIOBUTTON1;
        static const long ID_RADIOBUTTON2;
        static const long ID_RADIOBUTTON3;
        static const long ID_RADIOBUTTON4;
        static const long ID_RADIOBUTTON5;
        static const long ID_RADIOBUTTON6;
        static const long ID_RADIOBUTTON7;
        static const long ID_RADIOBUTTON8;
        static const long ID_RADIOBUTTON9;
        static const long ID_SEARCHCTRL1;
        static const long ID_PANEL1;
        static const long ID_MENUITEM4;
        static const long idMenuQuit;
        static const long ID_MENUITEM5;
        static const long ID_MENUITEM6;
        static const long ID_MENUITEM7;
        static const long ID_MENUITEM1;
        static const long ID_MENUITEM2;
        static const long ID_MENUITEM3;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(ProjektC2Frame)
        wxMenuItem* MenuItem8;
        wxRadioButton* RadioButton9;
        wxRadioButton* RadioButton1;
        wxMenuItem* MenuItem7;
        wxButton* Button4;
        wxMenuItem* MenuItem5;
        wxStaticText* StaticText2;
        wxRadioButton* RadioButton2;
        wxRadioButton* RadioButton6;
        wxRadioButton* RadioButton5;
        wxMenu* Menu3;
        wxButton* Button1;
        wxMenuItem* MenuItem4;
        wxRadioButton* RadioButton4;
        wxRadioButton* RadioButton7;
        wxPanel* Panel1;
        wxStaticText* StaticText1;
        wxRadioButton* RadioButton3;
        wxButton* Button2;
        wxButton* Button5;
        wxMenuItem* MenuItem3;
        wxButton* Button3;
        wxRadioButton* RadioButton8;
        wxStatusBar* StatusBar1;
        wxMenuItem* MenuItem6;
        wxTextCtrl* TextCtrl1;
        wxMenuItem* MenuItem9;
        wxChoice* Choice1;
        wxMenu* Menu4;
        wxSearchCtrl* SearchCtrl1;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // PROJEKTC2MAIN_H
