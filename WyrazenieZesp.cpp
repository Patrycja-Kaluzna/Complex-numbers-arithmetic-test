#include "WyrazenieZesp.hh"

/*
 * Funkcja wyswietla na standardowym wyjsciu
 * wyrazenie zespolone przy wykorzystaniu
 * funkcji wyswietlenia liczby zespolonej.
 * 
 * Argument:
 *      WyrZ - wyrazenie zespolone, ktore
 *             zostanie wyswietlone.
 * 
 * Warunek wstepny:
 *      Poprawnie zainicjowane elementy 
 *      struktury WyrazenieZesp (wiec tez
 *      LZespolona). 
 */ 
void Wyswietl (WyrazenieZesp WyrZ)
{
    Wyswietl (WyrZ.Arg1);
    switch (WyrZ.Op)
    {
    case Op_Dodaj:
        cout << " +";
        break;
    case Op_Odejmij:
        cout << " -";
        break;
    case Op_Mnoz:
        cout << " *";
        break;
    case Op_Dziel:
        cout << " /";
        break;
    case Op_Modulo:
        cout << " %";
        break;
    }
    Wyswietl (WyrZ.Arg2);
}



/*
 * Funkcja wczytuje wyrazenie zespolone wpisane
 * przez uzytkownika na standardowym wejsciu przy
 * wykorzystaniu funkcji wczytania liczby zespolonej.
 * 
 * Warunek wstepny:
 *      - Wyrazenie zespolone musi byc wpisane przez
 *      uzytkownika w odpowiedniej postaci, np.:
 *      (1+2i) + (3+4i) lub (1+2i)+(3+4i).
 *      (wpisanie w innej postaci powoduje wyswietlenie
 *      komunikatu o bledzie)
 * 
 * Zwraca:
 *      W przypadku powodzenia wczytane wyrazenie
 *      zespolone, a w przciwynym przypadku wyswietla 
 *      stosowny komunikat o bledzie.
 */
WyrazenieZesp WczytajWZ ()
{  
    WyrazenieZesp WyrZ;
    char pom;

    WyrZ.Arg1 = WczytajLZ ();
    cin >> pom;
    switch (pom)
    {
    case '+':
        WyrZ.Op = Op_Dodaj;
        break;
    case '-':
        WyrZ.Op = Op_Odejmij;
        break;
    case '*':
        WyrZ.Op = Op_Mnoz;
        break;
    case '/':
        WyrZ.Op = Op_Dziel;
        break;
    case '%':
        WyrZ.Op = Op_Modulo;
        break;
    default:
        cerr << "Blad: wczytanie wyrazenia zespolonego nie powiodlo sie" << endl;
        break;
    }
    WyrZ.Arg2 = WczytajLZ ();
    return WyrZ;
} 



/*
 * Funkcja interpetuje oraz oblicza wartosc
 * wyrazenia zespolonego przy wykorzystaniu
 * przeciazen operatorow arytmetycznych dla
 * operacji dodawania, odejmowania, mnozenia
 * i dzielenia liczb zespolonych.
 * 
 * Argument: 
 *      WyrZ - wyrazenie zespolone, ktore
 *             zostanie zinterpretowane, a
 *             nastepnie obliczone.
 * 
 * Warunek wstepny:
 *      Poprawnie zainicjowane elementy struktury
 *      WyrazenieZesp (wiec tez LZespolona). 
 * 
 * Zwraca:
 *      Liczbe zespolona bedaca wynikiem obliczen.
 */            
LZespolona Oblicz (WyrazenieZesp WyrZ)
{
    LZespolona LZ;

    switch (WyrZ.Op)
    {
    case Op_Dodaj:
        LZ = WyrZ.Arg1 + WyrZ.Arg2;
        break;
    case Op_Odejmij:
        LZ = WyrZ.Arg1 - WyrZ.Arg2;
        break;
    case Op_Mnoz:
        LZ = WyrZ.Arg1 * WyrZ.Arg2;
        break;
    case Op_Dziel:
        LZ = WyrZ.Arg1 / WyrZ.Arg2;
        break;
    case Op_Modulo:
        LZ = WyrZ.Arg1 % WyrZ.Arg2;
        break;
    }
    return LZ;
}



/*
 * Funkcja wyswietla na standardowym wyjsciu
 * wyrazenie zespolone przy wykorzystaniu
 * przeciazenia operatora << dla liczby zespolonej.
 * 
 * Argumenty:
 *      StreamWyj - zmienna typu ostream
 *                  przekazana przez referencje,
 *      WZ - wyrazenie zespolone, ktore zostanie
 *           wyswietlone.
 * 
 * Warunek wstepny:
 *      - Pierwszy parametr musi byc przekazany
 *        przez referencje.
 *      - Poprawnie zainicjowane elementy 
 *        struktury WyrazenieZesp (wiec tez
 *        LZespolona).
 * 
 * Zwraca:
 *       Referencje do pierwszego parametru.
 */ 
ostream & operator << (ostream & StreamWyj, WyrazenieZesp WZ)
{
    StreamWyj << WZ.Arg1;
    switch (WZ.Op)
    {
    case Op_Dodaj:
        StreamWyj << " +";
        break;
    case Op_Odejmij:
        StreamWyj << " -";
        break;
    case Op_Mnoz:
        StreamWyj << " *";
        break;
    case Op_Dziel:
        StreamWyj << " /";
        break;
    case Op_Modulo:
        StreamWyj << " %";
        break;
    }
    StreamWyj << WZ.Arg2;
    return StreamWyj;
}
