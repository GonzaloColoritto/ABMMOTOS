#include <stdio.h>
#include <stdlib.h>

int validarFecha(int dia,int mes,int anio)
{
    int retorno=-1;

    if(anio>=1900&&anio<=2020)
    {
        if ( mes>=1 && mes<=12 )
        {
            switch (mes)
            {
                case 1://enero
                case 3://marzo
                case 5://mayo
                case 7://julio
                case 8://agosto
                case 10://octubre
                case 12:/*diciembre*/if(dia>=1 && dia<=31)
                                     {
                                            //printf("   | Fecha correcta.\n");
                                            retorno=0;
                                     }
                                     else
                                     {
                                            //printf("   | Fecha incorrecta.\n");
                                            retorno=-1;
                                     }
                                     break;

                case 4://abril
                case 6://junio
                case 9://sptiembre
                case 11:/*noviembre*/if(dia>=1 && dia<=30)
                                     {
                                           //printf("   | Fecha correcta.\n");
                                            retorno=0;
                                     }
                                     else
                                     {
                                            //printf("   | Fecha incorrecta.\n");
                                            retorno=-1;
                                     }
                                     break;
                case 2:/*febrero*/if((anio%4==0 && anio%100!=0) || anio%400==0)
                                  {
                                      if (dia>=1 && dia<=29)
                                      {
                                            //printf("   | Fecha correcta.\n");
                                            retorno=0;
                                      }
                                       else
                                      {
                                            //printf("   | Fecha incorrecta.\n");
                                            retorno=-1;
                                      }
                                  }
                                  else
                                  {
                                     if (dia>=1 && dia<=28)
                                      {
                                            //printf("   | Fecha correcta.\n");
                                            retorno=0;
                                      }
                                       else
                                      {
                                            //printf("   | Fecha incorrecta.\n");
                                            retorno=-1;
                                      }
                                  }

            }
        }
        else
        {
            //printf("   | Fecha incorrecta.\n");
            retorno=-1;
        }
    }
    else
    {
        //printf("   | Fecha incorrecta.\n");
        retorno=-1;
    }

    return retorno;
}
