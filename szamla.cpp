#include "szamla.h"
#include "szerzodes.h"

Szamla::Szamla()
{
	osszeg = 0;
	fizetve = false;
	szamlaszama = 0;
}

void Szamla::setosszeg(int a)
{
	osszeg = a;
}

int Szamla::getosszeg() const
{
	return osszeg;
}

void Szamla::setfizetve()
{
	fizetve = true;
}

int Szamla::szamlaszamaletrehoz(const Szerzodes& a)
{
	int b = a.getszamladb();

	szamlaszama = b + 1;

	return b+1;
}

int Szamla::getszamlaszama() const
{
	return szamlaszama;
}