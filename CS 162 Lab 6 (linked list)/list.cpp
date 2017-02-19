//put your implementation of LinkedList class here

#include "list.h"
#include <iostream>

using namespace std;

LinkedList::LinkedList()
{
	head = NULL;
	tail = NULL;
	count = 0;
}

LinkedList::~LinkedList()
{
	Node * current = head;
	
	while (head != NULL)
	{
		current = head->next;
		delete head; //delete the node pointed to by head.
		head = current;
	}
}

bool LinkedList::add(int val) //makes an ordered list...
{
	Node * current; //pointer to traverse the list
	Node *trailCurrent; //pointer just before the current
	Node *newNode; //pointer to create a node
	bool found;

	newNode = new Node; //create a node (allocate space in memory that can hold information for datatype "Node" (ie. address of the head/tail, space for data to be inserted, address of pointers to the prev and next nodes in the list)
	newNode->data = val; //store the given val inside the node's data section.
	newNode->next = NULL; //newnode's "next" link is set to null (since we're unsorted)
	newNode->prev = NULL; //newnode's "prev" link is set to null. *IS THIS OK HERE, OR DOES IT ALWAYS ASSUME THAT THE NEW VALUE IS ALONE 

	if (head == NULL)
	{//if the val passed in is the first to be added to the list
		head = newNode; //then the newnode data replaces the null of head and tail
		tail = newNode;
		count++;
	}
	else //if it's not the first in the list
	{
		found = false;
		current = head;

		while (current != NULL && !found) //while current doesn't point to an empty node, and found is still false
		{
			if (current->data >= val) //if the current pointer points to a value that is bigger than or equal to the value we're trying to pass in
			{
				found = true; //breaks out of the "notfound" while loop.
			}
			else
			{
				trailCurrent = current; //the address just before "current" is now set to "current"
				current = current->next; //the address of current is changed to the address of the following node link.
				//this is breaking (replacing) the old links to the previously contiguous nodes and allowing the new node to be linked up between them
			}
		}
		if (current == head) //if the current node IS THE FIRST node
		{
			head->prev = newNode; //insert newNode before first
			newNode->next = head; 
			head = newNode; //update address so now head points to the correct beginning
			count++;
		}
		else
		{
			if (current != NULL) //insert newnode between trailCurrent and current
			{
				trailCurrent->next = newNode;
				newNode->prev = trailCurrent;
				newNode->next = current;
				current->prev = newNode;
			}
			else
			{
				trailCurrent->next = newNode;
				newNode->prev = trailCurrent;
				tail = newNode;
			}
			count++;
		}
	}
	return true;
}

bool LinkedList::remove(int val)
{
	Node * current; //pointer to traverse the list
	Node * trailCurrent; //pointer just before current
	bool found;

	if (head == NULL)
	{
		cout << "List is Empty" << endl;

	}
	else if (head->data == val)
	{
		current = head;
		head = head->next;
		if (head != NULL)
		{
			head->prev = NULL;
		}
		else
		{
			tail = NULL;
			
		}
		count--;
		delete current;
	}
	else
	{
		found = false;
		current = head;
		while (current != NULL && !found) //search list
		{
			if (current->data >= val)
			{
				found = true;
			}
			else
			{
				current = current->next;
			}
		}
		if (current == NULL)
		{
			cout << "Item to be deleted is not in the list. " << endl;
		}
		else if (current->data == val) //check if item being pointed at and item to be deleted are same
		{
			trailCurrent = current->prev;
			trailCurrent->next = current->next;
			if (current->next != NULL)
			{
				current->next->prev = trailCurrent;
			}
			if (current == tail)
			{
				tail = trailCurrent;
			}
			count--;
			delete current;
		}
		else
		{
			cout << "Item to be deleted is not in the list." << endl;
		}
	}
	return true;
}
	
void LinkedList::printAscending() const
{
	Node * current; //pointer to traverse the list
	current = head; //set the pointer to the first node in the list

	while (current != NULL) //while the node that current points to ISN'T empty
	{
		cout << current->data << " "; //output the value stored in data (pointed to by current)
		current = current->next; //set the new "current" pointer to the address stored in the "next" node

	}
	
}

void LinkedList::printDescending() const
{
	Node * current; //pointer to traverse the list
	current = tail; //set current to point to the last node in the list

	while (current != NULL) //while current points to an address that ISN'T empty
	{
		cout << current->data << " "; //output data stored in the address pointed to by "current"
		current = current->prev; //set the address stored in the pointer "current" to the address stored in the "prev" node
	}
}