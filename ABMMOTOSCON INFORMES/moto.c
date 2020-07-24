#include <stdio.h>
#include <stdlib.h>
#include "tipo.h"
#include "color.h"
#include "servicio.h"
#include "motos.h"
#include "utn.h"
#include "menu.h"
#include <ctype.h>
#include <string.h>

void inicializarMotos(eMoto vec[],int tam)
{
    for(int i=0; i<tam; i++)
    {
        vec[i].isEmpty=1;
    }
}

int cargarDescripcionTipo(char descripcion[],int id,eTipo tipos[],int tamTipos)
{
    int retorno=0;
    for(int i=0; i<tamTipos; i++)
    {
        if(tipos[i].id==id)
        {
            strcpy(descripcion,tipos[i].descripcion);
            retorno=1;
        }
    }
    return retorno;
}

int cargarDescripcionColor(char descripcion[],int id,eColor colores[],int tamColores)
{
    int retorno=0;
    for(int i=0; i<tamColores; i++)
    {
        if(colores[i].id==id)
        {
            strcpy(descripcion,colores[i].descripcion);
            retorno=1;
        }
    }
    return retorno;
}
void mostrarMoto(eMoto moto,eTipo tipos[],int tamTipos,eColor colores[],int tamColores)
{
    if(moto.isEmpty==0)
    {
        char descripcionTipo[20];
        char descripcionColor[20];
        cargarDescripcionTipo(descripcionTipo,moto.idTipo,tipos,tamTipos);
        cargarDescripcionColor(descripcionColor,moto.idColor,colores,tamColores);

        printf("    |%04d|    %10s    %10s     %10s      %d  \n",moto.id,moto.marca,descripcionTipo,descripcionColor,moto.cilindrada);

    }

}


void mostrarMotos(eMoto vecMoto[],int tamMotos,eTipo tipos[],int tamTipos,eColor colores[],int tamColores)
{

    int flag=0;


    printf("    ---------------------Listado Motos------------------------------\n");
    printf("    | ID |         Marca         Tipo           Color     Cilindrada\n");
    printf("    |----|----------------------------------------------------------\n");
    for(int i=0; i<tamMotos; i++)
    {
        if(vecMoto[i].isEmpty==0)
        {
            mostrarMoto(vecMoto[i],tipos,tamTipos,colores,tamColores);
            flag=1;
        }
    }
    if(flag==0)
    {
        printf("\n   |---------No hay motos que listar-----------\n");
    }

}

int buscarLibre(eMoto vec[], int tam)
{

    int indice=-1;
    for(int i=0; i<tam; i++)
    {

        if(vec[i].isEmpty == 1)
        {

            indice=i;
            break;
        }
    }
    return indice;
}

