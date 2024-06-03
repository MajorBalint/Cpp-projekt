#include"ugyfel.h"
#include "szerzodes.h"

Szerzodes::Szerzodes()
{
	szamladb = 0;
	szamlapointer = NULL;
	egyenleg = 0;
	fogyasztas = 0;
	szerzodesszam = 0;
}

int Szerzodes::push_back(Szamla* a)
{
	Szamla** uj;
	szamladb = szamladb + 1;
	uj = new Szamla * [szamladb];
	if (uj == NULL)
		return -1;

	for (int i = 0; i < (szamladb - 1); i++)
	{
		uj[i] = szamlapointer[i];
	}
	uj[szamladb - 1] = a;
	
	delete[] szamlapointer;

	szamlapointer = uj;

	return 0;
}

double Szerzodes::getfogyasztas() const
{
	return fogyasztas;
}

Szamla** Szerzodes::getszamlapointer() const
{
	return szamlapointer;
}

int Szerzodes::getszerzodesszam() const
{
	return szerzodesszam;
}

std::string Szerzodes::getszerzodescim() const
{
	return szerzodescim;
}

int Szerzodes::getegyenleg() const
{
	return egyenleg;
}

int Szerzodes::getszamladb() const
{
	return szamladb;
}

void Szerzodes::setegyenleg(int a)
{
	egyenleg = egyenleg + a;
}

void Szerzodes::setszerzodescim(std::string a)
{
	szerzodescim = a;
}

int Szerzodes::szerzodesszamletrehoz(const Ugyfel& a)
{
	int b = a.getszerzodesdb();
	szerzodesszam = b + 1;
	return szerzodesszam;
}

void Szerzodes::setfogyasztas(double a)
{
	fogyasztas = fogyasztas + a;
}

Szamla* Szerzodes::operator[](size_t id)
{
	return szamlapointer[id];
}

Szerzodes::~Szerzodes()
{
	for (int i = 0; i < szamladb; i++)
		delete szamlapointer[i];
	delete[] szamlapointer;
}
