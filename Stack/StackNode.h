#ifndef STACK_NODE_H
#define STACK_NODE_H

#include<iostream>
#include<cstdlib>

template <class T>
class StackNode {
	public:
		StackNode(T item) {
			this->data = item;
		}
		/*
		 * We don't need a destructor for this->next
		 * because this->next is set to a node that
		 * has already been created with new (and 
		 * deleted with delete) in the Stack.h file
		
		~StackNode() {
			delete this->next;
		}
		*/
	private:
		T data;
		StackNode<T>* next;
};
#endif
