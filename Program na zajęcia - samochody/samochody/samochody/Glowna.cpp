#include "Header.h" 
#include <iostream>
#include <fstream>

int main(void)
{

	using SAMOCHOD::samochod;
	ifstream plik;
	int number, wybor = 0; // zmienna int (nie mia³em jej wczeœniej a by³a jakaœ potrzebna)
	samochod tab[maks]; // tablica samochodów
	plik.open("samochody.txt");
	if (!wczytanie_pliku(plik, number, tab)) //otwarcie pliku, sprawdzenie czy plik istnieje
	{
		plik.close();
		return(0);
	}
	plik.close();
	for (;;)//nieskoñczona pêtla, która bêdzie wyœwietla³a menu po zakoñczeniu operacji w funkcji
	{

		while (wybor != 1)
		{
			menu(); // wyswietlenie menu
			cout << endl << "Twoj wybor: ";
			cin >> wybor;
			cout << endl;
			system("cls");
			switch (wybor) //w³¹czenie danej funcji w zale¿noœci od wyboru
			{
			case 0:
				cout << "Do zobaczenia" << endl;
				return(0);
				break;
			case 1:
				menu();
				break;
			case 2:
				pokaz_samochod(tab, number);
				break;
			case 3:
				dodaj_samochod(tab, number);
				break;
			case 4:
				cout << "Podaj numer samochodu do usuniecia: ";
				cin >> wybor;
				usun_samochod(tab, number, wybor);
				break;
			case 5:
				cout << "Podaj numer samochodu do wyswietlenia: ";
				cin >> wybor;
				cout << endl << endl;
				pokaz_samochod(tab, number, wybor);
				break;
			case 6:
				cout << "Sortowanie wedlug: 1.przebiegu, 2.pojemnosci, 3.rocznika" << endl;
				cout << "Podaj swoj wybor: ";
				cin >> wybor;
				sortuj_samochod(tab, number, wybor);
				cout << "\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315" << endl;
				pokaz_samochod(tab, number);
				break;
			case 7:
				cout << "Wyswietlanie wzgledem danej kategorii: 1.przebiegu, 2.pojemnosci, 3.rocznika" << endl;
				cout << "Podaj swoj wybor: ";
				cin >> wybor;
				cout << "Podaj minimalna wartosc wedlug ktrej nastapi wyswietlanie ";
				int prog;
				cin >> prog;
				wyswietl_samochod_z_parametrem(tab, number, wybor, prog);
				system("PAUSE");
				system("cls");
				break;
			case 8:
				zapis(tab, number);
				break;
			default:
				cout << "Brak podanej opcji" << endl;
			}
			if (cin.fail()) // jesli blad wybranej opcji i zepsucie strumienia
				czysc(); // czyszczenie strumienia
			wybor = 0; // zresetowanie wyboru
		}
		return (0);
	}
}