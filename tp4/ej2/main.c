/**
******************************************************
*  \file main.c
*  \brief Ejercicio 4.2
* \details Ingresar 40 datos y realizar los siguientes cálculos:
* \n 1) Suma de todos los datos
* \n 2) Promedio de todos los datos
* \n 3) Suma de los datos ubicados en las posiciones pares
* \n 4) Promedio de los datos positivos
* Uso del make
* - Compilar con make new o make tp4_2
* - Ejecutar o compilar y ejecutar en un paso com make run o simplemente make (luego de la ejecución se borrarán los archivos objeto y el ejecutable)
* - Generar y abrir página web con documento Doxygen con make html
* - Borrar web con make no_html
* - Agregar archivos .c, Makefile y Doxyfile al repositorio con make svn
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
*  \fn int main (void)
*  \brief Se ingresan 40 datos (la cantidad está definida en un DEFINE) y se llama a una función calculos para informar todo lo solicitado
* \details 
* \author Federico Ariel Marinzalda
* \version 1.0
* \date 28/6/2016
*
*
*******************************************************/
int main (void)
{
  int i,datos[CANT];
  printf("Ingresar %d números\n",CANT);
  for (i=0;i<CANT;i++)
    scanf("%d",datos+i);
  calculos(datos,CANT);
  return 0;
}