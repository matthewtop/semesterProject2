#include <iostream>
#include <cstdlib>
#include <string>
#include "classes.h"
#include <random>
#include <sstream>
#include <algorithm>
#include "functions.h"
#include <vector>

extern int global_int;
using namespace std;
int main() {
    const int MAX_KLIENCI = 100;
    Klient* klienci = new Klient[MAX_KLIENCI];
    int iloscKlientow = 0;
    int iloscSamochodow = 0;
    random_device rd;
    mt19937 e(rd());
    uniform_int_distribution<int> dr(5, 15);
    int maxIloscKlientow = dr(e);
    int maxIloscSamochodow = dr(e);
    bool dzialanie = true;
    Wypozyczalnia  wypozyczalnia;
    Samochod** samochody = new Samochod * [maxIloscSamochodow];
    wypozyczalnia.ustawSamochody(samochody);
    vector<Najem*> biuro;
    //demonstrowanie polimorfizmu
    Samochod samochod(1, "Ford", "Mustang", new Silnik(3000, 200));
    Klient klient(1, "John", "Doe", 30);
    
    while (dzialanie) {
        printMarkaModel(&samochod);
        printMarkaModel(&klient);
        cout << "" << endl;
        cout << "Wybierz opcje: " << endl;
        cout << "1.Dodaj Klienta " << endl;
        cout << "2.Dodaj Samochod " << endl;
        cout << "3.Pokaz Klientow " << endl;
        cout << "4.Pokaz samochody " << endl;
        cout << "5.Usun Klienta " << endl;
        cout << "6.Usun Samochod " << endl;
        cout << "7.Posortuj klientow wedlug wieku" << endl;
        cout << "8.Posortuj samochody wzgledem mocy" << endl;
        cout << "9.Wyswietl klientow zapisanych w pliku txt" << endl;
        cout << "10.Wyswietl samochody zapisane w pliku txt" << endl;
        cout << "11.Wyczysc zawartosc obu plikow tekstowych" << endl;
        cout << "12.Wynajmij samochod klientowi" << endl;
        cout << "13.Pokaz klientow oraz wypozyczone przez nich samochody" << endl;
        cout << "0.Wyjscie i wyczyszczenie pamieci" << endl;
        cout << "" << endl;
        cout << "Klienci: " << iloscKlientow << "/" << maxIloscKlientow << "" << "  Ilosc samochodow: " << iloscSamochodow << "/" << maxIloscSamochodow << endl;

        int wybor;
        cin >> wybor;
        system("cls");

        switch (wybor) {
        case 1:
            dodajKlienta(klienci, iloscKlientow, maxIloscKlientow, biuro);
            cout << "Dodano Klienta" << endl;
            break;
        case 2:
            dodajSamochod(samochody, iloscSamochodow, maxIloscSamochodow, biuro);
            cout << "Dodano samochod" << endl;
            break;
        case 3:
            cout << "Lista klientow: " << endl;
            pokazKlienci(klienci, iloscKlientow);
            break;
        case 4:
            cout << "Lista samochodow: " << endl;
            pokazSamochody(samochody, iloscSamochodow);
            break;
        case 5:
            usunKlienta(klienci, iloscKlientow);
            cout << "Klient usuniety" << endl;
            break;
        case 6:
            usunSamochod(samochody, iloscSamochodow);
            cout << "Samochod usuniety" << endl;
            break;
        case 7:
            sortujKlientowRosnaco(klienci, iloscKlientow);
            pokazKlienci(klienci, iloscKlientow);
            break;
        case 8:
            sortujSamochodyWzgledemMocy(samochody, iloscSamochodow);
            break;
        case 9:
            wyswietlKlientow();
            break;
        case 10:
            wyswietlSamochody();
            break;
        case 11:
            wyczyscPliki();
            break;
        case 12:
            wynajmijSamochod(biuro);
            break;
        case 13:
            wyswietlNajem(biuro);
            break;
        case 0:
            zakonczProgram(klienci, samochody, iloscKlientow, iloscSamochodow);
            break;
        default:
            break;
        }
    }
}
