// Lab3Stack.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "stack.h"

int main()
{   
    setlocale(LC_ALL, "Russian");
    std::cout << "Hello World!\n";

    Stack stack = Stack(10);

	stack.Push(0);
    stack.Push(1);
    stack.Push(2);
    stack.Push(3);
    stack.Push(4);
    stack.Push(5);
    stack.PrintBuffer();
	stack.ResizeStack(3);
    stack.PrintBuffer();
    stack.ResizeStack(10);
    stack.PrintBuffer();
    //stack.Push(5);
    //stack.PrintBuffer();
    //stack.Pop();
    //stack.PrintBuffer();


}

