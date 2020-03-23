#include "Header.h" 

namespace SAMOCHOD
{
	// Konstruktor 

	samochod::samochod(const string & mar, const string & mod, const int & r, const int & poj, const int & p, const bool & s)
	{
		marka = mar;
		model = mod;
		rocznik = r;
		pojemnosc = poj;
		przebieg = p;
		skrzynia = s;
	}

	// Funkcja przeciazajaca operator <<  

	ostream & operator << (ostream & o, const samochod & c)
	{
		o << "Marka:     " << c.get_marka() << endl;
		o << "Model:     " << c.get_model() << endl;
		o << "Rocznik:   " << c.get_rocznik() << endl;
		o << "Pojemnosc: " << c.get_pojemnosc() << endl;
		o << "Przebieg:  " << c.get_przebieg() << endl;
		o << "Skrzynia:  ";
		if (c.get_skrzynia())  //prze¿ucanie wartoœci na typ bool(z podanego rodzanu skrzynii biegów)
			o << "manualna";
		else
			o << "automatyczna";
		cout << endl;
		return(o);
	}

	/// Funkcja przeciazajaca operator >> 

	istream& operator >> (istream& i, samochod& c)
	{
		string marka, model;
		int przebieg, rocznik, pojemnosc;
		short skrzynia;
		i >> marka;
		i >> model;
		i >> rocznik;
		i >> pojemnosc;
		i >> przebieg;
		i >> skrzynia;
		c = samochod(marka, model, rocznik, pojemnosc, przebieg, skrzynia); // stworzenie obiektu "samochod" z odpowiednimi atryburtami
		return(i);
	}
}

bool wczytanie_pliku(std::ifstream& plik, int& n, SAMOCHOD::samochod tab[])
{
	if (!plik.is_open())
	{
		cout << "Nie znaleziono pliku" << endl;
		return(false);
	}
	plik >> n; // wczytanie ilosci aut 
	if (n > maks)
	{
		cout << "Zbyt duza liczba samochodow na liscie" << endl;
		return(false);
	}
	for (int i = 0; i < n; ++i)
		plik >> tab[i];
	return(true);
}



void menu(void)
{
	HANDLE hOut;
	cout << "\311\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\273" << endl;
	//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_RED);//chcia³em ¿eby napis menu g³ówne by³o fioletowe ale coœ mi nie wysz³o, zostawiam to bo mo¿e uda mi siê jeszcze to zrobiæ
	cout << "\271            MENU GLOWNE              \272" << endl;
	cout << "\314\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\271" << endl;
	cout << "\2721. Wyswietl menu programu            \272" << endl;
	cout << "\2722. Wyswietl cala liste               \272" << endl;
	cout << "\2723. Dodanie nowego samochodu          \272" << endl;
	cout << "\2724. Usuniecie samochodu               \272" << endl;
	cout << "\2725. Pokaz wybrany samochod            \272" << endl;
	cout << "\2726. Sortuj                            \272" << endl;
	cout << "\2727. Wyswietl wedlug zadanej kategorii \272" << endl;
	cout << "\2728. Zapisz liste                      \272" << endl;
	cout << "\2720. Wyjscie z programu                \272" << endl;
	cout << "\310\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\274" << endl;
}

// Funkcja czyszcz¹ca strumieñ

void czysc(void)
{
	std::cin.clear();
	std::cin.ignore(10000, '\n');
}



void usun_samochod(SAMOCHOD::samochod tab[], int & number, const int & n)
{
	if (n <= number)
	{
		tab[n - 1] = SAMOCHOD::samochod(); // wyzerowanie atrybutów samochodu 
		for (int i = n - 1; i < number; ++i) // zaktualizowanie bazy
			tab[i] = tab[i + 1];
		number--; //usuniêcie samochodu
	}
	else
	{ 
	cout << "blad! Brak samochodu na liscie!" << std::endl;
	}
	cout << "Samochod usunieto pomyslnie!" << endl << endl;

	system("PAUSE");
	system("cls");
}

