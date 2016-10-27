/**
******************************************************
*  \file funciones.c
*  \brief Contiene las funciones utilizadas en el ejercicio 2.4 del TP2
* \author Federico Ariel Marinzalda
* \version 1.0
* \date 15/5/2016
*
*
*******************************************************/
#include<stdio.h>
#include"prototipos.h"

/**
******************************************************
*  \fn void restadosnum (int a, int b)
*  \brief Calcula la diferencia entre dos números
* \author Federico Ariel Marinzalda
* \version 1.0
* \date 15/5/2016
* \param[in] a Minuendo
* \param[in] b Sustraendo
* \details Muestra mensaje con resultado de la resta
*******************************************************/
void restadosnum (int a, int b)
//La función calcula la diferencia entre a y b y muestra el resultado
{
  int dif;
  dif=a-b;
  printf("%d menos %d es igual a %d. ",a,b,dif); //Muestro resultado
  if (dif>0) //Si el resultado es positivo, se aclara con una leyenda
    printf("Resultado positivo\n");
  else if (dif<0) //Si el resultado es negativo, se aclara con una leyenda
    printf("Resultado negativo\n");
  else //Si no es ni positivo ni negativo, entonces es 0, resultado que se mostraría con el primer printf
    printf("\n");
}