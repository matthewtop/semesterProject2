#pragma once
#include <string>
using namespace std;

class Silnik {
private:
    int pojemnosc;
    int moc;
public:
    Silnik() : pojemnosc(0), moc(0) {}
    Silnik(int pojemnosc_, int moc_) : pojemnosc(pojemnosc_), moc(moc_) {}

    int getPojemnosc() const {
        return pojemnosc;
    }
    int getMoc() const {
        return moc;
    }
};

class Samochod {
private:
    int id;
    string marka;
    string model;
    Silnik silnik;
public:
    Samochod() : id(0), marka(""), model(""), silnik(Silnik()) {}
    Samochod(int id_, string marka_, string model_, Silnik silnik_) : id(id_), marka(marka_), model(model_), silnik(silnik_) {}


    int getId() const {
        return id;
    }
    void setId(int newId) {
        id = newId;
    }
    string getMarka() const {
        return marka;
    }
    string getModel() const {
        return model;
    }
    Silnik getSilnik() const {
        return silnik;
    }
};

class Klient {
private:
    int id;
    string imie;
    string nazwisko;
    int wiek;
public:
    Klient() : id(0), imie(""), nazwisko(""), wiek(0) {}
    Klient(int id_, string imie_, string nazwisko_, int wiek_) : id(id_), imie(imie_), nazwisko(nazwisko_), wiek(wiek_) {}

    int getId() const {
        return id;
    }
    string getImie() const {
        return imie;
    }
    string getNazwisko() const {
        return nazwisko;
    }
    int getWiek() const {
        return wiek;
    }
    void setId(int newId) {
        id = newId;
    }
    void setImie(string newImie) {
        imie = newImie;
    }
    void setNazwisko(string newNazwisko) {
        nazwisko = newNazwisko;
    }
    void setWiek(int newWiek) {
        wiek = newWiek;
    }
};

class Wypozyczalnia {
public:
    Samochod** samochody;
    Klient* klienci;
    int iloscSamochodow;
    int maxIloscSamochodow;

public:
    Wypozyczalnia() : samochody(nullptr), klienci(nullptr), iloscSamochodow(0), maxIloscSamochodow(0) {}
    Wypozyczalnia(int maxIloscSamochodow_) : samochody(new Samochod* [maxIloscSamochodow_]), klienci(nullptr), iloscSamochodow(0), maxIloscSamochodow(maxIloscSamochodow_) {}

    ~Wypozyczalnia() {
        delete[] samochody;
        delete[] klienci;
    }
};
