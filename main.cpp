#include <iostream>
#include <cstdlib>
#include <string>
#include "structures.h"
#include <random>
#include <sstream>


using namespace std;


void dodajKlienta(Klient*& KlientTab, int& iloscKlientow, int maxIloscKlientow) {
    if (iloscKlientow < maxIloscKlientow) {
        Klient* KlientTabTemp = new Klient[iloscKlientow + 1];
        int i = 0;
        if (iloscKlientow > 0) {
            for (i; i < iloscKlientow; i++)
            {
                KlientTabTemp[i] = KlientTab[i];
            }
        }
        cin.ignore();
        string daneKlienta;
        cout << "Podaj imie, nazwisko i wiek klienta oddzielajac je srednikiem (;): ";
        getline(cin, daneKlienta);
        size_t pos = daneKlienta.find(";");
        KlientTabTemp[iloscKlientow].id = iloscKlientow + 1;
        KlientTabTemp[iloscKlientow].imie = daneKlienta.substr(0, pos);
        size_t prev_pos = pos + 1;
        pos = daneKlienta.find(";", prev_pos);
        KlientTabTemp[iloscKlientow].nazwisko = daneKlienta.substr(prev_pos, pos - prev_pos);
        prev_pos = pos + 1;
        KlientTabTemp[iloscKlientow].wiek = stoi(daneKlienta.substr(prev_pos));
        delete[] KlientTab;
        KlientTab = KlientTabTemp;
        iloscKlientow++;
    }
    else
        cout << "Nie mozna dodac wiecej klientow!" << endl;
}
void dodajSamochod(Samochod**& SamochodTab, int& iloscSamochodow, int maxIloscSamochodow) {
    if (iloscSamochodow < maxIloscSamochodow) {
        Samochod** SamochodTabTemp = new Samochod * [iloscSamochodow + 1];
        int i = 0;
        if (iloscSamochodow > 0) {
            for (i; i < iloscSamochodow; i++)
            {
                SamochodTabTemp[i] = SamochodTab[i];
            }
        }
        cin.ignore();
        string daneSamochodu;
        cout << "Podaj marke, model, rok produkcji i przebieg samochodu oddzielajac je srednikiem (;): ";
        getline(cin, daneSamochodu);
        size_t pos = daneSamochodu.find(";");
        SamochodTabTemp[iloscSamochodow] = new Samochod();
        SamochodTabTemp[iloscSamochodow]->id = iloscSamochodow+1;
        SamochodTabTemp[iloscSamochodow]->marka = daneSamochodu.substr(0, pos);
        size_t prev_pos = pos + 1;
        pos = daneSamochodu.find(";", prev_pos);
        SamochodTabTemp[iloscSamochodow]->model = daneSamochodu.substr(prev_pos, pos - prev_pos);
        prev_pos = pos + 1;
       // pos = daneSamochodu.find(";", prev_pos);
       // SamochodTabTemp[iloscSamochodow]->rok = stoi(daneSamochodu.substr(prev_pos, pos - prev_pos));
        //prev_pos = pos + 1;
        SamochodTabTemp[iloscSamochodow]->moc = stoi(daneSamochodu.substr(prev_pos));
        SamochodTab = SamochodTabTemp;
        iloscSamochodow++;
    }
    else
        cout << "Nie mozna dodac wiecej samochodow!" << endl;
}



void pokazKlienci(Klient*& KlientTab, int& iloscKlientow) {
    for (int i = 0; i < iloscKlientow; i++)
    {
        cout << endl <<
            KlientTab[i].id << ". Godnosc: " << KlientTab[i].imie << " " << KlientTab[i].nazwisko << "\nWiek: " << KlientTab[i].wiek << endl;
    }
}

void pokazSamochody(Samochod**& SamochodTab, int& iloscSamochodow) {
    for (int i = 0; i < iloscSamochodow; i++)
    {
        cout << endl <<
            SamochodTab[i]->id << ". Samochod: " << SamochodTab[i]->marka << " " << SamochodTab[i]->model << "\nMoc: " << SamochodTab[i]->moc << " KM" << endl;
    }
}

//usuwanie, kopiowanie elementow do mniejszej tablicy z wyjatkiem wybranego
void usunKlienta(Klient*& KlientTab, int& iloscKlientow) {
    if (iloscKlientow != 0) {
        cout << "Wprowadz numer klienta do usuniecia:" << endl;
        int id;
        cin >> id;
        bool klientZnaleziony = false;
        for (int i = 0; i < iloscKlientow; i++) {
            if (KlientTab[i].id == id) {
                Klient* KlientTabTemp = new Klient[iloscKlientow - 1];
                for (int j = 0; j < iloscKlientow - 1; j++) {
                    if (j >= i) {
                        KlientTabTemp[j] = KlientTab[j + 1];
                        KlientTabTemp[j].id--;
                    }
                    else
                        KlientTabTemp[j] = KlientTab[j];
                }
                delete[] KlientTab;
                KlientTab = KlientTabTemp;
                --iloscKlientow;
                klientZnaleziony = true;
                break;
            }
        }
        if (!klientZnaleziony)
            cout << "Nie znaleziono klienta o podanym numerze ID" << endl;
    }
    else
        cout << "Brak klientow" << endl;
}
void usunSamochod(Samochod**& SamochodTab, int& iloscSamochodow) {
    if (iloscSamochodow != 0) {
        Samochod** SamochodTabTemp = new Samochod * [iloscSamochodow - 1];
        cout << "Wprowadz numer samochodu do usuniecia: " << endl;
        int id;
        cin >> id;
        if (id <= iloscSamochodow) {
            for (int i = 0; i < iloscSamochodow - 1; i++) {
                if (i >= id - 1) {
                    SamochodTabTemp[i] = new Samochod;
                    *SamochodTabTemp[i] = *SamochodTab[i + 1];
                    SamochodTabTemp[i]->id--;
                }
                else {
                    SamochodTabTemp[i] = new Samochod;
                    *SamochodTabTemp[i] = *SamochodTab[i];
                }
            }
            delete SamochodTab[id - 1];
            delete[] SamochodTab;
            SamochodTab = SamochodTabTemp;
            --iloscSamochodow;
        }
        else
            cout << "Podano bledny numer" << endl;
    }
    else
        cout << "Brak samochodow" << endl;
}

