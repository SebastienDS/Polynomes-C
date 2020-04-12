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
    printPolynome(sum);

    ret_value = EXIT_SUCCESS;

    destroyPolynome(&sum);
free_p2:
    destroyPolynome(&p2);
free_p1:
    destroyPolynome(&p1);
end:
    return ret_value;
}
