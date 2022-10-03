#include "classString.hpp"
#include <iostream>
#define CAPACITE_DEFAUT 16



//chaine de caractere de maxium 16 caracteres
classString::classString()
{
    str = new char[CAPACITE_DEFAUT];
    capacity = CAPACITE_DEFAUT;
    strlength = 0;
}

//char de maximum 16 caracteres, si plus de 16 characere, char*2
classString::classString(const char* str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        i++;
    }
    if (i < CAPACITE_DEFAUT)
    {
        this->str = new char[CAPACITE_DEFAUT];
        capacity = CAPACITE_DEFAUT;
    }
    else
    {
        this->str = new char[i * 2];
        capacity = i * 2;
    }
    strlength = i;
    for (int j = 0; j < i; j++)
    {
        this->str[j] = str[j];
    }
}



classString::~classString()
{
    delete[] str;
}
