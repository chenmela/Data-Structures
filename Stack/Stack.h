#ifndef STACK_H
#define STACK_H

#include<iostream>
#include<cstdlib>
#include"StackNode.h"

template <class T>
class Stack {
	public:
		struct EmptyStackException : public std::exception {
			const char * what() const throw() {
				return "Empty stack.";
			}
		};

		~Stack() {
			StackNode<T>* temp;
			for (temp = this->top; this->top != NULL; temp = this->top) {
				this->top = this->top->next;
				delete temp;
			}
		};

		T pop() {			
			if (this->isEmpty()) {
				throw EmptyStackException();
			}
			StackNode<T> * temp;
			temp = this->top;
			T item = temp->data;
			this->top = this->top->next;
			delete temp;
			return item;
		};

		T peek() {
			if (this->isEmpty()) {
				throw EmptyStackException();
			}
			return this->top->data;
		};

		void push(T item) {
			StackNode<T> * newNode = new StackNode<T>(item);
			//If first node, this->top is null
			newNode->next = this->top;
			this->top = newNode;
		};

		bool isEmpty() {
			return (this->top == NULL);
		}
	private:
		StackNode<T> * top;
};
#endif
