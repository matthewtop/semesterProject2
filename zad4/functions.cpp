#include "functions.h"
#include <cstdlib>
#include <string>
#include <random>
#include <sstream>
#include <algorithm>

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
        int moc = stoi(daneSamochodu.substr(prev_pos));

        Silnik* silnik = new Silnik(pojemnosc, moc);
        Samochod* samochod = new Samochod(iloscSamochodow + 1, marka, model, silnik);
        SamochodTabTemp[iloscSamochodow] = samochod;

        SamochodTab = SamochodTabTemp;
        iloscSamochodow++;
    }
    else {
        cout << "Nie mozna dodac wiecej samochodow." << endl;
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
            cout << samochody[i]->getId() << ". Samochod: " << samochody[i]->getMarka() << " " << samochody[i]->getModel()
                << "\nMoc: " << samochody[i]->getSilnik()->getMoc() << " KM"
                << "\nPojemnosc silnika: " << samochody[i]->getSilnik()->getPojemnosc() << " cm^3" << endl << endl;
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
                for (int j = i; j < iloscKlientow - 1; j++) {
                    KlientTab[j] = KlientTab[j + 1];
                    KlientTab[j].setId(KlientTab[j].getId() - 1);
                }
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
            if (SamochodTab[j]->getSilnik()->getMoc() > SamochodTab[j + 1]->getSilnik()->getMoc()) {
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


void przypiszSamochodDoKlienta(Klient* KlientTab, int iloscKlientow, Samochod** SamochodTab, int iloscSamochodow) {
    int klientId, samochodId;
    bool klientZnaleziony = false, samochodZnaleziony = false;
    cout << "Podaj id klienta: ";
    cin >> klientId;
    cout << "Podaj id samochodu: ";
    cin >> samochodId;
    for (int i = 0; i < iloscKlientow; i++) {
        if (KlientTab[i].getId() == klientId) {
            klientZnaleziony = true;
            for (int j = 0; j < iloscSamochodow; j++) {
                if (SamochodTab[j]->getId() == samochodId) {
                    samochodZnaleziony = true;
                    KlientTab[i].setSamochod(SamochodTab[j]); // ustawienie samochodu dla klienta
                    cout << "Samochod przypisany do klienta." << endl;
                    break;
                }
            }
            if (!samochodZnaleziony) {
                cout << "Nie znaleziono samochodu o podanym id." << endl;
            }
            break;
        }
    }
    if (!klientZnaleziony) {
        cout << "Nie znaleziono klienta o podanym id." << endl;
    }
}

void wyswietlKlientowSamochody(Klient* KlientTab, int iloscKlientow) {
    for (int i = 0; i < iloscKlientow; i++) {
        cout << "Klient " << KlientTab[i].getId() << ": " << KlientTab[i].getImie() << " " << KlientTab[i].getNazwisko() << endl;
        if (KlientTab[i].getSamochod() != nullptr) {
            cout << "\tSamochod " << KlientTab[i].getSamochod()->getId() << ": " << KlientTab[i].getSamochod()->getMarka() << " " << KlientTab[i].getSamochod()->getModel() << endl;
        }
    }
}
