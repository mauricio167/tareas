#include <stdio.h>
#include <stdlib.h>
#define vacia (inicio == NULL)
typedef struct datos elemento;
struct datos{
	float dato;
	elemento *siguiente;
};

void error(void){
	exit(1);
}
elemento *nuevoelemento(){
	elemento *q= (elemento *)malloc(sizeof(elemento));
	if(!q) error();
	return (q);
}

void poner(elemento **p, float x);
void pop(elemento **p);
int main(){
	elemento *inicio=NULL;
	float a,b;
	char op[81];
	printf("introducir los datos de la siguiente manera: \n");
	printf(">operador 1\n>operador 2\n>operador\npara salir pulse q");
	do{
		printf("> ");
		gets(op);
		switch(*op){
		case '+':
			b = pop(&inicio); a= pop(&inicio);
			printf("%g\n",a+b);
			poner(&inicio,a+b);
			break;
		case '-':
				b = pop(&inicio); a= pop(&inicio);
				printf("%g\n",a-b);
				poner(&inicio,a-b);
				break;
		case '*':
			b=pop(&inicio); a = pop(&inicio);
			printf("%g\n",a*b);
			poner(&inicio,a*b);
			break;
		case '/':
			b=pop(&inicio); a= pop(&inicio);
			if(b==0){
				printf("division por 0");
				break;
			}else{
				printf("%g\n",a/b);
				poner(&inicio,a/b);
			}
			break;
		default:
			poner(&inicio,atof(op));
		}
	} while(*op!='q');
}

void poner(elemento **p, float x){
	elemento *q, *inicio;
	inicio= *p;
	q=nuevoelemento();
	q->dato=x;
	q->siguiente=inicio;
	inicio = q;
	*p= inicio;
}
float pop(elemento **p){
	elemento *incio;
	float x;
	incio= *p; 
	if(vacia){
		return 0;
	}else{
		x=inicio->dato;
		*p=incio->siguiente;
		free(inicio);
		return(x);
	}
}
