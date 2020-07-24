#ifndef SERVICIO_H_INCLUDED
#define SERVICIO_H_INCLUDED

typedef struct{

int id;
char descripcion[20];
int precio;

}eServicio;
int cargarDescripcionServicio(char descripcion[],int id,eServicio servicio[],int tamServicio);
void mostrarServicio(eServicio servicio);
void mostrarServicios(eServicio vecServicio[],int tamServicio);
int cargarPrecioServicio(int precio,int id,eServicio servicio[],int tamServicio);
#endif // SERVICIO_H_INCLUDED
