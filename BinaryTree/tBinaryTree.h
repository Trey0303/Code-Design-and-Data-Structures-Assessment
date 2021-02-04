#pragma once

#include <vector>

template<typename T>
class tBinaryTree {
public:
	struct vertex {
		//data stored in this vertex
		T data;//holds the value stored by each vertex

		//left connection
		vertex* left;//points to the child node to its left, or null if there is no child

		//right connection
		vertex* right;//points to the child node to its right, or null if there is no child

		bool hasLeft() const;//a helper function, should return true if a child is present, otherwise false
		bool hasRight() const;//a helper function, should return true if a child is present, otherwise false


		vertex();//a default constructor that initializes its data members
	};

	tBinaryTree();//constructs the tree and initializes its data members

	//Rule of three
	tBinaryTree(const tBinaryTree& other);//copy constructor(can make a copy of something)

	// example: lista = listb
	tBinaryTree& operator=(const tBinaryTree& rhs);//copy assignment operator(overwrites data something with data of another thing)

	//destructs the tree, cleaning up its data members
	~tBinaryTree();//destructor(deletes data)

	void insert(const T& value);//accepts a value to be added to the binary tree
	
	//search                           Now is a reference to a pointer
	//bool search(const T& value, vertex& *found);


	//pre
	void printPreOrder();

	//post
	void printPostOrder();

	//in Order
	void printInOrder();

private:
	std::vector<vertex*> vertices;//is a vector of pointers to vertices,
	// which should be added/removed to when vertices are created/destroyed respectively

	//parent is a reference to a POINTER to a VERTEX
	void _insertRecursive(vertex*& curParent, const T& value);

	//bool searchRecursive(vertex*& curParent, const T& value, vertex& *found, bool valFound);

	void clearTree(vertex*& curParent);

	void tBinaryTreeRecursive(vertex*& curParent, const tBinaryTree& other);

	tBinaryTree& copyAssignmentRecursive(vertex*& curParent, const tBinaryTree& other);

	//pre
	void printPreOrderR(vertex*& curParent);

	//post
	void printPostOrderR(vertex*& curParent);

	//in Order
	void printInOrderR(vertex*& curParent);

	vertex* root;//is a pointer referring to the very first vertex in the tree, if any
};

template<typename T>
tBinaryTree<T>::tBinaryTree() {
	root = nullptr;
}

//copys tree
template<typename T>
tBinaryTree<T>::tBinaryTree(const tBinaryTree& other) {//other is original tree/list

	root = other.root;//set root to the root of the tree getting copied

	tBinaryTreeRecursive(root, other);

	vertices = other.vertices;//set vertices to the size/number of vertices getting copied from the original

}

template<typename T>
void tBinaryTree<T>::tBinaryTreeRecursive(vertex*& curParent, const tBinaryTree& other) {
	

	if (curParent != nullptr) {
		vertex* copyNode = new vertex();//create new empty node
		copyNode->data = curParent->data;//copy current node into empty node

		//if (curParent->left != nullptr) {
		tBinaryTreeRecursive(curParent->left, other);
		//}
		//if (curParent->right != nullptr) {
		tBinaryTreeRecursive(curParent->right, other);
		//}

	}

}

//overwrites tree
template<typename T>
tBinaryTree<T>& tBinaryTree<T>::operator=(const tBinaryTree& rhs) {
	
	//delete old data
	while (root != nullptr) {//while tree not clear
		clearTree(root);

	}

	//overwrite with new data
	root = rhs.root;//set root to the root of the tree getting copied

	copyAssignmentRecursive(root, rhs);
	
	//update vertices
	vertices = rhs.vertices;//set vertices to the size/number of vertices getting copied from the original


	return *this;
}

template<typename T>
tBinaryTree<T>& tBinaryTree<T>::copyAssignmentRecursive(vertex*& curParent, const tBinaryTree& other) {



	if (curParent != nullptr) {
		vertex* copyNode = new vertex();//create new empty node
		copyNode->data = curParent->data;//copy current node into empty node

		//if (curParent->left != nullptr) {
		copyAssignmentRecursive(curParent->left, other);
		//}
		//if (curParent->right != nullptr) {
		copyAssignmentRecursive(curParent->right, other);
		//}

	}

	return *this;

}


//deletes tree
template<typename T>
tBinaryTree<T>::~tBinaryTree() {
	//delete all vertices
	while (root != nullptr) {//while tree not clear
		clearTree(root);
		
	}
	std::cout << "cleared" << std::endl;
}