int altaMoto(int proximoId, eMoto vecMoto[],int tamMotos,eServicio vecServicio[],int tamServicio, eTipo vecTipo[],int tamTipo,eColor vecColor[],int tamColor)
{

    int retorno=0;
    int indice = buscarLibre(vecMoto,tamMotos);
    eMoto auxMoto;
    if(indice==-1)
    {

        printf("SISTEMA LLENO.\n\n");
    }
    else
    {

        auxMoto.id=proximoId;

        // printf("MARCAS DISPONIBLES: HONDA - SUZUKI - BMW - MOTOMEL\n");
        //utn_getName("Ingrese marca de la moto:","ERROR. Intente una vez mas",0,20,1,auxMoto.marca);

        printf("|-ALTA DE MOTOS-|\n\n");

        do
        {

            printf("Ingrese marca de la moto:");
            fflush(stdin);
            gets(auxMoto.marca);
            strupr(auxMoto.marca);
        }
        while(strlen(auxMoto.marca)>=20);

        system("cls");

        printf("-SELECCIONE EL ID DEL TIPO DE LA MOTO-\n\n");
        mostrarTipos(vecTipo,tamTipo);

        printf("Ingrese el ID del tipo: ");
        scanf("%d",&auxMoto.idTipo);
        while(auxMoto.idTipo<1000||auxMoto.idTipo>1003)
        {
            printf("ERROR. ID invalido.\n");
            printf("Ingrese el ID del tipo nuevamente: ");
            scanf("%d",&auxMoto.idTipo);
        }
        system("cls");

        printf("-SELECCIONE EL ID DEL COLOR DE LA MOTO-\n\n");
        mostrarColores(vecColor,tamColor);
        printf("Ingrese el ID del color: ");
        scanf("%d",&auxMoto.idColor);
        while(auxMoto.idColor<10000||auxMoto.idColor>10004)
        {
            printf("ERROR. ID invalido.\n");
            printf("Ingrese el ID del color nuevamente: ");
            scanf("%d",&auxMoto.idColor);
        }
        system("cls");

        do
        {
            printf("CILINDRADAS DISPONIBLES\n\n");
            printf("50 125 500 600 750\n");
            printf("Ingrese la cilindrada deseada: ");
            scanf("%d",&auxMoto.cilindrada);

        }
        while(auxMoto.cilindrada!=50 && auxMoto.cilindrada!=125 && auxMoto.cilindrada!=500 && auxMoto.cilindrada!=600 && auxMoto.cilindrada!=750 );


        auxMoto.isEmpty=0;

        vecMoto[indice]=auxMoto;

        retorno=1;
    }


    return retorno;
}
int buscarIdTipo(int id,eTipo tipos[],int tam)
{
    int indice = -1;

    for (int i=0; i<tam; i++)
    {
        if (tipos[i].id==id)
        {
            indice=i;
            break;
        }
    }


    return indice;
}

int buscarIdColor(int id,eColor color[],int tam)
{
    int indice = -1;

    for (int i=0; i<tam; i++)
    {
        if (color[i].id==id)
        {
            indice=i;
            break;
        }
    }


    return indice;
}
int buscarIdMoto(int id,eMoto moto[],int tam)
{
    int indice = -1;

    for (int i=0; i<tam; i++)
    {
        if (moto[i].id==id)
        {
            indice=i;
            break;
        }
    }


    return indice;
}

int modificarMoto(eMoto vecMoto[],int tamMotos,eColor vecColor[],int tamColor,eTipo vecTipo[],int tamTipo)
{

    int paso=0;
    int id;
    int indice;
    char confirmacion;

    system("cls");

    printf("***MODIFICAR MOTO***\n\n");
    mostrarMotos(vecMoto,tamMotos,vecTipo,tamTipo,vecColor,tamColor);
    printf("Ingrese ID de la moto a modificar: ");
    scanf("%d",&id);


    indice=buscarIdMoto(id, vecMoto, tamMotos);

    if(indice==-1)
    {

        printf("No hay una moto con el ID %d.\n\n",id);

    }
    else
    {
        mostrarMoto(vecMoto[indice],vecTipo,tamTipo,vecColor,tamColor);
        printf("Desea modificar esta moto? S/N.");
        fflush(stdin);
        scanf("%c",&confirmacion);
    }


    if(confirmacion=='s')
    {

        switch(menuModificarMoto())
        {

        case 1:
            printf("-SELECCIONE EL ID DEL COLOR DE LA MOTO-\n\n");
            mostrarColores(vecColor,tamColor);
            printf("Ingrese el ID del color: ");
            scanf("%d",&vecMoto[indice].idColor);
            while(vecMoto[indice].idColor<10000||vecMoto[indice].idColor>10004)
            {
                printf("ERROR. ID invalido.\n");
                printf("Ingrese el ID del color nuevamente: ");
                scanf("%d",&vecMoto[indice].idColor);
            }
            system("cls");
            paso=1;
            break;

        case 2:
            do
            {
                printf("CILINDRADAS DISPONIBLES\n\n");
                printf("50 125 500 600 750\n");
                printf("Ingrese la cilindrada deseada: ");
                scanf("%d",&vecMoto[indice].cilindrada);

            }
            while(vecMoto[indice].cilindrada!=50 && vecMoto[indice].cilindrada!=125 && vecMoto[indice].cilindrada!=500 && vecMoto[indice].cilindrada!=600 && vecMoto[indice].cilindrada!=750 );
            paso=1;
            break;
        case 3:
            system("cls");

            printf("-SELECCIONE EL ID DEL TIPO DE LA MOTO-\n\n");
            mostrarTipos(vecTipo,tamTipo);

            printf("Ingrese el ID del tipo: ");
            scanf("%d",&vecMoto[indice].idTipo);
            while(vecMoto[indice].idTipo<1000||vecMoto[indice].idTipo>1003)
            {
                printf("ERROR. ID invalido.\n");
                printf("Ingrese el ID del tipo nuevamente: ");
                scanf("%d",&vecMoto[indice].idTipo);
            }
            break;
        case 4:
            printf("Edicion cancelada\n");

            break;
        }

    }

    return paso;
}

