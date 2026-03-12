#pragma once

#include <iostream>
#include <stdexcept>
#include <functional>

class DynamicArray {

private:

	//! \brief Размер массива.
	int size_;


	//! \brief Вместимость массива.
	int capacity_;


	//! \brief Массив.
	int* array_;


	//! \brief Фактор роста массива.
	const int kGrowthFactor = 2;


	//! \brief Изменяет вместимость массива когда он полностью заполнен.
	//! \param new_capacity Новая вместимость массива. 
	void ResizeArray(int new_capacity);


	//! \biref Проверяет, находится ли индекс внутри массива. Если нет, выбрасывает исключение.
	//! \param index Индекс для вставки элемента.
	//! \param index Размер массива.
	//! \param compare_mode Режим сравнения. Если для проверки наличия индекса в массиве - то size<=index. 
	//!						Если для вставки, то size<index.
	//! \exception std::out_of_range Выбрасывается, если не прошло нужное сравнение.
	void CheckRange(int size, int index, std::function<bool(int, int)> compare_mode);
	//void CheckRange(int size, int index, bool allow_size_index);


	//Для вставки в конец массива и для остальных операций нужна разная проверка CheckRange.
	//Если нужно вставить в конец, то значение index = size является правильным, так как этот элемент следует за последним.
	//Но, например, при удалении, мы не можем обратиться к элементу по индексу size, так как его ещё нет. 
	//Можно это исправить путём использования std::function. Он позволяет использовать функции как объекты первого класса.
	//Это аналог делегатов из C#.
	//В нашем случае это означает, что, в зависимости от того, где была вызвана функция CheckRange, мы будем передавать в неё разные функции сравнения. 

	// Про std::function я узнал перед третьим курсом, то есть когда шёл этот предмет я ещё о нём не знал. 
	// Так что, для простоты, можно просто добавить переменную флаг, а не это. 


	//! \biref Проверяет, находится ли индекс внутри массива. Если нет, выбрасывает исключение.
	//! \param index Индекс для вставки элемента.
	//! \param index Размер массива.
	//! \exception std::out_of_range Выбрасывается, если size<=index. Т.к. это будет выход за границы массива.  
	bool CompareForCheckIndex(int size, int index);

	//! \biref Проверяет, находится ли индекс внутри массива. Если нет, выбрасывает исключение.
	//! \param index Индекс для вставки элемента.
	//! \param index Размер массива.
	//! \exception std::out_of_range Выбрасывается, если size<index. Т.к. вставлять элемент можно в конец массива, за его границу.   
	bool CompareForAddElement(int size, int index);


public:

	//! \brief Создаёт массив с заданным начальным размером.
	//! \param initial_capacity Начальная вместимость массива. 
	DynamicArray(int initial_capacity);
	~DynamicArray();


	int GetSize();
	int GetCapacity();
	int* GetArray();
	void PrintArray();


	//! \brief Добавляет элемент в массив.
	//! \param index Индекс массива, на который нужно поставить элемент.
	//! \param value Значение элемента.
	void AddElement(int index, int value);

	
	//! \brief Заменяет значение элемента массива.
	//! \param index Индекс массива, значение которого нужно поменять.
	//! \param value Новое значение.
	void SetElement(int index, int value);


	//! \brief Удаляет элемент на заданном индексе.
	//! \param index Индекс элемента, который нужно удалить.
	void RemoveByIndex(int index);


	//! \brief Удаляет первое вхождение заданного элемента.
	//! \param value Значение элемента, который нужно удалить.
	void RemoveByValue(int value);


	//! \brief Получает элемент на заданном индексе.
	//! \param index Индекс элемента, значение которого нужно получить.
	//! \return Значение элемента с данным индексом. 
	int GetElementByIndex(int index);


	//! \brief Сортирует массив методом сортировки выбором.
	void SortArray();


	//! \brief Линейный поиск в отсортированном массиве. 
	//! \param value Значение элемента, который нужно получить.
	//! \return Индекс найденного элемента или -1 если его нет. 
	int LinearSearch(int value);


	//! \brief Бинарный поиск в отсортированном массиве. 
	//! \param value Значение элемента, который нужно получить.
	//! \return Индекс найденного элемента или -1 если его нет. 
	int BinarySearch(int value);
	

	//! \brief Разворачивает элементы массива
	void ReverseArray();

};