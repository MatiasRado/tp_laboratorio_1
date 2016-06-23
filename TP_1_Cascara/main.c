#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    int numero1, numero2;
    int resultado;
    float resultado2;
    int opcion=0;
    int flagA=0;
    int flagB=0;

    do
    {
        system("cls");
        printf("   TP1 CALCULADORA \n");

        if (flagA==1)
            printf(" 1- Ingresar 1er operando (A=%d)\n", numero1);
        else
            printf(" 1- Ingresar 1er operando (A= Sin asignar)\n");

        if (flagB==1)
            printf(" 2- Ingresar 2do operando (B=%d)\n", numero2);
        else
            printf(" 2- Ingresar 2do operando (B= Sin asignar)\n");

        printf(" 3- Calclular la suma (A+B)\n");
        printf(" 4- Calcular la resta (A-B)\n");
        printf(" 5- Calcular la division(A/B)\n");
        printf(" 6- Calcular la multiplicacion (A*B)\n");
        printf(" 7- Calcular el factorial(A!)\n");
        printf(" 8- Calcular todas las operaciones\n");
        printf(" 9- Salir\n\n");
        fflush(stdin);
        scanf("%d", &opcion);

        switch (opcion)
        {
        case 1:
            numero1=ingresoNumero();
            flagA=1;
            break;

        case 2:
            numero2=ingresoNumero();
            flagB=1;
            break;

        case 3:
            if(flagA&&flagB)
            {
                resultado=suma(numero1,numero2);
                printf("%d \n\n",resultado);
            }else
            {
                printf("Debe ingresar los numeros \n\n\n");
            }
            system("pause");
            break;

        case 4:
            if (flagA&&flagB)
            {
                resultado=resta(numero1,numero2);
                printf("%d \n\n",resultado);
            }else
            {
               printf("Debe ingresar los numeros \n\n\n");
            }
            system("pause");
            break;

        case 5:
            if (flagA&&flagB)
            {
                resultado2=division(numero1, numero2);
                printf("%f \n\n",resultado2);
            }else
            {
               printf("Debe ingresar los numeros \n\n\n");
            }
            system("pause");
            break;

        case 6:
            if(flagA&&flagB)
            {
                resultado=multiplicacion(numero1, numero2);
                printf("%d \n\n", resultado);
            }else
            {
                printf("Debe ingresar los numeros \n\n\n");
            }
            system("pause");
            break;

        case 7:
            if(flagA)
            { if(numero1<1)
            { printf("Error");
            }
                else {
                    resultado=factorial(numero1);
                    printf("%d\n\n", resultado);
                     }

            }else
            {
               printf("Debe ingresar los numeros \n\n\n");
            }
            system("pause");
            break;

        case 8:
            if(flagA&&flagB)
            {
                suma(numero1,numero2);
                resta(numero1, numero2);
                division(numero1,numero2);
                multiplicacion(numero1,numero2);
                factorial(numero1);
            }else
            {
                printf("Debe ingresar los numeros \n\n\n");
            }
            system("pause");
            break;

        case 9:
            printf("-------\n");
            break;

        default:
            printf("Opcion incorrecta, vuelva a intentar\n");
            system("pause");
            break;
        }
    } while(opcion!=9);
    return 0;
}
