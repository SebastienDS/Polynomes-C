#ifndef POLYNOME_H
#define POLYNOME_H

#include "Rationnel.h"

typedef struct
{
    int degre;
    Rationnel *poly;
} Polynome;

void printPolynome(Polynome polynome);
int _initPolynome(int degre, Polynome *ret);
int initPolynome(int degre, Rationnel *poly, Polynome *ret);
void destroyPolynome(Polynome *polynome);
int inputPolynome(Polynome *ret);
int sumPolynome(Polynome p1, Polynome p2, Polynome *ret);
int productPolynome(Polynome p1, Polynome p2, Polynome* ret);

#endif