#pragma once


// !\brief Моя реализация кольцевого буффера на основе массива.
//         Кольцевой буфер работает по принципу FIFO.
class CircularBuffer {
private:

	//! \brief Массив для хранения элементов очереди.
	int* buffer_;

	//! \brief Количество элементов в очереди.
	int size_;

	//! \brief Вместимость очереди.
	int capacity_;

    //! \brief Индекс следующего элемента для добавления.
	int index_to_add_;

    //! \brief Индекс следующего элемента для удаления.
	int index_to_remove_;

	//! \brief Размер буфера по умолчанию. 
	int initial_capacity_ = 4;

    //! \brief Проверяет, что буфер не заполнен.
	void CheckSizeToAdd();

    //! \brief Проверяет, что буфер не пустой.
	void CheckSizeToRemove();

	//! \brief Увеличивает индекс на 1, 
	//!        или перебрасывает в начало, если дошёл до конца. 
	void ChangeIndex(int& index);

public:

	//! \brief Создаёт буфер с размером по умолчанию.
	CircularBuffer();


	//! \brief Создаёт буфер с заданным размером. 
	CircularBuffer(int capacity_);


    //! \brief Деструктор для освобождения памяти.
	~CircularBuffer();


    //! \brief Выводит элементы буфера. 
    void PrintBuffer() const;
	

	//! \brief Добавляет элемент в буфер. 
	void AddElement(int value);


	//! \brief Получает элемент из буфера.
	int GetElement();


	//! \brief Изменяет размер буфера. 
	void ResizeCircularBuffer(int new_capacity);
};

