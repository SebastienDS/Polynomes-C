#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Polynome.h"
#include "code.h"

void printPolynome(Polynome p)
{
    int x = p.degre;
    for (int i = p.degre; i > -1; i--)
    {
        if (p.poly[i].num != 0)
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
        }
        x--;
    }
}

int _initPolynome(int degre, Polynome *ret)
{
    Polynome p = {degre, malloc((degre + 1) * sizeof(Rationnel))};
    if (p.poly == NULL)
    {
        printf("L'allocation a echoué");
        return FAIL_MALLOC;
    }
    for (int i = 0; i < degre + 1; i++)
    {
        p.poly[i] = (Rationnel){0, 1};
    }
    *ret = p;
    return OK;
}

int initPolynome(int degre, Rationnel *poly, Polynome *ret)
{
    if (_initPolynome(degre, ret))
    {
        return FAIL_MALLOC;
    }
    for (int i = 0; i < degre + 1; i++)
    {
        ret->poly[i] = poly[i];
    }
    return OK;
}

void destroyPolynome(Polynome *p)
{
    free(p->poly);
    p->poly = NULL;
}

int inputDegre(int *degre)
{
    printf("Entrer le degre de votre polynome : ");
    if (scanf("%d", degre) != 1)
    {
        printf("Vous n'avez pas saisi d'entier\n");
        return FAIL_INPUT;
    }
    if (*degre <= 0)
    {
        printf("Vous n'avez pas saisi de degre valide\n");
        return FAIL;
    }
    return OK;
}

int inputPolynome1By1(Polynome *ret)
{
    int degre;
    if (inputDegre(&degre))
    {
        return FAIL;
    }

    Rationnel poly[degre + 1];

    printf("Entrer les %d coefficients de votre polynome (fraction): \n", degre + 1);
    for (int i = degre; i > -1; i--)
    {
        Rationnel ret;
        if (inputRationnelFrac(&ret))
        {
            return FAIL_INPUT;
        }
        poly[i] = ret;
    }

    if (initPolynome(degre, poly, ret))
    {
        return FAIL_MALLOC;
    }
    printf("Vous avez saisi le polynome : ");
    printPolynome(*ret);
    printf("\n");
    return OK;
}

int inputPolynome(Polynome *ret)
{
    int degre;
    if (inputDegre(&degre))
    {
        return FAIL;
    }

    Rationnel poly[degre + 1];

    printf("Entrer le polynome avec des fractions valides : \nf(x) = ");
    for (int i = degre; i > -1; i--)
    {
        Rationnel r;
        char* str = "%d/%d";
        char dest[10];

        strcpy(dest, str);
        if (i > 1)
        {
            strcat(dest, "x^");
            dest[7] = i + '0';
            dest[8] = '\0';
        }
        else if (i == 1) {
            strcat(dest, "x");
        }
        
        if (scanf(dest, &r.num, &r.den) != 2) 
        {
            printf("Vous n'avez pas saisi de fraction valide\n");   
            return FAIL_INPUT;
        }
        if (!isRationnelValid(r))
        {
            return FAIL;
        }
        simplify(&r);
        poly[i] = r;
    }

    if (initPolynome(degre, poly, ret))
    {
        return FAIL_MALLOC;
    }
    printf("Vous avez saisi le polynome : ");
    printPolynome(*ret);
    printf("\n");
    return OK;
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
        return FAIL_MALLOC;
    }
    return OK;
}

int productPolynome(Polynome p1, Polynome p2, Polynome *ret)
{
    int max = p1.degre + p2.degre;
    if (_initPolynome(max, ret))
    {
        return FAIL_MALLOC;
    }

    for (int i_p1 = 0; i_p1 < p1.degre + 1; i_p1++)
    {
        for (int i_p2 = 0; i_p2 < p2.degre + 1; i_p2++)
        {
            ret->poly[i_p1 + i_p2] = sumRationnel(ret->poly[i_p1 + i_p2], productRationnel(p1.poly[i_p1], p2.poly[i_p2]));
        }
    }
    return OK;
}

Rationnel evalPolynome(Polynome p, Rationnel x)
{
    Rationnel ret = p.poly[0];
    for (int i = 1; i < p.degre + 1; i++)
    {
        ret = sumRationnel(ret, productRationnel(p.poly[i], powRationnel(x, i)));
    }
    return ret;
}

int derivedPolynome(Polynome p, Polynome *ret)
{
    if (_initPolynome(p.degre - 1, ret))
    {
        return FAIL_MALLOC;
    }

    for (int i = 0; i < p.degre; i++)
    {
        ret->poly[i] = productRationnel((Rationnel){i + 1, 1}, p.poly[i + 1]);
    }
    return OK;
}

int primitivePolynome(Polynome p, Polynome *ret)
{
    if (_initPolynome(p.degre + 1, ret))
    {
        return FAIL_MALLOC;
    }

    for (int i = p.degre; i > -1; i--)
    {
        ret->poly[i + 1] = productRationnel(p.poly[i], (Rationnel){1, i + 1});
    }
    return OK;
}

Rationnel integralPolynome(Polynome p, Rationnel a, Rationnel b)
{
    Polynome primitive;
    if (primitivePolynome(p, &primitive))
    {
        return (Rationnel){0, 1}; 
    }

    Rationnel result = sumRationnel(evalPolynome(primitive, b), productRationnel(evalPolynome(primitive, a), (Rationnel){-1, 1}));

    destroyPolynome(&primitive);
    return result;
}