#include "second_operations.h"

void NuevoRegistro(void);
void MostrarLista(void);
void MostrarNodo(void);
void EliminarNodo(void);
void ModificarNodo();
int ModificarNodoElem(reg *actual); 
void ImpListaArchivo();


void NuevoRegistro()
{
	int flag = 0;
	reg *nuevo = (reg*)malloc(sizeof(reg));
	if(nuevo == NULL) {
		puts("ERROR DE ASIGNACION DE MEMORIA");
		exit(-1);
	}
	
	do {
		printf("\nIdCliente: ");
		nuevo->IdCliente = s2();
		flag = ValidID(nuevo->IdCliente);
	}while(!flag);
	
	printf("Nombre: ");
	nuevo->Nombre = s2(); 
	
	printf("Apellido Paterno: "); 
	nuevo->ApPaterno = s2();
	
	printf("Apellido Materno: ");
	nuevo->ApMaterno = s2();
	
	printf("Fecha\n ");
	do {
		printf("Mes (MM): ");
		scanf("%d",&nuevo->mes);
		if(nuevo->mes < Enero || nuevo->mes > Diciembre )
			puts("\rDATO INVALIDO! ");
	}while(nuevo->mes < Enero || nuevo->mes > Diciembre);

	do {
		do {
			printf("Dia (DD): ");
			scanf("%d",&nuevo->dia);
			if(nuevo->dia < 1 || nuevo->dia > 31)
				printf("ERROR DE FECHA!\nVerifique sus datos.\n");
		}while(nuevo->dia < 1 || nuevo->dia > 31);
		printf("Anio (AAAA): ");
		scanf("%d",&nuevo->anio);
		if(nuevo->anio < 999 || nuevo->anio > 3000 || nuevo->dia > DiaMes(nuevo->anio, nuevo->mes))
			puts("\nDATO INVALIDO! "); 
	}while(nuevo->anio < 999 || nuevo->anio > 3000 || nuevo->dia > DiaMes(nuevo->anio, nuevo->mes));
	
	Credito(&nuevo->credito);
	
	Deuda(&nuevo->deuda);
	
	if(primero == NULL) {
		primero = nuevo;
		primero->sig = NULL;
		ultimo = nuevo;
	}
	else {
		ultimo->sig = nuevo;
		ultimo = nuevo;
		ultimo->sig = NULL;
	}
	
	puts("REGISTRO GUARDADO CON EXITO!");
	system("pause");
	system("cls"); 
	 
}

void MostrarLista(void)
{
	reg *actual;
	actual = primero;
	
	if(primero != NULL) {
		printf("%10s%13s%16s%15s%14s%18s%14s\n\n","IDCliente","Nombre","ApPaterno","ApMaterno","Fecha","Credito","Deuda");
		while(actual != NULL) {
			printf("%5s%18s%16s%15s",actual->IdCliente,actual->Nombre,actual->ApPaterno,actual->ApMaterno);
			printf("%10d/%02d/%02d%16d%14d\n",actual->anio,actual->mes,actual->dia,actual->credito,actual->deuda);
			actual = actual->sig;
		}
		printf("\n");
	}
	else {
		printf("La agenda esta vacia\n");
	}
	
	system("pause");
	
}

void MostrarNodo()
{
	char *dato;
	reg *actual = (reg*)malloc(sizeof(reg));
	actual = primero;
	
	printf("Ingrese el IDCliente/Nombre para mostrar: ");
	dato = s2();

	if(primero != NULL) {
		printf("%10s%13s%16s%15s%14s%18s%14s\n\n","IDCliente","Nombre","ApPaterno","ApMaterno","Fecha","Credito","Deuda");
		while(actual != NULL) {
			if(!(strcmp(actual->IdCliente,dato)) || !(strcmp(dato,actual->Nombre))) {
				printf("%5s%18s%16s%15s",actual->IdCliente,actual->Nombre,actual->ApPaterno,actual->ApMaterno);
				printf("%10d/%02d/%02d%16d%14d\n",actual->anio,actual->mes,actual->dia,actual->credito,actual->deuda);
			}
			actual = actual->sig;
		}
		printf("\n");
	}
	else {
		printf("REGISTRO BUSCADO INEXISTENTE!\n");
	}
	
	system("pause");
}

void EliminarNodo()
{
	char *id;
	int flag = 0;
	reg *actual;
	actual = primero;
	
	printf("Ingrese el ID de la persona a eliminar: ");
	id = s2();

	while((actual != NULL) && !flag) {
		flag = (strcmp(actual->IdCliente,id) == 0);
		if(!flag) {
			ultimo = actual;
			actual = actual->sig;
		}
	}
	
	if(actual != NULL) {
		if(actual == primero) {
			primero = actual->sig;
		}
		else {
			ultimo->sig = actual->sig;
		}
		printf("REGISTRO BORRADO EXITOSAMENTE!\n");
		free(actual);
	}
	else
		printf("El IDCliente no existe\n");
	
	system("pause");
}

