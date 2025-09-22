#ifndef dyn_array_h
#define dyn_array_h

#include <iostream>
#include <assert.h>

template <class T> class DynArray {
public:
	DynArray();
	DynArray(unsigned int size_);
	~DynArray();
	
	DynArray(const DynArray <T>& rhs); // COPY CONSTRUCTOR
	DynArray <T>& operator=(const DynArray <T>& rhs); //ASIGNMENT OPERATOR
	unsigned int size() const;
	unsigned int push_back(const T& item);
	const T& operator[](unsigned int index) const;
	T& operator[](unsigned int index);
private:
	unsigned int size_;
	unsigned int capacity_;
	T* elements_;
};

template <class T> DynArray<T>::DynArray()
	: size_{0}, capacity_{2}, elements_{new T[2]} { 
	std::cout << "DynArray::DynArray()" << std::endl;
	// elements_ = new T[capacity_];
}
template <class T> DynArray<T>::DynArray(unsigned int size)
	: size_{size}, capacity_{(size>=1) ? size : 2} { 
	std::cout << "DynArray::DynArray(" << size << ")" << std::endl;
	// assert(size_ >= 0);
	elements_ = new T[capacity_];
}
template <class T> DynArray<T>::~DynArray() {
	std::cout << "DynArray::~DynArray()" << std::endl;
	delete[] elements_;
}
template <class T> unsigned int DynArray<T>::size() const {
	return size_;
}
template <class T> DynArray <T>:: DynArray(const DynArray <T>& rhs) : size_(rhs.size_), capacity_(rhs.capacity_) { //COPY CONSTRUCTOR
    elements_ = new T[capacity_];  // Allouer la mémoire
    for (int i = 0; i < size_; i++) {
        elements_[i] = rhs.elements_[i];  // Copier les éléments
    }
}

template <class T>	DynArray <T>& DynArray <T>::operator=(const DynArray <T>& rhs){ //ASSIGNMENT OPERATOR
	if (&rhs != this) {
		delete[] elements_;
		size_ = rhs.size_;
		capacity_ = rhs.capacity_;
		elements_ = new T[capacity_];
		for (int i = 0 ; i  < rhs.size_ ; i++ ) {
			elements_[i] = rhs.elements_[i];
		}
	}
	return *this;
}

template <class T> unsigned int DynArray<T>::push_back(const T& item) {
	std::cout << "DynArray::push_back" << std::endl;
	if(size_ == capacity_ ) {
		std::cout << "Reallocation..." << std::endl;
		capacity_ *= 2;
		T* bigger_array = new T[capacity_];
		for(int i=0; i <size_; ++i) {
			bigger_array[i] = elements_[i];
		}
		delete[] elements_;
		elements_ = bigger_array;
	}
	elements_[size_] = item;
	++size_;
	return size_ - 1;
}
template <class T> const T& DynArray<T>::operator[](unsigned int index) const {
	assert(index < size_);
	return elements_[index];
}
template <class T> T& DynArray<T>::operator[](unsigned int index) {
	assert(index < size_);
	return elements_[index];
}
#endif

