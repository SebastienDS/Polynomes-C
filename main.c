#include <stdio.h>
#include <stdlib.h>
#include "Rationnel.h"
#include "Polynome.h"

int main()
{
    int ret_value = EXIT_FAILURE;
    Polynome p1;
    Polynome p2;
    Polynome sum;
    Polynome product;
    Polynome derived;
    Polynome primitive;
    Polynome elevatedPolynome;

    // Exemple de saisie de polynome : 1/1x^6+0/1x^5+0/1x^4+0/1x^3+0/1x^2+1/1x+1/1
    if (inputPolynome(&p1)) 
    {
        goto end;
    }
    if (inputPolynome(&p2))
    {
        goto free_p1;
    }
    if (sumPolynome(p1, p2, &sum))
    {
        goto free_p2;
    }
    printf("\nsomme: ");
    printPolynome(sum);
    printf("\n\n");


    if (productPolynome(p1, p2, &product))
    {
        goto free_sum;
    }
    printf("produit: ");
    printPolynome(product);
    printf("\n\n");


    Rationnel x;
    printf("f(x) = ");
    printPolynome(p1);
    printf("\nx (fraction) = ");
    if (inputRationnelFrac(&x))
    {
        goto free_product;
    }
    Rationnel y = evalPolynome(p1, x);
    printf("f(");
    printRationnelFrac(x);
    printf(") = ");
    printRationnelFrac(y);
    printf("\n\n");


    if (derivedPolynome(p1, &derived)) 
    {
        goto free_product;
    }
    printf("f'(x) = ");
    printPolynome(derived);
    printf("\n\n");

    if (primitivePolynome(p1, &primitive)) 
    {
        goto free_derived;
    }
    printf("F(x) = ");
    printPolynome(primitive);
    printf("\n\n");


    Rationnel a, b;
    printf("Integral pour f(x) = ");
    printPolynome(p1);
    printf("\na (fraction) = ");
    if (inputRationnelFrac(&a))
    {
        goto free_primitive;
    }
    printf("b (fraction) = ");
    if (inputRationnelFrac(&b))
    {
        goto free_primitive;
    }

    Rationnel integral = integralPolynome(p1, a, b);
    printf("Integrale : ");
    printRationnelFrac(integral);
    printf("\n\n");

    int n;
    printf("Elevation du polynome: ");
    printPolynome(p1);
    printf(" a la puissance: ");

    if (scanf("%d", &n) != 1) {
        goto free_primitive;
    }

    if (elevationPowerN(p1, n, &elevatedPolynome))
    {
        goto free_primitive;
    }

    printf("Polynome apres elevation: ");
    printPolynome(elevatedPolynome);
    printf("\n\n");

    ret_value = EXIT_SUCCESS;

free_elevatedPolynome:
    destroyPolynome(&elevatedPolynome);
free_primitive:
    destroyPolynome(&primitive);
free_derived:
    destroyPolynome(&derived);
free_product:
    destroyPolynome(&product);
free_sum:
    destroyPolynome(&sum);
free_p2:
    destroyPolynome(&p2);
free_p1:
    destroyPolynome(&p1);
end:
    return ret_value;
}
