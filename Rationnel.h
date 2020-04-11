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

#endif