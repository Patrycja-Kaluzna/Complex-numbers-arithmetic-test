#include "LZespolona.hh"

/*!
 * Realizuje dodawanie dwoch liczb zespolonych.
 * 
 * Argumenty:
 *    Skl1 - pierwszy skladnik dodawania,
 *    Skl2 - drugi skladnik dodawania.
 * 
 * Zwraca:
 *    Sume dwoch skladnikow przekazanych jako parametry.
 */
LZespolona operator + (LZespolona  Skl1,  LZespolona  Skl2)
{
  LZespolona  Wynik;

  Wynik.re = Skl1.re + Skl2.re;
  Wynik.im = Skl1.im + Skl2.im;
  return Wynik;
}



/*
 * Realizuje odejmowanie dwoch liczb zespolonych.
 *
 * Argumenty:
 *    Skl1 - odjemna,
 *    Skl2 - odjemnik.
 * 
 * Zwraca:
 *    Roznice odjemnej i odjemnika przekazanych
 *    jako parametry.
 */
LZespolona operator - (LZespolona Skl1, LZespolona Skl2)
{
  LZespolona Wynik;

  Wynik.re = Skl1.re - Skl2.re;
  Wynik.im = Skl1.im - Skl2.im;
  return Wynik;
}



/*
 * Realizuje mnozenie dwoch liczb zespolonych.
 * 
 * Argumenty:
 *    Skl1 - pierwszy czynnik mnozenia,
 *    Skl2 - drugi czynnik mnozenia.
 * 
 * Zwraca: 
 *    Iloczyn dwoch czynnikow przekazanych jako
 *    parametry.
 */
LZespolona operator * (LZespolona Skl1, LZespolona Skl2)
{
  LZespolona Wynik;

  Wynik.re = Skl1.re * Skl2.re - Skl1.im * Skl2.im;
  Wynik.im = Skl1.re * Skl2.im + Skl1.im * Skl2.re;
  return Wynik;
}



/*
 * Oblicza sprzezenie liczby zespolonej.
 * 
 * Argument:
 *    Skl2 - liczba zespolona, ktorej sprzezenie
 *           zostanie obliczone.
 * 
 * Zwraca:
 *    Sprzezenie liczby zespolonej przekazanej
 *    jako parametr.
 */
LZespolona Sprzezenie (LZespolona Skl2)
{
  Skl2.im = -1 * Skl2.im;
  return Skl2;
}



/*
 * Oblicza modul liczby zespolonej podnisiony
 * do kwadratu.
 * 
 * Argument:
 *    Skl2 - liczba zespolna, ktorej modul podniesiony
 *           do kwadratu zostanie obliczony.
 * 
 * Zwraca:
 *     Podniosiony do kwadratu modul liczby zespolonej
 *     przekazanej jako parametr.
 */
double Modul2 (LZespolona Skl2)
{
  double M2 = Skl2.re * Skl2.re + Skl2.im * Skl2.im;
  return M2;
}



/*
 * Realizuje dzielenie liczby zespolonej przez 
 * liczbe typu double.
 * 
 * Argumenty:
 *    Wynik - liczba zespolona bedaca dzielna,
 *    M2 - liczba typu double bedaca dzielnikiem.
 * 
 * Warunek wstepny:
 *    - Liczba typu double musi byc rozna od zera.
 *      (jesli jest rowna zeru to wyswietla sie
 *      stosowny komunikat o bledzie)
 *  
 * Zwraca:
 *    Liczbe zespolona bedaca ilorazem dzielnej i
 *    dzielnika przekazanych jako parametry.
 */
LZespolona operator / (LZespolona Wynik, double M2)
{
  LZespolona LZpD;

  if (M2 != 0)
  {
    LZpD.re = Wynik.re / M2;
    LZpD.im = Wynik.im / M2;
  } else {
    cerr << "Blad: modul liczby zespolonej podniesiony do kwadratu jest rowny zero (dzielenie przez zero)" << endl;
  }
  return LZpD;
}

/*
 * Realizuje dzielenie dwoch liczb zespolonych przy
 * wykorzystaniu przeciazenia operatora mnozenia dla 
 * liczb zespolonych, przeciazenia operatora dzielenia
 * liczby zespolonej przez liczbe typu double oraz 
 * funkcji obliczajacych sprzezenie i modul 
 * podniosiony do kwadratu.
 * 
 * Argumenty:
 *    Skl1 - dzielna,
 *    Skl2 - dzielnik.
 * 
 * Warunek wstepny:
 *    - Modul liczby zespolonej podniesiony do kwadratu
 *      musi byc rozny od zera. (jesli jest rowny zeru
 *      to wyswietla sie stosowny komunikat o bledzie)
 * 
 * Zwraca:
 *    Iloraz dzielnej i dzielnika przekazanych jako
 *    parametry.
 */
