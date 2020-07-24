#ifndef TRABAJO_H_INCLUDED
#define TRABAJO_H_INCLUDED
#include "tipo.h"
#include "color.h"
#include "servicio.h"
#include "utn.h"
#include "motos.h"
#include "menu.h"
#include "fecha.h"
typedef struct{

int id;
int idMoto;
int idServicio;
eFecha fecha;
int isEmpty;

}eTrabajo;

int altaTrabajo(int proximoIdTrabajo,eTrabajo vecTrabajo[],int tamTrabajo,eMoto vecMoto[],int tamMoto,eServicio vecServicio[],int tamServicio,eTipo vecTipo[],int tamTipo,eColor vecColor[],int tamColor);
int buscarTrabajoLibre(eTrabajo vecTrabajo[],int tamTrabajo);
void inicializarTrabajos(eTrabajo vecTrabajo[],int tamTrabajo);
void mostrarTrabajo(eTrabajo Trabajo,eServicio vecServicio[],int tamServicio);
void mostrarTrabajos(eTrabajo vecTrabajo[],int tamTrabajo,eServicio vecServicio[],int tamServicio);
int agregarTrabajoAlArray(eTrabajo vecTrabajo[],int tamVecTrabajo,eTrabajo trabajoParaAgregarAlArray);
int buscarUltimoIdTrabajo(eTrabajo vecTrabajo[],int tamTrabajo);
#endif // TRABAJO_H_INCLUDED
