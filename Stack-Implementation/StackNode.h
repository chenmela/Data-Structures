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

		~StackNode() {
			delete this->data;
		}
		T data;
		StackNode<T>* next;
};
#endif
