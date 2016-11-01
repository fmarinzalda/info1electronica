/**
******************************************************
*  \file funciones.c
*  \brief Contiene las funciones utilizadas en el ejercicio 4.4 del TP4
* \author Federico Ariel Marinzalda
* \version 1.0
* \date 28/6/2016
*
*
*******************************************************/
#include"prototipos.h"

/**
******************************************************
*  \fn int myStrlen (const char* palabra)
*  \brief Función que calcula la longitud de una palabra
* \author Federico Ariel Marinzalda
* \version 1.0
* \date 28/6/2016
* \param [in] *palabra Palabra cuya longitud quiere determinarse
* \param [out] i Longitud de la palabra
* \returns Devuelve número entero
*******************************************************/
int myStrlen (const char* palabra)
{
  int i;
  for (i=0;*(palabra+i)!=NULLCHAR;i++);
  return i;
}