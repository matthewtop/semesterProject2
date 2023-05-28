#include "classes.h"
// Implementacja klasy Silnik


Silnik::Silnik() : pojemnosc(0), moc(0) {}

Silnik::Silnik(int pojemnosc_, int moc_) : pojemnosc(pojemnosc_), moc(moc_) {}

int Silnik::getPojemnosc() const {
    return pojemnosc;
}

int Silnik::getMoc() const {
    return moc;
}

// Implementacja klasy Samochod
Samochod::Samochod() : id(0), marka(""), model(""), silnik(nullptr) {}

Samochod::Samochod(int id_, string marka_, string model_, Silnik* silnik_)
    : id(id_), marka(marka_), model(model_), silnik(silnik_) {}

Samochod::Samochod(const Samochod& other)
    : id(other.id), marka(other.marka), model(other.model) {
    if (other.silnik != nullptr) {
        silnik = new Silnik(*other.silnik);
    }
    else {
        silnik = nullptr;
    }
}

Samochod& Samochod::operator=(const Samochod& other) {
    if (this != &other) {
        id = other.id;
        marka = other.marka;
        model = other.model;
        delete silnik;
        if (other.silnik != nullptr) {
            silnik = new Silnik(*other.silnik);
        }
        else {
            silnik = nullptr;
        }
    }
    return *this;
}

Samochod::~Samochod() {
    delete silnik;
}


int Samochod::getId() const {
    return id;
}

void Samochod::setId(int newId) {
    id = newId;
}

string Samochod::getMarka() const {
    return marka;
}

string Samochod::getModel() const {
    return model;
}

Silnik* Samochod::getSilnik() const {
    return silnik;
}

void Samochod::setSilnik(Silnik* newSilnik) {
    delete Samochod::silnik;
    Samochod::silnik = newSilnik;
}

// Implementacja klasy Klient
Klient::Klient() : id(0), imie(""), nazwisko(""), wiek(0), samochod(nullptr) {}

Klient::Klient(int id_, string imie_, string nazwisko_, int wiek_)
    : id(id_), imie(imie_), nazwisko(nazwisko_), wiek(wiek_), samochod(nullptr) {}

int Klient::getId() const {
    return id;
}

string Klient::getImie() const {
    return imie;
}

string Klient::getNazwisko() const {
    return nazwisko;
}

int Klient::getWiek() const {
    return wiek;
}

void Klient::setId(int newId) {
    id = newId;
}

void Klient::setImie(string newImie) {
    imie = newImie;
}

void Klient::setNazwisko(string newNazwisko) {
    nazwisko = newNazwisko;
}

void Klient::setWiek(int newWiek) {
    wiek = newWiek;
}

Samochod* Klient::getSamochod() const {
    return samochod;
}

void Klient::setSamochod(Samochod* samochod) {
    delete this->samochod;
    this->samochod = samochod;
}

// Implementacja klasy Wypozyczalnia

// Konstruktor domyślny.
Wypozyczalnia::Wypozyczalnia() : samochody(nullptr), klienci(nullptr),iloscSamochodow(0), maxIloscSamochodow(0) {}

//konstruktor kopiujacy
Wypozyczalnia::Wypozyczalnia(const Wypozyczalnia& other) :
    iloscSamochodow(other.iloscSamochodow),
    maxIloscSamochodow(other.maxIloscSamochodow)
{
    if (other.samochody != nullptr) {
        samochody = new Samochod * [maxIloscSamochodow];
        for (int i = 0; i < iloscSamochodow; i++) {
            samochody[i] = new Samochod(*other.samochody[i]);
        }
    }
    else {
        samochody = nullptr;
    }

    if (other.klienci != nullptr) {
        klienci = new Klient[maxIloscSamochodow];
        for (int i = 0; i < maxIloscSamochodow; i++) {
            klienci[i] = other.klienci[i];
        }
    }
    else {
        klienci = nullptr;
    }
}
void Wypozyczalnia::ustawSamochody(Samochod** noweSamochody) {
    samochody = noweSamochody;
}

Wypozyczalnia::Wypozyczalnia(int maxIloscSamochodow_)
    : samochody(new Samochod* [maxIloscSamochodow_]),
    klienci(nullptr),
    //klientSamochod(nullptr),
    iloscSamochodow(0),
    maxIloscSamochodow(maxIloscSamochodow_) {}
Wypozyczalnia::~Wypozyczalnia() {
    for (int i = 0; i < iloscSamochodow; i++) {
        delete samochody[i];
    }
    delete[] samochody;
    delete[] klienci;
   // delete[] klientSamochod;
}

SamochodHelper::SamochodHelper(const Samochod* samochod) : samochod(samochod) {}

int SamochodHelper::getId() const {
    return samochod->getId();
}

string SamochodHelper::getMarka() const {
    return samochod->getMarka();
}

string SamochodHelper::getModel() const {
    return samochod->getModel();
}

int SamochodHelper::getMoc() const {
    return samochod->getSilnik()->getMoc();
}

int SamochodHelper::getPojemnosc() const {
    return samochod->getSilnik()->getPojemnosc();
}
