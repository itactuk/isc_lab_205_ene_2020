#include<stdlib.h>
#include<stdio.h>
#include<string.h>

typedef struct todo_contenido{
	int x;
	char * t;
	int cant_elementos_t;
	int z[10];
} TODO_CONTENIDO;

void print_cont(TODO_CONTENIDO cont);
TODO_CONTENIDO leer_todo_contenido(char * arch);
void escribe_todo_contenido(char * arch, TODO_CONTENIDO cont);

int main(int n, int ** args){
	TODO_CONTENIDO cont;
	char * archivo;
	char buff[250];
	archivo = buff;
	if (n>1){ // tiene archivo por parametro
		archivo = args[1];
		printf("He recibido el archivo '%s' por parametro\n",archivo); 
	}else{// no tiene archivo por parametro
		printf("Digite archivo\n");
		scanf("%s", archivo);
	}
	printf("Usando el archivo %s\n", archivo); 
	cont = leer_todo_contenido(archivo);
	print_cont(cont);
	
	int i;
	printf("Digite el indice d t que quiere eliminar: ");
	scanf("%d", &i);
	for(int j=i; j<cont.cant_elementos_t-1;j++){
		cont.t[j] = cont.t[j+1];
	}
	cont.cant_elementos_t--;
	cont.t = realloc(cont.t, cont.cant_elementos_t  * sizeof(char));
	/*
	 cont.t[0] ='A';
	cont.t[1] ='B'; 
	cont.t[2] ='D';
	
	 * */
	
	/*
	cont.x = 24;
	cont.cant_elementos_t = 4;
	cont.t = realloc(cont.t, cont.cant_elementos_t  * sizeof(char));
	cont.t[0] ='A';
	cont.t[1] ='B'; 
	cont.t[2] ='C';
	cont.t[3] ='D';
	* */

	escribe_todo_contenido(archivo, cont);
	
	print_cont(cont);
}

void print_cont(TODO_CONTENIDO cont){
	printf("Todo contenido: \n");
	printf("x: %d\n", cont.x);
	printf("t:");
	for(int i=0; i<cont.cant_elementos_t ; i++){
		printf("%c", cont.t[i]);
	}
	printf("\n");
	printf("z:");
	for(int i=0; i<10; i++){
		printf("%d,", cont.z[i]);
	}
	printf("\n");
}

TODO_CONTENIDO leer_todo_contenido(char * arch){
	FILE * f = fopen(arch, "r");
	TODO_CONTENIDO cont;
	if (f == NULL){
		cont.x = -1;
		return cont;
	}
	fread(&cont, sizeof(TODO_CONTENIDO), 1, f);
	cont.t = malloc(cont.cant_elementos_t * sizeof(char));
	fread(cont.t, sizeof(char), cont.cant_elementos_t, f);
	fclose(f);
	return cont;
}

void escribe_todo_contenido(char * arch, TODO_CONTENIDO cont){
	FILE * f = fopen(arch, "w");
	fwrite(&cont, sizeof(TODO_CONTENIDO), 1, f);
	fwrite(cont.t, sizeof(char), cont.cant_elementos_t, f);
	fclose(f);
}
