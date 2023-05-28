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
	Samochod& operator=(const Samochod& other);
	~Samochod();
	
	Silnik* getSilnik() const;
	void setSilnik(Silnik* newSilnik);
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
	const Samochod* samochod;
public:
	SamochodHelper(const Samochod* samochod);
	int getId() const;
	string getMarka() const;
	string getModel() const;
	int getMoc() const;
	int getPojemnosc() const;
};

// Funkcje
void pokazSamochody(Samochod** samochody, int iloscSamochodow); 
