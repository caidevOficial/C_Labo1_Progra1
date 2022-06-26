/*
 * ============================================================================
 * This program is free software: you can redistribute it and/or modify it under
 * the terms of the GNU General Public License as published by the Free Software
 * Foundation, either version 3 of the License, or (at your option) any later
 * version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE. See the GNU General Public License for more
 * details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program. If not, see <http://www.gnu.org/licenses/>.
 * ============================================================================
 * 							#Biblioteca
 *
 * About: Versionar
 * El primero (X) se le conoce como version mayor y nos indica la version
 * 		principal del software. Ejemplo: 1.0.0, 3.0.0
 * El segundo (Y) se le conoce como version menor y nos indica nuevas funcionalidades.
 * 		Ejemplo: 1.2.0, 3.3.0
 * El tercero (Z) se le conoce como revision y nos indica que se hizo una revision del
 * 		codigo por algun fallo. Ejemplo: 1.2.2, 3.3.4
 *
 * Version     : 1.1.1 [Release Candidate v1.1]
 *
 * @author	CaiDev - FacuFalcone
 * ============================================================================
 */

#include <stdio.h>
#include <string.h>
#include "Sector.h"
#include "Empleado.h"

#ifndef CAIDEV_ESTRUCTURA_H_
#define CAIDEV_ESTRUCTURA_H_

char menuInforme();
int informes(eEmpleado vec[], char opcion, int tam, eSector sectores[], int tamSec);
void informarTotalSueldos(eEmpleado vec[], int tam);
void informarEmpleadosDeSector(eEmpleado vec[], int tam, eSector sectores[], int tamSec);
void informarMayorSueldoSector(eEmpleado vec[], int tam, eSector sectores[], int tamSec);
void informarEmpleadoCostosoSector(eEmpleado vec[], int tam, eSector sectores[], int tamsec);
void aumentarSueldosSector(eEmpleado vec[],int tam,eSector sectores[], int tamsec);
float obtenerTotalSueldosSector(int idSector, eEmpleado vec[], int tam);
void informarSectorCostoso(eEmpleado vec[],int tam, eSector sectores[], int tamsec);
void informarTotalSueldoPorSector(eEmpleado vec[],int tam, eSector sectores[], int tamsec);
void cantidadEmpleadosPorSector(eEmpleado vec[],int tam, eSector sectores[], int tamsec);
void informeEmpleadoMasJoven(eEmpleado vec[],int tam, eSector sectores[], int tamsec);

#endif
