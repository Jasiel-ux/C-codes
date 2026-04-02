#include <math.h>
#include <stdio.h>
/*jerarquias de operaciones

jerarquias.c

Jasiel D

*/
int main()
{
    int a,b,c,d,e;
    float R1,R2,R3,R4,R5;
    a=80;
    b=90;
    c=100;
    d=70;
    e=60;
    R1=a*b+c-d/e;
    R2=(a*b)+c-(d/e);
    R3=pow(a,2)-2;
    R4=a/pow(b,c)/d;
    R5=a/pow(b,(c/d));


    printf("a=%i b=%i c=%i d=%i e=%i\n",a,b,c,d,e);
    printf("R1 '(a*b+c-d/e)'      = %f \n", R1);
    printf("R2 '(a*b)+c-(d/e)'    = %f \n", R2);
    printf("R3 '(pow(a,2)-2)'     = %f \n", R3);
    printf("R4 '(a/pow(b,c)/d)'   = %f \n", R4);
    printf("R5 '(a/pow(b,(c/d)))' = %f \n", R5);

    return 0;
}
