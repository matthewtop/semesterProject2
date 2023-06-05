#include "classes.h"



//---------------------S I L N I K --------------------------------//
Silnik::Silnik() : pojemnosc(0), moc(0) {}

Silnik::Silnik(int pojemnosc_, int moc_) : pojemnosc(pojemnosc_), moc(moc_) {}

int Silnik::getPojemnosc() const {
    return pojemnosc;
}

int Silnik::getMoc() const {
    return moc;
}

bool Silnik::operator==(const Silnik& other) const {
    return pojemnosc == other.pojemnosc && moc == other.moc;
}

bool Silnik::operator!=(const Silnik& other) const {
    return !(*this == other);
}

Silnik& Silnik::operator=(const Silnik& other) {
    if (this == &other) {
        return *this;
    }
    pojemnosc = other.pojemnosc;
    moc = other.moc;
    return *this;
}

ostream& operator<<(ostream& os, const Silnik& silnik) {
    os << "Pojemnosc: " << silnik.pojemnosc << endl;
    os << "Moc: " << silnik.moc << endl;
    return os;
}
//---------------------S I L N I K --------------------------------//


//---------------------N A J E M --------------------------------//
Najem::Najem() : id(0), marka(""), model("") {}

Najem::Najem(int id_, std::string marka_, std::string model_) : id(id_), marka(marka_), model(model_) {}

Najem::Najem(const Najem& other) : id(other.id), marka(other.marka), model(other.model) {}


int Najem::getId() const {
    // Implementacja domyślna, zwraca wartość 0
    return 0;
}

string Najem::getMarka() const {
    // Implementacja domyślna, zwraca pusty ciąg znaków
    return "";
}

string Najem::getModel() const {
    // Implementacja domyślna, zwraca pusty ciąg znaków
    return "";
}

int Najem::getPojemnosc() const {
    // Implementacja domyślna, zwraca wartość 0
    return 0;
}

int Najem::getMoc() const {
    // Implementacja domyślna, zwraca wartość 0
    return 0;
}

//---------------------N A J E M --------------------------------//






//---------------------S A M O C H O D --------------------------------//
Samochod::Samochod() : id(0), marka(""), model(""), silnik(nullptr), czyWynajety(false) {}

Samochod::Samochod(int id_, string marka_, string model_, Silnik* silnik_)
    : id(id_), marka(marka_), model(model_), silnik(silnik_), czyWynajety(false) {}

Samochod::Samochod(const Samochod& other)
    : id(other.id), marka(other.marka), model(other.model), czyWynajety(false) {
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
        // Zwróć wartość domyślną lub obsłuż ten przypadek inaczej
        return 0;
    }
}

int Samochod::getMoc() const {
    return silnik->getMoc();
}

bool Samochod::getCzyWynajety() const
{
    return czyWynajety;
}
void Samochod::setCzyWynajety(bool wynajety)
{
    czyWynajety = wynajety;
}


bool Samochod::operator==(const Samochod& other) const {
    return id == other.id && marka == other.marka && model == other.model;
}

bool Samochod::operator!=(const Samochod& other) const {
    return !(*this == other);
}

Samochod& Samochod::operator=(const Samochod& other) {
    if (this == &other) {
        return *this;
    }
    id = other.id;
    marka = other.marka;
    model = other.model;
    delete silnik;
    silnik = new Silnik(*other.silnik);
    return *this;
}

ostream& operator<<(ostream& os, const Samochod& samochod) {
    Samochod::SamochodHelper samochodHelper(&samochod); // Utwórz obiekt SamochodHelper

    os << samochodHelper.getId() << "," << samochodHelper.getMarka() << "," << samochodHelper.getModel()
        << "," << samochodHelper.getPojemnosc() << "," << samochodHelper.getMoc() << endl;
    return os;
}
//---------------------S A M O C H O D --------------------------------//







//---------------------S A M O C H O D  H E L P E R --------------------------------//
Samochod::SamochodHelper::SamochodHelper(const Samochod* samochod) {
    this->samochod = const_cast<Samochod*>(samochod);
}

string Samochod::SamochodHelper::getMarka() const {
    return samochod->getMarka();
}

string Samochod::SamochodHelper::getModel() const {
    return samochod->getModel();
}

int Samochod::SamochodHelper::getId() const {
    return samochod->getId();
}

int Samochod::SamochodHelper::getMoc() const {
    return samochod->getMoc();
}

int Samochod::SamochodHelper::getPojemnosc() const {
    return samochod->getPojemnosc();
}

bool Samochod::SamochodHelper::getCzyWynajety() const
{
    return samochod->getCzyWynajety();
}

void Samochod::SamochodHelper::setCzyWynajety(bool wynajety)
{
    samochod->czyWynajety = wynajety;
}

//---------------------S A M O C H O D  H E L P E R --------------------------------//







//---------------------K L I E N T --------------------------------//
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
    if (samochod != nullptr && samochod != Klient::samochod) {
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
        Samochod::SamochodHelper samochodHelper(samochod);
        return samochodHelper.getMarka();
    }
    else {
        return "";
    }
}

string Klient::getModel() const {
    if (samochod != nullptr) {
        Samochod::SamochodHelper samochodHelper(samochod);
        return samochodHelper.getModel();
    }
    else {
        return "";
    }
}

int Klient::getPojemnosc() const {
    if (samochod != nullptr) {
        Samochod::SamochodHelper samochodHelper(samochod);
        return samochodHelper.getPojemnosc();
    }
    else {
        return 0;
    }
}

int Klient::getMoc() const {
    if (samochod != nullptr) {
        Samochod::SamochodHelper samochodHelper(samochod);
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

Klient::operator Klient* () const {
    return const_cast<Klient*>(this);
}
ostream& operator<<(ostream& os, const Klient& klient) {
    os << setw(3) << klient.getId() << " | " << setw(15) << klient.getImie() << " | " << setw(20) << klient.getNazwisko() << " | " << setw(4) << klient.getWiek() << endl;
    return os;
}
//---------------------K L I E N T --------------------------------//









//---------------------W Y P O Z Y C Z A L N I A --------------------------------//


// konstruktor domyślny
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
        klienci = new Klient[iloscSamochodow];
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

//---------------------W Y P O Z Y C Z A L N I A --------------------------------//



