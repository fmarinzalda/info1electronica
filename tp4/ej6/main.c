/**
******************************************************
*  \file main.c
*  \brief Ejercicio 4.6
* \details Modificar caracteres de una palabra
* Uso del make
* - Compilar con make new o make tp4_6
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
*  \brief Se ingresa una palabra, el caracter a modificar y el caracter por el cual se modifica. Esto se envía a la función replace y se informa la palabra modificada
* \details 
* \author Federico Ariel Marinzalda
* \version 1.0
* \date 28/6/2016
*
*
*******************************************************/
int main (void)
{
  char s[CAR+1],nuevo,viejo;
  printf("Ingrese palabra de hasta %d caracteres: ",CAR);
  scanf("%s",s);
  printf("Ingrese caracter a modificar: ");
  scanf(" %c",&viejo);
  printf("Ingrese caracter a escribir en lugar del viejo: ");
  scanf(" %c",&nuevo);
  replace(s,nuevo,viejo);
  printf("Palabra modificada: %s",s);
  return 0;
}