int bajaMoto(eMoto vecMoto[],int tamMoto,eColor vecColor[],int tamColor,eTipo vecTipo[],int tamTipo)
{

    int paso=0;
    int id;
    int indice;
    char confirmacion;

    printf("Ingrese ID de la moto a eliminar: ");
    scanf("%d",&id);


    indice=buscarIdMoto(id, vecMoto, tamMoto);

    if(indice==-1)
    {

        printf("No hay una moto con el ID %d.\n\n",id);

    }
    else
    {
        mostrarMoto(vecMoto[indice],vecTipo,tamTipo,vecColor,tamColor);
        printf("Desea eliminar esta moto? S/N.");
        fflush(stdin);
        scanf("%c",&confirmacion);
        if(confirmacion=='s')
        {

            vecMoto[indice].isEmpty=1;
            paso=1;
        }
        else
        {
            printf("Baja cancelada");
        }
    }


    return paso;
}


int agregarMotoAlArray(eMoto vecMoto[],int tamVec,eMoto motoParaAgregar)
{

    int indice=buscarLibre(vecMoto,tamVec);
    int retorno=0;
    eMoto auxMoto;

    if(indice==-1)
    {

        printf("Sistema lleno.\n");

    }
    else
    {

        auxMoto.id=motoParaAgregar.id;
        strcpy(auxMoto.marca,motoParaAgregar.marca);
        auxMoto.idTipo=motoParaAgregar.idTipo;
        auxMoto.idColor=motoParaAgregar.idColor;
        auxMoto.cilindrada=motoParaAgregar.cilindrada;
        auxMoto.isEmpty=0;

        vecMoto[indice]=auxMoto;
        retorno = 1;
    }


    return retorno;
}

int buscarUltimoId(eMoto vecMoto[],int tamMoto)
{
    int auxId=-1;

    int indice;
    for(int i=0; i<tamMoto; i++)
    {

        if(vecMoto[i].isEmpty == 1)
        {

            indice=i-1;
            auxId=vecMoto[indice].id+1;
            break;

        }
    }

    return auxId;
}
int mostrarMotoPorColor(eMoto vecMoto[],int tamMoto,eColor vecColor[],int tamColor,eTipo vecTipos[],int tamTipos)
{
    int retorno=-1;
    int id;

    printf("-SELECCIONE EL ID DEL COLOR DE LA MOTO A MOSTRAR-\n\n");
    mostrarColores(vecColor,tamColor);
    printf("Ingrese el ID del color: ");
    scanf("%d",&id);
    while(id<10000||id>10004)
    {
        printf("ERROR. ID invalido.\n");
        printf("Ingrese el ID del color nuevamente: ");
        scanf("%d",&id);
    }

    for(int i=0; i<tamMoto; i++)
    {

        if(vecMoto[i].idColor==id&&vecMoto[i].isEmpty==0)
        {

            mostrarMoto(vecMoto[i],vecTipos,tamTipos,vecColor,tamColor);
            retorno=1;
        }
    }
    return retorno;
}


