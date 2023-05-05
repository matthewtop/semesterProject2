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
        cout << "Podaj marke, model, pojemnosc i moc silnika oddzielajac je srednikiem (;): " << endl;
        cout << "Dane: ";
        getline(cin, daneSamochodu);
        size_t pos = daneSamochodu.find(";");
        SamochodTabTemp[iloscSamochodow] = new Samochod();
        SamochodTabTemp[iloscSamochodow]->id = iloscSamochodow + 1;
        SamochodTabTemp[iloscSamochodow]->marka = daneSamochodu.substr(0, pos);
        size_t prev_pos = pos + 1;
        pos = daneSamochodu.find(";", prev_pos);
        SamochodTabTemp[iloscSamochodow]->model = daneSamochodu.substr(prev_pos, pos - prev_pos);
        prev_pos = pos + 1;
        pos = daneSamochodu.find(";", prev_pos);
        SamochodTabTemp[iloscSamochodow]->silnik.pojemnosc = stoi(daneSamochodu.substr(prev_pos, pos - prev_pos));
        prev_pos = pos + 1;
        pos = daneSamochodu.find(";", prev_pos);
        SamochodTabTemp[iloscSamochodow]->silnik.moc = stoi(daneSamochodu.substr(prev_pos, pos - prev_pos));
        prev_pos = pos + 1;
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
            SamochodTab[i]->id << ". Samochod: " << SamochodTab[i]->marka << " " << SamochodTab[i]->model << "\nMoc: " << SamochodTab[i]->silnik.moc << " KM" << "\nPojemnosc silnika: " << SamochodTab[i]->silnik.pojemnosc << " cm^3" << endl;
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



bool porownajMoc(Samochod* a, Samochod* b) {
    return a->silnik.moc > b->silnik.moc;
}

void posortujSamochody(Samochod** SamochodTab, int iloscSamochodow) {
    sort(SamochodTab, SamochodTab + iloscSamochodow, porownajMoc);
}

void wyswietlPosortowaneSamochody(Samochod** SamochodTab, int iloscSamochodow) {
    cout << "Posortowane samochody (od największej mocy): " << endl;
    if (iloscSamochodow != 0) {
        for (int i = 0; i < iloscSamochodow; i++) {
            cout << SamochodTab[i]->id << ". " << SamochodTab[i]->marka << " " << SamochodTab[i]->model << ", moc: " << SamochodTab[i]->silnik.moc << " KM\n";
        }
    }
    else {
        cout << "Brak Samochodow do posortowania" << endl;
    }
}

void sortujKlientowRosnaco(Wypozyczalnia wypozyczalnia, int liczbaKlientow) {
    for (int i = 0; i < liczbaKlientow - 1; i++) {
        for (int j = 0; j < liczbaKlientow - i - 1; j++) {
            if (wypozyczalnia.klienci[j].wiek > wypozyczalnia.klienci[j + 1].wiek) {
                Klient temp = wypozyczalnia.klienci[j];
                wypozyczalnia.klienci[j] = wypozyczalnia.klienci[j + 1];
                wypozyczalnia.klienci[j + 1] = temp;
            }
        }
    }
}



int main()
{
    int iloscKlientow = 0;
    int iloscSamochodow = 0;
    random_device rd;
    mt19937 e(rd());
    uniform_int_distribution<int> dr(5, 15);
    int maxIloscKlientow = dr(e);
    int maxIloscSamochodow = dr(e);
    bool dzialanie = true;
    Wypozyczalnia wypozyczalnia;
    wypozyczalnia.samochody = new Samochod * [maxIloscSamochodow];
    wypozyczalnia.klienci = new Klient[maxIloscKlientow];

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
            
            dodajKlienta(wypozyczalnia.klienci, iloscKlientow, maxIloscKlientow);
            cout << "Dodano Klienta" << endl;
            break;
        case 2:
            dodajSamochod(wypozyczalnia.samochody, iloscSamochodow, maxIloscSamochodow);
            cout << "Dodano samochod" << endl;
            break;
        case 3:
            cout << "Lista klientow: " << endl;
            pokazKlienci(wypozyczalnia.klienci, iloscKlientow);
            break;
        case 4:
            cout << "Lista samochodow: " << endl;
            pokazSamochody(wypozyczalnia.samochody, iloscSamochodow);
            break;
        case 5:
            usunKlienta(wypozyczalnia.klienci , iloscKlientow);
            cout << "Klient usuniety" << endl;
            break;
        case 6:
            usunSamochod(wypozyczalnia.samochody , iloscSamochodow);
            cout << "Samochod usuniety" << endl;
            break;
        case 7:
            sortujKlientowRosnaco(wypozyczalnia, iloscKlientow);
            pokazKlienci(wypozyczalnia.klienci, iloscKlientow);
            break;
        case 8:
            posortujSamochody(wypozyczalnia.samochody, iloscSamochodow);
            wyswietlPosortowaneSamochody(wypozyczalnia.samochody, iloscSamochodow);
            break;
        case 0:
            dzialanie = wyczyscPamiec(wypozyczalnia.klienci, wypozyczalnia.samochody, iloscKlientow, iloscSamochodow);
            break;
        default:
            break;
        }
    }
}
