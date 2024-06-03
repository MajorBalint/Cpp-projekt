#ifndef SZAMLA_H
#define SZAMLA_H
#include<string>
#include"szerzodes.h"

class Szerzodes;

class Szamla
{
	int osszeg;
	int szamlaszama;
	bool fizetve;

public:
	Szamla();
	void setosszeg(int);
	int getosszeg() const;
	void setfizetve();
	int szamlaszamaletrehoz(const Szerzodes& a);
	int getszamlaszama() const;
};
#endif