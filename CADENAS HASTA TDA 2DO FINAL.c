//////////GUIA DE CADENAS//////////

//1//
/*
#include <stdio.h>
int contar_numeros(char cadena[]){ 
int i=0,contador=0; 
 while(cadena[i]!='\0'){ 
		if(cadena[i]>='0' && cadena[i]<='9'){
			contador++; 
		} 
	i++;	
} 
return contador;}
*/
//2//
/*
#include <stdio.h> 
int contar_no_alfabeticos(char cadena[]){ 
int i=0,contador=0; 
while(cadena[i]!='\0'){ 
	if(!((cadena[i]>='a' && cadena[i]<='z')||(cadena[i]>='A' && cadena[i]<='Z')||cadena[i]=='á'||cadena[i]=='Á'||cadena[i]=='é'||cadena[i]=='É'||cadena[i]=='í'||cadena[i]=='Í'||cadena[i]=='ó'||cadena[i]=='Ó'||cadena[i]=='ú'||cadena[i]=='Ú'||cadena[i]=='ñ'||cadena[i]=='Ñ')){ 
		contador++; 
	} 
i++; 
} 
return contador;}
*/
//3//
/*
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define MAX 50
typedef char t_cadena[MAX];

int cantidad_palabras(t_cadena cadena){
	int cantidad_de_palabras=0,i=0;
	bool en_palabra=false;;
	while(cadena[i]!='\0'){
		if (cadena[i]==' '||cadena[i]=='\n'||cadena[i]=='\t'){
			en_palabra=false;
		}
		else{
			if(en_palabra==false){
				cantidad_de_palabras++;
                en_palabra=true;
			}
		}	
	i++;	
	}	
return cantidad_de_palabras;}

int cant_palabras(t_cadena cadena){
	int cant=0,i;
	if(cadena[0]!=' ' && cadena[0]!='\0')
		cant=1;
	for(i=1;i<strlen(cadena);i++){
		if(cadena[i]!=' ' && cadena[i-1]==' ')
			cant++;
	}
	return cant;
}

int main(){
	t_cadena cadena1,cadena2,cadena3,cadena4,cadena5;
	strcpy(cadena1, "El sol es amarillo.");
    strcpy(cadena2, " Hoy es 30 de Junio de 2021 ");
    strcpy(cadena3, "30/06/2021");
    strcpy(cadena4, "El precio es $2.000.- ");
    strcpy(cadena5, "      ");
	printf("\nel numero de palabras es: %i",cantidad_palabras(cadena1));
	printf("\nel numero de palabras es: %i",cantidad_palabras(cadena2));
	printf("\nel numero de palabras es: %i",cantidad_palabras(cadena3));
	printf("\nel numero de palabras es: %i",cantidad_palabras(cadena4));
	printf("\nel numero de palabras es: %i",cantidad_palabras(cadena5));
	printf("\nel numero de palabras es: %i",cant_palabras(cadena1));
	printf("\nel numero de palabras es: %i",cant_palabras(cadena2));
	printf("\nel numero de palabras es: %i",cant_palabras(cadena3));
	printf("\nel numero de palabras es: %i",cant_palabras(cadena4));
	printf("\nel numero de palabras es: %i",cant_palabras(cadena5));	
return 0;}
*/
//4//
/*
#include <stdio.h>
#include <string.h>
#define MAX 50

typedef char t_cadena[MAX];

void invertir_cadena(t_cadena cadena,t_cadena cadena_invertida){
	int i,j=(strlen(cadena)-1);
	for(i=0;i<strlen(cadena);i++){
		if (!(cadena[i]=='\n'||cadena[i]=='\t'||cadena[i]==' ')){
			cadena_invertida[j]=cadena[i];
		}
		j--;
	}
cadena_invertida[strlen(cadena)]='\0';
}

void invertir_cadena(t_cadena cadena, t_cadena invertida){
	int i,j=0;
	i=strlen(cadena)-1;
	while(i>=0){
		if(cadena[i]!=' '){
			invertida[j]=cadena[i];
			j++;
		}
		i--;
	}	
}
*/
//5//
/*
#include <stdio.h>
#include <stdbool.h>

bool validar_clave(char clave[]){
bool es_valido=true;
int cantidad_caracteres=0,int i=0,pares=0,impares=0;
while(clave[i]!='\0' && es_valido==true){
	if(clave[i]<'0' || clave[i]>'9'){
		es_valido=false;		
	}
	cantidad_caracteres++;
	else{
		if (clave[i]=='0'||clave[i]=='2'||clave[i]=='4'||clave[i]=='6'||clave[i]=='8'){
			pares++;
		}
		else{
			impares++;
		}
	}
	i++;	
}
if ((cantidad_caracteres<6 ||cantidad_caracteres>12)||(impares>=pares)){
	es_valido=false;
}

return es_valido;
}
*/
//6//
/*
#include <stdio.h>
#include <stdbool.h>

bool validar_clave(char clave[]){
bool es_valido=true,caracteres_iguales=true;
int cantidad_caracteres=0,i=0;
char primer_caracter=clave[i];
while(clave[i]!=0 && es_valido==true){
	if(clave[i]<'0'||clave[i]>'9'){
		es_valido=false;
	}
	else{
		if(clave[i]!=primer_caracter){
			caracteres_iguales=false;
		}
	}
	cantidad_caracteres++;
	i++;
}
if(caracteres_iguales==true || cantidad_caracteres>8 || cantidad_caracteres<4){
	es_valido=false;
}	
	
return es_valido;}
*/
//7//
/*
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
bool es_palindromo(char cadena[]){
bool es_palindromo=true;
int i;
for(i=0;i<strlen(cadena)/2;i++){
	if(cadena[i]!=cadena[strlen(cadena)-1-i]){
		es_palindromo=false;
	}
}		
return es_palindromo}
*/
//8//
/*
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
bool es_palindromo(char cadena[]){
bool es_palindromo=true;
int i=0,f=(strlen(cadena)-1);
while(i<f && es_palindromo==true){
	if (cadena[i]==' '){
		i++;
	}
	else{
		if(cadena[f]==' '){
			f--;
		}
		else{
			if(cadena[i]!=cadena[f]){
				es_palindromo=false;
			}
			else{
				i++;
				f--;
			}
		}
	}	
}	
	
return es_palindromo;}
*/
//9//
/*
#include <stdio.h>
#include <string.h>
#define MAX 30
typedef char palabra[MAX];

void plural(palabra palabra){
	if(palabra[strlen(palabra)-1]=='a'||palabra[strlen(palabra)-1]=='e'||palabra[strlen(palabra)-1]=='i'||palabra[strlen(palabra)-1]=='o'||palabra[strlen(palabra)-1]=='u'||palabra[strlen(palabra)-1]=='A'||palabra[strlen(palabra)-1]=='E'||palabra[strlen(palabra)-1]=='I'||palabra[strlen(palabra)-1]=='O'||palabra[strlen(palabra)-1]=='U'||palabra[strlen(palabra)-1]=='é'||palabra[strlen(palabra)-1]=='É'){
		strcat(palabra,"s");
	}
	else if(palabra[strlen(palabra)-1]=='z'||palabra[strlen(palabra)-1]=='Z'){
		palabra[strlen(palabra)-1]='c';
		strcat(palabra,"es");
	}
	else if((!(palabra[strlen(palabra)-1]=='z'||palabra[strlen(palabra)-1]=='Z'||palabra[strlen(palabra)-1]=='x'||palabra[strlen(palabra)-1]=='X'||palabra[strlen(palabra)-1]=='s'||palabra[strlen(palabra)-1]=='S'))||(palabra[strlen(palabra)-1]=='Á'||palabra[strlen(palabra)-1]=='á'||palabra[strlen(palabra)-1]=='í'||palabra[strlen(palabra)-1]=='Í'||palabra[strlen(palabra)-1]=='ó'||palabra[strlen(palabra)-1]=='Ó'||palabra[strlen(palabra)-1]=='ú'||palabra[strlen(palabra)-1]=='U')){
		strcat(palabra,"es");
	}	
}
*/
//10//
/*
#include <stdio.h>
#include <string.h>
#define MAX 16
typedef char cadena[MAX];
int calcular_longitud(cadena cadena){
	int i=0;
	while(cadena[i]!='\0'){
		i++;
	}
return i;}

void comparar_cadenas(cadena cadena1,cadena cadena2){
	int comparar,longitud1=(strlen(cadena1)-1),longitud2=(strlen(cadena2)-1);
	if (calcular_longitud(cadena1)<calcular_longitud(cadena2)){
		printf("%s es mas corta que %s",cadena1,cadena2);
	}
	else if (calcular_longitud(cadena2)<calcular_longitud(cadena1)){
		printf("%s es mas corta que %s",cadena2,cadena1);
	}
	else if (calcular_longitud(cadena2)==calcular_longitud(cadena1)){
		comparar=strcmp(cadena1,cadena2);
		if (comparar<0){
			printf("%s es mas corta que %s alfabeticamente",cadena1,cadena2);
		}
		else if(comparar>0){
			printf("%s es mas corta que %s alfabeticamente",cadena2,cadena1);
		}
		else{
			printf("%s es igual a %s",cadena1,cadena2);
		}
	}	
}
*/
//11//
/*acordarse que hay dos codigos uno mio y el segundo perfecto proporcionado por blackbox.ai
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define MAXC 21
#define MAXP 20
typedef char cadena[MAXC];
typedef cadena T_vector[MAXP];

void cargar_palabras(T_vector vector, int* ml) {
    bool fin = false; // variable booleana para controlar el bucle
    while (*ml < MAXP && fin == false) {
        printf("ingrese una palabra o 0 para terminar:");
        fgets(vector[*ml], MAXC, stdin);
        fflush(stdin);
        if (vector[*ml][0] == '0') {
			fin = true; // establecer fin a true para salir del bucle
        } else {
            (*ml)++; // incrementar ml solo si se ingresa una palabra válida
        }
    }
}

void buscar_mayor_palabra(T_vector vector,int ml){
	int mayor,i,posicion;
	mayor=(strlen(vector[0])-1);
	posicion=0;
	for(i=1;i<ml;i++){
		if((strlen(vector[i])-1)>mayor){
			mayor=(strlen(vector[i])-1);
			posicion=i;
		} 	
	}
	printf("la palabra mas larga es %s",vector[posicion]);
}

void buscar_palabra(T_vector vector,int ml){
int i=0;
cadena cadena_aux;
printf("ingrese la palabra que quiere buscar:");
fgets(cadena_aux,MAXC,stdin);
fflush(stdin);
for(i=0;i<ml;i++){
	if((strcmp(cadena_aux,vector[i]))==0){
		printf("\nla cadena %s se encunetra en la posicion %i",cadena_aux,i+1);
	}
}	
}




int main(){
T_vector vector;
int ml=0;
cargar_palabras(vector,&ml);
buscar_mayor_palabra(vector,ml);
buscar_palabra(vector,ml);
return 0;}

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define MAXC 21
#define MAXP 20
typedef char cadena[MAXC];
typedef cadena T_vector[MAXP];

void cargar_palabras(T_vector vector, int* ml) {
    bool fin = false; // variable booleana para controlar el bucle
    while (*ml < MAXP && fin == false) {
        printf("ingrese una palabra o 0 para terminar:");
        fgets(vector[*ml], MAXC, stdin);
        fflush(stdin);
        vector[*ml][strcspn(vector[*ml],"\n")]='\0'; // eliminar carácter de nueva línea y agregar caracter nulo al final
        if (vector[*ml][0] == '0') {
            fin = true; // establecer fin a true para salir del bucle
        } else {
            (*ml)++; // incrementar ml solo si se ingresa una palabra válida
        }
    }
}

void buscar_mayor_palabra(T_vector vector,int ml){
    int mayor,i,posicion;
    mayor=strlen(vector[0]);
    posicion=0;
    for(i=1;i<ml;i++){
        if(strlen(vector[i])>mayor){
            mayor=strlen(vector[i]);
            posicion=i;
        } 	
    }
    printf("la palabra mas larga es %s\n",vector[posicion]);
}

void buscar_palabra(T_vector vector,int ml){
    int i=0;
    cadena cadena_aux;
    printf("ingrese la palabra que quiere buscar:");
    fgets(cadena_aux,MAXC,stdin);
    fflush(stdin);
    cadena_aux[strcspn(cadena_aux,"\n")]='\0'; // eliminar carácter de nueva línea y agregar caracter nulo
    bool encontrada = false;
    for(i=0;i<ml;i++){
        if(strcmp(cadena_aux,vector[i])==0){
            printf("\nla cadena %s se encuentra en la posición %i",cadena_aux,i+1);
            encontrada = true;
        }
    }
    if (!encontrada) {
        printf("\nLa palabra no se encontró en el vector.");
    }
}

int main(){
    T_vector vector;
    int ml=0;
    cargar_palabras(vector,&ml);
    buscar_mayor_palabra(vector,ml);
    buscar_palabra(vector,ml);
    return 0;
}
*/
//12//
/*
#include <stdio.h>
#include <string.h>
#define MAX 101
typedef char oracion[MAX];

void ingresar_oracion(oracion oracion){
printf("ingrese una oracion de maximo 100 caracteres:");
fgets(oracion,MAX,stdin);
fflush(stdin);
oracion[strcspn(oracion,"\n")]='\0';
}

int informar_vocales_minusculas_no_acentuadas(oracion oracion){
int i,cantidad=0;	
for(i=0;i<=strlen(oracion);i++){
	if(oracion[i]=='a'||oracion[i]=='e'||oracion[i]=='i'||oracion[i]=='o'||oracion[i]=='u'){
		cantidad++;
	}	
}	
return cantidad;	
}

int main(){
oracion oracion;
ingresar_oracion(oracion);
printf("la cantidad de vocales de la oracion es de:%i",informar_vocales_minusculas_no_acentuadas(oracion));	
return 0;}
*/
//13//
//muy importante volver sobre el punto 13 y revisar cada funcion detalladamente//
/*
#include <stdio.h>
#include <string.h>

#define MAX_CARACTERES 50
#define MAX_ORACIONES 3

typedef char oracion[MAX_CARACTERES];
typedef oracion oraciones[MAX_ORACIONES];

void leer_oraciones(oraciones oraciones) {
    for (int i = 0; i < MAX_ORACIONES; i++) {
        printf("Ingrese oración %d: ", i + 1);
        fgets(oraciones[i], MAX_CARACTERES, stdin);
        oraciones[i][strcspn(oraciones[i], "\n")] = '\0'; // eliminar carácter de nueva línea
    }
}

void encontrar_oracion_mas_larga(oraciones oraciones, int* indice_mas_larga) {
    int max_longitud = 0;
    int contador_iguales = 0;

    for (int i = 0; i < MAX_ORACIONES; i++) {
        int longitud = strlen(oraciones[i]);
        if (longitud > max_longitud) {
            max_longitud = longitud;
            *indice_mas_larga = i;
            contador_iguales = 1;
        } else if (longitud == max_longitud) {
            contador_iguales++;
        }
    }
}

void imprimir_oracion_mas_larga(oraciones oraciones, int indice_mas_larga, int contador_iguales) {
    if (contador_iguales > 1) {
        printf("Hay %d oraciones con la misma longitud máxima.\n", contador_iguales);
        for (int i = 0; i < MAX_ORACIONES; i++) {
            if (strlen(oraciones[i]) == strlen(oraciones[indice_mas_larga])) {
                printf("%s\n", oraciones[i]);
            }
        }
    } else {
        printf("La oración más larga es: %s\n", oraciones[indice_mas_larga]);
    }
}

int hay_oraciones_iguales(oraciones oraciones) {
    for (int i = 0; i < MAX_ORACIONES; i++) {
        for (int j = i + 1; j < MAX_ORACIONES; j++) {
            if (strcmp(oraciones[i], oraciones[j]) == 0) {
                return 1;
            }
        }
    }
    return 0;
}

void buscar_palabra(oraciones oraciones) {
    char palabra[MAX_CARACTERES];
    printf("Ingrese una palabra o parte de una oración: ");
    fgets(palabra, MAX_CARACTERES, stdin);
    palabra[strcspn(palabra, "\n")] = '\0'; // eliminar carácter de nueva línea

    int encontrado = 0;
    for (int i = 0; i < MAX_ORACIONES; i++) {
        if (strstr(oraciones[i], palabra) != NULL) {
            printf("La palabra u oracion se encuentra en la oración %d: %s\n", i + 1, oraciones[i]);
            encontrado = 1;
        }
    }
    if (!encontrado) {
        printf("La palabra u oracion no se encuentra en ninguna oración.\n");
    }
}

int main() {
    oraciones oraciones;
    int indice_mas_larga;
    int contador_iguales = 0;

    leer_oraciones(oraciones);
    encontrar_oracion_mas_larga(oraciones, &indice_mas_larga);
    imprimir_oracion_mas_larga(oraciones, indice_mas_larga, contador_iguales);

    if (hay_oraciones_iguales(oraciones)) {
        printf("Hay al menos 2 oraciones iguales.\n");
    } else {
        printf("No hay oraciones iguales.\n");
    }

    buscar_palabra(oraciones);

    return 0;
}
*/
//14//
/*
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_TEXTO 100000

typedef char Texto[MAX_TEXTO];

bool es_letra_o_numero(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')||c=='ñ'||c=='Ñ' ;
}

bool es_signo_puntuacion(char c) {
    return c == '.' || c == ',' || c == ';' || c == ':' || c == '(' || c == ')';
}

bool es_caracter_valido(char c) {
    return es_letra_o_numero(c) || es_signo_puntuacion(c) || c == ' ';
}

bool verificar_texto_valido(Texto texto) {
    bool valido = true;
    for (int i = 0; i < strlen(texto); i++) {
        if (!es_caracter_valido(texto[i])) {
            valido = false;
        }
    }
    return valido;
}

void cargar_texto(Texto texto) {
    printf("Ingrese el texto a enviar por telegrama: ");
    fgets(texto, MAX_TEXTO, stdin);
    texto[strcspn(texto, "\n")] = '\0'; // eliminar carácter de nueva línea
}

int contar_palabras(Texto texto) {
    int palabras = 0;
    bool en_palabra = false;

    for (int i = 0; i < strlen(texto); i++) {
        if (texto[i] == ' ') {
            en_palabra = false;
        } else if (es_caracter_valido(texto[i])) {
            if (!en_palabra) {
                palabras++;
                en_palabra = true;
            }
        }
    }

    return palabras;
}

int calcular_importe(Texto texto) {
    // Calcula el importe a abonar según la cantidad de palabras y caracteres en el texto
    int importe = 0;
    int caracteres_palabra = 0;
    for (int i = 0; i < strlen(texto); i++) {
        if (texto[i] == ' ') {
            // Calcula el importe para la palabra actual
            importe += (caracteres_palabra / 3) * 10;
            if (caracteres_palabra % 3 > 0) {
                importe += 8;
            }
            caracteres_palabra = 0; // Reinicia la cuenta de caracteres para la próxima palabra
        } else {
            caracteres_palabra++;
        }
    }
    // Calcula el importe para la última palabra
    importe += (caracteres_palabra / 3) * 10;
    if (caracteres_palabra % 3 > 0) {
        importe += 8;
    }
    return importe;
}

int main() {
    Texto texto;

    cargar_texto(texto);

    if (!verificar_texto_valido(texto)) {
        printf("Telegrama no válido\n");
    }
    else{
     	int palabras = contar_palabras(texto);
    	int importe = calcular_importe(texto);
		printf("El texto tiene %d palabras.\n", palabras);
    	printf("El importe a abonar es de $%d.\n", importe);
	}
    return 0;
}
*/
//////////GUIA DE STRUCTS//////////
//1//
/*
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define MF 5
#define MAXNOMBRE 30
typedef struct{
	int dia;
	int mes;
	int anio;	
}fecha;


typedef struct{
char nombre[MAXNOMBRE];
fecha nacimiento;
fecha ingreso;
int sueldo_basico;
}empleado;

typedef empleado T_empleados[MF];



void cargar_empleados(T_empleados empleados,int*ml){
int i=*ml;
char validador;
bool seguir=true;
	while((*ml)<MF && seguir==true){
		printf("desea ingresar al empleado en la posicion %i ingrese [Y/n]:",((*ml)+1));
		validador=getchar();
		fflush(stdin); 
		while(validador!='N' && validador!='n' && validador!='Y' && validador!='y' && validador!=' '){
			printf("\ndesea ingresar al empleado en la posicion %i ingrese [y/N]:",((*ml)+1));
			validador=getchar();
			fflush(stdin);
		}
		if(validador=='N'||validador=='n'||validador==' '){
			seguir=false;
		}
		else{
			printf("\ningrese el nombre del empleado:");
			fgets(empleados[(*ml)].nombre,MAXNOMBRE,stdin);
			fflush(stdin);
			empleados[(*ml)].nombre[strcspn(empleados[(*ml)].nombre,"\n")]='\0';
			printf("ingrese la fecha de nacimiento (dia mes año (separados por un espacio)):");
			scanf("%i %i %i",&empleados[(*ml)].nacimiento.dia,&empleados[(*ml)].nacimiento.mes,&empleados[(*ml)].nacimiento.anio);
			fflush(stdin);
			printf("ingrese la fecha de ingreso (dia mes año (separados por un espacio)):");
			scanf("%i %i %i",&empleados[(*ml)].ingreso.dia,&empleados[(*ml)].ingreso.mes,&empleados[(*ml)].ingreso.anio);
			fflush(stdin);
			printf("\ningrese su sueldo basico:");
			scanf("%i",&empleados[(*ml)].sueldo_basico);
			fflush(stdin);
			(*ml)++;
		}		
	}
}


void mostrar_cumpleaneros(T_empleados empleados,fecha fecha_actual,int ml){
int i,plata_regalo;
for(i=0;i<ml;i++){
	if(empleados[i].nacimiento.mes==fecha_actual.mes){
		printf("\nNombre:%s",empleados[i].nombre);
		plata_regalo=(((fecha_actual.anio)-(empleados[i].nacimiento.anio))*(empleados[i].sueldo_basico*0.0001));
		printf("\nRegalo:%i",plata_regalo);
	}
}
}

int main(){
	T_empleados empleados;
	int ml=0;
	fecha fecha_actual;
	printf("ingrese la fecha de proceso (dia mes año (separados por un espacio)):");
	scanf("%i %i %i",&fecha_actual.dia,&fecha_actual.mes,&fecha_actual.anio);
	fflush(stdin);
	cargar_empleados(empleados,&ml);
	mostrar_cumpleaneros(empleados,fecha_actual,ml);
return 0;}
*/
//2// //3// el dos y el tres van juntos porque el tres pide que para algunas busquedas se hagan binarias
/*
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define MAXPALABRA 61
#define CANTEMPLEADOS 5
typedef char palabra[MAXPALABRA];
typedef struct{
palabra calle;
int numero;
palabra localidad;
palabra provincia;
int codigo_postal;	
}Treg_direccion;

typedef struct{
int dia;
int mes;
int anio;
}Treg_fecha;

typedef struct{
palabra nombre_apellido;
int legajo;
Treg_direccion direccion;
Treg_fecha nacimiento;
Treg_fecha ingreso;
}Treg_empleado;

typedef Treg_empleado T_empleados[CANTEMPLEADOS];

bool verificar_fecha(int dia,int mes,int anio){
bool es_valido = true;
bool es_bisiesto = ((anio % 4 == 0 && anio % 100 != 0) || anio % 400 == 0);

    if (mes < 1 || mes > 12) {
        es_valido = false;
    } else {
        int dias_por_mes[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if (es_bisiesto && mes == 2) {
            dias_por_mes[1] = 29; // Febrero tiene 29 días en años bisiestos
        }

        if (dia < 1 || dia > dias_por_mes[mes - 1]) {
            es_valido = false;
        }
    }

    return es_valido;
	
	


}

void cargar_empleados(T_empleados empleados,int*ml){
int i=(*ml);
char validador;
bool seguir=true;
	while((*ml)<CANTEMPLEADOS && seguir==true){
		printf("desea ingresar al empleado en la posicion %i ingrese [Y/n]:",((*ml)+1));
		validador=getchar();
		fflush(stdin); 
		while(validador!='N' && validador!='n' && validador!='Y' && validador!='y'){
			printf("\ndesea ingresar al empleado en la posicion %i ingrese [y/N]:",((*ml)+1));
			validador=getchar();
			fflush(stdin);
		}
		if(validador=='N'||validador=='n'){
			seguir=false;
		}
		else{
			printf("ingrese el nombre y apellido del empleado:");
			fgets(empleados[i].nombre_apellido,MAXPALABRA,stdin);
			fflush(stdin);
			empleados[i].nombre_apellido[strcspn(empleados[i].nombre_apellido,"\n")]='\0';
			printf("\ningrese el numero de legajo del empleado:");
			scanf("%i",&empleados[i].legajo);
			fflush(stdin);
			printf("\na partir de ahora ingresara los datos del lugar en donde el empleado vive");
			printf("\ncalle:");
			fgets(empleados[i].direccion.calle,MAXPALABRA,stdin);
			fflush(stdin);
			empleados[i].direccion.calle[strcspn(empleados[i].direccion.calle,"\n")]='\0';
			printf("\nnumero de la vivienda:");
			scanf("%i",&empleados[i].direccion.numero);
			fflush(stdin);
			printf("\nlocalidad:");
			fgets(empleados[i].direccion.localidad,MAXPALABRA,stdin);
			fflush(stdin);
			empleados[i].direccion.localidad[strcspn(empleados[i].direccion.localidad,"\n")]='\0';
			printf("\nprovincia:");
			fgets(empleados[i].direccion.provincia,MAXPALABRA,stdin);
			fflush(stdin);
			empleados[i].direccion.provincia[strcspn(empleados[i].direccion.provincia,"\n")]='\0';
			printf("\ncodigo postal del barrio:");
			scanf("%i",&empleados[i].direccion.codigo_postal);
			fflush(stdin);
			printf("\ningrese la fecha de nacimiento [separada por un espacio(dia mes año)] del empleado:");
			scanf("%i %i %i",&empleados[i].nacimiento.dia,&empleados[i].nacimiento.mes,&empleados[i].nacimiento.anio);
			fflush(stdin);
			while(verificar_fecha(empleados[i].nacimiento.dia,empleados[i].nacimiento.mes,empleados[i].nacimiento.anio)==false){
				printf("\ningrese la fecha de nacimiento [separada por un espacio(dia mes año)] del empleado:");
				scanf("%i %i %i",&empleados[i].nacimiento.dia,&empleados[i].nacimiento.mes,&empleados[i].nacimiento.anio);
				fflush(stdin);
			}
			printf("\ningrese la fecha de ingreso [separada por un espacio(dia mes año)] del empleado:");
			scanf("%i %i %i",&empleados[i].ingreso.dia,&empleados[i].ingreso.mes,&empleados[i].ingreso.anio);
			fflush(stdin);
			while(verificar_fecha(empleados[i].ingreso.dia,empleados[i].ingreso.mes,empleados[i].ingreso.anio)==false){
				printf("\ningrese la fecha de ingreso [separada por un espacio(dia mes año)] del empleado:");
				scanf("%i %i %i",&empleados[i].ingreso.dia,&empleados[i].ingreso.mes,&empleados[i].ingreso.anio);
				fflush(stdin);
			}
			(*ml)++;
			i++;	
		}
	}
}

void mostrar_empleados(T_empleados empleados,int ml){
int i;
for (i=0;i<ml;i++){
	printf("\nnombre y apellido:%s",empleados[i].nombre_apellido);
	printf("\nlegajo:%i",empleados[i].legajo);
	printf("\ndireccion:");
	printf("\n\tcalle:%s",empleados[i].direccion.calle);
	printf("\n\taltura:%i",empleados[i].direccion.numero);
	printf("\n\tlocalidad:%s",empleados[i].direccion.localidad);
	printf("\n\tprovincia:%s",empleados[i].direccion.provincia);
	printf("\n\tcodigo postal:%i",empleados[i].direccion.codigo_postal);
	printf("\nfecha de nacimiento:%i %i %i",empleados[i].nacimiento.dia,empleados[i].nacimiento.mes,empleados[i].nacimiento.anio);
	printf("\nfecha de ingreso:%i %i %i",empleados[i].ingreso.dia,empleados[i].ingreso.mes,empleados[i].ingreso.anio);	
}		
}

void ordenar_nombre_asc(T_empleados empleados,int ml){
	int i=1,j,comparacion;
	Treg_empleado aux;
	bool cambios=true;
	while(cambios==true && i<ml){
		cambios=false;
		for(j=0;j<ml-1;j++){
			comparacion=strcmp(empleados[j].nombre_apellido,empleados[j+1].nombre_apellido);
			if(comparacion>0){
				aux=empleados[j];
				empleados[j]=empleados[j+1];
				empleados[j+1]=aux;
				cambios=true;
			} 
		}
		i++;		
	}	
}

void ordenar_nombre_desc(T_empleados empleados,int ml){
	int i=1,j,comparacion;
	Treg_empleado aux;
	bool cambios=true;
	while(cambios==true && i<ml){
		cambios=false;
		for(j=0;j<ml-1;j++){
			comparacion=strcmp(empleados[j].nombre_apellido,empleados[j+1].nombre_apellido);
			if(comparacion<0){
				aux=empleados[j];
				empleados[j]=empleados[j+1];
				empleados[j+1]=aux;
				cambios=true;
			} 
		}
		i++;		
	}	
}

void ordenar_legajo_asc(T_empleados empleados,int ml){
	int i=1,j;
	Treg_empleado aux;
	bool cambios=true;
	while(cambios==true && i<ml){
		cambios=false;
		for(j=0;j<ml-1;j++){			
			if(empleados[j].legajo>empleados[j+1].legajo){
				aux=empleados[j];
				empleados[j]=empleados[j+1];
				empleados[j+1]=aux;
				cambios=true;
			} 
		}
		i++;		
	}	
}

void ordenar_legajo_desc(T_empleados empleados,int ml){
	int i=1,j;
	Treg_empleado aux;
	bool cambios=true;
	while(cambios==true && i<ml){
		cambios=false;
		for(j=0;j<ml-1;j++){			
			if(empleados[j].legajo<empleados[j+1].legajo){
				aux=empleados[j];
				empleados[j]=empleados[j+1];
				empleados[j+1]=aux;
				cambios=true;
			} 
		}
		i++;		
	}	
}

void ordenar_edad_asc(T_empleados empleados, int ml) {
    int i = 1, j;
    Treg_empleado aux;
    bool cambios = true;

    while (cambios == true && i < ml) {
        cambios = false;
        for (j = 0; j < ml - 1; j++) {
            if (empleados[j].nacimiento.anio > empleados[j + 1].nacimiento.anio) {
                aux = empleados[j];
                empleados[j] = empleados[j + 1];
                empleados[j + 1] = aux;
                cambios = true;
            } else if (empleados[j].nacimiento.anio == empleados[j + 1].nacimiento.anio) {
                if (empleados[j].nacimiento.mes > empleados[j + 1].nacimiento.mes) {
                    aux = empleados[j];
                    empleados[j] = empleados[j + 1];
                    empleados[j + 1] = aux;
                    cambios = true;
                } else if (empleados[j].nacimiento.mes == empleados[j + 1].nacimiento.mes) {
                    if (empleados[j].nacimiento.dia > empleados[j + 1].nacimiento.dia) {
                        aux = empleados[j];
                        empleados[j] = empleados[j + 1];
                        empleados[j + 1] = aux;
                        cambios = true;
                    }
                }
            }
        }
        i++;
    }
}

void ordenar_edad_desc(T_empleados empleados, int ml) {
    int i = 1, j;
    Treg_empleado aux;
    bool cambios = true;

    while (cambios == true && i < ml) {
        cambios = false;
        for (j = 0; j < ml - 1; j++) {
            if (empleados[j].nacimiento.anio < empleados[j + 1].nacimiento.anio) {
                aux = empleados[j];
                empleados[j] = empleados[j + 1];
                empleados[j + 1] = aux;
                cambios = true;
            } else if (empleados[j].nacimiento.anio == empleados[j + 1].nacimiento.anio) {
                if (empleados[j].nacimiento.mes < empleados[j + 1].nacimiento.mes) {
                    aux = empleados[j];
                    empleados[j] = empleados[j + 1];
                    empleados[j + 1] = aux;
                    cambios = true;
                } else if (empleados[j].nacimiento.mes == empleados[j + 1].nacimiento.mes) {
                    if (empleados[j].nacimiento.dia < empleados[j + 1].nacimiento.dia) {
                        aux = empleados[j];
                        empleados[j] = empleados[j + 1];
                        empleados[j + 1] = aux;
                        cambios = true;
                    }
                }
            }
        }
        i++;
    }
}

void ordenar_atiguedad_asc(T_empleados empleados, int ml) {
    int i = 1, j;
    Treg_empleado aux;
    bool cambios = true;

    while (cambios == true && i < ml) {
        cambios = false;
        for (j = 0; j < ml - 1; j++) {
            if (empleados[j].ingreso.anio > empleados[j + 1].ingreso.anio) {
                aux = empleados[j];
                empleados[j] = empleados[j + 1];
                empleados[j + 1] = aux;
                cambios = true;
            } else if (empleados[j].ingreso.anio == empleados[j + 1].ingreso.anio) {
                if (empleados[j].ingreso.mes > empleados[j + 1].ingreso.mes) {
                    aux = empleados[j];
                    empleados[j] = empleados[j + 1];
                    empleados[j + 1] = aux;
                    cambios = true;
                } else if (empleados[j].ingreso.mes == empleados[j + 1].ingreso.mes) {
                    if (empleados[j].ingreso.dia > empleados[j + 1].ingreso.dia) {
                        aux = empleados[j];
                        empleados[j] = empleados[j + 1];
                        empleados[j + 1] = aux;
                        cambios = true;
                    }
                }
            }
        }
        i++;
    }
}


void ordenar_atiguedad_desc(T_empleados empleados, int ml) {
    int i = 1, j;
    Treg_empleado aux;
    bool cambios = true;

    while (cambios == true && i < ml) {
        cambios = false;
        for (j = 0; j < ml - 1; j++) {
            if (empleados[j].ingreso.anio < empleados[j + 1].ingreso.anio) {
                aux = empleados[j];
                empleados[j] = empleados[j + 1];
                empleados[j + 1] = aux;
                cambios = true;
            } else if (empleados[j].ingreso.anio == empleados[j + 1].ingreso.anio) {
                if (empleados[j].ingreso.mes < empleados[j + 1].ingreso.mes) {
                    aux = empleados[j];
                    empleados[j] = empleados[j + 1];
                    empleados[j + 1] = aux;
                    cambios = true;
                } else if (empleados[j].ingreso.mes == empleados[j + 1].ingreso.mes) {
                    if (empleados[j].ingreso.dia < empleados[j + 1].ingreso.dia) {
                        aux = empleados[j];
                        empleados[j] = empleados[j + 1];
                        empleados[j + 1] = aux;
                        cambios = true;
                    }
                }
            }
        }
        i++;
    }
}

void ordenar_localidad_asc(T_empleados empleados,int ml){
	int i=1,j,comparacion;
	Treg_empleado aux;
	bool cambios=true;
	while(cambios==true && i<ml){
		cambios=false;
		for(j=0;j<ml-1;j++){
			comparacion=strcmp(empleados[j].direccion.localidad,empleados[j+1].direccion.localidad);
			if(comparacion>0){
				aux=empleados[j];
				empleados[j]=empleados[j+1];
				empleados[j+1]=aux;
				cambios=true;
			} 
		}
		i++;		
	}	
}

void ordenar_localidad_desc(T_empleados empleados,int ml){
	int i=1,j,comparacion;
	Treg_empleado aux;
	bool cambios=true;
	while(cambios==true && i<ml){
		cambios=false;
		for(j=0;j<ml-1;j++){
			comparacion=strcmp(empleados[j].direccion.localidad,empleados[j+1].direccion.localidad);
			if(comparacion<0){
				aux=empleados[j];
				empleados[j]=empleados[j+1];
				empleados[j+1]=aux;
				cambios=true;
			} 
		}
		i++;		
	}	
}

int busqueda_binaria_nombre_apellido(T_empleados empleados, int ml) {
    palabra nombre_apellido;
    printf("ingrese el nombre y apellido del empleado a buscar:");
    fgets(nombre_apellido,MAXPALABRA,stdin);
    fflush(stdin);
    nombre_apellido[strcspn(nombre_apellido,"\n")]='\0';
	int inf, sup, mit;
    bool terminado;
    int posicion;

    // inicializaciones
    inf = 0;
    sup = ml - 1;
    terminado = false;

    while (!terminado) {
        if ((strcmp(nombre_apellido, empleados[sup].nombre_apellido) < 0) || (strcmp(nombre_apellido, empleados[inf].nombre_apellido) > 0)) {
            terminado = true; // NO ESTA => FIN DE LA BUSQUEDA
            posicion = -1;
        } else {
            mit = (inf + sup) / 2;
            if (strcmp(nombre_apellido, empleados[mit].nombre_apellido) == 0) {
                terminado = true; // ENCONTRADO => FIN DE LA BUSQUEDA
                posicion = mit;
            } else {
                if (strcmp(nombre_apellido, empleados[mit].nombre_apellido) < 0)
                    sup = mit - 1;
                else
                    inf = mit + 1;
            }
        }
    }

    return posicion;
}
int busqueda_binaria_legajo(T_empleados empleados, int ml){
    int legajo;
	printf("\ningrese el legajo a buscar:");
    scanf("%i",&legajo);
    fflush(stdin);
	int inf, sup, mit;
    bool terminado;
    int posicion;

    // inicializaciones
    inf = 0;
    sup = ml - 1;
    terminado = false;

    while (!terminado) {
        if ((legajo > empleados[sup].legajo) || (legajo < empleados[inf].legajo)) {
            terminado = true; // NO ESTA => FIN DE LA BUSQUEDA
            posicion = -1;
        } else {
            mit = (inf + sup) / 2;
            if (empleados[mit].legajo == legajo) {
                terminado = true; // ENCONTRADO => FIN DE LA BUSQUEDA
                posicion = mit;
            } else {
                if (legajo > empleados[mit].legajo)
                    inf = mit + 1;
                else
                    sup = mit - 1;
            }
        }
    }

    return posicion;
}

int main(){
T_empleados empleados;
int ml=0;
cargar_empleados(empleados,&ml);
	
	
	
	
return 0;}
//seguir este codigo en el futuro muy bueno para practicar todo//
*/
//faltan hacer los ejercicios 4 y 5 de la guia de structs//
//4// 
//5// 


