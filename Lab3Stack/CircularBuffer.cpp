#include "CircularBuffer.h"
#include <iostream>
#include <stdexcept>

using namespace std;


CircularBuffer::CircularBuffer() {
	capacity_ = initial_capacity_;
	buffer_ = new int[initial_capacity_];

	size_ = 0;

	index_to_add_ = 0;
	index_to_remove_ = 0;
}


CircularBuffer::CircularBuffer(int capacity) {
	capacity_ = capacity;
	buffer_ = new int[capacity];

	size_ = 0;

	index_to_add_ = 0;
	index_to_remove_ = 0;
}


CircularBuffer::~CircularBuffer() {
    delete[] buffer_;
}


void CircularBuffer::PrintBuffer() const{


    if (size_ == 0) {
        cout << "Буфер пустой." << endl;
        return;
    }


    

    //cout << "Элементы буфера: " << endl;
    for (int i = 0; i < size_; i++) {

        int current_index = (index_to_remove_ + i) % capacity_;
        cout <<current_index << " ";
    }
    cout << " - Индексы массива. ";
    cout << endl;
    for (int i = 0; i < size_; i++) {

        int current_index = (index_to_remove_ + i) % capacity_;
        cout << buffer_[current_index] << " ";
    }
    cout << " - Элементы буфера ";

    //if (index_to_remove_ >= index_to_add_) {
    //    for (int i = index_to_remove_; i < index_to_add_; i++)
    //        cout << buffer_[i] << " ";
    //}
    //else {
    //    for (int i = index_to_add_; i < index_to_remove_; i++)
    //        cout << buffer_[i] << " ";

    //}
    //if (index_to_add_ >= index_to_remove_) {
    //    for(int i = index_to_remove_; i< index_to_add_; i++)
    //        cout << buffer_[i] << " ";
    //}
    //else {
    //    for (int i = index_to_add_; i < index_to_remove_; i++)
    //        cout << buffer_[i] << " ";

    //}

    cout << endl;
}


void CircularBuffer::CheckSizeToAdd() {
	if (size_ == capacity_) {
		throw out_of_range("Переполнение буфера.");
	}
}


void CircularBuffer::CheckSizeToRemove() {
	if (size_ == 0) {
		throw out_of_range("В буфере нет элементов.");
	}
}


void CircularBuffer::ChangeIndex(int& index) {
	if (index  == capacity_ - 1) {
		index = 0;
	}
	else {
		index = index + 1;
	}
}


void CircularBuffer::AddElement(int value) {

	CheckSizeToAdd();

	buffer_[index_to_add_] = value;

	ChangeIndex(index_to_add_);

	size_ = size_ + 1;
}


int CircularBuffer::GetElement() {	
	CheckSizeToRemove();

	int element = buffer_[index_to_remove_];
	
	ChangeIndex(index_to_remove_);

	size_ -= 1;

	return element;
}


void CircularBuffer::ResizeCircularBuffer(int new_capacity) {

    if (new_capacity <= 0) {
        throw out_of_range("Новый размер буфера должен быть больше нуля.");
    }


    int* new_buffer = new int[new_capacity];

    // Если новый буфер больше старого, 
    // можно копировать все элементы в правильном порядке.
    if (new_capacity > capacity_) {
        for (int i = 0; i < size_; i++) {
            int index_to_copy = (index_to_remove_ + i) % capacity_;
            new_buffer[i] = buffer_[index_to_copy];
        }

        
        index_to_add_ = size_;
        index_to_remove_ = 0;
    }
    // Если новый буфер меньше старого,
    // Можно копировать только те элементы, которые влезут. 
    else {
        
        // Количество элементов в буфере может быть либо меньше, 
        // либо больше нового размера. 
        // Нужно посчитать, сколько элементов нужно скопировать.
        int elements_to_copy;
        if (size_ < new_capacity) {
            elements_to_copy = size_;
            index_to_add_ = elements_to_copy;
        }
        else {
            elements_to_copy = new_capacity;
            size_ = new_capacity;
            index_to_add_ = 0;
        }

        for (int i = 0; i < elements_to_copy; i++) {
            int index_to_copy = (index_to_remove_ + i) % capacity_;
            new_buffer[i] = buffer_[index_to_copy];
        }

        //index_to_add_ = elements_to_copy - 1;
        index_to_remove_ = 0;
    }

    capacity_ = new_capacity;
    delete[] buffer_;
    buffer_ = new_buffer;
}


