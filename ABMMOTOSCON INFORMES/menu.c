#include <stdio.h>
#include <stdlib.h>
#include "tipo.h"
#include "color.h"
#include "servicio.h"
#include "utn.h"
#include "motos.h"
#include "menu.h"
#include <ctype.h>

int menuInicio()
    {
        system("cls");
        int opcion;
        printf("TALLER DE MOTOS\n\n");
        printf("1- ALTA MOTO\n");
        printf("2- MODIFICAR MOTO\n");
        printf("3- BAJA MOTO\n");
        printf("4- LISTAR MOTOS\n");
        printf("5- LISTAR TIPOS\n");
        printf("6- LISTAR COLORES\n");
        printf("7- LISTAR SERVICIOS\n");
        printf("8- ALTA TRABAJO\n");
        printf("9- LISTAR TRABAJOS\n");
        printf("10- SALIR\n\n");
        printf("-INFORMES PREDETERMINADOS-\n");
        printf("11- LISTAR MOTOS POR COLOR\n");
        printf("12- LISTAR MOTOS POR TIPO\n");
        printf("13- LISTAR MOTOS SEPARADAS POR TIPO\n");
        printf("14- LISTAR MOTOS POR TIPO Y COLOR\n\n");
        printf("Ingrese una opcion: ");
        scanf("%d",&opcion);

        return opcion;

    }

    int menuModificarMoto()
{
    int opcion;

    printf("MENU DE MODIFICACION DE MOTOS\n\n");
    printf("1-  EDITAR COLOR\n");
    printf("2-  EDITAR CILINDRADA\n");
    printf("3-  EDITAR TIPO\n");
    printf("4-  SALIR\n\n");

    printf("Ingrese una opcion: ");
    scanf("%d",&opcion);

    return opcion;

}
