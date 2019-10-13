//INSTRUCTION:
//Use the provided text to help create llist.cpp
//based on Yoshii  CS311  Notes-6A

//- Make sure PURPOSE and PARAMETER comments are given
//- Make sure all if-then-else are commented describing which case it is
//- Make sure all local variables are described fully with their purposes
//EMACS HINT:
//  control-K cuts and control-Y pastes
//  Esc X replace-str does string replacements
//  Esc > goes to the end of the file; Esc < to the beginning
//  Tab on each line will indent perfectly for C++

// ====================================================
//HW#: HW3P1 llist
//Your name: **
//Complier:  **
//File type: llist implementation file
//=====================================================

using namespace std;

#include<iostream>
#include"llist.h" 

//constructor
//initializes Front, Rear, and Count to the appropriate values
llist::llist() {
	Front = NULL;
	Rear = NULL;
	Count = 0;
}

//destructor
//while not empty calls deleteFront and prints out a command letting the user know
llist::~llist() {
	int x;
	if (!isEmpty()) {
		cout << "Calling the llist destructor" << endl;
		while (!isEmpty()) {
			deleteFront(x);
		}
	}
}

//checks if list is empty
bool llist::isEmpty() {
	if (Front != NULL && Rear != NULL && Count != 0) {
		return false;
	}
}
//if list is empty, displays empty
//creates a pointer that displays all the elems starting at the front
void llist::displayAll() {
	if (isEmpty()) {
		cout << "Empty" << endl;
	}
	else {
		Node* display = new Node;
			display = Front;
		do {
			cout << display->Elem;
			display = display->Next;
		} while (display != NULL);
		cout << endl;
	}
}

//adds a new node and adds it to the rear. If its the first node, points front and rear to that single node
void llist::addRear(el_t NewNum) {
	Node* x = new Node;
	x->Elem = NewNum;
	x->Next = NULL;
	
	if (Count == 0) {
		Front = x;
	}
	else {
		Rear->Next = x;
	}
	Rear = x;
	Count++;
	
}

//creates a new node and inserts it at the front of the list
//if first node, points front and rear to that node
void llist::addFront(el_t NewNum) {
	Node* x = new Node;
	x->Elem = NewNum;
	x->Next = NULL;
	if (Count == 0) {
		Front = x;
		Rear = x;
	}
	else if (Count == 1) {
		Front = x;
		Front->Next = Rear;
	}
	else {
		x->Next = Front;
		Front = x;
	}
	Count++;
}

//if isEmpty, throws underflow
//if has one node, prints the content of that node and then deletes it
//if has multiple nodes, prints the contents of front, then deletes front and moves pointer to the next node
void llist::deleteFront(el_t& OldNum) {
	if (isEmpty()) {
		throw Underflow();
	}
	else if (Count == 1) {
		OldNum = Front->Elem;
		cout << OldNum << endl;
		Front = Rear = NULL;
		Count--;
	} else {
		Node* temp = new Node;
		temp = Front->Next;
		OldNum = Front->Elem;
		cout << OldNum << endl;
		delete Front;
		Front = temp;
		Count--;
	}
}
//if empty, throws Underflow
//if one node, prints the content of the node then deletes
//prints the content of the rear node then deletes the final node and moves rear pointer to new rear
void llist::deleteRear(el_t& OldNum) {
	if (isEmpty()) {
		throw Underflow();
	}
	else if (Count == 1) {
		OldNum = Rear->Elem;
		cout << OldNum << endl;
		Front = Rear = NULL;
		Count--;
	}
	else {
		OldNum = Rear->Elem;
		Node* p = new Node;
		p = Front;
		while (p->Next != Rear) {
			p = p->Next;
		}
		cout << OldNum << endl;
		delete Rear;
		Rear = p;
		Rear->Next = NULL;
		Count--;
	}
}

// If I is an illegal value(i.e. > Count or < 1) throw OutOfRange.
//deleteFront when I is 1 or
//deleteRear when I is Count
//delete the Ith node(I starts out at 1).Count is updated.
void llist::deleteIth(int I, el_t& OldNum) {
	if (I < 1 || I > Count) {
		throw OutOfRange();
	}
	else if (isEmpty()) {
		throw Underflow();
	}
	else if (I == 1) {
		deleteFront(OldNum);
	}
	else if (I == Count) {
		deleteRear(OldNum);
	}
	else {
		//node to point to just before ith node
		Node* p = new Node;
		p = Front;
		for (int i = 1; i < I - 1; i++) {
			p = p->Next;
		}
		//q is the ith node
		Node* q = p->Next;
		OldNum = q->Elem;
		cout << OldNum << endl;
		//move pointer around ith to the ith + 1
		p->Next = q->Next;
		delete q;
		Count--;
	}
}

//If I is an illegal value(i.e. > Count + 1 or < 1) throw OutOfRange.
//addFront when I is 1 or addRear when
//I is Count + 1
//add right before the Ith node.Cout if updated.
void llist::addbeforeIth(int I, el_t newNum) {
	if (I < 1 || I > Count + 1) {
		throw OutOfRange();
	}
	else if (I == 1) {
		addFront(newNum);
	}
	else if (I == Count + 1) {
		addRear(newNum);
	}
	else {
		//node to point to just before ith node
		Node* p = new Node;
		p = Front;
		for (int i = 1; i < I - 1; i++) {
			p = p->Next;
		}
		//q is the ith node
		Node* q = new Node;
		q->Elem = newNum;
		q->Next = p->Next;
		p->Next = q;
		Count++;
		cout << "List has been updated. Added node before " << I << "th node." << endl;
	}
}

