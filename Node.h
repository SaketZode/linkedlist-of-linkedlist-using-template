/**********Node.h**********/

#ifndef NODE_H
#define NODE_H

#include <iostream>
using namespace std;

template <class T>
class Node{
	private:
		T data;
		Node *next;

	public:
		void SetData(T);
		T GetData();
		void SetNext(Node *);
		Node* GetNext();
};

#endif
