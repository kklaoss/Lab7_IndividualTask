#include <iostream>
#include <string>
#include "set.h"

int main()
{
	try
	{
		// Тест 1: Работа с целыми числами
		Set<int> intSet;
		intSet.insert(10);   // [10]
		intSet.insert(20);   // [10, 20]
		intSet.insert(5);    // [5, 10, 20]
		std::cout << "Int set size: " << intSet.size() << std::endl; // 3

		// Попытка добавить дубликат (будет исключение)
		try
		{
			intSet.insert(10);
		}
		catch (const std::invalid_argument& e)
		{
			std::cerr << "Error: " << e.what() << std::endl;
		}

		intSet.remove(20); // Удаление существующего элемента
		std::cout << "Size after removal: " << intSet.size() << std::endl; // 2

		// Тест 2: Работа с числами с плавающей точкой
		Set<double> doubleSet;
		doubleSet.insert(3.14);
		doubleSet.insert(1.618); // Автоматическая сортировка: [1.618, 3.14]
		std::cout << "Double set size: " << doubleSet.size() << std::endl;

		// Тест 3: Работа со строками (лексикографический порядок)
		Set<std::string> stringSet;
		stringSet.insert("apple");
		stringSet.insert("banana"); // ["apple", "banana"]
		std::cout << "String set size: " << stringSet.size() << std::endl;

		// Проверка наличия элемента
		if (stringSet.has("banana"))
		{
			std::cout << "Banana found!" << std::endl;
		}

	}
	catch (const std::exception& e)
	{ // Общий обработчик исключений
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	return 0;
}