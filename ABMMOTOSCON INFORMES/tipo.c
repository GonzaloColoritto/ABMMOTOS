#include <stdio.h>
#include <stdlib.h>
#include "tipo.h"
#include "string.h"
#include "ctype.h"

/*int buscarLibre(eTipo vec[], int tam)
{

    int indice;
    for(int i=0; i<tam; i++)
    {

        if(vec[i].isEmpty == 1)
        {

            indice=i;
            break;
        }
    }
    return indice;
}*/

void mostrarTipo(eTipo tipo)
{


    printf("%d %s \n",tipo.id,tipo.descripcion);


}

void mostrarTipos(eTipo vecTipo[], int tamTipo)
{

    for(int i=0; i<tamTipo; i++)
    {

        mostrarTipo(vecTipo[i]);
    }


}


eTipo crearTipo(int idTipo,char descripcionTipo[20])
{

    eTipo auxTipo;

    auxTipo.id=idTipo;
    strcpy(auxTipo.descripcion,descripcionTipo);
    auxTipo.isEmpty=0;


    return auxTipo;
}

void inicializarTipos(eTipo vecTipo[],int tamTipo)
{

    for(int i=0; i<tamTipo; i++)
    {

        vecTipo[i].isEmpty = 1;
    }

}


/*void agregarTipo(eTipo vecTipo[],int tamTipo,eTipo tipo)
{

    int indice=buscarLibre(vecTipo,tamTipo);
    vecTipo[indice]=tipo;

}*/
