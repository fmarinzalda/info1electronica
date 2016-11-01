/**
******************************************************
*  \file main.c
*  \brief Ejercicio 4.7
* \details Verificar string (dirección IP, mail o tarjeta de créfito)
* Uso del make
* - Compilar con make new o make tp4_7
* - Ejecutar o compilar y ejecutar en un paso com make run o simplemente make (luego de la ejecución se borrarán los archivos objeto y el ejecutable)
* - Generar y abrir página web con documento Doxygen con make html
* - Borrar web con make no_html
* - Agregar archivos .c, Makefile y Doxyfile al repositorio con make svn
* \author Federico Ariel Marinzalda
* \version 1.0
* \date 24/8/2016
*
*
*******************************************************/
#include<stdio.h>
#include"prototipos.h"

/**
******************************************************
*  \fn int main (void)
*  \brief Se ingresa una cadena de caracteres y se la envía a una función de validación que se pasa por puntero a validateString
* \details 
* \author Federico Ariel Marinzalda
* \version 1.0
* \date 24/8/2016
*
*
*******************************************************/
int main (void)
{
  char s[255],validado;
  int cod;
  printf("Determine el tipo de cadena a ingresar:\n%d: Dirección IP\n%d: e-mail\n%d: Tarjeta de credito\n",IP,MAIL,CC);
  scanf("%d",&cod);
  while(cod!=IP && cod!=MAIL && cod!=CC)
  {
      printf("Código incorrecto. Determine el tipo de cadena a ingresar:\n%d: Dirección IP\n%d: e-mail\n%d: Tarjeta de credito\n",IP,MAIL,CC);
      scanf("%d",&cod);
  }
  switch(cod)
  {
      case IP:
          validateString=validateIP;
          break;
      case MAIL:
          validateString=validateMAIL;
          break;
      case CC:
          validateString=validateCC;
          break;
      default:
          break;
  }
  printf("Ingrese cadena de caracteres: ");
  scanf(" %[^\n]",s);//scanf que admite espacios
  validado=validateString(s);
  if(validado==FALSE)
      printf("La cadena no es válida\n");
  else
  {
      switch(cod)
      {
          case IP:
              printf("La cadena es una dirección IP\n");
              break;
          case MAIL:
              printf("La cadena es un e-mail\n");
              break;
          case CC:
              printf("La cadena es una tarjeta de crédito\n");
              break;
          default:
              break;
      }
  }
  return 0;
}