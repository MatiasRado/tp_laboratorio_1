#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "utn.h"
#include "func.h"
#include "ArrayList.h"

#define CANTIDAD 5


/**
 * \brief Inicializa el status en un array
 * \param arrayAviones Es el array en el cual buscar
 * \param cantidadDeElementos Indica la longitud del array
 * \param valor Es el valor que se asignara a status
 * \return -
 *
 */

void inicializarArrayX(Aviones arrayAviones[],int cantidadDeElementos,int valor)
{
    int i;
    for(i=0;i < cantidadDeElementos; i++)
    {
        arrayAviones[i].status = valor;
        arrayAviones[i].vuelosRealizados=0;
    }
}


/**
 * \brief Carga los valores
 * \param  Es el array de Aviones
 * \param freePlaceIndex Indica la posicion a setear
 * \param array de X
 * \param  Id
 * \return -
 *
 */

void setX(Aviones arrayAviones[],int freePlaceIndex, char fabAux[],int modeloAux, int matriculaAux, int capacidadAux, int tiempovueloAux, int vuelosRealizados)
{
    strcpy(arrayAviones[freePlaceIndex].fabricante,fabAux);
    arrayAviones[freePlaceIndex].modelo = modeloAux;
    arrayAviones[freePlaceIndex].matricula = matriculaAux;
    arrayAviones[freePlaceIndex].capacidad = capacidadAux;
    arrayAviones[freePlaceIndex].Tiempovuelo = tiempovueloAux;
    arrayAviones[freePlaceIndex].status = 1;
    arrayAviones[freePlaceIndex].vuelosRealizados = vuelosRealizados;
}



/**
 * \brief Muestra por pantalla
 * \param Array Es el array de libros
 * \param arrayLenght Indica la longitud del array
 * \return -
 */

void ListarArray(Aviones arrayAviones[],int arrayLenght)
{
    int i;

    printf("\n| MODELO  |  FABRICANTE |   MATRICULA |  ");
    for(i=0;i < arrayLenght; i++)
    {
        if(arrayAviones[i].status != 0)
        {
            printf("\n| %2d  | %-40s | %5d |",arrayAviones[i].modelo,arrayAviones[i].fabricante,arrayAviones[i].matricula);
        }
    }

}


/**
 * \brief Busca la primer ocurrencia  mediante su codigo
 * \param authorArray Es el array en el cual buscar
 * \param arrayLenght Indica la longitud del array
 * \param authorIdAux Es el id que se busca
 * \return Si no hay ocurrencia (-1) y si la hay la posicion de la misma (i)
 *
 */

int findById(Aviones arrayAviones[],int arrayLenght,int id)
{
    int i;

    for(i=0;i < arrayLenght; i++)
    {
        if(arrayAviones[i].matricula == id && arrayAviones[i].status == 1)
        {
            return i;
        }
    }
    return -1;
}



/**
 * \brief Busca el primer lugar no utilizado en el array
 * \param authorArray Es el array en el cual buscar
 * \param arrayLenght Indica la logitud del array
 * \return Si no hay lugares libres (-1) y si la hay la posicion del mismo (i)
 *
 */

int findEmptyPlace(Aviones arrayAviones[],int arrayLenght)
{
    int i;

    for(i=0;i < arrayLenght; i++)
    {
        if(arrayAviones[i].status == 0)
        {
            return i;
        }
    }
    return -1;
}



/**
 * \brief Busca la primer ocurrencia  mediante su nombre
 * \param authorArray Es el array en el cual buscar
 * \param arrayLenght Indica la longitud del array
 * \param authorIdAux Es el nombre que se busca
 * \return Si no hay ocurrencia (-1) y si la hay la posicion de la misma (i)
 *
 */

int findByName(Aviones* arrayAviones, int arrayLenght, char auxName[])
{
    int i;

    for(i=0;i < arrayLenght; i++)
    {
        if(strcmp(auxName,arrayAviones[i].fabricante)==0   && arrayAviones[i].status == 1)
        {
            return i;
        }
    }
    return -1;

}


