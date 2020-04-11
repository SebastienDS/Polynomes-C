#include <stdio.h>
#include <stdlib.h>
#include "Rationnel.h"
#include "Polynome.h"


int main() {
    Rationnel r1 = {1, 2};
    Rationnel r2 = {4, 5};
    Rationnel poly[] = {r1, r2};

    Polynome p = initPolynome(1, poly);
    printPolynome(p);

    destroyPolynome(&p);
    return 0;
}
