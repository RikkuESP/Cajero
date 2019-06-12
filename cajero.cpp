#include<iostream>
#include<time.h>
#include<stdlib.h>
#include<math.h>

using namespace std;

void interfaz();
void opciones();
void ingresar();
void sacar();
void ruleta();
void salir();
void seguir();

int saldoBase=1000; 
int aux1=0,aux2=0,num=0,meter=0,quitar=0;
char eleccion;

int main(){
	
	interfaz();
	opciones();
	switch (num){
		case 1: ingresar();
		case 2: sacar();
		case 3: ruleta();
		case 4: salir();
		default: salir();	
	}
	
	system("pause");
	return 0;
}

void interfaz(){
	cout<<"			***************************************************************"<<endl;
	cout<<"			*                                                             *"<<endl;
	cout<<"			*                       Bienvenid@                            *"<<endl;
	cout<<"			*          Este es tu cajero automatico de confianza          *"<<endl;
	cout<<"			*                                                             *"<<endl;
	cout<<"			***************************************************************"<<endl;
}

void opciones(){	
	cout<<" - Tu saldo actual en cuenta es de: "<<saldoBase<<" euros"<<endl;
	cout<<endl;
	cout<<" - Ahora, tienes las siguientes opciones: "<<endl;
	cout<<"   - Ingresar dinero: Pulse 1."<<endl;
	cout<<"   - Sacar dinero: Pulse 2."<<endl;
	cout<<"   - Jugar a la ruleta: Pulse 3."<<endl;
	cout<<"   - Salir: Pulse 4."<<endl;
	cout<<"\n";
	cout<<" Numero:  "; cin>>num;
}

void seguir(){
	cout<<"\n\n Quieres continuar haciendo transacciones o salir? (s/n): "; cin>>eleccion;
	if(eleccion == 's'){
		cout<<"\n\n";
		opciones();
	} else if(eleccion == 'n' || eleccion!='s'){
		salir();
	}
	cout<<endl;
}

void ingresar(){
	cout<<"\n\n";
	cout<<"	**Bip bop beep...** "<<endl;
	cout<<"\n	  Bien! Has elegido ingresar dinero (Recuerda que nos llevamos una comision del 2%)\n";
	cout<<"	  Si ingresas 100 euros, nos quedaremos 2 euros"<<endl;
	cout<<"	  Cuanto dinero quieres ingresar? "; cin>>meter;
	saldoBase += meter;
	cout<<"\n\n	**Bip bop beep...** "<<endl;
	cout<<"\n		Has ingresado "<<meter<<" euros con exito."<<endl;
	seguir();
}


void sacar(){
	cout<<"\n\n **Bip bop beep...** "<<endl;;
	cout<<"\n Bien! Has elegido sacar dinero\n";
	cout<<" Cuanto dinero quieres sacar? "; cin>>quitar;
	cout<<"\n **Bip bop beep...** "<<endl;
	if(saldoBase < quitar){
		cout<<"Ha habido un error fatal";
		seguir();
	}
	cout<<"	Has sacado "<<quitar<<" euros con exito."<<endl;
	saldoBase -= quitar;
	seguir();
}


void ruleta(){
	srand(time(NULL));
	int random = rand()% 10+1;
	int test;
	cout<<"	Dime un numero del 1 al 10, si aciertas ganaras 1.000.000 de euros!!!"<<endl;
	cout<<"	Jugar cuesta 10 euros solamente! :O"<<endl;
	cout<<"	Dime el numero afortunado: "; cin>>test;
	if(test == random){
		saldoBase += 1000000;
		cout<<"	Tu saldo ahora es de "<<saldoBase<<" euros!!";
	}else{
		cout<<"Mas suerte la proxima vez";
	}
	seguir();
	
}


void salir(){
	cout<<"\nUn placer hacer negocios contigo, y recuerda 'El tiempo es oro, colega'\n";
	system("pause");
	exit(1);
}


