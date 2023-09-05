#include <stdio.h>
#include <stdlib.h>

int factorial(int numero);
int ptencia(int base, int potencia);
int cargarArreglo(int arreglo[], int dim);
void mostrarArregloRE(int arreglo[], int i ,int validos);
void mostrarArregloREINV(int arreglo[],int i ,  int validos);

int main()
{

    int arreglo[30];

    int total = factorial(10);
    printf("El factorial es: %d\n", total);

    total = ptencia(6, 10);
    printf("La potencia es: %d", total);

    int validos = cargarArreglo(arreglo, 20);
    /*mostrarArregloRE(arreglo, 0, validos);
    printf("\n\n");
    mostrarArregloREINV(arreglo, validos-1, 0);*/

    capicuaRE(arreglo, 0, validos);

    if (capicuaRE(arreglo, validos, 0)){
        printf("es capicua");
    } else {
    printf("no es capicua");
    }


}

int factorial(int numero)
{

    int rta;

    if(numero == 0){

        rta = 1;

    }else{

    rta = numero * factorial(numero-1);

    }

    return rta;
}

int ptencia (int base, int potencia)
{

    int rta;

    if(potencia == 0){

        rta = 1;
    }else
    {

    rta = base * ptencia(base, potencia-1);
    }

    return rta;
}

int cargarArreglo(int arreglo[], int dim)
{

    int i = 0;
    char letra = 's';

    while(i < dim && letra == 's')
        {

        printf("Ingresa un valor al arreglo: ");
        fflush(stdin);
        scanf("%d", &arreglo[i]);

        printf("Ingresa 's' para contirnuar");
        fflush(stdin);
        scanf("%c", &letra);

        i++;
    }

    return i;
}

void mostrarArregloRE(int arreglo[],int i ,  int validos)
{

    if(i == validos-1){

        printf("| %d |", arreglo[i]);


    }else{

        printf("| %d |", arreglo[i]);
        mostrarArregloRE(arreglo, i+1, validos);

    }
}


void mostrarArregloREINV(int arreglo[],int i ,  int validos)
{

    if(i == 0){

        printf("| %d |", arreglo[i]);


    }else{

        printf("| %d |", arreglo[i]);
        mostrarArregloREINV(arreglo, i-1, validos);

    }
}

int capicuaRE (int arreglo[],int i , int validos)
{
    if (i>=validos){
        return 1;//es capicua
    }

    if(arreglo[i] == arreglo[validos-1-i]){

     return capicuaRE(arreglo, i+1, validos);

    }else{


    return 0;
    }

}
