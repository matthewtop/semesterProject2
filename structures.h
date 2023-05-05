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
    Silnik* silnik;
public:
    Samochod() : id(0), marka(""), model(""), silnik(nullptr) {}
    Samochod(int id_, string marka_, string model_, Silnik* silnik_) : id(id_), marka(marka_), model(model_), silnik(new Silnik(*silnik_)) {}

    // konstruktor kopiujący
    Samochod(const Samochod& other) : id(other.id), marka(other.marka), model(other.model), silnik(new Silnik(*(other.silnik))) {}

    // operator przypisania
    Samochod& operator=(const Samochod& other) {
        if (this != &other) {
            id = other.id;
            marka = other.marka;
            model = other.model;
            delete silnik;
            silnik = new Silnik(*(other.silnik));
        }
        return *this;
    }

    ~Samochod() {
        delete silnik;
    }

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
    Silnik* getSilnik() const {
        return silnik;
    }
};

class Klient {
private:
    int id;
    string imie;
    string nazwisko;
    int wiek;
    Samochod* samochod; // dodane pole

public:
    Klient() : id(0), imie(""), nazwisko(""), wiek(0), samochod(nullptr) {}
    Klient(int id_, string imie_, string nazwisko_, int wiek_) : id(id_), imie(imie_), nazwisko(nazwisko_), wiek(wiek_), samochod(nullptr) {}

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

    void setSamochod(Samochod* samochod) { // nowa metoda
        this->samochod = samochod;
    }
    

    Samochod* getSamochod() const {
        return samochod;
    }
};


class KlientSamochod {
private:
    Klient* klient;
    Samochod* samochod;
public:
    KlientSamochod(Klient* klient_, Samochod* samochod_) : klient(klient_), samochod(samochod_) {}

    Klient* getKlient() const {
        return klient;
    }
    Samochod* getSamochod() const {
        return samochod;
    }
};

class Wypozyczalnia {
public:
    Samochod** samochody;
    Klient* klienci;
    KlientSamochod* klientSamochod;
    int iloscSamochodow;
    int maxIloscSamochodow;

public:
    Wypozyczalnia() : samochody(nullptr), klienci(nullptr), klientSamochod(nullptr), iloscSamochodow(0), maxIloscSamochodow(0) {}
    Wypozyczalnia(int maxIloscSamochodow_) : samochody(new Samochod* [maxIloscSamochodow_]), klienci(nullptr), klientSamochod(nullptr), iloscSamochodow(0), maxIloscSamochodow(maxIloscSamochodow_) {}

    ~Wypozyczalnia() {
        delete[] samochody;
        delete[] klienci;
        delete klientSamochod;
    }

    friend class KlientSamochod;
};
