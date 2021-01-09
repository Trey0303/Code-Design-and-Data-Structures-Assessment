#pragma once

template <typename T>
class tVector {
	const static size_t GROWTH_FACTOR = 2;

	//pointer to array managed by the vector
	T* arr;
	//how many elements do we have
	size_t arrSize;
	//how many elements can we have
	size_t arrCapacity;

public:
	// initialize an empty vector
	tVector();

	//copy constructor
	tVector(const tVector& vec);

	//copy assignment operator
	tVector& operator=(const tVector& vec);

	// delete the vector(clean up the array)
	~tVector();

	//add elements to the vector
	void push_back(const T& value);

	//remove elements from the vector
	void pop_back();

	//retrieve an element from the vector
	T& at(size_t index);

	size_t size() const;
	size_t capacity() const;

	//returns the object at the given index
	T& operator[] (size_t index);

	void print();

	bool empty() const; //returns true if the vector contains no elements
	void resize(const T& num);//resizes the vector to contain the given number of elements
	void shrink_to_fit();//resizes the vectors capacity to match its size
	void clear();   //empties the vector (all elements are destroyed in this process)

};

template <typename T>
tVector<T>::tVector() {
	arr = new T[1];
	arrSize = 0;
	arrCapacity = 1;
}

template <typename T>
tVector<T>::~tVector() {
	delete[] arr;
}

template <typename T>
void tVector<T>::push_back(const T& value) {
	if (arrSize >= arrCapacity) {

		//updates arrCapacity
		arrCapacity = arrCapacity * GROWTH_FACTOR;
		//create new array
		T* newData = new T[arrCapacity];

		//copy everything over
		for (size_t i = 0; i < arrSize; ++i) {
			newData[i] = arr[i];
		}
		//delete old array
		delete[] arr;

		//update variables
		arr = newData;
	}

	arr[arrSize] = value;
	++arrSize;
}

template <typename T>
T& tVector<T>::at(size_t index) {
	return arr[index];
}

template <typename T>
tVector<T>::tVector(const tVector<T>& vec) {
	//            arrCapacity is used to get the whole array
	arr = new T[vec.arrCapacity];
	arrSize = vec.arrSize;
	arrCapacity = vec.arrCapacity;
	for (size_t i = 0; i < arrSize; i++) {
		arr[i] = vec.arr[i];
	}
}

template <typename T>
 tVector<T>& tVector<T>::operator = (const tVector<T> & vec) {
	 *arr = *vec.arr;
	 return *arr;
}

 template <typename T>
 void tVector<T>::pop_back() {
	 //destroy the last element
	 arr[arrSize - 1].~T();

	 //reduce size by one
	 --arrSize;
 }

 template <typename T>
 size_t tVector<T>::size()const {
	 return arrSize;
 }

 template <typename T>
 size_t tVector<T>::capacity() const {
	 return arrCapacity;
 }

 template <typename T>
 T& tVector<T>::operator[] (size_t index) {
	 if (index < arrSize) {
		return arr[index];
	 }
	 else {
		 
		 std::cout << "out of bounds"<< std::endl;
		 return arr[arrSize - 1];
		 /*for (size_t i = 0; i < arrSize; i++) {
			 if (i == arrSize) {
				 return arr[index];

			 }
			 
		 }*/
		 
	 }
 }

 template <typename T>
 void tVector<T>::print() {
	 for (size_t i = 0; i < arrSize; i++) {
		 if (i == 0) {
			std::cout << arr[i];

		 }
		 else {
			std::cout << ", " << arr[i];

		 }
	 }
	 std::cout << std::endl;
 }

template<class T> 
bool tVector<T>::empty() const {
	bool empty = false;
	if (arrSize < 1) {
		empty = true;
		std::cout << "array is empty" << std::endl;
	}
	else {
		empty = false;

		std::cout << "array is NOT empty" << std::endl;
	}
	return empty;
}

template<class T>
void tVector<T>::resize(const T& num) {
	bool fixed = false;
	while (!fixed) {
		//if array has more elements than requested
		if (num < arr) {
			fixed = false;
			//destroy the last element
			arr[arrSize - 1].~T();

			//reduce size by one
			--arrSize;
		}
		//if array has less elements than requested
		else if (num > arr) {
			if (arrSize >= arrCapacity) {

				//updates arrCapacity
				arrCapacity = arrCapacity * GROWTH_FACTOR;
				//create new array
				T* newData = new T[arrCapacity];

				//copy everything over
				for (size_t i = 0; i < arrSize; ++i) {
					newData[i] = arr[i];
				}
				//delete old array
				delete[] arr;

				//update variables
				arr = newData;
			}

			arr[arrSize] = num;
			++arrSize;
		}
		else {
			fixed = true;
		}

	}
}

template<class T>
void tVector<T>::shrink_to_fit() {
	if (arrSize < arrCapacity) {
		arrCapacity = arrSize;

		if (arrCapacity < 1) {
			arrCapacity = 1;
		}


		T* updateArr = new T[arrCapacity];

		for (size_t i = 0; i < arrSize; i++) {
			updateArr[i] = arr[i];
		}

		//delete old array
		delete[] arr;

		//update variables
		arr = updateArr;


		
	}
	else {
		std::cout << "arrSize: " << arrSize << std::endl;
		std::cout << "arrCapacity: " << arrCapacity << std::endl;
	}
}

template<class T>
void tVector<T>::clear() {
	bool empty = false;
	while (!empty) {
		if (arrSize < 1) {
			empty = true;
			//std::cout << "array is empty" << std::endl;
		}
		else {
			empty = false;
			//destroy the last element
			arr[arrSize - 1].~T();

			//reduce size by one
			--arrSize;
			//std::cout << "array is NOT empty" << std::endl;
		}

	}
	std::cout << "array is cleared" << std::endl;
}