//////////GUIA DE ARCHIVOS//////////
//1//
/*
#include <stdio.h>

int factorial(int numero) {
    int resultado = 1;
    for (int i = 2; i <= numero; i++) {
        resultado *= i;
    }
    return resultado;
}

void crear_y_cargar_archivo(FILE *archivo_a_leer){
	int numero;
		
		printf("\ningrese un numero o -1 para terminar: ");
		scanf("%i",&numero);
		while(numero>=0){
			fwrite(&numero,sizeof(numero),1,archivo_a_leer);
			printf("\ningrese un numero o -1 para terminar: ");
			scanf("%i",&numero);
		}
		
}

void leer_archivo(FILE *archivo_a_leer){
	int factorial;
	fread(&factorial,sizeof(factorial),1,archivo_a_leer);
	while(!feof(archivo_a_leer)){
		printf("\nel factorial es %i:",factorial);
		fread(&factorial,sizeof(factorial),1,archivo_a_leer);
	}
}


void leer_archivo_calcular_factoriales_y_escribirlos(FILE *archivo_a_leer,FILE *archivo_a_escribir){
int numero,resultado;
fread(&numero,sizeof(numero),1,archivo_a_leer);
while(!feof(archivo_a_leer)){
resultado=factorial(numero);
fwrite(&resultado,sizeof(resultado),1,archivo_a_escribir);
fread(&numero,sizeof(numero),1,archivo_a_leer);
}
}

int main(){
FILE *archivo_a_leer;
FILE *archivo_a_escribir;
FILE *archivo_final;
archivo_a_leer=fopen("numeros_enteros.dat","ab");
if(archivo_a_leer==NULL){
	printf("no se pudo crear el archivo");
}
else{
	crear_y_cargar_archivo(archivo_a_leer);
	fclose(archivo_a_leer);
}

archivo_a_leer=fopen("numeros_enteros.dat","rb");
archivo_a_escribir=fopen("numero_enteros_factorizados.dat","wb");
if(archivo_a_leer==NULL || archivo_a_escribir==NULL){
	printf("no se pudo abrir alguno de los dos archivos");
}
else{
	leer_archivo_calcular_factoriales_y_escribirlos(archivo_a_leer,archivo_a_escribir);
	fclose(archivo_a_leer);
	fclose(archivo_a_escribir);
	printf("\noperacion exitosa");
}
archivo_final=fopen("numero_enteros_factorizados.dat","rb");
if(archivo_final==NULL){
	printf("no se pudo abrir el archivo");
}
else{
	leer_archivo(archivo_final);
	fclose(archivo_final);	
}	
return 0;}
*/

