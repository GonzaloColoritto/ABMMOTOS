#include <stdio.h>
#include <stdlib.h>
#include "tipo.h"
#include "color.h"
#include "servicio.h"
#include "utn.h"
#include "motos.h"
#include "trabajo.h"
#include "menu.h"
#include <ctype.h>
#define TAMTIPO 4
#define TAMCOLOR 5
#define TAMSERVICIOS 4
#define TAMMOTO 10
#define TAMTRABAJO 10

int main()
{

    char seguir='s';
    char confirmacion;
    int flag=1; ///ESTA EN UNO SOLO PORQUE TENGO MOTOS HARCODEADAS SINO SE INICIALIZA EN 0
    int proximoId;
    int proximoIdTrabajo;

    eMoto vecMoto[TAMMOTO];
    eTipo vecTipos[TAMTIPO]= {{1000,"ENDURO"},{1001,"CHOPERA"},{1002,"SCOOTER"},{1003,"CICLOMOTOR"}};
    eColor vecColores[TAMCOLOR]= {{10000,"GRIS"},{10001,"NEGRO"},{10002,"BLANCO"},{10003,"AZUL"},{10004,"ROJO"}};
    eServicio vecServicios[TAMSERVICIOS]= {{20000,"Limpieza",250},{20001,"Cambio llantas",300},{20002,"Balanceo",17},{20003,"Cambio cadena",190}};
    eTrabajo vecTrabajo[TAMTRABAJO];
    /*eTipo vecTipo[TAMTIPO];
    inicializarTipos(vecTipo,TAMTIPO);
    eTipo tipoA=crearTipo(1005,"pepe");
    agregarTipo(vecTipo,TAMTIPO,tipoA);
    mostrarTipos(vecTipos,TAMTIPO);
    mostrarColores(vecColores,TAMCOLOR);
    mostrarServicios(vecServicios,TAMSERVICIOS);*/
    inicializarMotos(vecMoto,TAMMOTO);
    inicializarTrabajos(vecTrabajo,TAMTRABAJO);
    eMoto moto1= {001,"HONDA",1000,10001,125};
    eMoto moto2= {002,"SUZUKI",1002,10002,50};
    eMoto moto3= {003,"HONDA",1003,10001,500};
    eMoto moto4= {004,"BMW",1000,10001,125};
    eMoto moto5= {005,"SUZUKI",1002,10004,500};
    eMoto moto6= {006,"HONDA",1002,10003,500};
    agregarMotoAlArray(vecMoto,TAMMOTO,moto1);
    agregarMotoAlArray(vecMoto,TAMMOTO,moto2);
    agregarMotoAlArray(vecMoto,TAMMOTO,moto3);
    agregarMotoAlArray(vecMoto,TAMMOTO,moto4);
    agregarMotoAlArray(vecMoto,TAMMOTO,moto5);
    agregarMotoAlArray(vecMoto,TAMMOTO,moto6);
    proximoId=buscarUltimoId(vecMoto,TAMMOTO);
    eTrabajo trabajo1={100,1,20000,{13,12,2020}};
    eTrabajo trabajo2={101,2,20001,{15,2,2020}};
    eTrabajo trabajo3={102,2,20001,{1,1,2020}};
    eTrabajo trabajo4={103,4,20003,{3,5,2020}};
    eTrabajo trabajo5={104,6,20002,{11,10,2020}};
    agregarTrabajoAlArray(vecTrabajo,TAMTRABAJO,trabajo1);
    agregarTrabajoAlArray(vecTrabajo,TAMTRABAJO,trabajo2);
    agregarTrabajoAlArray(vecTrabajo,TAMTRABAJO,trabajo3);
    agregarTrabajoAlArray(vecTrabajo,TAMTRABAJO,trabajo4);
    agregarTrabajoAlArray(vecTrabajo,TAMTRABAJO,trabajo5);
    proximoIdTrabajo=buscarUltimoIdTrabajo(vecTrabajo,TAMTRABAJO);
    do
    {
        switch(menuInicio())
        {
        case 1:


            if(altaMoto(proximoId,vecMoto,TAMMOTO,vecServicios,TAMSERVICIOS,vecTipos,TAMTIPO,vecColores,TAMCOLOR)==1)
            {

                printf("Moto agregada con exito\n");
                proximoId++;
                flag=1;
            }
            else
            {
                printf("Error al agregar la moto.\n");
            }

            break;

        case 2:
            if(flag==1)
            {

                modificarMoto(vecMoto,TAMMOTO,vecColores,TAMCOLOR,vecTipos,TAMTIPO);
            }
            else
            {

                printf("Primero debe dar de alta una moto\n");
            }


            break;

        case 3:
            if(flag==1)
            {
                bajaMoto(vecMoto,TAMMOTO,vecColores,TAMCOLOR,vecTipos,TAMTIPO);

            }
            else
            {

                printf("Primero debe dar de alta una moto\n");
            }


            break;

        case 4:
            mostrarMotos(vecMoto,TAMMOTO,vecTipos,TAMTIPO,vecColores,TAMCOLOR);
            break;

        case 5:
            mostrarTipos(vecTipos,TAMTIPO);
            break;

        case 6:
            mostrarColores(vecColores,TAMCOLOR);
            break;

        case 7:
            mostrarServicios(vecServicios,TAMSERVICIOS);
            break;

        case 8:

            if(altaTrabajo(proximoIdTrabajo,vecTrabajo,TAMTRABAJO,vecMoto,TAMMOTO,vecServicios,TAMSERVICIOS,vecTipos,TAMTIPO,vecColores,TAMCOLOR))
            {
                proximoIdTrabajo++;
                printf("Trabajo exitoso.\n");
            }
            else
            {
                printf("Error al cargar el trabajo.-------------\n");
            }

            break;

        case 9:
            mostrarTrabajos(vecTrabajo,TAMTRABAJO,vecServicios,TAMSERVICIOS);
            break;

        case 10:



            printf(" ¿Desea salir? S/N: ");
            fflush(stdin);
            scanf("%c",&confirmacion);

            confirmacion=tolower(confirmacion);
            while(confirmacion!='n'&&confirmacion!='s')
            {
                printf("ERROR. OPCION INVALIDA\n");
                printf(" ¿Desea salir? S/N: ");
                fflush(stdin);
                scanf("%c",&confirmacion);

                confirmacion=tolower(confirmacion);
            }



            if(confirmacion=='s')
            {
                seguir = 'n';
            }
            break;

        case 11:
            if(mostrarMotoPorColor(vecMoto,TAMMOTO,vecColores,TAMCOLOR,vecTipos,TAMTIPO)==1)
            {

            }
            else
            {
                printf("No hay motos de ese color.\n");
            }
            break;
        case 12:
            if(mostrarMotoPorTipo(vecMoto,TAMMOTO,vecColores,TAMCOLOR,vecTipos,TAMTIPO)==1)
            {

            }
            else
            {
                printf("No hay motos de ese tipo.\n");
            }
            break;
        case 13:
            mostrarMotosSeparadasPorTipo(vecMoto,TAMMOTO,vecTipos,TAMTIPO,vecColores,TAMCOLOR);
            break;
        case 14:
            mostrarMotoPorColorTipo(vecMoto,TAMMOTO,vecTipos,TAMTIPO,vecColores,TAMCOLOR);
            break;
        }
        printf("\n");
        system("pause");
    }
    while(seguir=='s');

}
