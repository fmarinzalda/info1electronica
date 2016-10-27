/**
******************************************************
*  \file funciones.c
*  \brief Contiene las funciones utilizadas en el ejercicio 2.6 del TP2
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
*  \fn float ingresartemperatura (void)
*  \brief Ingreso y validación de registro de temperatura
* \author Federico Ariel Marinzalda
* \version 1.0
* \date 14/6/2016
* \param[out] temp Temperatura válida (no menor a -273 °C)
* \return temp (número real)
*\details Al ingresar a la función:
* \n 1) Pide ingreso de temperatura
* \n 2) Si es válida (no menor a -273 °C) la devuelve a la función temperaturasensor. Caso contrario, se vuelve a pedir ingreso.
*******************************************************/
float ingresartemperatura (void) //Como acá declaro la función ingresartemperatura, no necesito el prototipo en este archivo
{
      float temp;
      scanf("%f",&temp);
      while (temp<-273) //Avisa cuando temp<-273
      {
	printf("Temperatura no válida. Ingrese una temperatura válida (mayor o igual que -273 °C)\n");
	scanf("%f",&temp);
      }
      return temp;
}

/**
******************************************************
*  \fn float temperaturassensor (int sensor)
*  \brief Ingreso y validación de registro de temperatura
* \author Federico Ariel Marinzalda
* \version 1.0
* \date 14/6/2016
* \param[in] sensor Número de sensor
* \param[out] tempmax Temperatura máxima registrada por el sensor
* \return tempmax (número real)
*\details Al ingresar a la función:
* \n 1) Pide ingreso de 15 temperaturas, llamando a la función ingresartemperatura para realizar ese ingreso
* \n 2) Informa temperatura máxima registrada por el sensor
* \n 3) Informa promedio de temperaturas registradas por el sensor
* \n 4) Devuelve temperatura máxima a main
*******************************************************/
float temperaturassensor (int sensor) //Como acá declaro la función temperaturassensor, no necesito el prototipo en este archivo
{
    float temp,tempmax,prom=0;
    int j;
    printf("Ingrese %d registros de temperatura (la temperatura debe ser mayor o igual que -273 °C):\n\n",TEMP);
    for (j=0,tempmax=-274;j<TEMP;j++)
    {
      //TEMP
      temp=ingresartemperatura();
      if (temp>tempmax)
	tempmax=temp;
      prom+=temp; //En prom sumo las temperaturas válidas
    }
    printf("\nLa temperatura máxima registrada por el sensor %d fue %.2f °C\n",sensor,tempmax);
    prom/=j; //j = 15 fuera del for interno, por lo que acá calculo el promedio
    printf("El promedio de las %d temperaturas registradas por el sensor %d es %.2f °C\n",TEMP,sensor,prom);
    return tempmax;
}
