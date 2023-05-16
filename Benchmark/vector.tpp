#include "vector.h"

#include <iostream>
#include <stdexcept>

template <typename T>
Vector<T>::Vector() : s{0}, cap{4}, arr{new T[cap]} {}

template <typename T>
Vector<T>::~Vector(){
	delete[] arr;
}

template <typename T>
int Vector<T>::front(){
	return arr[0];
}

template <typename T>
int Vector<T>::back(){
	return arr[s - 1];
}

template <typename T>
T* Vector<T>::data(){
	return arr;
}

template <typename T>
T& Vector<T>::operator[](int pos){
	if(pos > s){
		throw std::out_of_range{"Index out of range"};
	}
	return arr[pos];
}

template <typename T>
T& Vector<T>::at(int pos){
	return arr[pos];
}

template <typename T>
bool Vector<T>::empty(){
	if(s == 0){
		return true;
	}
	return false;
}

template <typename T>
int Vector<T>::size(){
	return s;
}

template <typename T>
void Vector<T>::reserve(int new_cap){
	if (new_cap <= cap) {
        return;
    }
    T* new_arr = new T[new_cap];
    for (int i = 0; i < s; ++i) {
        new_arr[i] = arr[i];
    }
    delete[] arr;
    arr = new_arr;
    cap = new_cap;
}

template <typename T>
int Vector<T>::capacity() const{
	return cap;
}

template <typename T>
void Vector<T>::clear(){
	delete[] arr;
	arr = nullptr;
	s = 0;
	cap = 0;
}

template <typename T>
void Vector<T>::insert(int pos, const T& val){
	if(pos > s){
		throw std::out_of_range{"Index out of range"};
	}
	if(cap == s){
		resize(s * 2);
	}
	T* newArray = new T[s + 1];
	for(int i = 0; i < pos; ++i){
		newArray[i] = arr[i];
	}
	newArray[pos] = val;
	for(int i = pos + 1, j = pos; i < s + 1, j < s; ++i, ++j){
		newArray[i] = arr[j];
	}
	delete[] arr;
	arr = newArray;
	s = s + 1;
}

template <typename T>
void Vector<T>::erase(int pos){
	if(pos > s){
		throw std::out_of_range{"Position doesn't exist"};
	}
	for(int i = 0; i < s; ++i){
		arr[pos] = arr[pos+1];
	}
	s = s - 1;
}

template <typename T>
void Vector<T>::push_back(const T& val){
	if(cap == s){
		reserve(cap * 2);
	}
	arr[s] = val;
	s++;
}

template <typename T>
void Vector<T>::pop_back(){
	if(empty){
		throw std::out_of_range{"Vector is empty"};
	}
	--s;
}

template <typename T>
void Vector<T>::resize(int count){
	T* newArray = new T[count];
    for(int i = 0; i < s; ++i){
        newArray[i] = arr[i];
    }
    delete[] arr;
    arr = newArray;
    s = count;
}

template <typename T>
int Vector<T>::find(const T& val){
	for(int i = 0; i < size(); ++i){
		if(arr[i] == val){
			return i;
		}
	}
	return -1;
}
