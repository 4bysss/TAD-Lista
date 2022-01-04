#ifndef __LISTADIM__
#define __LISTADIM__
#include<cassert>
#include<iostream>
template <typename TIPO>class lista{
	struct nodo;
	public:
		typedef nodo* posicion;						//Hacemos un typedef de nodo* de cara a más comodidad a futuro
		lista();							//Constructor predeterminado
		lista(lista<TIPO>&l);						//Constructor por copia
		lista<TIPO>& operator=(const lista<TIPO>&L);			//Sobrecarga del operador =
		bool vacia()const;						//Comprobador de que la lista esta vacia (en caso de estarlo devuelvo true)
		void insertar(const TIPO&x,const posicion pos);			//Metodo con el que se puede insertar un elemento en una lista 
		void eliminar(const posicion pos);				//Metodo con el que se puede eliminar un elemento de una lista dada una determinada posicion
		const TIPO& elemento(const posicion pos)const;			//Metodo que devuelve el elemento que hay en una determinada posicion
		TIPO& elemento(posicion pos);
		posicion buscar(const TIPO& x)const;				//Metodo que busca un elemento en la lista y devuelve su posicion
		posicion siguiente(posicion pos)const;				//Metodo que dada una posicion devuelve el siguiente 
		posicion anterior (posicion pos)const;				//Metodo que dada una posicion devuelve el anterior a esta 
		posicion primera()const;					//Metodo que devuelve la primera posiciond de la lista y en caso de estar vacia devuelve fin()
		posicion fin()const;						//Metodo que devuelve la posicion siguiente al ultimo elemento
		~lista();							//Destructor de la lista
	private:
		struct nodo{
			TIPO elemento;
			nodo* siguiente;
			nodo(TIPO elem,nodo *pos=nullptr): elemento(elem), siguiente(pos){};
		};
		nodo* L; 							//Cabecera de la lista
		void copiar(const lista<TIPO>& list);				//Metodo que copia una lista enlazada
};
//Metodo privado
template <typename TIPO>
void lista<TIPO>::copiar(const lista<TIPO>&l){
	L=new nodo(TIPO());
	nodo *q= L;
	nodo*r=l.L->siguiente->siguiente;
	while(r->siguiente!=l.L->siguiente){				
		q->siguiente=new nodo(r->elemento);
		r=r->siguiente;
		q=q->siguiente;
	}
	q->siguiente=new nodo(r->elemento);
	q=q->siguiente;
	q->siguiente=L;
	L=q;
}
//Metodos publicos
template <typename TIPO>
lista<TIPO>::lista(){
	L=new nodo (TIPO());
	L->siguiente=L;
}
template <typename TIPO>
lista<TIPO>::lista(lista<TIPO>&l){
	copiar(l);
}
template <typename TIPO>
lista<TIPO>& lista<TIPO>::operator=(const lista<TIPO>&l){
	if(this!=&l){
		this->~lista();
		copiar(l);
	}
	return *this;
}
template <typename TIPO>
bool lista<TIPO>::vacia()const{
	return(L->siguiente==L);
}
template <typename TIPO>
void lista<TIPO>::insertar(const TIPO&x, lista<TIPO>::posicion pos){
	pos->siguiente=new nodo(x,pos->siguiente);
	if(pos==L){
		L=pos->siguiente;
	}
}
template <typename TIPO>
void lista<TIPO>::eliminar(lista<TIPO>::posicion pos){
	assert(pos!=L);
	if(pos->siguiente==L){
		L=pos;
	}
	nodo* q=pos->siguiente;
	pos->siguiente=q->siguiente;
	delete q;
}
template <typename TIPO>
const TIPO& lista<TIPO>::elemento(lista<TIPO>::posicion pos)const{
	assert(pos!=L);	
	return pos->siguiente->elemento;
}
template <typename TIPO>
TIPO& lista<TIPO>::elemento(lista<TIPO>::posicion pos){
	assert(pos!=L);	
	return pos->siguiente->elemento;
}
template <typename TIPO>
typename lista<TIPO>::posicion lista<TIPO>::buscar(const TIPO&x)const{
	nodo *q= L->siguiente;
	while(q->siguiente->elemento!=x&&q->siguiente!=L){
		q=q->siguiente;
	}
	if(q->siguiente->elemento==x){
	}
	return q;
}
template <typename TIPO>
typename lista<TIPO>::posicion lista<TIPO>::siguiente(lista<TIPO>::posicion pos)const{
	assert(pos->siguiente!=L);
	return pos->siguiente;
}
template <typename TIPO>
typename lista<TIPO>::posicion lista<TIPO>::anterior(lista<TIPO>::posicion pos)const{
	assert(pos!=L->siguiente);
	nodo*q=L->siguiente;
	while(q->siguiente!=pos){
		q=q->siguiente;
	}
	return q;
}
template <typename TIPO>
typename lista<TIPO>::posicion lista<TIPO>::primera()const{
	return L->siguiente;
}
template <typename TIPO>
typename lista<TIPO>::posicion lista<TIPO>::fin()const{
	return L;
}
template <typename TIPO>
lista<TIPO>::~lista(){
	nodo*p=L->siguiente;
	nodo*q;
	while(p!=L){
		q=p->siguiente;
		delete p;
		p=q;
	}
	delete p;
}
#endif


