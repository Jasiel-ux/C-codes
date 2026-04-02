#include <math.h>
#include <stdio.h>
#include <string.h>
/*funciones sin paso de parametros
Jasiel D
*/
float suma()
{
    float a,b,c,R1;
    a=25.5;
    b=90.45456456;
    c=3.141516;
    R1=a+b+c;
    printf("a=%f, b=%f, c=%f \n",a,b,c);
    printf("el resultado de su suma es: %f \n\n", R1);
    return 0;
}

float resta()
{
    float a,b,c,R1,R;
    a=25.5;
    b=90.45456456;
    c=3.141516;
    R1=a-b-c;
    printf("a=%f, b=%f, c=%f \n",a,b,c);

    return R1;
}



int main()
{
    float modificado;
    suma();
    printf("el resultado de su resta es: %f \n\n", resta());
    modificado=5+resta();
    printf("modificado %f \n",modificado);

    return 0;
}
