#pragma once
#ifndef STRUCTURES_H_INCLUDED
#define STRUCTURES_H_INCLUDED
#include <string>
using namespace std;

struct Silnik {
    int pojemnosc;
    int moc;
};

struct Samochod {
    int id;
    string marka;
    string model;
    Silnik silnik;   // agregacja silnika w samochodzie
};

struct Klient {
    int id;
    string imie;
    string nazwisko;
    int wiek;

};

struct Wypozyczalnia {
    Samochod** samochody;
    Klient* klienci;
};



#endif 
