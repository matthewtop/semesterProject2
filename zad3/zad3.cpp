#include <iostream>
#include <cstdlib>
#include <string>
#include "classes.h"
#include <random>
#include <sstream>
#include <algorithm>


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
            delete[] KlientTab;
        }
        cin.ignore();
        string daneKlienta;
        cout << "Podaj imie, nazwisko i wiek klienta oddzielajac je srednikiem (;): ";
        getline(cin, daneKlienta);
        size_t pos = daneKlienta.find(";");
        Klient klient;
        klient.setImie(daneKlienta.substr(0, pos));
        size_t prev_pos = pos + 1;
        pos = daneKlienta.find(";", prev_pos);
        klient.setNazwisko(daneKlienta.substr(prev_pos, pos - prev_pos));
        prev_pos = pos + 1;
        klient.setWiek(stoi(daneKlienta.substr(prev_pos)));
        klient.setId(iloscKlientow + 1);
        KlientTabTemp[iloscKlientow] = klient;
        KlientTab = KlientTabTemp;
        iloscKlientow++;
    }
    else {
        cout << "Nie mozna dodac wiecej klientow!" << endl;
    }
}
void dodajSamochod(Samochod**& SamochodTab, int& iloscSamochodow, int maxIloscSamochodow) {
    if (iloscSamochodow < maxIloscSamochodow) {
        Samochod** SamochodTabTemp = new Samochod * [iloscSamochodow + 1];
        int i = 0;
        if (iloscSamochodow > 0) {
            for (i = 0; i < iloscSamochodow; i++) {
                SamochodTabTemp[i] = SamochodTab[i];
            }
            delete[] SamochodTab;
        }

        string daneSamochodu;
        cout << "Podaj marke, model, pojemnosc i moc silnika oddzielajac je srednikiem (;): " << endl;
        cout << "Dane: ";
        cin.ignore();
        getline(cin, daneSamochodu);
        size_t pos = daneSamochodu.find(";");
        string marka = daneSamochodu.substr(0, pos);
        size_t prev_pos = pos + 1;
        pos = daneSamochodu.find(";", prev_pos);
        string model = daneSamochodu.substr(prev_pos, pos - prev_pos);
        prev_pos = pos + 1;
        pos = daneSamochodu.find(";", prev_pos);
        int pojemnosc = stoi(daneSamochodu.substr(prev_pos, pos - prev_pos));
        prev_pos = pos + 1;
        pos = daneSamochodu.find(";", prev_pos);
        int moc = stoi(daneSamochodu.substr(prev_pos, pos - prev_pos));
        prev_pos = pos + 1;

        SamochodTabTemp[iloscSamochodow] = new Samochod(iloscSamochodow + 1, marka, model, Silnik(pojemnosc, moc));

        SamochodTab = SamochodTabTemp;
        iloscSamochodow++;
    }
    else {
        cout << "Nie mozna dodac wiecej samochodow!" << endl;
    }
}



void pokazKlienci(Klient* klientTab, int iloscKlientow) {
    if (iloscKlientow != 0) {
        for (int i = 0; i < iloscKlientow; i++)
        {
            cout << endl << klientTab[i].getId() << ". Godnosc: " << klientTab[i].getImie() << " " << klientTab[i].getNazwisko() << "\nWiek: " << klientTab[i].getWiek() << endl;
        }
    }
    else {
        cout << "Brak klientow w bazie!" << endl;
    }
}

