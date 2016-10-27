/**
******************************************************
*  \file main.c
*  \brief Ejercicio 2.3
* \details Calculadora
* Uso del make
* - Compilar con make new o make tp2_3
* - Ejecutar o compilar y ejecutar en un paso com make run o simplemente make (luego de la ejecución se borrarán los archivos objeto y el ejecutable)
* - Generar y abrir página web con documento Doxygen con make html
* - Borrar web con make no_html
* - Agregar archivos .c, Makefile y Doxyfile al repositorio con make svn
* \author Federico Ariel Marinzalda
* \version 1.1
* \date 14/6/2016
*
*
*******************************************************/
#include<stdio.h>
#include"prototipos.h"

/**
******************************************************
*  \fn int main (void)
*  \brief En caso de elegir la opción 1 (ENCENDIDO) se llama a la función calculadora
* \details 
* \author Federico Ariel Marinzalda
* \version 1.1
* \date 14/6/2016
*
*
*******************************************************/
int main (void)
{
  int power;
  printf("Bienvenido\n");
  do
  {
    printf("¿Usar calculadora?\n%d = SÍ\n%d = NO\n",ON,OFF);
    scanf("%d",&power);
    if (power!=ON && power!=OFF)//En caso de escribir un código no válido se muestra leyenda aclaratoria
      printf("Opción no válida\n");
  } while (power!=ON && power!=OFF);//Hasta no ingresar un código válido no se usa la calculadora
  if (power==ON)
    calculadora();
  printf("Calculadora apagada\n");
  return 0;
}