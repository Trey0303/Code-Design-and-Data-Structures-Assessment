#pragma once

template<typename T>
class tList {
	struct node {
		T data; //data for the element stored
		node* prev; //pointer to the previous node
		node* next; //pointer to the next node
	};

	node* head; //pointer to the head of linked list
	node* tail; //pointer to tail of linked list

public:
	tList(); //initializes head and tail to null
	~tList(); //delete all nodes

	void push_front(const T& val); //adds element to front
	//void pop_front(); //removes element from front
	
	//void push_back(const T& val); //adds element to back
	//void pop_back(); //removes element from back

	//T& front(); //returns the element at the head/front
	//T& back(); //returns the element at the tail/back
};

template <typename T>
tList<T>::tList() {
	//arr = new T[1];
	head = nullptr;
	tail = nullptr;
}

template <typename T>
tList<T>::~tList() {
	//delete[] data;
}

template <typename T>
void tList<T>::push_front(const T& val) {
	node* newNode = new node();//created a new node

	//new node will have the data of val. 
	newNode->data = val;//whatever number that val is will be data for new node
	newNode->prev = nullptr;//prev is always nullptr
	newNode->prev = head;

	head = newNode;

	if (head != nullptr) {
		head->prev = newNode;
	}

	if (tail == nullptr) {
		tail = newNode;
	}
}

//template <typename T>
//void tList<T>::pop_front() {
//
//}
//
//template <typename T>
//void tList<T>::push_back(const T& val) {
//
//}
//
//template <typename T>
//void tList<T>::pop_back() {
//
//}
//
//template <typename T>
//T& tList<T>::front() {
//
//}
//
//template <typename T>
//T& tList<T>::back() {
//
//}