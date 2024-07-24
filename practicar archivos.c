//1//
/*
#include <stdio.h>
#include <stdbool.h>

void cargar_archivo(FILE*archivo){
	bool terminar=true;
	int numero;
	while(terminar==true){
		printf("ingrese un numero entero positivo (negativo para terminar):");
		scanf("%i",&numero);
		if (numero<0){
			terminar=false;
		}
		else{
			fwrite(&numero,sizeof(numero),1,archivo);
		}
	}
}
void calcular_factorial(int*num){
	int i,resultado=1;
	for(i=1;i<=(*num);i++){
		resultado*=i;		
	}
	(*num)=resultado;
}

void calcular_factoriales_y_escribirlos(FILE*archivo_viejo,FILE*archivo_nuevo){
	int numero;
	fread(&numero,sizeof(numero),1,archivo_viejo);
	while(!feof(archivo_viejo)) {
		printf("\n%i",numero);
		calcular_factorial(&numero);
		printf("\n%i",numero);
		fwrite(&numero,sizeof(numero),1,archivo_nuevo);
		fread(&numero,sizeof(numero),1,archivo_viejo);
	}
}

int main() {
    FILE* archivo_numeros = NULL;
    FILE* archivo_factoriales = NULL;

    archivo_numeros = fopen("numeros_enteros_ejercicio1.dat", "wb");
    if (archivo_numeros==NULL) {
        printf("No se pudo abrir el archivo");
        return 1;
    }else{
    	cargar_archivo(archivo_numeros);
    	fclose(archivo_numeros);
	}
    archivo_numeros=fopen("numeros_enteros_ejercicio1.dat", "rb");
    archivo_factoriales=fopen("numeros_factoriales_ejercicio1.dat", "wb");
    if (archivo_numeros==NULL||archivo_factoriales==NULL) {
        printf("No se pudo abrir los archivos");
        return 1;
    }
    else{
    	calcular_factoriales_y_escribirlos(archivo_numeros, archivo_factoriales);
    	fclose(archivo_numeros);
    	fclose(archivo_factoriales);
	}
    return 0;
}
*/
//2//
/*
#include <stdio.h>
#include <stdbool.h>
void cargar_archivo_enteros(FILE*numeros_enteros){
numeros_enteros=fopen("archivo_enteros_ejercicio2.dat","wb");
if (numeros_enteros==NULL){
	printf("hubo un error al abrir el archivo");
}
else{
	bool seguir=true;
	int numero;
	while(seguir==true){
		printf("ingrese un numero entero mayor a 1(1 o numero menor para terminar):");
		scanf("%i",&numero);
		if(numero<2){
			seguir=false;
		}
		else{
			fwrite(&numero,sizeof(numero),1,numeros_enteros);
		}
	}
	fclose(numeros_enteros);
}
}

void mostrar_archivo_enteros(FILE*archivo_enteros){
archivo_enteros=fopen("archivo_enteros_ejercicio2.dat","rb");
if (archivo_enteros==NULL){
	printf("hubo un error al abrir el archivo");
}
else{
	int numero;
	printf("los numeros del archivo son:");
	fread(&numero,sizeof(numero),1,archivo_enteros);
	while(!feof(archivo_enteros)){
		printf("%i\t",numero);
		fread(&numero,sizeof(numero),1,archivo_enteros);
	}
	fclose(archivo_enteros);
}
}

bool es_primo(int numero){
	bool es_primo;
	int i;
	es_primo=true;
	for(i=2;i<numero;i++){
		if(numero%i==0){
			es_primo=false;
		}
	}
return es_primo;
}

void leer_enteros_y_cargar_primos(FILE*archivo_enteros,FILE*archivo_primos){
archivo_enteros=fopen("archivo_enteros_ejercicio2.dat","rb");
archivo_primos=fopen("archivo_primos_ejercicio2.dat","wb");
if (archivo_enteros==NULL||archivo_primos==NULL){
	printf("hubo un error al abrir los archivos");
}
else{
	int numero;
	fread(&numero,sizeof(numero),1,archivo_enteros);
	while(!feof(archivo_enteros)){
		if((es_primo(numero))==true){
			fwrite(&numero,sizeof(numero),1,archivo_primos);
		}
		fread(&numero,sizeof(numero),1,archivo_enteros);
	}
	fclose(archivo_enteros);
	fclose(archivo_primos);
}
}

void mostrar_archivo_primos(FILE*archivo_primos){
archivo_primos=fopen("archivo_primos_ejercicio2.dat","rb");
	if (archivo_primos==NULL){
	printf("hubo un error al abrir el archivo");
}
else{
	int numero;
	printf("\nlos numeros primos del archivo son:");
	fread(&numero,sizeof(numero),1,archivo_primos);
	while(!feof(archivo_primos)){
		printf("%i\t",numero);
		fread(&numero,sizeof(numero),1,archivo_primos);
	}
	fclose(archivo_primos);
}	
}

int main(){
	FILE*archivo_enteros;
	FILE*archivo_primos;
	cargar_archivo_enteros(archivo_enteros);
	leer_enteros_y_cargar_primos(archivo_enteros,archivo_primos);
	mostrar_archivo_enteros(archivo_enteros);
	mostrar_archivo_primos(archivo_primos);	
return 0;
}

*/

