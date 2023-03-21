#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;
//-------------Struktury------------------
//
//klienci
string imiona[] = { "Mateusz", "Krzysztof", "Ferdynand", "Pawel", "Kacper" };
string nazwiska[] = { "Nowak", "Kowalski", "Nowy", "Stary", "Pyrkowski" };
int imionaLength = sizeof(imiona) / sizeof(imiona[0]) - 1;
int nazwiskaLength = sizeof(nazwiska) / sizeof(nazwiska[0]) - 1;
//samochody
string marki[] = { "BMW", "Renault", "Lamborghini", "Volksvagen", "Aston Martin", "Alfa Romeo", "Mercedes", "Ferrari", "Dodge" };
string modele[] = { "Passat", "3 Series", "GTR", "GT", "Laguna", "Mondeo", "Hellcat", "Demon", "Aventador" };
int markiLength = sizeof(marki) / sizeof(marki[0]) - 1;
int modeleLength = sizeof(modele) / sizeof(modele[0]) - 1;

struct Klient {
    int id;
    string imie;
    string nazwisko;
    int wiek;
};

struct Samochod {
    int id;
    string marka;
    string model;
    int moc;
};
//----------------------------------

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
        KlientTabTemp[iloscKlientow].id = iloscKlientow;
        KlientTabTemp[iloscKlientow].imie = "";
        KlientTabTemp[iloscKlientow].nazwisko = "";
        KlientTabTemp[iloscKlientow].wiek = 0;
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
        SamochodTabTemp[iloscSamochodow] = new Samochod;
        SamochodTabTemp[iloscSamochodow]->id = iloscSamochodow;
        SamochodTabTemp[iloscSamochodow]->marka = "";
        SamochodTabTemp[iloscSamochodow]->model = "";
        SamochodTabTemp[iloscSamochodow]->moc = 0;
        delete[] SamochodTab;
        SamochodTab = SamochodTabTemp;
        iloscSamochodow++;
    }
    else
        cout << "Nie mozna dodac wiecej samochodow!" << endl;
}

//przydzielanie losowych atrybutow
void iniKlienci(Klient*& KlientTab, int& iloscKlientow) {
    string choice;
    int i = 0;
    for (i; i < iloscKlientow; i++) {
        if (KlientTab[i].imie == "") {
            KlientTab[i].id = i;
            KlientTab[i].imie = imiona[rand() % imionaLength];
            KlientTab[i].nazwisko = nazwiska[rand() % nazwiskaLength];
            KlientTab[i].wiek = rand() %18 + 66;
        }
    }
}

void iniSamochody(Samochod**& SamochodTab, int& iloscSamochodow) {
    int i = 0;
    for (i; i < iloscSamochodow; i++) {
            if (SamochodTab[i]->marka == "") {
                SamochodTab[i] = new Samochod;
                SamochodTab[i]->id = i;
                SamochodTab[i]->marka = marki[rand() % markiLength];
                SamochodTab[i]->model = modele[rand() % modeleLength];
                SamochodTab[i]->moc = rand() % 650 + 100;
             }
    }
}

void pokazKlienci(Klient*& KlientTab, int& iloscKlientow) {
    for (int i = 0; i < iloscKlientow; i++)
    {
        cout << endl <<
            KlientTab[i].id << ". Godnosc: " << KlientTab[i].imie << " " << KlientTab[i].nazwisko << "\nWiek: " << KlientTab[i].wiek << "\n";
    }
}

void pokazSamochody(Samochod**& SamochodTab, int& iloscSamochodow) {
    for (int i = 0; i < iloscSamochodow; i++)
    {
        cout << endl <<
            SamochodTab[i]->id << ". Samochod: " << SamochodTab[i]->marka << " " << SamochodTab[i]->model << "\nMoc: " << SamochodTab[i]->moc << " KM" << "\n";
    }
}

