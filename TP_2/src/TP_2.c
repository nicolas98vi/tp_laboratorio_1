/*
 ============================================================================
 Name        : TP_2.c
 Author      : Viñas Nicolas
 Version     :
 Copyright   : Your copyright notice
 Description :
 El sistema deberá tener el siguiente menú de opciones:
1. ALTAS: Se debe permitir ingresar un empleado calculando automáticamente el número
de Id. El resto de los campos se le pedirá al usuario.
2. MODIFICAR: Se ingresará el Número de Id, permitiendo modificar: o Nombre o Apellido
o Salario o Sector
3. BAJA: Se ingresará el Número de Id y se eliminará el empleado del sistema.
4. INFORMAR:
1. Listado de los empleados ordenados alfabéticamente por Apellido y Sector.
2. Total y promedio de los salarios, y cuántos empleados superan el salario promedio.
 ============================================================================
 */


#include "ArrayEmployees.h"







int main(void) {
	setbuf(stdout, NULL);
	Employee arrayEmployees[TAM];
	int opcion;
	int cantidadProductos;
	cantidadProductos=0;
    int retorno;
    retorno=initEmployees(arrayEmployees, TAM);
    mostrar(retorno," ","No se logro inicializar con exito!","Se logro inicializar con exito!!!");



	do
	{

		initInt(&opcion,"-------------------------------------\n"
				 "1. ALTA producto\n"
				 "2. MODIFICACION producto\n"
				 "3. BAJA producto\n"
				 "4. Listado de los empleados ordenados alfabéticamente por Apellido y Sector\n"
				 "5. Total y promedio de los salarios, y cuántos empleados\n"
	             "6. SALIR\n"
				 "-------------------------------------\n"
				 "Ingrese una opcion: ");
		while(opcion<=0 || opcion>=7){
			initInt(&opcion,"-------------------------------------\n"
					"ERROR AL INGRESAR NUMERO"
					"1. ALTA producto\n"
					"2. MODIFICACION producto\n"
					"3. BAJA producto\n"
					"4. Listado de los empleados ordenados alfabéticamente por Apellido y Sector\n"
					"5. Total y promedio de los salarios, y cuántos empleados\n"
				    "6. SALIR\n"
					"-------------------------------------\n"
					"Ingrese una opcion valida: ");
		}
		switch(opcion)
		{
		   case 1:
			   cantidadProductos++;
			   retorno = addEmployee(arrayEmployees,cantidadProductos);
			   mostrar(retorno," ","No se logro dar de alta!","Se logro dar de alta!!!");
			   system("pause");
			break;
			case 2:
				if(cantidadProductos>0){
					retorno=cambiar(arrayEmployees,cantidadProductos);
					mostrar(retorno,"No se logro cambiar el usuario!","ERROR AL BUSCAR ID","Se logro cambiar el usuario!!!");
				}else{
					printf("No ingreso ningun usuario\n");
				}

				system("pause");

				break;
			case 3:
				if(cantidadProductos>0){
					retorno=removeEmployee(arrayEmployees,cantidadProductos);
					mostrar(retorno,"No se logro borrar el usuario!","ERROR AL BUSCAR ID","Se logro borrar el usuario!!!");
				}else{
					printf("No ingreso ningun usuario\n");
				}

				system("pause");
				break;
			case 4:
				if(cantidadProductos>0){
					sortEmployees(arrayEmployees,cantidadProductos);
				}else{
					printf("No ingreso ningun usuario\n");
				}

				system("pause");
				break;
			case 5:
			    sacarPromedio(arrayEmployees,cantidadProductos);
				system("pause");
				break;
			case 6:
				printf("Usted salio del programa\n");
				system("pause");
				break;
		}
	}while(opcion != 6);

	return EXIT_SUCCESS;
}

