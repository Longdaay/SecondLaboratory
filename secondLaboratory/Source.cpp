#include <iostream>
#include <chrono>
#include <vector>
#include <set>

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

void print_array(vector<int>&digits_array)
{
	for (int i = 0; i < digits_array.size(); i++)
	{
		cout << digits_array[i] << " ";
	}
}
int count_if(vector<int>&digits_array , int value, int param)
{
	int count = 0;
	for (int i = 0; i < digits_array.size(); i++) // прогоняем весь массив и подсчитываем количество элементов
	{
		switch (param)
		{
		case 0:
			if (digits_array[i] < value)
			{
				count++;
			}
			break;
		case 1:
			if (digits_array[i] > value)
			{
				count++;
			}
			break;
		case 2:
			if (digits_array[i] == value)
			{
				count++;
			}
			break;
		default:
			break;
		}
	}
	return count;
}
int checkdigit()
{
	while (true)
	{
		int value;
		// вводим число, которое хотим представить в двоичной форме
		cin >> value; // число целое
		if (cin.fail()) // ecли предыдущее извелечение оказлось неудачным,
		{
			cin.clear(); // то возвращаем cin в обычный режим работы
			cin.ignore(32767, '\n'); // и удаляем из буфера значения предыдущего ввода 
			cout << "Недопустимое заданное число. Введите число правильно" << '\n';
		}
		else
		{
			cin.ignore(32767, '\n'); // удаляем из буфера значения предыдущего ввода 
			return value;
		}
	}
}
void random_array(vector<int>&digits_array)
{
	// выводим получившийся массив
	cout << endl << "Получившийся массив:" << endl;
	//
	srand(time(0)); // устанавливает передаваемое пользователем значение в качестве стартового. Получает на вход в виде параметра системное время, которое при каждом запуске программы будет разным. Позволяет rand() каждый раз генерировать случайные числа
	for (int i = 0; i < digits_array.size(); i++) // цикл для генерации цифр и записи в 
	{
		digits_array[i] = rand() % 100; // генерируем элемент массива и загоняем значение в диапазон от 0 до 99
		cout << digits_array[i] << " "; // выводим через пробел
	}
	cout << endl << "Достаточно!" << endl << endl;

	system("pause"); // ожидаем ввода пользователя
}
void insertion_sort(vector<int>&digits_array)
{
	// сортируем массив вставками --  insertion sort
	cout << "Отсортированный массив: " << endl;
	int min_value;	// переменная, принимающая минимальное значение минимальное значение
	int j = 0; // объявление переменной, котороая используется для выбора иного от i элемента массива
	for (int i = 1; i < digits_array.size(); i++)
	{
		min_value = digits_array[i]; // задаем текущему минимальному значению массива текущий элемент массива
		j = i - 1; // задаем значение j на 1 меньше, чем i, для того, чтобы работать с предыдушем элементом массива 
		while (j >= 0 and digits_array[j] > min_value) //пока текущий элемент меньше предыдущего и j не присвоилось отрицательное значение, присваиваем последнему значению предыдущее ????
		{
			digits_array[j + 1] = digits_array[j];
			j = j - 1;
		}
		digits_array[j + 1] = min_value; // присваеваем следующему элементу минимальное значения массива
	}

}
int main()
{
	setlocale(0, ""); // локализация
	unsigned short n; // переменна, которая хранит размерность массива
	short value_a; // переменная, в которую пользователь вводит значение для проверки
	int count; // переменная, которая хранит количество чисел удовлетворяющих условию
	chrono::steady_clock sc;   // create an object of `steady_clock` class
	int index_1;
	int index_2;
	int middle;
	double seconds; // переменная, которая хранит в себе время исполнения события
	int key;
	bool har = 0;
	int temp_1;
	int temp_2;
	int param = 0;
	double summ_time = 0.;

	// вводим значение размерности массива
	cout << "Введите размерность массива N (N >= 4, арабскими цифрами - Пример: 10, 42, 54, 10000)" << endl;
	n = checkdigit();
	vector<int> digits_array(n); // основной массив числел
	set <int> numbers_alt_array; // неповторяющийся массив необходим для создания массива неповторяющихся индексов элеметов
	vector<int> numbers_array; // дополнительный массив индексов для выполнения 2-го задания

	random_array(digits_array);
	
	auto start = sc.now();     // устанавливаем начало отсчета времени события
	insertion_sort(digits_array);

	auto end = sc.now();       // устанавливаем конец отсчета времени события
	auto time_span = static_cast<chrono::duration<double>>(end - start);   // высчитываем время, затраченное на событие

	// выводим отсортированный массив
	print_array(digits_array);
	cout << endl << endl;
	cout << "Время, затраченное на сортировку: " << time_span.count() << " секунд" << endl << endl;
	// указываем минимальное, среднее и максимальное значения массива
	cout << "Минимальное значение в массиве: " << digits_array[0] << endl;
	cout << "Максимальное значение в массиве: " << digits_array[n - 1] << endl << endl;
	cout << "Среднее значение в массиве: " << digits_array[digits_array.size()/2] << endl;
	cout << "Среднее значение (min + max) / 2: " << (digits_array[0] + digits_array[n - 1]) / 2 << endl;

	system("pause"); // ожидаем ввода пользователя
	////////////////Вывод количества больших и меньших значений в соответствии с вводимым числом
	// вводим значение 
	cout << "Введите значение А (Выведет количество элементов массива, которые меньше значения А (арабскими цифрами - Пример: 10, 42, 54, 10000)): ";
	value_a = checkdigit();
	count = count_if(digits_array, value_a, param); // param = 0 - проверяем, сколько значений меньше
	// выводим полученное количество
	cout << "Количество элементов < " << value_a << ": " << count << endl;
	system("pause"); // ожидаем ввода пользователя
	// ввводим значение для подсчета количества элементов, превышающих заданное значение
	cout << "Введите значение А (Выведет количество элементов массива, которые больше значения А (арабскими цифрами - Пример: 10, 42, 54, 10000)): ";
	value_a = checkdigit();
	param = 1; // проверяем, сколько значений больше
	count = count_if(digits_array, value_a, param); // param = 1 - проверяем, сколько значений больше
	// выводим полученное количество
	cout << "Количество элементов > " << value_a << ": " << count << endl;
	system("pause"); // ожидаем ввода пользователя
	////////////////////подсчет количества элементов равных среднему значению массива
	middle = (digits_array[0] + digits_array[n - 1]) / 2;
	middle--; // уменьшаем среднее значение на 1, что б найти левую границу для посчета элементов
	start = sc.now(); // устанавливаем начало отсчета времени события
	index_1 = Search_Binary(digits_array, 0, n, middle, har) - 1; // находим левую границу
	end = sc.now();       // устанавливаем конец отсчета времени события
	time_span = static_cast<chrono::duration<double>>(end - start);   // высчитываем время, затраченное на событие
	//cout << "Указанное число находится в ячейке с индексом (левый): " << index_1<< "\n\n";
	cout << "Время, затраченное на поиск левой границы: " << time_span.count() << " секунд" << endl << endl;
	summ_time = summ_time + time_span.count();
	middle = middle + 2; // увеличиваем среднее значение на 2, что б найти правую границу для посчета элементов
	start = sc.now(); // устанавливаем начало отсчета времени события
	index_2 = Search_Binary(digits_array, 0, n, middle, har) + 1 ;  // находим правую границу
	end = sc.now();       // устанавливаем конец отсчета времени события
	time_span = static_cast<chrono::duration<double>>(end - start);   // высчитываем время, затраченное на событие
	//cout << "Указанное число находится в ячейке с индексом (правый): " << index_2 << "\n\n";
	cout << "Время, затраченное на поиск правой границы: " << time_span.count() << " секунд" << endl << endl;
	summ_time = summ_time + time_span.count();
	//cout << "Среднее значение " << (digits_array[0] + digits_array[n - 1]) / 2 << " находится в промежутке позиций " << digits_array[index_1] << " .... " << digits_array[index_2] << endl;
	count = 0; // обнуляем "счетчик" для повторного использования
	start = sc.now(); // устанавливаем начало отсчета времени события
	for (int i = index_1; i < index_2; i++)
	{
		if (digits_array[i] == (digits_array[0] + digits_array[n - 1]) / 2)
		{
			count++;
		}
	}
	end = sc.now();      // устанавливаем конец отсчета времени события
	time_span = static_cast<chrono::duration<double>>(end - start);   // высчитываем время, затраченное на событие
	summ_time = summ_time + time_span.count();
	cout << "Количество элементов равных среднему значению: " << count << endl;
	cout << "Время затраченное на поиск количества значений в массиве (через бинарный поиск): " << summ_time << " секунд" << endl << endl;

	///// проверка глупой проверки
	param = 2;
	value_a = (digits_array[0] + digits_array[n - 1]) / 2;
	start = sc.now(); // устанавливаем начало отсчета времени события
	count = count_if(digits_array, value_a, param);
	end = sc.now();     // устанавливаем конец отсчета времени события
	time_span = static_cast<chrono::duration<double>>(end - start);   // высчитываем время, затраченное на событие
	cout << "Количество элементов равных среднему значению: " << count << endl;
	cout << "Время затраченное на поиск количества значений в массиве (глупая проверка): " << time_span.count() << " секунд" << endl << endl;
	system("pause"); // ожидаем ввода пользователя
	///////////// 2 задание //////////////
	cout << "_________________ЗАДАНИЕ 2_________________" << endl;

	system("pause"); // ожидаем ввода пользователя
	cout << "Сложение искомого + следующее " << endl;
	for (int i = 0; i < n; i++) // прогоняем массив и обновляем значения (текущее значение = текущее значение + следующее (в случае с последним элементов: последнее значение = последнее значение + первое))
	{
		if (i != n - 1)
			digits_array[i] = digits_array[i] + digits_array[i + 1];
		else
			digits_array[i] = digits_array[i] + digits_array[0];
		cout << digits_array[i] << " ";
	}
	cout << endl;
	system("pause"); // ожидаем ввода пользователя
	cout << "Обратная сортировка массива" << endl;
	for (int i = 0; numbers_alt_array.size() < n; i++) // просчет происходит следующим образом: рандомом получаем число от n, загоняем в set(если значение такое есть - не добавит), если размерность вектора изменилась, то загоняем число в новый вектор
	{
		temp_2 = numbers_alt_array.size(); // присваиваем переменной размерность массива
		temp_1 = rand() % n;
		numbers_alt_array.insert(temp_1);
		if (temp_2 != numbers_alt_array.size())
		{
			numbers_array.push_back(temp_1);
		}
	}
	for (int i = 0; i < n; i++)
	{
		temp_2 = digits_array[i];
		digits_array[i] = digits_array[numbers_array[i]];
		digits_array[numbers_array[i]] = temp_2;
	}
	
	print_array(digits_array);
	system("pause"); // ожидаем ввода пользователя
	cout << endl;
	////////////поиск, добавление, удаление ////////////////
	//////поиск
	har = 1;
	cout << "Введите число, которое найдем в массиве, добавим в массив, а затем удалим (арабскими цифрами - Пример: 10, 42, 54, 10000): ";
	key = checkdigit();
	start = sc.now(); // устанавливаем начало отсчета времени события
	index_1 = Search_Binary(digits_array, 0, n, key, har);
	if (index_1 >= 0)
		cout << "Искомое значение находится в массиве на позиции " << index_1 << endl;
	else
		cout << "Искомого значения нет в массиве!" << endl;
	end = sc.now();     // устанавливаем конец отсчета времени события
	time_span = static_cast<chrono::duration<double>>(end - start);   // высчитываем время, затраченное на событие
	cout << "Время, затраченное на поиск: " << time_span.count() << " секунд" << endl << endl;
	///// добавление
	system("pause"); // ожидаем ввода пользователя
	cout << "Добавление в массив числа " << index_1  << endl;
	start = sc.now(); // устанавливаем начало отсчета времени события
	digits_array.push_back(key);
	end = sc.now();       // end timer (starting & ending is done by measuring the time at the moment the process started & ended respectively)
	print_array(digits_array);
	time_span = static_cast<chrono::duration<double>>(end - start);   // высчитываем время, затраченное на событие
	cout << endl << "Время, затраченнное на добавление: " << time_span.count() << " секунд" << endl << endl;
	//// удаление
	system("pause"); // ожидаем ввода пользователя
	cout << "Удаление из массива числа " << index_1 << endl;
	start = sc.now(); // устанавливаем начало отсчета времени события
	digits_array.pop_back();
	end = sc.now();       // устанавливаем конец отсчета времени события
	print_array(digits_array);
	time_span = static_cast<chrono::duration<double>>(end - start);   // высчитываем время, затраченное на событие
	cout << endl << "Время, затраченное на удаление: " << time_span.count() << " секунд" << endl << endl;

	return 0;
}