//usuwanie, kopiowanie elementow do mniejszej tablicy z wyjatkiem wybranego
void usunKlienta(Klient*& KlientTab, int& iloscKlientow) {
    if (iloscKlientow != 0) {
        Klient* KlientTabTemp = new Klient[iloscKlientow - 1];
        cout << "Wprowadz numer klienta do usuniecia:" << endl;
        int id;
        cin >> id;
        if (id <= iloscKlientow) {
            for (int i = 0; i < iloscKlientow - 1; i++) {
                if (i >= id) {
                    KlientTabTemp[i] = KlientTab[i + 1];
                    KlientTabTemp[i].id--;
                }
                else
                    KlientTabTemp[i] = KlientTab[i];
            }
            delete[] KlientTab;
            KlientTab = KlientTabTemp;
            --iloscKlientow;
        }
        else
            cout << "Podano bledny numer"<<endl;
    }
    else
        cout << "Brak klientow"<<endl;
}

void usunSamochody(Samochod**& SamochodTab, int& iloscSamochodow) {
    if (iloscSamochodow != 0) {
        Samochod** SamochodTabTemp = new Samochod * [iloscSamochodow - 1];
        cout << "Wprowadz numer samochodu do usuniecia: " << endl;
        int id;
        cin >> id;
        if (id <= iloscSamochodow) {
            for (int i = 0; i < iloscSamochodow - 1; i++) {
                if (i >= id) {
                    SamochodTabTemp[i] = new Samochod;
                    SamochodTabTemp[i] = SamochodTab[i + 1];
                    SamochodTabTemp[i]->id--;
                }
                else {
                    SamochodTabTemp[i] = new Samochod;
                    SamochodTabTemp[i] = SamochodTab[i];
                }
            }
            delete SamochodTab[id];
            delete[] SamochodTab;
            SamochodTab = SamochodTabTemp;
            --iloscSamochodow;
        }
        else
            cout << "Podano bledny numer"<<endl;
    }
    else
        cout << "Brak samochodow"<<endl;
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

int main()
{
    bool dzialanie = true;

    srand(1000);
    int maxIloscKlientow = rand() % 10 + 5; //losowanie wielkosci tablicy
    int maxIloscSamochodow = rand() % 10 + 5;
    int iloscKlientow = 0;
    int iloscSamochodow = 0;
    Klient* KlientTab = new Klient[maxIloscKlientow];
    Samochod** SamochodTab = new Samochod * [maxIloscSamochodow];

    while (dzialanie) {
        cout << "" << endl;
        cout << "Wybierz opcje: " << endl;
        cout << "1.dodaj Klienta " << endl;
        cout << "2.dodaj Samochod " << endl;
        cout << "3.Wypelnij tablice klientow danymi" << endl;
        cout << "4.Zapelnij tablice samochodow " << endl;
        cout << "5.Pokaz Klientow " << endl;
        cout << "6.Pokaz samochody " << endl;
        cout << "7.Usun Klienta " << endl;
        cout << "8.Usun Samochod " << endl;
        cout << "0.Wyjscie i wyczyszczenie pamieci" << endl;
        cout<<""<<endl;
        cout << "Klienci: " << iloscKlientow << "/" << maxIloscKlientow << "" << "  Ilosc samochodow: " << iloscSamochodow << "/" << maxIloscSamochodow << endl;

        int wybor;
        cin >> wybor;

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
            iniKlienci(KlientTab, iloscKlientow);
            cout << "Tablica kleintow wypelniona" << endl;

            break;
        case 4:
            iniSamochody(SamochodTab, iloscSamochodow);
            cout << "Tablica kleintow wypelniona" << endl;
            break;
        case 5:
            cout << "Lista klientow: " << endl;
            pokazKlienci(KlientTab, iloscKlientow);
            break;
        case 6:
            cout << "Lista samochodow: " << endl;
            pokazSamochody(SamochodTab, iloscSamochodow);
            break;
        case 7:
            usunKlienta(KlientTab, iloscKlientow);
            cout << "Klient usuniety" << endl;
            break;
        case 8:
            usunSamochody(SamochodTab, iloscSamochodow);
            cout << "Samochod usuniety" << endl;
            break;
        case 0:
            dzialanie = wyczyscPamiec(KlientTab, SamochodTab, iloscKlientow, iloscSamochodow);
            break;
        default:
            break;
        }
    }
}