int mostrarMotoPorTipo(eMoto vecMoto[],int tamMoto,eColor vecColor[],int tamColor,eTipo vecTipos[],int tamTipos)
{
    int retorno=-1;
    int id;

    printf("-SELECCIONE EL ID DEL TIPO DE LA MOTO A MOSTRAR-\n\n");
    mostrarTipos(vecTipos,tamTipos);
    printf("Ingrese el ID del tipo: ");
    scanf("%d",&id);
    while(id<1000||id>10003)
    {
        printf("ERROR. ID invalido.\n");
        printf("Ingrese el ID del tipo nuevamente: ");
        scanf("%d",&id);
    }

    for(int i=0; i<tamMoto; i++)
    {

        if(vecMoto[i].idTipo==id&&vecMoto[i].isEmpty==0)
        {

            mostrarMoto(vecMoto[i],vecTipos,tamTipos,vecColor,tamColor);
            retorno=1;
        }
    }
    return retorno;
}

/*
int mostrarMotoPorCilindrada(eMoto vecMoto[],int tamMoto,eColor vecColor[],int tamColor,eTipo vecTipos[],int tamTipos){
int retorno=-1;
int id;


 for(int i=0;i<tamMoto;i++){


 }
 return retorno;
}*/



void mostrarMotosSeparadasPorTipo(eMoto vecMoto[],int tamMotos,eTipo tipos[],int tamTipos,eColor colores[],int tamColores)
{


    int flag;

    printf("   |--------------------------Listado Motos por Tipo-----------------------------|\n");

    for(int t=0; t<tamTipos; t++)
    {
        flag=0;
        printf("    MOTOS DEL TIPO %s \n",tipos[t].descripcion);
        // printf("     id        Marca      Tipo          Color      Cilindrada     \n");

        for(int e=0; e<tamMotos; e++)
        {
            if(vecMoto[e].isEmpty==0 && vecMoto[e].idTipo==tipos[t].id)
            {
                mostrarMoto(vecMoto[e],tipos,tamTipos,colores,tamColores);
                flag=1;
            }

        }
        if(flag==0)
        {
            printf("\n   |---------No hay motos de este tipo que listar-----------\n\n");
        }
    }




}
int mostrarMotoPorColorTipo(eMoto vecMoto[],int tamMotos,eTipo tipos[],int tamTipos,eColor colores[],int tamColores)
{

    int idColor;
    int idTipo;
    int retorno=-1;


    printf("-SELECCIONE EL ID DEL COLOR DE LA MOTO-\n\n");
    mostrarColores(colores,tamColores);
    printf("Ingrese el ID del color: ");
    scanf("%d",&idColor);
    while(idColor<10000||idColor>10004)
    {
        printf("ERROR. ID invalido.\n");
        printf("Ingrese el ID del color nuevamente: ");
        scanf("%d",&idColor);
    }

    printf("-SELECCIONE EL ID DEL TIPO DE LA MOTO-\n\n");
    mostrarTipos(tipos,tamTipos);

    printf("Ingrese el ID del tipo: ");
    scanf("%d",&idTipo);
    while(idTipo<1000||idTipo>1003)
    {
        printf("ERROR. ID invalido.\n");
        printf("Ingrese el ID del tipo nuevamente: ");
        scanf("%d",&idTipo);
    }

    for(int i=0; i<tamMotos; i++)
    {


        if(vecMoto[i].idColor==idColor&&vecMoto[i].idTipo==idTipo)
        {

            mostrarMoto(vecMoto[i],tipos,tamTipos,colores,tamColores);
            retorno=1;
        }

    }
    return retorno;
}


