#include <iostream>
#include <cstdlib>
#include "a1_sequential_list.hpp"

using namespace std;

SequentialList::SequentialList(unsigned int cap)
{
    capacity_ = cap;
    data_ = new DataType[cap];
    size_ = 0;
}

SequentialList::~SequentialList()
{
    delete []data_;
    data_ = NULL;
}

unsigned int SequentialList::size() const
{
    return size_;
}

unsigned int SequentialList::capacity() const
{
    return capacity_;
}

bool SequentialList::empty() const
{
    return size_ == 0;
}

bool SequentialList::full() const
{
    return size_ == capacity_;
}

SequentialList::DataType SequentialList::select(unsigned int index) const
{
    if(index >= size_){
        return data_[size_-1];
    }
    else
    return data_[index];
}

unsigned int SequentialList::search(DataType val) const
{
    int i = 0;
    while (data_[i] != val && i < size_) {
        i++;
    }
    return i;
}

void SequentialList::print() const
{
    for (int i = 0; i < size_; i++) {
        cout << data_[i];
    }
}

bool SequentialList::insert(DataType val, unsigned int index)
{
    if (size_ >= capacity_) {
        cout << "Error: List is full." << endl;
        return false;
    }
    else if (index > size_) {
        cout << "Error: Index is out of range" << endl;
        return false;
    }
    else if(index == 0){
        return insert_front(val);
    }
    else if(index == size_){
        return insert_back(val);
    }
    else{
    for (int i = size_; i > index; i--) {
        data_[i] = data_[i-1];
    }
    data_[index] = val;
    size_++;
    
    return true;
    }
}

bool SequentialList::insert_front(DataType val)
{
    if (size_ >= capacity_) {
        cout << "Error: List is full" << endl;
        return false;
    }
    else{
    for (int i = size_; i > 0; i--) {
        data_[i] = data_[i-1];
    }
    data_[0] = val;
    size_++;
    
    return true;
    }
}

bool SequentialList::insert_back(DataType val)
{
    if (size_ >= capacity_) {
        cout << "Error: List is full" << endl;
        return false;
    }

    else {
        data_[size_] = val;
        size_++;

        return true;
    }
}

bool SequentialList::remove(unsigned int index)
{
    if(index >= size_){
        cout << "Error: Index is out of range" << endl;
        return false;
    }
    else if(index == 0){
        return remove_front();
    }
    else if(index == size_ - 1){
        return remove_back();
    }
    else{
    for (int i = index; i < size_ - 1; i++) {
        data_[i] = data_[i+1];
        data_[i+1] = 0;
    }
        size_--;
        return true;
    }
}

bool SequentialList::remove_front()
{
    if (size_ == 0) {
        cout << "Error: List is empty." << endl;
        return false;
    }
    else{
    for (int i = 0; i < size_ - 1; i++) {
        data_[i] = data_[i+1];
        data_[i+1] = 0;
    }
    size_--;
    return true;
    }
}

bool SequentialList::remove_back()
{
    if (size_ == 0) {
        cout << "Error: List is empty" << endl;
        return false;
    }
    else{
    data_[size_-1] = 0;
    size_--;
    return true;
    }
}

bool SequentialList::replace(unsigned int index, DataType val)
{
    if (index >= size_) {
        cout << "Error: Index is out of range";
        return false;
    }
    else{
        data_[index] = val;
        return true;
    }
}
