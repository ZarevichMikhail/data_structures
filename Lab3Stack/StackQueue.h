#pragma once
#include "stack.h"

//! \brief Реализация очереди на основе двух стеков. 
class StackQueue
{

private:
    
    Stack first_stack_;

    Stack second_stack_;

    int capacity_;

    //int initial_capacity_ = 4;


    //! \brief Передаёт все элементы из первого стека во второй. 
    void PushToSecond();



public:

    //StackQueue();

    //! \brief Конструктор.
    //! \param capacity Размер стека. 
    StackQueue(int capacity);


    //! \brief Выводит элементы буфера. 
    void PrintQueue() const;


    //! \brief Добавляет элемент в очередь. 
    //! \exception std::out_of_range Выбрасывается, если возникло переполнение очереди.
    void Enqueue(int value);


    //! \brief Получает элемент из очереди.
    //! \exception std::out_of_range Выбрасывается, если в очереди нет элементов
    int Dequeue();


    //! \brief Проверяет, не пустая ли очередь. 
    bool IsEmpty() const;


    //! \brief Возвращает количество элементов в очереди.
    int GetSize() const;

    //! \brief Изменяет размер очереди. 
    //! \param new_capacity Новая вместимость очереди. 
    void ResizeQueue(int new_capacity);


    //! \birief Удаляет очередь. 
    //void DeleteQueue();

};

