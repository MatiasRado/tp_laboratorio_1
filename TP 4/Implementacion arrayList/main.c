#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "utn.h"
#include "func.h"
#include "ArrayList.h"

#define CANTIDAD 5


int main()
{
    int opcion=0;
    int matriculaAux;
    int indexAux,index2, max, i, flag=0,flag2=0;
    int tiempovueloAux, capacidadAux, horaAux, idVuelosAux;
    int j, maxModelo;
    int modeloAux;
    int comprobar,prueba;
    char fabricanteAux[50];
    char origenAux[50];
    char destinoAux[50];
    Aviones arrayAviones[CANTIDAD];
    Vuelos arrayVuelos[CANTIDAD];
    //arrayLIst
    Aviones* p1Aux;
    Aviones* Avion;
    FILE* f;

    inicializarArrayX(arrayAviones,CANTIDAD,0);
    inicializarArrayVuelos(arrayVuelos,CANTIDAD,0);

    Aviones*p0=newAviones(1,"Carlos",1,1,55);
    Aviones*p1=newAviones(2,"Ramirez",77,2,66);
    Aviones*p2=newAviones(3,"Fernando",88,3,105);

    setVuelos(arrayVuelos,1,"CH","AL",5,1,5555);
    setVuelos(arrayVuelos,2,"AL","CH",6,2,2050);
    setVuelos(arrayVuelos,3,"SS","DD",7,3,1535);


    ArrayList* lista = al_newArrayList();
    ArrayList* lista2=al_newArrayList();
    ArrayList* listaArchivo=al_newArrayList();


    lista->add(lista,p0);
    lista->add(lista,p1);
    lista->add(lista,p2);



    f = fopen("data.csv","r");
    if (f==NULL)
    {
        printf("No se abrio archivo");
    }


    while(opcion != 99)
    {
        printf(" --- MENU ---");
        opcion = getInt("\n\n--- ARRAY LIST ---\n\n 7- ADD p0\n 8- Print List\n 9- Remove\n 10- Clear\n 11- Pop\n 12- Set\n 13- Len\n 14- Contains\n 15- SubList\n 16- Clone\n 17- ContainsAll\n 18- IndexOf\n 19- isEmpty\n 20- DeleteArrayList\n 21- Push\n\n -- ARCHIVO --\n 22- GENERO+PRINT Archivo\n 23- ADD p0 a Archivo\n 24- Remuevo Elemento 10\n");
        switch(opcion)
        {
            case 1:
                indexAux=findEmptyPlace(arrayAviones,CANTIDAD);
                if(indexAux == -1)
                {
                    printf("\n\nNO QUEDAN LUGARES LIBRES!!!\n");
                    getChar("\n\nENTER (para continuar)");
                    break;
                }
                matriculaAux=getInt("Ingrese matricula");
                index2=findById(arrayAviones,CANTIDAD,matriculaAux);
                if(index2 != -1)
                {
                    printf("\n\YA SE ENCUENTRA ESA MATRICULA\n");
                    getChar("\n\nENTER (para continuar)");
                    break;
                }

                getString("Ingrese fabricante",fabricanteAux);
                fflush(stdin);
                modeloAux=getInt("Ingrese modelo");
                capacidadAux=getInt("Ingrese capacidad");
                tiempovueloAux=getInt("Ingrese autonomia");
                setX(arrayAviones,indexAux,fabricanteAux,modeloAux,matriculaAux,capacidadAux,tiempovueloAux,0);
                flag =1;
                break;

            case 2:

                if(flag==0)
                {
                    printf("Requiere alta");
                    break;
                }
                matriculaAux=getInt("Ingrese matricula a modificar");
                indexAux=findById(arrayAviones,CANTIDAD,matriculaAux);
                if(indexAux == -1)
                {
                    printf("\n\nNO SE ENCUENTRA ESA MATRICULA\n");
                    getChar("\n\nENTER (para continuar)");
                    break;
                }
                getString("Ingrese fabricante",fabricanteAux);
                fflush(stdin);
                modeloAux=getInt("Ingrese modelo");
                capacidadAux=getInt("Ingrese capacidad");
                tiempovueloAux=getInt("Ingrese autonomia");
                setX(arrayAviones,indexAux,fabricanteAux,modeloAux,matriculaAux,capacidadAux,tiempovueloAux,arrayAviones[indexAux].vuelosRealizados);
                break;


            case 3:
                matriculaAux=getInt("Ingrese matricula a borrar");
                indexAux=findById(arrayAviones,CANTIDAD,matriculaAux);
                if(indexAux == -1)
                {
                    printf("\n\nNO SE ENCUENTRA ESA MATRICULA\n");
                    getChar("\n\nENTER (para continuar)");
                    break;
                }
                arrayAviones[indexAux].status=0;
                break;


            case 4:
                index2=findEmptyVuelo(arrayVuelos,CANTIDAD);
                if(index2 == -1)
                {
                    printf("\n\nNO QUEDAN LUGARES LIBRES!!!\n");
                    getChar("\n\nENTER (para continuar)");
                    break;
                }
                matriculaAux=getInt("Ingrese matricula de avion");
                indexAux=findById(arrayAviones,CANTIDAD,matriculaAux);
                if(indexAux == -1)
                {
                    printf("\n\nNO SE ENCUENTRA ESA MATRICULA\n");
                    getChar("\n\nENTER (para continuar)");
                    break;
                }
                arrayAviones[indexAux].vuelosRealizados++;
                getString("Ingrese origen",origenAux);
                fflush(stdin);
                getString("Ingrese destino",destinoAux);
                fflush(stdin);
                idVuelosAux=getInt("Ingrese id vuelo");
                comprobar=findVueloById(arrayVuelos,CANTIDAD,idVuelosAux);
                if(comprobar != -1)
                {
                    printf("\n\nYA SE ENCUENTRA ESA ID.\n");
                    getChar("\n\nENTER (para continuar)");
                    break;
                }
                horaAux=getInt("Ingrese hora de viaje");
                setVuelos(arrayVuelos,index2,origenAux,destinoAux,idVuelosAux,matriculaAux,horaAux);
                flag2=5;
                break;


            case 5:
                if(flag2==0)
                {
                    printf("requiere alta");
                    break;
                }
                idVuelosAux=getInt("Ingrese id de Vuelo a eliminar");
                matriculaAux=getInt("Ingrese matricula a borrar");
                indexAux=findVueloById(arrayVuelos,CANTIDAD,idVuelosAux);
                if(indexAux == -1||matriculaAux !=arrayVuelos[indexAux].matriculaAvion)
                {
                    printf("\n\nERROR.\n");
                    getChar("\n\nENTER (para continuar)");
                    break;
                }
                arrayVuelos[indexAux].status=0;
                break;


            case 6:
                for(i=0;i<CANTIDAD;i++)
                {
                    if (i==0)
                    {
                        max=i;
                    }
                    if(arrayAviones[i].vuelosRealizados>max)
                    {
                        max=arrayAviones[i].vuelosRealizados;
                        matriculaAux=i;
                    }
                }
                for(i=0;i<CANTIDAD;i++)
                {
                    if(max==arrayAviones[i].vuelosRealizados)
                    {
                        printf("\nMAS VUELOS %d, AVION: %d\n\n",max,arrayAviones[i].matricula);
                    }
                }
                break;


            case 7:
                lista->add(lista,p0);
                break;


            case 8:
                for(i=0; i<lista->len(lista); i++)
                {
                    Aviones* pAux = lista->get(lista,i);
                    printf("%d) ",i);
                    printAviones(pAux);
                }
                break;


            case 9:
                printf("Ingrese Index");
                scanf("%d",&indexAux);
                if(indexAux<0||indexAux>lista->size)
                {
                    printf("\nIndex Erroneo\n");
                }
                lista->remove(lista,indexAux);
                break;


            case 10:
                lista->clear(lista);
                break;


            case 11:
                p1Aux = lista->pop(lista,1);
                printf("\nElemento pop(): %s\r\n",p1Aux->fabricante);
                break;


            case 12:
                lista->set(lista,1,p2);
                break;


            case 13:
                indexAux=lista->len(lista);
                printf("%d\n\n",indexAux);
                break;


            case 14:
                printf("\r\nContiene p0 ?\r\n");
                if(lista->contains(lista,p0))
                {
                    printf("SI");
                }
                else
                {
                    printf("NO");
                }
                break;


            case 15:
                printf("\r\nObtenemos sub-lista de 0 a 2\r\n");
                ArrayList* subLista = lista->subList(lista,0,2);
                printList(subLista);
                break;


            case 16:
                printf("Clonamos..\n");
                lista2 = lista->clone(lista);
                printList(lista2);
                break;


            case 17:
                printf("\r\nLista clonada contiene lista?:");
                indexAux=(lista->containsAll(lista,lista2));
                if(indexAux==1)
                {
                    printf("Si\n\n");
                }
                else
                {
                    printf("No\n\n");
                }
                break;


            case 18:
                printf("\r\n\r\nPosicion de p2:");
                indexAux = lista->indexOf(lista,p2);
                printf("%d\r\n",indexAux);
                break;

            case 19:
                indexAux=lista->isEmpty(lista);
                if(indexAux==0)
                {
                    printf("\nContiene Elementos");
                }
                else
                {
                    printf("\nEsta Vacia");
                }
                break;


            case 20:
                al_deleteArrayList(lista);
                break;


            case 21:
                lista->push(lista,0,p0);
                break;

            case 22:
                par(f, listaArchivo);
                break;

            case 23:
                listaArchivo->add(listaArchivo,p0);
                break;

            case 24:
                listaArchivo->remove(listaArchivo,10);
                break;

        }
        system("PAUSE");
    }
}