void pokazSamochody(Samochod** samochody, int iloscSamochodow) {
    if (iloscSamochodow != 0) {
        for (int i = 0; i < iloscSamochodow; i++) {
            cout << endl <<
                samochody[i]->getId() << ". Samochod: " << samochody[i]->getMarka() << " " << samochody[i]->getModel() << "\nMoc: " << samochody[i]->getSilnik().getMoc() << " KM" << "\nPojemnosc silnika: " << samochody[i]->getSilnik().getPojemnosc() << " cm^3" << endl;
        }
    }
    else {
        cout << "Brak samochodow w bazie!" << endl;
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
            if (KlientTab[i].getId() == id) {
                Klient* KlientTabTemp = new Klient[iloscKlientow - 1];
                for (int j = 0; j < iloscKlientow - 1; j++) {
                    if (j >= i) {
                        KlientTabTemp[j] = KlientTab[j + 1];
                        KlientTabTemp[j].setId(KlientTabTemp[j].getId() - 1);
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
        cout << "Wprowadz numer samochodu do usuniecia:" << endl;
        int id;
        cin >> id;
        bool samochodZnaleziony = false;
        for (int i = 0; i < iloscSamochodow; i++) {
            if (SamochodTab[i]->getId() == id) {
                Samochod* SamochodTabTemp = new Samochod[iloscSamochodow - 1];
                for (int j = 0; j < iloscSamochodow - 1; j++) {
                    if (j >= i) {
                        SamochodTabTemp[j] = *SamochodTab[j + 1];
                        SamochodTabTemp[j].setId(SamochodTabTemp[j].getId() - 1);
                    }
                    else
                        SamochodTabTemp[j] = *SamochodTab[j];
                }
                delete SamochodTab[i];
                delete[] SamochodTab;
                SamochodTab = new Samochod * [iloscSamochodow - 1];
                for (int j = 0; j < iloscSamochodow - 1; j++) {
                    SamochodTab[j] = new Samochod(SamochodTabTemp[j]);
                }
                delete[] SamochodTabTemp;
                --iloscSamochodow;
                samochodZnaleziony = true;
                break;
            }
        }
        if (!samochodZnaleziony)
            cout << "Nie znaleziono samochodu o podanym numerze ID" << endl;
    }
    else
        cout << "Brak samochodow" << endl;
}

//usuniecie wszystkich obiektow i wyczyszczenie pamieci
void zakonczProgram(Klient*& KlientTab, Samochod**& SamochodTab, int iloscKlientow, int iloscSamochodow) {
    delete[] KlientTab;
    KlientTab = nullptr;
    for (int i = 0; i < iloscSamochodow; i++) {
        delete SamochodTab[i];
    }
    delete[] SamochodTab;
    SamochodTab = nullptr;
    exit(0);
}



void sortujSamochodyWzgledemMocy(Samochod**& SamochodTab, int& iloscSamochodow) {
    for (int i = 0; i < iloscSamochodow - 1; i++) {
        for (int j = 0; j < iloscSamochodow - i - 1; j++) {
            if (SamochodTab[j]->getSilnik().getMoc() > SamochodTab[j + 1]->getSilnik().getMoc()) {
                Samochod* temp = SamochodTab[j];
                SamochodTab[j] = SamochodTab[j + 1];
                SamochodTab[j + 1] = temp;
            }
        }
    }
    // Wyświetlenie posortowanej tablicy
    pokazSamochody(SamochodTab, iloscSamochodow);
}
   

void sortujKlientowRosnaco(Klient*& klientTab, int liczbaKlientow) {
    for (int i = 0; i < liczbaKlientow - 1; i++) {
        for (int j = 0; j < liczbaKlientow - i - 1; j++) {
            if (klientTab[j].getWiek() > klientTab[j + 1].getWiek()) {
                Klient temp = klientTab[j];
                klientTab[j] = klientTab[j + 1];
                klientTab[j + 1] = temp;
            }
        }
    }
}



int main()
{
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
    while (dzialanie) {
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
        cout << "0.Wyjscie i wyczyszczenie pamieci" << endl;
        cout << "" << endl;
        cout << "Klienci: " << iloscKlientow << "/" << maxIloscKlientow << "" << "  Ilosc samochodow: " << iloscSamochodow << "/" << maxIloscSamochodow << endl;

        int wybor;
        cin >> wybor;
        system("cls");

        switch (wybor) {
        case 1:

            dodajKlienta(klienci, iloscKlientow, maxIloscKlientow);
            cout << "Dodano Klienta" << endl;
            break;
        case 2:
            dodajSamochod(samochody, iloscSamochodow, maxIloscSamochodow);
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
        case 0:
            zakonczProgram(klienci, samochody, iloscKlientow, iloscSamochodow);
            break;
        default:
            break;
        }
    }
}
