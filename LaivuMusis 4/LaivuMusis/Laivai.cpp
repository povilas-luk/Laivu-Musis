#include "Bibliotekos.h"
using namespace std;

laivai::laivai(char d, int lgth, vector<int> r, vector<int> c, int hit, string nme)
{
	dir = d;
	ilgis = lgth;
	LaivuEile = r;
	LaivuStulpelis = c;
	pataikymai = hit;
	pavadinimas = nme;
}

//uzregistruoti pataikyta suvi
void laivai::Pataike()
{
	pataikymai++;
}

// Patikrinti ar nenuskendo laivas
int laivai::ArNuskedo()
{
	if (pataikymai >= ilgis)
	{
		return 9;
	}
	else
	{
		return 0;
	}
}

//get boat grid coordinates
void laivai::LaivuKoordinates(int(&lenta)[10][10])
{
	for (int i = 0; i < ilgis; i++)
	{
		lenta[LaivuEile[i]][LaivuStulpelis[i]] = -2;
	}
	cout << endl;
}

//Laivo pavadinimas pagal koordinates
string laivai::GautiPavadinima(int r, int c)
{
	for (int i = 0; i < ilgis; i++)
	{
		if ((LaivuEile[i] == r) && (LaivuStulpelis[i] == c))
		{
			return pavadinimas;
		}
	}
	return "";
}