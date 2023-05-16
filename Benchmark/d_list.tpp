#include "d_list.h"
#include <stdexcept>

template <typename T>
List<T>::~List(){
	while(head){
		Node* tmp = head;
		head = head->next;
		delete tmp;
	}
}

template <typename T>
void List<T>::push_front(const T& val){
	Node* new_node = new Node(val);
	new_node->next = head;
	head = new_node;
	if(!tail){
		tail = head;
	}
}

template <typename T>
void List<T>::push_back(const T& val){
	Node* new_node = new Node(val);
	if(!tail){
		tail = new_node;
		head = tail;
	}
	else{
		tail->next = new_node;
		tail = new_node;
	}
}

template <typename T>
void List<T>::pop_front(){
	if(!head){
		return;
	}
	Node* tmp = head;
	head = head->next;
	if(!head){
		tail = nullptr;
	}
	delete tmp;
}

template <typename T>
void List<T>::pop_back(){
	if(!head){
		return;
	}
	if(head == tail){
		delete head;
		head = nullptr;
		tail = nullptr;
		return; 
	}
	Node* tmp = head;
	while(tmp->next != tail){
		tmp = tmp->next;
	}
	delete tail;
	tail = tmp;
	tail->next = nullptr;
}

template <typename T>
bool List<T>::empty(){
	if(head == nullptr){
		return true;
	}
	return false;
}

template <typename T>
T& List<T>::front(){
	return head->val;
}

template <typename T>
T& List<T>::back(){
	return tail->val;
}

template <typename T>
void List<T>::remove(const T& value){
	if(head == nullptr) {
        return;
    }
    if(head->val == value) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }
    Node* curr = head;
    while(curr->next != nullptr && curr->next->val != value) {
        curr = curr->next;
    }
    if(curr->next == nullptr) {
        return;
    }
    Node* temp = curr->next;
    curr->next = temp->next;
    delete temp;
}

template <typename T>
int List<T>::size() const{
	int count = 0;
	Node* current = head;
	while(current != nullptr){
		count++;
		current = current->next;
	}
	return count;
}

template <typename T>
void List<T>::erase(int pos){
	if(empty()){
		throw std::out_of_range{"List is empty"};
	} 
	if(pos < 0 || pos >= size()){
		throw std::out_of_range{"Index out of range"};
	}
	if(pos == 0){
		pop_front();
	}
	Node* current = head;
    Node* previous = nullptr;
    int count = 0;
    
    while (count < pos) {
        previous = current;
        current = current->next;
        count++;
    }
    
    previous->next = current->next;
    
    if (current == tail) {
        tail = previous;
    } else {
        current->next->prev = previous;
    }
    
    delete current;
}

template <typename T>
void List<T>::insert(int pos, const T& val){
	if (pos < 0 || pos > size()) {
        throw std::out_of_range{"Invalid position"};
    }
    
    if (pos == 0) {
        push_front(val);  
        return;
    }
    
    Node* current = head;
    Node* previous = nullptr;
    int count = 0;
    
    while (count < pos) {
        previous = current;
        current = current->next;
        count++;
    }
    
    Node* new_node = new Node(val);
    new_node->next = current;
    new_node->prev = previous;
    
    previous->next = new_node;
    
    if (current != nullptr) {
        current->prev = new_node;
    } else {
        tail = new_node;  
    }
}

template <typename T>
int List<T>::find(const T& val){
	Node* current = head;
    int index = 0;
    while (current != nullptr) {
        if (current->val == val) {
            return index;
        }
        current = current->next;
        index++;
    }
    return -1;
}

template <typename T>
void List<T>::printList(const List<T>& myList) {
    typename List<T>::Node* current = myList.head;

    while (current != nullptr) {
        std::cout << current->val << " ";
        current = current->next;
    }

    std::cout << std::endl;
}