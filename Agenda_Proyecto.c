
#include<windows.h>
#include "primary_operations.h"


void menu(void); 
void subMenu(void);

 
int main()
{
	FILE *base;
	char nombre[] = "DATA BASE.txt";
	
	if((base = fopen(nombre,"r+t")) != NULL){
		archivo(base);
	}
	
	menu();
	
	return 0;	
} 

void menu(void)
{
	int op;
	
	do {
		system("cls");
		puts("\n|---------------------------------------|");
		puts("\t\tREGISTRO");
		puts("\n  MENU");
		puts(" (1) AGREGAR NUEVO REGISTRO");
		puts(" (2) MODIFICAR UN REGISTRO PARTICULAR");
		puts(" (3) BORRAR UN REGISTRO");
		puts(" (4) MOSTRAR REGISTROS");
		puts(" (5) SALIR");
		printf("\nDigite una opcion: ");
		scanf("%d",&op);
		
		switch(op) {
			case 1:
				NuevoRegistro();
				break;
			case 2:
				ModificarNodo();
				break;
			case 3:
				EliminarNodo();
				break;
			case 4:
				subMenu();		
				break;	
			case 5:
				break;	
			default:
				printf("OPCION INVALIDA!");			
		}
			
	}while(op != 5);
	
	ImpListaArchivo();
}

void subMenu()
{
	int op;
	
	system("cls");
	do {
		puts("\n|---------------------------------------|");
		puts("\t\tREGISTRO\n\n");
		puts(" (1) MOSTAR TODOS LOS REGISTROS");
		puts(" (2) MOSTRAR RESGISTRO ESPECIFICO");
		puts(" (3) MENU PRINCIPAL");
		printf("\n Digite una opcion: ");
		scanf("%d",&op);
		if(op < 1 || op > 5) {
			printf("\nOPCION INVALIDA!..\n\n");
			system("pause");
		}
		system("cls");
	}while(op > 3 || op < 1);
	
	switch(op) {
		case 1:
			MostrarLista();
			break;
		case 2:
			MostrarNodo();
			break;
		default:
			break;
				
	}
}



