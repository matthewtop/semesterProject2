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


//Implementacja klasy Najem
Najem::Najem() : id(0), marka(""), model("") {}

Najem::Najem(int id_, std::string marka_, std::string model_) : id(id_), marka(marka_), model(model_) {}

Najem::Najem(const Najem& other) : id(other.id), marka(other.marka), model(other.model) {}


int Najem::getId() const {
    // Implementacja domyœlna, zwraca wartoœæ 0
    return 0;
}

string Najem::getMarka() const {
    // Implementacja domyœlna, zwraca pusty ci¹g znaków
    return "";
}

string Najem::getModel() const {
    // Implementacja domyœlna, zwraca pusty ci¹g znaków
    return "";
}

int Najem::getPojemnosc() const {
    // Implementacja domyœlna, zwraca wartoœæ 0
    return 0;
}

int Najem::getMoc() const {
    // Implementacja domyœlna, zwraca wartoœæ 0
    return 0;
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
    silnik = newSilnik;
}

int Samochod::getPojemnosc() const {
    if (silnik != nullptr) {
        return silnik->getPojemnosc();
    }
    else {
        // Zwróæ wartoœæ domyœln¹ lub obs³u¿ ten przypadek inaczej
        return 0;
    }
}

int Samochod::getMoc() const {
    return silnik->getMoc();
}

// Implementacja klasy Klient

Klient::Klient()
    : samochod(nullptr)
{
    id = 0;
    wiek = 0;
    dlugoscNajmu = 0;
}
Klient::Klient(int id_, string imie_, string nazwisko_, int wiek_) {
    id = id_;
    imie = imie_;
    nazwisko = nazwisko_;
    wiek = wiek_;
    samochod = nullptr;
}

Klient::~Klient() {
    if (samochod != nullptr) {
        delete samochod;
    }
}
int Klient::getId() const {
    return id;
}

string Klient::getImie() const {
    return imie;
}

string Klient::getNazwisko() const {
    return nazwisko;
}

string Klient::getMarka() const {
    if (samochod != nullptr) {
        SamochodHelper samochodHelper(samochod);
        return samochodHelper.getMarka();
    }
    else {
        return "";
    }
}

string Klient::getModel() const {
    if (samochod != nullptr) {
        SamochodHelper samochodHelper(samochod);
        return samochodHelper.getModel();
    }
    else {
        return "";
    }
}

int Klient::getPojemnosc() const {
    if (samochod != nullptr) {
        SamochodHelper samochodHelper(samochod);
        return samochodHelper.getPojemnosc();
    }
    else {
        return 0;
    }
}

int Klient::getMoc() const {
    if (samochod != nullptr) {
        SamochodHelper samochodHelper(samochod);
        return samochodHelper.getMoc();
    }
    else {
        return 0;
    }
}

int Klient::getDlugoscNajmu() const {
    return dlugoscNajmu;
}
Samochod* Klient::getSamochod() const {
    return samochod;
}

void Klient::setImie(const string& newImie) {
    imie = newImie;
}

void Klient::setNazwisko(const string& newNazwisko) {
    nazwisko = newNazwisko;
}

void Klient::setWiek(int newWiek) {
    wiek = newWiek;
}

void Klient::setId(int newId) {
    id = newId;
}
int Klient::getWiek() const {
    return wiek;
}

void Klient::setSamochod(Samochod* samochod) {
    delete this->samochod;
    this->samochod = samochod;
}

void Klient::setDlugoscNajmu(int dlugosc) {
    dlugoscNajmu = dlugosc;
}

// Implementacja klasy Wypozyczalnia

// konstruktor domyœlny
Wypozyczalnia::Wypozyczalnia() : samochody(nullptr), klienci(nullptr), iloscSamochodow(0), maxIloscSamochodow(0) {}

Wypozyczalnia::Wypozyczalnia(const Wypozyczalnia& other)
    : iloscSamochodow(other.iloscSamochodow), maxIloscSamochodow(other.maxIloscSamochodow) {
    if (other.samochody != nullptr) {
        samochody = new Samochod * [maxIloscSamochodow];
        for (int i = 0; i < maxIloscSamochodow; i++) {
            samochody[i] = new Samochod(*other.samochody[i]);
        }
    }
    else {
        samochody = nullptr;
    }

    if (other.klienci != nullptr) {
        klienci = new Klient[maxIloscSamochodow];
        for (int i = 0; i < iloscSamochodow; i++) {
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
    iloscSamochodow(0),
    maxIloscSamochodow(maxIloscSamochodow_) {}
Wypozyczalnia::~Wypozyczalnia() {
    for (int i = 0; i < iloscSamochodow; i++) {
        delete samochody[i];
    }
    delete[] samochody;
    delete[] klienci;
}


SamochodHelper::SamochodHelper(const Samochod* samochod) {
    this->samochod = const_cast<Samochod*>(samochod);
}


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
/*
Samochod* SamochodHelper::getSamochod() const
{
    return samochod;
}*/


