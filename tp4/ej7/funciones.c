/**
******************************************************
*  \file funciones.c
*  \brief Contiene las funciones utilizadas en el ejercicio 4.7 del TP4
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
*  \fn int validateIP (char* s)
*  \brief Función que valida una dirección IP
* \author Federico Ariel Marinzalda
* \version 1.0
* \date 24/8/2016
* \param [in] *s Cadena a validar
* \param [out] TRUE Si es un IP válido
* \param [out] FALSE Si no es un IP válido
* \returns Un número entero
*******************************************************/
int validateIP (char* s)
{
  int i,l,aux,j,dig=0,num=0,cpuntos=0;//dig controla cuantos números seguidos se leyeron, mientras que num toma el valor de cada bloque
  l=myStrlen(s);
  if(l<7 || l>15)//Una dirección IP puede ser de 0.0.0.0 a 255.255.255.255 (son como mínimo 7 caracteres y como máximo 15 caracteres)
      return FALSE;
  for (i=l-1;i>=0;i--)
  {
    if((*(s+i)<'0' && *(s+i)!='.') || *(s+i)>'9')//La dirección IP puede tener solo números o el punto
    {
        return FALSE;
    }
    if((i==l-1 && *(s+i)=='.') || (i==0 && *(s+i)=='.'))//La dirección IP no puede empezar ni terminar con punto
    {
        return FALSE;
    }
    if(*(s+i)!='.' && dig==3)//No puede haber 4 digitos seguidos
    {
        return FALSE;
    }
    if(*(s+i)!='.' && dig<3)
    {
        for(aux=*(s+i)-'0',j=1;j<=dig;aux=aux*10,j++);
        dig++;
        num+=aux;
    }
    if(*(s+i)=='.')
    {
        cpuntos++;
        dig=0;
        if(cpuntos>3)//No puede haber más de 3 puntos
            return FALSE;
        if(*(s+i+1)=='.')//No puede haber dos puntos seguidos
            return FALSE;
        if(num>255)//Los bloques numéricos no pueden ser mayores a 255
            return FALSE;
        num=0;
    }
  }
  if(cpuntos<3)//En caso de haber terminado de leer la cadena, si no hubo 3 puntos, la cadena no es un IP válido
      return FALSE;
  if(num>255)//Verifica que el primer número no sea mayor a 255
      return FALSE;
  return TRUE;
}

