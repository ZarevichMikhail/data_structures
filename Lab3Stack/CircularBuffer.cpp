#include "CircularBuffer.h"
#include <iostream>

using namespace std;

CircularBuffer::CircularBuffer() {


	capacity_ = initial_capacity_;
	buffer_ = new int[initial_capacity_];


	size_ = 0;

	first_index_ = 0;
	index_to_add_ = 0;
	index_to_remove_ = 0;
	last_index_ = 0;

}


CircularBuffer::CircularBuffer(int capacity) {


	capacity_ = capacity;
	buffer_ = new int[capacity];

	size_ = 0;

	first_index_ = 0;
	index_to_add_ = 0;
	index_to_remove_ = 0;
	last_index_ = 0;

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


void CircularBuffer::ChangeIndex(int* index) {

	if (*(index) == size_ - 1) {

		index = 0;
	}
	else {
		index = index + 1;
	}

}


void CircularBuffer::AddElement(int value) {

	// TODO
	CheckSizeToAdd();

	buffer_[index_to_add_] = value;

	
	//index_to_add_ = index_to_add_ + 1;
	ChangeIndex(&index_to_add_);

	size_ = size_ + 1;

}


int CircularBuffer::GetElement() {

	
	CheckSizeToAdd();

	int element = buffer_[index_to_remove_];

	
	//index_to_remove_ += index_to_remove_;
	ChangeIndex(&index_to_remove_);

	size_ -= 1;

	return element;

}