//usuniecie wszystkich obiektow i wyczyszczenie pamieci
bool wyczyscPamiec(Klient*& KlientTab, Samochod**& SamochodTab, int iloscKlientow, int iloscSamochodow) {
    delete[] KlientTab;
    KlientTab = nullptr;
    for (int i = 0; i < iloscSamochodow; i++) {
        delete SamochodTab[i];
    }
    delete[] SamochodTab;
    SamochodTab = nullptr;
    return false;
}

void wiekKlienci(Klient* KlientTab, int iloscKlientow) {
    for (int i = 0; i < iloscKlientow; i++) {
        KlientTab[i].wiek += 5;
    }
    cout << "Zwiekszono wiek wszystkich klientow o 5" << endl;
}

void mocSamochody(Samochod** SamochodyTab, int iloscSamochodow) {
    for (int i = 0; i < iloscSamochodow; i++) {
        SamochodyTab[i]->moc += 100;
    }
    cout << "Zwiekszono moc wszystkich samochodow o 100 koni mechanicznych." << endl;
}

void wprowadzDaneKlienta(Klient* KlientTab) {
    string input;
    cout << "Podaj id, imię, nazwisko i wiek klienta, oddzielając każdy atrybut średnikiem: ";
    getline(cin, input);

    stringstream ss(input);
    string token;

    getline(ss, token, ';');
    KlientTab->id = stoi(token);

    getline(ss, KlientTab->imie, ';');

    getline(ss, KlientTab->nazwisko, ';');

    getline(ss, token, ';');
    KlientTab->wiek = stoi(token);
}



int main()
{
    default_random_engine e;
    uniform_int_distribution<unsigned> u(3, 10);
    int maxIloscKlientow = u(e);
    int maxIloscSamochodow = u(e);

    bool dzialanie = true;
    int iloscKlientow = 0;
    int iloscSamochodow = 0;
    Klient* KlientTab = new Klient[maxIloscKlientow];
    Samochod** SamochodTab = new Samochod * [maxIloscSamochodow];

    while (dzialanie) {
        cout << "" << endl;
        cout << "Wybierz opcje: " << endl;
        cout << "1.Dodaj Klienta " << endl;
        cout << "2.Dodaj Samochod " << endl;
        cout << "3.Pokaz Klientow " << endl;
        cout << "4.Pokaz samochody " << endl;
        cout << "5.Usun Klienta " << endl;
        cout << "6.Usun Samochod " << endl;
        cout << "7.Zwieksz wiek wszystkich klientow o 5" << endl;
        cout << "8.Zwieksz moc wszystkich samochodow o 100KM" << endl;
        cout << "0.Wyjscie i wyczyszczenie pamieci" << endl;
        cout << "" << endl;
        cout << "Klienci: " << iloscKlientow << "/" << maxIloscKlientow << "" << "  Ilosc samochodow: " << iloscSamochodow << "/" << maxIloscSamochodow << endl;

        int wybor;
        cin >> wybor;
        system("cls");

        switch (wybor) {
        case 1:
            
            dodajKlienta(KlientTab, iloscKlientow, maxIloscKlientow);
            cout << "Dodano Klienta" << endl;
            break;
        case 2:
            dodajSamochod(SamochodTab, iloscSamochodow, maxIloscSamochodow);
            cout << "Dodano samochod" << endl;
            break;
        case 3:
            cout << "Lista klientow: " << endl;
            pokazKlienci(KlientTab, iloscKlientow);
            break;
        case 4:
            cout << "Lista samochodow: " << endl;
            pokazSamochody(SamochodTab, iloscSamochodow);
            break;
        case 5:
            usunKlienta(KlientTab, iloscKlientow);
            cout << "Klient usuniety" << endl;
            break;
        case 6:
            usunSamochod(SamochodTab, iloscSamochodow);
            cout << "Samochod usuniety" << endl;
            break;
        case 7:
            wiekKlienci(KlientTab, iloscKlientow);
            break;
        case 8:
            mocSamochody(SamochodTab, iloscSamochodow);
            break;
        case 0:
            dzialanie = wyczyscPamiec(KlientTab, SamochodTab, iloscKlientow, iloscSamochodow);
            break;
        default:
            break;
        }
    }
}
