#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "utn.h"

int obtenerEspacioLibre(EPersona Personas[],int longitud)
{
    int i;
    for(i=0;i < longitud; i++)
    {
        if(Personas[i].estado == 0)
        {
            return i;
        }
    }
    return -1;
}


int buscarPorDni(EPersona lista[],int longitud, int dni)
{
    int i;
    for(i=0;i<longitud;i++)
    {
        if(lista[i].dni == dni)
        {
            return i;
        }
    }
    return -1;
}


/**
 * \brief Inicializa el status en un array
 * \param arrayAviones Es el array en el cual buscar
 * \param cantidadDeElementos Indica la longitud del array
 * \param valor Es el valor que se asignara a status
 * \return -
 *
 */

void inicializarArrayPersonas(EPersona Personas[],int cantidadDeElementos,int valor)
{
    int i;

    for(i=0;i < cantidadDeElementos; i++)
    {
        Personas[i].estado = valor;
    }
}



/**
 * \brief Carga los valores
 * \param  Es el array de Aviones
 * \param freePlaceIndex Indica la posicion a setear
 * \param array de X
 * \param  Dni
 * \return -
 *
 */
void setX(EPersona Persona[],int freePlaceIndex, char nombre[],int dni, int edad)
{
    strcpy(Persona[freePlaceIndex].nombre,nombre);
    Persona[freePlaceIndex].dni = dni;
    Persona[freePlaceIndex].edad = edad;
    Persona[freePlaceIndex].estado = 1;
}


/**
 * \brief Ordena el array
 * \param ArrayX Es el array en el cual buscar
 * \param arrayLenght Indica la longitud del array
 * \return /
 *
 */
void order(EPersona Persona[],int arrayLenght)
{
    EPersona arrayAux;
    int i,j;

    for(i=0; i < arrayLenght - 1; i++)
    {
        if(Persona[i].estado == 0)
        {
            continue;
        }
        for(j=i+1; j < arrayLenght; j++)
        {
            if(Persona[j].estado == 0)
            {
                continue;
            }
            if(strcmp(Persona[j].nombre,Persona[i].nombre)<0)
            {
                arrayAux = Persona[j];
                Persona[j] = Persona[i];
                Persona[i] = arrayAux;
            }
        }
    }
}



void ListarArray(EPersona Persona[],int arrayLenght)
{
    int i;

    printf("\n| EDAD  |  NOMBRE |   DNI |  ");
    for(i=0;i < arrayLenght; i++)
    {
        if(Persona[i].estado != 0)
        {
            printf("\n| %6d  | %-40s | %5d |",Persona[i].edad,Persona[i].nombre,Persona[i].dni);
        }
    }

}




/**
*\brief Imprime por pantalla un grafico segun las edades
*\param lista Array de estructura EPersona
*\param size Tamaño del array
*\return ---
*
*/
void graficoEdades(EPersona lista[],int size)
{
    int i,contMenores=0,adultos=0,mayores=0,max;
    for(i=0;i<size;i++)
    {
        if(lista[i].estado != 0 && lista[i].edad <= 18)
        {
            contMenores++;
        }
        if(lista[i].estado != 0 && lista[i].edad > 18 && lista[i].edad <= 35)
        {
            adultos++;
        }
        if(lista[i].estado != 0 && lista[i].edad >35)
        {
            mayores++;
        }
    }



    if(contMenores > adultos && contMenores > mayores)
    {
        max = contMenores;
    }
    else if(adultos > mayores)
        max = adultos;
    else
        max = mayores;



    for(i=max;i>0;i--)
    {
       if(i <= contMenores)
       {
           printf("  *");
       }

       if(i <= adultos)
       {
           printf("\t  *");
       }
       else
       {
           printf("\t");
       }

       if(i <= mayores)
       {
           printf("\t *");
       }

       printf("\n");
    }
    printf(" <18 \t18-35\t>35\n");
}
