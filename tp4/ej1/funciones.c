/**
******************************************************
*  \file funciones.c
*  \brief Contiene las funciones utilizadas en el ejercicio 4.1 del TP4
* \author Federico Ariel Marinzalda
* \version 1.0
* \date 28/6/2016
*
*
*******************************************************/
#include<stdio.h>
#include"prototipos.h"

/**
******************************************************
*  \fn void mostrarbytes (char* p)
*  \brief Muestra el contenido de cada byte de una variable long
* \author Federico Ariel Marinzalda
* \version 1.0
* \date 28/6/2016
* \param [in] *p Recibe dirección del número con el que se trabaja
*******************************************************/
void mostrarbytes (char* p)
{
  int i;
  for (i=0;i<sizeof(long);i++)
    printf("El byte %d del numero representado en hexadecimal es %X\n",i,(unsigned int)*(p+i));
}