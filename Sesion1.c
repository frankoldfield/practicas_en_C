#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//#include <windows.h> Esto no funciona ahora mismo porque no estamos en windows, estamos en linux

    int main ()//Esta función con el return 0 es la estructura básica de un programa en c
    {
            //SetConsoleCP(1252); //Para leer acentos
            //SetConsoleOutputCP(1252); //Para imprimir acentos
            printf("Hola!!!");
            printf("¿Cómo te llamas? ");
            char nombre[100];
            scanf("%s",nombre);//Lo que leamos tiene tipo string (primer campo) y va a la variable nombre (segundo campo)
            printf("Encantado de conocerte %s.\n", nombre); // El %s hace referencia a que el siguiente campo será un string que irá embebido en la posición en la que está %s
            printf("Esto pensando un número del 1 al 10. A ver si lo averiguas... \n");
            srand(time(NULL));//Le metemos como semilla al randomizador la variable del tiempo
            int miNumero = 1+rand()%(10); //rand genera un número entre 0 y 2^8, podemos hacerle una transformación a este rango inf+rand(sup-inf+1) (fórmula para cambiar el rango de rand)
            int numero;
            int intentos = 0;
            do
            {
                printf("El número es: ");
                scanf("%d",&numero); //Le ponemos & para pasarle la dirección de memoria en vez del nombre de la variable, que en este caso es lo que necesita scanf
                if (miNumero<numero)
                    printf("Mi número es menor.\n");
                if (miNumero>numero)
                    printf("Mi número es mayor.\n");
                intentos++; //Incrementamos en 1 el número de intentos
            }while(miNumero!=numero);
            printf("Lo averiguaste en %d intentos.\n", intentos);
            //system("pause");//Llamada para hacer una pausa, no funciona porque estamos en linux
            return 0; //Si se llega aqui devolvemos el codigo de error 0 para indicar que el funcionamiento ha sido corecto
    }
