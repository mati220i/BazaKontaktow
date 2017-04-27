#include "uzytkownicy.h"
#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <fstream>

/*!
*Funkcja kowertujaca do int.
*/
template<typename T> int to_int(const T& obj)
{
    std::stringstream ss;
    int i;
    istringstream iss(obj);
    iss >> i;
    return i;
}

/*!
*Funkcja kowertujaca do std::string.
*/
template<typename T> std::string to_string(const T& obj)
{
    std::stringstream ss;
    ss << obj;
    return ss.str();
}


/*!
* Funkcja oproznia cala liste przekazana przez parametr.
* Nie zwraca zadnej wartosci.
*/
void usuwanie_listy(struct uzytkownik **lista){
    if(*lista){
        while(*lista){
            struct uzytkownik *next=(*lista)->next;
            free(*lista);
            *lista=next;
        }
    }
}

/*!
* Funkcja wyszukuje wybrany element listy.
* Przyjmuje ona dwa parametry, pierwszym jest lista,
* drugim nr elementu ktorego szukamy.
* Funkcja zwraca adres elementu, ktorego szukamy.
*/
struct uzytkownik *szukaj_wybranego2(struct uzytkownik *lista,int nr){
    while(lista){
        if(lista->id==nr)
            break;
        lista=lista->next;
    }
    return lista;
}


/*!
* Funkcja kopiuje element z listy podanej jako drugi parametr
* do listy podanej jako pierwszy parametr.
* Zwraca adres pierwszego elementu nowej listy.
*/
struct uzytkownik *kopiowanie_danych(struct uzytkownik *lista,struct uzytkownik *oryginal){
    struct uzytkownik *nowa_osoba=new uzytkownik;
    if(nowa_osoba){
        nowa_osoba->id=oryginal->id;
        nowa_osoba->nazwa=oryginal->nazwa;
        nowa_osoba->haslo=oryginal->haslo;
        nowa_osoba->next=NULL;
        if(lista==NULL){
            return nowa_osoba;
        }else{
            struct uzytkownik *prev=szukaj_ostatniego_elementu(lista);
            prev->next=nowa_osoba;
            return lista;
        }
    }
    return lista;
}

/*!
* Funkcja jest glowna funkcja kopiujaca, ktora korzysta z funkcji pomocniczej.
* Kopiuje ona elementy listy oryginalnej, do momentu kiedy wskaznik next elementu listy bedzie pusty.
* Zwraca ona adres elementu nowej listy.
*/
struct uzytkownik *kopiowanie_listy(struct uzytkownik *nowa_lista,struct uzytkownik *oryginal){
    struct uzytkownik *temp=oryginal;
    while(temp){
        nowa_lista=kopiowanie_danych(nowa_lista,temp);
        temp=temp->next;
    }
    return nowa_lista;
}


/*!
* Funkcja szuka wolnego ID.
* Przyjmuje za parametr liste, w ktorej szykamy wolnego ID.
* Funkcja zwraca wartosc wolnego ID.
*/
int szukaj_wolnego_id(struct uzytkownik *lista){
    int licznik=1;
    if(lista==NULL)
        return 1;
    if(lista->id!=1)
        return 1;
    /*!
    * Petla przeszukuje numery ID i zatrzymuje sie kiedy znajdzie wolny.
    */
    while(lista){
        if(lista->id!=licznik)
            break;
        licznik++;
        lista=lista->next;
    }
    return licznik;
}


/*!
* Funkcja wyszukuje ostatni element listy.
* Jako parametr przyjmuje liste, w ktorej szukamy ostatniego elementu.
* Funkcja zwraca adres ostatniego elementu.
*/
struct uzytkownik *szukaj_ostatniego_elementu(struct uzytkownik *lista){
    struct uzytkownik *prev=NULL;
    while(lista){
        prev=lista;
        lista=lista->next;
    }
    return prev;
}

/*!
* Funkcja szuka miejsca w liscie, ktora zostala podana w pierwszym parametrze listy
* elementu o numerze podanym jako drugi element listy.
* Zwraca ona adres elementu poprzedzajacy element szukany.
*/
struct uzytkownik *szukaj_miejsca(struct uzytkownik *lista,int id){
    struct uzytkownik *prev=NULL;
    while(lista&&lista->id<id){
        prev=lista;
        lista=lista->next;
    }
    return prev;
}

