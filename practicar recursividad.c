//1//
/*
#include <stdio.h>
unsigned long long int factorial(int numero){
	if (numero<0){
		return -1;
	}
	else{
		if(numero==0){
			return 1;
		}
		return(numero*(factorial(numero-1)));
	}
}


int main(){
unsigned long long int numero;
printf("ingrese un numero entero positivo o igual a 0 para calcular su factorial:");
scanf("%llu",&numero);
while(numero<0){
	printf("ingrese un numero entero positivo o igual a 0 para calcular su factorial:");
	scanf("%llu",&numero);
}
printf("el factorial de %llu es:%llu",numero,factorial(numero));
return 0;
}
*/
//2//
/*
#include <stdio.h>

int fibonacci(int numero){
	if (numero<0){
		
		return -1;
	}
	if(numero==0){
		return 0;
	}
	if(numero==1){
		return 1;
	}	
	return(fibonacci(numero-1)+fibonacci(numero-2));	
}

int main(){
	int numero,i;
	printf("ingrese que hasta que termino quiere calcular fibonacci:");
	scanf("%i",&numero);
	while(numero<0){
		printf("ingrese que hasta que termino quiere calcular fibonacci:");
		scanf("%i",&numero);
	}
	for(i=0;i<=numero;i++){
		printf("\nel termino %i de fibonacci es igual:%i",i,fibonacci(i));
	}
	
return 0;
}
*/
//3//
/*
#include <stdio.h>
#include <string.h>
#define MAX 100
typedef int enteros[100];

int busqueda_binaria(enteros numeros,int buscado,int inicio,int fin,){
	if (inicio>fin){
		return -1;
	}
	int medio=(inicio+fin)/2;
	if(vector[medio]==buscado){
		return medio;
	}
	else{
		if(buscado>medio){
			return busqueda_binaria(numeros,buscado,medio+1,fin);
		}
		else{
			return busqueda_binaria(numeros,buscado,inicio,medio-1);
		}
	}
}
*/
//4//
/*
int division_recursiva(int dividendo,int divisor){
	  if(dividendo < divisor) {
            return 0;
        } else {
            return (1+division_recursiva(dividendo-divisor,divisor);
        }
}
*/
//5//
/*
#include <stdio.h>
typedef int Tvector[100];

int busqueda_lineal(tvector vector, int ml,  int mayor){
	if(ml == 0){
    	return mayor;
    }
	else{
    	if(vector[ml-1] >= mayor){
			return busqueda_lineal(vector, ml-1,vector[ml-1]);
   		}
		else{
			return busqueda_lineal(vector, ml-1, mayor);
    	}
  	}
}

a la hora de incializar esta funcion hay que pasarle en mayor a vector[0];
*/
//6//
/*
int invertir_numero(int numero,int invertido){
	if (numero==0){
		return invertido;	
	}
	else{
		invertido=(invertdio*10)+(numero%10);
		return invertir_numero(numero/10,invertido);
	}
}
*/
//7//
/*
int suma_naturales(int numero){
	if(numero<0){
		return -1;
	}
	else{
		if(numero==0){
			return 0;
		}
		else{
			return(numero+suma_naturales(numero-1));
		}
	}
}
*/
//8//
/*
bool es_capicua(int numero_capicua,int original,int numero){
	if (original==num_capicua){
		return true;
	}
	else if(numero==0){
		return false;
	}
	else{
		int resto;
		resto=numero%10;
		return capicua((numero_capicua*10)+resto,original,numero/10);
	}
	
}
*/
//9//
/*	
int sumar_digitos(int numero){
	int digito;
	if(numero==0){
		return numero;
	}
	else{
		return(numero%10+sumar_digitos(numero/10))
	}
} 
*/
//10// 
/*	
//Algoritmo de Euclides recursivo//
int mcd(int a, int b) {
    if (b == 0)
        return a;
    return mcd(b, a % b);
}
//algoritmo de eculides iterativo
*/
//11//
/*
int potencia(int a, int b) {
    if (b == 0)
        return 1;
    return (a*potencia(a,b-1));
}
*/
//12//
/*
#include <stdio.h>
void mostrar_naturales(int numero) {
    if (numero >= 0){
        mostrar_naturales(numero - 1);
        printf("%i ", numero);
    }
}

int main(){
	int n;
	printf("ingrese un numero:");
	scanf("%i",&n);
	mostrar_naturales(n);
	return 0;
}
*/
//13//
/*
#include <stdbool.h>
#include <stdio.h>
bool binario(int num){
	if(num==0||num==1){
		return true;
	}
	else{
		if(((num%10)!=0)&&((num%10)!=1)){
			return false;
		}
	}
	return(binario(num/10));
}
*/
//14//
/*
#include <stdio.h>
void imprimirPunto(int b) {
    if (b > 0) {
        printf(".");
        imprimirPunto(b - 1);
    }
}

void rectangulo(int b, int h) {
    if (h > 0) {
        imprimirPunto(b);
        printf("\n");
        rectangulo(b, h - 1);
    }
}

int main() {
    int num1, num2;

    printf("Ingrese la base: ");
    scanf("%d", &num1);
    printf("Ingrese la altura: ");
    scanf("%d", &num2);

    rectangulo(num1, num2);

    return 0;
}
*/

/*
int sumar_digtios_vector(Tvector vector,int ML){
	if(ML==1){
		return vec[0];
	}
	else{
		return vector[ML-1]+suma_digitos_vector(vector,ML-1);
	}
}
*/

/*
int MCD_recursivo(numero1,numero2){
	if (numero1==numero2){
		return numero1;
	}
	else if (numero1>numero2){
		return MCD_recursivo(numero1-numero2,numero2);
	}
	else if (numero>numero1){
		return MCD_recursivo(numero1,numero2-numero1);
	}
}
*/









