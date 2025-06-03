#pragma once
#include <stdexcept>

// Шаблон класса Vect - реализация динамического массива
template <typename T>
class Vect
{
private:
	T* data;         // Указатель на массив элементов
	size_t capacity; // Выделенная память (в элементах)
	size_t size;     // Текущее количество элементов

	// Увеличение емкости массива в 2 раза
	void resize()
	{
		size_t new_capacity = (capacity == 0) ? 1 : capacity * 2;
		T* new_data = new T[new_capacity];
		// Копирование существующих элементов
		for (size_t i = 0; i < size; ++i)
		{
			new_data[i] = data[i];
		}
		delete[] data;
		data = new_data;
		capacity = new_capacity;
	}

public:
	Vect() : data(nullptr), capacity(0), size(0) {} // Конструктор по умолчанию

	~Vect()
	{ // Деструктор: освобождение памяти
		delete[] data;
	}

	// Добавление элемента в конец (при необходимости расширяет массив)
	void push_back(const T& value)
	{
		if (size >= capacity) resize();
		data[size++] = value;
	}

	// Удаление последнего элемента (бросает исключение при пустом массиве)
	void pop_back()
	{
		if (size == 0) throw std::out_of_range("Vect is empty");
		--size;
	}

	// Доступ к элементу по индексу с проверкой границ
	T& operator[](size_t index)
	{
		if (index >= size) throw std::out_of_range("Index out of range");
		return data[index];
	}

	// Константная версия оператора []
	const T& operator[](size_t index) const
	{
		if (index >= size) throw std::out_of_range("Index out of range");
		return data[index];
	}

	// Получение текущего размера
	size_t getSize() const { return size; }
};