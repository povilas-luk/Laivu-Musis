#ifndef Lenta_h
#define Lenta_h
#include "Bibliotekos.h"
using namespace std;


class Lenta
{
private:
	bool r;
	int tempLenta[10][10];
public:
	Lenta()
	{
		r = false;
	}

	void SudetiLaivus(int(&lenta)[10][10], vector<laivai>& laivuSarasas)
	{
		int temp;

		while (!r)
		{
			temp = 0;
			for (int i = 0; i < 10; i++)
			{
				for (int j = 0; j < 10; j++)
				{
					lenta[i][j] = 0;
				}
			}

			r = idetiLaiva(lenta, 5, "5 Vietu", laivuSarasas); if (r == true) { temp++; }
			r = idetiLaiva(lenta, 4, "4 Vietu", laivuSarasas); if (r == true) { temp++; }
			r = idetiLaiva(lenta, 4, "4 Vietu", laivuSarasas); if (r == true) { temp++; }
			r = idetiLaiva(lenta, 3, "3 Vietu", laivuSarasas); if (r == true) { temp++; }
			r = idetiLaiva(lenta, 3, "3 Vietu", laivuSarasas); if (r == true) { temp++; }
			r = idetiLaiva(lenta, 3, "3 Vietu", laivuSarasas); if (r == true) { temp++; }
			r = idetiLaiva(lenta, 2, "2 Vietu", laivuSarasas); if (r == true) { temp++; }
			r = idetiLaiva(lenta, 2, "2 Vietu", laivuSarasas); if (r == true) { temp++; }
			r = idetiLaiva(lenta, 2, "2 Vietu", laivuSarasas); if (r == true) { temp++; }
			r = idetiLaiva(lenta, 2, "2 Vietu", laivuSarasas); if (r == true) { temp++; }
			if (temp > 0) { r = true; }
		}
	}

	bool idetiLaiva(int lenta[][10], int LaivoDydis, string LaivoPavadinimas, vector<laivai> &laivuSarasas) // Padeda viena laiva
	{
		srand(time(NULL));
		int stul = 0;
		int eil = 0;
		char d;
		bool idejimoKlaida = true;
		int cS = 0;
		int temp = 0;

		d = gautiKrypti(rand() % 10);  //Sugeneruoja kaip deti laiva horizontaliai ar vertikaliai
		atstatytiEiluStulpeli(stul, eil, LaivoDydis, d);  //Sugeneruoja atsitiktines koordinates

		while (idejimoKlaida)
		{
			cS = patikrintiTarpus(lenta, stul, eil, LaivoDydis, d); //tikrina ar laivas tilps i lenta
			if (cS == 1) //jeigu 1 reiskia netelpa todel generuoja naujas koordinates
			{
				d = gautiKrypti(rand() % 10);
				atstatytiEiluStulpeli(stul, eil, LaivoDydis, d);
				cS = 0;
				temp++;
				if (temp == 50)
				{
					return true;
				}

				continue;
			}
			pakeistiLentele(lenta, stul, eil, LaivoDydis, d); //Ideda laiva i lenta
			pakeistiLaivoDuomenis(lenta, stul, eil, LaivoDydis, LaivoPavadinimas, d, laivuSarasas);//sukuria laivo objekta
			return false;
		}
	}

	char gautiKrypti(int d) //Horizontaliai ar vertikaliai deti laiva
	{
		if (d > 4)
			return 'h';
		else
			return 'v';
	}

	void pakeistiLentele(int lenta[][10], int stul, int eil, int LaivoDydis, char dir)
		//Ideda laiva i lenta
	{
		if (dir == 'h')
		{
			for (int i = 0; i < LaivoDydis; i++)
			{
				lenta[eil][stul] = LaivoDydis;
				stul++;
			}
		}
		else if (dir == 'v')
		{
			for (int i = 0; i < LaivoDydis; i++)
			{
				lenta[eil][stul] = LaivoDydis;
				eil++;
			}
		}
		else
		{
			cout << "Error!  No direction passed" << endl;
		}
	}

