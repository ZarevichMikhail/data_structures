#include <iostream>
#include "DynamicArray.h"

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
    
    DynamicArray array = DynamicArray(4);
    
    //array.AddElement(array.GetSize(), 0);
    //array.AddElement(array.GetSize(), 1);
    //array.AddElement(array.GetSize(), 2);
    //array.AddElement(array.GetSize(), 3);
    //std::cout << array.GetSize() << array.GetCapacity() << std::endl;
    //array.AddElement(array.GetSize(), 4);
    //array.AddElement(array.GetSize(), 5);
    //std::cout << array.GetSize() << array.GetCapacity() << std::endl;

    //array.RemoveByIndex(array.GetSize()-1);
    //array.RemoveByIndex(array.GetSize()-1);
    //array.RemoveByIndex(array.GetSize()-1);
    //
    //array.PrintArray();
    //std::cout << array.GetSize() << " " << array.GetCapacity() << std::endl;
    //std::cout << array.GetElementByIndex(2) << std::endl;

    while (true)
    {

        array.PrintArray();

        cout << "Выберите действие: \n";
        cout << "1. Вставить элемент в начало массива. \n";
        cout << "2. Вставить элемент в конец массива. \n";
        cout << "3. Вставить элемент на какую-либо позицию. \n";
        cout << "4. Удалить элемент по индексу. \n";
        cout << "5. Удалить элемент по значению. \n";
        cout << "6. Заменить элемент. \n";
        cout << "7. Развернуть массив. \n";
        cout << "8. Сортировка массива.\n";
        cout << "9. Линейный поиск элемента.  \n";
        cout << "10. Бинарный поиск элемента. \n";

        int choice = GetInput("Действие: ");

        switch (choice)
        {
        case 1:
        {
            int value = GetInput("Введите значение элемента: \n");

            array.AddElement(0, value);

            break;
        }
        case 2:
        {
            int value = GetInput("Введите значение элемента: \n");

            array.AddElement(array.GetSize(), value);

            break;
        }
        case 3:
        {   
            int index = GetInput("Введите индекс: ");
            int value = GetInput("Введите значение элемента: \n");

            array.AddElement(index, value);

            break;
        }
        case 4:
        {
            int index = GetInput("Введите индекс: ");
            
            array.RemoveByIndex(index);

            break;
        }
        case 5:
        {
            int value = GetInput("Введите значение: ");

            array.RemoveByValue(value);

            break;
        }
        case 6: {

            int index = GetInput("Введите индекс: ");
            int value = GetInput("Введите значение: ");

            array.SetElement(index, value);

            break;

        }
        case 7: {

            array.ReverseArray();

            break;

        }
        case 8:
        {
            array.SortArray();

            cout << "Массив отсортирован. \n";

            break;
        }
        case 9:
        {
            int value = GetInput("Введите значение: ");
            int index = array.LinearSearch(value);
            cout << "Элемент был найден на позиции: " << index;

            break;
        }
        case 10:
        {
            int value = GetInput("Введите значение: ");
            int index = array.BinarySearch(value);

            cout << "Элемент был найден на позиции: " << index;

            break;
        }
        default:
            cout << "Неизвестная команда. \n";
        }
    }

    



}