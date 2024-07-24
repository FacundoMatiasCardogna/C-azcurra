//GUIA DE MEMORIA DINAMICA//
// 1) Escribir un programa el cual reserve memoria dinámica para almacenar un número entero (int), le solicite al usuario el ingreso de un número y se asigna dicho valor en la memoria reservada, luego mostrar dicho valor por pantalla Liberar la memoria reservada al finalizar el programa.//
/*
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(){
  int*numero=NULL;
  numero=(int*)malloc(sizeof(int));
  if (numero==NULL){
      printf("no se pudo realizar la asignacion de memoria");  
  }
  else{
    printf("ingrese el numero a almacenar en memoria dinamica:");
    scanf("%i",numero);
    printf("el numero es %i",*numero);
    free(numero);
  }
return 0;
}
*/
// 2)Escribir un programa el cual reserve memoria dinámica para almacenar una cierta cantidad de números enteros (n * int), este valor n debe ser ingresado por el usuario. Luego solicitarle que ingresé n valores enteros ingresados de a uno y almacenarlos en la memoria previamente reservada. Mostrar luego todos los valores ingresados. Liberar la memoria reservada al finalizar el programa.//

// 3) Asumiendo que ya existe un puntero que apuntan a un bloque de memoria previamente reservada con malloc de tamaño (n * int), redimensionar dicha memoria a un tamaño de (2 * n *int).//
//enteros+i es lo mismo que &enteros[i] estos dos dan posicion de referencia//
//*(enteros + i) y enteros[i] son iguales estos dos dan el valor que esta dentro del puntero//
/*
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void cargar_enteros(int*enteros,int n,int*ml){
  for(int i=*ml;i<n;i++){
    printf("ingrese el numero %i:",i+1);
    scanf("%i",&enteros[i]);
    (*ml)++;    
  }
}
void mostrar_enteros(int*enteros,int n){
  for(int i=0;i<n;i++){
    printf("el numero de la posicion %i es:%i\n",i+1,enteros[i]);// "*"(enteros+i) seria lo mismo 
  }
} 

int* redimensionar_enteros(int*enteros,int n){
  int*aux=NULL;
  aux=realloc(enteros,sizeof(int)*n);
  if (aux==NULL){
    printf("no se pudo asignar memoria");
  }
  else{
    enteros=aux;
    printf("reasignacion de memoria existosa\n");
  }
return enteros;}
 
int main(){
  int*numeros=NULL,n,ml=0;
  printf("ingrese la cantidad de numeros enteros que quiere ingresar:");
  scanf("%i",&n);
  numeros=(int*)malloc(sizeof(int)*n);
  if (numeros==NULL){
    printf("no se pudo realizar la operacion");
  }
  else{
    cargar_enteros(numeros,n,&ml);
    mostrar_enteros(numeros,n);
    n*=2;
    redimensionar_enteros(numeros,n);
    cargar_enteros(numeros,n,&ml);
    mostrar_enteros(numeros,n);
    free(numeros);
  }
  return 0;
}
*/
//4) Escribir un programa el cual reserve memoria dinámica para almacenar un struct del tipo t_alumno (ver anexo). Luego solicitar al usuario que ingrese los datos del alumno y almacenarlos en la memoria previamente reservada.Mostrar luego todos los datos del alumno. Liberar la memoria reservada al finalizar el programa.//
/*
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
int padron;
char nombre[30];
char apellido[30];
}t_alumno;

void cargar_alumno(t_alumno*alumno){
  printf("ingrese el padron del alumno:");
  scanf("%i",&(*alumno).padron);//&alumno->padron
  fflush(stdin);
  printf("ingrese el nombre del alumno:");
  scanf("%s",(*alumno).nombre);//alumno->nombre
  fflush(stdin);
  printf("ingrese el apellido del alumno:");
  scanf("%s",alumno->apellido);
  fflush(stdin);
}

void mostrar_alumno(t_alumno*alumno){
printf("nro padron:%i,nombre:%s,apellido:%s",(*alumno).padron,alumno->nombre,alumno->apellido);
}

int main(){
  t_alumno*alumno=NULL;
  alumno=(t_alumno*)malloc(sizeof(t_alumno));
  if(alumno==NULL){
    printf("error al realizar la operacion");
  }
  else{
    cargar_alumno(alumno);
    mostrar_alumno(alumno);
    free(alumno);
  }  
return 0;
}
*/
//5)Escribir un programa el cual reserve memoria dinámica para almacenar una cantidad n de struct del tipo t_alumno (ver anexo). El usuario debe ingresar la cantidad n. Luego solicitar al usuario que ingrese los datos de los n alumnos y almacenarlos en la memoria previamente reservada. Mostrar luego todos los datos de todos los alumnos. Liberar la memoria reservada al finalizar el programa//
//6)Implementar una función que retorna un puntero a un struct del tipo t_alumno (ver anexo), el cual apunta a un bloque de memoria dinámica,respetando la siguiente declaración. En caso de no poder reservar la memoria,retornar NULL.t_alumno* crear_alumno();//
/*
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
int padron;
char nombre[30];
char apellido[30];
}t_alumno;

t_alumno*crear_alumno(){
  t_alumno*alumno=NULL;
  alumno=(t_alumno*)malloc(sizeof(t_alumno));
  return alumno;
}
t_alumno*crear_alumnos(int n){
  t_alumno*alumnos=NULL;
  alumnos=(t_alumno*)malloc(sizeof(t_alumno)*n);
  return alumnos;
}


void cargar_alumnos(t_alumno*alumnos,int n,int*ml){
  for(int i=(*ml);i<n;i++){
    printf("ingrese el padron del alumno:");
    scanf("%i",&alumnos[i].padron);//&alumno->padron
    fflush(stdin);
    printf("ingrese el nombre del alumno:");
    scanf("%s",alumnos[i].nombre);//alumno->nombre
    fflush(stdin);
    printf("ingrese el apellido del alumno:");
    scanf("%s",alumnos[i].apellido);
    fflush(stdin);
    (*ml)++;
  }
}

void mostrar_alumno(t_alumno*alumnos,int n){
  for(int i=0;i<n;i++){
    printf("el padron del alumno %i es:%i\n",i+1,(*(alumnos+i)).padron);//alumnos[i].padron
    printf("el nombre del alumno %i es:%s\n",i+1,alumnos[i].nombre);
    printf("el nombre del alumno %i es:%s\n",i+1,alumnos[i].apellido);
  }
}

int main(){
int n,ml1=0,ml2=0;
  printf("ingrese la cantidad de alumnos que desea ingresar:");
  scanf("%i",&n);
  t_alumno*alumno=crear_alumno(),*alumnos=crear_alumnos(n);
  if(alumno==NULL){
  printf("no se pudo reservar el espacio");
  }
  else{
    cargar_alumnos(alumno,1,&ml1);
    mostrar_alumno(alumno,1);
    free(alumno);
  }
  if(alumnos==NULL){
    printf("no se pudo reservar el espacio");
  }
  else{
    cargar_alumnos(alumnos,n,&ml2);
    mostrar_alumno(alumnos,n);
    free(alumnos);
  }
  




  
return 0;
}
*/
//8//
//8)Implementar una función que retorna un puntero a un vector de n valores de tipo int, todos inicializados en cero, el cual apunta a un bloque de memoria dinámica, respetando la siguiente declaración. En caso de no poder reservar la memoria, retornar NULL.int* crear_vector_inicializado(int n);//
/*
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


int* crear_vector_inicializado(int n){
  int*vector=NULL;
  vector=(int*)calloc(n,sizeof(int));

return vector;}

void mostrar_vector(int*vector,int n){
for(int i=0;i<n;i++){
  printf("\nel numero alojado en la posicion %i es:%i",i+1,vector[i]);
  }
}

void cargar_vector(int*vector,int*ml,int n){
  for(int i=(*ml);i<n;i++){
    printf("\ningrese el numero de la posicion %i;",i+1);
    scanf("%i",(vector+i));//&vector[i]
    (*ml)++;
  }
}

int main(){
  int n,ml=0;;
  printf("ingrese la cantidad de numeros del vector:");
  scanf("%i",&n);
  int*vector=crear_vector_inicializado(n);
  if (vector==NULL){
    printf("no se pudo realizar el proceso");
  }
  else{
    mostrar_vector(vector,n);
    cargar_vector(vector,&ml,n);
    mostrar_vector(vector,n);
    free(vector);
  }

  
return 0;}
*/
//9//
//9) Reservar memoria para almacenar una palabra ingresada por el usuario, esleída en una cadena auxiliar, luego copiada a memoria dinámica, recordando que se requiere adicionar un carácter de fin de cadena//
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 30
typedef char cadena[MAX];
int main(){
  cadena aux;
  printf("ingrese una palabra:");
  fgets(aux,MAX,stdin);
  aux[strcspn(aux,"\n")]='\0';
  char*cadena=NULL;
  cadena=malloc(sizeof(char)*(strlen(aux)+1));
  if(cadena!=NULL){
    strcpy(cadena,aux);
    printf("la cadena en memoria dinamica es:%s",cadena);
    free(cadena);
  }
  else{
    printf("error en la asignacion");
  }

  
return 0;
}
*/
// 10)Utilizar memoria dinámica para almacenar una cierta cantidad de n palabras ingresadas por el usuario. Crear una estructura de datos dinámica de dos dimensiones que permita almacenar esta información. Mostrar toda la información de la estructura luego de haber sido cargada. Liberar toda la memoria al finalizar el programa.//
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 30
typedef char cadena[MAX];

