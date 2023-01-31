#include <stdio.h>
#include <math.h>
#include <windows.h>

#define printf __mingw_printf

double d = 149.6*1E6; //Variable global de la distancia al sol en Km, numero real en notacion exponencial

int main()
{
    SetConsoleCP(1252);
    SetConsoleOutputCP(1252);
    double v;
    int res;
    do
    {
        printf("Introduce velocidad en Km/h: ");
        res = scanf("%lf",&v);//El primer campo es el formato y el segundo la dirección de memoria
        if (res!=1)
            printf("Formato incorrecto ...\n");
        while(getchar()!='\n');//Conviene limpiar el buffer cuando queramos leer una variable, ya que si no es posible que se siga leyendo el buffer de la variable anteriormente introducida antes de leer lo nuevo introducido
    }
    while(res!=1);
    printf("Velocidad %.2lf Km/h\n",v);
    printf("Distancia %.2lf Km\n",d);//El .2 sirve para que solo imprima dos decimales, el lf para indicar large float

    long double horas = (long double)d/v;//Estas variables son el mismo dato expresado de distinta manera LE HEMOS TENIDO QUE HACER CASTING PORQUE ES DE UN DOUBLE A UN LONG DOUBLE
    long double dias = horas/24;
    long double anyos = dias/365;
    long double minutos = horas*60;
    long double segundos = minutos*60;
    printf("Segundos: %Lg\n",segundos);//El especificador de formato g lo que hace es imprimir en formato con punto decimal o exponencial dependiendo de cual es más corto.
    printf("Minutos: %Lg\n",minutos);
    printf("Horas: %Lg\n",horas);
    printf("Dias: %Lg\n",dias);
    printf("Años: %Lg\n",anyos);//Ahora vamos a utilizar otras variables para expresar en formato años,días,horas,minutos,segundos (Todos suman el tiempo total)
    long double a = floorl(anyos);//floor es una función para convertir un float al entero más pequeño cercano a este
    long double d = floorl((anyos-a)*365);//Al cambiar a long double floor pasa a ser floorl, y %g pasa a ser %Lg AL USAR d DE NUEVO HEMOS ENMASCARADO LA VARIABLE d GLOBAL.
    long double h = floorl((((anyos-a)*365)-d)*24);
    long double m = floorl((((((anyos-a)*365)-d)*24)-h)*60);
    long double s = floorl((((((((anyos-a)*365)-d)*24)-h)*60)-m)*60);//Se puede hacer como lo hizo el profesor ya que tiene en cuenta el tiempo que no se puede expresar en unidades grandes y lo pasa a una mas pequeña
    //long double a = floorl(anyos);
    //long double d = floorl((anyos-floorl(anyos))*365);
    //long double h = floorl((dias-floorl(dias))*24);
    //long double m = floorl((horas-floorl(horas))*60);
    //long double s = floorl((minutos-floorl(minutos))*60);
    printf("%Lg años, %Lg dias, %Lg horas, %Lg minutos, %Lg segundos",a,d,h,m,s);
    return 0;
}
