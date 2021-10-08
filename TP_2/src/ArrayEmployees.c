#include "ArrayEmployees.h"



/** \brief To indicate that all position in the array are empty,
* this function put the flag (isEmpty) in TRUE in all
* position of the array
* \param list Employee* Pointer to array of employees
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int initEmployees(Employee* list, int len)
{
	int retorno;
	retorno=0;
	int i;
	for(i=0; i<len; i++)
	{
		list[i].isEmpty = VACIO;
		retorno=1;
	}
	return retorno;
}



/**brief add in a existing list of employees the values received as parameters
*in the first empty position
*param list employee*
*param len int
*param id int
*param name[] char
*param lastName[] char
*param salary float
*param sector int
*return int Return (-1) if Error [Invalid length or NULL pointer or without
*free space] - (0) if Ok
*/
int addEmployee(Employee* list, int len){
	int retorno;
	retorno=0;


	list[len].isEmpty=LLENO;
	list[len].id=len;
	initChar(list[len].name,"Ingrese su Nombre: ");
	list[len].name[0]=  toupper (list[len].name[0]);
	initChar(list[len].lastName,"Ingrese su Apellido: ");
	list[len].lastName[0]=  toupper (list[len].lastName[0]);
	do{
		initFloat(&list[len].salary,"Ingrese su Salario: ");
	}while(list[len].salary<0);
	do{
		initInt(&list[len].sector,"Ingrese su Sector: ");
	}while(list[len].sector<0);

	retorno=1;

	mostrarUno(list, len);
	return retorno;
}
/// @fn void initChar(char*, char*)
/// @brief Deja al usuario ingresar un char
///
/// @param palabra
/// permite ingresar un char
/// @param mensaje
/// Muestra un mensaje por printf
void initChar(char* palabra,char* mensaje){
	printf("%s",mensaje);
	fflush(stdin);
	scanf("%s",palabra);
}
/// @fn void initInt(int*, char*)
/// @brief Deja al usuario ingresar un int
///
/// @param numero
/// permite ingresar un int
/// @param mensaje
/// Muestra un mensaje por printf
void initInt(int* numero,char* mensaje){
	printf("%s",mensaje);
	fflush(stdin);
	scanf("%d",&*numero);
}
/// @fn void initFloat(float*, char*)
/// @brief Deja al usuario ingresar un float
///
/// @param Flotante
///  permite ingresar un float
/// @param mensaje
/// Muestra un mensaje por printf
void initFloat(float* Flotante,char* mensaje){
	printf("%s",mensaje);
	fflush(stdin);
	scanf("%f",&*Flotante);
}
/// @fn void mostrar(int, char*, char*, char*)
/// @brief Muestra una respuesta segun el retorno que tenga
///
/// @param opcion
/// Usa el retorno para dar una respuesta
/// @param mesajeUno
/// Muestra un mensaje segun corresponda
/// @param mesajeDos
/// Muestra un mensaje segun corresponda
/// @param mesajeTres
/// Muestra un mensaje segun corresponda
void mostrar(int opcion,char* mesajeUno,char* mesajeDos,char* mesajeTres){
	switch(opcion){
		case -1:
			mostrarSolo(mesajeUno);
		break;
		case 0:
			mostrarSolo(mesajeDos);
		break;
		case 1:
			mostrarSolo(mesajeTres);
		break;
	}
}
/// @fn void mostrarSolo(char*)
/// @brief muestra un mensaje
///
/// @param mensaje
void mostrarSolo(char* mensaje){
	printf("%s\n",mensaje);
}
/// @fn int cambiar(Employee*, int)
/// @brief Pregunta ina ID, depues si queres eliminarlo y si queres lo elimina
///
/// @param list
/// Estructura de usuario
/// @param len
/// Cantidad de usuarios
/// @return
int cambiar(Employee* list, int len){
	int retorno;
	retorno=-1;
	int buscar;
	int pregunta;

	initInt(&buscar,"Ingrese la ID que busca: ");
	retorno=findEmployeeById(list, len,buscar);
	if(retorno==1){
		mostrarUno(list,buscar);
					do{
						initInt(&pregunta,"Seguro que quiere cambiarlo?(1-si / 2-no): ");
					}while(pregunta!= 1 && pregunta!= 2);

					if(pregunta==1){
						addEmployee(list,buscar);

					}else{
						retorno=-1;
					}
	}
	return retorno;
}
/** \brief find an Employee by Id en returns the index position in array.
*
* \param list Employee*
* \param len int
* \param id int
* \return Return employee index position or (-1) if [Invalid length or NULL
pointer received or employee not found]
*
*/
int findEmployeeById(Employee* list, int len,int id){
	int retorno;
	int i;
	retorno=0;


	for(i=0;i<len;i++){
		if(list[i+1].id==id && list[i+1].isEmpty==LLENO){

			retorno=1;
		}
	}
	return retorno;
}
/// @fn void mostrarDatos(Employee*, int)
/// @brief Muestra los datos ingresados en lista por un for.
///
/// @param list
/// @param len
void mostrarDatos(Employee* list, int len){
	int i;
	printf("   Apellido   Nombre    Salario   Sector \n");
	for(i=0;i<len;i++){
		if(list[i+1].isEmpty==1){
			mostrarUno(list,i+1);
		}

	}
}
/// @fn void mostrarUno(Employee*, int)
/// @brief Muestra un Empleado
///
/// @param list
/// @param listado
void mostrarUno(Employee* list, int listado){
	printf("%2d) %6s %10s %8.2f %7d\n",list[listado].id,list[listado].lastName,list[listado].name,list[listado].salary,list[listado].sector);
}
/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
*
* \param list Employee*
* \param len int
* \param id int
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a employee] - (0) if Ok
*
*/
int removeEmployee(Employee* list, int len){
	int retorno;
	retorno=0;
	int buscar;
	int pregunta;

	initInt(&buscar,"Ingrese la ID que busca: ");
	retorno=findEmployeeById(list, len,buscar);

	if(retorno==1){
		do{
			initInt(&pregunta,"Seguro que quiere cambiarlo?(1-si / 2-no): ");
		}while(pregunta!= 1 && pregunta!= 2);

		if(pregunta==1){

			list[buscar].isEmpty=0;

		}else{
				retorno=-1;
		}
	}
	mostrarDatos(list,  len);

	return retorno;
}


