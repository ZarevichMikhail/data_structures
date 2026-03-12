#pragma once

#include <stdexcept>
using namespace std;


//! \brief Моя реализация стека на основе массива.
class Stack {

private:

	//! \brief Массив для хранения элементов стека.
	int* buffer_;

	//! \brief Размер стека.
	int size_;

	//! \brief Индекс последнего элемента. 
	int top_;


	

	bool IsEmpty();

public:

	Stack();
	~Stack();
	
	//! \brief Создаёт стек заданного размера.
	//! \param Размер стека.
	Stack(int size);
	

	//! \brief Выводит на экран все элементы стека.
	void PrintBuffer();

	//! \brief Добавляет элемент в конец стека.
	//! \param value Значение элемента. 
	//! \exception std::out_of_range Выбрасывается, если возникло переполнение стека.
	void Push(int value);
	

	//! \brief Удаляет последний элемент стека.
	//! \exception std::out_of_range Выбрасывается, если стек пустой.
	void Pop();


	//! \brief Возвращает значение последнего элемента стека.
	int Top();

	//! \brief Изменяет размер стека
	//! Если он больше текущего - расширяет.
	//! Если меньше - удаляет последние элементы, которые не влезают
	//! \param new_size Новый размер стека. 
	//! \exception std::out_of_range Выбрасывается, если новый размер меньше или равен нулю.
	void ResizeStack(int new_size);

};

