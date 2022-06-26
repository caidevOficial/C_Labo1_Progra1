/*
 * Empleado.h
 *
 *  Created on: 8 may. 2020
 *      Author: Facu
 */
#include "caidevDataWareHouse.h"
#include "Sector.h"

#ifndef BIBLIOTECA_EMPLEADO_H_
#define BIBLIOTECA_EMPLEADO_H_

/**
 * @struct	Fecha
 * @brief
 */
typedef struct{
	int dia;
	int mes;
	int anho;
}eFecha;

typedef struct{
	int id;
	char nombre[20];
	char sexo;
	int edad;
	float sueldo;
	int idSector;
	int isEmpty; // 0=false 1=true
	eFecha fechaIngreso;
	eFecha fechaNacimiento;
}eEmpleado;

/**
 * @fn int menu()
 * @brief
 * @return
 */
int menu();

/**
 * @fn void cargarEmpleado(eEmpleado)
 * @brief	Carga un empleado en la estructura.
 * @param	emp es el empleado a cargar.
 */
void cargarEmpleado(eEmpleado emp);

/**
 * @fn void mostrarEmpleado(eEmpleado)
 * @brief	Muestra un empleado cargado.
 * @param	emp el empleado a mostrar.
 */
void mostrarEmpleado(eEmpleado emp, eSector sectores[], int tamSec);

/**
 * @fn void mostrarEmpleados(eEmpleado[], int)
 * @brief	Muestra una lista de empleados.
 * @param	vec lista de empleados.
 * @param	tam tamanho de la lista.
 */
void mostrarEmpleados(eEmpleado vec[], int tam, eSector sector[], int tamSec);

/**
 * @fn void ordenarEmpleados(eEmpleado[], int)
 * @brief	Ordena la lista de empleados segun sexo y salario.
 * @param	vec lista a ordenar.
 * @param	tam tamanho de lista.
 */
void ordenarEmpleados(eEmpleado vec[], int tam);

/**
 * @fn void ordenarEmpleadosPorNombre(eEmpleado[], int)
 * @brief
 * @param lista
 * @param cantidad
 */
void ordenarEmpleadosPorNombre(eEmpleado lista[], int cantidad);

/**
 * @fn void ordenarEmpleadosPorSexoyNombre(eEmpleado[], int)
 * @brief
 * @param lista
 * @param cantidad
 */
void ordenarEmpleadosPorSexoyNombre(eEmpleado lista[], int cantidad);

/**
 * @fn void inicializarEmpleados(eEmpleado[], int)
 * @brief
 * @param vec
 * @param tam
 */
void inicializarEmpleados(eEmpleado vec[], int tam);


/**
 * @fn int buscarLibre(eEmpleado[], int)
 * @brief
 * @param vec
 * @param tam
 * @return
 */
int buscarLibre(eEmpleado vec[], int tam);

/**
 * @fn int buscarEmpleado(int, eEmpleado[], int)
 * @brief
 * @param id
 * @param vec
 * @param tam
 * @return
 */
int buscarEmpleado(int id, eEmpleado vec[], int tam, eSector sectores[], int tamSec);

/**
 * @fn int asignarID(int*, int*)
 * @brief
 * @param idActual
 * @param idProxima
 * @return
 */
//int asignarID(int* idActual, int* idProxima);

/**
 * @fn void altaEmpleado(eEmpleado[], int)
 * @brief
 * @param vec
 * @param tam
 */
int altaEmpleado(eEmpleado vec[], int tam, eSector sectores[], int tamSec);//, int* nextID);

/**
 * @fn void bajaEmpleado(eEmpleado[], int)
 * @brief
 * @param vec
 * @param tam
 */
void bajaEmpleado(eEmpleado vec[], int tam, eSector sectores[], int tamSec);

/**
 * @fn void modificarEmpleado(eEmpleado[], int)
 * @brief
 * @param vec
 * @param tam
 */
void modificarEmpleado(eEmpleado vec[], int tam, eSector sectores[], int tamSec);

/**
 * @fn void listarEmpleadasMujeres(eEmpleado[], int, eSector[], int)
 * @brief
 * @param vec
 * @param tam
 * @param sectores
 * @param tamSec
 */
void listarEmpleadasMujeres(eEmpleado vec[], int tam, eSector sectores[], int tamSec);

/**
 * @fn void listarEmpleadosPorAnio(eEmpleado[], int, eSector[], int)
 * @brief
 * @param vec
 * @param tam
 * @param sectores
 * @param tamSec
 */
void listarEmpleadosPorAnio(eEmpleado vec[], int tam, eSector sectores[], int tamSec);

/**
 * @fn int cargarDescripcionSector(char[], int, eSector[], int)
 * @brief
 * @param descripcion
 * @param idSector
 * @param sectores
 * @param tamSec
 * @return
 */
int cargarDescripcionSector(char descripcion[], int idSector,eSector sectores[], int tamSec);

/**
 * @fn int cargarNombreEmpleado(char[], int, eEmpleado[], int)
 * @brief
 * @param nombre
 * @param idSector
 * @param empleados
 * @param tam
 * @return
 */
int cargarNombreEmpleado(char nombre[], int idSector,eEmpleado empleados[], int tam);

/**
 * @fn void hardcodear(eEmpleado[], int)
 * @brief
 * @param vec
 * @param cant
 */
void hardcodear(eEmpleado vec[], int cant);

#endif /* BIBLIOTECA_EMPLEADO_H_ */
