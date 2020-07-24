#ifndef MOTOS_H_INCLUDED
#define MOTOS_H_INCLUDED
#include "tipo.h"
#include "color.h"
#include "servicio.h"

typedef struct{

int id;
char marca[20];
int idTipo;
int idColor;
int cilindrada;
int isEmpty;

}eMoto;
int buscarLibre(eMoto vec[], int tam);
int altaMoto(int proximoId, eMoto vecMoto[],int tamMotos,eServicio vecServicio[],int tamServicio, eTipo vecTipo[],int tamTipo,eColor vecColor[],int tamColor);
void mostrarMoto(eMoto moto,eTipo tipos[],int tamTipos,eColor colores[],int tamColores);
void mostrarMotos(eMoto vecMoto[],int tamMotos,eTipo tipos[],int tamTipos,eColor colores[],int tamColores);
void inicializarMotos(eMoto vec[],int tam);
int modificarMoto(eMoto vecMoto[],int tamMotos,eColor vecColor[],int tamColor,eTipo vecTipo[],int tamTipo);
int buscarIdMoto(int id,eMoto moto[],int tam);
int buscarIdColor(int id,eColor color[],int tam);
int buscarIdTipo(int id,eTipo tipos[],int tam);
int bajaMoto(eMoto vecMoto[],int tamMoto,eColor vecColor[],int tamColor,eTipo vecTipo[],int tamTipo);
int agregarMotoAlArray(eMoto vecMoto[],int tamVec,eMoto motoParaAgregar);
int buscarUltimoId(eMoto vecMoto[],int tamMoto);
int cargarDescripcionColor(char descripcion[],int id,eColor colores[],int tamColores);
int cargarDescripcionTipo(char descripcion[],int id,eTipo tipos[],int tamTipos);
int mostrarMotoPorColor(eMoto vecMoto[],int tamMoto,eColor vecColor[],int tamColor,eTipo tipos[],int tamTipos);
int mostrarMotoPorTipo(eMoto vecMoto[],int tamMoto,eColor vecColor[],int tamColor,eTipo vecTipos[],int tamTipos);
void mostrarMotosSeparadasPorTipo(eMoto vecMoto[],int tamMotos,eTipo tipos[],int tamTipos,eColor colores[],int tamColores);
int mostrarMotoPorColorTipo(eMoto vecMoto[],int tamMotos,eTipo tipos[],int tamTipos,eColor colores[],int tamColores);
#endif // MOTOS_H_INCLUDED