/*!
* Funkcja wyszukuje wybrany element listy.
* Przyjmuje ona dwa parametry, pierwszym jest lista,
* drugim nr elementu ktorego szukamy.
* Funkcja zwraca adres elementu, ktory jest przed elementem szukanym.
*/
struct uzytkownik *szukaj_wybranego(struct uzytkownik *lista,int nr){
    struct uzytkownik *prev=NULL;
    while(lista&&(lista->id)!=nr){
        prev=lista;
        lista=lista->next;
    }
    return prev;
}

/*!
* Funkcja dodaje do tymczasowej listy, ktora zostala podana jako pierwszy parametr funkcji
* element, ktory zostal przekazany przez drugi parametr.
* Funkcja zwraca adres pierwszego elementu listy.
*/
struct uzytkownik *dodawanie_do_posortowanej(struct uzytkownik *lista,struct uzytkownik *mini){
    struct uzytkownik *nowa_osoba=new uzytkownik;
    /*!
    * Przydzielana zostaje pamiec na nowy element listy.
    */
    if(nowa_osoba){
        /*!
        * Jesli nowy element zostal utworzony, do kolejnych pol kopiowane sa nowe elementy.
        */
        nowa_osoba->id=mini->id;
        nowa_osoba->nazwa=mini->nazwa;
        nowa_osoba->haslo=mini->haslo;
        nowa_osoba->next=NULL;
        /*!
        * Jesli lista jest pusta element staje sie pierwszym elementem listy.
        * W innym przypadku zostaje dodany na koniec listy.
        */
        if(lista==NULL){
            return nowa_osoba;
        }else{
            struct uzytkownik *prev=szukaj_ostatniego_elementu(lista);
            prev->next=nowa_osoba;
            return lista;
        }
    }
    return lista;
}



/*!
* Funkcja pozwala dodawac nowe dane do listy.
* Jako pierwszy parametr przyjmuje liste, do ktorej sa dodawane elementy.
* Drugim jest nazwa ktora ma zostac zapisana do nowego elementu.
* Trzecim zas jest haslo ktore ma nalezec do nowego elementu.
* Zwraca ona adres pierwszego elementu listy.
*/
struct uzytkownik *dodawanie(struct uzytkownik **lista,string nazwa,string haslo){
    struct uzytkownik *nowa_osoba=new uzytkownik;
    if(nowa_osoba){
        int new_id=szukaj_wolnego_id(*lista);
        nowa_osoba->id=new_id;
        nowa_osoba->nazwa=nazwa;
        nowa_osoba->haslo=haslo;
        nowa_osoba->next=NULL;
        if(*lista==NULL){
            return nowa_osoba;
        }else{
            if((*lista)->id>=new_id){
                nowa_osoba->next=*lista;
                *lista=nowa_osoba;
                return *lista;
            }else{
                struct uzytkownik *tmp=szukaj_miejsca(*lista,new_id);
                if(tmp->next){
                    nowa_osoba->next=tmp->next;
                    tmp->next=nowa_osoba;
                    return *lista;
                }else{
                    tmp->next=nowa_osoba;
                    return *lista;
                }
            }
        }
    }
    return *lista;
}


/*!
* Funkcja pozwala edytowac w liscie przekazanej przez pierwszy parametr.
* Pierwszym i drugim parametrem sa nowe dane do elementu.
* Trzecim jest numer ID elementu, ktory ma zostac edytowany.
* Czwartym zas jest dotychczasowe niezmienne ID elementu.
* Zwraca ona adres pierwszego elementu zaktualizowanej listy.
*/
struct uzytkownik *edycja(struct uzytkownik **lista,string nazwa,string haslo,int wybor,int id){
    struct uzytkownik *nowa_osoba=new uzytkownik;
    if(nowa_osoba){
        nowa_osoba->id=id;
        nowa_osoba->nazwa=nazwa;
        nowa_osoba->haslo=haslo;
        nowa_osoba->next=NULL;
        if((*lista)->id==wybor){
            struct uzytkownik *next=(*lista)->next;
            free(*lista);
            *lista=nowa_osoba;
            (*lista)->next=next;
            return *lista;
        }else{
            struct uzytkownik *tmp=szukaj_miejsca(*lista,id);
            if(tmp->next){
                nowa_osoba->next=tmp->next->next;
                free(tmp->next);
                tmp->next=nowa_osoba;
                return *lista;
            }
        }
    }
    return *lista;
}

