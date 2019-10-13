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
	if (!isEmpty()) {
		cout << "Calling the llist destructor" << endl;
		while (!isEmpty()) {
			deleteFront();
		}
	}
}

//checks if list is empty
bool llist::isEmpty() {
	if (Front == Rear == NULL && Count == 0) {
		true;
	}
}
//if list is empty, displays empty
//creates a pointer that displays all the elems starting at the front
void llist::displayAll() {
	if (isEmpty()) {
		cout << "Empty" << endl;
	}
	else {
		Node* display = Front;
		while (display->Elem != NULL) {
			cout << display->Elem << endl;
			display = display->Next;
		}
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
2 cases :
  -Special case: if this is going to be the very first node, you must
	create a new nodeand make Frontand Rear point to it.Place NewNumand
	Count is updated.
	- Regular : adds a new node at the rearand puts NewNum in the Elem field
	of this new node.Count is updated.
  Regular case:
	  Rear->Next = new Node;
	  Rear = Rear->Next;
	  Rear->Elem = NewNum;
	  Rear->Next = NULL;

	  void llist::addFront(el_t NewNum)
		  2 cases:
  -Special case: if this is going to be the very first node, you must
	  create a new nodeand make Frontand Rear point to it.Place NewNumand
	  Count is updated.
	  - Regular : add a new node to the front of the listand
	  Count is updated.
  Regular case:
	  Node* x;
	  x = new Node;
	  x->Next = Front;
	  Front = x;
	  Front->Elem = NewNum;

	  void llist::deleteFront(el_t& OldNum)
		  3 cases:
  -Error case: if the List is empty, throw Underflow
  - Special case: if currently only one Node,
	  give back the front node element through OldNum(pass by reference) and
	  make sure both Frontand Rear become NULL.Count is updated.
	  - Regular : give back the front node element through OldNum(pass by reference)
	  and also removes the front node.Count is updated.
  Regular case:
	  OldNum = Front->Elem;
	  Node* Second;
	  Second = Front->Next;
	  delete Front;
	  Front = Second;

	  void llist::deleteRear(el_t& OldNum)
		  3 cases:
  -Error case: if empty, throw Underflow
  - Special case: if currently only one node,
	  give back the rear node element through OldNum(pass by reference) and
	  make sure both Frontand Rear become NULL.Count is updated.
	  - Regular : give back the rear node element through OldNum(pass by reference)
	  and also remove the rear node.Count is updated.
  Regular case:
	  OldNum = Rear->Elem;
	  Node* p;
	  Make p go to the one right before rear(using while)
		  delete Rear;
	  Rear = p;

	  void llist::deleteIth(int I, el_t& OldNum)
		  4 cases:
  -Error case:
	  If I is an illegal value(i.e. > Count or < 1) throw OutOfRange.
		  - Special cases : this should simply call deleteFront when I is 1 or
		  deleteRear when I is Count
		  - Regular : delete the Ith node(I starts out at 1).Count is updated.
		  < see the template loops in the notes to move 2 pointers to the right nodes;
	  and make sure you indicate the purposes of these local pointers >

		  void llist::addbeforeIth(int I, el_t newNum)
		  4 cases :
  -Error case:
	  If I is an illegal value(i.e. > Count + 1 or < 1) throw OutOfRange.
		  - Special cases : this should simply call addFront when I is 1 or addRear when
		  I is Count + 1
		  - Regular : add right before the Ith node.Cout if updated.
		  <see the template loops in the notes to move 2 pointers to the right nodes
		  and make sure you indicate the purposes of these local pointers>

