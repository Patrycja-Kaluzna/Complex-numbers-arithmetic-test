#include "BazaTestu.hh"
#include "LZespolona.hh"
#include "Statystyka.hh"

#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
  /*if (argc < 2) {
    cout << endl;
    cout << " Brak opcji okreslajacej rodzaj testu." << endl;
    cout << " Dopuszczalne nazwy to: latwy, trudny." << endl;
    cout << endl;
    return 1;
  }

  BazaTestu  BazaT = { nullptr, 0, 0 };

  if (InicjalizujTest(&BazaT,argv[1]) == false) {
    cerr << " Inicjalizacja testu nie powiodla sie." << endl;
    return 1;
  }
  
  cout << endl;
  cout << " Start testu arytmetyki zespolonej: " << argv[1] << endl;
  cout << endl;

  WyrazenieZesp   WyrZ_PytanieTestowe;
  
  while (PobierzNastpnePytanie(&BazaT,&WyrZ_PytanieTestowe)) {
    cout << " Czesc rzeczywista pierwszego argumentu: ";
    cout << WyrZ_PytanieTestowe.Arg1.re << endl;
  }*/

  //TEST PRZECIĄŻEŃ OPERATORÓW +, -, *, / DLA LICZB ZESPOLONYCH (I JEDNOCZENIE TEST WYSWIETLANIA LICZBY ZESPOLONEJ) 

  LZespolona Skl1, Skl2, Wynik;
  double Ltd;

  Skl1.re = 1;
  Skl1.im = 2;
  Skl2.re = 3;
  Skl2.im = 4;
  Ltd = 2;

  cout << endl;
  cout << " Dodawanie liczby zespolonych:";
  Wynik = Skl1 + Skl2;
  Wyswietl (Wynik);
  cout << endl;

  cout << " Odejmowanie liczb zespolonych:";
  Wynik = Skl1 - Skl2;
  Wyswietl (Wynik);
  cout << endl;

  cout << " Mnozenie liczb zespolonych:";
  Wynik = Skl1 * Skl2;
  Wyswietl (Wynik);
  cout << endl;

  cout << " Dzielenie liczby zespolonej przez liczbe typu double:";
  Wynik = Skl1 / Ltd;
  Wyswietl (Wynik);
  cout << endl;

  cout << " Dzielenie liczb zespolonych:";
  Wynik = Skl1 / Skl2;
  Wyswietl (Wynik);
  cout << endl;

  //TEST STATYSTYKI

  Statystyka Stat;

  Stat.DobreOdp = 2;
  Stat.ZleOdp = 4;

  cout << endl;
  WyswietlStatystyke (Stat);
  cout << endl;

  //TEST WYŚWIETLANIA WYRAŻENIA ZESPOLONEGO

  WyrazenieZesp WZ;

  WZ.Arg1.re = 1;
  WZ.Arg1.im = 2;
  WZ.Op = Op_Dodaj;
  WZ.Arg2.re = 3;
  WZ.Arg2.im = 4;

  Wyswietl (WZ);
  cout << endl;

  //TEST WCZYTYWANIA WYRAZENIA ZESPOLONEGO (I JEDNOCZESNIE LICZBY ZESPOLONEJ) ORAZ WYSWIETLANIA ICH

  WyrazenieZesp WZ2;

  cout << endl;
  WZ2 = WczytajWZ ();
  cout << endl;
  Wyswietl (WZ2);
  cout << endl;

  //TEST OBLICZANIA WYRAZENIA ZESPOLONEGO

  cout << endl;
  Wyswietl (Oblicz (WZ2));
  cout << endl;

  //WCZYTYWANIE LICZBY ZESPOLONEJ ZA POMOCA PRZECIAZENIA OPERATORA >> ORAZ WYSWIETLENIE JEJ

  LZespolona LZ;

  cout << endl;
  cin >> LZ;
  cout << endl;
  Wyswietl (LZ);
  cout << endl;

  //WYSWIETLANIE LICZBY ZESPOLONEJ ZA POMOCA PRZECIAZENIA OPERATORA << 

  cout << endl << Skl1 << endl;

  //WYSWIETLANIE WYRAZENIE ZESPOLONEGO ZA POMOCA PRZECIAZENIA OPERATORA <<

  cout << endl << WZ << endl;

  cout << endl;
  cout << " Koniec testu" << endl;
  cout << endl;
}
