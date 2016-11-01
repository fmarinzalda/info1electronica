/**
******************************************************
*  \file funciones.c
*  \brief Contiene las funciones utilizadas en el ejercicio 4.6 del TP4
* \author Federico Ariel Marinzalda
* \version 1.0
* \date 28/6/2016
*
*
*******************************************************/
#include"prototipos.h"

/**
******************************************************
*  \fn void replace (char* s,char nuevo,char viejo);
*  \brief Función que modifica un caracter por otra nuevo
* \author Federico Ariel Marinzalda
* \version 1.0
* \date 28/6/2016
* \param [in] *s Palabra a modificar
* \param [in] nuevo Caracter a escribir
* \param [in] viejo Caracter a modificar
*******************************************************/
void replace (char* s,char nuevo,char viejo)
{
  int i;
  for (i=0;*(s+i)!=NULLCHAR;i++)
  {
    if (*(s+i)==viejo)
    {
      *(s+i)=nuevo;
    }
  }
}