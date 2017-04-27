#ifndef lista_h
#define lista_h
#include <iostream>
#include <wx/string.h>

using namespace std;
/*!
* Struktura zawierajaca dane osoby.
*/
struct osoba{
    int id,ilosc_nr_telefonu,ilosc_adresow_email;
    string id_s,imie,nazwisko,miasto,ulica,nr_domu,kod_pocztowy,poczta,
    /*!
    * email jest zmienną wskznikową,
    * do tej zmiennej bedzie tworzona dynamicznie tablica
    * z adresami email pojedynczej osoby.
    */
    *email,
    /*!
    * nr_telefonu jest zmienną wskznikową,
    * do tej zmiennej bedzie tworzona dynamicznie tablica
    * z numerami telefonow pojedynczej osoby.
    */
    *nr_telefonu;

    struct osoba *next;

};

template<typename T> std::string to_string(const T& obj);

template<typename T> int to_int(const T& obj);

int szukaj_ostatniego_id(struct osoba *lista);

struct osoba *kopiowanie_listy(struct osoba *nowa_lista,struct osoba *oryginal);

struct osoba *szukaj_wybranego(struct osoba *lista,int nr);

struct osoba *szukaj_wybranego2(struct osoba *lista,int nr);

int zapisywanie_do_pliku(struct osoba *lista,string nazwa_pliku);

int wczytywanie_z_pliku(struct osoba **lista,string nazwa_pliku);

struct osoba *dodawanie_danych(struct osoba **lista,
                               string imie,
                               string nazwisko,
                               string miasto,
                               string ulica,
                               string nr_domu,
                               string kod_pocztowy,
                               string poczta,
                               int ilosc_nr_telefonu,
                               string nr_telefonu[],
                               int ilosc_adresow_email,
                               string adres_email[]);

struct osoba *edycja(struct osoba **lista,
                                int id,
                                string id_s,
                               string imie,
                               string nazwisko,
                               string miasto,
                               string ulica,
                               string nr_domu,
                               string kod_pocztowy,
                               string poczta,
                               int ilosc_nr_telefonu,
                               string nr_telefonu[],
                               int ilosc_adresow_email,
                               string adres_email[],
                               int wybor);

struct osoba *usuwanie(struct osoba *list_pointer,int i);

struct osoba *wyszukiwanie(struct osoba *lista,int wyszukiwanie_po_polu,string szukane);

#endif
