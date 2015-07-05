#include "a1_doubly_linked_list.hpp"
#include <iostream>
#include <cstdlib>

using namespace std;

DoublyLinkedList::Node::Node(DataType data)
{
    value = data;
    next = NULL;
    prev = NULL;
}

DoublyLinkedList::DoublyLinkedList()
{
    head_ = NULL;
    tail_ = NULL;
    size_ = 0;
}

DoublyLinkedList::~DoublyLinkedList()
{
    while (head_) {
        Node* nodeptr= head_;
        head_ = head_->next;
        delete nodeptr;
    }
}

unsigned int DoublyLinkedList::size() const
{
    return size_;
}

unsigned int DoublyLinkedList::capacity() const
{
    return CAPACITY;
}

bool DoublyLinkedList::empty() const
{
    return head_ == NULL;
}

bool DoublyLinkedList::full() const
{
    return size_>= CAPACITY;
}

DoublyLinkedList::DataType DoublyLinkedList::select(unsigned int index) const
{
    Node* nodeptr;
    nodeptr = head_;
    int i = 0;
    
    while (i < index && nodeptr -> next != NULL) {
        nodeptr = nodeptr -> next;
        i++;
    }
    return nodeptr -> value;
}

unsigned int DoublyLinkedList::search(DataType value) const
{
    Node* nodeptr;
    nodeptr = head_;
    int i = 0;
    
    while (nodeptr -> value != value && nodeptr -> next != NULL) {
        nodeptr = nodeptr -> next;
        i++;
    }
    if (nodeptr -> next == NULL) {
        return i+1;
    }
    else
    return i;
}

void DoublyLinkedList::print() const
{
    Node* nodeptr;
    
    while (nodeptr -> next != NULL) {
        cout << nodeptr -> value;
    }
}

DoublyLinkedList::Node* DoublyLinkedList::getNode(unsigned int index) const
{
    int i = 0;
    Node* nodeptr = head_;
    
    while (i < index && nodeptr -> next != NULL) {
        nodeptr = nodeptr -> next;
        i++;
    }
    return nodeptr;
}

bool DoublyLinkedList::insert(DataType value, unsigned int index)
{
    if (size_ >= CAPACITY) {
        cout << "Error: list is full" << endl;
        return false;
    }
    else if (index > size_) {
        cout << "Error: Index out of range" << endl;
        return false;
    }
    else if(index == 0){
        return insert_front(value);
    }
    else if(index == size_){
        return insert_back(value);
    }
    else{
        Node* nodeptr = getNode(index - 1);
        Node* tempnode = new Node(value);
        tempnode -> next = nodeptr -> next;
        tempnode -> next -> prev = tempnode;
        tempnode -> prev = nodeptr;
        nodeptr -> next = tempnode;
        
        size_++;
        
        return true;
    }
}

bool DoublyLinkedList::insert_front(DataType value)
{
    if (size_ >= CAPACITY) {
        cout << "Error: list is full" << endl;
        return false;
    }
    else{
        Node* nodeptr = new Node(value);
        if (head_ != NULL) {
            nodeptr -> next = head_;
            nodeptr -> prev = NULL;
            head_ -> prev = nodeptr;
        }
        
        head_ = nodeptr;
        
        if (size_ == 0) {
            tail_ = head_;
        }
        
        size_++;
        
        return true;
    }

}

bool DoublyLinkedList::insert_back(DataType value)
{
    if (size_ >= CAPACITY) {
        cout << "Error: List is full" << endl;
        return false;
    }
    else if(size_ == 0) {
        return insert_front(value);
    }
    else {
        Node* nodeptr = new Node(value);
        nodeptr -> prev = tail_;
        nodeptr -> next = NULL;
        tail_ -> next = nodeptr;
        tail_ = nodeptr;
    
        size_++;
        return true;
    }
}

bool DoublyLinkedList::remove(unsigned int index)
{
    if (index >= size_) {
        cout << "Error: Index out of range" << endl;
        return false;
    }
    else if(index == 0){
        return remove_front();
    }
    else if(index == size_ -1){
        return remove_back();
        }
    else{
        Node* nodeptr = getNode(index);
        nodeptr -> prev -> next = nodeptr -> next;
        nodeptr -> next -> prev = nodeptr -> prev;
        delete nodeptr;
        
        size_--;
        return true;
    }
}

bool DoublyLinkedList::remove_front()
{
    if (head_ == NULL) {
        cout << "Error: list is empty" << endl;
        return false;
    }
    else if(size_ == 1){
        delete head_;
        head_ = NULL;
        tail_ = NULL;
        size_--;
        return true;
    }
    else{
        Node* nodeptr = head_ -> next;
        delete head_;
        head_ = nodeptr;
        head_ -> prev = NULL;
        size_--;
        return true;
    }
}

bool DoublyLinkedList::remove_back()
{
    if (head_ == NULL) {
        cout << "Error: list is empty" << endl;
        return false;
    }
    else if(size_ == 1){
        return remove_front();
    }
    else{
        Node* nodeptr = tail_ -> prev;
        delete tail_;
        tail_ = nodeptr;
        tail_ -> next = NULL;
        size_--;
        return true;
    }
}

bool DoublyLinkedList::replace(unsigned int index, DataType value)
{
    Node* nodeptr;
    if (index >= size_) {
        cout << "Error: Index out of range" << endl;
        return false;
    }
    else{
        nodeptr = getNode(index);
        nodeptr -> value = value;
        return true;
    }
}

