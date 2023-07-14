#include<stdlib.h>

typedef struct reg
{
	char *IdCliente;
	char *Nombre;
	char *ApPaterno;
	char *ApMaterno;
    int mes;
    int dia;
    int anio;                     
	int credito;
	int deuda;
	struct reg *sig;	
 }reg;                          

enum Mes
{
	Enero = 1,
	Febrero,
	Marzo,
	Abril,
	Mayo,
	Junio,
	Julio,
	Agosto,
	Septiembre,
	Octubre,
	Noviembre,
	Diciembre
};

reg *primero = NULL;
reg *ultimo = NULL;