/*!
* Funkcja usuwa z listy podanej jako parametr element o numerze ID takim jaki podano w drugim parametrze.
* Trzecim parametrem jest czesc nazwy pliku.
* Dodatkowo funkcja umożliwia usuniecie danych w pliku *.txt poprzez ich usuniecie.
* Zwraca ona adres pierwszego elementu listy, pomniejszonego o usuniety element.
*/
struct uzytkownik *usuwanie(struct uzytkownik *list_pointer,int wybor,string nazwa_pliku){
    /*!
    *W tych dwoch zmiennych bedzie umieszczona nazwa pliku ktory jest aktualnie usuwany.
    */
    string plik1="Baza Kontaktow"+nazwa_pliku+".txt",plik2="Do Odczytu"+nazwa_pliku+".txt";
    /*!
    *Usuniecie plikow nalezacych do usuwanego uzytkownika.
    */
    remove(plik1.c_str());
    remove(plik2.c_str());
    if(list_pointer){
        if(list_pointer->id==wybor){
            struct uzytkownik *next=list_pointer->next;

            free(list_pointer);
            return next;
        }else{
            struct uzytkownik *next, *temp=szukaj_wybranego(list_pointer,wybor);
            next=temp->next;
            if(next){
                temp->next=next->next;
                free(next);
            }else
                free(next);
        }
    }
    return list_pointer;
}

/*!
* Funkcja zapisuje do pliku aktualny stan listy, ktora zostala podana jako parametr funkcji.
*/
int zapisywanie_do_pliku(struct uzytkownik *lista){
    fstream do_odczytu;
    do_odczytu.open("Uzytkownicy Do Odczytu.txt",ios::out);
    /*!
    * Sprawdzany zostaje warunek czy lista istnieje.
    */
    if(lista){
        if(do_odczytu.is_open()==false)
            return -1;
        /*!
        * Do pliku zostaja dopisane elementy listy.
        */
        do{
            do_odczytu<<lista->id<<endl;
            do_odczytu<<lista->nazwa<<endl;
            do_odczytu<<lista->haslo<<endl;
            lista=lista->next;
        }while(lista);
        do_odczytu.close();
    }
    /*!
    * Jesli lista przekazana przez parametr jest pusta, plik zostaje usuwany.
    */
    else{
        remove("Uzytkownicy Do Odczytu.txt");
    }
    return 0;
}

/*!
* Funkcja wczytuje z pliku dane, ktore potem trafiaja do listy.
* Przyjmuje jako pierwszy parametr liste, do ktorej beda zapisywane nowe elementy.
*/
int wczytywanie_z_pliku_uzytkowikow(struct uzytkownik **lista){
    fstream baza_kontaktow;
    baza_kontaktow.open("Uzytkownicy Do Odczytu.txt",ios::in);
    if(baza_kontaktow.is_open()==false)
        return -1;
    string odczyt;
    struct uzytkownik *nowa_osoba=NULL;
    while(getline(baza_kontaktow,odczyt)){
        /*!
        * Zostaje przydzielana pamiec na nowy element listy.
        */
        nowa_osoba=new uzytkownik;
        nowa_osoba->next=NULL;
        /*!
        * Do nowego elementu listy kopiowane sa elementy wczytywane z pliku.
        */
        nowa_osoba->id=to_int(odczyt);
        getline(baza_kontaktow,odczyt);
        nowa_osoba->nazwa=odczyt;
        getline(baza_kontaktow,odczyt);
        nowa_osoba->haslo=odczyt;
        *lista=dodawanie_do_posortowanej(*lista,nowa_osoba);
    }
    return 0;
}
