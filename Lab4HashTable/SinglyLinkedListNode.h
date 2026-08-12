#pragma once

#include <string>

//! \brief Структура, представляющая узел односвязного списка.
struct Node {

	//! \brief Данные, которые хранит узел. 
	std::string data_;


	//! \brief Указатель на следующий узел.
	Node* next_;


	//! \brief Конструктор.
	//!	Создаёт узел с заданным значением.
	//! Указатель на следующий узел устанавливается в nullptr.
	//! \param initial_data Значение, которое будет хранить узел.
	Node(std::string initial_data);

	~Node();

};