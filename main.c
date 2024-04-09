#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <string.h>
#include "pila.h"

#define ESC 27
#define DIM 10

void ejercicios();
void menuEjercicios();
void arreglo1();
void arregloPto1();
void arregloPto2();
void arregloPto9();
void arregloPto10();
void arreglosClase9();
void muestraArreglo(int a[], int v);
void pasaPar(int a[], int v, Pila* p);
void invertirArreglo (int a[], int v);
void intercambio (int* origen, int* destino);
void ordenarArreglo (int a[], int v);
void strings();
int cargaArregloRandom(int a[], int dim);
int cargaArregloUsuario(int a[], int dim, int v);
int cuentaDigitos(int nro);
int cuentaIngresos(int a[], int v);
int esCapicua(int a[], int v);
int buscaElementos (int a[], int v, int dato);
int buscaMenorPosicion (int a[], int v, int inicio);


int main ()
{
    srand(time(NULL));
    ejercicios();

    return 0;
}
void ejercicios()
{
    char opcion;

    do
    {
        system("cls");
        menuEjercicios();


        printf("\n\n\n");
        opcion = getch();
        printf("ESC para salir o cualquier tecla para continuar.\n");
        system("cls");


        switch(opcion)
        {
        case '0':
            arreglo1();
            break;
        case '1':
            arregloPto1();
            break;
        case '2':
            arregloPto2();
            break;
        case '9':
            arregloPto9();
            break;
        case '10':
            arregloPto10();
            break;
        case '5':
            strings();
            break;
        case '6':
            arreglosClase9();
            break;
        }
        system("pause");
    }
    while(opcion!=27);

}
void menuEjercicios()
{
    printf("Ingrese caso:\n\n\n");
    printf("\n 0 - Ejercicios Arreglo 1");
    printf("\n 1 - Ejercicios Arreglo Pto 1");
    printf("\n 2 - Ejercicios Arreglo Pto 2");
    printf("\n 9 - Ejercicios Arreglo Pto 9");
    printf("\n 10 - Ejercicios Arreglo Pto 10");
    printf("\n 5 - Ejercicios Strings");
    printf("\n 6 - Ejercicios Clase 9-4");

}
void arreglo1()
{
    int notas [DIM];
    int validosNotas = 0;
    validosNotas = cargaArregloUsuario(notas, DIM, validosNotas);
    printf("\n Listado de notas\n");
    muestraArreglo(notas, validosNotas);
    validosNotas = cargaArregloUsuario(notas, DIM, validosNotas);
    printf("\n Listado de notas2\n");
    muestraArreglo(notas, validosNotas);
    printf("\n El nro 0 tiene %d", cuentaDigitos(0));
    printf("\n El nro 1999 tiene %d", cuentaDigitos(1999));
    printf("\n El nro 3000000 tiene %d", cuentaDigitos(3000000));
}
void arregloPto1()
{
    int datos [DIM];
    int numeros = 0;
    int cantidad = 0;

    numeros = cargaArregloUsuario(datos, DIM, numeros);
    printf("\n Datos ingresados: \n");
    muestraArreglo(datos, numeros);

    cantidad = cuentaIngresos(datos, numeros);
    printf("\n La cantidad de datos ingresados es: %d .\n", cantidad);

}
void arregloPto2()
{
    int datos [DIM];
    int numeros = 0;
    Pila par;
    inicpila (&par);

    numeros = cargaArregloRandom(datos, numeros);
    printf("\n Datos ingresados: \n");
    muestraArreglo(datos, numeros);

    pasaPar(datos, numeros, &par);
    mostrar(&par);

}
void arregloPto9()
{
    int datos [DIM];
    int numeros = 0;
    int flag = 0;

    numeros = cargaArregloUsuario(datos, DIM, numeros);
    printf("\n Datos ingresados: \n");
    muestraArreglo(datos, numeros);

    if (flag == 1){
        printf("\n Los datos no son capicua\n");
    } else {
    printf("\n Los datos son capicua\n");
    }

}
void arregloPto10 ()
{
    int datos [DIM];
    int numeros = 0;

    numeros = cargaArregloUsuario(datos, DIM, numeros);
    printf("\n Datos ingresados: \n");
    muestraArreglo(datos, numeros);

    printf("\n");

    invertirArreglo(datos, numeros);
    printf("\n Los datos invertidos son: \n");
    muestraArreglo(datos, numeros);

}
void arreglosClase9()
{
    int datos [DIM];
    int numeros = 0;

    numeros = cargaArregloRandom(datos, numeros);
    printf("\n Datos ingresados: \n");
    muestraArreglo(datos, numeros);

    ordenarArreglo(datos, numeros);
    muestraArreglo(datos, numeros);


}
void strings ()
{
    char letras []= {'a', 'b', 'c', 'd','\0'};
    char saludo []= "Hello World";
    char apellido [50]="Garcia";

    printf("\nLetras: %s\n", letras);
    printf("\nSaludo: %s\n", saludo);
}
void muestraArreglo(int a[], int v)
{
    for(int i = 0; i < v; i++)
    {
        if (i % 10 == 0)
        {
            printf("\n");
        }
        printf("%5d | ", a[i]);
    }
}
void pasaPar(int a[], int v, Pila* p)
{
   for(int i = 0; i <= v; i++){
        if (a[i] % 2 == 0){
            apilar(p, a[i]);
        }
    }

//    while (int i = 0; i < v && i < 50){
//        if(a[i]%2 == 0){
//            apilar(p, a[i]);
//        }
//        i++;
//    }
}
void invertirArreglo (int a[], int v)
{
    int inicio = 0;
    int fin = v - 1;

    while (inicio < fin){
        intercambio(&a[inicio], &a[fin]);
        inicio++;
        fin--;
    }

}
void intercambio (int* origen, int* destino)
{
    int aux = *origen;
    *origen = *destino;
    *destino = aux;
}
void ordenarArreglo (int a[], int v)
{
    int inicio = 0;
    int i = 1;
    int posicionMenor = 0;

    posicionMenor = buscaMenorPosicion (a[i], v, inicio);
    intercambio(a[i], a[posicionMenor]);
    muestraArreglo(a[i], v);
}