template<typename T>
void tBinaryTree<T>::clearTree(vertex*& curParent) {
	if (curParent->left != nullptr) {//node to the left is not empty
		clearTree(curParent->left);
	}
	else if (curParent->right != nullptr) {//node to the right is not empty
		clearTree(curParent->right);
	}
	else if (curParent != nullptr) {//if right and left of curParent are both null and root isnt
		curParent = nullptr;
		delete curParent;//delete root
		//after deleted curParent
		//will check while loop to see if there are still nodes left
		//if there are then it will start this function again from the beginning
	}
}


template<typename T>
bool tBinaryTree<T>::vertex::hasLeft() const{
	if (left != nullptr) {
		return true;
	}
	return false;
}

template<typename T>
bool tBinaryTree<T>::vertex::hasRight() const {
	if (right != nullptr) {
		return true;
	}
	return false;
}

template<typename T>
tBinaryTree<T>::vertex::vertex() {
	left = nullptr;//initialise as null by default
	right = nullptr;//initialise as null by default
	data = T();//initialise default
}

template<typename T>
void tBinaryTree<T>::insert(const T& value) {
	_insertRecursive(root, value);
}

template<typename T>
void tBinaryTree<T>::_insertRecursive(vertex*& curParent, const T& value) {

	// is there a value?
	if (curParent == nullptr)//is it empty? if it is empty
	{
		//insert value here
		curParent = new vertex();//creates a new vertex/node
		curParent->data = value;//add value to curParent data
		vertices.push_back(curParent);//uses curParents data to adds value to tree/list
	}

	// is the value the same as what we're trying to insert?
	// is this a duplicate?
	else if (curParent->data == value)
	{
		// duplicate - don't bother
	}
	// is our value less than the current vertex?
	else if (value < curParent->data)
	{
		//repeat this function using a different parent that is on the left(because value is less than current parent)
		_insertRecursive(curParent->left, value);//replaces curParent with value that is to the left of current root/parent
	}
	// ok, it's greater than the current vertex, so...
	else
	{
		//repeat this function using a different parent that is on the right(because value is greater than current parent)
		_insertRecursive(curParent->right, value);//replaces curParent with value that is to the right of current root/parent
	}

}

//template<typename T>
//bool tBinaryTree<T>::search(const T& value, vertex& *found) {
//	bool valFound = false;
//	searchRecursive(root, value, found, valFound);
//	return valFound;
//}

//template<typename T>
//bool tBinaryTree<T>::searchRecursive(vertex*& curParent, const T& value, vertex& *found, bool valFound) {
//	if (curParent != nullptr) {
//		if (curParent->data == value) {//if value is found
//			//found = curParent->data;//makes found a copy of vertex value?
//			valFound = true;
//			std::cout << "true" << std::endl;
//			return valFound;//return true
//		}
//		else if (curParent->data < value) {//if target value bigger
//			searchRecursive(curParent->right, value, found, valFound);//recall function with updated root
//		}
//		else if (curParent->data > value) {//if target value smaller
//			searchRecursive(curParent->left, value, found, valFound);//recall function with updated root
//		}
//
//	}
//	else {//if value not found anywhere in tree
//		std::cout << "false" << std::endl;
//		valFound = false;
//		return valFound;//return false
//		
//	}
//}

template<typename T>
void tBinaryTree<T>::printPreOrder() {
	if (root != nullptr) {
		printPreOrderR(root);
	}

	std::cout << std::endl;
}
template<typename T>
void tBinaryTree<T>::printPreOrderR(vertex*& curParent) {
	
	
	std::cout << curParent->data << ", ";
	
	if (curParent->left != nullptr) {
		printPreOrderR(curParent->left);
	}

	if (curParent->right != nullptr) {
		printPreOrderR(curParent->right);
	}
}

template<typename T>
void tBinaryTree<T>::printPostOrder() {
	if (root != nullptr) {
		printPostOrderR(root);
	}

	std::cout << std::endl;
}

template<typename T>
void tBinaryTree<T>::printPostOrderR(vertex*& curParent) {
	
	if (curParent->left != nullptr) {
		printPostOrderR(curParent->left);
	}
	if (curParent->right != nullptr) {
		printPostOrderR(curParent->right);
	}
	std::cout << curParent->data << ", ";//print only when currnt root is not null


}

template<typename T>
void tBinaryTree<T>::printInOrder() {
	if (root != nullptr) {
		printInOrderR(root);
	}

	std::cout << std::endl;
}

template<typename T>
void tBinaryTree<T>::printInOrderR(vertex*& curParent) {
	if (curParent->left != nullptr) {
		printInOrderR(curParent->left);
	}
	std::cout << curParent->data << ", ";

	if (curParent->right != nullptr) {
		printInOrderR(curParent->right);
	}

}
