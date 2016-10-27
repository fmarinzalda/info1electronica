/**
******************************************************
*  \file main.c
*  \brief Ejercicio 2.5
* \details Ingresar una temperatura en °C y convertirla a °K
* Uso del make
* - Compilar con make new o make tp2_5
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
*  \brief Se ingresa por teclado una tempearatura en °C y si es válida (no menor a -273 °C) se llama a la función celsiusakelvin
* \details 
* \author Federico Ariel Marinzalda
* \version 1.3
* \date 14/6/2016
*
*
*******************************************************/
int main (void)
{
  float tc;
  printf("Ingrese temperatura en °C\n");
  scanf("%f",&tc);
  while (tc<-273)
  {
    printf("La temperatura no puede ser menor a -273 °C (significaría una temperatura negativa en °K que no existe)\n");
    printf("Ingrese temperatura en °C\n");
    scanf("%f",&tc);
  }
  celsiusakelvin(tc); //Llamo a la función celsiusakelvin y envío la temperatura ingresada en °C
  return 0;
}