#include <stdio.h>
#include <stdlib.h>
#include "Polynome.h"


void printPolynome(Polynome p) {
    int x = p.degre;
    for (int i = 0; i < p.degre + 1; i++)
    {
        printRationnelFrac(p.poly[i]);
        if (x == 1) {
            printf("x");
        }else if (x > 0) {
            printf("x^%d", x);
        }
        x--;
    }
}

Polynome initPolynome(int degre, Rationnel* poly) {
    Polynome p = {degre, malloc(degre * sizeof(Rationnel))};
    for (int i = 0; i < degre + 1; i++)
    {
        p.poly[i] = poly[i];
    }
    return p;
}

void destroyPolynome(Polynome* p) {
    free(p->poly);
}