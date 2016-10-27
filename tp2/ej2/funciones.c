/**
******************************************************
*  \file funciones.c
*  \brief Contiene las funciones utilizadas en el ejercicio 2.2 del TP2
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
*  \fn int factorial (int a)
*  \brief Cálculo de factorial de un número
* \author Federico Ariel Marinzalda
* \version 1.0
* \date 15/5/2016
* \param[in] n Número no negativo
* \param[out] r Factorial de n (r = n!)
* \return r (número entero)
*******************************************************/
int factorial (int a)
{
  int r=1,i;
  for (i=2;i<=a;i++)
    r=r*i;
  return r;
}