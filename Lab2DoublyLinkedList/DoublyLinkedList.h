#pragma once
#include <iostream>
#include <functional>
#include "Node.h"


//! \brief Класс, представляющий двусвязный список.
class DoublyLinkedList {

private:

	//! \brief Указатель на первый узел списка.
	Node* head_;


	//! \brief Указатель на последний узел списка.
	Node* tail_;


	//! \brief Количество элементов в списке.
	int size_;


	//! \brief Проверяет, находится ли индекс внутри массива. Если нет, выбрасывает исключение.
	//! \param size Размер массива.
	//! \param index Индекс для вставки элемента.
	//! \param compare_mode Режим сравнения. Если для проверки наличия индекса в массиве - то size<=index. 
	//!						Если для вставки, то size<index.
	//! \exception std::out_of_range Выбрасывается, не прошло нужное сравнение
	void CheckRange(int size, int index, std::function<bool(int, int)> compare_mode);


	//! \brief Проверяет, находится ли индекс внутри массива. Если нет, выбрасывает исключение.
	//! \param size Размер массива.
	//! \param index Индекс для вставки элемента.
	//! \exception std::out_of_range Выбрасывается, если size<=index. Т.к. это будет выход за границы массива.  
	bool CompareForCheckIndex(int size, int index);
	 
	//! \brief Проверяет, находится ли индекс внутри массива. Если нет, выбрасывает исключение.
	//! \param size Размер массива.
	//! \param index Индекс для вставки элемента.
	//! \exception std::out_of_range Выбрасывается, если size<index. Т.к. вставлять элемент можно в конец массива, за его границу.   
	bool CompareForAddElement(int size, int index);


	//! \brief Удаляет узел из списка.
	//! \param node_to_delete Указатель на узел, который нужно удалить.
	void DeleteNode(Node* node_to_delete);


	//! \brief Меняет местами два соседних узла.
	//! \param left Левый узел.
	//! \param right Правый узел. 
	void SwapNeighborNodes(Node* left, Node* right);

public:
	

	//! \brief Конструктор.
    //!		   Создаёт список с пустыми head и tail и размером 0.
	DoublyLinkedList();
	~DoublyLinkedList();

	Node* GetHead() const;
	Node* GetTail() const;
	int GetSize() const;


	//! \brief Выводит элементы списка.
	void PrintList() const;
	 

	//! \brief Добавляет элемент в массив.
	//! \param index Индекс массива, на который нужно поставить элемент.
	//! \param value Значение элемента.
	void AddElement(int index, int value);


	//! \brief Заменяет значение элемента массива.
	//! \param index Индекс массива, значение которого нужно поменять.
	//! \param value Новое значение.
	void SetElement(int index, int value);


	//! \brief Удаляет элемент на заданном индексе.
	//! \param index Индекс элемента, который нужно удалить.
	void RemoveByIndex(int index);


	//! \brief Удаляет первое вхождение заданного элемента.
	//! \param value Значение элемента, который нужно удалить.
	void RemoveByValue(int value);


	//! \brief Получает элемент на заданном индексе.
	//! \param index Индекс элемента, значение которого нужно получить.
	//! \return Указатель на узел с данным индексом. 
    Node* GetElementByIndex(int index);
     

	//! \brief Сортирует массив методом гномьей сортировки.
	void Sort();


	//! \brief Линейный поиск в отсортированном массиве. 
	//! \param value Значение элемента, который нужно получить.
	//! \return Индекс найденного элемента или -1 если его нет. 
	int LinearSearch(int value);


};

	