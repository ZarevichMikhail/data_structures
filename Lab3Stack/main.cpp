#include <iostream>
#include "stack.h"
#include "CircularBuffer.h"
#include "CircularBufferQueue.h"
#include "StackQueue.h"

using namespace std;
int main()
{   
    setlocale(LC_ALL, "Russian");
    std::cout << "Hello World!\n";

    // Тестирование очереди на основе двух стеков

    StackQueue queue = StackQueue(5);

    queue.Enqueue(0);
    queue.Enqueue(1);
    queue.Enqueue(2);
    queue.Enqueue(3);
    queue.PrintQueue();
    queue.Enqueue(4);
    queue.Dequeue();
    queue.PrintQueue();

    cout << "Уменьшил размер очереди до 2." << endl;
    queue.ResizeQueue(2);
    queue.PrintQueue();

    cout << queue.Dequeue();
    queue.PrintQueue();

    //queue.Dequeue();
    //queue.Enqueue(5);
    //queue.PrintQueue();

    //cout << queue.Dequeue();
    //queue.PrintQueue();

    // Тестирование очереди на основе кольцевого буфера
    //CircularBufferQueue queue = CircularBufferQueue(5);

    //queue.Enqueue(0); 
    //queue.Enqueue(1);
    //queue.Enqueue(2);
    //queue.Enqueue(3);
    //queue.Enqueue(4);
    //queue.PrintQueue();

    //queue.Dequeue();
    //queue.Dequeue();
    //queue.Dequeue();
    //queue.Enqueue(4);

    //queue.PrintQueue();

    //queue.Enqueue(5);
    //queue.PrintQueue();

    // Тестирование кольцевого буфера

    //CircularBuffer buffer = CircularBuffer(5);

    //buffer.AddElement(0);
    //buffer.AddElement(1);
    //buffer.AddElement(2);
    //buffer.AddElement(3);
    //buffer.AddElement(4);
    //buffer.GetElement();
    //buffer.GetElement();
    //buffer.AddElement(12);
    //buffer.AddElement(13);
    ////buffer.AddElement(5);
    ////buffer.AddElement(6);
    //cout << buffer.GetFreeSpace()<< " "<< buffer.GetOccupiedSpace()<< endl;
    ////



    //buffer.PrintBuffer();

    //cout << "После увеличения размера до 7" << endl;
    //buffer.ResizeCircularBuffer(7);
    //cout << buffer.GetFreeSpace() << " " << buffer.GetOccupiedSpace() << endl;
    //buffer.PrintBuffer();
    //cout << "Удалил один элемент и добавил три" << endl;
    //buffer.GetElement();
    //buffer.AddElement(5);
    //buffer.AddElement(6);
    //buffer.AddElement(7);

    //buffer.PrintBuffer();

    //cout << "После удаления трёх элементов. В буфере останется 4. " << endl;
    //buffer.GetElement();
    //buffer.GetElement();
    //buffer.GetElement();
    //buffer.PrintBuffer();
    //cout << "Уменьшение размера до 5." << endl;
    //buffer.ResizeCircularBuffer(5);
    //buffer.PrintBuffer();

    //cout << "Добавил один элемент." << endl;
    //buffer.AddElement(8);
    //buffer.PrintBuffer();

    //cout << "Уменьшение размера до 3." << endl;
    //buffer.ResizeCircularBuffer(3);
    //buffer.PrintBuffer();
    //cout << buffer.GetFreeSpace() << " " << buffer.GetOccupiedSpace() << endl;

    //

    //buffer.GetElement();
    //buffer.AddElement(11);
    //buffer.PrintBuffer();

    //std::operator<<(std::cout, "После удаления первого элемента.");
    //std::operator<<(std::cout, "\n");
    // 
    // 
    //cout << "После удаления первого элемента: " << endl;
    //buffer.GetElement();
    //
    //buffer.PrintBuffer();

    //cout << "После удаления второго элемента: " << endl;
    //buffer.GetElement();
    ////buffer.GetElement();
    //
    //buffer.PrintBuffer();

    //buffer.AddElement(5);
    //buffer.AddElement(6);
    //buffer.PrintBuffer();
    //cout << "После удаления третьего элемента: " << endl;
    //buffer.GetElement();
    //buffer.PrintBuffer();

    //buffer.AddElement(10);
    //buffer.PrintBuffer();
    
    // Тестирование стека
    

 //   Stack stack = Stack(10);

	//stack.Push(0);
 //   stack.Push(1);
 //   stack.Push(2);
 //   stack.Push(3);
 //   stack.Push(4);
 //   stack.Push(5);
 //   stack.PrintBuffer();
	//stack.ResizeStack(3);
 //   stack.PrintBuffer();
 //   stack.ResizeStack(10);
 //   stack.PrintBuffer();



}

