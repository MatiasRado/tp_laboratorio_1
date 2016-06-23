#include "ArrayList.h"

typedef struct{
    char fabricante[50];
    int modelo;
    int matricula;
    int capacidad;
    int Tiempovuelo;
    int status; // activo 1 inactivo 0
    int vuelosRealizados;
}Aviones;


typedef struct{
int id;
int matriculaAvion;
int hora;
char origen[100];
char destino[100];
int status; // activo 1 inactivo 0
}Vuelos;

//Aviones
void inicializarArrayX(Aviones arrayAviones[],int cantidadDeElementos,int valor);
void setX(Aviones arrayAviones[],int freePlaceIndex, char fabAux[],int modeloAux, int matriculaAux, int capacidadAux, int tiempovueloAux, int vuelosRealizados);
void ListarArray(Aviones arrayAviones[],int arrayLenght);
int findById(Aviones arrayAviones[],int arrayLenght,int id);
int findEmptyPlace(Aviones arrayAviones[],int arrayLenght);
int findByName(Aviones* arrayAviones, int arrayLenght, char auxName[]);


//vuelos
void inicializarArrayVuelos(Vuelos arrayVuelos[],int cantidadDeElementos,int valor);
void setVuelos(Vuelos arrayVuelos[],int freePlaceIndex, char origenAux[],char destinoAux[], int id, int matriculaAvion, int hora);
void ListarArrayVuelos(Vuelos arrayX[],int arrayLenght);
int findEmptyVuelo(Vuelos arrayVuelos[],int arrayLenght);
int findVueloById(Vuelos arrayVuelos[],int arrayLenght,int id);
void order(Vuelos arrayVuelos[],int arrayLenght);



//Vuelos+Aviones
void ListarAvionesVuelos(Aviones arrayX[], Vuelos arrayVuelos[], int arrayLenght);

//ArrayList
void printAviones(Aviones* p);
Aviones* newAviones(int matriculaAux, char fabAux[],int modeloAux,float capacidadAux,int tiempovueloAux);
void printList(ArrayList* lista);
int par(FILE *f, ArrayList* lista);

