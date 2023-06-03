#include "functions.h"
#include <cstdlib>
#include <string>
#include <random>
#include <sstream>
#include <algorithm>
#include <fstream> 
#include <iomanip>


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
        if (pos != string::npos) {
            Klient klient;
            klient.setImie(daneKlienta.substr(0, pos));
            size_t prev_pos = pos + 1;
            pos = daneKlienta.find(";", prev_pos);
            if (pos != string::npos) {
                klient.setNazwisko(daneKlienta.substr(prev_pos, pos - prev_pos));
                prev_pos = pos + 1;
                string wiekStr = daneKlienta.substr(prev_pos);
                if (!wiekStr.empty() && wiekStr.find_first_not_of("0123456789") == string::npos) {
                    int wiek = stoi(wiekStr);
                    klient.setWiek(wiek);
                    klient.setId(iloscKlientow + 1);
                    KlientTabTemp[iloscKlientow] = klient;
                    KlientTab = KlientTabTemp;
                    iloscKlientow++;

                    // zapis danych klienta do pliku
                    ofstream plik("klienci.txt", ios::app); // Otwórz plik w trybie do³¹czania danych (append)

                    if (plik.is_open()) {
                        // Zapisz dane klienta w odpowiednim formacie do pliku
                        plik << setw(3) << klient.getId() << " | " << setw(15) << klient.getImie() << " | " << setw(20) << klient.getNazwisko() << " | " << setw(4) << klient.getWiek() << endl;

                        plik.close(); // Zamknij plik
                    }
                    else {
                        cout << "Blad otwarcia pliku." << endl;
                    }
                    return;
                }
            }
        }
        cout << "Nieprawidlowe dane. Klient nie zostal dodany." << endl;
        delete[] KlientTabTemp;
    }
    else {
        cout << "Nie mozna dodac wiccej klientow!" << endl;
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

        static int idCounter = 0;
        Samochod* samochod = new Samochod(idCounter++, marka, model, silnik);

        SamochodTabTemp[iloscSamochodow] = samochod;

        SamochodTab = SamochodTabTemp;
        iloscSamochodow++;

        // Zapisz dane samochodu do pliku
        ofstream plik("samochody.txt", ios::app);

        if (plik.is_open()) {
            SamochodHelper samochodHelper(samochod); // Utwórz obiekt SamochodHelper

            plik << samochodHelper.getId() << "," << samochodHelper.getMarka() << "," << samochodHelper.getModel()
                << "," << samochodHelper.getPojemnosc() << "," << samochodHelper.getMoc() << endl;

            plik.close();
        }
        else {
            cout << "Blad otwarcia pliku." << endl;
        }
    }
    else {
        cout << "Nie mozna dodac wiecej samochodow." << endl;
    }
}



void pokazKlienci(Klient* KlientTab, int iloscKlientow) {
    cout << "+-----+-----------------+----------------------+------+" << endl;
    cout << "| ID  | Imie            | Nazwisko             | Wiek |" << endl;
    cout << "+-----+-----------------+----------------------+------+" << endl;

    for (int i = 0; i < iloscKlientow; i++) {
        cout << "| " << setw(3) << KlientTab[i].getId() << " | " << setw(15) << KlientTab[i].getImie() << " | " << setw(20) << KlientTab[i].getNazwisko() << " | " << setw(4) << KlientTab[i].getWiek() << " |" << endl;
    }

    cout << "+-----+-----------------+----------------------+------+" << endl;
}



void pokazSamochody(Samochod** SamochodTab, int iloscSamochodow) {
    cout << "+-----+------------+-------------------+-----------+--------+" << endl;
    cout << "| ID  |   Marka    |      Model        | Pojemnosc |  Moc   |" << endl;
    cout << "+-----+------------+-------------------+-----------+--------+" << endl;

    int maxModelWidth = 15;

    for (int i = 0; i < iloscSamochodow; i++) {
        SamochodHelper helper(SamochodTab[i]);

        maxModelWidth = max(maxModelWidth, static_cast<int>(helper.getModel().length()));

        cout << "| " << setw(3) << helper.getId() << " | " << setw(10) << helper.getMarka() << " | " << setw(maxModelWidth) << helper.getModel() << " | " << setw(9) << fixed << setprecision(2) << helper.getPojemnosc() << " | " << setw(6) << fixed << setprecision(2) << helper.getMoc() << " |" << endl;
    }

    cout << "+-----+------------+-------------------+-----------+--------+" << endl;
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
        std::cout << "Wprowadz numer samochodu do usuniecia:" << std::endl;
        int id;
        std::cin >> id;
        bool samochodZnaleziony = false;
        for (int i = 0; i < iloscSamochodow; i++) {
            SamochodHelper samochodHelper(SamochodTab[i]);  // Utworzenie obiektu SamochodHelper z samochodu
            if (samochodHelper.getId() == id) {
                delete SamochodTab[i];
                for (int j = i; j < iloscSamochodow - 1; j++) {
                    SamochodTab[j] = SamochodTab[j + 1];
                    // SamochodTab[j]->SamochodHelper.setId(SamochodTab[j]->getId() - 1);
                }
                --iloscSamochodow;
                samochodZnaleziony = true;
                break;
            }
        }
        if (!samochodZnaleziony)
            std::cout << "Nie znaleziono samochodu o podanym numerze ID" << std::endl;
    }
    else
        std::cout << "Brak samochodow" << std::endl;
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
            SamochodHelper samochodHelper1(SamochodTab[j]); // Utwórz obiekt SamochodHelper dla pierwszego samochodu
            SamochodHelper samochodHelper2(SamochodTab[j + 1]); // Utwórz obiekt SamochodHelper dla drugiego samochodu

            if (samochodHelper1.getMoc() > samochodHelper2.getMoc()) {
                Samochod* temp = SamochodTab[j];
                SamochodTab[j] = SamochodTab[j + 1];
                SamochodTab[j + 1] = temp;
            }
        }
    }
    // Wyœwietlenie posortowanej tablicy
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

