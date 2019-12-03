/***********CSLL.cpp***********/

#include "LinkedList.h"

template <class T>
bool LinkedList<T>::IsEmpty() const{
	return (head==nullptr && tail==nullptr);
}

template <class T>
LinkedList<T>::LinkedList():head(nullptr), tail(nullptr), cnt(0){
	Node<T> *t = head;
	while(t != nullptr){
		head = head->GetNext();
		delete t;
		t = head;
	}
	cout<<"CTOR call"<<endl;
}

template <class T>
LinkedList<T>::~LinkedList(){
	
}

template <class T>
bool LinkedList<T>::AddAtBegin(T ele){
	bool Success = false;
	Node<T> *temp = new Node<T>;
	temp->SetData(ele);
	if(IsEmpty()){
		head = tail = temp;
	}
	else{
		temp->SetNext(head);
		head = temp;
	}
	cnt++;
	Success = true;
	return Success;
}

template <class T>
Node<T>* LinkedList<T>::VisitLoc(int c){
	/*if(head==nullptr && tail==nullptr){
		Node<T> *t = new Node<T>;
		head = tail = t;
		return t;
	}*/
	Node<T> *t = head;
	int cc = 1;
	if(c > 0){
		while(cc<=c){
			t = t->GetNext();
			cc++;
		}
	}
	return t;
}

template <class T>
bool LinkedList<T>::AddAtEnd(T ele){
	bool Success = false;
	Node<T> *temp = new Node<T>;
	temp->SetData(ele);
	if(IsEmpty()){
		head = tail = temp;
	}
	else{
		tail->SetNext(temp);
		tail = temp;
	}
	cnt++;
	Success = true;
	return Success;
}

/*template <class T>
bool LinkedList<T>::AddAtPos(T ele, int pos){
	bool Success = false;
	if(cnt >= pos-1){
		Node<T> * = head;
		Node<T> *q = head->GetNext();
		Node<T> *temp = new Node<T>;
		temp->SetData(ele);
		int c = 0;
		while(c < pos-2){
			p = p->GetNext();
			q = q->GetNext();
		}
		p->SetNext(temp);
		temp->SetNext(q);
		cnt++;
	}
	Success = true;
	return Success;
}*/

template <class T>
T LinkedList<T>::DelFromBegin(){
	T ele;
	if(IsEmpty()){
		throw runtime_error("Empty List!");
	}
	ele = head->GetData();
	Node<T> *t = head;
	if(head == tail){
		delete t;
		head = tail = nullptr;
	}
	else{
		head = head->GetNext();
		t->SetNext(nullptr);
		delete t;
	}
	cnt--;
	return ele;
}

template <class T>
T LinkedList<T>::DelFromEnd(){
	T ele;
	if(IsEmpty()){
		throw runtime_error("Empty List!");
	}
	ele = tail->GetData();
	Node<T> *t = head;
	if(head == tail){
		delete t;
		head = tail = nullptr;
	}
	else{
		while(t->GetNext() != tail){
			t = t->GetNext();
		}
		t->SetNext(nullptr);
		delete tail;
		tail = t;
	}
	cnt--;
	return ele;
}

template <class T>
T LinkedList<T>::DelAtPos(int pos){
	T ele;
	if(IsEmpty()){
		throw runtime_error("Empty List");
	}
	Node<T> *p = head;
	Node<T> *q = head->GetNext();
	Node<T> *t = nullptr;
	if(cnt >= pos-1){
		Node<T> *p = head;
		Node<T> *q = head->GetNext();
		Node<T> *t = head;
		int c = 0;
		while(c < pos-2){
			p = p->GetNext();
			q = q->GetNext();
		}
		t = q;
		ele = t->GetData();
		q = q->GetNext();
		p->SetNext(q);
		delete t;
		cnt--;
	}
	return ele;
}

template <class T>
int LinkedList<T>::GetCount(){
	return cnt;
}

template <class T>
bool LinkedList<T>::Reverse(){
	if(IsEmpty()){
		throw runtime_error("Empty List");
	}
	Node<T> *nhead = head;
	Node<T> *t = nullptr;
	head = head->GetNext();
	tail = nhead;
	tail->SetNext(nullptr);
	while(head != nullptr){
		t = head;
		head = head->GetNext();
		t->SetNext(nhead);
		nhead = t;
	}
	head = nhead;
}

template <class T>
Node<T>* LinkedList<T>::GetHead() const{
	return head;
}

template <class T>
ostream& operator<<(ostream &ot, const LinkedList <T> &li){
	//ot<<"\nInside oll"<<endl;
	//return out;
	if(li.IsEmpty()){
		throw runtime_error("Empty List");
	}
	Node<T> *t = li.GetHead();
	while(t != nullptr){
		ot<<t->GetData()<<"-->";
		t = t->GetNext();
	}
	ot<<"nullptr"<<endl;
	//return out;
	//li.Display();
}

template <class T>
void LinkedList<T>::Display() const{
	if(IsEmpty()){
		throw runtime_error("Empty List");
	}
	Node<T> *t = head;
	while(t != nullptr){
		cout<<t->GetData()<<endl;
		t = t->GetNext();
	}
	cout<<endl;
}

/*template <class U>
ostream& operator<<(ostream &out, const LinkedList<U> &l){
	if(l.IsEmpty()){
		throw runtime_error("Empty List");
		//return;
	}
	Node<U> *t = l.head;
	while(t != nullptr){
		out<<t->GetData()<<"-->";
		t = t->GetNext();
	}
	out<<"nullptr"<<endl;
	return out;
}*/
