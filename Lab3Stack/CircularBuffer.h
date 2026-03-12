#pragma once


// !\brief Моя реализация кольцевого буффера на основе массива.
// Кольцевой буфер работает по принципу LIFO.
class CircularBuffer {
private:

	//! \brief Массив для хранения элементов очереди.
	int* buffer_;

	//! \brief Количество элементов в очереди.
	int size_;

	//! \brief Вместимость очереди.
	int capacity_;

	//! \brief Индекс первого добавленного элемента . 
	int first_index_;

	int index_to_add_;
	int index_to_remove_;

	
	//! \brief Индекс последнего добавленного элемента
	int last_index_;


	//! \brief Размер буфера по умолчанию. 
	int initial_capacity_ = 4;


	void CheckSizeToAdd();
	void CheckSizeToRemove();


	//! \brief Увеличивает индекс на 1, 
	//! или перебрасывает в начало, если дошёл до конца. 
	void ChangeIndex(int* index);

	void ChangeAddIndex();
	void ChangeRemoveIndex();


public:

	//! \brief Создаёт буфер с размером по умолчанию.
	CircularBuffer();


	//! \brief Создаёт буфер с заданным размером. 
	CircularBuffer(int capacity_);


	~CircularBuffer();

	
	//! \brief Добавляет элемент в буфер. 
	void AddElement(int value);


	//! \brief Получает элемент из буфера.
	int GetElement();


	//! \brief Изменяет размер буфера. 
	void ResizeCircularBuffer();






};

