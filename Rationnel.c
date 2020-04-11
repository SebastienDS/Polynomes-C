#include <stdio.h>
#include <stdlib.h>
#include "Rationnel.h"


void printRationnelFrac(Rationnel r) {
    printf("+(%d/%d)", r.num, r.den);
}

void printRationnel(Rationnel r) {
    if ((float)r.num/r.den >= 0) {
        printf("+");
    }
    printf("%.2f", (float)r.num / r.den);
}