void dodaj_samochod(SAMOCHOD::samochod tab[], int& number)
{
	if (number < maks) 
	{
		cout << "Schemat: " << endl; 
		cout << "1. Marka" << endl;
		cout << "2. Model" << endl;
		cout << "3. Rocznik" << endl;
		cout << "4. Pojemnosc silnika" << endl;
		cout << "5. Przebieg" << endl;
		cout << "6. Typ skrzynii biegow (0. automatyczna, 1. manualna)" << endl << endl;
		cout << "\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261\261" << endl << endl;
		cout << "Podaj dane:"<<endl;
		cin >> tab[number]; //tu jest prezci¹¿ony operator
		number++; 
	}
	else
		cout << "Baza jest pe³na samochodów, musisz cos z niej usunac, zanim dodasz kolejny samochod!" << endl;

	cout << "Samochod dodano poyslnie (aby dodac go do pliku zapisz zmiany wybierajac opcje nr 8 w meu glownym)!" << endl << endl;

	system("PAUSE");
	system("cls");
}

void pokaz_samochod(const SAMOCHOD::samochod tab[], const int & number, const int & n)
{
	if (n == 0) 
	{
		for (int n = 0; n < number; ++n)
			cout << "Samochod numer " << n + 1 << ":\n" << tab[n] << endl << endl;
	}
	else 
		cout << "Samochod numer: " << n << ":\n" << tab[n - 1] << endl << endl;
	system("PAUSE");
	system("cls");
}

void sortuj_samochod(SAMOCHOD::samochod tab[], const int & number, const int & n) // ta funkcja sortuje samochody po wybranym kryterium (sortowanie bombelkowe polecone na zajêciach)
{
	SAMOCHOD::samochod pom = tab[0]; 
	if (n == 1) 
	{
		for (int i = 0; i < number - 1; ++i)
			for (int j = 0; j < number - 1; ++j)
				if (tab[j].get_przebieg() < tab[j + 1].get_przebieg())
				{
					pom = tab[j];
					tab[j] = tab[j + 1];
					tab[j + 1] = pom;
				}
	}
	if (n == 2) 
	{
		for (int i = 0; i < number - 1; ++i)
			for (int j = 0; j < number - 1; ++j)
				if (tab[j].get_pojemnosc() < tab[j + 1].get_pojemnosc())
				{
					pom = tab[j];
					tab[j] = tab[j + 1];
					tab[j + 1] = pom;
				}
	}
	if (n == 3) 
	{
		for (int i = 0; i < number - 1; ++i)
			for (int j = 0; j < number - 1; ++j)
				if (tab[j].get_rocznik() < tab[j + 1].get_rocznik())
				{
					pom = tab[j];
					tab[j] = tab[j + 1];
					tab[j + 1] = pom;
				}
	}

}
//Wyœwiwtlanie samochodu w schemacie podaj rocznik i podajesz np 2000, to wyswietli wszystkie auta ponad rocznikiem 2000
void wyswietl_samochod_z_parametrem(const SAMOCHOD::samochod tab[], const int & number, const int & wybor, const int & prog) 
{
	

	if (wybor == 1) 
	{
		for (int i = 0; i < number; ++i)
		{
			if (tab[i].get_przebieg() >= prog)
				cout << tab[i] << endl;
		}
	}
	if (wybor == 2) 
	{
		for (int i = 0; i < number; ++i)
		{
			if (tab[i].get_pojemnosc() >= prog)
				cout << tab[i] << endl;
		}
	}
	if (wybor == 3) 
	{
		for (int i = 0; i < number; ++i)
		{
			if (tab[i].get_rocznik() >= prog)
				cout << tab[i] << endl;
		}
	}
}



void zapis(const SAMOCHOD::samochod tab[], const int & n)
{
	ofstream plik;
	plik.open("samochody.txt"); 
	if (!plik.is_open()) //sprawdza czy plik da siê otworzyc, dzia³a tak jak plik.good() i patrzy zcy taki plik wgl istnieje.
		cout << "Blad otwarcia pliku" << std::endl;
	else
	{
		plik << n << endl; //zapisanie liczby samochodow ( tej ktora podalismy)
		for (int i = 0; i < n; ++i) //wypisanie wszystkich samochodow w petli
		{
			plik << tab[i].get_marka() << " ";
			plik << tab[i].get_model() << " ";
			plik << tab[i].get_rocznik() << " ";
			plik << tab[i].get_pojemnosc() << " ";
			plik << tab[i].get_przebieg() << " ";
			plik << tab[i].get_skrzynia() << endl;
		}
	}
	plik.close(); 
	cout << "Zmiany zapisano pomyslnie!" << endl << endl;
	system("PAUSE");
	system("cls");
}