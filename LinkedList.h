/*************LinkedList.h************/

#ifndef LL_H
#define LL_H

#include "Node.cpp"

template <class T>
class LinkedList{
	private:
		Node<T> *head, *tail;
		int cnt;

	public:
		LinkedList();
		Node<T>* GetHead() const;
		bool AddAtBegin(T);
		bool AddAtEnd(T);
		bool AddAtPos(T, int);
		T DelFromBegin();
		T DelFromEnd();
		T DelAtPos(int);
		int GetCount();
		bool IsEmpty() const;
		bool Reverse();
		Node<T>* VisitLoc(int);
		void Display() const;
		template <class U>
		friend ostream& operator<<(ostream &, const LinkedList<T> &);
		/*{
			if(li.IsEmpty()){
                		throw runtime_error("Empty List");
        		}
			Node<T> *t = li.head;
			while(t != nullptr){
				out<<t->GetData()<<"-->";
				t = t->GetNext();
			}
			out<<"nullptr"<<endl;
			return out;
		}*/
		~LinkedList();
};

#endif

