#include <iostream>
#include "listaDoblemente.h"

int main(){
	lista<int>a,b,c;
	int i=0;
	for(int i=0;i<10;i++){
		a.insertar(i,a.primera());
		b.insertar(i+5,b.primera());
		std::cout<<b.elemento(b.primera())<<",";
	}
	c=b;
	b.buscar(8);
	b.eliminar(b.anterior(b.fin()));
	std::cout<<"Las cositas de B son:"<<std::endl;
	while(i<9){
		std::cout<<b.elemento(b.primera())<<",";
		b.eliminar(b.primera());
		i++;
	}

	std::cout<<i<<std::endl;
	std::cout<<"Las cositas de A son:"<<std::endl;
	while(a.primera()!=a.fin()){
		std::cout<<a.elemento(a.primera())<<",";
		a.eliminar(a.primera());
	}
	std::cout<<std::endl;
	c.insertar(99,c.fin());
	std::cout<<"Las cositas de C son:"<<std::endl;
	while(c.primera()!=c.fin()){
		std::cout<<c.elemento(c.primera())<<",";
		c.eliminar(c.primera());
	}
	std::cout<<std::endl;
	std::cout<<"Funciona correctamente ;)";

	return 0;
	}
	
