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
	~tBinaryTree();//destructs the tree, cleaning up its data members

	void insert(const T& value);//accepts a value to be added to the binary tree
	
	//search
	bool search(const T& value, vertex& found);

private:
	std::vector<vertex*> vertices;//is a vector of pointers to vertices,
	// which should be added/removed to when vertices are created/destroyed respectively

	//parent is a reference to a POINTER to a VERTEX
	void _insertRecursive(vertex*& curParent, const T& value);

	bool searchRecursive(vertex*& curParent, const T& value, vertex& found);

	vertex* root;//is a pointer referring to the very first vertex in the tree, if any
};

template<typename T>
tBinaryTree<T>::tBinaryTree() {
	root = nullptr;
}

template<typename T>
tBinaryTree<T>::~tBinaryTree() {
	//delete all vertices
}

template<typename T>
bool tBinaryTree<T>::vertex::hasLeft() const{
	/*if (left != nullptr) {
		return true;
	}
	return false;*/
}

template<typename T>
bool tBinaryTree<T>::vertex::hasRight() const {
	/*if (right != nullptr) {
		return true;
	}
	return false;*/
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
		_insertRecursive(root->left, value);//replaces curParent with value that is to the left of current root/parent
	}
	// ok, it's greater than the current vertex, so...
	else
	{
		//repeat this function using a different parent that is on the right(because value is greater than current parent)
		_insertRecursive(root->right, value);//replaces curParent with value that is to the right of current root/parent
	}

}

template<typename T>
bool tBinaryTree<T>::search(const T& value, vertex& found) {
	searchRecursive(root, value);
}

template<typename T>
bool tBinaryTree<T>::searchRecursive(vertex*& curParent, const T& value, vertex& found) {
	if (curParent->data == value) {//if value is found
		return value;
	}
	else if (curParent->data < value) {//if target value bigger
		searchRecursive(root->right, value);
	}
	else if (curParent->data > value) {//if target value smaller
		searchRecursive(root->left, value);
	}
	else {//if value not found anywhere in tree
		std::cout << "Not Found" << std::endl;
		return value;
	}
}