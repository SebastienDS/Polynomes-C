#include <stdio.h>
#include <stdlib.h>
#include "Rationnel.h"
#include "Polynome.h"

int main()
{
    // Rationnel r1 = {4, 2};
    // Rationnel r2 = {4, 5};
    // Rationnel poly[] = {r1, r2};
    // Polynome p = initPolynome(1, poly);
    // destroyPolynome(&p);


    Polynome p1 = inputPolynome();
    Polynome p2 = inputPolynome();
    printPolynome(sumPolynome(p1, p2));

    destroyPolynome(&p1);
    destroyPolynome(&p2);
    return 0;
}
