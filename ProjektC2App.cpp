/***************************************************************
 * Name:      ProjektC2App.cpp
 * Purpose:   Code for Application Class
 * Author:    Sliwa ()
 * Created:   2016-12-02
 * Copyright: Sliwa ()
 * License:
 **************************************************************/

#include "ProjektC2App.h"
#include "uzytkownicy.h"
#include <wx/msgdlg.h>

extern struct uzytkownik *uzytkownicy;

//(*AppHeaders
#include "ProjektC2Main.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(ProjektC2App);

bool ProjektC2App::OnInit()
{
    //AppInitialize

    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	ProjektC2Frame* Frame = new ProjektC2Frame(0);
    	Frame->Show();
    	Frame->SetIcon(wxICON(ikona_programu));
    	if(uzytkownicy==NULL){
        /*!
        *Jeśli program nie zawieta uzytkownikow program wyswietla proste powiadomienie opisujace poszczegolne kroki pozwalajace zaczac korzystac z programu.
        */
        int Okno_wprowadzenia = wxMessageBox("Witaj w Bazie Kontaktow!\nAby zaczac korzystac z bazy kontaktow musisz zalozyc swoje konto uzytkownika klikajac w \"Zarzadzanie Uzytkownikami\"\nNatepnie wybrac swoje konto z listy, wpisac haslo i kliknac przycisk \"Zaloguj\"","Witaj!", wxYES_DEFAULT | wxICON_INFORMATION);
        if(Okno_wprowadzenia == wxYES)
            ;
    }

    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
