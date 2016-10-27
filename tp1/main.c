/**
******************************************************
*  \file main.c
*  \brief Ejercicio 1.2
* \details Ingresar dos números y calcular su diferencia, mostrando si el resultado es positivo, negativo o 0
* Uso del make
* - Compilar con make new o make tp1_2
* - Ejecutar o compilar y ejecutar en un paso com make run o simplemente make (luego de la ejecución se borrarán los archivos objeto y el ejecutable)
* - Generar y abrir página web con documento Doxygen con make html
* - Borrar web con make no_html
* - Agregar archivos .c, Makefile y Doxyfile al repositorio con make svn
* \author Federico Ariel Marinzalda
* \version 1.4
* \date 14/6/2016
*
*
*******************************************************/
#include<stdio.h>
#include"prototipos.h"

/**
******************************************************
*  \fn int main (void)
*  \brief Se ingresan dos numeros y se llama a la función restadosnum
* \details 
* \author Federico Ariel Marinzalda
* \version 1.3
* \date 14/6/2016
*
*
*******************************************************/
int main (void)
{
  int a,b;
  printf("Ingrese el primer número\n");
  scanf("%d",&a);
  printf("Ingrese el segundo número\n");
  scanf("%d",&b);
  restadosnum(a,b); //Llamo a la función restadosnum y envío los dos números ingresados
  return 0;
}