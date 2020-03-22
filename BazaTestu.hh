#ifndef BAZATESTU_HH
#define BAZATESTU_HH

#include "WyrazenieZesp.hh"

/*
 * Plik zawiera definicje struktury BazaTestu oraz
 * zapowiedzi funkcji dzialajacych na tej strukturze.
 */

/*
 * Modeluje pojecie baza testu z zestawem pytan w tablicy
 * oraz informacji o maksymalnej ilosci pytan, jak
 * tez indeksem nastepnego pytania, ktore ma byc pobrane
 * z bazy.
 */
struct BazaTestu {
  WyrazenieZesp *wskTabTestu;     /* Wskaznik na tablice zawierajaca pytania testu */
  unsigned int IloscPytan;        /* Ilosc wszystkich pytan */
  unsigned int IndeksPytania;     /* Numer pytania, ktore ma byc pobrane jako nastepne */
};

/*
 * Inicjalizuje test powiazany z dana nazwa.
 */
bool InicjalizujTest(BazaTestu  *, const char *);

/*
 * Udostepnia nastepne pytanie z bazy.
 */
bool PobierzNastpnePytanie(BazaTestu  *,  WyrazenieZesp *);

#endif
