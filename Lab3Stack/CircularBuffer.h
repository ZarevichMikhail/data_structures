#pragma once


// !\brief Моя реализация кольцевого буффера на основе массива.
//         Кольцевой буфер работает по принципу FIFO.
class CircularBuffer {
private:

	//! \brief Массив для хранения элементов буфера.
	int* buffer_;


	//! \brief Количество элементов в буфера.
	int size_;


	//! \brief Вместимость буфера.
	int capacity_;


    //! \brief Индекс следующего элемента для добавления.
	int index_to_add_;


    //! \brief Индекс следующего элемента для удаления.
	int index_to_remove_;


	//! \brief Размер буфера по умолчанию. 
	int initial_capacity_ = 4;


    //! \brief Проверяет, что буфер не заполнен.
    //! \exception std::out_of_range Выбрасывается, если возникло переполнение буфера.
	void CheckSizeToAdd();


    //! \brief Проверяет, что буфер не пустой.
    //! \exception std::out_of_range Выбрасывается, если буфер пустой.
    void CheckSizeToRemove();


	//! \brief Увеличивает индекс на 1, 
	//!        или перебрасывает в начало, если дошёл до конца. 
    //! param &index Ссылка на индекс. 
	void ChangeIndex(int& index);

public:

	//! \brief Создаёт буфер с размером по умолчанию.
	CircularBuffer();


	//! \brief Создаёт буфер с заданным размером. 
    //! \param capacity Размер буфера. 
	CircularBuffer(int capacity);


    //! \brief Деструктор для освобождения памяти.
	~CircularBuffer();


    //! \brief Возвращает свободное место.
    int GetFreeSpace() const;


    //! \brief Возвращает занятое место. 
    int GetOccupiedSpace() const;


    //! \brief Выводит элементы буфера. 
    void PrintBuffer() const;
	

	//! \brief Добавляет элемент в буфер. 
    //! \param value Значение элемента.
	void AddElement(int value);


	//! \brief Получает элемент из буфера.
	int GetElement();


	//! \brief Изменяет размер буфера. 
    //! \param new_capacity Новый размер буфера.
    //! \exception std::out_of_range Выбрасывается, если новый размер меньше или равен 0. 
    void ResizeCircularBuffer(int new_capacity);

    
    //! \brief Удаляет буфер и освобождает память. 
    void DeleteCircularBuffer();
};