//3//
/*
#include <stdio.h>
#include <stdbool.h>
void cargar_archivo_enteros(FILE*numeros_enteros){
numeros_enteros=fopen("archivo_enteros_ejercicio3.dat","wb");
if (numeros_enteros==NULL){
	printf("hubo un error al abrir el archivo");
}
else{
	bool seguir=true;
	int numero;
	while(seguir==true){
		printf("ingrese un numero entero desde el 0 al 255 (numero negativo o mayor a 255 para terminar):");
		scanf("%i",&numero);
		if(numero<0 || numero>255){
			seguir=false;
		}
		else{
			fwrite(&numero,sizeof(numero),1,numeros_enteros);
		}
	}
	fclose(numeros_enteros);
}
}

void mostrar_archivo_enteros(FILE*archivo_enteros){
archivo_enteros=fopen("archivo_enteros_ejercicio3.dat","rb");
if (archivo_enteros==NULL){
	printf("hubo un error al abrir el archivo");
}
else{
	int numero;
	printf("los numeros del archivo son:");
	fread(&numero,sizeof(numero),1,archivo_enteros);
	while(!feof(archivo_enteros)){
		printf("%i ",numero);
		fread(&numero,sizeof(numero),1,archivo_enteros);
	}
	fclose(archivo_enteros);
}
}

void leer_archivo_mostrar_ascii(FILE*archivo_enteros){
archivo_enteros=fopen("archivo_enteros_ejercicio3.dat","rb");
if (archivo_enteros==NULL){
	printf("hubo un error al abrir el archivo");
}
else{
	int numero;
	printf("el texto en ascii es:");
	fread(&numero,sizeof(numero),1,archivo_enteros);
	while(!feof(archivo_enteros)){
		printf("%c",numero);
		fread(&numero,sizeof(numero),1,archivo_enteros);
	}
	fclose(archivo_enteros);
}
}

int main(){
FILE*archivo;
cargar_archivo_enteros(archivo);
mostrar_archivo_enteros(archivo);
leer_archivo_mostrar_ascii(archivo);	
return 0;}
*/
//4//
/*
#include <stdio.h>
#include <stdbool.h>
bool tiene_cinco_digitos(int numero) {
    int digitos = 0;
    int temp = numero;
	bool es_valido=false;
    if (temp < 0) {
        temp = -temp; // Cambiamos el signo del número
    }
    while (temp != 0) {
        temp /= 10;
        digitos++;
    }
	if(digitos==5){
		es_valido=true;
	}
	
    return es_valido;
}

void cargar_archivo1(FILE*archivo1){
archivo1=fopen("archivo_numeros5digitos1_ejercicio4.dat","wb");
if (archivo1==NULL){
	printf("no se pudo abrir el archivo");
}
else{
	printf("carga de datos del archivo1");
	bool seguir=true;
	while(seguir==true){
		int numero;
		printf("\ningrese un numero de 5 digitos de menor a mayor(cualquier numero que no sea de 5 digitos termina la operacion):");
		scanf("%i",&numero);
		if(tiene_cinco_digitos(numero)==false){
			seguir=false;
		}
		else{
			fwrite(&numero,sizeof(numero),1,archivo1);
		}
	}
	fclose(archivo1);
}
}
void cargar_archivo2(FILE*archivo2){
archivo2=fopen("archivo_numeros5digitos2_ejercicio4.dat","wb");
if (archivo2==NULL){
	printf("no se pudo abrir el archivo");
}
else{
	printf("carga de datos del archivo 2");
	bool seguir=true;
	while(seguir==true){
		int numero;
		printf("\ningrese un numero de 5 digitos ordenados de menor a mayor(cualquier numero que no sea de 5 digitos termina la operacion):");
		scanf("%i",&numero);
		if(tiene_cinco_digitos(numero)==false){
			seguir=false;
		}
		else{
			fwrite(&numero,sizeof(numero),1,archivo2);
		}
	}
	fclose(archivo2);
}
}

void juntar_archivos(FILE*archivo1,FILE*archivo2,FILE*archivo_final){
archivo1=fopen("archivo_numeros5digitos1_ejercicio4.dat","rb");
archivo2=fopen("archivo_numeros5digitos2_ejercicio4.dat","rb");
archivo_final=fopen("archivo_finalordenado_ejercicio4.dat","wb");

if(archivo1==NULL||archivo2==NULL||archivo_final==NULL){
	printf("no se pudo abrir alguno de los archivos");
}
else{
	int numero1,numero2;
	fread(&numero1,sizeof(numero1),1,archivo1);
	fread(&numero2,sizeof(numero1),1,archivo2);
	while((!feof(archivo1)) &&(!feof(archivo2))){
		if(numero1>numero2){
			fwrite(&numero2,sizeof(numero2),1,archivo_final);
			fread(&numero2,sizeof(numero2),1,archivo2);
		}
		else{
			fwrite(&numero1,sizeof(numero1),1,archivo_final);
			fread(&numero1,sizeof(numero1),1,archivo1);
		}
	}
	while(!feof(archivo1)) {
        fwrite(&numero1, sizeof(numero1), 1, archivo_final);
        fread(&numero1, sizeof(numero1), 1, archivo1);
    }
    while (!feof(archivo2)) {
        fwrite(&numero2, sizeof(numero2), 1, archivo_final);
        fread(&numero2, sizeof(numero2), 1, archivo2);
    }
	fclose(archivo1);
	fclose(archivo2);
	fclose(archivo_final);
}
}

void mostrar_archivo_final(FILE*archivo_final){
archivo_final=fopen("archivo_finalordenado_ejercicio3.dat","rb");
if(archivo_final==NULL){
	printf("hubo un error al abrir el archivo");
}
else{
	int numero;
	fread(&numero,sizeof(numero),1,archivo_final);
	while(!feof(archivo_final)){
		printf("%i ",numero);
		fread(&numero,sizeof(numero),1,archivo_final);
	}
	fclose(archivo_final);
}
}


int main(){
	FILE*archivo1;
	FILE*archivo2;
	FILE*archivo_final;
	cargar_archivo1(archivo1);
	cargar_archivo2(archivo2);
	juntar_archivos(archivo1,archivo2,archivo_final);
	mostrar_archivo_final(archivo_final);
return 0;}
*/
//5//
/*
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define MAXP 50 
#define MAXN 3
typedef char nombre_apellido[MAXP];
typedef nombre_apellido Tvec_nombres[MAXN];

void cargar_archivo(FILE*archivo_desordenado){
	archivo_desordenado=fopen("nombres_desordenados_ejercicio5.dat","wb");
	if(archivo_desordenado==NULL){
		printf("no se pudo abrir el archivo");
	}
	else{
		bool seguir=true;
		int i=0;
		nombre_apellido nombre;
		while(seguir==true && i<MAXN){
			printf("ingrese un nombre y apellido(ingrese 0 para terminar la carga):");
			fgets(nombre,MAXP,stdin);
			fflush(stdin);
			nombre[strcspn(nombre,"\n")]='\0';
			if(nombre[0]=='0'){
				seguir=false;
			}
			else{
				fwrite(nombre,sizeof(nombre),1,archivo_desordenado);
				i++;
			}
		}
		fclose(archivo_desordenado);
	}	
}

void cargar_datos_en_vector(FILE*archivo_desordenado,Tvec_nombres nombres,int*ml){
	archivo_desordenado=fopen("nombres_desordenados_ejercicio5.dat","rb");
	if(archivo_desordenado==NULL){
		printf("no se pudo abrir el archivo");
	}
	else{
		int i;
		i=(*ml);
		nombre_apellido nombre;
		fread(nombre,sizeof(nombre),1,archivo_desordenado);
		while(!feof(archivo_desordenado) && i<MAXN){
			strcpy(nombres[i],nombre);
			i++;
			fread(nombre,sizeof(nombre),1,archivo_desordenado);
		}
		(*ml)=i;
		printf("%i",(*ml));
		fclose(archivo_desordenado);
	}	
}

void ordenar_vector(Tvec_nombres nombres,int ml){
	int i=1,j,comparacion;
	nombre_apellido nombreaux;
	bool cambios=true;
	while(cambios=true && i<ml){
		cambios=false;
		for(j=0;j<ml-1;j++){
			comparacion=strcmp(nombres[j],nombres[j+1]);
			if (comparacion>0){
				strcpy(nombreaux,nombres[j]);
				strcpy(nombres[j],nombres[j+1]);
				strcpy(nombres[j+1],nombreaux);
				cambios=true;
			}
		}
		i++;	
	}
}

void cargar_vector_ordenado_en_archivo_nuevo(Tvec_nombres nombres,int ml,FILE*archivo_ordenado){
	archivo_ordenado=fopen("archivo_ordenado_ejercicio5.dat","wb");	
	if(archivo_ordenado==NULL){
		printf("no se pudo abrir el archivo");
	}
	else{
		int i;
		for(i=0;i<ml;i++){
			fwrite(nombres[i],sizeof(nombres[i]),1,archivo_ordenado);
		}
		fclose(archivo_ordenado);
	}
}


void leer_ordenado(FILE*archivo_ordenado){
	archivo_ordenado=fopen("archivo_ordenado_ejercicio5.dat","rb");	
	if(archivo_ordenado==NULL){
		printf("no se pudo abrir el archivo");
	}
	else{
		nombre_apellido cadena;
		fread(cadena,sizeof(cadena),1,archivo_ordenado);
		while(!feof(archivo_ordenado)){
			printf("\nnombre y apellido:%s",cadena);
			fread(cadena,sizeof(cadena),1,archivo_ordenado);
		}
		fclose(archivo_ordenado);
	}
}
	
int main(){
	FILE*archivo_desordenado;
	FILE*archivo_ordenado;
	Tvec_nombres nombres;
	int ml=0;
	cargar_archivo(archivo_desordenado);
	cargar_datos_en_vector(archivo_desordenado,nombres,&ml);
	ordenar_vector(nombres,ml);
	cargar_vector_ordenado_en_archivo_nuevo(nombres,ml,archivo_ordenado);
	leer_ordenado(archivo_ordenado);
return 0;
}	
*/
//6A 6B//
/*
#include <stdio.h>
#include <stdbool.h>
typedef struct{
	int caracteristica_de_localidad;
	int caracteristica_central;
	int numero;
}numero_de_telefono;
bool tiene_tres_digitos(int numero) {
    int digitos = 0;
    int temp = numero;
	bool es_valido=false;
    if (temp < 0) {
        temp = -temp; // Cambiamos el signo del número
    }
    while (temp != 0) {
        temp /= 10;
        digitos++;
    }
	if(digitos==3){
		es_valido=true;
	}
	
    return es_valido;
}
bool tiene_cuatro_digitos(int numero) {
    int digitos = 0;
    int temp = numero;
	bool es_valido=false;
    if (temp < 0) {
        temp = -temp; // Cambiamos el signo del número
    }
    while (temp != 0) {
        temp /= 10;
        digitos++;
    }
	if(digitos==4){
		es_valido=true;
	}
	
   	return es_valido;
}

void cargar_archivo(FILE*archivo_desordenado){
	archivo_desordenado=fopen("archivo_numeros_desordenado_ejercicio6.dat","wb");
	if(archivo_desordenado==NULL){
		printf("no se pudo abrir el archivo");
	}
	else{
		bool seguir=true;
		numero_de_telefono telefono;
		while(seguir==true){
			printf("la manera correcta de ingresar un numero es:(4 digitos) (3 digitos) (4 digitos) hay que tener en cuenta los espacios en el medio \nun ejemplo correcto seria 5491 125 2819");
			printf("\ningrese el numero de telefono(el numero negativo tambien debe de ser de (4) (3) (4) cifras para terminar):");
			scanf("%i %i %i",&telefono.caracteristica_de_localidad,&telefono.caracteristica_central,&telefono.numero);
			while(tiene_cuatro_digitos(telefono.caracteristica_de_localidad)==false||tiene_tres_digitos(telefono.caracteristica_central)==false||tiene_cuatro_digitos(telefono.numero)==false){
				printf("\ningreso mal el numero de telefono la manera de ingresarlos son:\ncaracteristica de localidad(4 digitos)(espacio)caracteristica central(3 digitos)(espacio)numero de telefono(4 digitos)(enter)");
				printf("\nvuelva a ingresar un numero de telefono(el numero negativo tambien debe de ser de (4) (3) (4) cifras para terminar):");
				scanf("%i %i %i",&telefono.caracteristica_de_localidad,&telefono.caracteristica_central,&telefono.numero);
			}
			if(telefono.caracteristica_de_localidad<0 || telefono.caracteristica_central<0 || telefono.numero<0){
				seguir=false;
			}
			else{
				fwrite(&telefono,sizeof(telefono),1,archivo_desordenado);
			}
		}
		fclose(archivo_desordenado);
	}
}

void leer_archivo_listar_segun_caracteristica_de_localidad_pedida1(FILE*archivo_desordenado,int caracteristica_de_localidad,FILE*archivo_numeros_por_localidad){
	archivo_desordenado=fopen("archivo_numeros_desordenado_ejercicio6.dat","rb");
	archivo_numeros_por_localidad=fopen("archivo_por_localidad_numeros_desordenados_ejercicio6.dat","wb");
	if(archivo_desordenado==NULL||archivo_numeros_por_localidad==NULL){
		printf("no se pudo abrir los archivos");
	}
	else{
		numero_de_telefono telefono;
		fread(&telefono,sizeof(telefono),1,archivo_desordenado);
		while(!feof(archivo_desordenado)){
			if(telefono.caracteristica_de_localidad==caracteristica_de_localidad){
				printf("\nnumero de telefono con caracteristica %i:%i%i%i",caracteristica_de_localidad,telefono.caracteristica_de_localidad,telefono.caracteristica_central,telefono.numero);
				fwrite(&telefono,sizeof(telefono),1,archivo_numeros_por_localidad);
			}
			fread(&telefono,sizeof(telefono),1,archivo_desordenado);
		}
		fclose(archivo_desordenado);
		fclose(archivo_numeros_por_localidad);	
	}
}

void leer_archivo_de_numeros1(FILE*archivo_desordenado){
	archivo_desordenado=fopen("archivo_por_localidad_numeros_desordenados_ejercicio6.dat","rb");
	if(archivo_desordenado==NULL){
		printf("no se pudo abrir el archivo");
	}
	else{
		numero_de_telefono telefono;
		fread(&telefono,sizeof(telefono),1,archivo_desordenado);
		while(!feof(archivo_desordenado)){
			printf("\nnumero de telefono:%i%i%i",telefono.caracteristica_de_localidad,telefono.caracteristica_central,telefono.numero);
			fread(&telefono,sizeof(telefono),1,archivo_desordenado);
		}
		fclose(archivo_desordenado);
	}
}

void cargar_archivo_2(FILE*archivo_ordenado){
	archivo_ordenado=fopen("archivo_numeros_ordenado_ejercicio6.dat","wb");
	if(archivo_ordenado==NULL){
		printf("no se pudo abrir el archivo");
	}
	else{
		bool seguir=true;
		numero_de_telefono telefono;
		while(seguir==true){
			printf("\ningresar los numeros de telefono de menor a mayor de forma ascendente o creciente");
			printf("la manera correcta de ingresar un numero es:(4 digitos) (3 digitos) (4 digitos) hay que tener en cuenta los espacios en el medio \nun ejemplo correcto seria 5491 125 2819");
			printf("\ningrese el numero de telefono(el numero negativo tambien debe de ser de (4) (3) (4) cifras para terminar):");
			scanf("%i %i %i",&telefono.caracteristica_de_localidad,&telefono.caracteristica_central,&telefono.numero);
			while(tiene_cuatro_digitos(telefono.caracteristica_de_localidad)==false||tiene_tres_digitos(telefono.caracteristica_central)==false||tiene_cuatro_digitos(telefono.numero)==false){
				printf("\ningresar los numeros de telefono de menor a mayor de forma ascendente o creciente");
				printf("\ningreso mal el numero de telefono la manera de ingresarlos son:\ncaracteristica de localidad(4 digitos)(espacio)caracteristica central(3 digitos)(espacio)numero de telefono(4 digitos)(enter)");
				printf("\nvuelva a ingresar un numero de telefono(el numero negativo tambien debe de ser de (4) (3) (4) cifras para terminar):");
				scanf("%i %i %i",&telefono.caracteristica_de_localidad,&telefono.caracteristica_central,&telefono.numero);
			}
			if(telefono.caracteristica_de_localidad<0 || telefono.caracteristica_central<0 || telefono.numero<0){
				seguir=false;
			}
			else{
				fwrite(&telefono,sizeof(telefono),1,archivo_ordenado);
			}
		}
		fclose(archivo_ordenado);
	}
}

void leer_archivo_listar_segun_caracteristica_de_localidad_pedida2(FILE*archivo_ordenado,int caracteristica_de_localidad,FILE*archivo_numeros_por_localidad){
	archivo_ordenado=fopen("archivo_numeros_ordenado_ejercicio6.dat","rb");
	archivo_numeros_por_localidad=fopen("archivo_por_localidad_numeros_ordenados_ejercicio6.dat","wb");
	if(archivo_ordenado==NULL||archivo_numeros_por_localidad==NULL){
		printf("no se pudo abrir los archivos");
	}
	else{
		numero_de_telefono telefono;
		fread(&telefono,sizeof(telefono),1,archivo_ordenado);
		while((!feof(archivo_ordenado)) && (telefono.caracteristica_de_localidad<=caracteristica_de_localidad) ){
			if(telefono.caracteristica_de_localidad==caracteristica_de_localidad){
				printf("\nnumero de telefono con caracteristica %i:%i%i%i",caracteristica_de_localidad,telefono.caracteristica_de_localidad,telefono.caracteristica_central,telefono.numero);
				fwrite(&telefono,sizeof(telefono),1,archivo_numeros_por_localidad);
			}
			fread(&telefono,sizeof(telefono),1,archivo_ordenado);
		}
		fclose(archivo_ordenado);
		fclose(archivo_numeros_por_localidad);	
	}
}

void leer_archivo_de_numeros2(FILE*archivo_ordenado){
	archivo_ordenado=fopen("archivo_por_localidad_numeros_ordenados_ejercicio6.dat","rb");
	if(archivo_ordenado==NULL){
		printf("no se pudo abrir el archivo");
	}
	else{
		numero_de_telefono telefono;
		fread(&telefono,sizeof(telefono),1,archivo_ordenado);
		while(!feof(archivo_ordenado)){
			printf("\nnumero de telefono:%i%i%i",telefono.caracteristica_de_localidad,telefono.caracteristica_central,telefono.numero);
			fread(&telefono,sizeof(telefono),1,archivo_ordenado);
		}
		fclose(archivo_ordenado);
	}
}

int main(){
	FILE*archivo_desordenado;
	FILE*listado_de_numeros1;
	FILE*archivo_ordenado;
	FILE*listado_de_numeros2;
	cargar_archivo(archivo_desordenado);
	int numero1,numero2;
	printf("ingrese un prefijo de localidad(4 digitos) a buscar en la lista:");
	scanf("%i",&numero1);
	while(tiene_cuatro_digitos(numero1)==false){
		printf("ingrese un prefijo de localidad(4 digitos) a buscar en la lista:");
		scanf("%i",&numero1);
	} 
	leer_archivo_listar_segun_caracteristica_de_localidad_pedida1(archivo_desordenado,numero1,listado_de_numeros1);
	leer_archivo_de_numeros1(listado_de_numeros1);
	cargar_archivo_2(archivo_ordenado);
	printf("ingrese un prefijo de localidad(4 digitos) a buscar en la lista:");
	scanf("%i",&numero2);
	while(tiene_cuatro_digitos(numero2)==false){
		printf("ingrese un prefijo de localidad(4 digitos) a buscar en la lista:");
		scanf("%i",&numero2);
	} 
	leer_archivo_listar_segun_caracteristica_de_localidad_pedida2(archivo_ordenado,numero2,listado_de_numeros2);
	leer_archivo_de_numeros2(listado_de_numeros2);	
return 0;
}
*/
//7//
/*
#include <stdio.h>
#include <stdbool.h>
void eleminar_espacios_superfluos(FILE*archivo_superfluos,FILE*archivo_final){
	archivo_superfluos=fopen("archivo_superfluos_ejercicio7.txt","r");
	archivo_final=fopen("archivo_sin_superfluos_ejrcicio7.txt","w");
	if (archivo_superfluos==NULL||archivo_final==NULL){
		printf("hubo un error al abrir los archivos");
	}
	else{
		bool espacio_anterior=false;
		char caracter;
		caracter=fgetc(archivo_superfluos);
		while(!feof(archivo_superfluos)){
			if(caracter==' '||caracter=='\t'||caracter=='\n'||caracter=='\r'){
				if(espacio_anterior==false){
					fputc(caracter,archivo_final);
					espacio_anterior=true;
				}
			}
			else{
				espacio_anterior=false;
				if(caracter=='.'){
					fputc(caracter,archivo_final);
					caracter='\n';
					fputc(caracter,archivo_final);
				}
				else{
					fputc(caracter,archivo_final);
				}
			}
			caracter=fgetc(archivo_superfluos);
		}
		fclose(archivo_superfluos);
		fclose(archivo_final);
	}
}

int main(){
	FILE*archivo_con_espacios;
	FILE*archivo_sin_espacios;
	eleminar_espacios_superfluos(archivo_con_espacios,archivo_sin_espacios);
	printf("excelente proceso");
return 0;}	
*/	
//8//
/*
#include <stdio.h>
#define MAX 100
typedef char cadena[MAX];
int contar_cantidad_palabras(FILE*archivo){
	int cantidad_palabras=-1;
	archivo=fopen("archivo_texto_ejercicio8.txt","r");
	if(archivo==NULL){
		printf("error al abrir el archivo");
	}
	else{	
		cantidad_palabras=0;
		cadena palabra;
		fscanf(archivo,"%s",palabra);
		while(!feof(archivo)){
			cantidad_palabras++;
			fscanf(archivo,"%s",palabra);
		}
		fclose(archivo);
	}
return cantidad_palabras;
}

int contar_cantidad_letras(FILE*archivo){
	int cantidad_letras=-1;
	archivo=fopen("archivo_texto_ejercicio8.txt","r");
	if(archivo==NULL){
		printf("error al abrir el archivo");
	}
	else{	
		cantidad_letras=0;
		char caracter;
		caracter=fgetc(archivo);
		while(!feof(archivo)){
			if ((caracter>='A'&& caracter<='Z')||(caracter>='a'&& caracter<='z')||(caracter>='á'&& caracter<='Ñ')||(caracter=='é')){
				cantidad_letras++;
			}
		caracter=fgetc(archivo);	
		}
		fclose(archivo);
	}
return cantidad_letras;
}

int main(){
	FILE*archivo;
	int letras=contar_cantidad_letras(archivo);
	int palabras=contar_cantidad_palabras(archivo);
	printf("\n%i",letras);
	printf("\n%i",palabras);
	printf("\nla longitud promedio de las palabras es de %i letras",(letras/palabras));
	printf("\nla cantidad de palabras es de:%i",palabras);		
return 0;}
*/
//faltan hacer los ejercicios 9 y 10 de la guia de archivos y otra cosa para ver es como hice las cosas en los archivos de texto ver si los puedo hacer de otra manera//
	
	
















	
	
	
	
	