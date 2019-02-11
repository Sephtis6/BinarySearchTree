#pragma once
#include <iostream>
using namespace std;

//template used
template <typename T>
struct Node
{
	//data in this node
	T data;
	//pointer to left subtree
	Node<T>* left;
	//pointer to right subtree
	Node<T>* right;
	//pointer to parent
	Node<T>* parent;
};
//template used
template <typename T>
class BST
{
	//prvate data used
private:
	//nodes for the begining
	Node<T>* parent;
	Node<T>* root;
public:
	//constrcutor of the bst
	BST()
	{
		//sets the root of the bst
		root = nullptr;
	}
	//insert data into the bst
	void insert(T new_data)
	{
		//if no root exists
		if (root == nullptr)
		{
			//set root to a new node with the input data
			root = new Node<T>{ new_data, nullptr, nullptr, nullptr };
			return;
		}
		//set the node currently on to the root so can go through the bst to find where it goes
		Node<T>* onCurrentNode = root;
		while (onCurrentNode != nullptr)
		{
			//if a node exists with the data to insert return without making a new node
			if (onCurrentNode->data == new_data)
			{
				return;
			}
			//otherwise if the new data to input is less then the current node go left on the tree
			if (new_data < onCurrentNode->data)
			{
				//when there is nothing on the left to compare to create a new node conataining the inserted data
				if (onCurrentNode->left == nullptr)
				{
					onCurrentNode->left = new Node<T>{ new_data,nullptr,nullptr, onCurrentNode };
					return;
				}
				//set the current node to the left node in order to allow to compare till node is inserted and a data match found
				onCurrentNode = onCurrentNode->left;
			}
			//otherwise if the new data to input is greater then the current node go right on the tree
			else
			{
				//when there is nothing on the right to compare to create a new node conataining the inserted data
				if (onCurrentNode->right == nullptr)
				{
					onCurrentNode->right = new Node<T>{ new_data,nullptr,nullptr, onCurrentNode };
					return;
				}
				//set the current node to the right node in order to allow to compare till node is inserted and a data match found
				onCurrentNode = onCurrentNode->right;
			}
		}
	}

