#ifndef Zaist_h
#define Zaisti_h
#include "Bibliotekos.h"

class zaisti
{
private:
	bool vyksta;
	zaidejas z1;
	zaidejas z2;
	int budas;
public:
	zaisti()
	{
		vyksta = true;
	}
	void Pradeti() //Zaidimo pradzia duoda pasirinkti kokiu budu zaisti
	{
		cout << "	Laivu Musis " << endl << endl;
		cout << "Zmogus pries zmogu 1" << endl;
		cout << "Zmogus pries kompiuteri 2" << endl;
		cout << "Kompiuteris pries kompiuteri 3" << endl;
		cin >> budas;
		if (budas == 1)
			ZvsZ();
		else if (budas == 2)
			ZvsC();
		else if (budas == 3)
			CvsC();

	}
	void NupiestiLentas() //Isspausdina netikras lentas
	{
		system("CLS");
		cout << "    Pirmas Zaidejas " << endl;
		z1.spausdintiNetikraLenta();
		cout << "    Antras Zaidejas " << endl;
		z2.spausdintiNetikraLenta();
	}
	void Nupiesti() // Isspausdina lentas su visais laivais
	{
		system("CLS");
		cout << "    Pirmas Zaidejas " << endl;
		z1.isspausdinti();
		cout << "    Antras Zaidejas " << endl;
		z2.isspausdinti();
	}
	void ZvsZ() //Zmogus pries zmogu
	{
		int eile = 0;
		int stulpelis = 0;
		int pataike1 = 0;
		int pataike2 = 0;

		z1.sudetiLaivus();
		z2.sudetiLaivus();

		//Nupiesti();
		//system("pause");

		NupiestiLentas();

		while (vyksta)
		{
			z1.atakuoti(eile, stulpelis);
			pataike1 = z2.ArPataike(eile, stulpelis);
			z1.NetikraLenta(eile, stulpelis, pataike1);
			if (pataike1 == 10)
			{
				system("CLS");
				cout << "Laimejo pirmas zaidejas! " << endl;
				vyksta = false;
			}

			NupiestiLentas();

			z2.atakuoti(eile, stulpelis);
			pataike2 = z1.ArPataike(eile, stulpelis);
			z2.NetikraLenta(eile, stulpelis, pataike2);
			if (pataike2 == 10)
			{
				system("CLS");
				cout << "Laimejo antras zaidejas! " << endl;
				vyksta = false;
			}
			NupiestiLentas();
		}
	}
	void ZvsC() //Zmogus pries kompiuteri
	{
		int eile = 0;
		int stulpelis = 0;
		int pataike1 = 0;
		int pataike2 = 0;

		z1.sudetiLaivus();
		z2.sudetiLaivusCPU();

		//Nupiesti();
		//system("pause");

		NupiestiLentas();

		while (vyksta)
		{
			z1.atakuoti(eile, stulpelis);
			pataike1 = z2.ArPataike(eile, stulpelis);
			z1.NetikraLenta(eile, stulpelis, pataike1);
			if (pataike1 == 10)
			{
				system("CLS");
				cout << "Laimejo pirmas zaidejas! " << endl;
				vyksta = false;
			}

			NupiestiLentas();

			z2.atakuotiCPU(eile, stulpelis, pataike2);
			pataike2 = z1.ArPataikeCPU(eile, stulpelis);
			z2.NetikraLenta(eile, stulpelis, pataike2);
			if (pataike2 == 10)
			{
				system("CLS");
				cout << "Laimejo antras zaidejas! " << endl;
				vyksta = false;
			}
			NupiestiLentas();
		}
	}
	void CvsC() //Kompiuteris pries kompiuteri
	{
		int eile = 0;
		int stulpelis = 0;
		int pataike1 = 0;
		int pataike2 = 0;

		z1.sudetiLaivusCPU();
		z2.sudetiLaivusCPU();

		//Nupiesti();
		//system("pause");

		NupiestiLentas();

		while (vyksta)
		{
			z1.atakuotiCPU(eile, stulpelis, pataike1);
			pataike1 = z2.ArPataikeCPU(eile, stulpelis);
			z1.NetikraLenta(eile, stulpelis, pataike1);
			if (pataike1 == 10)
			{
				system("CLS");
				cout << "Laimejo pirmas zaidejas! " << endl;
				vyksta = false;
			}

			NupiestiLentas();
			Sleep(200);

			z2.atakuotiCPU(eile, stulpelis, pataike2);
			pataike2 = z1.ArPataikeCPU(eile, stulpelis);
			z2.NetikraLenta(eile, stulpelis, pataike2);
			if (pataike2 == 10)
			{
				system("CLS");
				cout << "Laimejo antras zaidejas! " << endl;
				vyksta = false;
			}
			NupiestiLentas();
			Sleep(200);
		}
	}
};

#endif // !Zaist_h

