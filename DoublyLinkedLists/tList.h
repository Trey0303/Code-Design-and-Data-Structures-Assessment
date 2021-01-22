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

	//rule of three
	tList(const tList& other);//copys list

	tList& operator=(const tList& rhs);

	~tList(); //delete all nodes

	void push_front(const T& val); //adds element to front
	void pop_front(); //removes element from front
	
	void push_back(const T& val); //adds element to back
	void pop_back(); //removes element from back

	T& front(); //returns the element at the head/front
	T& back(); //returns the element at the tail/back
};

template <typename T>
tList<T>::tList() {
	head = nullptr;
	tail = nullptr;
}

template <typename T>
tList<T>::tList(const tList& other) {
	node * cur = other.tail;//make it start at tail when making copy list
	node* curNext = nullptr;

	while (cur != nullptr) {//until there are no more nodes to copy over
		node* copyNode = new node();//create new node
		copyNode->data = cur->data;//new node will take in a number/value
		copyNode->next = curNext;//next will be set to whatever last next was(at the start it will be null)

		if (curNext != nullptr) {
			curNext->prev = copyNode;
		}

		if (tail == nullptr) {
			tail = copyNode;
		}

		if (cur->prev == nullptr) {
			copyNode->prev = nullptr;
		}

		curNext = copyNode;
		cur = cur->prev;//will advance to the next number
	}

	head = curNext;


}

template <typename T>
tList<T>& tList<T>::operator=(const tList& rhs) {
	node *other = rhs.head;//create new list
	node* prevNode = nullptr;//starts off null
	while (other != nullptr) {//until equal to tail of rhs list
		//create node to put a number from rhs in
		node* curNode = new node();//create new node

		//put rhs number into empty new node
		curNode->data = other->data;//->data is to access node inside list(put in the data)
		
		//get new node to have pointers for previous and next number/node
		//?? needs to point to next number in rhs for when it loops
		curNode->next = nullptr;//next is always null because the next number hasnt been copied over yet
		
		//will create pointer to for curNode to point to for previous number(note: prevNode should start off null)
		curNode->prev = prevNode;//create a pointer for preious number

		//when its not the first time running through this code
		if (prevNode != nullptr) {//if previous node exist
			//?? needs to point to prev number if there is one for when it loops
			prevNode->next = curNode;//set pointer for previous node to current node for so it knows what number comes after prev node

		}
		prevNode = curNode;//update previous node
		

		other = other->next;//access next node in other list

		if (other == nullptr) {
			//set a pointer for tail at the back of the list
			tail = curNode;
		}
	}

	//return new list
	return *this;
}

template <typename T>
tList<T>::~tList() {
	while (head != nullptr) {//loop until is null
		node* oldtail = tail;
		//note:if tail is null,things will break
		tail = oldtail->prev;

		if (tail != nullptr) {
			tail->next = nullptr;
		}
		else {
			head = nullptr;
		}

		delete oldtail;
	}
	/*
	delete head;
	delete tail;*/
}

template <typename T>
void tList<T>::push_front(const T& val) {
	node* newNode = new node();//created a new node

	//new node will have the data of val. 
	newNode->data = val;//whatever number that val is will be data for new node
	newNode->prev = nullptr;//prev is always nullptr
	newNode->next = head;//whatever was the head before will become the new nodes next


	//if head is not null
	if (head != nullptr) {
		head->prev = newNode;//current head points towards its prev
	}

	//prev becomes new head
	head = newNode;
	
	//if head is null
	if (tail == nullptr) {
		tail = newNode;//tail will equal newNode
	}
}

template <typename T>
void tList<T>::pop_front() {
	node* oldHead = head;//oldHead becomes head
	//note:if head is null,things will break
	head = oldHead->next;//head becomes head.next

	if (head != nullptr) {
		head->prev = nullptr;
	}
	else {
		tail = nullptr;
	}
	
	delete oldHead;
}

template <typename T>
void tList<T>::push_back(const T& val) {
	node* newNode = new node();//created a new node

	newNode->data = val;
	newNode->next = nullptr;
	newNode->prev = tail;

	if (head != nullptr) {
		tail->next = newNode;
	}

	tail = newNode;

	if (head == nullptr) {
		head = newNode;
	}
}

template <typename T>
void tList<T>::pop_back() {
	node* oldtail = tail;
	//note:if tail is null,things will break
	tail = oldtail->prev;

	if (tail != nullptr) {
		tail->next = nullptr;
	}
	else {
		head = nullptr;
	}

	delete oldtail;
}

template <typename T>
T& tList<T>::front() {//similar to back()
	return head->data;//return the head which is in the front of the list
}

template <typename T>
T& tList<T>::back() {//similar to front()
	return tail->data;//returns data stored in the back
}