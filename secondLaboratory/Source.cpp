/////////// Разработать алгоритм и написать программу:
//////////	1)	которая создает массив размерности N, заполненный случайными числами в диапазоне от 0 до 99;
/////////	2)	сортирует элементы массива сортировкой - вставками (insertion sort);
////////	3)	найдет максимальный и минимальный элемент массива;
///////		4)	выведит количество элементов, равных среднему значения max и min;
//////		5)	выводит количество элементов, которые меньше числа a;
/////		6)	выводит количество элементов, которые больше числа b;
////		7)	выводит скорость удаление, вставки и поиска значения;
///			8)  заменит каждый элемент массива суммой значений текущего элементы и следующего (последний = последний + первый). Сделает «обратную» сортировку – каждому элементу присвоить случайный номер в массиве;
//			9)	выводит скорость обмена элементов массива, номера пользователем.


#include <iostream>
#include <chrono>
#include <vector>
#include <set>
#include <Windows.h>

using namespace std;
const int NotUsed = system("color 70");

void SetColor(int text, int bg) //Функция смены цвета
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)((bg << 4) | text));
}
int Search_Binary(vector<int>& digits_array, int left, int right, int key, bool har)
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
void print_array(vector<int> digits_array) // функция вывода массива
{
	for (int i = 0; i < digits_array.size(); i++)
	{
		cout << digits_array[i] << " ";
	}
}
void print_array_color(vector<int> digits_array, int key, int key_2, int par) // вывод массива с дополнительной подсветкой значений. Дополнительно принимает на вход параметр для вывода
{
	int temp = 0;
	for (int i = 0; i < digits_array.size(); i++)
	{
		if (par == 0) //поиск значения - первое вхождение считываем лишь
		{
			if (digits_array[i] == key and temp == 0)
			{
				SetColor(5, 7);
				cout << digits_array[i] << " ";
				SetColor(0, 7);
				temp = 1;
			}
			else
				cout << digits_array[i] << " ";
		}
		if (par == 1) // добавление элемента - выводим последнее значение
		{
			if (i == digits_array.size()- 1)
			{
				SetColor(5, 7);
				cout << digits_array[i] << " ";
				SetColor(0, 7);
			}
			else
				cout << digits_array[i] << " ";
		}
		if (par == 2) // обмен элементов между собой
		{
			if (i == key or i == key_2)
			{
				SetColor(5, 7);
				cout << digits_array[i] << " ";
				SetColor(0, 7);
			}
			else
				cout << digits_array[i] << " ";
		}
	}
	cout << endl;
}
int count_if(vector<int>& digits_array, int value, int param) // функция для прогона массива и поиска меньшего/большего/среднего значения
{
	int count = 0; // "обнуляем счетчик" для дальнейшего использования
	for (int i = 0; i < digits_array.size(); i++) // прогоняем весь массив и подсчитываем количество элементов
	{
		switch (param)
		{
		case 0:
			if (digits_array[i] < value) // ищем количество меньших искомого
			{
				count++;
			}
			break;
		case 1:
			if (digits_array[i] > value) // ищем количество больших искомого
			{
				count++;
			}
			break;
		case 2:
			if (digits_array[i] == value) // ищем количество равных искомому
			{
				count++;
			}
			break;
		default:
			break;
		}
	}
	return count; // возвращаем количество найденных
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
void random_array(vector<int>& digits_array)
{
	// выводим получившийся массив
	cout << endl << "Получившийся массив:" << endl;
	srand(time(0)); // устанавливает передаваемое пользователем значение в качестве стартового. Получает на вход в виде параметра системное время, которое при каждом запуске программы будет разным. Позволяет rand() каждый раз генерировать случайные числа
	for (int i = 0; i < digits_array.size(); i++) // цикл для генерации цифр и записи в 
	{
		digits_array[i] = rand() % 100; // генерируем элемент массива и загоняем значение в диапазон от 0 до 99
		cout << digits_array[i] << " "; // выводим через пробел
	}
	cout << endl << "Достаточно!" << endl << endl;

	system("pause"); // ожидаем ввода пользователя
}
void swap(int* first_p, int* second_p)
{
	int temp = *first_p;
	*first_p = *second_p;
	*second_p = temp;
}
void insertion_sort(vector<int>& digits_array)
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
void bubble_sort(vector<int>& digits_array) // сортировка пузырьком
{
	int temp;
	for (int i = 0; i < digits_array.size() - 1; i++)
		for (int j = 0; j < digits_array.size() - 1; j++)
			if (digits_array[j] > digits_array[j + 1])
			{
				swap(digits_array[j], digits_array[j + 1]); // меняем местами, если искомое значение больше следующего 
			}
}
void selection_sort(vector<int>& b)
{
	int i, j, min_idx;

	for (i = 0; i < b.size() - 1; i++)
	{
		// Находим минимальный элемент в неотсортированном массиве 
		min_idx = i;
		for (j = i + 1; j < b.size(); j++)
			if (b[j] < b[min_idx])
				min_idx = j;

		// Меняем найденный минимальный элемент с первым
		swap(b[min_idx], b[i]);
	}
}
void gnomeSort(vector<int>& c) // при нахождении неотсортированной пары делается шаг назад, отсортированной - шаг вперед
{
	int index = 0;

	while (index < c.size()) {
		if (index == 0)
			index++;
		if (c[index] >= c[index - 1])
			index++;
		else {
			swap(c[index], c[index - 1]);
			index--;
		}
	}
	return;
}
void ShakerSort(vector<int>& d) // Сортировка происходит в две стороны, что увеличивает скорость расчета
{
	int i, j, k;
	int m = d.size();
	for (i = 0; i < m;) {
		for (j = i + 1; j < m; j++) {
			if (d[j] < d[j - 1])
				swap(d[j], d[j - 1]);
		}
		m--;
		for (k = m - 1; k > i; k--) {
			if (d[k] < d[k - 1])
				swap(d[k], d[k - 1]);
		}
		i++;
	}
}
void min_middle_max(vector<int>& digits_array)
{	
	// указываем минимальное, среднее и максимальное значения массива
	cout << "Минимальное значение в массиве: " << digits_array[0] << endl;
	cout << "Максимальное значение в массиве: " << digits_array[digits_array.size() - 1] << endl << endl;
	cout << "Среднее значение (min + max) / 2: " << (digits_array[0] + digits_array[digits_array.size() - 1]) / 2 << endl;

	system("pause"); // ожидаем ввода пользователя
}
void min_max_counts(vector<int>& digits_array, int param)
{
	int value_a = checkdigit(); // вводим значение, предварительно провериd на правильность ввода
	int count = count_if(digits_array, value_a, param); // param = 0 - проверяем, сколько значений меньше  param = 1 - проверяем, сколько значений больше
	if (param == 0) 
		cout << "Количество элементов < " << value_a << ": " << count << endl; // выводим полученное количество
	else
		cout << "Количество элементов > " << value_a << ": " << count << endl; // выводим полученное количество
	system("pause"); // ожидаем ввода пользователя
}
int main()
{
	setlocale(0, ""); // локализация
	unsigned short n; // переменная, которая хранит размерность массива
	int value_a; // переменная, в которую пользователь вводит значение для проверки
	int count; // переменная, которая хранит количество чисел удовлетворяющих условию
	chrono::steady_clock sc;   // create an object of `steady_clock` class
	int index_1, index_2; // переменные для хранения левой и правой границы от среднего значения
	int middle; // переменная, которая хранит среднее значение значений массива
	double seconds; // переменная, которая хранит в себе время исполнения события
	int key; // переменная, в которую пользователь вводит значение для его поиска/добавления/удаления в массиве
	bool har = 0; // параметр, в зависимости от которого меняется условие выполнения бинарного поиска
	int temp_1, temp_2; // переменные для временного хранения значений
	int param = 0; // параметр, в зависимости от которого меняется условие выполнения проверки искомого значения
	double summ_time = 0.; // переменная, которая хранит общее время выполнения бинарного поиска

	cout << "ЛАБОРАТОРНАЯ РАБОТА №2 - Работа с сортировкой массива" << endl << endl;
	// вводим значение размерности массива
	cout << "Введите размерность массива N (N >= 4, арабскими цифрами - Пример: 10, 42, 54, 10000)" << endl;
	n = checkdigit();

	vector<int> digits_array(n); // основной массив чисел
	set <int> numbers_alt_array; // неповторяющийся массив необходим для создания массива неповторяющихся индексов элеметов
	vector<int> numbers_array; // дополнительный массив индексов для выполнения 2-го задания
	vector<int> a(n);
	vector<int> b(n);
	vector<int> c(n);
	vector<int> d(n);
	
	random_array(digits_array); // рандомайз массива

	a = digits_array; // сортировка пузырьком (Bubble sort)
	b = digits_array; // сортировка выбором (Selection sort)
	c = digits_array; // сортировка Gnome (Gnome sort)
	d = digits_array; // сортировка усовершенствованным пузырьком (shaker sort)

	auto start = sc.now();     // устанавливаем начало отсчета времени события
	insertion_sort(digits_array); // сортировка массива вставками
	auto end = sc.now();       // устанавливаем конец отсчета времени события
	auto time_span = static_cast<chrono::duration<double>>(end - start);   // высчитываем время, затраченное на событие

	print_array(digits_array); // выводим отсортированный массив
	cout << endl << endl;
	cout << "Время, затраченное на сортировку вставками: " << time_span.count() << " секунд" << endl << endl;
	
	auto start_1 = sc.now();     // устанавливаем начало отсчета времени события
	bubble_sort(a); // сортировка массива пузырьком
	auto end_1 = sc.now();       // устанавливаем конец отсчета времени события
	auto time_span_1 = static_cast<chrono::duration<double>>(end_1 - start_1);   // высчитываем время, затраченное на событие
	cout << "Время, затраченное на сортировку пузырьком: " << time_span_1.count() << " секунд" << endl << endl;

	auto start_2 = sc.now();     // устанавливаем начало отсчета времени события
	selection_sort(b); // сортировка массива выбором
	auto end_2 = sc.now();       // устанавливаем конец отсчета времени события
	auto time_span_2 = static_cast<chrono::duration<double>>(end_2 - start_2);   // высчитываем время, затраченное на событие
	cout << "Время, затраченное на сортировку выбором: " << time_span_2.count() << " секунд" << endl << endl;

	auto start_3 = sc.now();     // устанавливаем начало отсчета времени события
	gnomeSort(c); // сортировка массива Gnome
	auto end_3 = sc.now();       // устанавливаем конец отсчета времени события
	auto time_span_3 = static_cast<chrono::duration<double>>(end_3 - start_3);   // высчитываем время, затраченное на событие
	cout << "Время, затраченное на сортировку Gnome: " << time_span_3.count() << " секунд" << endl << endl;

	auto start_4 = sc.now();     // устанавливаем начало отсчета времени события
	ShakerSort(d); // сортировка массива Shaker sort
	auto end_4 = sc.now();       // устанавливаем конец отсчета времени события
	auto time_span_4 = static_cast<chrono::duration<double>>(end_4 - start_4);   // высчитываем время, затраченное на событие
	cout << "Время, затраченное на сортировку усовершенствованным пузырьком: " << time_span_4.count() << " секунд" << endl << endl;

	min_middle_max(digits_array); // функция вывода мин, мидл, мах значения
	
											//----------------Вывод количества больших и меньших значений в соответствии с вводимым числом----------------

	cout << "Введите значение А (Выведет количество элементов массива, которые меньше значения А (арабскими цифрами - Пример: 10, 42, 54, 10000)): "; // вводим значение 
	min_max_counts(digits_array, param);

	cout << "Введите значение А (Выведет количество элементов массива, которые больше значения А (арабскими цифрами - Пример: 10, 42, 54, 10000)): "; // ввводим значение для подсчета количества элементов, превышающих заданное значение
	min_max_counts(digits_array, param = 1); // проверяем, сколько значений больше

												//----------------подсчет количества элементов равных среднему значению массива----------------

	middle = (digits_array[0] + digits_array[n - 1]) / 2;
	middle--; // уменьшаем среднее значение на 1, что б найти левую границу для посчета элементов
	auto start_5 = sc.now(); // устанавливаем начало отсчета времени события
	index_1 = Search_Binary(digits_array, 0, n, middle, har) - 1; // находим левую границу
	auto end_5 = sc.now();       // устанавливаем конец отсчета времени события
	auto time_span_5 = static_cast<chrono::duration<double>>(end_5 - start_5);   // высчитываем время, затраченное на событие
	//cout << "Указанное число находится в ячейке с индексом (левый): " << index_1<< "\n\n";
	//cout << "Время, затраченное на поиск левой границы: " << time_span_5.count() << " секунд" << endl << endl;

	summ_time = summ_time + time_span_5.count();

	middle = middle + 2; // увеличиваем среднее значение на 2, что б найти правую границу для посчета элементов
	auto start_6 = sc.now(); // устанавливаем начало отсчета времени события
	index_2 = Search_Binary(digits_array, 0, n, middle, har) + 1;  // находим правую границу
	auto end_6 = sc.now();       // устанавливаем конец отсчета времени события
	auto time_span_6 = static_cast<chrono::duration<double>>(end_6 - start_6);   // высчитываем время, затраченное на событие
	//cout << "Указанное число находится в ячейке с индексом (правый): " << index_2 << "\n\n";
	//cout << "Время, затраченное на поиск правой границы: " << time_span_6.count() << " секунд" << endl << endl;

	summ_time = summ_time + time_span_5.count();

	//cout << "Среднее значение " << (digits_array[0] + digits_array[n - 1]) / 2 << " находится в промежутке позиций " << digits_array[index_1] << " .... " << digits_array[index_2] << endl;

	count = 0; // обнуляем "счетчик" для повторного использования
	auto start_7 = sc.now(); // устанавливаем начало отсчета времени события
	for (int i = index_1; i < index_2; i++)
	{
		if (digits_array[i] == (digits_array[0] + digits_array[n - 1]) / 2)
		{
			count++;
		}
	}
	auto end_7 = sc.now();      // устанавливаем конец отсчета времени события
	auto time_span_7 = static_cast<chrono::duration<double>>(end_7 - start_7);   // высчитываем время, затраченное на событие
	summ_time = summ_time + time_span.count();
	cout << "Количество элементов равных среднему значению ("<< middle - 1 << "): " << count << endl;
	cout << "Время затраченное на поиск количества значений в массиве (через бинарный поиск): " << summ_time << " секунд" << endl << endl;

	///// проверка глупой проверкой /////////
	value_a = (digits_array[0] + digits_array[n - 1]) / 2;
	auto start_8 = sc.now(); // устанавливаем начало отсчета времени события
	count = count_if(digits_array, value_a, param = 2);
	auto end_8 = sc.now();     // устанавливаем конец отсчета времени события
	auto time_span_8 = static_cast<chrono::duration<double>>(end_8 - start_8);   // высчитываем время, затраченное на событие
	cout << "Количество элементов равных среднему значению (" << middle - 1 << "): " << count << endl;
	cout << "Время затраченное на поиск количества значений в массиве (глупая проверка): " << time_span_8.count() << " секунд" << endl << endl;
	
																										//---------------- 2 задание ----------------

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
	cout << endl;
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
	cout << endl;
	system("pause"); // ожидаем ввода пользователя
	cout << endl;
																	//---------------- поиск, добавление, удаление, обмен ----------------

	//////поиск
	har = 1;
	cout << "Введите число, которое найдем в массиве, добавим в массив, а затем удалим (арабскими цифрами - Пример: 10, 42, 54, 10000): ";
	key = checkdigit();
	auto start_9 = sc.now(); // устанавливаем начало отсчета времени события
	index_1 = Search_Binary(digits_array, 0, n, key, har);
	if (index_1 >= 0)
		cout << "Искомое значение находится в массиве на позиции " << index_1 << endl;
	else
		cout << "Искомого значения нет в массиве!" << endl;
	auto end_9 = sc.now();     // устанавливаем конец отсчета времени события
	auto time_span_9 = static_cast<chrono::duration<double>>(end_9 - start_9);   // высчитываем время, затраченное на событие
	print_array_color(digits_array, key, n + 1, 0);
	cout << "Время, затраченное на поиск: " << time_span_9.count() << " секунд" << endl << endl;


	///// добавление
	system("pause"); // ожидаем ввода пользователя
	cout << "Добавление в массив числа " << key << endl;
	auto start_10 = sc.now(); // устанавливаем начало отсчета времени события
	digits_array.push_back(key);
	auto end_10 = sc.now();   // устанавливаем конец отсчета времени события
	print_array_color(digits_array, key, n + 1, 1);
	auto time_span_10 = static_cast<chrono::duration<double>>(end_10 - start_10);   // высчитываем время, затраченное на событие
	cout << endl << "Время, затраченнное на добавление: " << time_span_10.count() << " секунд" << endl << endl;


	//// удаление
	system("pause"); // ожидаем ввода пользователя
	cout << "Удаление из массива числа " << key << endl;
	auto start_11 = sc.now(); // устанавливаем начало отсчета времени события
	digits_array.pop_back();
	auto end_11 = sc.now();       // устанавливаем конец отсчета времени события
	print_array(digits_array);
	auto time_span_11 = static_cast<chrono::duration<double>>(end_11 - start_11);   // высчитываем время, затраченное на событие
	cout << endl << "Время, затраченное на удаление: " << time_span_11.count() << " секунд" << endl << endl;


	//// обмен
	system("pause"); // ожидаем ввода пользователя
	cout << "Обмен элементов заданных пользователем "<< endl;
	cout << "Введите первую позицию элемента (вводите число не превышающее размерность массива - от 0 до "<< n -1 << " )" << endl;
	index_1 = checkdigit();
	cout << "Введите вторую позицию элемента (вводите число не превышающее размерность массива - от 0 до " << n - 1 << " )" << endl;
	index_2 = checkdigit();
	auto start_12 = sc.now(); // устанавливаем начало отсчета времени события
	temp_1 = digits_array[index_1];
	digits_array[index_1] = digits_array[index_2];
	digits_array[index_2] = temp_1;
	auto end_12 = sc.now();       // устанавливаем конец отсчета времени события
	print_array_color(digits_array, index_1, index_2, 2);
	auto time_span_12 = static_cast<chrono::duration<double>>(end_12 - start_12);   // высчитываем время, затраченное на событие
	cout << endl << "Время, затраченное на обмен: " << time_span_12.count() << " секунд" << endl << endl;
	system("pause");

	return 0;
}