/**
 * \brief Inicializa el status en un array
 * \param arrayX Es el array en el cual buscar
 * \param cantidadDeElementos Indica la longitud del array
 * \param valor Es el valor que se asignara a status
 * \return -
 *
 */

void inicializarArrayVuelos(Vuelos arrayVuelos[],int cantidadDeElementos,int valor)
{
    int i;

    for(i=0;i < cantidadDeElementos; i++)
    {
        arrayVuelos[i].status = valor;
    }
}


/**
 * \brief Carga los valores
 * \param  Es el array de X
 * \param freePlaceIndex Indica la posicion a setear
 * \param array de X
 * \param  Id
 * \return -
 *
 */

void setVuelos(Vuelos arrayVuelos[],int freePlaceIndex, char origenAux[],char destinoAux[], int id, int matriculaAvion, int hora)
{

    strcpy(arrayVuelos[freePlaceIndex].destino,destinoAux);
    strcpy(arrayVuelos[freePlaceIndex].origen,origenAux);

    arrayVuelos[freePlaceIndex].id = id;
    arrayVuelos[freePlaceIndex].matriculaAvion = matriculaAvion;
    arrayVuelos[freePlaceIndex].hora = hora;
    arrayVuelos[freePlaceIndex].status = 1;
}


/**
 * \brief Muestra por pantalla
 * \param Array Es el array de libros
 * \param arrayLenght Indica la longitud del array
 * \return -
 */

void ListarArrayVuelos(Vuelos arrayVuelos[],int arrayLenght)
{
    int i;

    printf("\n| MODELO  |  FABRICANTE |   MATRICULA |  ");
    for(i=0;i < arrayLenght; i++)
    {
        if(arrayVuelos[i].status != 0)
        {
            printf("\n| %6s  | %-40s | %5d |",arrayVuelos[i].origen,arrayVuelos[i].destino,arrayVuelos[i].hora);
        }
    }
}

/**
 * \brief Busca el primer lugar no utilizado en el array
 * \param authorArray Es el array en el cual buscar
 * \param arrayLenght Indica la logitud del array
 * \return Si no hay lugares libres (-1) y si la hay la posicion del mismo (i)
 *
 */

int findEmptyVuelo(Vuelos arrayVuelos[],int arrayLenght)
{
    int i;

    for(i=0;i < arrayLenght; i++)
    {
        if(arrayVuelos[i].status == 0)
        {
            return i;
        }
    }
    return -1;
}



/**
 * \brief Busca la primer ocurrencia  mediante su codigo
 * \param authorArray Es el array en el cual buscar
 * \param arrayLenght Indica la longitud del array
 * \param authorIdAux Es el id que se busca
 * \return Si no hay ocurrencia (-1) y si la hay la posicion de la misma (i)
 *
 */

int findVueloById(Vuelos arrayVuelos[],int arrayLenght,int id)
{
    int i;
    for(i=0;i < arrayLenght; i++)
    {
        if(arrayVuelos[i].id == id && arrayVuelos[i].status == 1)
        {
            return i;
        }
    }
    return -1;
}


/**
 * \brief Ordena el array
 * \param ArrayX Es el array en el cual buscar
 * \param arrayLenght Indica la longitud del array
 * \return /
 *
 */
void order(Vuelos arrayVuelos[],int arrayLenght)
{
    Vuelos arrayAux;
    int i,j;

    for(i=0; i < arrayLenght - 1; i++)
    {
        if(arrayVuelos[i].status == 0)
        {
            continue;
        }
        for(j=i+1; j < arrayLenght; j++)
        {
            if(arrayVuelos[j].status == 0)
            {
                continue;
            }
            if(strcmp(arrayVuelos[j].origen,arrayVuelos[i].origen)>0)
            {
                arrayAux = arrayVuelos[j];
                arrayVuelos[j] = arrayVuelos[i];
                arrayVuelos[i] = arrayAux;
            }
        }
    }
}

