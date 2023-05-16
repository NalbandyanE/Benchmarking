#ifndef D_LIST_H
#define D_LIST_H

template <typename T>
class List{
public:
	List() : head{nullptr}, tail{nullptr} {}
	~List();
	void push_front(const T& val);
	void push_back(const T& val);
	void pop_front();
	void pop_back();
	bool empty();
	T& front();
	T& back();
	void remove(const T& value);
	int size() const;
	void erase(int pos);
	void insert(int pos, const T& val);
	int find(const T& val);
	void printList(const List<T>& myList);
private:
	struct Node {
	    T val;
	    Node* next;
	    Node* prev;
	    Node(T x) : val{x}, next{nullptr}, prev{nullptr} {}
	};
	Node* head;
	Node* tail;
};

#include "d_list.tpp"

#endif