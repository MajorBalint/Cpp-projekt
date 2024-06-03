#include "ugyfeldb.h"
#include "ugyfel.h"

Ugyfeldb::Ugyfeldb()
{
	ugyfelekszama = 0;
	ugyfelpointer = nullptr;
}

int Ugyfeldb::push_back(Ugyfel* a)
{
	Ugyfel** uj;
	uj = new Ugyfel* [ugyfelekszama+1];
	if (uj == NULL)
		return -1;

	for (int i = 0; i < (ugyfelekszama); i++)
	{
		uj[i] = ugyfelpointer[i];
	}
	uj[ugyfelekszama] = a;

	delete[] ugyfelpointer;

	ugyfelekszama = ugyfelekszama + 1;

	ugyfelpointer = uj;

	return 0;
}

int Ugyfeldb::getugyfelekszama() const
{
	return ugyfelekszama;
}

Ugyfel** Ugyfeldb::getp() const
{
	return ugyfelpointer;
}

void Ugyfeldb::setugyfelekszama(int a)
{
		ugyfelekszama = ugyfelekszama + a;
}

Ugyfel* Ugyfeldb::operator[](size_t id)
{
	return ugyfelpointer[id];
}

Ugyfeldb::~Ugyfeldb()
{
	for(int i=0; i < ugyfelekszama; i++)
		delete ugyfelpointer[i];
	delete[] ugyfelpointer;
}