/**
 * \brief Lista ambos arrays
 * \param ArrayAviones Es el array en el cual buscar
  * \param ArrayVuelos Es el segundo array en el cual buscar
 * \param arrayLenght Indica la longitud del array
 * \return /
 *
 */

void ListarAvionesVuelos(Aviones arrayAviones[], Vuelos arrayVuelos[], int arrayLenght)
{   int i;
    int idAux;
    int j;

    printf("\n| PASAJEROS  |  MODELO |   ORIGEN         |   DESTINO   | HORARIO  ");
    for(i=0;i < arrayLenght; i++)
    {
        if(arrayVuelos[i].status != 0)
        {
            idAux=arrayVuelos[i].matriculaAvion;
            for(j=0;j < arrayLenght; j++)
            {
                if(arrayAviones[j].matricula == idAux && arrayAviones[j].status == 1)
                {
                    printf("\n | %6d  | %6d  |  | %12s  | %-12s | %5d |",arrayAviones[j].capacidad,arrayAviones[j].modelo,arrayVuelos[i].origen,arrayVuelos[i].destino,arrayVuelos[i].hora);
                }
                if(arrayAviones[j].matricula == idAux && arrayAviones[j].status == 0)
                {
                    printf("\n | ELIMINADO  | ELIMINADO  |  | %12s  | %-12s | %5d |",arrayVuelos[i].origen,arrayVuelos[i].destino,arrayVuelos[i].hora);
                }
            }
        }
    }
}


/** \brief Imprime los aviones
 *
 * \param Array de Aviones
 * \return /
 *
 */

void printAviones(Aviones* p)
{
    printf("Modelo:%d Fabricante:%s\r\n",p->modelo,p->fabricante);
}




/** \brief Set this employee the values recived as parameters
 *
 * \param pEmployee employee*
 * \param id int
 * \param name[] char
 * \param lastName[] char
 * \param salary float
 * \param sector int
 * \return int Return (-1) if Error [NULL pointer] - (0) if Ok
 *
 */
Aviones* newAviones(int matriculaAux, char fabAux[],int modeloAux,float capacidadAux,int tiempovueloAux)
{
    Aviones* returnAux = NULL;
    Aviones* newAvion = malloc(sizeof(Aviones));

    if(newAvion != NULL)
    {
        newAvion->matricula = matriculaAux;
        strcpy(newAvion->fabricante,fabAux);
        newAvion->modelo = modeloAux;
        newAvion->capacidad = capacidadAux;
        newAvion->Tiempovuelo = tiempovueloAux;
        newAvion->status = 0;
        returnAux = newAvion;
    }

    return returnAux;

}


/** \brief Imprimo Lista
 *
 * \param ArrayList
 * \return /
 *
 */

void printList(ArrayList* lista)
{
    int i;
    for(i=0; i<lista->len(lista); i++)
    {
        void* pAux = lista->get(lista,i);
        printf("%d) ",i);
        printAviones(pAux);
   }
}




int par(FILE *f, ArrayList* lista)
{
    Aviones *Aux;
    char id[50];
    char fabAux[50];
    char modeloAux[50];
    char capacidadAux[50];
    char tiempoVueloAux[50];
    int aux1,aux2,aux3,aux4;


    while(!feof(f))
    {
        fscanf(f, "%[^,],%[^,],%[^,],%[^,]%s\n", id, fabAux, modeloAux,capacidadAux,tiempoVueloAux);

        aux1=atoi(id);
        aux2=atoi(tiempoVueloAux);
        aux3=atoi(modeloAux);
        aux4=atoi(capacidadAux);
        Aux = newAviones(aux1,fabAux,aux3,aux4,aux2);
        lista->add(lista,Aux);
    }

    printList(lista);
    return 0;
}
