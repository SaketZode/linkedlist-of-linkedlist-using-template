#include "LinkedList.cpp"

int main(){
	int ele, lno;
	LinkedList <LinkedList<int>> oll;	//outer linked list
	LinkedList <int> ill1;
	LinkedList <int> ill2;
	LinkedList <int> ill3;
	
	//adding elements to inner linked list
	ill1.AddAtEnd(11);
	ill1.AddAtEnd(12);
	ill1.AddAtEnd(13);
	ill2.AddAtEnd(21);
	ill2.AddAtEnd(22);
	ill2.AddAtEnd(23);
	ill3.AddAtEnd(31);
	ill3.AddAtEnd(32);
	ill3.AddAtEnd(33);
	
	//adding inner linked lists to outer list
	oll.AddAtEnd(ill1);
	oll.AddAtEnd(ill2);
	oll.AddAtEnd(ill3);
	
	cout<<"\nObjects inserted"<<endl;

	//displaying the list
	cout<<"\n***************Displaying*********"<<endl;
	try{
		oll.Display();
	}catch(runtime_error e){
		cout<<e.what()<<endl;
	}

	return 0;
}

