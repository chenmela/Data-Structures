#include<iostream>
#include<cstdlib>
#include<assert.h>
#include"Queue.h"

int main() {
	Queue<int> * queue = new Queue<int>();
	queue->enqueue(4);
	queue->enqueue(5);

	assert(queue->peek() == 4);
	assert(queue->dequeue() == 4);
	queue->dequeue();
	
	assert(queue->isEmpty());
	delete queue;
	return 0;
}
