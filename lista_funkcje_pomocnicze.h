#ifndef lista_funkcje_pomocnicze_h
#define lista_funkcje_pomocnicze_h

int szukaj_wolnego_id(struct osoba *lista);

int szukaj_ostatniego_id(struct osoba *lista);

struct osoba *szukaj_ostatniego_elementu(struct osoba *lista);

struct osoba *szukaj_wybranego(struct osoba *lista,int nr);

struct osoba *sprawdz_czy_istnieje_id(struct osoba *lista,int nr);

struct osoba *szukaj_miejsca(struct osoba *lista,int id);

void usuwanie_znaku_nowego_wiersza(char *ciag);

struct osoba *dodawanie_do_posortowanej(struct osoba *lista,struct osoba *mini);

void wyswietlanie(struct osoba *lista,int wyswitlanie_usuwanie);

struct osoba *usuwanie_w_sortowaniu(struct osoba *lista,int wybor);

void usuwanie_listy(struct osoba **lista);

struct osoba *kopiowanie_danych(struct osoba *lista,struct osoba *oryginal);

struct osoba *kopiowanie_listy(struct osoba *nowa_lista,struct osoba *oryginal);

void sortowanie(struct osoba *lista,int sortowanie_po_polu,int sposob);

void wyszukiwanie(struct osoba *lista,int wyszukiwanie_po_polu,char *szukane,int szukane_int);

#endif
