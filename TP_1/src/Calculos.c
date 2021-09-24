//Viñas Nicolas
#include "Biblioteca.h"

/// @fn void sumarNumeros(int*, int, int)
/// @brief Suma el entero numeroUno y numeroDos
/// Envia a la funcion menu el resultado
///
/// @param suma
/// Guarda el resultado y lo manda a la funcion que lo llamo
///
/// @param numeroUno
/// Primer numero ingresado
///
/// @param numeroDos
/// Segundo numero ingresado
///
void sumarNumeros(int* suma,int numeroUno,int numeroDos){
	*suma=numeroUno+numeroDos;
}

/// @fn void restarNumeros(int*, int, int)
/// @brief Resta el entero numeroUno y numeroDos
/// Envia a la funcion menu el resultado
///
/// @param resta
/// Guarda el resultado y lo manda a la funcion que lo llamo
///
/// @param numeroUno
/// Primer numero ingresado
///
/// @param numeroDos
/// Segundo numero ingresado
///
void restarNumeros(int* resta,int numeroUno,int numeroDos){
	*resta=numeroUno-numeroDos;
}

/// @fn void divicionDeNumeros(int*, int, int)
/// @brief Divide el entero numeroUno y numeroDos
/// Envia a la funcion menu el resultado
///
///
/// @param divicion
/// Guarda el resultado y lo manda a la funcion que lo llamo
///
/// @param numeroUno
/// Primer numero ingresado
///
/// @param numeroDos
/// Segundo numero ingresado
///
void divicionDeNumeros(int* divicion,int numeroUno,int numeroDos){
	*divicion=numeroUno/numeroDos;
}

/// @fn void multiplicacionDeNumeros(int*, int, int)
/// @brief Multiplica el entero numeroUno y numeroDos
/// Envia a la funcion menu el resultado
///
/// @param multiplicacion
/// Guarda el resultado y lo manda a la funcion que lo llamo
///
/// @param numeroUno
/// Primer numero ingresado
///
/// @param numeroDos
/// Segundo numero ingresado
///
void multiplicacionDeNumeros(int* multiplicacion,int numeroUno,int numeroDos){
	*multiplicacion=numeroUno*numeroDos;
}


/// @fn long int factorialDeNumeros(int)
/// @brief Factoriza un numero y lo devuleve a la funcion que llamo esta funcion
///
/// @param numero
/// El numero a factorial
///
/// @return factorial, devuelve el factorial del numero y lo manda a la funcion que lo llamo
long int factorialDeNumeros(int numero){

	float factorial = 1;

	if (numero != 1 && numero != 0 && numero >= 0)
	{
		factorial = numero * factorialDeNumeros(numero-1);
	}

	return factorial;
}

