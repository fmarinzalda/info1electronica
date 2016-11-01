/**
******************************************************
*  \file main.c
*  \brief Ejercicio 4.5
* \details Comparar primeros "n" caracteres de dos cadenas de caracteres
* Uso del make
* - Compilar con make new o make tp4_5
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
*  \brief Se envían dos constantes de caracteres y un entero a la función myStrncmp para informar cuál está primera en el orden alfabético
* \details 
* \author Federico Ariel Marinzalda
* \version 1.0
* \date 28/6/2016
*
*
*******************************************************/
int main (void)
{
  char *s1,*s2;
  unsigned int n;
  int res;
  s1="Info";
  s2="Informatica";
  printf("Ingrese cantidad de letras a comparar: ");
  scanf("%u",&n);
  res=myStrncmp(s1,s2,n);
  if (res==0)
  {
    printf("Las palabras %s y %s están en el mismo orden alfabético\n",s1,s2);
  }
  else if (res>0)
  {
    printf("La palabra %s está primera alfabéticamente respecto a %s\n",s1,s2);
  }
  else
  {
    printf("La palabra %s está primera alfabéticamente respecto a %s\n",s2,s1);
  }
  return 0;
}