typedef char* t_palabra;
typedef t_palabra* t_vec;

void cargar_vector(t_vec vector,int n){
  int i;
  cadena aux;
  for(i=0;i<n;i++){
    printf("ingrese la palabra %i:",i+1);
    fgets(aux,MAX,stdin);
    aux[strcspn(aux,"\n")]='\0';
    fflush(stdin);
    vector[i]=NULL;
    vector[i]=(char*)malloc(sizeof(char)*(strlen(aux)+1));
    if (vector[i]==NULL){
      printf("no se pudo asignar memoria para la palabra:%i",i+1);
    }
    else{
      strcpy(vector[i],aux);
    }
  }
}

void mostrar_vector(t_vec vector,int n){
  int i;
  for(i=0;i<n;i++){
    printf("%s",*(vector+i));//lo mismo que vector[i]
  }
}
    
void liberar_memoria(t_vec vector,int n){
  int i;
  for(i=0;i<n;i++){
    free(vector[i]);
  }
  free(vector);
}

int main(){
int n;
printf("ingrese la cantidad de palabras que desea ingresar:");
scanf("%i",&n);
getchar();
fflush(stdin);
t_vec vector_palabras=NULL;
vector_palabras=(t_palabra*)malloc(sizeof(t_palabra)*n);
  if (vector_palabras==NULL){
    printf("no se pudo realizar la opercion");
  }
  else{
    cargar_vector(vector_palabras, n);
    mostrar_vector(vector_palabras,n);
    liberar_memoria(vector_palabras,n);
    
    
  }

  

  
return 0;}
*/
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 30
typedef char cadena[MAX];

