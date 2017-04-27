#ifndef uzytkownicy_h
#define uzytkownicy_h
#include <iostream>
#include <strings.h>

using namespace std;

/*!
* Struktura zawierajaca dane uzytkownika.
*/
struct uzytkownik{
    int id;
    string nazwa,haslo;
    struct uzytkownik *next;
};

template<typename T> int to_int(const T& obj);

template<typename T> std::string to_string(const T& obj);

void usuwanie_listy(struct uzytkownik **lista);

struct uzytkownik *szukaj_wybranego2(struct uzytkownik *lista,int nr);

struct uzytkownik *kopiowanie_listy(struct uzytkownik *nowa_lista,struct uzytkownik *oryginal);

int szukaj_wolnego_id(struct uzytkownik *lista);

struct uzytkownik *szukaj_ostatniego_elementu(struct uzytkownik *lista);

struct uzytkownik *szukaj_miejsca(struct uzytkownik *lista,int id);

struct uzytkownik *szukaj_wybranego(struct uzytkownik *lista,int nr);

struct uzytkownik *dodawanie_do_posortowanej(struct uzytkownik *lista,struct uzytkownik *mini);

struct uzytkownik *dodawanie(struct uzytkownik **lista,string nazwa,string haslo);

struct uzytkownik *edycja(struct uzytkownik **lista,string nazwa,string haslo,int wybor,int id);

struct uzytkownik *usuwanie(struct uzytkownik *list_pointer,int wybor,string nazwa_pliku);

int zapisywanie_do_pliku(struct uzytkownik *lista);

int wczytywanie_z_pliku_uzytkowikow(struct uzytkownik **lista);

#endif
