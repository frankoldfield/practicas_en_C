#include <stdio.h>
#include <math.h>
#include <windows.h>

#define printf __mingw_printf
double d = 384400;
int res;

int main()
{
   double v1;
   double v2;
   printf("Introduzca la velocidad del vehículo que va de la tierra a la luna en Km/h: \n");
   res = scanf("%f",&v1);
   if (res!=1)
            printf("Formato incorrecto ...\n");
   while(getchar()!='\n');
   printf("Introduzca la velocidad del vehículo que va de la luna a la tierra en Km/h: \n");
   res = scanf("%f",&v2);
   if (res!=1)
            printf("Formato incorrecto ...\n");
   while(getchar()!='\n');
   double tiempo = d/(v1+v2);
   printf("El tiempo que tardan en encontrarse es de : %g horas\n",tiempo);

    return 0;
}
