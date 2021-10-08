#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "ctype.h"
#define TAM 100
#define LLENO 1
#define VACIO 0

struct{
int id;
char name[51];
char lastName[51];
float salary;
int sector;
int isEmpty;
}typedef Employee;


int initEmployees(Employee producto[], int tam);
int addEmployee(Employee* list, int len);
void initChar(char* palabra,char* mensaje);
void initInt(int* numero,char* mensaje);
void initFloat(float* Flotante,char* mensaje);


void mostrar(int opcion,char* mesajeUno,char* mesajeDos,char* mesajeTres);
void mostrarSolo(char* mensaje);

int cambiar(Employee* list, int len);
int findEmployeeById(Employee* list, int len,int id);

void mostrarDatos(Employee* list, int len);
void mostrarUno(Employee* list, int listado);

int removeEmployee(Employee* list, int len);

int sortEmployees(Employee* list, int len);

void sacarPromedio(Employee* list, int len);
int printEmployees(Employee* list, int length);
