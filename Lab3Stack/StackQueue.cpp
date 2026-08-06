#include "StackQueue.h"
#include <iostream>

using namespace std;

// Неправильный вариант. 
// Сначала будет создан стек с помощью конструтора по умолчанию. 
//StackQueue::StackQueue(int capacity) {
//
//    first_stack_  = Stack(capacity);
//    second_stack_ = Stack(capacity);
//}

// Правильный вариант с помощью списка инициализации
StackQueue::StackQueue(int capacity) : first_stack_(capacity), second_stack_(capacity) {
    
    capacity_ = capacity;
    // Теперь тело конструктора может быть абсолютно пустым.
    // Стеки уже создались с нужным размером до входа сюда.
}


void StackQueue::PrintQueue() const{
    cout << "Первый стек:" << endl;
    first_stack_.PrintBuffer();
    cout << endl;
    cout << "Второй стек:" << endl;
    second_stack_.PrintBuffer();

}


void StackQueue::PushToSecond() {

    while (first_stack_.IsEmpty() == false) {
        second_stack_.Push(first_stack_.Top());
        first_stack_.Pop();
    }
}


void StackQueue::Enqueue(int value) {

    if (GetSize() >= capacity_) {
        throw std::out_of_range("Переполнение очереди.");
    }
    first_stack_.Push(value);
}


int StackQueue::Dequeue() {

    if (IsEmpty()) {
        throw std::out_of_range("Очередь пустая. Невозможно удалить элемент.");
    }


    if (second_stack_.IsEmpty()) {
        PushToSecond();
    }

    int output = second_stack_.Top();
    second_stack_.Pop();
    return output;

}


bool StackQueue::IsEmpty() const {

    return first_stack_.IsEmpty() && second_stack_.IsEmpty();
}


int StackQueue::GetSize() const {
    return first_stack_.GetSize() + second_stack_.GetSize();
}

void StackQueue::ResizeQueue(int new_capacity) {

    // Если новый размер больше или равен текущему, то расширяем оба стека
    if (new_capacity>=capacity_){
        first_stack_.ResizeStack(new_capacity);
        second_stack_.ResizeStack(new_capacity);
    
    }
    // Если новый размер меньше текущего, то нужно скопировать первые элементы, которые влезают.
    // Например если в очередь были добавлены элменты 0 1 2 3 4
    // то после уменьшения размера до 3
    // будет 0 1 2
    else if (new_capacity < capacity_) {
        

        int current_size = GetSize();
        int elements_to_copy;

        if (current_size > new_capacity) {
            elements_to_copy = new_capacity;
        }
        else {
            elements_to_copy = current_size;
        }

        // Создание временного массива, куда будут записаны элементы очереди
        // в том порядке, в котором они добавлялись. 
        int* temp_array = new int[elements_to_copy];

        for (int i = 0; i < elements_to_copy; i++) {
            temp_array[i] = Dequeue();
        }

        // Очистка очереди
        while (IsEmpty() != true) {
            Dequeue();
        }

        // Очистку можно оптимизировать
        // Dequeue() может вызвать функцию PushToSecond()
        // Вместо этого можно очищать стеки через их собственные методы Pop()
        //while (!first_stack_.IsEmpty()) {
        //    first_stack_.Pop();
        //}
        //while (!second_stack_.IsEmpty()) {
        //    second_stack_.Pop();
        //}

        // Также, поскольку стек - это массив с индексом, на который записывать
        // Можно создать метод Clear, который перезаписывает этот индекс
        //void Stack::Clear() {
        //    top_ = -1;
        //}

        // Это будет работать намного быстрее
        //first_stack_.Clear();
        //second_stack_.Clear();

        first_stack_.ResizeStack(new_capacity);
        second_stack_.ResizeStack(new_capacity);

        // Копирование первых элментов в новую очередь.
        for (int i = 0; i < elements_to_copy; i++) {
            Enqueue(temp_array[i]);
        }

        delete[] temp_array; 

    }

    capacity_ = new_capacity;

}


