#ifndef TREE_H
#define TREE_H

#include<iostream>
#include<cstdlib>
#include<vector>

template <class T>
class Tree {
	private:
		template <class U>
		class TreeNode {
			public:
				TreeNode(U item) {
					this->data = item;
					left = NULL;
					right = NULL;
					parent = NULL;
				}
				T data;
				TreeNode<U>* left;
				TreeNode<U>* right;
				TreeNode<U>* parent;
		};
		TreeNode<T> * root;
	public:
		Tree() {
			this->root = NULL;
		};
		Tree(const Tree& oldtree) {
			std::vector<T> vals;
			this->preOrderTraversal(oldtree.root, vals);
			if (oldtree.root == NULL) this->root = NULL;
			this->root = new TreeNode<T>(vals[0]);
			for (int i = 1; i < vals.size(); i++) {
				this->insert(vals[i]);
			}	
		};
		~Tree() {

		};
		bool isEmpty() {
			return (this->root == NULL);
		};
		bool insert(T item) {
			TreeNode<T> * newNode = new TreeNode<T>(item);
			if (this->isEmpty()) {
				this->root = newNode;
				return true;
			}
			return insert(newNode, this->root);
		};
		bool insert(TreeNode<T>* newNode, TreeNode<T>* currentNode) {
			TreeNode<T> * curr = currentNode;
			if (newNode->data > curr->data) {
				if (curr->right == NULL) {
					curr->right = newNode;
					newNode->parent = curr;
					return true;
				}
				insert(newNode, curr->right);
			}
			else {
				if (curr->left == NULL) {
					curr->left = newNode;
					newNode->parent = curr;
					return true;
				}
				insert(newNode, curr->left);
			}
			return false;
		};
		void printTraversal(std::string name) {
			if (name == "IO") {
				this->inOrderTraversal(this->root);
			}	
			if (name == "PO") {
				postOrderTraversal(this->root);
			}
			if (name == "PR") {
				preOrderTraversal(this->root);
			}
		};
		void postOrderTraversal(TreeNode<T> * node) {
			if (node != NULL) {
				postOrderTraversal(node->left);
				postOrderTraversal(node->right);
				std::cout << node->data << std::endl;
			}
		}
		void inOrderTraversal(TreeNode<T> * node) {
			if (node != NULL) {
				inOrderTraversal(node->left);
				std::cout << node->data << std::endl;
				inOrderTraversal(node->right);
			}
		};
		void preOrderTraversal(TreeNode<T> * node, std::vector vals) {
			if (node != NULL) {
				std::cout << node->data << std::endl;
				vals.push_back(node->data);
				preOrderTraversal(node->left);
				preOrderTraversal(node->right);
			}
		};
};

#endif
