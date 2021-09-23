#include "Biblioteca.h"


/// @fn int ingresoDeNumeros(char*, char*, int*)
/// @brief Da a ingresar un numero
///
/// @param mensaje
/// String inicialisado en la funcion menu para mostrase en un printf para marcar que ingrese un numero
///
/// @param mensageDeOrden
/// String inicialisado en la funcion menu para mostrase en un printf que avisa de su ingreso exitoso
///
/// @param numeroIngresar
/// Es un puntero de entero que guarda y envia al menu el numero ingresado
///
/// @return Retorna una bandera para confirmar de que se ingreso un numero entero
int ingresoDeNumeros(char* mensaje,char* mensageDeOrden,int* numeroIngresar){
	    int retorno;
	    int auxiliar;
	    retorno=0;


			printf("\n%s",mensaje);
			fflush(stdin);
			auxiliar=scanf("%d",&*numeroIngresar);
		/*do{
	    }while(!auxiliar);*/

		if(!auxiliar){
			printf("\n*ERROR* LO INGRESADO NO ES UN NUMERO\n");

		}else{
			retorno=1;
			printf("\n%s %d",mensageDeOrden,*numeroIngresar);
		}


		return retorno;
}
