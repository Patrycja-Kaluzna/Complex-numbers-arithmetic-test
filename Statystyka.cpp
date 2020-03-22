#include "Statystyka.hh"

/* Funkcja wyswietla na standardowym wyjsciu statystyke dotyczaca
 * udzielonych przez uzytkownika odpowiedzi na pytania z testu.
 * 
 * Parametr:
 *      Stat - zmienna, z ktorej zostana pobrane dane statycztyczne
 *             do wyswietlenia.
 * 
 * Warunek wstepny:
 *      - Poprwanie zainicjowane elementy struktury Statystyka.
 */
void WyswietlStatystyke (Statystyka Stat)
{
cout << " Ilosc dobrych odpowiedzi: " << Stat.DobreOdp << endl;
cout << " Ilosc blednych odpowiedzi: " << Stat.ZleOdp << endl;
cout << " Wynik procentowy poprawnych odpowiedzi: " << setprecision(3) << (Stat.DobreOdp * 100 / (Stat.DobreOdp + Stat.ZleOdp)) << "%" << endl;
}
