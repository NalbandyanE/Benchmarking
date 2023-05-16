#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>

template <typename T>
class Vector{
public:
	Vector();
	~Vector();
	int front();
	int back();
	T* data();
	T& operator[](int pos);
	T& at(int pos);
	bool empty();
	int size();
	void reserve(int new_cap);
	int capacity() const;
	void clear();
	void insert(int pos, const T& val);
	void erase(int pos);
	void push_back(const T& val);
	void pop_back();
	void resize(int count);
	int find(const T& val);
private:
	int s;
	int cap;
	T* arr;
};

#include "vector.tpp"

#endif  // VECTOR_H