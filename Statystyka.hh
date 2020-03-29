#ifndef STATYSTYKA_HH
#define STATYSTYKA_HH

#include <iostream>
#include <iomanip> 

using namespace std;

/*
 * Plik zawiera definicje struktury Statystyka oraz
 * zapowiedz funkcji dzialajacej na tej strukturze.
 */

/*
 * Modeluje pojecie statystyki.
 */ 
struct Statystyka {
double DobreOdp = 0;       /* Licznik poprawnych odpowiedzi */
double ZleOdp = 0;         /* Licznik niepoprawnych odpowiedzi */
};

/*
 * Wyswietla statystyke
 */
void WyswietlStatystyke (Statystyka);

#endif