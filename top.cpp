#include <iostream>
#include <cstdlib>
#include <ctime>

//Gabriel Gomez
//Puro codigo serio.

using namespace std;

void selection(int *array,int l){
	int may=0,pos,aux;
	for(int i=0;i<l;i++){
		may=0;
		for(int j=0;j<l-i;j++){
			if(array[j]>may){
				may=array[j];
				pos=j;
			}
		}
		array[pos]=array[l-i-1];
		array[l-i-1]=may;
	}
}

void bubble(int *array,int l){
	int aux;
	for(int i=1;i<=l;i++){
		for(int j=0;j<l-i;j++){
			if(array[j]>array[j+1]){
				aux=array[j];
				array[j]=array[j+1];
				array[j+1]=aux;
			}
		}
	}
}

void shell(int *array,int l){
	bool band;
	int increase=l/2,aux;
	while(increase>0){
		band=false;
		for(int j=0;j+increase<l;j++){
			if(array[j]>array[increase+j]){
				aux=array[j];
				array[j]=array[increase+j];
				array[increase+j]=aux;
				band=true;
				j++;
			}
		}
		if(!band){
			increase/=2;
		}
		band=true;
	}
}

void shaker(int *array,int l){
	int izq=0,der=l,aux;
	bool band=true;
	for(int i=1;i<=l&&band;i++){
		band=false;
		for(int j=izq;j<der-i;j++){
			if(array[j]>array[j+1]){
				aux=array[j];
				array[j]=array[j+1];
				array[j+1]=aux;
				band=true;
			}
		}
		for(int j=der-i;j>izq;j--){
			if(array[j]<array[j-1]){
				aux=array[j];
				array[j]=array[j-1];
				array[j-1]=aux;
				band=true;
			}
		}
	}
}

void insertion(int *array,int l){
	int j,aux;
	for(int i=0;i<l;i++){
		j=i;
		while(j>0&&array[j]<array[j-1]){
			aux=array[j];
			array[j]=array[j-1];
			array[j-1]=aux;
			j--;
		}
	}
}

int main(){
	int l=8;
	int cad[l];
	srand(time(NULL));
	for(int i=0;i<l;i++){
		cad[i]=(rand()%100)+1;
		printf("%d\n",cad[i]);
	}
	printf("------\n");
	//bubble(cad,l);
	//selection(cad,l);
	//shell(cad,l);
	//shaker(cad,l);
	//insertion(cad,l);
	printf("------\n");
	for(int i=0;i<l;i++){
		printf("%d\n",cad[i]);
	}
	return 0;
}
