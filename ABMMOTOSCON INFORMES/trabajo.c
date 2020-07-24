#include <stdio.h>
#include <stdlib.h>
#include "tipo.h"
#include "color.h"
#include "servicio.h"
#include "utn.h"
#include "motos.h"
#include "menu.h"
#include "fecha.h"
#include "trabajo.h"
#include <ctype.h>
void mostrarTrabajo(eTrabajo Trabajo,eServicio vecServicio[],int tamServicio)
{
    char descripcion[20];


    if(Trabajo.isEmpty==0)
    {

     cargarDescripcionServicio(descripcion,Trabajo.idServicio,vecServicio,tamServicio);
        printf("%02d         %03d      %15s     %d/%d/%d \n",Trabajo.id,Trabajo.idMoto,descripcion,Trabajo.fecha.dia,Trabajo.fecha.mes,Trabajo.fecha.anio);
    }


}

void mostrarTrabajos(eTrabajo vecTrabajo[],int tamTrabajo,eServicio vecServicio[],int tamServicio) {


 int flag=0;


    printf("   |---------------------Listado de Trabajos----------------------|\n");
    printf("IDTRABAJO IDMOTO         SERVICIO         FECHA     \n");
    for(int i=0; i<tamTrabajo; i++)
    {
        if(vecTrabajo[i].isEmpty==0)
        {
            mostrarTrabajo(vecTrabajo[i],vecServicio,tamServicio);
            flag=1;
        }
    }
    if(flag==0)
    {
        printf("\n   |---------No hay trabajos que listar-----------\n");
    }




}

void inicializarTrabajos(eTrabajo vecTrabajo[],int tamTrabajo)
{

    for(int i=0; i<tamTrabajo; i++)
    {

        vecTrabajo[i].isEmpty=1;
    }

}


int buscarTrabajoLibre(eTrabajo vecTrabajo[],int tamTrabajo)
{

    int indice=-1;
    for(int i=0; i<tamTrabajo; i++)
    {

        if(vecTrabajo[i].isEmpty == 1)
        {

            indice=i;
            break;
        }
    }
    return indice;
}








int altaTrabajo(int proximoIdTrabajo,eTrabajo vecTrabajo[],int tamTrabajo,eMoto vecMoto[],int tamMoto,eServicio vecServicio[],int tamServicio,eTipo vecTipo[],int tamTipo,eColor vecColor[],int tamColor)
{

    int retorno=0;
    eTrabajo auxTrabajo;
    int indice;
    int indiceTrabajo;
    int id;
    int idServicio;



    printf("***ALTA DE TRABAJOS***\n\n");
    mostrarMotos(vecMoto,tamMoto,vecTipo,tamTipo,vecColor,tamColor);
    printf("Ingrese ID de la moto para el trabajo: ");
    scanf("%d",&id);


    indice=buscarIdMoto(id, vecMoto, tamMoto);
    indiceTrabajo=buscarTrabajoLibre(vecTrabajo, tamTrabajo);
    if(indiceTrabajo==-1)
    {

        printf("No se pueden agregar mas trabajos.\n\n");
    }
    else
    {
        if(indice==-1)
        {
            printf("Id invalido\n");

        }
        else
        {
            do{
            auxTrabajo.id=proximoIdTrabajo;
            auxTrabajo.idMoto=id;

            mostrarServicios(vecServicio,tamServicio);
            printf("Ingrese el ID del servicio deseado:");
            scanf("%d",&idServicio);
            auxTrabajo.idServicio=idServicio;
            }while(idServicio<20000||idServicio>20003);
            /*while(idServicio<20000&&idServicio>20003)
            {
                system("cls");
                mostrarServicios(vecServicio,tamServicio);
                printf("ERROR. Ingrese un ID de servicio valido:");
                scanf("%d",&idServicio);

            }*/






                printf("Ingrese una fecha para el trabajo.\n");
                printf("Ingrese el dia:");
                scanf("%d",&auxTrabajo.fecha.dia);

                printf("Ingrese el mes:");
                scanf("%d",&auxTrabajo.fecha.mes);

                printf("Ingrese el anio:");
                scanf("%d",&auxTrabajo.fecha.anio);

                //printf("%d",validarFecha(auxTrabajo.fecha.dia,auxTrabajo.fecha.mes,auxTrabajo.fecha.anio));
                while(validarFecha(auxTrabajo.fecha.dia,auxTrabajo.fecha.mes,auxTrabajo.fecha.anio)==-1)
                {

                    printf("Fecha invalida.\n");
                    printf("Ingrese el dia:");
                    scanf("%d",&auxTrabajo.fecha.dia);

                    printf("Ingrese el mes:");
                    scanf("%d",&auxTrabajo.fecha.mes);

                    printf("Ingrese el anio:");
                    scanf("%d",&auxTrabajo.fecha.anio);

                }



            auxTrabajo.isEmpty=0;
            vecTrabajo[indiceTrabajo]=auxTrabajo;

            retorno=1;
        }

    }

    printf("\n\n");

    return retorno;
}


int agregarTrabajoAlArray(eTrabajo vecTrabajo[],int tamVecTrabajo,eTrabajo trabajoParaAgregarAlArray){

 int indice=buscarTrabajoLibre(vecTrabajo,tamVecTrabajo);
    int retorno=0;
    eTrabajo auxTrabajo;

    if(indice==-1)
    {

        printf("Sistema lleno.\n");

    }
    else
    {

        auxTrabajo.id=trabajoParaAgregarAlArray.id;
        auxTrabajo.idMoto=trabajoParaAgregarAlArray.idMoto;
        auxTrabajo.idServicio=trabajoParaAgregarAlArray.idServicio;
        auxTrabajo.fecha=trabajoParaAgregarAlArray.fecha;
        auxTrabajo.isEmpty=0;

        vecTrabajo[indice]=auxTrabajo;
        retorno = 1;
    }


    return retorno;


}

int buscarUltimoIdTrabajo(eTrabajo vecTrabajo[],int tamTrabajo){
int auxId=-1;

 int indice;
    for(int i=0; i<tamTrabajo; i++)
    {

        if(vecTrabajo[i].isEmpty == 1)
        {

            indice=i-1;
            auxId=vecTrabajo[indice].id+1;
            break;

        }
    }

return auxId;
}

