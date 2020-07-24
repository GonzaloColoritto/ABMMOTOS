#ifndef COLOR_H_INCLUDED
#define COLOR_H_INCLUDED

typedef struct{

    int id;
    char descripcion[20];

}eColor;

void mostrarColor(eColor color);
void mostrarColores(eColor vecColor[],int tamColor);
#endif // COLOR_H_INCLUDED
