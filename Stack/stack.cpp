#include<iostream>
#include<cstdlib>
#include<assert.h>
#include"Stack.h"

int main() {
	Stack<int>* s1 = new Stack<int>();
	s1->push(5);
	s1->push(7);

	assert(s1->pop() == 7);
	assert(s1->peek() == 5);

	s1->pop();
	assert(s1->isEmpty());
	delete s1;
	return 0;
}
