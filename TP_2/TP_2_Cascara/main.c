#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "utn.h"
#define MAX 20

int main()
{
    int indexAux;
    char seguir='s';
    int opcion=0;
    int auxEdad;
    char auxNombre[50];
    int auxDni;
    EPersona Persona[MAX];

 inicializarArrayPersonas(Persona,MAX,0);


    while(seguir=='s')
    {
        printf("1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por  nombre\n");
        printf("4- Imprimir grafico de edades\n\n");
        printf("5- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                indexAux=obtenerEspacioLibre(Persona,MAX);
                if(indexAux == -1)
                {
                    printf("\n\nNO QUEDAN LUGARES LIBRES!!!\n");
                    getChar("\n\nENTER (para continuar)");
                    break;
                }
                auxDni=getInt("Ingrese DNUI");
                auxEdad=getInt("Ingrese Edad");
                getString("Ingrese nombre", auxNombre);
                setX(Persona,indexAux,auxNombre,auxDni,auxEdad);
                break;


            case 2:
                printf("Ingrese el dni de la persona a borrar: ");
                scanf("%d",&auxDni);
                indexAux = buscarPorDni(Persona,MAX,auxDni);
                if(indexAux=-1)
                {
                    printf("Error, no encontrado");
                    break;
                }
                Persona[indexAux].estado=0;
                break;


            case 3:
                system("cls");
                order(Persona,MAX);
                ListarArray(Persona,MAX);
                system("pause");
                break;


            case 4:
                graficoEdades(Persona,MAX);
                break;


            case 5:
                seguir = 'n';
                break;
        }
    }
    return 0;
}