/**
******************************************************
*  \fn int validateMAIL (char* s)
*  \brief Función que valida una cuenta de e-mail
* \author Federico Ariel Marinzalda
* \version 1.0
* \date 25/8/2016
* \param [in] *s Cadena a validar
* \param [out] TRUE Si es un e-mail válido
* \param [out] FALSE Si no es un e-mail válido
* \returns Un número entero
*******************************************************/
int validateMAIL (char* s)
{
  int i,l,control,validlocal,validdomain,doml,posultimopunto=0,j,cpuntos=0;//dig controla cuantos números seguidos se leyeron, mientras que num toma el valor de cada bloque
  char local[250],domain[253],ip[16];//El @ divide parte local (de 1 a 249 caracteres) y parte dominio (domain, de al menos 4 caracteres)
  l=myStrlen(s);
  if(myStrlen(s)>254)//Una cadena de más de 254 caracteres puede generar un overflow en el buffer de teclado
      return FALSE;
  for (i=0;i<l;i++)
  {
      if(*(s+i)<=31 || *(s+i)==127)//Un e-mail no puede tener caracteres no imprimibles
          return FALSE;
  }
  for(i=l-5;*(s+i)!='@';i--);//Al salir del for, i contendrá la cantidad de caracteres de la parte local
  if(i<1)//La parte local debe tener al menos un caracter
      return FALSE;
  if(l-i-1<4)//La parte dominio no puede tener menos de 4 caracteres (la longitud de la parte dominio queda determinada por l-i-1)
      return FALSE;
  control=myStrncpy(local,s,i);
  if(control==-1)
      return FALSE;
  control=myStrnlastcpy(domain,s,l-i-1);
  if(control==-1)
      return FALSE;
  doml=myStrlen(domain);
  if(i<3)//Si no hay al menos 3 caracteres estos caracteres no son válidos:@<>.\/()[]",;: y el caracter espacio
  {
      for(j=0;j<i;j++)
      {
          switch(*(local+j))
          {
              case'@':case'<':case'>':case'.':case'\\':case'/':case'(':case')':case'[':case']':case'\"':case',':case';':case':':case' ':
                  validlocal=FALSE;
                  break;
              default:
                  break;
          }
      }
  }
  else if(*local!='\"')//Si la parte local no empieza con ", estos caracteres no son válidos:@<>\/()[]",;: y el caracter espacio. Además el punto no debe aparecer dos veces consecutivas
  {
      for(j=0;j<i;j++)
      {
          switch(*(local+j))
          {
              case'@':case'<':case'>':case'\\':case'/':case'(':case')':case'[':case']':case'\"':case',':case';':case':':case' ':
                  validlocal=FALSE;
                  break;
              case'.':
                  cpuntos++;
                  if(cpuntos>1)
                      validlocal=FALSE;
                  if(j==0 || j==i-1)
                      validlocal=FALSE;
                  break;
              default:
                  cpuntos=0;
                  break;
          }
      }
  }
  else if(*local=='\"' && *(local+i-1)!='\"')//Si la parte local empieza con " debe terminar con "
  {
      validlocal=FALSE;
  }
  else
  {
      validlocal=TRUE;
  }
  if(*domain=='[' && *(domain+doml-1)==']')
  {
      if(doml<=17)
      {
          control=myStrcencpy(ip,domain,1,1);
          if(control==-1)
              return FALSE;
          validdomain=validateIP(ip);
      }
      else
          validdomain=FALSE;
  }
  else
  {
      validdomain=TRUE;
      for(j=0;j<doml;j++)
      {
          if(*(domain+j)=='.')
          {
              posultimopunto=j;//Guarda la posición del último punto encontrado en la parte dominio
              if(*(domain+j+1)=='.' || j==0 || j==doml-1)//La parte dominio no puede empezar ni terminar con punto, ni pueden haber dos puntos seguidos
                  validdomain=FALSE;
          }
          else if(*(domain+j)<'0' || (*(domain+j)>'9' && *(domain+j)<'A') || (*(domain+j)>'Z' && *(domain+j)<'a') || *(domain+j)>'z')//Sólo puede haber letras
          {
              validdomain=FALSE;
          }
      }
      if(posultimopunto==0)//Debe haber un punto en la parte dominio
          validdomain=FALSE;
      else
      {
        for(j=posultimopunto+1;j<doml;j++)
        {
            if(*(domain+j)<'A' || (*(domain+j)>'Z' && *(domain+j)<'a') || *(domain+j)>'z')//Después del último punto sólo debe haber letras
            {
                validdomain=FALSE;
            }
        }
        if(*(domain+posultimopunto+2)==NULLCHAR)//Después del último punto debe haber al menos 2 caracteres
            validdomain=FALSE;
      }
  }
  if(validlocal==TRUE && validdomain==TRUE)
      return TRUE;
  else
      return FALSE;
}

/**
******************************************************
*  \fn int validateCC (char* s)
*  \brief Función que valida una tarjeta de crédito
* \author Federico Ariel Marinzalda
* \version 1.0
* \date 25/8/2016
* \param [in] *s Cadena a validar
* \param [out] tarjetavalida TRUE en caso de ser valida, FALSE en caso de no ser valida
* \returns Un número entero
*******************************************************/
int validateCC (char* s)
{
  int i,l,tarjetavalida;//dig controla cuantos números seguidos se leyeron, mientras que num toma el valor de cada bloque
  l=myStrlen(s);
  if(l!=16)//Una tarjeta de crédito tiene 16 números
      return FALSE;
  tarjetavalida=TRUE;
  for(i=0;i<l && tarjetavalida==TRUE;i++)
  {
      if(*(s+i)<'0' || *(s+i)>'9')
          tarjetavalida=FALSE;
  }
  return tarjetavalida;
}