void ModificarNodo()
{
	int flag = 0;
	char *dato;
	reg *actual = (reg*)malloc(sizeof(reg));
	actual = primero;
	
	printf("Ingrese el IDCliente buscado: ");
	dato = s2();

	if(primero != NULL) {
		while(actual != NULL && !flag) {
			if(!(strcmp(actual->IdCliente,dato))) {
				printf("\n%10s%13s%16s%15s%14s%18s%14s\n\n","IDCliente","Nombre","ApPaterno","ApMaterno","Fecha","Credito","Deuda");
				printf("%5s%18s%16s%15s",actual->IdCliente,actual->Nombre,actual->ApPaterno,actual->ApMaterno);
				printf("%10d/%02d/%02d%16d%14d\n",actual->anio,actual->mes,actual->dia,actual->credito,actual->deuda);
				flag = ModificarNodoElem(actual);
                if(flag){
                    puts("REGISTRO MODIFICADO EXITOSAMENTE!");
                    break;
                } else {
                    puts("REGISTRO NO MOFICADO CORRECTAMENTE!");
                    break;
                }
			}
			actual = actual->sig;
			if(actual == NULL) {
				puts("\nEl IDCliente ingresado no existe, por favor verifique nuevamente sus datos");
			}
		}
		printf("\n");
	}
	else {
		puts("La lista se encuentra vacia");
	}
	
	system("pause");	
}

int ModificarNodoElem(reg *actual)
{
	int op, flag = 0;	
	puts("\n");
	puts(" (1) IDCliente");
	puts(" (2) Nombre");
	puts(" (3) Apellido Paterno");
	puts(" (4) Apellido Materno");
	puts(" (5) Fecha");
	puts(" (6) Credito");
	puts(" (7) Deuda");
	puts(" (8) Volver atras");
	printf("Elija una opcion: ");
	scanf("%d",&op);
	switch(op) {
		case 1:
			do {
				printf("\nIdCliente: ");
				actual->IdCliente = s2();
				flag = ValidID(actual->IdCliente);
			}while(!flag);
			break;
		case 2:
			printf("Nombre: ");
			actual->Nombre = s2();
			break;
		case 3:
			free(actual->ApPaterno);
			printf("Apellido Paterno: "); 
			actual->ApPaterno = s2();
			break;
		case 4:
			printf("Apellido Materno: ");
			actual->ApMaterno = s2();
			break;
		case 5:
			do {
				printf("Mes (MM): ");
				scanf("%d",&actual->mes);
				if(actual->mes < Enero || actual->mes > Diciembre )
					puts("\rDATO INVALIDO! ");
			}while(actual->mes < Enero || actual->mes > Diciembre);

			do {
					do {
						printf("Dia (DD): ");
						scanf("%d",&actual->dia);
						if(actual->dia < 1 || actual->dia > 31)
							printf("ERROR DE FECHA!\nVerifique sus datos.\n");
					}while(actual->dia < 1 || actual->dia > 31);
					printf("Anio (AAAA): ");
					scanf("%d",&actual->anio);
					if(actual->anio < 999 || actual->anio > 3000 || actual->dia > DiaMes(actual->anio, actual->mes))
						puts("\nDATO INVALIDO! "); 
				}while(actual->anio < 999 || actual->anio > 3000 || actual->dia > DiaMes(actual->anio, actual->mes));
			break;
		case 6:
			Credito(&actual->credito);
			break;
		case 7:
			Deuda(&actual->deuda);
			break;
		default:
			puts("OPCION INVALIDA!");
            system("pause");
            return 0;								
	}
	
    return 1;
}

void ImpListaArchivo()
{
	FILE *archivo;
	char nombre[] = "DATA BASE.txt";
	
	if((archivo = fopen(nombre,"wt")) == NULL) {
		puts("ERROR EN LA APERTURA DEL ARCHIVO");
		exit(-1);
	}
	
	reg *actual;
	actual = primero;
	
	if(primero != NULL) {
		
		while(actual != NULL) {
			fprintf(archivo,"%s %s %s %s",actual->IdCliente,actual->Nombre,actual->ApPaterno,actual->ApMaterno);
			fprintf(archivo," %d %02d %02d %d %d\n",actual->anio,actual->mes,actual->dia,actual->credito,actual->deuda);
			actual = actual->sig;
		}
		printf("\n");
	}
	else {
		printf("La agenda esta vacia\n");
	}
	
	fclose(archivo);	
}