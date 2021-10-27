/*
 * pedido.h
 *
 *  Created on: 24 oct. 2021
 *      Author: ACantarini
 */

#ifndef PEDIDO_H_
#define PEDIDO_H_
#include "cliente.h"

typedef struct
{
	int idPedido;
	int idCliente;
	int idTipoPlastico;
	int KilosTotalRecoleccion;
	char estado[20];
	int kilosHDPE;
	int kilosLDPE;
	int kilosPP;
	int isEmpty;
}ePedido;

void inicializarPedido(ePedido pedidos[], int tamPedido);
int buscarPosicionVaciaPedido(ePedido pedidos[], int tamPedido, int* posicion);
int buscarPedido(ePedido pedidos[], int tamPedido, int id);
int crearPedido(eCliente clientes[], int tamCliente,eLocalidad localidades[], int tamLocalidad,ePedido pedidos[],int id, int posicion);
void mostrarPedido(ePedido pedido);
void mostrarPedidos(ePedido pedidos[], int tamPedido);
int subMenuTipo();
int procesarResiduos(ePedido pedidos[], int tamPedidos, eCliente clientes[], int tamCliente);
void mostrarClienteConPP(eCliente cliente, eLocalidad localidades[], int tamLocalidad);
void mostrarClientesConPP(eCliente clientes[], int tamCliente, eLocalidad localidades[], int tamLocalidad);
int mostrarPedidosPendienteConCliente(ePedido pedidos[],int tamPedidos, eCliente clientes[], int tamClientes);
int mostrarPedidosCompletadosConCliente(ePedido pedidos[], int tamPedidos, eCliente clientes[], int tamClientes);

#endif /* PEDIDO_H_ */
