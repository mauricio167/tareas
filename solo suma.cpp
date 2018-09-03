#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct nodo Nodo;
typedef Nodo *pelemento;
struct nodo{
	int dato;
	pelemento siguiente;
	pelemento anterior;
};
typedef struct listadoble listdob;
struct listadoble{
	pelemento inicio;
	pelemento final;
};
void insertar(listdob*lista1,int dato);
void visualizarlista(listdob nlista);
int listaVacia();
void suma(listdob list1,listdob list2);
pelemento nuevoElemento();
pelemento inicio=NULL;
pelemento final=NULL;
int main(){
	int a,b,n;
	listdob Lista1,Lista2;
	Lista1.inicio=NULL;
	Lista2.inicio=NULL;
	Lista1.final=NULL;
	Lista2.final=NULL;
	scanf("%i",&a);
	do{
		n=a%10;
		a=a/10;
		insertar(&Lista1,n);
	}while(a!=0);
	visualizarlista(Lista1);
	printf("\n");
	scanf("%i",&b);
	do{
		n=b%10;
		b=b/10;
		insertar(&Lista2,n);
	}while(b!=0);
	visualizarlista(Lista2);
	printf("\n la suma es \n");
	suma(Lista1,Lista2);
}

void visualizarlista(listdob nlista){
	if(nlista.inicio!=NULL){
		pelemento aux=nlista.inicio;
		while(aux!=NULL){
			printf("%i\n ",aux->dato);
			aux=aux->siguiente;
		}
	}
}

void insertar(listdob*lista,int dato){
	pelemento q=nuevoElemento();
	q->dato=dato;
	q->anterior=NULL;
	q->siguiente=NULL;
	if((lista->inicio==NULL) && (lista->final==NULL)){ 
		lista->inicio=q;
		lista->final=q;
		return;
	}else{
		q->siguiente=lista->inicio;
		lista->inicio->anterior=q;
		lista->inicio=q;
	}
}


void suma(listdob list1,listdob list2){
	pelemento aux1= list1.final;
	pelemento aux2= list2.final;
	listdob resultado;
	resultado.inicio=NULL;
	resultado.final=NULL;
	int acarreo=0;
	int digito=0;
	while((aux1!=NULL) && (aux2!=NULL)){
		int suma=aux1->dato + aux2->dato + acarreo;
		acarreo=suma/10;
		digito=suma%10;
		insertar(&resultado,digito);
		aux1=aux1->anterior;
		aux2=aux2->anterior;
	}
	pelemento temp=aux1==NULL ? aux2:aux1;
	while(temp!=NULL){
		int suma=temp->dato+acarreo;
		acarreo=suma/10;
		digito=suma%10;
		insertar(&resultado,digito);
		temp=temp->anterior;
	}
	if(acarreo>0){
		insertar(&resultado,acarreo);		
	}
	visualizarlista(resultado);
}

pelemento nuevoElemento(){
	pelemento q=(pelemento)malloc(sizeof(Nodo));
	return q;
}
