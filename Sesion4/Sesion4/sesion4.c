#include <stdio.h>
#include <windows.h>
#define STRING_SIZE 100
void imprimir_array(int v[], int n)
{
    for (int i=0;i<n;i++)
    {
     printf("v[%d]=%d\n",i,v[i]);
    }
}

void imprimir_matriz(int filas, int columnas, int matriz[][columnas])
{
    for (int i=0;i<filas;i++)
    {
        for (int j=0;j<columnas;j++)
            printf("matriz[%d][%d]=%d\n",i,j,matriz[i][j]);
    }
}

int busca_matriz(int filas, int columnas, int matriz[][columnas], int a)
{
    for (int i=0;i<filas;i++)
        for (int j=0;j<columnas;j++)
            if (matriz[i][j]==a)
                return 1;
    return 0;
}

int busca_array(int v[],int n, int a)
{
    for (int i=0;i<n;i++)
        if (v[i]==a)
            return 1;
    return 0;
}

int busca_array_v1(int v[],int n, int a)
{
    int encontrado = 0;
    int i = 0;
    while (i<n && !encontrado)
    {
        if (v[i]==a)
            encontrado = 1;
        i++;
    }
    return encontrado;
}

int busca_array_v2(int v[],int n, int a)
{
        int i = 0;
        while (i<n && v[i]!=a)
            i++;
        return (i<n);
}

int iguales(char s1[],char s2[])
{
    int i = 0;
    while(s1[i]!='\0' && s2[i]!='\0' && s1[i]==s2[i])
        i++;
    return (s1[i]==s2[i]);
}

int main()
{

    SetConsoleCP(1252);
    SetConsoleOutputCP(1252);
    printf("Introduce tamaño del array (>=0): ");
    int n;
    scanf("%d",&n);
    int v[n];
    for (int i=0;i<n;i++)
    {
        printf("Introduce elemento %d del array: ",i);
        scanf("%d",&v[i]);
    }
    imprimir_array(v, n);

    printf("Introduce un elemento a buscar: ");
    int a;
    scanf("%d",&a);
    if (busca_array_v1(v,n,a))
        printf("El elemento %d existe en el array.\n",a);
    else
        printf("El elemento %d no existe en el array.\n",a);

    //matrices
    printf("Introduce número de filas (>0): ");
    int filas;
    scanf("%d",&filas);
    printf("Introduce número de columnas (>0): ");
    int columnas;
    scanf("%d",&columnas);
    int matriz[filas][columnas];
    for (int i=0;i<filas;i++)
    {
        for (int j=0;j<columnas;j++)
        {
            printf("Introduce elemento (%d,%d) de la matriz: ",i,j);
            scanf("%d",&matriz[i][j]);
        }
    }
    imprimir_matriz(filas,columnas,matriz);

    printf("Introduce un elemento a buscar: ");
    scanf("%d",&a);
    if (busca_matriz(filas,columnas,matriz,a))
        printf("El elemento %d existe en la matriz.\n",a);
    else
        printf("El elemento %d no existe en la matriz.\n",a);
    //STRINGS
    char s1[STRING_SIZE];
    char s2[STRING_SIZE];
    printf("Introduzca la primera cadena: ");
    scanf("%s",s1);
    printf("Introduzca la segunda cadena: ");
    scanf("%s",s2);
    if(iguales(s1,s2))
        printf("Las dos cadenas son iguales");
    else
        printf("Las dos cadenas son distintas");
    return 0;
    //LA FUNCIÓN QUE YA IMPLEMENTA LA COMPARACIÓN DE STRINGS ES strcomp(s1,s2)
}
