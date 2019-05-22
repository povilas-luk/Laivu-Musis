#ifndef Laivai_h
#define Laivai_h
#include "Bibliotekos.h"
using namespace std;

class laivai
{
private:
	char dir;
	int ilgis;
	vector<int> LaivuEile;
	vector<int> LaivuStulpelis;
	int pataikymai;
	string pavadinimas;
public:
	laivai(char d, int lgth, vector<int> r, vector<int> c, int hit, string nme);
	void Pataike();
	int ArNuskedo();
	void LaivuKoordinates(int(&lenta)[10][10]);
	string GautiPavadinima(int r, int c);
};

#endif /*Laivai_h*/