void wyswietlKlientow() {
    ifstream plik("klienci.txt");
    if (plik.is_open()) {
        cout << plik.rdbuf();
        plik.close();
    }
    else {
        cout << "Nie mozna otworzyc pliku klienci.txt." << endl;
    }
}

void wyswietlSamochody() {
    ifstream plik("samochody.txt");
    if (plik.is_open()) {
        cout << plik.rdbuf();
        plik.close();
    }
}

void wyczyscPliki() {
    ofstream plikKlienci("klienci.txt", ofstream::trunc);
    if (plikKlienci.is_open()) {
        plikKlienci.close();
        cout << "Plik klienci.txt zostal wyczyszczony." << endl;
    }
    else {
        cout << "Nie mozna otworzyc pliku klienci.txt." << endl;
    }

    ofstream plikSamochody("samochody.txt", ofstream::trunc);
    if (plikSamochody.is_open()) {
        plikSamochody.close();
        cout << "Plik samochody.txt zosta³ wyczyszczony." << endl;
    }
    else {
        cout << "Nie mozna otworzyc pliku samochody.txt." << endl;
    }
}

void wynajemSamochodu(Samochod** SamochodTab, Klient* KlientTab, int iloscSamochodow, int iloscKlientow) {
    if (iloscSamochodow == 0 || iloscKlientow == 0) {
        cout << "Brak samochodow lub klientow do wynajecia." << endl;
        return;
    }

    int idKlienta;
    int idSamochodu;
    int dlugoscWynajmu;

    cout << "Podaj ID klienta: ";
    cin >> idKlienta;

    cout << "Podaj ID samochodu: ";
    cin >> idSamochodu;

    cout << "Podaj dlugosc wynajmu w miesiacach: ";
    cin >> dlugoscWynajmu;

    Samochod* samochod = nullptr;
    Klient* klient = nullptr;

    // Find the selected samochod and klient based on their IDs
    for (int i = 0; i < iloscSamochodow; i++) {

        if (SamochodTab[i]->getId() == idSamochodu) {
            samochod = SamochodTab[i];
            break;
        }
    }

    for (int i = 0; i < iloscKlientow; i++) {
        if (KlientTab[i].getId() == idKlienta) {
            klient = &KlientTab[i];
            break;
        }
    }

    if (samochod != nullptr && klient != nullptr) {
        if (klient->getSamochod() == nullptr) {
            SamochodHelper samochodHelper(samochod);
            klient->setSamochod(samochod);
            klient->setDlugoscNajmu(dlugoscWynajmu);
            cout << "Samochod o ID " << samochodHelper.getId() << " zostal wynajety klientowi o ID " << klient->getId() << " na okres " << dlugoscWynajmu << " miesiecy." << endl;
        }
        else {
            cout << "Klient o ID " << klient->getId() << " ma juz wynajety samochod." << endl;
        }
    }
    else {
        cout << "Nie znaleziono samochodu lub klienta o podanym ID." << endl;
    }
}
void wyswietlNajem(Klient* KlientTab, int iloscKlientow) {
    cout << "+-----------------+----------------------+-----------------+-----------------+---------------+" << endl;
    cout << "| Imie            | Nazwisko             | Marka           | Model           | Dlugosc najmu |" << endl;
    cout << "+-----------------+----------------------+-----------------+-----------------+---------------+" << endl;

    for (int i = 0; i < iloscKlientow; i++) {
        Klient klient = KlientTab[i];

        Samochod* wynajetySamochod = klient.getSamochod();
        if (wynajetySamochod != nullptr) {
            SamochodHelper samochodHelper(wynajetySamochod); // Utwórz obiekt SamochodHelper
            cout << "| " << setw(15) << klient.getImie() << " | " << setw(20) << klient.getNazwisko() << " | ";
            cout << setw(15) << samochodHelper.getMarka() << " | " << setw(15) << samochodHelper.getModel() << " | ";
            cout << left << setw(5) << klient.getDlugoscNajmu() << "miesiac";
            if (klient.getDlugoscNajmu() > 1) {
                cout << "e";
            }
            cout << " |" << endl;
        }
    }

    cout << "+-----------------+----------------------+-----------------+-----------------+---------------+" << endl;
}