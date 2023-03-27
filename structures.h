#pragma once
#ifndef STRUCTURES_H_INCLUDED
#define STRUCTURES_H_INCLUDED
#include <string>
using namespace std;

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

#endif 
