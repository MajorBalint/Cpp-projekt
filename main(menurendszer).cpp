#include<string>
#include<iostream>
#include"ugyfel.h"
#include"ugyfeldb.h"

int ugyfelfelv(Ugyfeldb& a)
{
	Ugyfel* p = new Ugyfel;
	if (p == NULL)
	{
		std::cout << "Sikertelen memoria foglalas.";
		return -1;
	}
	std::string nev, cim;
	int hiba;
	int ugyfelekszama;

	std::cout << "Kerem adja meg az ugyfel nevet es cimet." << std::endl;

	char delimeter(';');
	std::getline(std::cin, nev, delimeter);
	std::getline(std::cin, cim);

	p->setcim(cim);
	p->setnev(nev);
	ugyfelekszama = a.getugyfelekszama();
	p->azonositoletrehoz(ugyfelekszama);

	std::cout << "Az on azonositoja:" << p->getazonosito() << std::endl;

	hiba=a.push_back(p);
	if (hiba == -1)
	{
		std::cout << "Sikertelen memoria foglalas.";
		return -1;
	}
	return 0;
}

int szerzodesk(Ugyfeldb& a)
{
	Ugyfel* p=NULL;
	Szerzodes* uj = new Szerzodes;
	if (uj == NULL)
	{
		std::cout << "Sikertelen memoria foglalas.";
		return -1;
	}
	Ugyfel** azonkeres = a.getp();
	std::string cim;

	int b = a.getugyfelekszama(), keresettazonosito, hibas, azonositotarol;
	std::cout << "Kerem adja meg az ugyfelazonositot." << std::endl;

	std::cin >> keresettazonosito;

	for (int i = 0; i < b; i++)
	{
		azonositotarol = azonkeres[i]->getazonosito();
		if (azonositotarol == keresettazonosito)
			p = azonkeres[i];
	}
	if (p == NULL)
	{
		std::cout << "Nem letezo azonosito.";
		return -1;
	}
	std::cout << "Kerem adja meg a szerzodes igenybevetelenek cimet." << std::endl;

	char delimeter(';');
	std::getline(std::cin, cim, delimeter);
	
	uj->setszerzodescim(cim);

	azonositotarol = uj->szerzodesszamletrehoz(*p);

	std::cout << "Az on azonositoja:" << azonositotarol << std::endl;

	hibas = p->push_back(uj);
	
	if (hibas == -1)
	{
			std::cout << "Sikertelen memoria foglalas.";
			return -1;
	}
	return 0;
}

int szamlazas(Ugyfeldb& a)
{
	int ugyfela, szerzodessz, azonositotarol, hibas = 0;
	std::cout << "Kerem adja meg az ugyfelazonositot, majd a szerzodesszamot." << std::endl;

	std::cin >> ugyfela;
	std::cin >> szerzodessz;

	int b = a.getugyfelekszama();
	Ugyfel** azonkeres = a.getp();
	Ugyfel* p=NULL;

	for (int i = 0; i < b; i++)
	{
		azonositotarol = azonkeres[i]->getazonosito();
		if (azonositotarol == ugyfela)
			p = azonkeres[i];
	}
	if (p == NULL)
	{
		std::cout << "Nem letezo azonosito.";
		return -1;
	}

	b = p->getszerzodesdb();
	Szerzodes** keres = p->getszerzodespointer();
	Szerzodes* pointer=NULL;

	for (int i = 0; i < b; i++)
	{
		azonositotarol = keres[i]->getszerzodesszam();
		if (azonositotarol == szerzodessz)
			pointer = keres[i];
	}
	if (pointer == NULL)
	{
		std::cout << "Nem letezo azonosito.";
		return -1;
	}

	Szamla* uj = new Szamla;
	if (uj == NULL)
	{
		std::cout << "Sikertelen memoria foglalas.";
		return -1;
	}

	int osszeg;

	std::cout << "Kerem adja meg az osszeget." << std::endl;
	std::cin >> osszeg;

	uj->setosszeg(osszeg);
	pointer->setegyenleg(-uj->getosszeg());

	azonositotarol = uj->szamlaszamaletrehoz(*pointer);
	std::cout << "A szamla azonositoja:" << azonositotarol << std::endl;

	hibas = pointer->push_back(uj);
	if (hibas == -1)
	{
		std::cout << "Sikertelen memoria foglalas.";
		return -1;
	}
	return 0;
}

