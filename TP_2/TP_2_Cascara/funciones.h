

typedef struct
{
    char nombre[50];
    int edad;
    int estado;
    int dni;

}EPersona;

/**
 * Obtiene el primer indice libre del array.
 * @param lista el array se pasa como parametro.
 * @return el primer indice disponible
 */
int obtenerEspacioLibre(EPersona lista[], int longitud);

/**
 * Obtiene el indice que coincide con el dni pasado por parametro.
 * @param lista el array se pasa como parametro.
 * @param dni el dni a ser buscado en el array.
 * @return el indice en donde se encuentra el elemento que coincide con el parametro dni
 */
int buscarPorDni(EPersona lista[],int longitud, int dni);



void inicializarArrayPersonas(EPersona Personas[],int cantidadDeElementos,int valor);
void setX(EPersona Persona[],int freePlaceIndex, char nombre[],int dni, int edad);
void ListarArray(EPersona Persona[],int arrayLenght);
void graficoEdades(EPersona lista[],int size);
