#ifndef UGYFEL_H
#define UGYFEL_H
#include<string>
#include"szerzodes.h"
#include"szamla.h"

class Szerzodes;
class Szamla;

class Ugyfel
{
	int szerdodesdb;
	Szerzodes** szerzodespointer;
	std::string nev;
	std::string cim;
	int azonosito;
	
public:
	Ugyfel();
	int push_back(Szerzodes*);
	Szerzodes** getszerzodespointer() const;
	int getszerzodesdb() const;
	int getazonosito() const;
	std::string getnev() const;
	std::string getcim() const;
	void setnev(std::string);
	void setcim(std::string);
	int azonositoletrehoz(int);
	Szerzodes* operator[](size_t id);

	~Ugyfel();
};
#endif