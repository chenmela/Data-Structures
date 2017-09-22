#include<iostream>
#include<cstdlib>
#include"Tree.h"

int main() {
	Tree<int> * tree = new Tree<int>();
	tree->insert(5);
	tree->insert(3);
	tree->insert(7);
	tree->insert(1);
	tree->insert(4);
	tree->insert(6);
	tree->insert(8);

	tree->printTraversal("IO");
	tree->printTraversal("PO");
	tree->printTraversal("PR");
	
	
	Tree<int>* tree2 = new Tree<int>(*tree);
	std::cout << "Tree 2 traversals" << std::endl;

	tree2->printTraversal("IO");
	tree2->printTraversal("PO");
	tree2->printTraversal("PR");
	return 0;
}
