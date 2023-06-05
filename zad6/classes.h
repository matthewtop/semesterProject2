#pragma once
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

extern int global_int;

//---------------------S I L N I K --------------------------------//
class Silnik {
private:
	int pojemnosc;
	int moc;
public:
	Silnik();
	Silnik(int pojemnosc_, int moc_);
	int getPojemnosc() const;
	int getMoc() const;
	
	// Przeciążenie operatorów porównania
	bool operator==(const Silnik& other) const;
	bool operator!=(const Silnik& other) const;

	// Przeciążenie operatora przypisania
	Silnik& operator=(const Silnik& other);

	// Przeciążenie operatora strumienia
	friend ostream& operator<<(ostream& os, const Silnik& silnik);

};
//---------------------S I L N I K --------------------------------//








//---------------------N A J E M --------------------------------//
class Najem {
protected:
	int id;
	string marka;
	string model;
public:
	Najem();
	Najem(int id_, std::string marka_, std::string model_);
	Najem(const Najem& other); //konstruktor kopiujacy
	virtual ~Najem() {}
	//metody wirtualne, settery,gettery
	virtual string getMarka() const = 0;
	virtual string getModel() const = 0;
	virtual int getId() const = 0;
	virtual int getPojemnosc() const = 0;
	virtual int getMoc() const = 0;
	
};
//---------------------N A J E M --------------------------------//







//---------------------S A M O C H O D --------------------------------//
class Samochod : public Najem {
private:
	int id;
	string marka;
	string model;
	Silnik* silnik;
	Silnik* getSilnik() const;
	
	bool czyWynajety;

	int getPojemnosc() const;
	int getMoc() const override;

	virtual string getMarka() const override;
	virtual void setId(int newId);
	virtual string getModel() const;
	
	void setCzyWynajety(bool wynajety);

	void setSilnik(Silnik* newSilnik);

	
	
public:
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
		bool getCzyWynajety() const;
		void setCzyWynajety(bool wynajety);
		int getDlugoscNajmu() const;  
	};

	friend class SamochodHelper;
	virtual int getId() const;
	bool getCzyWynajety() const;
	Samochod();
	Samochod(int id_, string marka_, string model_, Silnik* silnik_);
	Samochod(const Samochod& other);	
	~Samochod();

	

	bool operator==(const Samochod& other) const;
	bool operator!=(const Samochod& other) const;
	Samochod& operator=(const Samochod& other);
	friend ostream& operator<<(ostream& os, const Samochod& samochod);

};
//---------------------S A M O C H O D --------------------------------//










//---------------------K L I E N T --------------------------------//
class Klient : public Najem {
private:
	int id;
	int wiek;
	int dlugoscNajmu;
	string imie;
	string nazwisko;	
	Samochod* samochod;

public:

	friend ostream& operator<<(ostream& os, const Klient& klient);
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
	
	operator Klient* () const;

	string getImie() const;
	string getNazwisko() const;
	Samochod* getSamochod() const;
};
//---------------------K L I E N T --------------------------------//











//---------------------W Y P O Z Y C Z A L N I A --------------------------------//
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
//---------------------W Y P O Z Y C Z A L N I A --------------------------------//
