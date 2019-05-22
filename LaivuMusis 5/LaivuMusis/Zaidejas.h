#ifndef Zaidejas_h
#define Zaidejas_h
#include "Bibliotekos.h"
using namespace std;

class zaidejas
{
private:
	const static int eile = 10;
	const static int stulpelis = 10;
	int lenta[eile][stulpelis];
	int NeLenta[eile][stulpelis];
	vector<int> CPUeil;
	vector<int> CPUstul;
	vector<int> CPUkryptis;
	vector<laivai> laivuSarasas;
	int teil;
	int *tteil;
	int tstul;
	int *ttstul;
	int Pataikyta;
	int kryptis;
	int control;
public:
	zaidejas()
	{
		for (int i = 0; i < eile; i++)
		{
			for (int j = 0; j < stulpelis; j++)
			{
				lenta[i][j] = 0;
				NeLenta[i][j] = 0;
			}
		}
		Pataikyta = 0;
		kryptis = 0;
		control = 0;
	}
	void atakuoti(int &eil, int &stul) // Zmogus pasirenka kokias koordinates atakuoti
	{
		cout << "Irasykite eiles koordinate: ";
		cin >> eil;
		cout << "Irasykite stulpelio koordinate: ";
		cin >> stul;
	}
	int ArPataike(int eil, int stul) // tikrina ar zmogus pataike isveda teksta
	{
		int paskendo = 0;
		for (int i = 0; i < 10; i++)
		{
			if (Pataikyta == 30)
			{
				return 10;
			}
			if (lenta[eil][stul] == 1)
			{
				cout << "Cia jau buvo sauta." << endl;
				Sleep(1000);
				return 1;
			}
			else if (lenta[eil][stul] == 0)
			{
				cout << "Nepataikei " << endl;
				lenta[eil][stul] = 9;
				Sleep(1000);
				return 9;

			}
			else if (lenta[eil][stul] == 9)
			{
				cout << "Cia jau buvo sauta." << endl;
				Sleep(1000);
				return 9;
			}
			else if (laivuSarasas[i].GautiPavadinima(eil, stul) != "")
			{
				laivuSarasas[i].Pataike();
				//cout << "Pataikei i " << laivuSarasas[i].GautiPavadinima(eil, stul) << endl;
				cout << "Pataikei" << endl;
				lenta[eil][stul] = 1;
				paskendo = laivuSarasas[i].ArNuskedo();
				Pataikyta++;
				if (paskendo == 9)
				{
					laivuSarasas[i].LaivuKoordinates(lenta);
					cout << "Nuskandinai " << laivuSarasas[i].GautiPavadinima(eil, stul);
					Sleep(1000);
					return -1;
				}
				Sleep(1000);
				return 1;
			}
		}
		return 1;
	}
	void sudetiLaivus() // duoda zmogui pasirinkti rankiniu budu ar automatiskai sudeti laivus
	{
		int budas;
		Lenta L;
		system("CLS");
		cout << "Sudeti laivus" << endl;
		cout << "Automatiskai 1" << endl;
		cout << "Rankomis 2" << endl;
		cin >> budas;
		if (budas == 1)
			L.SudetiLaivus(lenta, laivuSarasas);
		else if (budas == 2)
			L.SudetiLaivusRank(lenta, laivuSarasas);
	}
	void sudetiLaivusCPU() // CPU atomatiskai sudeda laivus
	{
		Lenta L;
		L.SudetiLaivus(lenta, laivuSarasas);
	}
	void NetikraLenta(int eil, int stul, int sk)
	{
		NeLenta[eil][stul] = sk;
	}
	void spausdintiNetikraLenta()
	{
		cout << "  0 1 2 3 4 5 6 7 8 9" << endl;
		for (int i = 0; i < 10; i++)
		{
			cout << i;
			for (int j = 0; j < 10; j++)
			{
				if (NeLenta[i][j] == 1 || NeLenta[i][j] == -1)
					cout << " X";
				else if (NeLenta[i][j] == -2)
					cout << " *";
				else if (NeLenta[i][j] == 9 || NeLenta[i][j] == 8)
					cout << " o";
				else
					cout << " ~";
			}
			cout << endl;
		}
		cout << endl;
	}
	void isspausdinti() //Ispausdina lenta su visais laivais
	{
		for (int i = 0; i < eile; i++)
		{
			for (int j = 0; j < stulpelis; j++)
			{
				cout << lenta[i][j] << " ";
			}
			cout << endl;
		}
	}
};


#endif /*Zaidejas_h*/
