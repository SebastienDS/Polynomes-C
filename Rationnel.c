#include <stdio.h>
#include <stdlib.h>
#include "Rationnel.h"

void printRationnelFrac(Rationnel r)
{
    printf("+(%d/%d)", r.num, r.den);
}

void printRationnel(Rationnel r)
{
    if ((float)r.num / r.den >= 0)
    {
        printf("+");
    }
    printf("%.2f", (float)r.num / r.den);
}

Rationnel inputRationnelFrac()
{
    int num, den;
    if (scanf("%d/%d", &num, &den) != 2 || den == 0)
    {
        printf("Vous n'avez pas saisi de fraction valide\n");
        exit(EXIT_FAILURE);
    }
    Rationnel r = {num, den};
    return r;
}

int pgcd(int a, int b)
{
    int reste;
    while (1)
    {
        reste = a % b;
        if (reste == 0)
            return b;
        a = b;
        b = reste;
    }
}

void simplify(Rationnel *r)
{
    int pgcd_ = pgcd(r->num, r->den);
    r->num /= pgcd_;
    r->den /= pgcd_;
}

Rationnel sumRationnel(Rationnel r1, Rationnel r2)
{
    Rationnel r;
    int a = r1.num;
    int b = r1.den;
    int c = r2.num;
    int d = r2.den;

    if (b != d)
    {
        a *= d;
        c *= b;
        b *= d;
    }
    r.num = a + c;
    r.den = b;

    simplify(&r);
    return r;
}