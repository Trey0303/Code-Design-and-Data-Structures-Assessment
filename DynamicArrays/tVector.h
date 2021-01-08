#pragma once

template <typename T>
class tVector {
	const static size_t GROWTH_FACTOR = 2;

	T* arr;
	size_t arrSize;
	size_t arrCapacity;

public:
	tVector();

	tVector(const tVector& vec);

	tVecotr& operator=(const tVector& vec);

	~tVector();

	void push_back(const T& value);

	void pop_back();

	T& at(size_t index);

	size_t size() const;
	size_t capacity() const;
};

template <typename T>
tVector<T>::tVector() {
	arr = new T[0];
	arrSize = 0;
	arrCapacity = 0;
}

template <typename T>
tVector<T>::~tVector() {
	delete[] arr;
}

template <typename T>
void tVector<T>::push_back(const T& value) {
	if (arrSize >= arrCapacity) {
		T* newData = new T[arrCapacity * GROWTH_FACTOR];
		for (size_t i = 0; i < arrSize; ++i) {
			newData[i] = arr[i];
		}

		delete[] arr;

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
	arr = new T(*vec.arr);
}

template <typename T>
 tVector<T>& operator = (const tVector<T> & vec) {
	 *arr = *vec.arr;
	 return *arr;
}

 template <typename T>
 void tVector<T>::pop_back() {
	 arr[size - 1].~T();

	 --size;
 }

 template <typename T>
 size_t tVector<T>::size()const {
	 return arrSize;
 }

 template <typename T>
 size_t tVector<T>::capacity() const {
	 return arrCapacity;
 }