//2//
/*
#include <stdio.h>
#include <stdbool.h>

bool es_primo(int num) {
   bool verdadero;
   
    if (num <= 1){
		verdadero=false;
	} // 0 y 1 no son primos
    else{
    	verdadero=true;
    	for (int i = 2; i * i <= num; i++) {
        	if (num % i == 0){
				verdadero=false;
			}  // num es divisible entre i, no es primo
    	}
    	
	}
    return verdadero; 
}

void leer_primos_y_agregarlos_a_otro_archivo(FILE *archivo,FILE *archivo_destinatario){
int numero;
fread(&numero,sizeof(int),1,archivo);
while(!feof(archivo)){
	if(es_primo(numero)==true){
		printf("\nel numero primo es :%i",numero);
		fwrite(&numero,sizeof(int),1,archivo_destinatario);
	}
	fread(&numero,sizeof(int),1,archivo);	
}
}

void cargar_datos(FILE *archivo){
	int numero;
	printf("ingrese un numero (numero 1 o numero menor que 1 para finalizar):");
	scanf("%i",&numero);
	while(numero>=2){
		fwrite(&numero,sizeof(int),1,archivo);
		printf("ingrese un numero (numero 1 o numero menor que 1 para finalizar):");
		scanf("%i",&numero);
	}
}

int main(){
FILE *numeros;
FILE *numeros_primos;

numeros=fopen("numeros.dat","wb");
if(numeros==NULL){
	printf("no se pudo ingresar al archivo");
}
else{
	cargar_datos(numeros);
	fclose(numeros);
}
numeros=fopen("numeros.dat","rb");
numeros_primos=fopen("numeros_primos.dat","wb");
if( numeros==NULL || numeros_primos==NULL ){
	printf("no se pudo abrir alguno de los dos archivos");
}
else{
	leer_primos_y_agregarlos_a_otro_archivo(numeros,numeros_primos);
	fclose(numeros);
	fclose(numeros_primos);
}		
									
return 0;}
*/
//3//
/*
#include <stdio.h>
#include <stdbool.h>
bool validar_numero(int numero){
	bool es_valido=false;
	if (numero>=0 && numero<=255){
		es_valido=true;
	}
return es_valido;}

void cargar_archivo_numero(FILE*archivo_enteros){
		int numero;
		printf("ingrese un numero entre el 0 y el 255:");
		scanf("%i",&numero);		
		while(validar_numero(numero)==true){
			fwrite(&numero,sizeof(int),1,archivo_enteros);
			printf("\ningrese un numero entre el 0 y el 255:");
			scanf("%i",&numero);
		}
}

void escribir_texto_txt(FILE*archivo_enteros,FILE*archivo_nuevo){
	char caracter;
	int numero;
	while(!feof(archivo_enteros)){
		fread(&numero,sizeof(numero),1,archivo_enteros);
		caracter=(char)numero;
		fputc(caracter,archivo_nuevo);
	}
}	
	
void leer_archivo_txt(FILE*archivo_nuevo){
	char caracter;
	while(!feof(archivo_nuevo)){
		caracter=fgetc(archivo_nuevo);
		printf("%c",caracter);
		}
}

void escribir_texto_b(FILE*archivo_enteros,FILE*archivo_nuevo){
	char caracter;
	int numero;
	while(!feof(archivo_enteros)){
		fread(&numero,sizeof(numero),1,archivo_enteros);
		caracter=(char)numero;
		fwrite(&caracter,sizeof(caracter),1,archivo_nuevo);
	}
}	
	
void leer_archivo_b(FILE*archivo_nuevo){
	char caracter;
	while(!feof(archivo_nuevo)){
		fread(&caracter,sizeof(caracter),1,archivo_nuevo);
		printf("%c",caracter);
		}
}


int main(){
FILE*archivo_enteros;
FILE*archivo_nuevo;
	
archivo_enteros=fopen("archivos_enteros.dat","wb");
archivo_nuevo=fopen("archivo_caracteres.txt","w");	
	
if(archivo_enteros==NULL||archivo_nuevo==NULL){
	printf("no se pudo abrir alguno de los dos archivos");
}
else{
	cargar_archivo_numero(archivo_enteros);
	fclose(archivo_enteros);
	archivo_enteros=fopen("archivos_enteros.dat","rb");
	if(archivo_enteros==NULL){
		printf("no se pudo abrir el archivo");
	}
	else{
		escribir_texto_txt(archivo_enteros,archivo_nuevo);
		fclose(archivo_nuevo);
		archivo_nuevo=fopen("archivo_caracteres.txt","r");
		if(archivo_nuevo==NULL){
			printf("no se pudo abrir el archivo");
		}
		else{
			leer_archivo_txt(archivo_nuevo);
			fclose(archivo_nuevo);
		}
	}
}		
return 0;}
*/
//4//
/*
#include <stdio.h>
#include <stdbool.h>
int count_digits(int num) {
    int num_digits = 0;
    while (num > 0) {
        num /= 10;
        num_digits++;
    }
    return num_digits;
}


void cargar_archivo(FILE*archivo){
int numero;
bool seguir=true;
printf("ingrese numeros de 5 digitos ordenados en forma ascendente");
while(seguir==true){
	printf("\ningrese un numero de 5 digitos(si hay distinta cantidad de digitos termina):");
	scanf("%i",&numero);
	if(count_digits(numero)!=5){
		seguir=false;
	}
	else{
		fwrite(&numero,sizeof(numero),1,archivo);
	}
}
}
void mostrar_archivo(FILE*archivo){
archivo=fopen("archivo_arreglado.dat","rb");
int numero;
if (archivo==NULL){
	printf("no se pudo abrir el archivo");
}
else{
	while(!feof(archivo)){
		fread(&numero,sizeof(int),1,archivo);
		printf("\n%i",numero);
	}
	fclose(archivo);
}
}

void ordenar_archivos_en_uno_nuevo(FILE*archivo1,FILE*archivo2,FILE*archivo_salida){
archivo_salida=fopen("archivo_arreglado.dat","wb");
archivo1=fopen("archivo_5digitos1.dat","rb");
archivo2=fopen("archivo_5digitos2.dat","rb");
int numero1,numero2;
if (archivo_salida==NULL||archivo1==NULL||archivo2==NULL){
	printf("la operacion salio mal no se pudo abrir el archivo");
}
else{
		fread(&numero1,sizeof(int),1,archivo1);
		fread(&numero2,sizeof(int),1,archivo2);
	while((!feof(archivo1))&&(!feof(archivo2))){
		if(numero1<numero2){
			fwrite(&numero1,sizeof(int),1,archivo_salida);
			fread(&numero1,sizeof(int),1,archivo1);
		}
		else{
			fwrite(&numero2,sizeof(int),1,archivo_salida);
			fread(&numero2,sizeof(int),1,archivo2);
		}		
	}
	while(!feof(archivo1)){
		fwrite(&numero1,sizeof(int),1,archivo_salida);
		fread(&numero1,sizeof(int),1,archivo1);	
	}
	while(!feof(archivo2)){
		fwrite(&numero2,sizeof(int),1,archivo_salida);
		fread(&numero2,sizeof(int),1,archivo2);	
	}
	
fclose(archivo_salida);
fclose(archivo1);
fclose(archivo2);	
}
}



int main(){
FILE*archivo1;
FILE*archivo2;
FILE*archivo_final;	

archivo1=fopen("archivo_5digitos1.dat","wb");
archivo2=fopen("archivo_5digitos2.dat","wb");	
if(archivo1==NULL || archivo2==NULL){
	printf("no se pudo abrir los archivos");	
}
else{
	cargar_archivo(archivo1);
	cargar_archivo(archivo2);
	fclose(archivo1);
	fclose(archivo2);
	ordenar_archivos_en_uno_nuevo(archivo1,archivo2,archivo_final);
	mostrar_archivo(archivo_final);
}	
	
	
}
*/
//4// reversionado valentin //revisar devuelta el punto 4//
/*
#include <stdio.h>
#define MAXF 100

typedef int T_Vector[MAXF];

int busqueda(T_Vector vector, int inf, int sup, int *numero) {
	if (*numero < vector[inf] || *numero > vector[sup])
		return -1;
	else {
		int medio = (inf + sup) / 2;

		if (*numero == vector[medio])
			return medio;
		else if (*numero < vector[medio])
			return busqueda(vector, inf, medio - 1, numero);
		else
			return busqueda(vector, medio + 1, sup, numero);
	}
}

void insertar_no_repetidos(T_Vector vector, int *ml, int numero) {
	if (*ml < MAXF) {
		if (*ml == 0) {
			vector[0] = numero;
			(*ml)++;
		} else if (busqueda(vector, 0, *ml - 1, &numero) == -1) {
			int i = *ml, aux;
			vector[i] = numero;

			while (i >= 0 && vector[i - 1] > vector[i]) {
				aux = vector[i - 1];
				vector[i - 1] = vector[i];
				vector[i] = aux;
				i--;
			}

			(*ml)++;
		}
	}
}

void concatenar_archivos(FILE *arNums1, FILE *arNums2, FILE *nuevoArchivo) {
	T_Vector numsConcatenados;
	int i, numero, mlConcatenados = 0;

	do {
		fscanf(arNums1, "%i", &numero);
		insertar_no_repetidos(numsConcatenados, &mlConcatenados, numero);
	} while (!feof(arNums1));

	do {
		fscanf(arNums2, "%i", &numero);
		insertar_no_repetidos(numsConcatenados, &mlConcatenados, numero);
	} while (!feof(arNums2));

	for (i = 0; i < mlConcatenados; i++) {
		fprintf(nuevoArchivo, "%i\n", numsConcatenados[i]);
	}
}

void main() {
	FILE *arNums1 = fopen("../FILES/nums5digitos1.txt", "r");
	FILE *arNums2 = fopen("../FILES/nums5digitos2.txt", "r");

	if (arNums1 == NULL || arNums2 == NULL)
		printf("No se pudo abrir uno de los archivos...");
	else {
		FILE *arConcatenado = fopen("../FILES/nums5digitos.txt", "w");
		concatenar_archivos(arNums1, arNums2, arConcatenado);
		fclose(arNums1);
		fclose(arNums2);
		fclose(arConcatenado);
	}
}
*/
//5//
/*
#include<stdio.h>
#include <stdbool.h>
#include <string.h>
#define MAX 60
#define MAXN 5
typedef char nombre[MAX];
typedef nombre nombres[MAXN];
void cargar_archivo(FILE*archivo_nombres_desordenados){
archivo_nombres_desordenados=fopen("archivo_nombres.dat","wb");
if(archivo_nombres_desordenados==NULL){
	printf("no se pudo realizar la operacion con el archivo");
	
}
else{
	nombre nombre;
	int i=0;
	bool seguir=true;
	while(seguir==true && i<MAXN){
		printf("ingrese un nombre y apellido o 0 para terminar:");
		fgets(nombre,MAX,stdin);
		fflush(stdin);
		nombre[strcspn(nombre,"\n")]='\0';
		if(nombre[0]=='0'){
			seguir=false;
		}
		else{
			fwrite(nombre,sizeof(nombre),1,archivo_nombres_desordenados);
			i++;
		}
	}
	fclose(archivo_nombres_desordenados);
	printf("%i",i);
}
}

void leer_archivo_pasar_a_vector(FILE*archivo_nombres_desordenados,nombres nombres,int*ml){
archivo_nombres_desordenados=fopen("archivo_nombres.dat","rb");
nombre nombre;
int i=(*ml);
if(archivo_nombres_desordenados==NULL){
	printf("no se pudo abrir el archivo");
}
else{
	fread(nombre,sizeof(nombre),1,archivo_nombres_desordenados);
	strcpy(nombres[i],nombre);
	while(!feof(archivo_nombres_desordenados) && i<MAXN){
		i++;
		fread(nombre,sizeof(nombre),1,archivo_nombres_desordenados);
		strcpy(nombres[i],nombre);
	}
	i--;
	fclose(archivo_nombres_desordenados);
	printf("%i",i);
}
}

int main(){
FILE*archivo_desordenado;
FILE*archivo_nuevo;
nombres nombres;
int ml=0,i;
cargar_archivo(archivo_desordenado);
leer_archivo_pasar_a_vector(archivo_desordenado,nombres,&ml);
for(i=0;i<MAXN;i++){
	printf("\n%s",nombres[i]);
}	
return 0;}
*/

//6//










