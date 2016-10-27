/**
******************************************************
*  \file main.c
*  \brief Ejercicio 2.1
* \details Ingresar base y exponente y calcular potencia (x^y)
* Uso del make
* - Compilar con make new o make tp2_1
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
*  \brief Ingresar por teclado la base y el exponente que debe ser múltiplo de 0.5 para contemplar raíces cuadradas. Luego, se llama a la función potencia
* \details 
* \author Federico Ariel Marinzalda
* \version 1.3
* \date 14/6/2016
*
*
*******************************************************/
int main (void)
{
  float base,exponente;
  printf("Ingrese valor de la base\n");
  scanf("%f",&base);
  printf("Ingrese valor del exponente\n");
  scanf("%f",&exponente);
  potencia(base,exponente);
  return 0;
}