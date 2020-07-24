#ifndef TIPO_H_INCLUDED
#define TIPO_H_INCLUDED

typedef struct{

    int id;
    char descripcion[20];
    int isEmpty;

}eTipo;


void mostrarTipo(eTipo tipo);
void mostrarTipos(eTipo vecTipo[],int tamTipo);
void inicializarTipos(eTipo vecTipo[],int tamTipo);

eTipo crearTipo(int id,char descripcion[20]);
void agregarTipo(eTipo vecTipo[],int tamTipo,eTipo tipo);
#endif // TIPO_H_INCLUDED