LZespolona operator / (LZespolona Skl1, LZespolona Skl2)
{
  LZespolona Wynik;

  Wynik = operator * (Skl1, Sprzezenie (Skl2));
  Wynik = Wynik / Modul2 (Skl2);
  return Wynik;
}



/*
 * Funkcja wczytuje liczbe zespolona wpisana 
 * przez uzytkownika na standardowym wejsciu.
 * 
 * Warunek wstepny:
 *    - Liczba zespolona musi byc wpisana przez uzytkownika
 *      w odpowiedniej postaci, np.: (1+2i).
 *      (wpisanie w innej postaci powoduje wyswietlenie
 *      komunikatu o bledzie)
 * 
 * Zwraca: 
 *    W przypadku powodzenia wczytana liczbe zespolona, a
 *    w przeciwnym przypadku wyswietla stosowny komunikat o
 *    bledzie.
 */
LZespolona WczytajLZ ()
{
  LZespolona LZ;
  char pom;

  cin >> pom;
  if (pom == '(')
  {
    cin >> LZ.re;
    cin >> LZ.im;
    cin >> pom;
    if (pom != 'i')
    {
      cerr << "Blad: wczytanie liczby zespolonej nie powiodlo sie" << endl;
    } else {
      cin >> pom;
      if (pom != ')')
      {
        cerr << "Blad: wczytanie liczby zespolonej nie powiodlo sie" << endl;
      }
    }
  } else {
    cerr << "Blad: wczytanie liczby zespolonej nie powiodlo sie" << endl;
  }
  return LZ;
}



/*
 * Funkcja wyswietla na standardowym wyjsciu
 * liczbe zespolona.
 * 
 * Argument:
 *    Wynik - liczba zespolona, ktora
 *            zostanie wyswietlona.
 * 
 * Warunek wstepny:
 *    - Poprawnie zainicjowane elementy
 *      struktury LZespolona.
 */ 
void Wyswietl (LZespolona Wynik)
{
  cout << " (" << Wynik.re;
  if (Wynik.im >= 0) 
    {
      cout << "+" << Wynik.im << "i)";
    } else {
      cout << Wynik.im << "i)";
    }
}



/*
 * Funkcja wczytuje liczbe zespolona wpisana
 * przez uzytkownika na standardowym wejsciu.
 * 
 * Argumenty:
 *      StreamWej - zmienna typu istream
 *                  przekazana przez referencje,
 *      LZ - liczba zespolona, ktora zostanie
 *           wczytana. (tez przekazana przez
 *           referencje)
 * 
 * Warunek wstepny:
 *      - Pierwszy parametr musi byc przekazany
 *        przez referencje.
 *      - Drugi parametr tez musi byc przekazany
 *        przez referencje.
 *      - Liczba zespolona musi byc wpisana przez uzytkownika
 *        w odpowiedniej postaci, np.: (1+2i).
 *        (wpisanie w innej postaci powoduje postawienie 
 *        odpowniedniej flagi sygnalizujacej wystapienie bledu
 *        podczas wczytywania)
 * 
 * Zwraca:
 *      Referencje do pierwszego parametru.
 */ 
istream & operator >> (istream & StreamWej, LZespolona & LZ)
{
  char pom;

  StreamWej >> pom;
  if (pom == '(')
  {
    StreamWej >> LZ.re;
    StreamWej >> LZ.im;
    StreamWej >> pom;
    if (pom == 'i')
    {
      StreamWej >> pom;     
      if (!StreamWej.eof())
      {  
        if (pom == ')')
        {
          return StreamWej;
        } else {
          StreamWej.setstate(ios_base::failbit);       
        }
      } else {
          StreamWej.setstate(ios_base::failbit);
      }  
    } else {
      StreamWej.setstate(ios_base::failbit);
    }
  } else {
    StreamWej.setstate(ios_base::failbit);
  }
  return StreamWej;
}




/*
 * Funkcja wyswietla na standardowym wyjsciu
 * liczbe zespolona.
 * 
 * Argumenty:
 *      StreamWyj - zmienna typu ostream
 *                  przekazana przez referencje,
 *      LZ - liczba zespolona, ktora zostanie
 *           wyswietlona.
 * 
 * Warunek wstepny:
 *      - Pierwszy parametr musi byc przekazany
 *        przez referencje.
 *      - Poprawnie zainicjowane elementy 
 *        struktury LZespolona.
 * 
 * Zwraca:
 *       Referencje do pierwszego parametru.
 */ 
ostream & operator << (ostream & StreamWyj, LZespolona LZ)
{
  StreamWyj << " (" << LZ.re;
  if (LZ.im >= 0)
  {
    StreamWyj << "+" << LZ.im << "i)";
  } else {
    StreamWyj << LZ.im << "i)";
  }
  return StreamWyj;
}
