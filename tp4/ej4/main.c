/**
******************************************************
*  \file main.c
*  \brief Ejercicio 4.4
* \details Calcular longitud de una cadena de caracteres
* Uso del make
* - Compilar con make new o make tp4_4
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
*  \brief Se envía una constante de caracteres a la función myStrlen y se informa la palabra invertida
* \details 
* \author Federico Ariel Marinzalda
* \version 1.0
* \date 28/6/2016
*
*
*******************************************************/
int main (void)
{
  char *palabra;
  int largo;
  palabra="Informatica";
  largo=myStrlen(palabra);
  printf("La palabra %s tiene %d caracteres\n",palabra,largo);
  return 0;
}