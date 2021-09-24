//Viñas Nicolas
#include "Biblioteca.h"


/// @fn void menu(void)
/// @brief Menu de interaccion con el usuario y inicializador de funciones
///
void menu(void){
	int primerOperador;
	int segundoOperador;

	int suma;
	int resta;
	int divicion;
	int multiplicacion;
	int factorialUno;
	int factorialDos;

	int opcion;
	int banderaUno;
	int banderaDos;
	int bandera;
	bandera=0;


	do{
		printf("\n ________________ \n| MENU PRINCIPAL |\n '''''''''''''''' \n1. Ingresar 1er operando (A=x)\n2. Ingresar 2do operando (B=y)\n3. Calcular todas las operaciones\n4. Informar resultados\n5. Salir de calculadora");
		mostrarDatosIngresados( banderaUno, banderaDos, primerOperador, segundoOperador);
		printf("\nIngrese un numero de la lista:");
		fflush(stdin);
		scanf("%d",&opcion);



		if(opcion==1 || opcion==2 || opcion==3 || opcion==4 || opcion==5){
			switch(opcion){
		    case 1:
		    banderaUno=ingresoDeNumeros("\nIngrese el primer numero: ","\nINGRESADO CON EXITO\n\nUsted ingreso en el primer numero :",&primerOperador);
			break;
		    case 2:
		    banderaDos=ingresoDeNumeros("\nIngrese el segundo numero: ","\nINGRESADO CON EXITO\n\nUsted ingreso en el segundo numero :",&segundoOperador);
			break;
		    case 3:
			if(bandera==0 &&banderaDos==1&&banderaUno==1){
				bandera=1;
				printf("\na) Calcular la suma (%d+%d)\nb) Calcular la resta (%d-%d)\nc) Calcular la division (%d/%d)\nd) Calcular la multiplicacion (%d*%d)\ne) Calcular el factorial (%d!) y Calcular el factorial (%d!)\n",primerOperador,segundoOperador,primerOperador,segundoOperador,primerOperador,segundoOperador,primerOperador,segundoOperador,primerOperador,segundoOperador);
				aviso(bandera, banderaUno, banderaDos);
				sumarNumeros(&suma,primerOperador,segundoOperador);

				restarNumeros(&resta,primerOperador,segundoOperador);

				divicionDeNumeros(&divicion, primerOperador, segundoOperador);

				multiplicacionDeNumeros(&multiplicacion, primerOperador, segundoOperador);


				factorialUno=factorialDeNumeros(primerOperador);
				factorialDos=factorialDeNumeros(segundoOperador);

			}else{
				aviso(bandera, banderaUno, banderaDos);
			}
			break;
		    case 4:

			if( banderaDos==1&&banderaUno==1 && bandera==1){

				MostrarTodos("a" ,"+",suma,primerOperador,segundoOperador);
				MostrarTodos("b" ,"-",resta,primerOperador,segundoOperador);
				if(primerOperador!=0 || segundoOperador!=0){
					MostrarTodos("c" ,"/",divicion,primerOperador,segundoOperador);
				}else{
					printf("\nNo es posible dividir por cero\n");
				}

				MostrarTodos("d" ,"*",multiplicacion,primerOperador,segundoOperador);

				mostrarFactorial( factorialUno, factorialDos,primerOperador,segundoOperador);
				bandera=0;
			}else{
				aviso(bandera, banderaUno, banderaDos);
			}
			break;
		    case 5:
			printf("\nSALIO DE LA CALCULADORA");
			break;
		  }
		}else{
			printf("\nINGRESE UNA OPCION VALIDA!!!");
		}

	}while(opcion!=5);
}


