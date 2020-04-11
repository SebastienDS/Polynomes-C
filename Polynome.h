#ifndef POLYNOME_H
#define POLYNOME_H

#include "Rationnel.h"

typedef struct
{
    int degre;
    Rationnel *poly;
} Polynome;

void printPolynome(Polynome polynome);
Polynome initPolynome(int degre, Rationnel *poly);
void destroyPolynome(Polynome *polynome);
Polynome inputPolynome();
Polynome sumPolynome(Polynome p1, Polynome p2);

#endif