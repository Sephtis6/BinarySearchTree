// BST.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "BST.h"
#include <iostream>

using namespace std;
void DisplayUserCommands();
void Test();

//main function that the program runs off of
int main()
{
	//stores the data to be used and creates a new list for the user
	int number;
	int treeData;
	BST <int> binaryTree;
	//welcomes the user
	cout << "Welcome to the BST assignment" << endl;
	//checkpoint that can be returnes to
start:
	//calling a function to display the list of user commands
	DisplayUserCommands();
	//get's the user's choice and does something based on it
	cout << "Please enter a number: " << endl;
	cin >> number;
	//does something based on the number the user picks
	switch (number)
	{
		//clears the system of outputs and then loads a function based on the number picked
	case 1:
		system("CLS");
		cout << "Please enter a number to add to the list" << endl;
		cin >> treeData;
		binaryTree.insert(treeData);
		goto start;
		break;
	case 2:
		system("CLS");
		cout << "Please enter what data you want to find on the BST" << endl;
		cin >> treeData;
		binaryTree.find(treeData);
		goto start;
		break;
	case 3:
		system("CLS");
		cout << "Please enter what data on the BST you want to delete" << endl;
		cin >> treeData;
		binaryTree.del(treeData);
		goto start;
		break;
	case 4:
		system("CLS");
		cout << "Finding the max node in the BST" << endl;
		binaryTree.findMax2();
		goto start;
		break;
	case 5:
		system("CLS");
		cout << "Running the automated testing function" << endl;
		Test();
		goto start;
		break;
	case 6:
		system("CLS");
		cout << "Displaying all nodes in the BST" << endl;
		binaryTree.display2();
		goto start;
		break;
	case 7:
		system("CLS");
		return 0;
		break;
	default:
		cout << "You chose an unavailable option. Program will close soon." << endl;
		break;
	}

	system("pause");
	return 0;
}
// funtion to display the list of user commands
void DisplayUserCommands() {
	cout << "List of choices:" << endl;
	cout << "1 Insert data to the BST" << endl;
	cout << "2 Search for a specific set of data froom the BST" << endl;
	cout << "3 Delete a set of data from the BST" << endl;
	cout << "4 Find the max node in the BST" << endl;
	cout << "5 Run the premade automated test" << endl;
	cout << "6 Display the list from least to greatest" << endl;
	cout << "7 Exit out of the program" << endl;
}
//test void that goes through the functions of the list and diplays the results at vaious points in the process
void Test()
{
	BST <int> testTree;
	//add delete/find with no list
	testTree.findMax2();
	testTree.del(100);
	testTree.display2();
	testTree.insert(25);
	testTree.insert(50);
	testTree.insert(90);
	testTree.insert(40);
	testTree.insert(15);
	testTree.insert(10);
	testTree.insert(20);
	cout << "Displaying complete list" << endl;
	testTree.display2();
	cout << "Adding new max node" << endl;
	testTree.insert(100);
	testTree.findMax2();
	cout << "Deleting max data" << endl;
	testTree.del(100);
	testTree.findMax2();
	testTree.display2();

	system("Pause");
}