int cargaArregloRandom(int a[], int dim)//vacios p/ poder cargar de dif dimension
{
    int i;
    for (i = 0; i < 50; i++)
    {
        a[i] = rand()%10;
    }
    return i;
}
int cargaArregloUsuario(int a[], int dim, int v)
{
    char opcion;
    int numero;

    while( v < dim && opcion != ESC)
    {
        printf("\n Ingrese un dato:");
        scanf("%d", &a[v]);
        v++;

        printf("ESC para salir o cualquier tecla para continuar.");
        opcion = getch();
        system("cls");
    }
    return v;
}
int cuentaDigitos(int nro)
{
    int digitos =0;
    if (nro=0)
    {
        digitos = 1;
    }
    while (nro > 0)
    {
        digitos ++;
        nro = nro/10;
    }
    return digitos;
}
int cuentaIngresos(int a[], int v)
{
    int suma;

    for (int i = 0; i < v; i++){
        suma = suma + a[i];
    }
    return suma;
}
int esCapicua(int a[], int v)
{
    int flag = 1;
    int inicio = 0;
    int fin = v - 1;

    while (inicio < fin && flag == 1 ){
        if (a[inicio] == a[fin]){
            inicio++;
            fin--;
        } else {
            flag = 0;}
    }
    return flag;
}
int buscaElementos (int a[], int v, int dato)
{
    int flag = -1;
    int i = 0;

    while(i < v && flag == -1){
        if (a[i] == dato){
            flag = i;
        } else {
            i++;
        }
    }
    return flag;
}
int buscaMenorPosicion (int a[], int v, int inicio)
{
    int i = 0;
    int posicionMenor = 0;
    int inic = 1;

    for ( i = 0; i < v; i++){
        if (a[i] < a[posicionMenor]){
            posicionMenor = i;
            inic++;
        }
    }

    return posicionMenor;
}
