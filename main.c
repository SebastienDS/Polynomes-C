#include <stdio.h>
#include <stdlib.h>
#include "Rationnel.h"
#include "Polynome.h"
#include "code.h"

// int main()
// {
//     int ret_value = EXIT_FAILURE;
//     Polynome p1;
//     Polynome p2;
//     Polynome sum;
//     Polynome product;
//     Polynome derived;
//     Polynome primitive;
//     Polynome elevatedPolynome;

//     // Exemple de saisie de polynome degre 6: 1/1x^6+0/1x^5+0/1x^4+0/1x^3+0/1x^2+1/1x+1/1
//     if (inputPolynome(&p1)) 
//     {
//         goto end;
//     }
//     if (inputPolynome(&p2))
//     {
//         goto free_p1;
//     }
//     if (sumPolynome(p1, p2, &sum))
//     {
//         goto free_p2;
//     }
//     printf("\nsomme: ");
//     printPolynome(sum);
//     printf("\n\n");


//     if (productPolynome(p1, p2, &product))
//     {
//         goto free_sum;
//     }
//     printf("produit: ");
//     printPolynome(product);
//     printf("\n\n");


//     Rationnel x;
//     printf("f(x) = ");
//     printPolynome(p1);
//     printf("\nx (fraction) = ");
//     if (inputRationnelFrac(&x))
//     {
//         goto free_product;
//     }
//     Rationnel y = evalPolynome(p1, x);
//     printf("f(");
//     printRationnelFrac(x);
//     printf(") = ");
//     printRationnelFrac(y);
//     printf("\n\n");


//     if (derivedPolynome(p1, &derived)) 
//     {
//         goto free_product;
//     }
//     printf("f'(x) = ");
//     printPolynome(derived);
//     printf("\n\n");

//     if (primitivePolynome(p1, &primitive)) 
//     {
//         goto free_derived;
//     }
//     printf("F(x) = ");
//     printPolynome(primitive);
//     printf("\n\n");


//     Rationnel a, b;
//     printf("Integral pour f(x) = ");
//     printPolynome(p1);
//     printf("\na (fraction) = ");
//     if (inputRationnelFrac(&a))
//     {
//         goto free_primitive;
//     }
//     printf("b (fraction) = ");
//     if (inputRationnelFrac(&b))
//     {
//         goto free_primitive;
//     }

//     Rationnel integral = integralPolynome(p1, a, b);
//     printf("Integrale : ");
//     printRationnelFrac(integral);
//     printf("\n\n");

//     int n;
//     printf("Elevation du polynome: ");
//     printPolynome(p1);
//     printf(" a la puissance: ");

//     if (scanf("%d", &n) != 1) {
//         goto free_primitive;
//     }

//     if (elevationPowerN(p1, n, &elevatedPolynome))
//     {
//         goto free_primitive;
//     }

//     printf("Polynome apres elevation: ");
//     printPolynome(elevatedPolynome);
//     printf("\n\n");

//     ret_value = EXIT_SUCCESS;

// free_elevatedPolynome:
//     destroyPolynome(&elevatedPolynome);
// free_primitive:
//     destroyPolynome(&primitive);
// free_derived:
//     destroyPolynome(&derived);
// free_product:
//     destroyPolynome(&product);
// free_sum:
//     destroyPolynome(&sum);
// free_p2:
//     destroyPolynome(&p2);
// free_p1:
//     destroyPolynome(&p1);
// end:
//     return ret_value;
// }

int main() 
{
    int ret_value = OK;
    int input;
    int n;
    Rationnel x;
    Rationnel y;
    Polynome p1;
    Polynome p2;
    Polynome res;

    int nbrFree = 0;

    while (ret_value == OK)
    {
        printf("Que voulez vous faire: \n");
        printf("  0- quitter\n");
        printf("  1- addition\n");
        printf("  2- produit\n");
        printf("  3- evaluer en un point\n");
        printf("  4- deriver\n");
        printf("  5- primitive\n");
        printf("  6- integrale\n");
        printf("  7- elevation a la puissance n\n");

        if (scanf("%d", &input) != 1)
        {
            printf("Saisie incorrect !\n");
            ret_value = FAIL_INPUT;
            break;
        }

        if (input == 0)
        {
            ret_value = END;
            break;
        }
        if (input > 7 || input < 0) {
            printf("Action invalide\n");
            continue;
        }

        // Exemple de saisie de polynome degre 6: 1/1x^6+0/1x^5+0/1x^4+0/1x^3+0/1x^2+1/1x+1/1
        if (inputPolynome(&p1)) 
        {
            ret_value = FAIL;
            break;
        }
        nbrFree++;
        if (input < 3)
        {
            if (inputPolynome(&p2)) 
            {
                ret_value = FAIL;
                break;
            }
            nbrFree++;
        }

        switch (input)
        {
        case 1:
            if (sumPolynome(p1, p2, &res))
            {
                ret_value = FAIL;
                break;
            }
            printf("\nsomme: ");
            printPolynome(res);
            printf("\n\n");
            break;
        case 2:
            if (productPolynome(p1, p2, &res))
            {
                ret_value = FAIL;
                break;
            }
            printf("\nproduit: ");
            printPolynome(res);
            printf("\n\n");
            break;
        case 3:
            printf("\nx (fraction) = ");
            if (inputRationnelFrac(&x))
            {
                ret_value = FAIL;
                break;
            }
            y = evalPolynome(p1, x);
            printf("\nf(");
            printRationnelFrac(x);
            printf(") = ");
            printRationnelFrac(y);
            printf("\n\n");
            break;
        case 4:
            if (derivedPolynome(p1, &res)) 
            {
                ret_value = FAIL;
                break;
            }
            printf("\nf'(x) = ");
            printPolynome(res);
            printf("\n\n");
            break;
        case 5:
            if (primitivePolynome(p1, &res)) 
            {
                ret_value = FAIL;
                break;
            }
            printf("\nF(x) = ");
            printPolynome(res);
            printf("\n\n");
            break;
        case 6:
            printf("\na (fraction) = ");
            if (inputRationnelFrac(&x))
            {
                ret_value = FAIL;
                break;
            }
            printf("b (fraction) = ");
            if (inputRationnelFrac(&y))
            {
                ret_value = FAIL;
                break;
            }

            x = integralPolynome(p1, x, y);
            printf("\nIntegrale : ");
            printRationnelFrac(x);
            printf("\n\n");
            break;
        case 7:
            printf("elevation a la puissance: ");

            if (scanf("%d", &n) != 1) {
                ret_value = FAIL_INPUT;
                break;
            }

            if (elevationPowerN(p1, n, &res))
            {
                ret_value = FAIL;
                break;
            }

            printf("\nPolynome apres elevation: ");
            printPolynome(res);
            printf("\n\n");
            break;
        default:
            printf("Action invalide");
            break;
        }
        if (nbrFree > 0) {
            destroyPolynome(&p1);
            destroyPolynome(&res);
        } 
        if (nbrFree > 1) {
            destroyPolynome(&p2);
        }
    }

    return ret_value;
}
