/**
******************************************************
*  \file main.c
*  \brief Ejercicio 4.3
* \details Invertir cadena de caracteres
* Uso del make
* - Compilar con make new o make tp4_3
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
*  \brief Se ingresa una palabra de hasta 20 caracteres y se llama a la función stringReverse
* \details 
* \author Federico Ariel Marinzalda
* \version 1.0
* \date 28/6/2016
*
*
*******************************************************/
int main (void)
{
  char palabra[CAR+1];
  printf("Ingrese palabra de hasta %d caracteres: ",CAR);
  scanf("%s",palabra);
  stringReverse(palabra);
  printf("Palabra invertida: %s\n",palabra);
  return 0;
}