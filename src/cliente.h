/*
 * cliente.h
 *
 *  Created on: 22 oct. 2021
 *      Author: ACantarini
 */

#ifndef CLIENTE_H_
#define CLIENTE_H_
#include "validaciones.h"
#include "localidad.h"

typedef struct
{
	int idCliente;
	char nombreEmpresa[50];
	int cuit;
	char calle[50];
	int numeroCalle;
	int idLocalidad;
	int acumuladorPP;
	int acumuladorPC;
	int isEmpty;
}eCliente;

int menu();
void inicializarCliente(eCliente clientes[], int tamCliente);
int buscarPosicionVaciaCliente(eCliente clientes[], int tamCliente, int* posicion);
int altaCliente(eCliente clientes[], eLocalidad localidades[], int tamLocalidad, int posicion, int id);
int buscarCliente(eCliente clientes[], int tamCliente, int id);
void mostrarCliente(eCliente cliente, eLocalidad localidades[], int tamLocalidad);
int mostrarClientes(eCliente clientes[], int tamCliente, eLocalidad localidades[], int tamLocalidades);
int bajaCliente(eCliente clientes[], int tamCliente, eLocalidad localidades[], int tamLocalidades);
void modificarCliente(eCliente clientes[], int tamCliente, eLocalidad localidades[], int tamLocalidades);
int subMenuModificarCliente();

#endif /* CLIENTE_H_ */
