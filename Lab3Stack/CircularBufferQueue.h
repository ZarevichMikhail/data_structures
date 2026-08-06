#pragma once

#include "CircularBuffer.h"

//! \brief Моя реализация очереди на основе кольцевого буфера.
class CircularBufferQueue
{

private:


    //! \brief Очередь.
    CircularBuffer queue;


    //! \brief Размер буфера по умолчанию. 
    int initial_capacity_ = 4;



public:

    //! \brief Создаёт очередь с размером по умолчанию. 
    CircularBufferQueue();

    //! \brief Создаёт очередь с заданным размером. 
    CircularBufferQueue(int capacity);


    //! \brief Выводит элементы буфера. 
    void PrintQueue() const;


    //! \brief Добавляет элемент в очередь. 
    void Enqueue(int value);


    //! \brief Получает элемент из очереди.
    int Dequeue();


    //! \brief Проверяет, не пустая ли очередь. 
    bool IsEmpty();


    //! \brief Изменяет размер очереди. 
    //! \param new_capacity Новая вместимость очереди. 
    void ResizeQueue(int new_capacity);


    //! \birief Удаляет очередь. 
    void DeleteQueue();
};