typedef int* numero;
typedef numero* t_vec;

void cargar_vector(t_vec vector,int n){
  int i,aux;
  for(i=0;i<n;i++){
    printf("ingrese el numero de la posicion %i:",i+1);
    scanf("%i",&aux);
    fflush(stdin);
    vector[i]=NULL;
    vector[i]=(int*)malloc(sizeof(int));
    if (vector[i]==NULL){
      printf("no se pudo asignar memoria para la palabra:%i",i+1);
    }
    else{
      *vector[i]=aux;
    }
  }
}

void mostrar_vector(t_vec vector,int n){
  int i;
  for(i=0;i<n;i++){
    printf("el numero de la posicion %i es:%i\n",i+1,**(vector+i));
  }
}

void liberar_memoria(t_vec vector,int n){
  int i;
  for(i=0;i<n;i++){
    free(vector[i]);
  }
  free(vector);
}

int main(){
int n;
printf("ingrese la cantidad de numeros que desea ingresar:");
scanf("%i",&n);
fflush(stdin);
t_vec vector_palabras=NULL;
vector_palabras=(numero*)malloc(sizeof(numero)*n);
  if (vector_palabras==NULL){
    printf("no se pudo realizar la opercion");
  }
  else{
    cargar_vector(vector_palabras, n);
    mostrar_vector(vector_palabras,n);
    liberar_memoria(vector_palabras,n);
  }
return 0;  
}
*/
