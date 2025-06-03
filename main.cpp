#include <iostream>
#include <string>
#include "set.h"

int main()
{
	setlocale(LC_ALL, "RUS");
	try
	{
		// Тест 1: Работа с целыми числами
		Set<int> intSet;
		intSet.insert(10);   // [10]
		intSet.insert(20);   // [10, 20]
		intSet.insert(5);    // [5, 10, 20]
		std::cout << "Размер множества целых чисел: " << intSet.size() << std::endl; // 3

		// Попытка добавить дубликат (будет исключение)
		try
		{
			intSet.insert(10);
		}
		catch (const std::invalid_argument& e)
		{
			std::cerr << "Ошибка: " << e.what() << std::endl;
		}

		intSet.remove(20); // Удаление существующего элемента
		std::cout << "Размер после удаления: " << intSet.size() << std::endl; // 2

		// Тест 2: Работа с числами с плавающей точкой
		Set<double> doubleSet;
		doubleSet.insert(3.14);
		doubleSet.insert(1.618); // Автоматическая сортировка: [1.618, 3.14]
		std::cout << "Размер множества дробных чисел: " << doubleSet.size() << std::endl;

		// Тест 3: Работа со строками (лексикографический порядок)
		Set<std::string> stringSet;
		stringSet.insert("яблоко");
		stringSet.insert("банан"); // ["яблоко", "банан"]
		std::cout << "Размер множества строк: " << stringSet.size() << std::endl;

		// Проверка наличия элемента
		if (stringSet.has("банан"))
		{
			std::cout << "Элемент 'банан' найден!" << std::endl;
		}
	}
	catch (const std::exception& e)
	{ // Общий обработчик исключений
		std::cerr << "Исключение: " << e.what() << std::endl;
	}

	return 0;
}