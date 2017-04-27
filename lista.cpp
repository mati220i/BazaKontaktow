#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "lista.h"
#include "lista_funkcje_pomocnicze.h"
#include <fstream>
#include <sstream>

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
*Funkcja konwertujaca do int.
*/
template<typename T> int to_int(const T& obj)
{
    std::stringstream ss;
    int i;
    istringstream iss(obj);
    iss >> i;
    return i;
}


using namespace std;

/*!
* Funkcja szuka wolnego ID.
* Przyjmuje za parametr liste, w ktorej szukamy wolnego ID.
* Funkcja zwraca wartosc wolnego ID.
*/
int szukaj_wolnego_id(struct osoba *lista){
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
struct osoba *szukaj_ostatniego_elementu(struct osoba *lista){
    struct osoba *prev=NULL;
    while(lista){
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
struct osoba *szukaj_wybranego(struct osoba *lista,int nr){
    struct osoba *prev=NULL;
    while(lista&&(lista->id)!=nr){
        prev=lista;
        lista=lista->next;
    }
    return prev;
}

/*!
* Funkcja wyszukuje wybrany element listy.
* Przyjmuje ona dwa parametry, pierwszym jest lista,
* drugim nr elementu ktorego szukamy.
* Funkcja zwraca adres elementu, ktorego szukamy.
*/
struct osoba *szukaj_wybranego2(struct osoba *lista,int nr){
    while(lista){
        if(lista->id==nr)
            break;
        lista=lista->next;
    }
    return lista;
}

/*!
* Funkcja szuka miejsca w liscie, ktora zostala podana w pierwszym parametrze listy
* elementu o numerze podanym jako drugi element listy.
* Zwraca ona adres elementu poprzedzajacy element szukany.
*/
struct osoba *szukaj_miejsca(struct osoba *lista,int id){
    struct osoba *prev=NULL;
    while(lista&&lista->id<id){
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
struct osoba *dodawanie_do_posortowanej(struct osoba *lista,struct osoba *mini){
    /*!
    * Przydzielana zostaje pamiec na nowy element listy.
    */
    struct osoba *nowa_osoba=new osoba;
    int i;
    if(nowa_osoba){
        /*!
        * Jesli nowy element zostal utworzony, do kolejnych pol kopiowane sa nowe elementy.
        */
        nowa_osoba->id=mini->id;
        nowa_osoba->imie=mini->imie;
        nowa_osoba->nazwisko=mini->nazwisko;
        nowa_osoba->miasto=mini->miasto;
        nowa_osoba->ulica=mini->ulica;
        nowa_osoba->nr_domu=mini->nr_domu;
        nowa_osoba->kod_pocztowy=mini->kod_pocztowy;
        nowa_osoba->poczta=mini->poczta;
        nowa_osoba->next=NULL;
        nowa_osoba->ilosc_nr_telefonu=mini->ilosc_nr_telefonu;
        nowa_osoba->nr_telefonu=new string[mini->ilosc_nr_telefonu];
        for(i=0;i<mini->ilosc_nr_telefonu;i++){
            nowa_osoba->nr_telefonu[i]=mini->nr_telefonu[i];
        }
        nowa_osoba->ilosc_adresow_email=mini->ilosc_adresow_email;
        nowa_osoba->email=new string[mini->ilosc_adresow_email];
        for(i=0;i<mini->ilosc_adresow_email;i++){
            nowa_osoba->email[i]=mini->email[i];
        }
        /*!
        * Jesli lista jest pusta element staje sie pierwszym elementem listy.
        * W innym przypadku zostaje dodany na koniec listy.
        */
        if(lista==NULL){
            return nowa_osoba;
        }else{
            struct osoba *prev=szukaj_ostatniego_elementu(lista);
            prev->next=nowa_osoba;
            return lista;
        }
    }
    return lista;
}

/*!
* Funkcja zapisuje do pliku aktualny stan listy, ktora zostala podana jako parametr funkcji.
* Drugim argumentem jest czesc nazwy pliku jaka ma on zawierac.
*/
int zapisywanie_do_pliku(struct osoba *lista,string nazwa_pliku){
    int i;

    fstream baza_kontaktow,do_odczytu;
    baza_kontaktow.open("Baza Kontaktow"+nazwa_pliku+".txt", ios::out);
    do_odczytu.open("Do Odczytu"+nazwa_pliku+".txt",ios::out);
    /*!
    * Sprawdzany zostaje warunek czy lista istnieje.
    */
    if(lista){
        if(baza_kontaktow.is_open()==false)
            return -1;
        if(do_odczytu.is_open()==false)
            return -1;
        /*!
        * Do pliku zostaja dopisane elementy listy.
        */
        do{
            baza_kontaktow<<"----------------------------------------------------------------------------\n";
            baza_kontaktow<<"  ID: "<<lista->id<<endl;
            baza_kontaktow<<"  Imie: "<<lista->imie<<endl;
            baza_kontaktow<<"  Nazwisko: "<<lista->nazwisko<<endl;
            baza_kontaktow<<"  Miasto: "<<lista->miasto<<endl;
            baza_kontaktow<<"  Ulica: "<<lista->ulica<<endl;
            baza_kontaktow<<"  Nr Domu: "<<lista->nr_domu<<endl;
            baza_kontaktow<<"  Kod Pocztowy: "<<lista->kod_pocztowy<<endl;
            baza_kontaktow<<"  Poczta: "<<lista->poczta<<endl;
            baza_kontaktow<<"  Ilosc nr telefonu: "<<lista->ilosc_nr_telefonu<<endl;
            for(i=0;i<lista->ilosc_nr_telefonu;i++){
                baza_kontaktow<<"  "<<i+1<<" Nr Telefonu: "<<lista->nr_telefonu[i]<<endl;
            }
            baza_kontaktow<<"  Ilosc adresow email: "<<lista->ilosc_adresow_email<<endl;
            for(i=0;i<lista->ilosc_adresow_email;i++){
                baza_kontaktow<<"  "<<i+1<<" Adres Email: "<<lista->email[i]<<endl;
            }
            baza_kontaktow<<"----------------------------------------------------------------------------\n";
            /*!
            * Do kolejnego pliku zostaja dodane same elementy.
            * Sluzyc beda one tylko do odczytu.
            * Nie maja one charakteru, by otowrzyc plik z danymi i swobodnie czytac
            * elementy bazy kontaktow.
            */
            do_odczytu<<lista->id<<endl;
            do_odczytu<<lista->imie<<endl;
            do_odczytu<<lista->nazwisko<<endl;
            do_odczytu<<lista->miasto<<endl;
            do_odczytu<<lista->ulica<<endl;
            do_odczytu<<lista->nr_domu<<endl;
            do_odczytu<<lista->kod_pocztowy<<endl;
            do_odczytu<<lista->poczta<<endl;
            do_odczytu<<lista->ilosc_nr_telefonu<<endl;
            for(i=0;i<lista->ilosc_nr_telefonu;i++){
                do_odczytu<<lista->nr_telefonu[i]<<endl;
            }
            do_odczytu<<lista->ilosc_adresow_email<<endl;
            for(i=0;i<lista->ilosc_adresow_email;i++){
                do_odczytu<<lista->email[i]<<endl;
            }
            lista=lista->next;
        }while(lista);
        baza_kontaktow.close();
        do_odczytu.close();
    }
    /*!
    * Jesli lista przekazana przez parametr jest pusta, plik zostaje usuwany.
    */
    else{
        string plik1="Baza Kontaktow"+nazwa_pliku+".txt",plik2="Do Odczytu"+nazwa_pliku+".txt";
        remove(plik1.c_str());
        remove(plik2.c_str());
    }
    return 0;
}


/*!
* Funkcja wczytuje z pliku dane, ktore potem trafiaja do listy.
* Przyjmuje jako pierwszy parametr liste, do ktorej beda zapisywane nowe elementy.
* Drugim argumentem jest czesc nazwy pliku jaka ma on zawierac.
*/
int wczytywanie_z_pliku(struct osoba **lista,string nazwa_pliku){
    fstream baza_kontaktow;
    baza_kontaktow.open("Do Odczytu"+nazwa_pliku+".txt",ios::in);

    string odczyt;
    int i=0;
    struct osoba *nowa_osoba=NULL;
    while(getline(baza_kontaktow,odczyt)){
        /*!
        * Zostaje przydzielana pamiec na nowy element listy.
        */
        nowa_osoba=new osoba;
        nowa_osoba->next=NULL;
        /*!
        * Do nowego elementu listy kopiowane sa elementy wczytywane z pliku.
        */
        nowa_osoba->id=to_int(odczyt);
        getline(baza_kontaktow,odczyt);
        nowa_osoba->imie=odczyt;
        getline(baza_kontaktow,odczyt);
        nowa_osoba->nazwisko=odczyt;
        getline(baza_kontaktow,odczyt);
        nowa_osoba->miasto=odczyt;
        getline(baza_kontaktow,odczyt);
        nowa_osoba->ulica=odczyt;
        getline(baza_kontaktow,odczyt);
        nowa_osoba->nr_domu=odczyt;
        getline(baza_kontaktow,odczyt);
        nowa_osoba->kod_pocztowy=odczyt;
        getline(baza_kontaktow,odczyt);
        nowa_osoba->poczta=odczyt;
        getline(baza_kontaktow,odczyt);
        nowa_osoba->ilosc_nr_telefonu=to_int(odczyt);
        nowa_osoba->nr_telefonu=new string[nowa_osoba->ilosc_nr_telefonu];
        for(i=0;i<nowa_osoba->ilosc_nr_telefonu;i++){
            getline(baza_kontaktow,odczyt);
            nowa_osoba->nr_telefonu[i]=odczyt;
        }
        getline(baza_kontaktow,odczyt);
        nowa_osoba->ilosc_adresow_email=to_int(odczyt);
        nowa_osoba->email=new string[nowa_osoba->ilosc_adresow_email];
        for(i=0;i<nowa_osoba->ilosc_adresow_email;i++){
            getline(baza_kontaktow,odczyt);
            nowa_osoba->email[i]=odczyt;
        }
        /*!
        * Do listy zostaje zapisany nowy element.
        */
        *lista=dodawanie_do_posortowanej(*lista,nowa_osoba);
    }
    return 0;
}


/*!
* Funkcja pozwala dodawac nowe dane do listy.
* Jako pierwszy parametr przyjmuje liste, do ktorej sa dodawane elementy.
* Kolejne parametry to nowe dane, ktore maja zostac zapisane do nowego elementu.
* Zwraca ona adres pierwszego elementu listy.
*/
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
                               string adres_email[])
{
    struct osoba *nowa_osoba=new osoba;
    if(nowa_osoba){
        int new_id=szukaj_wolnego_id(*lista);
        nowa_osoba->id=new_id;
        nowa_osoba->id_s=to_string(new_id);
        nowa_osoba->imie=imie;
        nowa_osoba->nazwisko=nazwisko;
        nowa_osoba->miasto=miasto;
        nowa_osoba->ulica=ulica;
        nowa_osoba->nr_domu=nr_domu;
        nowa_osoba->kod_pocztowy=kod_pocztowy;
        nowa_osoba->poczta=poczta;
        nowa_osoba->next=NULL;
        nowa_osoba->ilosc_nr_telefonu=ilosc_nr_telefonu;
        /*!
        * Zostaje przydzielona dynamicznie pamiec na tablice numerow telefonow.
        */
        nowa_osoba->nr_telefonu=new string[ilosc_nr_telefonu];
        for(int i=0;i<ilosc_nr_telefonu;i++){
            nowa_osoba->nr_telefonu[i]=nr_telefonu[i];
        }
        nowa_osoba->ilosc_adresow_email=ilosc_adresow_email;
        /*!
        * Zostaje przydzielona pamiec na adresy email osoby.
        */
        nowa_osoba->email=new string[ilosc_adresow_email];
        for(int i=0;i<ilosc_adresow_email;i++){
            nowa_osoba->email[i]=adres_email[i];
        }
        /*!
        * Szukane zostaje miejsce na nowy element,
        * po czym element zostaje dodany do listy.
        */
        if(*lista==NULL){
            return nowa_osoba;
        }else{
            if((*lista)->id>=new_id){
                nowa_osoba->next=*lista;
                *lista=nowa_osoba;
                return *lista;
            }else{
                struct osoba *tmp=szukaj_miejsca(*lista,new_id);
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
* Funkcja pozwala edytowac w liscie przekazanej przez pierwszy parametr elementy podane przez kolejne parametry.
* Zwraca ona adres pierwszego elementu zaktualizowanej listy.
*/
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
                               int wybor)
{
    struct osoba *nowa_osoba=new osoba;
    if(nowa_osoba){
        nowa_osoba->id=id;
        nowa_osoba->id_s=id_s;
        nowa_osoba->imie=imie;
        nowa_osoba->nazwisko=nazwisko;
        nowa_osoba->miasto=miasto;
        nowa_osoba->ulica=ulica;
        nowa_osoba->nr_domu=nr_domu;
        nowa_osoba->kod_pocztowy=kod_pocztowy;
        nowa_osoba->poczta=poczta;
        nowa_osoba->next=NULL;
        nowa_osoba->ilosc_nr_telefonu=ilosc_nr_telefonu;
        nowa_osoba->nr_telefonu=new string[ilosc_nr_telefonu];
        for(int i=0;i<ilosc_nr_telefonu;i++){
            nowa_osoba->nr_telefonu[i]=nr_telefonu[i];
        }
        nowa_osoba->ilosc_adresow_email=ilosc_adresow_email;
        nowa_osoba->email=new string[ilosc_adresow_email];
        for(int i=0;i<ilosc_adresow_email;i++){
            nowa_osoba->email[i]=adres_email[i];
        }
        if((*lista)->id==wybor){
            struct osoba *next=(*lista)->next;
            free(*lista);
            *lista=nowa_osoba;
            (*lista)->next=next;
            return *lista;
        }else{
            struct osoba *tmp=szukaj_miejsca(*lista,id);
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
* Funkcja oproznia cala liste przekazana przez parametr.
* Nie zwraca zadnej wartosci.
*/
void usuwanie_listy(struct osoba **lista){
    if(*lista){
        while(*lista){
            struct osoba *next=(*lista)->next;
            free(*lista);
            *lista=next;
        }
    }
}


/*!
* Funkcja kopiuje element z listy podanej jako drugi parametr
* do listy podanej jako pierwszy parametr.
* Zwraca adres pierwszego elementu nowej listy.
*/
struct osoba *kopiowanie_danych(struct osoba *lista,struct osoba *oryginal){
    struct osoba *nowa_osoba=new osoba;
    int i;
    if(nowa_osoba){
        nowa_osoba->id=oryginal->id;
        nowa_osoba->id_s=oryginal->id_s;
        nowa_osoba->imie=oryginal->imie;
        nowa_osoba->nazwisko=oryginal->nazwisko;
        nowa_osoba->miasto=oryginal->miasto;
        nowa_osoba->ulica=oryginal->ulica;
        nowa_osoba->nr_domu=oryginal->nr_domu;
        nowa_osoba->kod_pocztowy=oryginal->kod_pocztowy;
        nowa_osoba->poczta=oryginal->poczta;
        nowa_osoba->next=NULL;
        nowa_osoba->ilosc_nr_telefonu=oryginal->ilosc_nr_telefonu;
        nowa_osoba->nr_telefonu=new string[oryginal->ilosc_nr_telefonu];
        for(i=0;i<oryginal->ilosc_nr_telefonu;i++){
            nowa_osoba->nr_telefonu[i]=oryginal->nr_telefonu[i];
        }
        nowa_osoba->ilosc_adresow_email=oryginal->ilosc_adresow_email;
        nowa_osoba->email=new string[oryginal->ilosc_adresow_email];
        for(i=0;i<oryginal->ilosc_adresow_email;i++){
            nowa_osoba->email[i]=oryginal->email[i];
        }
        if(lista==NULL){
            return nowa_osoba;
        }else{
            struct osoba *prev=szukaj_ostatniego_elementu(lista);
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
struct osoba *kopiowanie_listy(struct osoba *nowa_lista,struct osoba *oryginal){
    struct osoba *temp=oryginal;
    while(temp){
        nowa_lista=kopiowanie_danych(nowa_lista,temp);
        temp=temp->next;
    }
    return nowa_lista;
}

/*!
* Funkcja usuwa z listy podanej jako parametr element o numerze ID takim jaki podano w drugim parametrze.
* Zwraca ona adres pierwszego elementu listy, pomniejszonego o usuniety element.
*/
struct osoba *usuwanie(struct osoba *list_pointer,int wybor){
    if(list_pointer){
        if(list_pointer->id==wybor){
            struct osoba *next=list_pointer->next;
            free(list_pointer);
            return next;
        }else{
            struct osoba *next, *temp=szukaj_wybranego(list_pointer,wybor);
            next=temp->next;
            if(next){
                temp->next=next->next;
                free(next);
            }else
                free(next);
        }
    }
    if(wybor==-1)
        usuwanie_listy(&(list_pointer));
    return list_pointer;
}

/*!
* Funkcja wyszukuje podany przez uzytkownika element ktory zostal podany jako ostatni parametr.
* Posiada ona trzy parametry.
* Pierwszym z nich jest lista, w ktorej bedzie przeprowadzane wyszukiwanie.
* Drugim wartosc sterujaca, po ktorym polu bedzie przeprowadzane wyszukiwanie.
* Trzecim jest wzorzec do wyszukania, ktory jest typu string.
* Funkcja ta zwraca adres pierwszego elementu listy jednokierunkowej ktora zawiera znalezione elementy.
*/
struct osoba *wyszukiwanie(struct osoba *lista,int wyszukiwanie_po_polu,string szukane){
    int i;
    struct osoba *znaleziony=NULL,*temp=NULL;
    switch(wyszukiwanie_po_polu){
        case 0: while(lista){
                    if(lista->id==szukane){
                        znaleziony=lista;
                        temp=dodawanie_do_posortowanej(temp,znaleziony);
                    }
                    lista=lista->next;
                }
                break;
        case 1: while(lista){
                    if(szukane==lista->imie){
                        znaleziony=lista;
                        temp=dodawanie_do_posortowanej(temp,znaleziony);
                    }
                    lista=lista->next;
                }
                break;
        case 2: while(lista){
                    if(szukane==lista->nazwisko){
                        znaleziony=lista;
                        temp=dodawanie_do_posortowanej(temp,znaleziony);
                    }
                    lista=lista->next;
                }
                break;
        case 3: while(lista){
                    if(szukane==lista->miasto){
                        znaleziony=lista;
                        temp=dodawanie_do_posortowanej(temp,znaleziony);
                    }
                    lista=lista->next;
                }
                break;
        case 4: while(lista){
                    if(szukane==lista->ulica){
                        znaleziony=lista;
                        temp=dodawanie_do_posortowanej(temp,znaleziony);
                    }
                    lista=lista->next;
                }
                break;
        case 5: while(lista){
                    if(szukane==lista->nr_domu){
                        znaleziony=lista;
                        temp=dodawanie_do_posortowanej(temp,znaleziony);
                    }
                    lista=lista->next;
                }
                break;
        case 6: while(lista){
                    if(szukane==lista->kod_pocztowy){
                        znaleziony=lista;
                        temp=dodawanie_do_posortowanej(temp,znaleziony);
                    }
                    lista=lista->next;
                }
                break;
        case 7: while(lista){
                    if(szukane==lista->poczta){
                        znaleziony=lista;
                        temp=dodawanie_do_posortowanej(temp,znaleziony);
                    }
                    lista=lista->next;
                }
                break;
        case 8: while(lista){
                    for(i=0;i<lista->ilosc_nr_telefonu;i++){
                        if(lista->nr_telefonu[i]==szukane){
                            znaleziony=lista;
                            temp=dodawanie_do_posortowanej(temp,znaleziony);
                        }
                    }
                    lista=lista->next;
                }
                break;
        case 9: while(lista){
                    for(i=0;i<lista->ilosc_adresow_email;i++){
                        if(szukane==lista->email[i]){
                            znaleziony=lista;
                            temp=dodawanie_do_posortowanej(temp,znaleziony);
                        }
                    }
                    lista=lista->next;
                }
                break;
    }
    return temp;
}
