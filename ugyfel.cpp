#include "ugyfel.h"
#include"ugyfeldb.h"

int Ugyfel::azonositoletrehoz(int a)
{
    if (a >= 0)
    {
        int azon = a + 1;
        azonosito = azon;
        return azon;
    }
}

Szerzodes* Ugyfel::operator[](size_t id)
{
   
    return szerzodespointer[id];
  
}

Ugyfel::~Ugyfel()
{
    for (int i = 0; i < szerdodesdb; i++)
        delete szerzodespointer[i];
    delete[] szerzodespointer;
}

Ugyfel::Ugyfel()
{
    szerdodesdb = 0;
    szerzodespointer = NULL;
    azonosito = 0;
}

int Ugyfel::push_back(Szerzodes* a)
{
    Szerzodes** uj;
    szerdodesdb = szerdodesdb + 1;
    uj = new Szerzodes * [szerdodesdb];
    if (uj == NULL)
        return -1;

    for (int i = 0; i < (szerdodesdb - 1); i++)
    {
        uj[i] = szerzodespointer[i];
    }
    uj[szerdodesdb - 1] = a;
    
    delete[] szerzodespointer;

    szerzodespointer = uj;

    return 0;
}

Szerzodes** Ugyfel::getszerzodespointer() const
{
    return szerzodespointer;
}

int Ugyfel::getszerzodesdb() const
{
    return szerdodesdb;
}

int Ugyfel::getazonosito() const
{
    return azonosito;
}

std::string Ugyfel::getnev() const
{
    return nev;
}

std::string Ugyfel::getcim() const
{
    return cim;
}

void Ugyfel::setnev(std::string a)
{
    nev = a;
}

void Ugyfel::setcim(std::string a)
{
    cim = a;
}