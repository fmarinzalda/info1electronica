/**
******************************************************
*  \file prototipos.h
*  \brief Contiene los prototipos de las funciones y las constantes simbólicas utilizadas en el ejercicio 4.7
* \author Federico Ariel Marinzalda
* \version 1.0
* \date 24/8/2016
*
*
*******************************************************/

//Prototipos de funciones usadas en en el ejercicio 4.7
void replace (char*,char,char);
int (*validateString) (char*);
int validateIP (char*);
int validateMAIL (char*);
int validateCC (char*);
int myStrlen (const char*);
int myStrcencpy (char*,char*,int,int);
int myStrnlastcpy (char*,char*,int);
int myStrncpy (char*,char*,int);

//Constantes simbólicas usadas en en el ejercicio 4.7
#define NULLCHAR '\0'
#define CAR 20
#define IP 1
#define MAIL 2
#define CC 3
#define TRUE 1
#define FALSE 0