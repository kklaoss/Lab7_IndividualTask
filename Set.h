#pragma once
#include "vect.h"
#include <stdexcept>

// Шаблон класса Set - множество уникальных элементов с сортировкой
template <typename T>
class Set
{
private:
	Vect<T> elements; // Хранилище элементов

	// Бинарный поиск элемента
	bool contains(const T& value) const
	{
		size_t left = 0;
		size_t right = elements.getSize();
		while (left < right)
		{
			size_t mid = left + (right - left) / 2;
			if (elements[mid] == value) return true;
			if (elements[mid] < value) left = mid + 1;
			else right = mid;
		}
		return false;
	}

public:
	// Вставка элемента с сохранением порядка сортировки
	void insert(const T& value)
	{
		if (contains(value))
		{ // Проверка на дубликат
			throw std::invalid_argument("Element already exists");
		}

		// Линейный поиск позиции для вставки
		size_t pos = elements.getSize();
		for (size_t i = 0; i < elements.getSize(); ++i)
		{
			if (elements[i] > value)
			{
				pos = i;
				break;
			}
		}

		// Вставка со сдвигом элементов
		elements.push_back(value); // Добавляем временно в конец
		for (size_t i = elements.getSize() - 1; i > pos; --i)
		{
			elements[i] = elements[i - 1];
		}
		elements[pos] = value; // Записываем значение в правильную позицию
	}

	// Удаление элемента
	void remove(const T& value)
	{
		for (size_t i = 0; i < elements.getSize(); ++i)
		{
			if (elements[i] == value)
			{
				// Сдвиг элементов для заполнения "дырки"
				for (size_t j = i; j < elements.getSize() - 1; ++j)
				{
					elements[j] = elements[j + 1];
				}
				elements.pop_back();
				return;
			}
		}
		throw std::invalid_argument("Element not found");
	}

	// Проверка наличия элемента
	bool has(const T& value) const
	{
		return contains(value);
	}

	// Количество элементов
	size_t size() const
	{
		return elements.getSize();
	}
};