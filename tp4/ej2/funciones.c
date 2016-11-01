/**
******************************************************
*  \file funciones.c
*  \brief Contiene las funciones utilizadas en el ejercicio 4.2 del TP4
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
*  \fn void calculos (int* datos,int largo)
*  \brief Función que realiza los calculos solicitados
* \author Federico Ariel Marinzalda
* \version 1.0
* \date 28/6/2016
* \param [in] *datos Recibe la dirección del vector de datos ingresados en el main
* \param [in] largo Cantidad de datos
* \details Operaciones realizadas
* \n 1) Suma de todos los datos
* \n 2) Promedio de todos los datos
* \n 3) Suma de los datos ubicados en las posiciones pares
* \n 4) Promedio de los datos positivos (en caso de no haber datos positivos, se informa con mensaje aclaratorio)
*******************************************************/
void calculos (int* datos,int largo)
{
  int i,sumtotal=0,sumposicionpar=0,contpositivos=0,sumpositivos=0;
  for (i=0;i<largo;i++)
  {
    sumtotal+=*(datos+i);
    if (i%2==0)
    {
      sumposicionpar+=*(datos+i);
    }
    if (*(datos+i)>0)
    {
      contpositivos++;
      sumpositivos+=*(datos+i);
    }
  }
  printf("\nLa suma de los %d datos es igual a %d\n",largo,sumtotal);
  printf("El promedio de los %d datos es igual a %f\n",largo,((float)sumtotal)/largo);
  printf("La suma de los datos que ocupan posición par es igual a %d\n",sumposicionpar);
  if (contpositivos)
  {
    printf("El promedio de los datos positivos es igual a %f\n",((float)sumpositivos)/contpositivos);
  }
  else
  {
    printf("No se ingresaron datos positivos. No se puede calcular el promedio\n");
  }
}