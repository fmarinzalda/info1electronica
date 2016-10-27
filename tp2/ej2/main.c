/**
******************************************************
*  \file main.c
*  \brief Ejercicio 2.2
* \details Ingresar número y calcular el factorial
* Uso del make
* - Compilar con make new o make tp2_2
* - Ejecutar o compilar y ejecutar en un paso com make run o simplemente make (luego de la ejecución se borrarán los archivos objeto y el ejecutable)
* - Generar y abrir página web con documento Doxygen con make html
* - Borrar web con make no_html
* - Agregar archivos .c, Makefile y Doxyfile al repositorio con make svn
* \author Federico Ariel Marinzalda
* \version 1.2
* \date 14/6/2016
*
*
*******************************************************/
#include<stdio.h>
#include"prototipos.h"

/**
******************************************************
*  \fn int main (void)
*  \brief Ingresar por teclado un número. Cuando sea válido (no negativo) se llama a la función factorial
* \details 
* \author Federico Ariel Marinzalda
* \version 1.3
* \date 14/6/2016
*
*
*******************************************************/
int main (void)
{
  int dato,fact;
   do
  {
    printf("Ingrese número\n");
    scanf("%d",&dato);
    if (dato<0)
      printf("No se puede calcular el factorial de un número negativo. ");
  } while (dato<0);
  fact=factorial(dato);
  printf("El factorial de %d es %d\n",dato,fact);
  return 0;
}