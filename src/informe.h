/*
 * informe.h
 *
 *  Created on: 26 oct. 2021
 *      Author: ACantarini
 */

#ifndef INFORME_H_
#define INFORME_H_
#include "pedido.h"

int mostrarPedidosPorLocalidad(eLocalidad localidades[], int tamLocalidad, ePedido pedidos[], int tamPedido, eCliente clientes[], int tamCliente);
int buscarClienteConMasPP(eCliente clientes[], int tamCliente);
void mostrarClienteConMasPP(eCliente clientes[], int tamCliente,eLocalidad localidades[], int tamLocalidad, int cantidadMasCliente);
void mostrarClienteConPC(eCliente cliente, eLocalidad localidades[], int tamLocalidad);
int buscarClienteConMasPC(eCliente clientes[], int tamCliente);
void mostrarClienteConMasPC(eCliente clientes[], int tamCliente,eLocalidad localidades[], int tamLocalidad, int cantidadMasCliente);
void cantidadPoplipropilenoxCliente(ePedido pedidos[], int tamPedido);
void mostrarClienteConMasPPyPC(ePedido pedidos[], int tamPedido, eCliente clientes[], int tamCliente, eLocalidad localidades[], int tamLocalidades);


#endif /* INFORME_H_ */
