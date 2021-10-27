/*
 * localidad.h
 *
 *  Created on: 22 oct. 2021
 *      Author: ACantarini
 */

#ifndef LOCALIDAD_H_
#define LOCALIDAD_H_
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int idLocalidad;
	char nombre[50];
	int isEmpty;
}eLocalidad;

void mostrarLocalidades(eLocalidad localidades[], int tam);

#endif /* LOCALIDAD_H_ */

