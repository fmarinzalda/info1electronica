/**
******************************************************
*  \file funciones.c
*  \brief Contiene las funciones utilizadas en el ejercicio 2.3 del TP2
* \author Federico Ariel Marinzalda
* \version 1.0
* \date 22/5/2016
*
*
*******************************************************/
#include<stdio.h>
#include<math.h>
#include"prototipos.h"

/**
******************************************************
*  \fn void calculadora (void)
*  \brief Uso de la calculadora
* \author Federico Ariel Marinzalda
* \version 1.1
* \date 17/6/2016
* \details Se debe ingresar el código de operación a realizar (códigos según constantes simbólicas)
* Operaciones 
* \n 1) SUMA
* \n 2) RESTA
* \n 3) MULTIPLICACIÓN
* \n 4) DIVISIÓN
* \n 5) POTENCIA
* \n 6) RAÍZ CUADRADA
* \n 7) FACTORIAL
* \n 8) SUMAR A MEMORIA (M+)
* \n 9) RESTAR A MEMORIA (M-)
* \n 10) MOSTRAR MEMORIA (MR)
* \n 11) BORRAR MEMORIA (MC)
* \n 0) APAGAR
* \n La memoria se inicializa en 0
*******************************************************/
void calculadora (void)
{
  float a,b,memoria=0.;
  int opcion,aux,error,resultadoreal;
  printf("Ingrese número\n");
  scanf("%f",&a);
  printf("\nIngrese opción:\n%d = SUMA\n%d = RESTA\n%d = MULTIPLICACIÓN\n%d = DIVISIÓN\n%d = POTENCIA\n%d = RAÍZ CUADRADA\n%d = FACTORIAL\n",SUMA,RESTA,MULTIPLICACION,DIVISION,POTENCIA,RAIZCUADRADA,FACTORIAL);
  printf("%d = SUMAR A MEMORIA\n%d = RESTAR A MEMORIA\n%d = MOSTRAR MEMORIA\n%d = BORRAR MEMORIA\n%d = APAGAR\n",SUMAM,RESTAM,MR,MC,OFF);//En los carteles se respetan los valores de constantes simbólicas, sean cuales sean
  scanf("%d",&opcion);//Respetar valores de constantes simbólicas
  while (opcion!=OFF)
  {
    error=NO;
    if (opcion == SUMA || opcion == RESTA || opcion == MULTIPLICACION || opcion == DIVISION || opcion == POTENCIA)//Cuando se elige una de esas operaciones, se necesita otro número para hacer el cálculo
    {
      printf("\nIngrese número\n");
      scanf("%f",&b);
    }
    printf("\nOperación realizada: ");
    switch (opcion)
    {
      case SUMA:
	printf("SUMA\n");
	a=a+b;
	break;
      case RESTA:
	printf("RESTA\n");
	a=a-b;
	break;
      case MULTIPLICACION:
	printf("MULTIPLICACIÓN\n");
	a=a*b;
	break;
      case DIVISION:
	printf("DIVISIÓN\n");
	if (b)
	  a=a/b;
	else
	{
	  printf("\nError (no se puede dividir por 0)\n");
	  error=SI;
	}
	break;
      case POTENCIA:
	printf("POTENCIA\n");
	resultadoreal=SI;
	a=potencia(a,b,&resultadoreal);
	if (a==0 && resultadoreal==NO) //En caso de haber entrado a la función y no haber podido calcular la potencia (raíz de número negativo o 0 elevado a un número no positivo)
	{
	  printf("\nError (resultado fuera del campo de los reales)\n");
	  error=SI;
	}
	break;
      case RAIZCUADRADA:
	printf("RAÍZ CUADRADA\n");
	if (a>=0)
	  a=sqrt(a);
	else
	{
	  printf("\nError (no se puede calcular la raíz cuadrada de un número negativo)\n");
	  error=SI;
	}
	break;
      case FACTORIAL:
	printf("FACTORIAL\n");
	aux=(int)a;//Se evalúa si a es entero. Primero se guarda la parte entera de a en un auxiliar
	if (a>=0 && aux==a)//Ingresa por verdadero si a es entero positivo
	{
	  aux=factorial(aux);
	  a=(float)aux;
	}
	else
	{
	  printf("\nError (no se puede calcular el factorial de un número que no sea natural)\n");
	  error=SI;
	}
	break;
      case SUMAM://Sumar valor ingresado al guardado en memoria y guardar el resultado, pero no se opera con ese resultado
	printf("SUMAR A MEMORIA\n");
	memoria+=a;
	break;
      case RESTAM://Restar valor ingresado al guardado en memoria y guardar el resultado, pero no se opera con ese resultado
	printf("RESTAR A MEMORIA\n");
	memoria-=a;
	break;
      case MR://Mostrar e inicar operación con valor guardado en memoria
	printf("MOSTRAR MEMORIA\n");
	printf("¿Seguro quiere mostrar el valor guardado en memoria? No podrá operar con el último resultado o número ingresado y operará con el valor guardado en memoria\n%d = SÍ\n%d = NO\n",SI,NO);
	scanf("%d",&aux);
	if (aux==SI)
	  a=memoria;
	break;
      case MC://Borrar memoria (vuelve a 0) y empezar una nueva operación pidiendo ingresar un número
	printf("BORRAR MEMORIA\n");
	printf("¿Seguro quiere mostrar borrar la memoria? Tampoco podrá operar el último resultado o número ingresado\n%d = SÍ\n%d = NO\n",SI,NO);
	scanf("%d",&aux);
	if (aux==SI)
	{
	  memoria=0.;
	  printf("\nMemoria borrada. Vuelve a 0\n");
	  printf("\nIngrese número\n");
	  scanf("%f",&a);
	}
	break;
      default:
	printf("Opción no válida\n\n");//En caso de escribir un código no válido, se muestra una leyenda
	break;
    }
    if (opcion == SUMA || opcion == RESTA || opcion == MULTIPLICACION || opcion == DIVISION || opcion == POTENCIA || opcion == RAIZCUADRADA || opcion == FACTORIAL)//Si se hizo alguno de esos cálculos, mostrar resultado
      if (error==NO)
	printf("\nResultado = %f\n",a);
      else//En caso de error, se "reinicia" la calculadora, empezando a operar con un número a ingresar por teclado, pero no se borra la memoria
      {
	printf("\nIngrese número\n");
	scanf("%f",&a);
      }
    else if (opcion == SUMAM || opcion == RESTAM || opcion == MR)//Si se trabaja con memoria, mostrar valor o resultado de memoria (excepto en caso de borrarla)
    {
      printf("\nMemoria = %f\n",memoria);
      printf("\nSigue operando con = %f\n",a);
    }
    printf("\nIngrese opción:\n%d = SUMA\n%d = RESTA\n%d = MULTIPLICACIÓN\n%d = DIVISIÓN\n%d = POTENCIA\n%d = RAÍZ CUADRADA\n%d = FACTORIAL\n",SUMA,RESTA,MULTIPLICACION,DIVISION,POTENCIA,RAIZCUADRADA,FACTORIAL);
    printf("%d = SUMAR A MEMORIA\n%d = RESTAR A MEMORIA\n%d = MOSTRAR MEMORIA\n%d = BORRAR MEMORIA\n%d = APAGAR\n",SUMAM,RESTAM,MR,MC,OFF);//En los carteles se respetan los valores de constantes simbólicas, sean cuales sean
    scanf("%d",&opcion);
  }
}

