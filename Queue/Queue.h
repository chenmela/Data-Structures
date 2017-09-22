#ifndef QUEUE_H
#define QUEUE_H

#include<iostream>
#include<cstdlib>
#include"QueueNode.h"

template <class T>
class Queue {
	public:
		struct EmptyQueueException : public std::exception {
			const char * what() const throw() {
				return "Empty queue.";
			}
		};

		~Queue() {
			QueueNode<T> * temp;
			for (temp = this->top; this->top != NULL; temp = this->top) {
				this->top = this->top->next;
				delete temp;
			}
			delete this->bottom;	
		};

		T dequeue() {			
			if (this->isEmpty()) {
				throw EmptyQueueException();
			}
			QueueNode<T> * temp = this->top;
			T item = temp->data;
			this->top = this->top->next;
			delete temp;
			if (this->isEmpty()) {
				this->bottom = NULL;
			}
			return item;
		};

		T peek() {
			if (this->isEmpty()) {
				throw EmptyQueueException();
			}
			return this->top->data;
		};

		void enqueue(T item) {
			QueueNode<T> * newNode = new QueueNode<T>(item);
			if (this->isEmpty()) {
				this->top = newNode;
			}
			else {
				this->bottom->next = newNode;
			}
			this->bottom = newNode;
		};

		bool isEmpty() {
			return (this->top == NULL);
		}
	private:
		QueueNode<T> * top = NULL;
		QueueNode<T> * bottom = NULL;
};
#endif
