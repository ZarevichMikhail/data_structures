
#include <iostream>
#include "DoublyLinkedList.h"
#include <vector>

#include <limits>
#include <string>

using namespace std;

int GetInput(const string& prompt)
{
    int value;
    string input;

    // Цикл для ввода правильного значения. 
    // Если введено правильное значение, возвращает его
    // иначе выводить ошибку и просит снова ввести
    while (true)
    {
        cout << prompt;
        getline(cin, input);

        try
        {
            // stoi преобразует строку в целое число. 
            value = stoi(input);
            return value;
        }
        // Возникает, когда введено не число. 
        catch (const invalid_argument& e)
        {
            cout << "Invalid input. Please enter an integer value.\n";
        }
        // int занимает 4 байта 
        // если число слишком длинное, возникает эта ошибка
        catch (const out_of_range& e)
        {
            cout << "Input is out of range. Please enter a valid integer value.\n";
        }
    }
}




int main()
{   

    setlocale(LC_ALL, "Russian");

    DoublyLinkedList list = DoublyLinkedList();

    // Тестирование
    //list.AddElement(0, 6);
    //list.AddElement(1, 5);
    //list.PrintList();

    //list.AddElement(2, 4);
    //list.AddElement(3, 3);
    //list.AddElement(4, 2);
    //list.AddElement(5, 1);
    //list.PrintList(); 
    //// 5 0 6 1 2 4
    //list.Sort();
    //list.PrintList();

    // Конструктор копирования пока не сделал. 
    //DoublyLinkedList list2 = list;
    //list.RemoveByValue(5);
    //list.RemoveByValue(4);
    //list.RemoveByValue(1);
    //list.PrintList();


    //cout << "После удаления элемента по индексу 0" << endl;
    //list.RemoveByIndex(0);
    //list.PrintList();
    //cout << "После удаления элемента по индексу 2" << endl;
    //list.RemoveByIndex(2);
    //list.PrintList();

    //cout << "После удаления последнего элемента" << endl;
    //list.RemoveByIndex(list.GetSize()-1);
    //list.PrintList();



    while (true)
    {

        list.PrintList();

        cout << "Выберите действие: \n";
        cout << "1. Вставить элемент в начало списка. \n";
        cout << "2. Вставить элемент в конец списка. \n";
        cout << "3. Вставить элемент на какую-либо позицию. \n";
        cout << "4. Удалить элемент по индексу. \n";
        cout << "5. Удалить элемент по значению. \n";
        cout << "6. Заменить элемент. \n";
        cout << "7. Сортировка списка.\n";
        cout << "8. Линейный поиск элемента.  \n";


        int choice = GetInput("Действие: ");

        switch (choice)
        {
        case 1:
        {
            int value = GetInput("Введите значение элемента: \n");

            list.AddElement(0, value);

            break;
        }
        case 2:
        {
            int value = GetInput("Введите значение элемента: \n");

            list.AddElement(list.GetSize(), value);

            break;
        }
        case 3:
        {
            int index = GetInput("Введите индекс: ");
            int value = GetInput("Введите значение элемента: \n");

            list.AddElement(index, value);

            break;
        }
        case 4:
        {
            int index = GetInput("Введите индекс: ");

            list.RemoveByIndex(index);

            break;
        }
        case 5:
        {
            int value = GetInput("Введите значение: ");

            list.RemoveByValue(value);

            break;
        }
        case 6: {

            int index = GetInput("Введите индекс: ");
            int value = GetInput("Введите значение: ");

            list.SetElement(index, value);
            break;

        }
        case 7:
        {
            list.Sort();

            cout << "Список отсортирован. \n";

            break;
        }
        case 8:
        {
            int value = GetInput("Введите значение: ");
            int index = list.LinearSearch(value);
            cout << "Элемент был найден на позиции: " << index << endl;

            break;
        }

        default:
            cout << "Неизвестная команда. \n";
        }
    }





}

