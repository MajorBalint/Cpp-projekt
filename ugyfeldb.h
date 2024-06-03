#ifndef UGYFELDB_H
#define UGYFELDB_H
#include "ugyfel.h"

class Ugyfeldb
{
	int ugyfelekszama;
	Ugyfel** ugyfelpointer;

public:
	Ugyfeldb();
	int push_back(Ugyfel*);
	int getugyfelekszama() const;
	Ugyfel** getp() const;
	void setugyfelekszama(int);
	Ugyfel* operator[](size_t id);

	~Ugyfeldb();
};
#endif