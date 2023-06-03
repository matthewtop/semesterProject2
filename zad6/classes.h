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

class Najem {
private:
	int id;
	string marka;
	string model;
public:
	Najem();
	Najem(int id_, std::string marka_, std::string model_);
	Najem(const Najem& other);
	virtual ~Najem() {}

	virtual string getMarka() const = 0;
	virtual string getModel() const = 0;
	virtual int getId() const = 0;
	virtual int getPojemnosc() const = 0;
	virtual int getMoc() const = 0;
	
};

class Samochod : public Najem {
private:
	int id;
	string marka;
	string model;
	Silnik* silnik;
	Silnik* getSilnik() const;
	

	int getPojemnosc() const;
	int getMoc() const override;

	virtual string getMarka() const override;
	virtual void setId(int newId);
	virtual string getModel() const;

	void setSilnik(Silnik* newSilnik);
	
public:

	friend class SamochodHelper;
	virtual int getId() const;
	Samochod();
	Samochod(int id_, string marka_, string model_, Silnik* silnik_);
	Samochod(const Samochod& other);	
	~Samochod();

	

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
		return os;
	}

};

class Klient : public Najem {
private:
	int id;
	int wiek;
	int dlugoscNajmu;
	string imie;
	string nazwisko;
	
	Samochod* samochod;


public:
	Klient();
	Klient(int id_, string imie_, string nazwisko_, int wiek_);
	~Klient();

	virtual int getId() const override;
	virtual string getMarka() const override;
	virtual string getModel() const override;
	virtual int getPojemnosc() const override;
	virtual int getMoc() const override;
	
	
	int getWiek() const;

	void setImie(const string& newImie);
	void setNazwisko(const string& newNazwisko);
	void setWiek(int newWiek);
	void setId(int newId);
	void setSamochod(Samochod* samochod);
	void setDlugoscNajmu(int dlugosc);
	int getDlugoscNajmu() const;
	
	

	string getImie() const;
	string getNazwisko() const;
	Samochod* getSamochod() const;
};



class Wypozyczalnia {
private:
	Samochod** samochody;
	Klient* klienci;
	
	int iloscSamochodow;
	int maxIloscSamochodow;

public:
	static int liczbaWypozyczonychSamochodow;
	Wypozyczalnia();
	Wypozyczalnia(const Wypozyczalnia& other);
	Wypozyczalnia(int maxIloscSamochodow_);
	~Wypozyczalnia();
	void ustawSamochody(Samochod** noweSamochody);
};

class SamochodHelper {
private:
	 Samochod* samochod;
public:
	SamochodHelper(const Samochod* samochod);
	string getMarka() const;
	string getModel() const;
	int getId() const;
	int getMoc() const;
	int getPojemnosc() const;
	
	//Samochod* getSamochod() const;
	
};
void pokazSamochody(Samochod** samochody, int iloscSamochodow);