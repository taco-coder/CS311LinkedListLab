//INSTRUCTION
//Look for ** to complete all of them
//The output should match my assingment sheet

//=========================================================
//HW#: HW3P1 llist
//Your name: Tahwab Noori
//Complier:  g++
//File type: client program (tester)
//===========================================================

using namespace std;

#include <iostream>
#include "llist.h"

void caseOne()
{
	cout << "CASE 1:------------------- " << endl;
	llist L;   // this is my list
	int x;  // to hold a removed element

	//1 check empty and report the result  
	cout << 1 << endl;
	if (L.isEmpty()) {
		cout << "List empty" << endl;
	}
	else {
		cout << "List not empty" << endl;
	}
	//2 display the list  
	cout << 2 << endl;
	L.displayAll();
	//3 add 4 integers 1,2,3,4    
	cout << 3 << endl;
	for (int i = 1; i < 5; i++) {
		L.addRear(i);
	}
	//4 display the list  
	cout << 4 << endl;
	L.displayAll();
	//5 remove from front twice (and display the elements removed)
	cout << 5 << endl;
	for (int i = 0; i < 2; i++) {
		L.deleteFront(x);
	}
	//6 display the list
	cout << 6 << endl;
	L.displayAll();
	//7 check empty and report the result 
	cout << 7 << endl;
	if (L.isEmpty()) {
		cout << "List empty" << endl;
	}
	else {
		cout << "Not empty" << endl;
	}
	//8 remove from the rear twice (display the element removed)
	cout << 8 << endl;
	for (int i = 0; i < 2; i++) {
		L.deleteRear(x);
	}
	//9 check empty again and report the result
	cout << 9 << endl;
	if (L.isEmpty()) {
		cout << "List empty" << endl;
	}
	else {
		cout << "Not empty" << endl;
	}
}//end of case 1 

void caseTwo()
{
	cout << "Case 2: -----------------------" << endl;
	llist L2;  // another list
	int x;   // to hold the removed element 
	int c = 1;  // displayed step number

	// 1.add to front once   (element 5)
	cout << c << endl; c++;
	L2.addFront(5);
	// 2.add to front again  (element 4)
	cout << c << endl; c++;
	L2.addFront(4);
	// 3.delete Front
	cout << c << endl; c++;
	L2.deleteFront(x);
	// 4.add to rear 3 times (elements 6,8,9)
	cout << c << endl; c++;
	for (int i = 6; i < 10; i++) {
		if (i != 7) {
			L2.addRear(i);
		}
	}
	// 5. display all
	cout << c << endl; c++;
	L2.displayAll();
	// 6.add before the 1st  (element 4) . 4 5 6 8 9
	cout << c << endl; c++;
	L2.addbeforeIth(1, 4);
	// 7.add before the 4th  (element 7) . 4 5 6 7 8 9
	cout << c << endl; c++;
	L2.addbeforeIth(4, 7);
	// 8.add before the 7th  (element 10) . 4 5 6 7 8 9 10
	cout << c << endl; c++;
	L2.addbeforeIth(7, 10);
	// 9.add before the 9th  (element 12) . error (out of range)
	cout << c << endl; c++;
	try { L2.addbeforeIth(9, 12); }
	catch (llist::OutOfRange) { cout << "error: out of range" << endl; }
	// 10.add before the 0th (element 0) . error (out of range)
	cout << c << endl; c++;
	try { L2.addbeforeIth(0, 0); }
	catch (llist::OutOfRange) { cout << "error: out of range" << endl; }
	// 11.displayAll
	cout << c << endl; c++;
	L2.displayAll();
	// 12.delete Ith I==1 (indicate  the element removed) . 5 6 7 8 9 10
	cout << c << endl; c++;
	L2.deleteIth(1, x);
	// 13.delete Ith I==6 (indicate the element removed)  - 5 6 7 8 9 
	cout << c << endl; c++;
	L2.deleteIth(6, x);
	// 14.delete Ith I==3 (indicate the element removed)  - 5 6 8 9
	cout << c << endl; c++;
	L2.deleteIth(3, x);
	// 15.delete Ith I==5 . error (out of range)
	cout << c << endl; c++;
	try { L2.deleteIth(5, x); }
	catch (llist::OutOfRange) { cout << "error: out of range" << endl; }
	// 16.delete Ith I==0 . error (out of range)
	cout << c << endl; c++;
	try { L2.deleteIth(0, x); }
	catch (llist::OutOfRange) { cout << "error: out of range" << endl; }
	// 17.displayAll
	cout << c << endl; c++;
	L2.displayAll();
	// 18.delete from rear until it is empty (indicate the elements removed)
	cout << c << endl; c++;
	do {
		L2.deleteRear(x);
	} while (!L2.isEmpty());
	// 19.displayAll  
	cout << c << endl; c++;
	L2.displayAll();

}//end of case 2

void caseThree()
{
	cout << "Case 3:-------------------- " << endl;
	llist L3;
	int x;  // to hold the removed element

	// 1.add before the 0th . error (out of range)
	cout << 1 << endl;;
	try { L3.addbeforeIth(0, 3); }
	catch (llist::OutOfRange) { cout << "error: out of range" << endl; }
	//2.delete front . error (underflow)
	cout << 2 << endl;
	try { L3.deleteFront(x); }
	catch (llist::Underflow) { cout << "error: underflow" << endl; }
}   //end of case 3

void caseFour()
{
	cout << "Case 4:------------------------ " << endl;
	llist L4;
	int x;  // to hold the removed element

	//   1.delete 2nd . error (out of range)
	cout << 1 << endl;
	try { L4.deleteIth(2, x); }
	catch (llist::OutOfRange) { cout << "error: out of range" << endl; }
	//    2.delete rear . error (underflow)
	cout << 2 << endl;
	try { L4.deleteRear(x); }
	catch (llist::Underflow) { cout << "error: underflow" << endl; }
} // end of case 4


//PURPOSE of the Program: create a menu and allow user to test functionality of llist
//Algorithm/Design: 4 test cases are divided into 4 functions and run through a series of steps
int main()
{
	int selection; // this will indicate what the user wants to do

	do
	{
		cout << endl << "MENU: These are your options: " << endl << endl;
		cout << "   (1) Case 1  " << endl;
		cout << "   (2) Case 2  " << endl;
		cout << "   (3) Case 3  " << endl;
		cout << "   (4) Case 4 " << endl;
		cout << "    Enter ( 0 ) to quit " << endl;
		cout << "===>";

		cin >> selection;

		switch (selection)
		{
		case 1: caseOne(); break;
		case 2: caseTwo(); break;
		case 3: caseThree(); break;
		case 4: caseFour(); break;
		}
	} while (selection != 0);

}// end of main

