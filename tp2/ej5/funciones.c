/**
******************************************************
*  \file funciones.c
*  \brief Contiene las funciones utilizadas en el ejercicio 2.5 del TP2
* \author Federico Ariel Marinzalda
* \version 1.1
* \date 14/6/2016
*
*
*******************************************************/
#include<stdio.h>
#include"prototipos.h"

/**
******************************************************
*  \fn void celsiusakelvin (int tc)
*  \brief Convierte de °C a °K
* \author Federico Ariel Marinzalda
* \version 1.1
* \date 14/6/2016
* \param[in] tc Temperatura en °C
* \details Muestra conversión
*******************************************************/
void celsiusakelvin (float tc)
//La función calcula el equivalente a °K de una temperatura expresada en °C
{
  float tk;
  tk=tc+273;
  printf("%.2f °C son %.2f °K\n",tc,tk);
}