#include "DynamicArray.h"

DynamicArray::DynamicArray(int initial_capacity) {

	capacity_ = initial_capacity;
	size_ = 0;
	array_ = new int[capacity_];

}


DynamicArray::~DynamicArray() {
	delete[] array_;
}


int DynamicArray::GetSize() {

	return size_;
}


int DynamicArray::GetCapacity() {

	return capacity_;
}


int* DynamicArray::GetArray() {

	return array_;
}


void DynamicArray::PrintArray() {

	std::cout << "Текущий массив: \n";
	for (int i = 0; i < size_; i++) {

		std::cout << array_[i] << " ";
	}
	std::cout << std::endl;
}


void DynamicArray::AddElement(int index, int value) {

	
	// Логика сдвига элементов:
	// Все элементы сдвигаются (копируются) на 1 индекс вперёд
	// Новый элемент вставляется на новый индекс

	// 0 1 2 3 4 5 6 Индексы до сдвига
	// 0 1 2 3 4 5 6 Значения до сдвига
	// 
	// add(3,7)
	// 0 1 2 3 4 5 6 7 Индексы после сдвига
	// 0 1 2 3 3 4 5 6 Значения после сдвига
	// 0 1 2 7 3 4 5 6 Значения после вставки

	// Логика сдвига элементов 
	// i = size = 7 ... i = index = 3
	// array[7] = array[6]; array_[i] = array_[i - 1];
	// array[4] = array[3]

	// Присваиваем обычную функцию
	//func = CompareForGetElement;
	// Сигнатура: возвращает bool, принимает два int

	std::function<bool(int, int)> func;
	func = [&](int a, int b) { return CompareForAddElement(a, b); };
	CheckRange(size_, index, func);
	if (size_ == capacity_) {

		ResizeArray(capacity_ * kGrowthFactor);
	}
	 


	for (int i = size_; i > index; i--) {
		array_[i] = array_[i - 1];
	}

	array_[index] = value;
	size_ = size_ + 1;
}



void DynamicArray::SetElement(int index, int value) {


	std::function<bool(int, int)> func;
	func = [&](int a, int b) { return CompareForCheckIndex(a, b); };
	CheckRange(size_, index, func);

	array_[index] = value;
}



void  DynamicArray::CheckRange(int size, int index, std::function<bool(int, int)> compare_mode) {

	if (index < 0) {
		throw std::out_of_range("Индекс должен быть больше 0. ");
	}
	else if (compare_mode(size, index)) {
		throw std::out_of_range("Слишком большой индекс. ");
	}
}


bool DynamicArray::CompareForCheckIndex(int size, int index) {

	return size <= index;
}


bool DynamicArray::CompareForAddElement(int size, int index) {

	return size < index;
}


void DynamicArray::RemoveByIndex(int index) {



	// Логика элементов:
	// Все элементы сдвигаются (копируются) на 1 индекс назад
	// Новый элемент вставляется на новый индекс

	// 0 1 2 3 4 5 6 Индексы до удаления
	// 0 1 2 3 4 5 6 Значения до удаления
	// 
	// remove(3)
	// 0 1 2 3 4 5 6 Индексы после удаления
	// 0 1 2 4 5 6 6 Значения после удаления

	// Логика удаления элементов 
	// i = index = 3 ... i = index = size
	// array[3] = array[4]; array_[i] = array_[i + 1];
	// array[5] = array[6]; array_[i] = array[size-1]

	std::function<bool(int, int)> func;
	func = [&](int a, int b) { return CompareForCheckIndex(a, b); };
	CheckRange(size_, index, func);

	for (int i = index; i < size_ - 1; i++) {

		array_[i] = array_[i + 1];
	}
	size_ = size_ - 1;

	// Уменьшает capacity массива, если он стал слишком маленьким. 
	if (size_ < capacity_ / kGrowthFactor) {
		ResizeArray(capacity_ / kGrowthFactor);
	}


}


void DynamicArray::RemoveByValue(int value) {

	int index = LinearSearch(value);
	
	if (index == -1) {
		return;
	}
	else {
		
		RemoveByIndex(index);
	}
}


int DynamicArray::GetElementByIndex(int index) {

	std::function<bool(int, int)> func;
	func = [&](int a, int b) { return CompareForCheckIndex(a, b); };
	CheckRange(size_, index, func);
	return array_[index];
}


void DynamicArray::SortArray() {

	int n = size_;
	int min_index;
	int temp;
	for (int i = 0; i < n; i++) {

		min_index = i;

		for (int j = i + 1; j < n; j++) {
			
			if (array_[j] < array_[min_index]) {
				min_index = j;
			}
		}

		temp = array_[i];
		array_[i] = array_[min_index];
		array_[min_index] = temp;

	}

}


void DynamicArray::ResizeArray(int new_capacity) {


	if (new_capacity == 0) {
		new_capacity = 1;
	}

	capacity_ = new_capacity;
	int* new_array = new int[capacity_];
	for (int i = 0; i < size_; i++) {
		new_array[i] = array_[i];
	}

	// Правильный вариант
	// Данные под указателем удаляются только при delete
	// Тут происходит выделение более крупного массива,
	// Копирование в него старых данных, удаление старых данных
	// Перенос указателя на скопированные данные
	delete[] array_;
	array_ = new_array;


	// Это неправильно, будет утечка памяти. 
	// В array_ лежат старые данные
	// строчка array_ = new_array; присваиваем в array новый указатель
	// на старые данные теперь ничего не указывает, они не удалятся, а останутся в памяти
	//array_ = new_array;
	//delete[] new_array;

}


int DynamicArray::LinearSearch(int value) {

	for (int i = 0; i < size_; i++) {

		if (array_[i] == value) {
			return i;
		}
	}
	return -1;

}


int DynamicArray::BinarySearch(int value) {

	int low = 0;
	int high = size_ - 1;
	int mid_index = (low + high) / 2;

	while (low <= high) {
		mid_index = (low + high) / 2;

		if (value == array_[mid_index]) {
			return mid_index;
		}
		else if (value > array_[mid_index]) {
			low = mid_index + 1;
		}
		else {
			high = mid_index - 1;
		}
	}

	return -1;
}


void DynamicArray::ReverseArray() {

	int left;
	int right;
	
	for (int i = 0; i < (size_) / 2; i++) {

		left = GetElementByIndex(i);
		right = GetElementByIndex(size_ -1 - i);
		SetElement(i, right);
		SetElement(size_ - 1 - i, left);

		// Внутри класса у меня есть доступ к массиву array_
		// Поэтому публичные методы тут можно не использовать
		//int temp = array_[i];
		//array_[i] = array_[size_ - 1 - i];
		//array_[size_ - 1 - i] = temp;
		
		// Встроенная функция для обмена значений
		//std::swap(array_[i], array_[size_ - 1 - i]);

		// Встроенная функция для разворота массива
		//#include <algorithm>
		//std::reverse(vec.begin(), vec.end());

	}
}


