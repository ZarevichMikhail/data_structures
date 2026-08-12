#pragma once

#include <string>

//! \brief Класс реализующий хэш-таблицу
class HashTable{

private:


    int initial_capacity = 4;


    //! \brief Коэффициент заполнения, при котором нужно выполнять перехэширование.
    const int fill_factor = 0.75;

    //! \brief Множитель, на который нужно умножать размер нового массива при перехэшировании.
    const float growth_factor = 1.5;

    int* array;

    //! \brief Функция хэширования на основе метода Пирсона. Возвращает индекс в массиве по ключу.
    int HashFunction(int key);

    
    //! \brief Перехэширование. Изменяет размер хэш-таблицы.
    //! Создаёт массив нового размера, перехэширует все элементы.
    void ReHash(int new_capacity);

public:

    //! \brief Конструктор. Создаёт хэш-таблицу с вместимостью по умолчанию.
    HashTable();

    //! \brief Конструктор.
    //! \param capacity Вместимость хэш-таблицы.
    HashTable(int capacity);

    ~HashTable();


    //! \brief Вставляет пару ключ-значение в таблицу.
    void Insert(std::string key, std::string value);

    //! \brief Ищет значение по ключу.
    std::string Search(std::string key);

    //! \brief Удаляет значение по ключу.
    void Delete(std::string key);

};

