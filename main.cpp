#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;

struct Osoba {
    char imie[20];
    char nazwisko[20];
    int wiek;
};

void display(Osoba* osoba, int rozmiar) {
    for (int i = 0; i < rozmiar; i++) {
        cout << i+1 << ". " << osoba[i].imie << " " << osoba[i].nazwisko << " " << osoba[i].wiek << " lat " << "\n";
    }
    cout << "\n";
}

void add(Osoba* &osoba, int &rozmiar) {
    Osoba nowy_element;
    cout << "Podaj imie: ";
    cin >> nowy_element.imie;
    cout << "Podaj nazwisko: ";
    cin >> nowy_element.nazwisko;
    cout << "Podaj wiek: ";
    cin >> nowy_element.wiek;
    Osoba* nowaOsoba = new Osoba[rozmiar+1];
    for (int j = 0; j < rozmiar; j++) {
        nowaOsoba[j] = osoba[j];
    }
    nowaOsoba[rozmiar] = nowy_element;
    delete[] osoba;
    osoba = nowaOsoba;
    rozmiar++;
}

void remove(Osoba* &osoba, int &rozmiar) {
    int nr;
    cout << "Który element usunąć?: ";
    cin >> nr;
    if (nr < 1 || nr > rozmiar) {
        cout << "Nieprawidlowy numer elementu.\n";
    } else {
        Osoba* nowaOsoba = new Osoba[rozmiar-1];
        for (int i = 0; i < nr-1; i++) {
            nowaOsoba[i] = osoba[i];
        }
        for (int i = nr; i < rozmiar; i++) {
            nowaOsoba[i-1] = osoba[i];
        }
        delete[] osoba;
        osoba = nowaOsoba;
        rozmiar--;
    }
}

void atrybuty(Osoba* osoba, int rozmiar) {
    for (int i = 0; i < rozmiar; i++) {
        strcpy(osoba[i].imie, "Jan");
        strcpy(osoba[i].nazwisko, "Kowalski");
        osoba[i].wiek = rand() % 18 + 50;
    }
}

int main() {
    srand(time(NULL));
    Osoba* osoba = NULL;
    int rozmiar = 0;
    int choice;
    do {
        cout << "Wybierz opcje:\n" << "1. Stworz liste.\n" << "2. Wyswietl liste.\n" << "3. Dodaj element.\n" << "4. Usun element.\n" << "5. Losuj atrybuty.\n" << "0. Zakoncz program.\n";
        cin >> choice;
        switch(choice) {
            case 1: {
                rozmiar = rand() % 6 + 15;
                osoba = new Osoba[rozmiar];
                break;
            }
            case 2: {
                display(osoba, rozmiar);
                break;
            }
            case 3: {
                add(osoba, rozmiar);
                break;
            }
            case 4: {
                remove(osoba, rozmiar);
                break;
            }
            case 5: {
                atrybuty(osoba, rozmiar);
                break;
            }
            case 0: {
                break;
            }
            default: {
                cout << "Nieprawidlowa opcja.\n";
                break;
            }
        }
    } while (choice != 0);
    delete[] osoba;
    return 0;
}