/** \brief Sort the elements in the array of employees, the argument order
indicate UP or DOWN order
*
* \param list Employee*
* \param len int
* \param order int [1] indicate UP - [0] indicate DOWN
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int sortEmployees(Employee* list, int len){
	int retorno;
	retorno=0;
	int i;
	int j;
	int auxiliarID;
	int auxuliarSector;
	char auxiliarNombre[30];
	char auxiliarApellido[30];
	float auxiliarSalario;
	for(i=1;i<len;i++){
		for(j=1;j<len;j++){
			if(strcmp(list[i].lastName,list[j].lastName)==-1 && list[i].sector > list[j].sector && list[i].isEmpty==LLENO && list[j].isEmpty==LLENO){

				 auxiliarID=list[i].id;
				 list[i].id=list[j].id;
				 list[j].id=auxiliarID;

				 auxuliarSector=list[i].sector;
				 list[i].sector=list[j].sector;
				 list[j].sector=auxuliarSector;

				 strcpy(auxiliarNombre,list[i].name);
				 strcpy(list[i].name,list[j].name);
				 strcpy(list[j].name,auxiliarNombre);

				 strcpy(auxiliarApellido,list[i].lastName);
				 strcpy(list[i].lastName,list[j].lastName);
				 strcpy(list[j].lastName,auxiliarApellido);

				 auxiliarSalario=list[i].salary;
				 list[i].salary=list[j].salary;
				 list[j].salary=auxiliarSalario;
				 retorno=1;
			}
		}
	}

	mostrarDatos(list, len);

	return retorno;
}
/// @fn void sacarPromedio(Employee*, int)
/// @brief Suma y promedia los salarios de los empleados.
/// Muestra e resultado
///
/// @param list
/// @param len
void sacarPromedio(Employee* list, int len){
	float suma;
	float promedio;
	suma=printEmployees(list, len);

	promedio=suma/len;

	printf("Suma de salarios : %.2f\nEl promedio de sueldo de %d usuario/s es %.2f\n",suma,len,promedio);
}
/** \brief print the content of employees array
*
* \param list Employee*
* \param length int
* \return int
*
*/
int printEmployees(Employee* list, int length){
	int i;
	float suma;
	suma=0;

	for(i=1;i<=length;i++){
		if(list[i].isEmpty==LLENO){
			suma=suma+list[i].salary;
		}
	}

	return suma;
}