/**
******************************************************
*  \fn float potencia (float a,float b)
*  \brief Calcula la potencia base^exponente
* \author Federico Ariel Marinzalda
* \version 1.0
* \date 15/5/2016
* \param[in] a base (número real)
* \param[in] b exponente (número real)
* \details
* Muestra mensaje con resultado de la potencia
* \n El programa permite mostrar resultados que sean números imaginarios
*******************************************************/
float potencia (float a,float b,int *resultadoreal)
{
  float bs,ex,r,retorno;
  int aux;
  bs=(a<0)?-a:a;
  ex=(b<0)?-b:b;
  if (a==0 && b<=0)
  {
    printf("No se puede calcular la potencia de %f elevado a la %f\n",a,b);
    retorno=0.;
    *resultadoreal=NO;
  }
  else
  {
    r=pow(bs,ex);
    if (b!=ex)
    {
      r=1/r;
    }
    if (a!=bs)
    {
      aux=(int)(10*ex);//Con la variable aux evalúo si el exponente múltiplicado por 10 es múltiplo de 4
      aux%=4;
      switch (aux)
      {
	case 0://Si es múltiplo de 4 r no varía respecto a la última cuenta que se realizó
	  printf("%.2f elevado a la %.2f es igual a %f\n",a,b,r);
	  retorno=r;
	  break;
	case 1://Si el resto es 1 el resultado es r imaginario (j r)
	  printf("%.2f elevado a la %.2f es igual a j %f\n",a,b,r);
	  retorno=0.;
	  *resultadoreal=NO;
	  break;
	case 2://Si el resto es 2 el resultado es -r
	  printf("%.2f elevado a la %.2f es igual a %f\n",a,b,-r);
	  retorno=r;
	  break;
	case 3://Si el resto es 3 el resultado es r imaginario (j r)
	  printf("%.2f elevado a la %.2f es igual a j %f\n",a,b,r);
	  retorno=0.;
	  *resultadoreal=NO;
	default:
	  break;
      }
    }
    else
    {
      printf("%.2f elevado a la %.2f es igual a %f\n",a,b,r);
      retorno=r;
    }
  }
  return retorno;
}

/**
******************************************************
*  \fn int factorial (int a)
*  \brief Cálculo de factorial de un número
* \author Federico Ariel Marinzalda
* \version 1.0
* \date 15/5/2016
* \param[in] n Número no negativo
* \param[out] r Factorial de n (r = n!)
* \return r (número entero)
*******************************************************/
int factorial (int a)
{
  int r=1,i;
  for (i=2;i<=a;i++)
    r=r*i;
  return r;
}