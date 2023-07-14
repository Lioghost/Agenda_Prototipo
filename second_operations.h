#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<windows.h>
#include "struct_client.h"

#define anio_bisiesto(y)  ((((y)%400)==0)||((((y)%4)==0)&&(((y)%100)!=0)))
#define V 35

char *s2(void); 
int ValidID(char *id);
void archivo(FILE *base);
void vaciar(char datos[],int x);
char *convertir(FILE *base);
int conv_ent(FILE *base);
int *Credito(int *credito);
int *Deuda(int *deuda);
int DiaMes(int y, int m);


char *s2(void)
{
	char *cad, cd[V]; 
	scanf("%s",cd);
	cad = (char*)calloc(strlen(cd)+1,sizeof(char));   
	if(cad == NULL) {
		puts("ERROR EN LA ASIGNACION DE MEMORIA");
		exit(-1);
	}
	strcpy(cad,cd);
	
	return cad;
}

int ValidID(char *id)
{
	reg *pos;
	pos = primero;
	while(pos != NULL) {
		if(!(strcmp(id,pos->IdCliente))) {
			puts("El IDCliente ya esta siendo usado por otra persona");
			puts("Ingrese un IDCliente distinto");
			return 0;
		}
		
		pos = pos->sig;
	}
	
	return 1;
}

void archivo(FILE *base)
{
	reg *nuevo;
	//char aux, datos[35] = {0};
    char line[100];
	
    while(fgets(line, sizeof(line), base) != NULL)
    {
        if(!feof(base)) {
			nuevo = (reg*)malloc(sizeof(reg));
			if(nuevo == NULL) {
				puts("ERROR DE ASIGNACION DE MEMORIA");
				exit(-1);
				}
		}

        line[strcspn(line, "\n")] = '\0';

        nuevo->IdCliente = strdup(strtok(line, " "));
        nuevo->Nombre = strdup(strtok(NULL, " "));
        nuevo->ApPaterno = strdup(strtok(NULL, " "));
        nuevo->ApMaterno = strdup(strtok(NULL, " "));
        nuevo->anio = atoi(strtok(NULL, " "));
        nuevo->mes = atoi(strtok(NULL, " "));
        nuevo->dia = atoi(strtok(NULL, " "));
        nuevo->credito = atoi(strtok(NULL, " "));
        nuevo->deuda = atoi(strtok(NULL, " "));

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

    }
		
	fclose(base);
}

void vaciar(char datos[],int x)
{
	int i;
	
	for(i = 0;i < x;i++) {
		datos[i] = '\0';
	}
}


int *Credito(int *credito)
{
	int s;
	
	do {
		printf("Credito: ");
		scanf("%d",&s);
		if(s < 0){
			puts("\nDATO INVALIDO! ");
			puts("INGRESE UNA CANTIDAD MAYOR A CERO");
		}
	}while(s < 0);
	
	*credito = s;
	
	return credito;
}

int *Deuda(int *deuda)
{
	int s;
	
	do {
		printf("Deuda: ");
		scanf("%d",&s);
		if(s < 0){
			puts("\nDATO INVALIDO! ");
			puts("INGRESE UNA CANTIDAD MAYOR A CERO");
		}
	}while(s < 0);
	
	*deuda = s;
	
	return deuda;
}

int DiaMes(int y, int m)
{
	const int dias[] = { 31, 28, 31, 30, 31, 30,
                        31, 31, 30, 31, 30, 31 };
   int resultado = 0;
   resultado = dias[m-1];
 
   if(m == Febrero && anio_bisiesto ( y ))
      resultado++;   
 
   return resultado;
}


