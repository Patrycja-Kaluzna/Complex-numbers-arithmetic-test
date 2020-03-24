#ifndef WYRAZENIEZESP_HH
#define WYRAZENIEZESP_HH

#include "LZespolona.hh"
#include <iostream>

using namespace std;

/*
 * Plik zawiera definicje struktury WyrazenieZesp oraz
 * zapowiedzi funkcji dzialajacych na tej strukturze,
 * a takze definicje zmiennej Operator bedacej typu
 * wyliczeniowego.
 */

/*!
 * Modeluje zbior operatorow arytmetycznych.
 */
enum Operator {Op_Dodaj, Op_Odejmij, Op_Mnoz, Op_Dziel, Op_Modulo};

/*
 * Modeluje pojecie dwuargumentowego wyrazenia zespolonego.
 */
struct WyrazenieZesp {
  LZespolona Arg1;    /* Pierwszy argument wyrazenia arytmetycznego */
  Operator Op;        /* Opertor wyrazenia arytmetycznego */
  LZespolona Arg2;    /* Drugi argument wyrazenia arytmetycznego */
};

/*
 * Wyswietla wyrazenie zespolone.
 */
void Wyswietl (WyrazenieZesp);

/*
 * Wczytuje wyrazenie zespolone.
 */
WyrazenieZesp WczytajWZ ();

/*
 * Interpretuje i oblicza wartosc wyrazenia zespolonego.
 */
LZespolona Oblicz (WyrazenieZesp);

/*
 * Wyswietla wyrazenie zespolone.
 */
ostream & operator << (ostream &, WyrazenieZesp);

#endif
