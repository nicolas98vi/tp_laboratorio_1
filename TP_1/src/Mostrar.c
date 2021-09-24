//Viñas Nicolas
#include "Biblioteca.h"

/// @fn void aviso(int)
/// @brief muestra un mesaje.
/// si es 0 no se ingreso un numero.
/// si es 1 se calculo con exito.
///
/// @param ActivaAviso Es la bandera que se usa para desenlasar el mensaje.
void aviso(int ActivaAviso,int banderaA, int banderaB){
	if(ActivaAviso==1){
		printf(" ___________________\n| EXITO AL CALCULAR |\n '''''''''''''''''''\n");
	}else{
		if(banderaA!=1 || banderaB!=1){
			printf(" ___________________________\n| NO INGRESASTE LOS NUMEROS |\n '''''''''''''''''''''''''''\n");
		}else{
			printf(" _____________________________________\n| NO CALCULASTE LOS NUMEROS INGRESADOS |\n ''''''''''''''''''''''''''''''''''''''\n");

		}
	}

}


/// @fn void MostrarTodos(char*, char*, int)
/// @brief muestra el un mesnaje y el resultado de un calculo.
///
/// @param lista
/// Numero de listado de calculo.
///
/// @param signo
/// Signo del calculo.
///
/// @param resultado.
/// Muestra el entero resultado.
///
/// @param A.
/// Primer numero a calcular
/// @param B.
/// Segundo numero a calcular
void MostrarTodos(char* lista,char* signo, int resultado,int A,int B){
	printf("\n%c) El resultado de %d%c%d es: %d\n",*lista,A,*signo,B,resultado);
}


/// @fn void mostrarFactorial(int, int)
/// @brief muestra los dos numeros factorizados.
///
/// @param factorialUnoTerminado.
/// Primero entero ingresado factorizado.
/// @param factorialDosTerminado.
/// Segundo entero ingresado factorizado.
/// @param A.
/// Primer numero a calcular
/// @param B.
/// Segundo numero a calcular
void mostrarFactorial(int factorialUnoTerminado,int factorialDosTerminado,int A, int B){
	if(A<17 && A>=0){
		printf("\nEl factorial de %d es: %d",A,factorialUnoTerminado);
	}else{
		printf("\nEl %d no es factorizable!!!",A);
	}
	if(B<17 && B>=0){
		printf("\nEl factorial de %d es: %d",B,factorialDosTerminado);
	}else{
		printf("\nEl %d no es factorizable!!!",B);
	}
}

/// @fn void mostrarDatosIngresados(int, int, int, int)
/// @brief Muestra los numeros ingresados utilisables.
///
/// @param ingresadoUno
/// Bandera para saber si es necesario el printf.
///
/// @param ingresadoDos
/// Bandera para saber si es necesario el printf.
///
/// @param numeroUno
/// Primer numero ingresado calculable.
///
/// @param numeroDos
/// Segundo numero ingresado calculable.
///
void mostrarDatosIngresados(int ingresadoUno,int ingresadoDos,int numeroUno,int numeroDos){

	if(ingresadoUno==1){
		printf("\nEl primer numero ingresado es: %d\n",numeroUno);
	}
	if(ingresadoDos==1){
		printf("\nEl segundo numero ingresado es: %d\n",numeroDos);
	}
}
