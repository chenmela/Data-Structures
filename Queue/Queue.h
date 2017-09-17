#include<cstdlib>

template <class T>
class Queue {
	public:
		~Queue();
		void enqueue(T item) {
			QueueNode<T> * newNode = new QueueNode(item);
			if (this->isEmpty()) {
				top = newNode;
				bottom = newNode->next;
			}

		};
		T dequeue();
		T peek();
		bool isEmpty();
	private:
		QueueNode<T> * top;
		QueueNode<T> * bottom;
}
