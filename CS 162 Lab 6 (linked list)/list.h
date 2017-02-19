#ifndef LIST_H
#define LIST_H

#include <iostream>
using namespace std;

class LinkedList
{
public:
	LinkedList();
	~LinkedList();
	bool add(int val);
	bool remove(int val);
	void printAscending() const;
	void printDescending() const;

private:
	struct Node
	{
		int data;
		Node * next;
		Node * prev;
	};
	Node * head, *tail;
	int count; //ok to add a count variable here?

};


#endif
