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

Polynome initPolynome(int degre, Rationnel *poly)
{
    Polynome p = {degre, malloc(degre * sizeof(Rationnel))};
    for (int i = 0; i < degre + 1; i++)
    {
        p.poly[i] = poly[i];
    }
    return p;
}

void destroyPolynome(Polynome *p)
{
    free(p->poly);
}

Polynome inputPolynome()
{
    int degre;
    printf("Entrer le degre de votre polynome : ");
    if (scanf("%d", &degre) != 1)
    {
        printf("Vous n'avez pas saisi d'entier\n");
        exit(EXIT_FAILURE);
    }
    if (degre <= 0)
    {
        printf("Vous n'avez pas saisi de degre valide\n");
        exit(EXIT_FAILURE);
    }
    Rationnel poly[degre + 1];

    printf("Entrer les %d coefficients de votre polynome (fraction): \n", degre + 1);
    for (int i = degre; i > -1; i--)
    {
        poly[i] = inputRationnelFrac();
    }

    Polynome p = initPolynome(degre, poly);
    printf("Vous avez saisi le polynome : ");
    printPolynome(p);
    printf("\n");
    return p;
}

Polynome sumPolynome(Polynome p1, Polynome p2)
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
    return initPolynome(max, poly);
}