	void del(T new_data)
	{
		//set the node currently on to the root so can go through the bst to find where the data to delete is
		//goes through the find function for the new data and puts it as onCurrentNode
		Node<T>* onCurrentNode = find(new_data);
		//if node is nullptr pointer displays data not found
		if (onCurrentNode == nullptr)
		{
			cout << "Data not found" << endl;
			return;
		}
		//if the node is the root node and it's left and right child are nullptr sets the root to
		//nullptr and then deletes the node
		if (onCurrentNode == root && onCurrentNode->right == nullptr && onCurrentNode->left == nullptr)
		{
			root = nullptr;
			delete onCurrentNode;
		}
		//otherwise if the node has no children it finds out if it is it's parents
		//left or right pointer and then sets that pointer to nullptr
		//then deletes that node
		else if (onCurrentNode->right == nullptr && onCurrentNode->left == nullptr)
		{
			if (onCurrentNode->parent->right == onCurrentNode)
			{
				onCurrentNode->parent->right = nullptr;
			}
			else if (onCurrentNode->parent->left == onCurrentNode)
			{
				onCurrentNode->parent->left = nullptr;
			}
			delete onCurrentNode;
		}
		//if it has only one child it finds out whether it is the left or right child of it's parent
		//then it goes through and sets it's parents pointer to itself to point to it's child instead
		//while also setting it's child parent pointer to it's parent pointer
		//then it deletes the node to delete
		else if (onCurrentNode->right != nullptr || onCurrentNode->left != nullptr)
		{
			if (onCurrentNode->parent->left == onCurrentNode)
			{
				if (onCurrentNode->right != nullptr)
				{
					onCurrentNode->parent->left = onCurrentNode->right;
					onCurrentNode->right->parent = onCurrentNode->parent;
				}
				else if (onCurrentNode->left != nullptr)
				{
					onCurrentNode->parent->left = onCurrentNode->left;
					onCurrentNode->left->parent = onCurrentNode->parent;
				}
				delete onCurrentNode;
			}
			else if (onCurrentNode->parent->right == onCurrentNode)
			{
				if (onCurrentNode->right != nullptr)
				{
					onCurrentNode->parent->right = onCurrentNode->right;
					onCurrentNode->right->parent = onCurrentNode->parent;
				}
				else if (onCurrentNode->left != nullptr)
				{
					onCurrentNode->parent->right = onCurrentNode->left;
					onCurrentNode->left->parent = onCurrentNode->parent;
				}
				delete onCurrentNode;
			}
			//otherwise if it has two children it runs through the findMax function to find the largest left most node
			//the it takes that node and sees if it has a child
			//if it does it sets that to be the right child of the parent node and sets the child parent node to the pointer parent
			//then if it has no child it sets the parent right pointer to null
			//after that it takes the larest nodes and and has the node to deletes data become the same as the largest data
			//then you delete the largest node that you just left free floating
			else if (onCurrentNode->right != nullptr && onCurrentNode->left != nullptr)
			{
				Node<T>* temp = findMax(onCurrentNode->left);
				if (temp->left != nullptr)
				{
					temp->parent->right = temp->left;
					temp->left->parent = temp->parent;
					temp->left = nullptr;
				}
				else
				{
					temp->parent->right = nullptr;
				}

				onCurrentNode->data = temp->data;
				delete temp;
			}
			return;
		}
		return;
	}
	//find the node with data that matches the input data
	Node<T>* find(T new_data)
	{
		//create a root node if no nodes in tree
		if (root == nullptr)
		{
			cout << "No List to search in" << endl;
			return nullptr;
		}
		//set the node currently on to the root so can go through the bst to find the inseted data
		Node<T>* onCurrentNode = root;
		while (onCurrentNode != nullptr)
		{
			//if data found to exist return the current node
			if (onCurrentNode->data == new_data)
			{
				return onCurrentNode;
			}
			//otehrwise if data is less then the current node's data go to the left node for another comparison of data
			if (new_data < onCurrentNode->data)
			{
				//set current node to left node for further comparisons
				onCurrentNode = onCurrentNode->left;
			}
			//otherwise if data is greater then current node's data go to the right node for another comparison of data
			else
			{
				//set current node to right node for further comparisons
				onCurrentNode = onCurrentNode->right;
			}
		}

	}

	//return the node that has the highest value
	Node<T>* findMax(Node<T>* temp)
	{
		//current node is set to root
		Node<T>* onCurrentNode = temp;
		while (onCurrentNode != nullptr)
		{
			//if there if no right node return the current node it is one
			if (onCurrentNode->right == nullptr)
			{
				return onCurrentNode;
			}
			//otherwise set the right node to the current node and do another check till there is no more right nodes to go through
			onCurrentNode = onCurrentNode->right;
		}
	}
	//void to run through findMax using the root node as the node inserted
	Node<T>* findMax2()
	{
		if (root == nullptr)
		{
			cout << "No list to search in" << endl;
			return nullptr;
		}
		Node<T>* temp = findMax(root);
		cout << "The max node in the list is: " << temp->data << endl;
		return temp;
	}

	void display(Node<T>* temp2)
	{
		//uses a recursive loop in order to show the entire list from smallest to largest
		if (temp2->left != nullptr)
		{
			display(temp2->left);
		}
		cout << temp2->data << " ";
		if (temp2->right != nullptr)
		{
			display(temp2->right);
		}
	}
	void display2()
	{
		//lookes to see if there is a list to display
		if (root == nullptr)
		{
			cout << "There is no list to display" << endl;
		}
		else
		{
			//goes through the display function using root as the node to start from
			display(root);
			//displays when the list is completely displayed
			cout << endl << "All nodes in list shown" << endl;
		}
	}
};