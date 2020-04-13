#ifndef RATIONNEL_H
#define RATIONNEL_H

typedef struct
{
    int num;
    int den;
} Rationnel;

void printRationnelFrac(Rationnel r);
void printRationnel(Rationnel r);
int inputRationnelFrac(Rationnel *ret);
int isRationnelValid(Rationnel r);
int pgcd(int a, int b);
void simplify(Rationnel *r);
Rationnel sumRationnel(Rationnel r1, Rationnel r2);
Rationnel productRationnel(Rationnel r1, Rationnel r2);
Rationnel powRationnel(Rationnel x, int power);

#endif