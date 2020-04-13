#include <stdio.h>
#include <stdlib.h>
#include "Rationnel.h"
#include "code.h"

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

int inputRationnelFrac(Rationnel *ret)
{
    int num, den;
    if (scanf("%d/%d", &num, &den) != 2)
    {
        printf("Vous n'avez pas saisi de fraction valide\n");
        return FAIL_INPUT;
    }
    Rationnel r = {num, den};
    if (!isRationnelValid(r))
    {
        return FAIL;
    }
    *ret = r;
    simplify(ret);
    return OK;
}

int isRationnelValid(Rationnel r)
{
    return r.den != 0;
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

Rationnel productRationnel(Rationnel r1, Rationnel r2)
{
    Rationnel r;
    r.num = r1.num * r2.num;
    r.den = r1.den * r2.den;

    simplify(&r);
    return r;
}

Rationnel powRationnel(Rationnel x, int power)
{
    Rationnel ret = {1, 1};
    for (int i = 0; i < power; i++)
    {
        ret = productRationnel(ret, x);
    }
    return ret;
}