int szamlabef(Ugyfeldb& a)
{
	int ugyfela, szerzodessz, szamlasz, azonositotarol;
	std::cout << "Kerem adja meg az ugfyelazonositot, szerzodesszamot, szamlaszamot." << std::endl;

	std::cin >> ugyfela;
	std::cin >> szerzodessz;
	std::cin >> szamlasz;

	int b = a.getugyfelekszama();
	Ugyfel** azonkeres = a.getp();
	Ugyfel* p=NULL;

	for (int i = 0; i < b; i++)
	{
		azonositotarol = azonkeres[i]->getazonosito();
		if (azonositotarol == ugyfela)
			p = azonkeres[i];
	}
	if (p == NULL)
	{
		std::cout << "Nem letezo azonosito.";
		return -1;
	}

	b = p->getszerzodesdb();
	Szerzodes** keres = p->getszerzodespointer();
	Szerzodes* pointer=NULL;

	for (int i = 0; i < b; i++)
	{
		azonositotarol = keres[i]->getszerzodesszam();
		if (azonositotarol == szerzodessz)
			pointer = keres[i];
	}
	if (pointer == NULL)
	{
		std::cout << "Nem letezo azonosito.";
		return -1;
	}

	b = pointer->getszamladb();
	Szamla** kereses = pointer->getszamlapointer();
	Szamla* szamlap=NULL;

	for (int i = 0; i < b; i++)
	{
		azonositotarol = kereses[i]->getszamlaszama();
		if (azonositotarol == szamlasz)
			szamlap = kereses[i];
	}
	if (szamlap == NULL)
	{
		std::cout << "Nem letezo azonosito.";
		return -1;
	}
	pointer->setegyenleg(szamlap->getosszeg());
	szamlap->setfizetve();

	return 0;
}

int egyenleglek(Ugyfeldb& a)
{
	int ugyfela, szerzodessz, azonositotarol, egyenleg;
	std::cout << "Kerem adja meg az ugfyelazonositot, szerzedesszamot." << std::endl;

	std::cin >> ugyfela;
	std::cin >> szerzodessz;

	int b = a.getugyfelekszama();
	Ugyfel** azonkeres = a.getp();
	Ugyfel* p=NULL;

	for (int i = 0; i < b; i++)
	{
		azonositotarol = azonkeres[i]->getazonosito();
		if (azonositotarol == ugyfela)
			p = azonkeres[i];
	}
	if (p == NULL)
	{
		std::cout << "Nem letezõ azonosito.";
		return -1;
	}

	b = p->getszerzodesdb();
	Szerzodes** keres = p->getszerzodespointer();
	Szerzodes* pointer=NULL;

	for (int i = 0; i < b; i++)
	{
		azonositotarol = keres[i]->getszerzodesszam();
		if (azonositotarol == szerzodessz)
			pointer = keres[i];
	}
	if (pointer == NULL)
	{
		std::cout << "Nem letezo azonosito.";
		return -1;
	}

	egyenleg = pointer->getegyenleg();

	std::cout << "Az on egyenlege:" << egyenleg << std::endl;

	return 0;
}

int fogybejelent(Ugyfeldb& a)
{
	int ugyfela, szerzodessz, azonositotarol, hibas = 0;
	double fogyaszt = 0.0;
	std::cout << "Kerem adja meg az ugyfelazonositot, majd a szerzodesszamot." << std::endl;

	std::cin >> ugyfela;
	std::cin >> szerzodessz;

	int b = a.getugyfelekszama();
	Ugyfel** azonkeres = a.getp();
	Ugyfel* p=NULL;

	for (int i = 0; i < b; i++)
	{
		azonositotarol = azonkeres[i]->getazonosito();
		if (azonositotarol == ugyfela)
			p = azonkeres[i];
	}
	if (p == NULL)
	{
		std::cout << "Nem letezo azonosito.";
		return -1;
	}

	b = p->getszerzodesdb();
	Szerzodes** keres = p->getszerzodespointer();
	Szerzodes* pointer=NULL;

	for (int i = 0; i < b; i++)
	{
		azonositotarol = keres[i]->getszerzodesszam();
		if (azonositotarol == szerzodessz)
			pointer = keres[i];
	}
	if (pointer == NULL)
	{
		std::cout << "Nem letezo azonosito.";
		return -1;
	}

	std::cout << "Kerem adja meg a bejelenteni kivant fogyasztast." << std::endl;

	std::cin >> fogyaszt;

	pointer->setfogyasztas(fogyaszt);

	return 0;
}

