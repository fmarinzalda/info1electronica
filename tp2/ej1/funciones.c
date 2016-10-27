/**
******************************************************
*  \file funciones.c
*  \brief Contiene las funciones utilizadas en el ejercicio 2.1 del TP2
* \author Federico Ariel Marinzalda
* \version 1.0
* \date 15/5/2016
*
*
*******************************************************/
#include<stdio.h>
#include<math.h>
#include"prototipos.h"

/**
******************************************************
*  \fn void potencia (float a,float b)
*  \brief Calcula la potencia base^exponente
* \author Federico Ariel Marinzalda
* \version 1.0
* \date 15/5/2016
* \param[in] a base (número real)
* \param[in] b exponente (número real)
* \details
* Muestra mensaje con resultado de la potencia
* \n El programa permite mostrar resultados que sean números imaginarios
*******************************************************/
void potencia (float a,float b)
{
  float bs,ex,r;
  int aux;
  bs=(a<0)?-a:a;
  ex=(b<0)?-b:b;
  if (a==0 && b<=0)
  {
    printf("No se puede calcular la potencia de %f elevado a la %f\n",a,b);
  }
  else
  {
    r=pow(bs,ex);
    if (b!=ex)
    {
      r=1/r;
    }
    if (a!=bs)
    {
      aux=(int)(10*ex);//Con la variable aux evalúo si el exponente múltiplicado por 10 es múltiplo de 4
      aux%=4;
      switch (aux)
      {
	case 0://Si es múltiplo de 4 r no varía respecto a la última cuenta que se realizó
	  printf("%.2f elevado a la %.2f es igual a %f\n",a,b,r);
	  break;
	case 1://Si el resto es 1 el resultado es r imaginario (j r)
	  printf("%.2f elevado a la %.2f es igual a j %f\n",a,b,r);
	  break;
	case 2://Si el resto es 2 el resultado es -r
	  printf("%.2f elevado a la %.2f es igual a %f\n",a,b,-r);
	  break;
	case 3://Si el resto es 3 el resultado es r imaginario (j r)
	  printf("%.2f elevado a la %.2f es igual a j %f\n",a,b,r);
	default:
	  break;
      }
    }
    else
    {
      printf("%.2f elevado a la %.2f es igual a %f\n",a,b,r);
    }
  }
}