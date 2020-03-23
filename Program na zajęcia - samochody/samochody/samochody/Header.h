#ifndef SAMOCHOD_H
#define SAMOCHOD_H
#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <windows.h>

using namespace std;
const int maks = 1000; // ile max samochodów mo¿ê byæ



namespace SAMOCHOD 
{
	class samochod 
	{
	private:
		string marka;
		string model;
		int rocznik;
		int pojemnosc;
		int przebieg;
		bool skrzynia;
	public:
		samochod(const string & mar = "Brak", const string & mod = "Brak", const int & r = 0, const int & poj = 0, const int & p = 0, const bool & s = 1); 
		const string & get_marka(void)const { return(marka); } // zwrócenie marki
		const string & get_model(void)const { return(model); } // itd...
		const int & get_rocznik(void)const { return(rocznik); } 
		const int & get_pojemnosc(void)const { return(pojemnosc); } 
		const int & get_przebieg(void)const { return(przebieg); } 
		const bool & get_skrzynia(void)const { return(skrzynia); } 
	};
	ostream & operator << (ostream & o, const samochod & c); // funkcja przeciazajaca operator << 
	istream & operator >> (istream & i, samochod & c); // funkcja przeciazajaca operator >> 
}

bool wczytanie_pliku(std::ifstream & plik, int & n, SAMOCHOD::samochod tab[]); 
void menu(void); 
void czysc(void); // czyszczenie strumienia
void usun_samochod(SAMOCHOD::samochod tab[], int & number, const int & n); 
void dodaj_samochod(SAMOCHOD::samochod tab[], int & number); 
void pokaz_samochod(const SAMOCHOD::samochod tab[], const int & number, const int & n = 0); 
void sortuj_samochod(SAMOCHOD::samochod tab[], const int & number, const int & n); 
void wyswietl_samochod_z_parametrem(const SAMOCHOD::samochod tab[], const int & number, const int & wybor, const int & prog); 
void zapis(const SAMOCHOD::samochod tab[], const int & n); 

#endif // SAMOCHOD_H