	int patikrintiTarpus(int lenta[][10], int c, int r, int s, char d) //Tikrina ar laivai neuzeina vienas ant kito
	{
		int temp = 0;
		if (d == 'h')
		{
			for (int i = c; i < c + s; i++)
			{
				if (lenta[r][i] == 0 && i < 10 && i >= 0)
					temp++;
				if (lenta[r + 1][i + 1] != 0 || lenta[r - 1][i - 1] != 0)
					temp--;
				if (lenta[r - 1][i + 1] != 0 || lenta[r + 1][i - 1] != 0)
					temp--;
				if (lenta[r][c + s] != 0)
					temp--;
				if (lenta[r][c - 1] != 0)
					temp--;
			}
			if (temp == s)
				return 0;
			else
				return 1;
		}
		else
		{
			for (int i = r; i < r + s; i++)
			{
				if (lenta[i][c] == 0 && i < 10 && i >= 0)
					temp++;
				if (lenta[i + 1][c + 1] != 0 || lenta[i - 1][c - 1] != 0)
					temp--;
				if (lenta[i + 1][c - 1] != 0 || lenta[i - 1][c + 1] != 0)
					temp--;
				if (lenta[r + s][c] != 0)
					temp--;
				if (lenta[r - 1][c] != 0)
					temp--;
			}

			if (temp == s)
				return 0;
			else
				return 1;
		}
	}

	void atstatytiEiluStulpeli(int &stul, int &eil, int LaivoDydis, char d)
	{
		if (d == 'h')
		{
			stul = rand() % 10 - LaivoDydis;
			eil = rand() % 10;
		}
		else
		{
			stul = rand() % 10;
			eil = rand() % 10 - LaivoDydis;
		}
	}

	void pakeistiLaivoDuomenis(int lenta[][10], int c, int r, int LaivoDydis, string LaivoPavadinimas, char d, vector<laivai> &laivuSarasas)
	{

		if (d == 'h')
		{
			vector<int> r1(LaivoDydis);
			for (int i = 0; i < (int)r1.size(); ++i)
			{
				r1.at(i) = r;
			}
			vector<int> c1(LaivoDydis);
			for (int i = 0; i < (int)c1.size(); ++i)
			{
				c1.at(i) = c;
				c++;
			}
			laivai carrierBoat('h', LaivoDydis, r1, c1, 0, LaivoPavadinimas);
			laivuSarasas.push_back(carrierBoat);
		}
		else if (d == 'v')
		{
			vector<int> r1(LaivoDydis);
			for (int i = 0; i < (int)r1.size(); ++i)
			{
				r1.at(i) = r;
				r++;
			}
			vector<int> c1(LaivoDydis);
			for (int i = 0; i < (int)c1.size(); ++i)
			{
				c1.at(i) = c;
			}

			laivai carrierBoat('v', LaivoDydis, r1, c1, 0, LaivoPavadinimas);
			laivuSarasas.push_back(carrierBoat);
		}

	}
	void SudetiLaivusRank(int(&lenta)[10][10], vector<laivai>& laivuSarasas)
	{
		int kryptis;
		char kryp;
		int eilute;
		int stulpelis;
		int tilps;
		string pav;
		for (int i = 5; i > 0; i--)
		{
			system("CLS");
			cout << "   0 1 2 3 4 5 6 7 8 9" << endl << endl;
			for (int l = 0; l < 10; l++)
			{
				cout << l << "  ";
				for (int j = 0; j < 10; j++)
				{
					cout << lenta[l][j] << " ";
				}
				cout << endl;
			}
			cout << "Ideti " << i << " vietu laiva" << endl;
			cout << "kryptis '0' horizontaliai, '1' vertikaliai " << endl;
			cout << "eilute (0-9)" << endl;
			cout << "stulpelis (0-9)" << endl;
			cout << "pvz.: (1 5 2)" << endl;
			cin >> kryptis >> eilute >> stulpelis;
			if (kryptis == 0) kryp = 'h';
			else if (kryptis == 1) kryp = 'v';
			tilps = patikrintiTarpus(lenta, stulpelis, eilute, i, kryp);
			if (tilps == 1) { i++; }
			if (tilps == 0)
			{
				pakeistiLentele(lenta, stulpelis, eilute, i, kryp);
				if (i == 5) pav = "5 Vietu";
				if (i == 4) pav = "3 Vietu";
				if (i == 3) pav = "2 Vietu";
				if (i == 1) pav = "1 Vietu";
				pakeistiLaivoDuomenis(lenta, stulpelis, eilute, i, pav, kryp, laivuSarasas);
			}
		}
	}
};

#endif // Lenta_h


