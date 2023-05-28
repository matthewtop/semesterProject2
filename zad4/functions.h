#pragma once
#include<iostream>
#include<string>
#include "classes.h"
extern int global_int;
using namespace std;
void dodajKlienta(Klient*& KlientTab, int& iloscKlientow, int maxIloscKlientow);
void dodajSamochod(Samochod**& SamochodTab, int& iloscSamochodow, int maxIloscSamochodow);
void pokazKlienci(Klient* KlientTab, int iloscKlientow);
void pokazSamochody(Samochod** SamochodTab, int iloscSamochodow);
void usunKlienta(Klient*& KlientTab, int& iloscKlientow);
void usunSamochod(Samochod**& SamochodTab, int& iloscSamochodow);
void zakonczProgram(Klient*& KlientTab, Samochod**& SamochodTab, int iloscKlientow, int iloscSamochodow);
void sortujSamochodyWzgledemMocy(Samochod**& SamochodTab, int& iloscSamochodow);
void sortujKlientowRosnaco(Klient*& klientTab, int liczbaKlientow);
