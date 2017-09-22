#ifndef QUEUE_NODE_H
#define QUEUE_NODE_H

#include<iostream>
#include<cstdlib>

template <class T>
class QueueNode {
	public:
		QueueNode(T item) {
			this->data = item;
		}
		T data;
		QueueNode<T>* next;
};
#endif
