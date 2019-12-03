/**********Node.cpp********/

#include "Node.h"

template <class T>
void Node<T>::SetData(T ele){
	data = ele;
}

template <class T>
T Node<T>::GetData(){
	return data;
}

template <class T>
void Node<T>::SetNext(Node *t){
	next = t;
}

template <class T>
Node<T>* Node<T>::GetNext(){
	return next;
}
