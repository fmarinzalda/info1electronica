/**
******************************************************
*  \file funciones.c
*  \brief Contiene las funciones utilizadas en el ejercicio 4.3 del TP4
* \author Federico Ariel Marinzalda
* \version 1.0
* \date 28/6/2016
*
*
*******************************************************/
#include"prototipos.h"

/**
******************************************************
*  \fn void stringReverse (char* palabra)
*  \brief Función que recibe la palabra y la invierte
* \author Federico Ariel Marinzalda
* \version 1.0
* \date 28/6/2016
* \param [in] *palabra Palabra a invertir
*******************************************************/
void stringReverse (char* palabra)
{
  int i,largo;
  char aux;
  largo=my_strlen(palabra);
  for (i=0;i<largo/2;i++)
  {
    aux=*(palabra+i);
    *(palabra+i)=*(palabra+largo-1-i);
    *(palabra+largo-1-i)=aux;
  }
}

/**
******************************************************
*  \fn int my_strlen (char* palabra)
*  \brief Función que calcula la longitud de una palabra
* \author Federico Ariel Marinzalda
* \version 1.0
* \date 28/6/2016
* \param [in] *palabra Palabra cuya longitud quiere determinarse
* \param [out] i Longitud de la palabra
* \returns Devuelve número entero
*******************************************************/
int my_strlen (char* palabra)
{
  int i;
  for (i=0;*(palabra+i)!=NULLCHAR;i++);
  return i;
}