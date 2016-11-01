/**
******************************************************
*  \file main.c
*  \brief Ejercicio 4.1
* \details Mostrar contenido de cada byte de una variable long
* Uso del make
* - Compilar con make new o make tp4_1
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
#include"prototipos.h"

/**
******************************************************
*  \fn int main (void)
*  \brief Se llama a la función mostrarbytes para informar el contenido de cada byte de un número de tamaño long
* \details 
* \author Federico Ariel Marinzalda
* \version 1.0
* \date 28/6/2016
*
*
*******************************************************/
int main (void)
{
  long numero=0x1234567812345678;
  char* p;
  p=(char*)&numero;
  mostrarbytes(p);
  return 0;
}
  