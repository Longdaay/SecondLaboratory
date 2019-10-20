#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <vector>

using namespace std;

int Search_Binary(vector<int> digits_array, int left, int right, int key, bool har)
{
	bool counter = 1;
	int midd = 0;
	while (counter == 1)
	{
		midd = (left + right) / 2;

		if (key < digits_array[midd])       // если искомое меньше значения в ячейке
			right = midd - 1;      // смещаем правую границу поиска
		else if (key > digits_array[midd])  // если искомое больше значения в ячейке
			left = midd + 1;    // смещаем левую границу поиска
		else                       // иначе (значения равны)
			return midd;           // функция возвращает индекс ячейки

		if (left > right)          // если границы сомкнулись 
			counter = 0;
	}
	if (har == 0)
		return midd;
	else
		return -1;
}

int main()
{
	setlocale(0, "");
	unsigned short n; // переменная, которая хранит размерность массива;
	int temp; // переменная, которая, во время сортировки массива, хранит временное значение элемента
	int min_value; // переменная, которая принимает минимальное значение во время сортировки
	int j = 0; // объявление переменной, которая используется для выбора иного от i элемента массива
	short value_a; // переменная, в которую пользователь вводит значение для проверки
	int count = 0; // переменная, которая хранит количество чисел удовлетворяющих условию
	chrono::steady_clock sc;   // create an object of `steady_clock` class
	int index_1 = 0;
	int index_2 = 0;
	int middle = 0;
	double seconds; // переменная, которая хранит в себе время исполнения события
	int key = 0;
	bool har = 0;
	
	// вводим значение размерности массива
	cout << "Введите размерность массива N" << endl;
	cin >> n;
	vector<int> digits_array(n);
	vector<int> numbers_array(n);
	// выводим получившийся массив
	/*cout << endl << "Получившийся массив:" << endl;
	// 
	srand(time(0)); // устанавливает передаваемое пользователем значение в качестве стартового. Получает на вход в виде параметра системное время, которое при каждом запуске программы будет разным. Позволяет rand() каждый раз генерировать случайные числа

	for (int i = 0; i < n; i++) // цикл для генерации цифр и звписи в
	{
		digits_array[i] = rand() % 100; // генерируем элемент массива и загоняем значение в диапазон от 0 до 99
		cout << digits_array[i] << " "; // выводим через пробел
	}
	cout << endl << "Достаточно!" << endl << endl;
	cout << "Отсортированный массив: " << endl;
	auto start = sc.now();     // start timer // устанавливаем начало отсчета времени события
	// сортируем массив вставками insertion sort
	for (int i = 1; i < n; i++)
	{
		min_value = digits_array[i]; // задаем текущему минимальному значению массива текущий элемент массива
		j = i - 1; // задаем значению j на 1 меньше, чем i, для того, чтобы работать с предыдущем элемнентом массива 
		while (j >= 0 and digits_array[j] > min_value) //пока текущий элемент меньше предыдущего и j не присвоила отрицательное значение, присваиваем последующему значению предыдущее ???
		{
			digits_array[j + 1] = digits_array[j];
			j = j - 1;
		}
		digits_array[j + 1] = min_value; // присыаиваем ???
	}
// устанавливаем конец отсчета времени события
// присваиваем значению время, потраченное на сортировку массива
	auto end = sc.now();       // end timer (starting & ending is done by measuring the time at the moment the process started & ended respectively)
	auto time_span = static_cast<chrono::duration<double>>(end - start);   // measure time span between start & end
	// выводим отсортированный массив
	for (int i = 0; i < n; i++)
	{
		cout << digits_array[i] << " ";
	}
	cout << endl << endl;
	cout << "Время, затраченное на сортировку: " << time_span.count() << " секунд" << endl << endl;
	// указываем минимальное и максимальное значения массива
	cout << "manimum value in array: " << digits_array[0] << endl;
	cout << "maximum value in array: " << digits_array[n - 1] << endl << endl;
	cout << "medium value: " << digits_array[digits_array.size()/2] << endl;
	cout << "medium value (min + max) / 2: " << (digits_array[0] + digits_array[n - 1]) / 2 << endl;
	*/
	cout << "Другой массив: " << endl;
	count = 0;
	for (int i = 0; i < n; i++)
	{
		while (count == 0)
		{
			numbers_array[i] = rand() % n;
			for (int j = 0; i < n; j++)
			{
				if (numbers_array[i + 1] == numbers_array[j])
				{
					count = 0;
				}
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		cout << numbers_array[i] << " ";

	}
	cout << endl;
	////////////////задание с поиском большего и меньшего значения
	/*
	// вводим значение для подсчета количества элементов массива, не превышающих заданное значение
	cout << "Введите значение А (Выведет количество элементов массива, которые меньше значения А): ";
	cin >> value_a; // сделатт защиту от дурака
	for (int i = 0; i < n; i++) // прогоняем весь массив и подсчитываем количество элементов
	{
		if (digits_array[i] < value_a)
		{
			count++;
		}
	}
	// выводим полученное количество
	cout << "Количество элементов < " << value_a << ": " << count << endl;

	// вводим значение для подсчета кодичества эдементов, превышающих заданное значение
	cout << "Введите значение В (Выведет количество элементов массива, которые больше значения В): ";

	cin >> value_a; // объединить циклы в один
	count = 0; // обнуляем "счетчик" для повторного ичпользования 
	for (int i = 0; i < n; i++) // прогоняем весь массив и подсчитываем количество элементов
	{
		if (digits_array[i] > value_a)
		{
			count++;
		}
	}
	// выводим полученное количество
	cout << "Количество элементов > " << value_a << ": " << count << endl;






	//////////////////// подсчет количество значений среднего числа массива
	*/
	/*middle = (digits_array[0] + digits_array[n - 1]) / 2;
	middle--;
	start = sc.now();
	index_1 = Search_Binary(digits_array, 0, n, middle, har) - 1;
	end = sc.now();       // end timer (starting & ending is done by measuring the time at the moment the process started & ended respectively)
	time_span = static_cast<chrono::duration<double>>(end - start);   // measure time span between start & end
	cout << "Указанное число находится в ячейке с индексом (левый): " << index_1<< "\n\n";
	cout << "Время, затраченное на поиск: " << time_span.count() << " секунд" << endl << endl;
	middle = middle + 2;
	 start = sc.now();
	index_2 = Search_Binary(digits_array, 0, n, middle, har) + 1 ;
	end = sc.now();       // end timer (starting & ending is done by measuring the time at the moment the process started & ended respectively)
	time_span = static_cast<chrono::duration<double>>(end - start);   // measure time span between start & end
	cout << "Указанное число находится в ячейке с индексом (правый): " << index_2 << "\n\n";
	cout << "Время, затраченное на поиск: " << time_span.count() << " секунд" << endl << endl;

	cout << "Среднее значение " << (digits_array[0] + digits_array[n - 1]) / 2 << " находится в промежутке позиций " << digits_array[index_1] << " .... " << digits_array[index_2] << endl;
	count = 0;
	start = sc.now();
	for (int i = index_1; i < index_2; i++)
	{
		if (digits_array[i] == (digits_array[0] + digits_array[n - 1]) / 2)
		{
			count++;
		}
	}
	end = sc.now();       // end timer (starting & ending is done by measuring the time at the moment the process started & ended respectively)
	time_span = static_cast<chrono::duration<double>>(end - start);   // measure time span between start & end
	cout << "Количество элементов, равных среднему значению: " << count << endl;
	cout << "Время, затраченное на поиск количества средних значений в массиве (через бинарный поиск): " << time_span.count() << " секунд" << endl << endl;








	///// проверка глупой проверки
	count = 0; // обнуляем "счетчик" для повторного ичпользования
	start = sc.now();
	for (int i = 0; i < n; i++) // прогоняем весь массив и подсчитываем количество элементов
	{
		if (digits_array[i] == (digits_array[0] + digits_array[n - 1]) / 2)
		{
			count++;
		}
	}
	end = sc.now();       // end timer (starting & ending is done by measuring the time at the moment the process started & ended respectively)
	time_span = static_cast<chrono::duration<double>>(end - start);   // measure time span between start & end
	cout << "Количество элементов, равных среднему значению: " << count << endl;
	cout << "Время, затраченное на поиск количества средних значений в массиве (глупая проверка): " << time_span.count() << " секунд" << endl << endl;
	/////// проверка глупой проверки
	// что б задать рандомный неповторяющийся номер элемента массива, надо сравнить каждый получаемый элемент с остальными и, если он не подходит, то генерировать заново 
	*/

	/*

	///////////// 2 zadanie //////////////
	cout << "_________________ЗАДНИЕ 2_________________" << endl;
	system("pause");
	for (int i = 0; i < n; i++)
	{
		if (i != n - 1)
			digits_array[i] = digits_array[i] + digits_array[i + 1];
		else
			digits_array[i] = digits_array[i] + digits_array[0];
		cout << digits_array[i] << " ";
	}
	cout << endl;
	cout << "Обратная сортировка " << endl;
	for (int i = 0; i < n; i++)
	{
		int temp = 0;
		int b = rand() % n;
		temp = digits_array[b];
		digits_array[b] = digits_array[i];
		digits_array[i] = temp;
		cout << digits_array[i] << " ";
	}
	cout << endl;
	////////////поиск, вставка, удаление ////////////////
	//////поиск
	har = 1;
	cout << "Введите число, которое найдем в массиве, добавим в массив и удалим: ";
	cin >> key;
	start = sc.now();
	index_1 = Search_Binary(digits_array, 0, n, key, har);
	if (index_1 >= 0)
		cout << "Искомое значение находится в массиве на позиции " << index_1 << endl;
	else
		cout << "Искомого значения нет в массиве!" << endl;
	end = sc.now();       // end timer (starting & ending is done by measuring the time at the moment the process started & ended respectively)
	time_span = static_cast<chrono::duration<double>>(end - start);   // measure time span between start & end
	cout << "Время, затраченное на поиск числа: " << time_span.count() << " секунд" << endl << endl;
	///// вставка
	
	start = sc.now();
	digits_array.push_back(key);
	end = sc.now();       // end timer (starting & ending is done by measuring the time at the moment the process started & ended respectively)
	for (int i = 0; i < digits_array.size(); i++)
	{
		cout << digits_array[i] << " ";
	}
	time_span = static_cast<chrono::duration<double>>(end - start);   // measure time span between start & end
	cout << endl << "Время, затраченное на добавление числа: " << time_span.count() << " секунд" << endl << endl;

	//// удаление
	start = sc.now();
	digits_array.pop_back();
	end = sc.now();       // end timer (starting & ending is done by measuring the time at the moment the process started & ended respectively)
	for (int i = 0; i < digits_array.size(); i++)
	{
		cout << digits_array[i] << " ";
	}
	time_span = static_cast<chrono::duration<double>>(end - start);   // measure time span between start & end
	cout << endl << "Время, затраченное на удаление числа: " << time_span.count() << " секунд" << endl << endl;
	*/
	return 0;
}