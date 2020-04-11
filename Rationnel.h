#ifndef RATIONNEL_H
#define RATIONNEL_H

typedef struct
{
    int num;
    int den;
} Rationnel;

void printRationnelFrac(Rationnel r);
void printRationnel(Rationnel r);
Rationnel inputRationnelFrac();
int pgcd(int a, int b);
void simplify(Rationnel *r);
Rationnel sumRationnel(Rationnel r1, Rationnel r2);

#endif