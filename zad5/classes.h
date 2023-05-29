#pragma once
#include <string>
#include <iostream>
using namespace std;

extern int global_int;

class Silnik {
private:
	int pojemnosc;
	int moc;
public:
	Silnik();
	Silnik(int pojemnosc_, int moc_);
	int getPojemnosc() const;
	int getMoc() const;



	bool operator==(const Silnik& other) const {
		return pojemnosc == other.pojemnosc && moc == other.moc;
	}

	bool operator!=(const Silnik& other) const {
		return !(*this == other);
	}

	Silnik& operator=(const Silnik& other) {
		if (this == &other) {
			return *this;
		}
		pojemnosc = other.pojemnosc;
		moc = other.moc;
		return *this;
	}

	friend ostream& operator<<(ostream& os, const Silnik& silnik) {
		os << "Pojemnosc: " << silnik.pojemnosc << endl;
		os << "Moc: " << silnik.moc << endl;
		return os;
	}

};

class Samochod {
private:
	int id;
	string marka;
	string model;
	Silnik* silnik;
	int getId() const;
	void setId(int newId);
	string getMarka() const;
	string getModel() const;
public:

	friend class SamochodHelper;
	Samochod();
	Samochod(int id_, string marka_, string model_, Silnik* silnik_);
	Samochod(const Samochod& other);
	//Samochod& operator=(const Samochod& other);
	~Samochod();

	Silnik* getSilnik() const;
	void setSilnik(Silnik* newSilnik);

	bool operator==(const Samochod& other) const {
		return id == other.id && marka == other.marka && model == other.model;
	}

	bool operator!=(const Samochod& other) const {
		return !(*this == other);
	}

	Samochod& operator=(const Samochod& other) {
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

	friend ostream& operator<<(ostream& os, const Samochod& samochod) {
		os << "ID: " << samochod.id << endl;
		os << "Marka: " << samochod.marka << endl;
		os << "Model: " << samochod.model << endl;
		//os << "Silnik: " << *samochod.silnik << endl;
		return os;
	}

};

class Klient {
private:
	int id;
	string imie;
	string nazwisko;
	int wiek;
	Samochod* samochod;

public:
	Klient();
	Klient(int id_, string imie_, string nazwisko_, int wiek_);
	int getId() const;
	string getImie() const;
	string getNazwisko() const;
	int getWiek() const;
	void setId(int newId);
	void setImie(string newImie);
	void setNazwisko(string newNazwisko);
	void setWiek(int newWiek);

	void setSamochod(Samochod* samochod);
	Samochod* getSamochod() const;
};



class Wypozyczalnia {
private:
	Samochod** samochody;
	Klient* klienci;
	//KlientSamochod* klientSamochod;
	int iloscSamochodow;
	int maxIloscSamochodow;

public:
	Wypozyczalnia();
	Wypozyczalnia(const Wypozyczalnia& other);
	Wypozyczalnia(int maxIloscSamochodow_);
	~Wypozyczalnia();
	void ustawSamochody(Samochod** noweSamochody);

	//friend class KlientSamochod;
};

class SamochodHelper {
private:
	 Samochod* samochod;
public:
	SamochodHelper(const Samochod* samochod);
	int getId() const;
	string getMarka() const;
	string getModel() const;
	int getMoc() const;
	int getPojemnosc() const;
	//const Samochod* getSamochod() const;
	Samochod* getSamochod() const;
	
};
void pokazSamochody(Samochod** samochody, int iloscSamochodow);
