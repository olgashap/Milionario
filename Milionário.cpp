/*
Numeros de 1 a 50.
Estrelas de 1 a 12.


1 ) Gerar 1 chave do euromilhões.

    14  16  20  28  39  48  -  3  10

2 ) Impedir a saida de alguns números.

3 ) Garantir a saida de determinados.

4 ) Simultaneamente impedir a saida de alguns numeros e garantir a saida de outros.

*/



#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

//verifica se o numero não está repetido
bool Existe(int numeros[],int quantNumeros, int valor){
	for(int i=0; i < quantNumeros; i++){
		if(numeros[i]==valor)
			return true;
	}
	return false;
}
bool ExisteProibidos(int numeros[],int quantNumeros, int valor){
	for(int i=0; i < quantNumeros; i++){
		if(numeros[i]==valor)
			return true;
	}
	return false;
}



//gera numeros aleatorios
void Aleatorios (int numeros[],int numerosProibidos[],int numerosGarantidos[],int quantNumeros, int Limite,int quantNumerosProibidos,int quantNumerosGarantidos){
	srand(time(NULL));
	int j;
	int valor;
	//cout<<"numero de permitidos"<<quantNumerosGarantidos<<endl;
	
	for(j=0;j<quantNumerosGarantidos-1;++j){
		numeros[j]=numerosGarantidos[j];
	}

	for(int i=quantNumerosGarantidos-2; i<quantNumeros;i++){
		
		valor=rand() % Limite +1;
		while(Existe(numeros,i,valor) || Existe(numerosProibidos,quantNumerosProibidos,valor)){
			valor=rand() %Limite +1;
		}
		numeros[i]=valor;
	}
	
}

//Ordenar numeros por ordem crescente
void Ordenar(int numeros[]){
	for(int j=0;j<5;j++){
		for(int i=0;i<5;i++){
			if(numeros[i]>numeros[j]){
				int troca=numeros[i];
				numeros[i]=numeros[j];
				numeros[j]=troca;
			}
		}
	}
}




int main(){
	
	int numeros[5];
	int numeros_proibidos[49];
	int estrelas_proibidas[11];
	int numeros_garantidos[5];
	int estrelas_garantidas[2];
	
	int num=0;
	int k=0;
	int m=0;
	int p=0;
	int q=0;
	
	//Pedir numeros não desejados
	cout<<"Quais os numeros que nao quer que saiam? (0 para terminar)"<<endl;
	do{
		cin>>num;
		numeros_proibidos[k]=num;
		k+=1;
		
	}
	while(num != 0);
	
	cout<<"Quais as estrelas que nao quer que saiam? (0 para terminar)"<<endl;
	do{
		num=0;
		cin>>num;
		estrelas_proibidas[m]=num;
		m+=1;
		
	}
	while(num != 0);
	
	cout<<"Quais os numeros que quer garantir? (0 para terminar)"<<endl;
	do{
		num=0;
		//--------------------------------------------------
		cin>>num;
		while(Existe(numeros_proibidos,k,num) && num !=0){
			cout<<"Valor já existe nos numeros nao permitidos..!"<<endl;
			cin>>num;
		}
		
		//--------------------------------------------------
		
		
		numeros_garantidos[p]=num;
		p+=1;
		
	}
	while(num != 0 && p < 6  );
	
	cout<<"Quais as estrelas que quer garantir? (0 para terminar)"<<endl;
	do{
		num=0;
		//--------------------------------------------------
		cin>>num;
		while(Existe(estrelas_proibidas,m,num) && num !=0){
			cout<<"Valor já existe nas estrelas nao permitidas..!"<<endl;
			cin>>num;
		}
		
		//--------------------------------------------------
		estrelas_garantidas[q]=num;
		q+=1;
		
	}
	while(num != 0 && q <3);
	
	cout<<"Opcoes Escolhidas:--------------------------"<<endl;
	cout<<"Numeros proibidos:"<<endl;
	for(int i=0; i<k-1;i++){
		cout<<numeros_proibidos[i]<<" \t ";
	}
	
	cout<<endl;
	
	cout<<"Estrelas proibidas:"<<endl;
	for(int i=0; i<m-1;i++){
		cout<<estrelas_proibidas[i]<<" \t ";
	}
	
	cout<<endl;
	
	cout<<"Numeros garantidos:"<<endl;
	for(int i=0; i<p-1;i++){
		cout<<numeros_garantidos[i]<<" \t ";
	}
	
	cout<<endl;
	
	cout<<"Estrelas garantidas:"<<endl;
	for(int i=0; i<q-1;i++){
		cout<<estrelas_garantidas[i]<<" \t ";
	}
	cout<<endl<<endl;
	
	cout<<"chave calculada:-----------------------------"<<endl;
	//Numeros
	Aleatorios(numeros,numeros_proibidos,numeros_garantidos,5,50,k+1,p+1);
	Ordenar (numeros);
	for(int i=0;i<5;i++){
		cout<<numeros[i]<<" \t ";
	}

	cout<<"				 ";
	
	
	//Estrelas
	Aleatorios(numeros,estrelas_proibidas,estrelas_garantidas,2,12,m+1,q+1);
	Ordenar(numeros);
	for(int i=0; i<2;i++){
		cout<<numeros[i]<<" \t ";
	}
}