int fogylek(Ugyfeldb& a)
{
	int ugyfela, szerzodessz, azonositotarol;
	double egyenleg;
	std::cout << "Kerem adja meg az ugfyelazonositot, szerzedesszamot." << std::endl;

	std::cin >> ugyfela;
	std::cin >> szerzodessz;

	int b = a.getugyfelekszama();
	Ugyfel** azonkeres = a.getp();
	Ugyfel* p = NULL;

	for (int i = 0; i < b; i++)
	{
		azonositotarol = azonkeres[i]->getazonosito();
		if (azonositotarol == ugyfela)
			p = azonkeres[i];
	}
	if (p == NULL)
	{
		std::cout << "Nem letezõ azonosito.";
		return -1;
	}

	b = p->getszerzodesdb();
	Szerzodes** keres = p->getszerzodespointer();
	Szerzodes* pointer = NULL;

	for (int i = 0; i < b; i++)
	{
		azonositotarol = keres[i]->getszerzodesszam();
		if (azonositotarol == szerzodessz)
			pointer = keres[i];
	}
	if (pointer == NULL)
	{
		std::cout << "Nem letezo azonosito.";
		return -1;
	}

	egyenleg = pointer->getfogyasztas();

	std::cout << "Az on bejelentett fogyasztasainak osszege:" << egyenleg << std::endl;

	return 0;
}

int ugyfeladatok(Ugyfeldb& a)
{
	Ugyfel* p = NULL;
	Ugyfel** azonkeres = a.getp();
	std::string cim;

	int b = a.getugyfelekszama(), keresettazonosito, hibas, azonositotarol;
	std::cout << "Kerem adja meg az ugyfelazonositot." << std::endl;

	std::cin >> keresettazonosito;

	for (int i = 0; i < b; i++)
	{
		azonositotarol = azonkeres[i]->getazonosito();
		if (azonositotarol == keresettazonosito)
			p = azonkeres[i];
	}
	if (p == NULL)
	{
		std::cout << "Nem letezo azonosito.";
		return -1;
	}

	std::cout << p->getnev() << std::endl << p->getcim() << std::endl;

	return 0;
}

int szerzodesadatok(Ugyfeldb& a)
{
	int ugyfela, szerzodessz, azonositotarol, egyenleg;
	std::cout << "Kerem adja meg az ugfyelazonositot, szerzedesszamot." << std::endl;

	std::cin >> ugyfela;
	std::cin >> szerzodessz;

	int b = a.getugyfelekszama();
	Ugyfel** azonkeres = a.getp();
	Ugyfel* p = NULL;

	for (int i = 0; i < b; i++)
	{
		azonositotarol = azonkeres[i]->getazonosito();
		if (azonositotarol == ugyfela)
			p = azonkeres[i];
	}
	if (p == NULL)
	{
		std::cout << "Nem letezõ azonosito.";
		return -1;
	}

	b = p->getszerzodesdb();
	Szerzodes** keres = p->getszerzodespointer();
	Szerzodes* pointer = NULL;

	for (int i = 0; i < b; i++)
	{
		azonositotarol = keres[i]->getszerzodesszam();
		if (azonositotarol == szerzodessz)
			pointer = keres[i];
	}
	if (pointer == NULL)
	{
		std::cout << "Nem letezo azonosito.";
		return -1;
	}

	std::cout << p->getnev() << std::endl << pointer->getszerzodescim() << std::endl;

	return 0;
}

int& menukezeles(Ugyfeldb& counter, int& hiba)
{
	hiba = 1;
	int menupont;
	hiba = 0;
	
	std::cout << "Valasszon az alabbi menupontok kozul:" << std::endl << "Program bezarasa : -1" << std::endl << "Ugyfel adatok felvetele:1" << std::endl << "Szerzodes kotese:2" << std::endl << "Szolgaltatasi dij eloirasa:3" << std::endl << "Szolgaltatasi dij befizetese:4" << std::endl << "Egyenleg lekerdezese:5" << std::endl << "Fogyasztas bejelentese:6" << std::endl << "Fogyasztas lekerdezese:7" << std::endl << "Ugyfeladatok lekerdezese:8" << std::endl << "Szerzodesasatok lekerdezese:9" << std::endl;

	std::cin >> menupont;

	if (menupont < -1 || menupont == 0 || menupont >9)
	{
		std::cout << "Rossz szamot adott meg, kerem adja meg megegyszer a kivant szamot:" << std::endl;
		hiba = 0;
		return hiba;
	}

	switch (menupont)
	{
	case -1: hiba = -1; break;
	case 1: (ugyfelfelv(counter)); break;
	case 2: (szerzodesk(counter)); break;
	case 3: (szamlazas(counter)); break;
	case 4: (szamlabef(counter)); break;
	case 5: (egyenleglek(counter)); break;
	case 6: (fogybejelent(counter)); break;
	case 7: (fogylek(counter)); break;
	case 8: (ugyfeladatok(counter)); break;
	case 9: (szerzodesadatok(counter)); break;
	}

	return hiba;
}

int main()
{
	Ugyfeldb counter;
	int hiba = 0;

	while (hiba != -1)
	{
		hiba = menukezeles(counter, hiba);
	}

	return 0;
}