/**
******************************************************
*  \file main.c
*  \brief Ejercicio 2.6
* \details Sensores
* Uso del make
* - Compilar con make new o make tp2_6
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
*  \brief Se ingresan 15 registros de temperaturas de 5 sensores
* \details Para analizar cada sensor se llama a la función temperaturasensor
* \n Recibe de esa función la temperatura máxima registrada por ese sensor estudiado
* \n Interesa saber el sensor que registró la temperatura más alta de todas
* \author Federico Ariel Marinzalda
* \version 1.2
* \date 22/5/2016
*
*
*******************************************************/
int main (void)
{
  float tempmax; //tempmax es la temperatura máxima registrada por el sensor analizado
  float sentemp; //sentemp es la temperatura máxima entre todos los sensores
  int sennum,i; //sennum guarda el número de sensor que detectó la mayor temperatura entre todas
  printf("\nAnálisis de los %d sensores\n",SEN);
  for (i=0,sentemp=-274;i<SEN;i++)
  {
    printf("\nRegistros del sensor %d:\n",i+1);
    //Sensores
    tempmax=temperaturassensor(i+1); //Envío a la función el número de sensor, que lo utilizo en los printf que hay en la misma
    if (tempmax>sentemp)
    {
      sentemp=tempmax;
      sennum=i+1;
    }
  }
  printf("\nEl sensor %d registró la mayor temperatura entre todas, que fue %.2f °C\n\n",sennum,sentemp);
  return 0;
}