#ifndef SZERZODES_H
#define SZERZODES_H
#include<string>
#include"szamla.h"
#include"ugyfel.h"

class Ugyfel;
class Szamla;

class Szerzodes
{
	Szamla** szamlapointer;
	int szamladb;
	std::string szerzodescim;
	int szerzodesszam;
	double fogyasztas;
	int egyenleg;
	
public:
	Szerzodes();
	int push_back(Szamla*);
	double getfogyasztas() const;
	Szamla** getszamlapointer() const;
	int getszerzodesszam() const;
	std::string getszerzodescim() const;
	int getegyenleg() const;
	int getszamladb() const;
	void setegyenleg(int);
	void setszerzodescim(std::string);
	int szerzodesszamletrehoz(const Ugyfel&);
	void setfogyasztas(double);
	Szamla* operator[](size_t id);
	
	~Szerzodes();
};
#endif