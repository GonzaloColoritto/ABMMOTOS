#include <stdio.h>
#include <stdlib.h>
#include "color.h"


void mostrarColor(eColor color)
{


    printf("%d %s \n",color.id,color.descripcion);


}

void mostrarColores(eColor vecColor[], int tamColor)
{

    for(int i=0; i<tamColor; i++)
    {

        mostrarColor(vecColor[i]);
    }


}

