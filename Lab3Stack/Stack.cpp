#include <iostream>
#include <stdexcept>
#include "Stack.h"

using namespace std;


Stack::Stack(int size) {
	if (size <= 0) {
		throw out_of_range("Размер стека должен быть больше нуля.");
	}

	size_ = size;
	buffer_ = new int[size_];
	top_ = -1;
}


Stack::~Stack() {
	delete[] buffer_;
}


bool Stack::IsEmpty() const {
    return top_ == -1;
}


int Stack::GetSize() const {
    return top_ + 1;
}


void Stack::Push(int value) {
	if (top_ >= size_ - 1) {
		throw out_of_range("Переполнение стека.");
	}

	top_ = top_ + 1;
	buffer_[top_] = value;
}


void Stack::Pop() {
	if (IsEmpty() == true) {
		throw out_of_range("Стек пустой.");
	}

	top_ = top_ - 1;
}


int Stack::Top() const {
	if (IsEmpty() == true) {
		throw out_of_range("Стек пустой.");
	}

	return buffer_[top_];
}


void Stack::ResizeStack(int new_size) {
	if (new_size <= 0) {
		throw out_of_range("Новый размер стека должен быть больше нуля.");
	}
	
	int* new_buffer = new int[new_size];

	// Если новый размер больше текущего количества элементов, то копируем все элементы.
	if (top_ <= new_size-1){
		for (int i = 0; i <top_+1; i++) {
			new_buffer[i] = buffer_[i];
		}
	}
	// Если новый размер меньше текущего количества элементов, то копируем те, которые влезают.
	else {
		for (int i = 0; i < new_size; i++) {
			new_buffer[i] = buffer_[i];
		}
		top_ = new_size - 1;
	}

	size_ = new_size;
	delete[] buffer_;
	buffer_ = new_buffer;
}


void Stack::PrintBuffer() const {

    if (IsEmpty() == true) {
        cout << "Стек пустой." << endl;
        return;
    }

	cout << "Элементы стека: \n";
	for (int i = 0; i < top_+1; i++) {

		cout << buffer_[i] << " ";
	}

	cout << endl;
	cout << "Последний элемент стека: \n";
	cout << Top() << endl;
}