/**
******************************************************
*  \fn int myStrlen (const char* palabra)
*  \brief Función que calcula la longitud de una palabra
* \author Federico Ariel Marinzalda
* \version 1.0
* \date 28/6/2016
* \param [in] *palabra Palabra cuya longitud quiere determinarse
* \param [out] i Longitud de la palabra
* \returns Devuelve número entero
*******************************************************/
int myStrlen (const char* palabra)
{
  int i;
  for (i=0;*(palabra+i)!=NULLCHAR;i++);
  return i;
}

/**
******************************************************
*  \fn int myStrncpy (char* dest,char* origen,int n)
*  \brief Función que copia los primeros n caracteres de una palabra a otro string
* \author Federico Ariel Marinzalda
* \version 1.0
* \date 25/8/2016
* \param [in] *dest Dirección del string al que se envía la palabra
* \param [in] *origen Dirección del string del que proviene la palabra
* \param [in] n Cantidad de caracteres a copiar
* \param [out] -1 En caso de error en la copia
* \param [out] 0 En caso de copia realizada correctamente
* \returns Devuelve número entero
*******************************************************/
int myStrncpy (char* dest,char* origen,int n)
{
  int i;
  if(dest==NULL || n<1)
      return -1;
  for(i=0;i<n && *(origen+i)!=NULLCHAR;i++)
      *(dest+i)=*(origen+i);
  *(dest+i)=NULLCHAR;
  return 0;
}

/**
******************************************************
*  \fn int myStrnlastcpy (char* dest,char* origen,int n)
*  \brief Función que copia los últimos n caracteres de una palabra a otro string
* \author Federico Ariel Marinzalda
* \version 1.0
* \date 25/8/2016
* \param [in] *dest Dirección del string al que se envía la palabra
* \param [in] *origen Dirección del string del que proviene la palabra
* \param [in] n Cantidad de caracteres a copiar
* \param [out] -1 En caso de error en la copia
* \param [out] 0 En caso de copia realizada correctamente
* \returns Devuelve número entero
*******************************************************/
int myStrnlastcpy (char* dest,char* origen,int n)
{
  int i,l;
  if(dest==NULL || n<1)
      return -1;
  l=myStrlen(origen);
  if(l<=n)
  {
      for(i=0;i<l;i++)
          *(dest+i)=*(origen+i);
  }
  else
  {
      for(i=0;i<n;i++)
          *(dest+i)=*(origen+(l-n+i));
  }
  *(dest+i)=NULLCHAR;
  return 0;
}

/**
******************************************************
*  \fn int myStrcencpy (char* dest,char* origen,int n,int m)
*  \brief Función que copia los caracteres centrales de una palabra a otro string (no copia ni los n primeros ni los m últimos)
* \author Federico Ariel Marinzalda
* \version 1.0
* \date 25/8/2016
* \param [in] *dest Dirección del string al que se envía la palabra
* \param [in] *origen Dirección del string del que proviene la palabra
* \param [in] n Cantidad de primeros caracteres que no se desean copiar
* \param [in] m Cantidad de últimos caracteres que no se desean copiar
* \param [out] control -1 En caso de error en la copia, 0 En caso de copia realizada correctamente
* \returns Devuelve número entero
*******************************************************/
int myStrcencpy (char* dest,char* origen,int n,int m)
{
  int l,control;
  l=myStrlen(origen);
  if(dest==NULL || n+m>l || n<0 || m<0)
      return -1;
  control=myStrncpy(dest,origen,l-m);
  if(control==-1)
      return control;
  control=myStrnlastcpy(dest,dest,l-m-n);
  return control;
}