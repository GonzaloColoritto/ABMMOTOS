#include <stdio.h>
#include <stdlib.h>
#include "tipo.h"
#include "color.h"
#include "servicio.h"
#include <string.h>
#include <ctype.h>
void mostrarServicio(eServicio servicio)
{


    printf("%05d %20s   %03d\n",servicio.id,servicio.descripcion,servicio.precio);


}

void mostrarServicios(eServicio vecServicio[], int tamServicio)
{
    printf("ID                SERVICIO   $$$\n");
    printf("--------------------------------\n");
    for(int i=0; i<tamServicio; i++)
    {

        mostrarServicio(vecServicio[i]);
    }


}
int cargarDescripcionServicio(char descripcion[],int id,eServicio servicio[],int tamServicio)
{
    int retorno=0;
    for(int i=0; i<tamServicio; i++)
    {
        if(servicio[i].id==id)
        {
            strcpy(descripcion,servicio[i].descripcion);
            retorno=1;
        }
    }
    return retorno;
}

