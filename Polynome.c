#include <stdio.h>
#include <stdlib.h>
#include "Polynome.h"

void printPolynome(Polynome p)
{
    int x = p.degre;
    for (int i = p.degre; i > -1; i--)
    {
        printRationnelFrac(p.poly[i]);
        if (x == 1)
        {
            printf("x");
        }
        else if (x > 0)
        {
            printf("x^%d", x);
        }
        x--;
    }
}

int _initPolynome(int degre, Polynome* ret) 
{
    Polynome p = {degre, malloc(degre * sizeof(Rationnel))};
    if (p.poly == NULL)
    {
        printf("L'allocation a echoué");
        return 1;
    }
    *ret = p;
    return 0;
}

int initPolynome(int degre, Rationnel *poly, Polynome *ret)
{
    if (_initPolynome(degre, ret)) 
    {
        return 1;
    }
    for (int i = 0; i < degre + 1; i++)
    {
        ret->poly[i] = poly[i];
    }
    return 0;
}

void destroyPolynome(Polynome *p)
{
    free(p->poly);
    p->poly = NULL;
}

int inputPolynome(Polynome *ret)
{
    // return: 0: good, 1: fail malloc, 2: fail input degre
    int degre;
    printf("Entrer le degre de votre polynome : ");
    if (scanf("%d", &degre) != 1)
    {
        printf("Vous n'avez pas saisi d'entier\n");
        return 2;
    }
    if (degre <= 0)
    {
        printf("Vous n'avez pas saisi de degre valide\n");
        return 2;
    }
    Rationnel poly[degre + 1];

    printf("Entrer les %d coefficients de votre polynome (fraction): \n", degre + 1);
    for (int i = degre; i > -1; i--)
    {
        poly[i] = inputRationnelFrac();
    }

    if (initPolynome(degre, poly, ret))
    {
        return 1;
    }
    printf("Vous avez saisi le polynome : ");
    printPolynome(*ret);
    printf("\n");
    return 0;
}

int sumPolynome(Polynome p1, Polynome p2, Polynome *ret)
{
    int max = (p1.degre > p2.degre) ? p1.degre : p2.degre;
    Rationnel poly[max + 1];
    for (int i = 0; i < max + 1; i++)
    {
        Rationnel sum = {0, 1};
        if (p1.degre >= i)
        {
            sum = sumRationnel(sum, p1.poly[i]);
        }
        if (p2.degre >= i)
        {
            sum = sumRationnel(sum, p2.poly[i]);
        }
        poly[i] = sum;
    }
    if (initPolynome(max, poly, ret))
    {
        return 1;
    }
    return 0;
}

int productPolynome(Polynome p1, Polynome p2, Polynome* ret) 
{
    int max = (p1.degre > p2.degre) ? p1.degre : p2.degre;
    if (_initPolynome(max, ret)) 
    {
        return 1;
    }

    for (int i_p1 = 0; i_p1 < p1.degre + 1; i_p1++)
    {
        for (int i_p2 = 0; i_p2 < p2.degre + 1; i_p2++)
        {
            ret->poly[i_p1 + i_p2] = sumRationnel(ret->poly[i_p1 + i_p2], productRationnel(p1.poly[i_p1], p1.poly[i_p1]));
        } 
    }
    return 0;
}
