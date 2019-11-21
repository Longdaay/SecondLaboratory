/////////// ����������� �������� � �������� ���������:
//////////	1)	������� ������� ������ ����������� N, ����������� ���������� ������� � ��������� �� 0 �� 99;
/////////	2)	��������� �������� ������� ����������� - ��������� (insertion sort);
////////	3)	������ ������������ � ����������� ������� �������;
///////		4)	������� ���������� ���������, ������ �������� �������� max � min;
//////		5)	������� ���������� ���������, ������� ������ ����� a;
/////		6)	������� ���������� ���������, ������� ������ ����� b;
////		7)	������� �������� ��������, ������� � ������ ��������;
///			8)  ������� ������ ������� ������� ������ �������� �������� �������� � ���������� (��������� = ��������� + ������). ������� ���������� ���������� � ������� �������� ��������� ��������� ����� � �������;
//			9)	������� �������� ������ ��������� �������, ������ �������������.


#include <iostream>
#include <chrono>
#include <vector>
#include <set>
#include <Windows.h>

using namespace std;
const int NotUsed = system("color 70");

void SetColor(int text, int bg) //������� ����� �����
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

		if (key < digits_array[midd])       // ���� ������� ������ �������� � ������
			right = midd - 1;      // ������� ������ ������� ������
		else if (key > digits_array[midd])  // ���� ������� ������ �������� � ������
			left = midd + 1;    // ������� ����� ������� ������
		else                       // ����� (�������� �����)
			return midd;           // ������� ���������� ������ ������

		if (left > right)          // ���� ������� ���������� 
			counter = 0;
	}
	if (har == 0)
		return midd;
	else
		return -1;
}
void print_array(vector<int> digits_array) // ������� ������ �������
{
	for (int i = 0; i < digits_array.size(); i++)
	{
		cout << digits_array[i] << " ";
	}
}
void print_array_color(vector<int> digits_array, int key, int key_2, int par) // ����� ������� � �������������� ���������� ��������. ������������� ��������� �� ���� �������� ��� ������
{
	int temp = 0;
	for (int i = 0; i < digits_array.size(); i++)
	{
		if (par == 0) //����� �������� - ������ ��������� ��������� ����
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
		if (par == 1) // ���������� �������� - ������� ��������� ��������
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
		if (par == 2) // ����� ��������� ����� �����
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
int count_if(vector<int>& digits_array, int value, int param) // ������� ��� ������� ������� � ������ ��������/��������/�������� ��������
{
	int count = 0; // "�������� �������" ��� ����������� �������������
	for (int i = 0; i < digits_array.size(); i++) // ��������� ���� ������ � ������������ ���������� ���������
	{
		switch (param)
		{
		case 0:
			if (digits_array[i] < value) // ���� ���������� ������� ��������
			{
				count++;
			}
			break;
		case 1:
			if (digits_array[i] > value) // ���� ���������� ������� ��������
			{
				count++;
			}
			break;
		case 2:
			if (digits_array[i] == value) // ���� ���������� ������ ��������
			{
				count++;
			}
			break;
		default:
			break;
		}
	}
	return count; // ���������� ���������� ���������
}
int checkdigit()
{
	while (true)
	{
		int value;
		// ������ �����, ������� ����� ����������� � �������� �����
		cin >> value; // ����� �����
		if (cin.fail()) // ec�� ���������� ����������� �������� ���������,
		{
			cin.clear(); // �� ���������� cin � ������� ����� ������
			cin.ignore(32767, '\n'); // � ������� �� ������ �������� ����������� ����� 
			cout << "������������ �������� �����. ������� ����� ���������" << '\n';
		}
		else
		{
			cin.ignore(32767, '\n'); // ������� �� ������ �������� ����������� ����� 
			return value;
		}
	}
}
void random_array(vector<int>& digits_array)
{
	// ������� ������������ ������
	cout << endl << "������������ ������:" << endl;
	srand(time(0)); // ������������� ������������ ������������� �������� � �������� ����������. �������� �� ���� � ���� ��������� ��������� �����, ������� ��� ������ ������� ��������� ����� ������. ��������� rand() ������ ��� ������������ ��������� �����
	for (int i = 0; i < digits_array.size(); i++) // ���� ��� ��������� ���� � ������ � 
	{
		digits_array[i] = rand() % 100; // ���������� ������� ������� � �������� �������� � �������� �� 0 �� 99
		cout << digits_array[i] << " "; // ������� ����� ������
	}
	cout << endl << "����������!" << endl << endl;

	system("pause"); // ������� ����� ������������
}
void swap(int* first_p, int* second_p)
{
	int temp = *first_p;
	*first_p = *second_p;
	*second_p = temp;
}
void insertion_sort(vector<int>& digits_array)
{
	// ��������� ������ ��������� --  insertion sort
	cout << "��������������� ������: " << endl;
	int min_value;	// ����������, ����������� ����������� �������� ����������� ��������
	int j = 0; // ���������� ����������, �������� ������������ ��� ������ ����� �� i �������� �������
	for (int i = 1; i < digits_array.size(); i++)
	{
		min_value = digits_array[i]; // ������ �������� ������������ �������� ������� ������� ������� �������
		j = i - 1; // ������ �������� j �� 1 ������, ��� i, ��� ����, ����� �������� � ���������� ��������� ������� 
		while (j >= 0 and digits_array[j] > min_value) //���� ������� ������� ������ ����������� � j �� ����������� ������������� ��������, ����������� ���������� �������� ���������� ????
		{
			digits_array[j + 1] = digits_array[j];
			j = j - 1;
		}
		digits_array[j + 1] = min_value; // ����������� ���������� �������� ����������� �������� �������
	}
}
void bubble_sort(vector<int>& digits_array) // ���������� ���������
{
	int temp;
	for (int i = 0; i < digits_array.size() - 1; i++)
		for (int j = 0; j < digits_array.size() - 1; j++)
			if (digits_array[j] > digits_array[j + 1])
			{
				swap(digits_array[j], digits_array[j + 1]); // ������ �������, ���� ������� �������� ������ ���������� 
			}
}
void selection_sort(vector<int>& b)
{
	int i, j, min_idx;

	for (i = 0; i < b.size() - 1; i++)
	{
		// ������� ����������� ������� � ����������������� ������� 
		min_idx = i;
		for (j = i + 1; j < b.size(); j++)
			if (b[j] < b[min_idx])
				min_idx = j;

		// ������ ��������� ����������� ������� � ������
		swap(b[min_idx], b[i]);
	}
}
void gnomeSort(vector<int>& c) // ��� ���������� ����������������� ���� �������� ��� �����, ��������������� - ��� ������
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
void ShakerSort(vector<int>& d) // ���������� ���������� � ��� �������, ��� ����������� �������� �������
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
	// ��������� �����������, ������� � ������������ �������� �������
	cout << "����������� �������� � �������: " << digits_array[0] << endl;
	cout << "������������ �������� � �������: " << digits_array[digits_array.size() - 1] << endl << endl;
	cout << "������� �������� (min + max) / 2: " << (digits_array[0] + digits_array[digits_array.size() - 1]) / 2 << endl;

	system("pause"); // ������� ����� ������������
}
void min_max_counts(vector<int>& digits_array, int param)
{
	int value_a = checkdigit(); // ������ ��������, �������������� �������d �� ������������ �����
	int count = count_if(digits_array, value_a, param); // param = 0 - ���������, ������� �������� ������  param = 1 - ���������, ������� �������� ������
	if (param == 0) 
		cout << "���������� ��������� < " << value_a << ": " << count << endl; // ������� ���������� ����������
	else
		cout << "���������� ��������� > " << value_a << ": " << count << endl; // ������� ���������� ����������
	system("pause"); // ������� ����� ������������
}
int main()
{
	setlocale(0, ""); // �����������
	unsigned short n; // ����������, ������� ������ ����������� �������
	int value_a; // ����������, � ������� ������������ ������ �������� ��� ��������
	int count; // ����������, ������� ������ ���������� ����� ��������������� �������
	chrono::steady_clock sc;   // create an object of `steady_clock` class
	int index_1, index_2; // ���������� ��� �������� ����� � ������ ������� �� �������� ��������
	int middle; // ����������, ������� ������ ������� �������� �������� �������
	double seconds; // ����������, ������� ������ � ���� ����� ���������� �������
	int key; // ����������, � ������� ������������ ������ �������� ��� ��� ������/����������/�������� � �������
	bool har = 0; // ��������, � ����������� �� �������� �������� ������� ���������� ��������� ������
	int temp_1, temp_2; // ���������� ��� ���������� �������� ��������
	int param = 0; // ��������, � ����������� �� �������� �������� ������� ���������� �������� �������� ��������
	double summ_time = 0.; // ����������, ������� ������ ����� ����� ���������� ��������� ������

	cout << "������������ ������ �2 - ������ � ����������� �������" << endl << endl;
	// ������ �������� ����������� �������
	cout << "������� ����������� ������� N (N >= 4, ��������� ������� - ������: 10, 42, 54, 10000)" << endl;
	n = checkdigit();

	vector<int> digits_array(n); // �������� ������ �����
	set <int> numbers_alt_array; // ��������������� ������ ��������� ��� �������� ������� ��������������� �������� ��������
	vector<int> numbers_array; // �������������� ������ �������� ��� ���������� 2-�� �������
	vector<int> a(n);
	vector<int> b(n);
	vector<int> c(n);
	vector<int> d(n);
	
	random_array(digits_array); // ��������� �������

	a = digits_array; // ���������� ��������� (Bubble sort)
	b = digits_array; // ���������� ������� (Selection sort)
	c = digits_array; // ���������� Gnome (Gnome sort)
	d = digits_array; // ���������� ������������������� ��������� (shaker sort)

	auto start = sc.now();     // ������������� ������ ������� ������� �������
	insertion_sort(digits_array); // ���������� ������� ���������
	auto end = sc.now();       // ������������� ����� ������� ������� �������
	auto time_span = static_cast<chrono::duration<double>>(end - start);   // ����������� �����, ����������� �� �������

	print_array(digits_array); // ������� ��������������� ������
	cout << endl << endl;
	cout << "�����, ����������� �� ���������� ���������: " << time_span.count() << " ������" << endl << endl;
	
	auto start_1 = sc.now();     // ������������� ������ ������� ������� �������
	bubble_sort(a); // ���������� ������� ���������
	auto end_1 = sc.now();       // ������������� ����� ������� ������� �������
	auto time_span_1 = static_cast<chrono::duration<double>>(end_1 - start_1);   // ����������� �����, ����������� �� �������
	cout << "�����, ����������� �� ���������� ���������: " << time_span_1.count() << " ������" << endl << endl;

	auto start_2 = sc.now();     // ������������� ������ ������� ������� �������
	selection_sort(b); // ���������� ������� �������
	auto end_2 = sc.now();       // ������������� ����� ������� ������� �������
	auto time_span_2 = static_cast<chrono::duration<double>>(end_2 - start_2);   // ����������� �����, ����������� �� �������
	cout << "�����, ����������� �� ���������� �������: " << time_span_2.count() << " ������" << endl << endl;

	auto start_3 = sc.now();     // ������������� ������ ������� ������� �������
	gnomeSort(c); // ���������� ������� Gnome
	auto end_3 = sc.now();       // ������������� ����� ������� ������� �������
	auto time_span_3 = static_cast<chrono::duration<double>>(end_3 - start_3);   // ����������� �����, ����������� �� �������
	cout << "�����, ����������� �� ���������� Gnome: " << time_span_3.count() << " ������" << endl << endl;

	auto start_4 = sc.now();     // ������������� ������ ������� ������� �������
	ShakerSort(d); // ���������� ������� Shaker sort
	auto end_4 = sc.now();       // ������������� ����� ������� ������� �������
	auto time_span_4 = static_cast<chrono::duration<double>>(end_4 - start_4);   // ����������� �����, ����������� �� �������
	cout << "�����, ����������� �� ���������� ������������������� ���������: " << time_span_4.count() << " ������" << endl << endl;

	min_middle_max(digits_array); // ������� ������ ���, ����, ��� ��������
	
											//----------------����� ���������� ������� � ������� �������� � ������������ � �������� ������----------------

	cout << "������� �������� � (������� ���������� ��������� �������, ������� ������ �������� � (��������� ������� - ������: 10, 42, 54, 10000)): "; // ������ �������� 
	min_max_counts(digits_array, param);

	cout << "������� �������� � (������� ���������� ��������� �������, ������� ������ �������� � (��������� ������� - ������: 10, 42, 54, 10000)): "; // ������� �������� ��� �������� ���������� ���������, ����������� �������� ��������
	min_max_counts(digits_array, param = 1); // ���������, ������� �������� ������

												//----------------������� ���������� ��������� ������ �������� �������� �������----------------

	middle = (digits_array[0] + digits_array[n - 1]) / 2;
	middle--; // ��������� ������� �������� �� 1, ��� � ����� ����� ������� ��� ������� ���������
	auto start_5 = sc.now(); // ������������� ������ ������� ������� �������
	index_1 = Search_Binary(digits_array, 0, n, middle, har) - 1; // ������� ����� �������
	auto end_5 = sc.now();       // ������������� ����� ������� ������� �������
	auto time_span_5 = static_cast<chrono::duration<double>>(end_5 - start_5);   // ����������� �����, ����������� �� �������
	//cout << "��������� ����� ��������� � ������ � �������� (�����): " << index_1<< "\n\n";
	//cout << "�����, ����������� �� ����� ����� �������: " << time_span_5.count() << " ������" << endl << endl;

	summ_time = summ_time + time_span_5.count();

	middle = middle + 2; // ����������� ������� �������� �� 2, ��� � ����� ������ ������� ��� ������� ���������
	auto start_6 = sc.now(); // ������������� ������ ������� ������� �������
	index_2 = Search_Binary(digits_array, 0, n, middle, har) + 1;  // ������� ������ �������
	auto end_6 = sc.now();       // ������������� ����� ������� ������� �������
	auto time_span_6 = static_cast<chrono::duration<double>>(end_6 - start_6);   // ����������� �����, ����������� �� �������
	//cout << "��������� ����� ��������� � ������ � �������� (������): " << index_2 << "\n\n";
	//cout << "�����, ����������� �� ����� ������ �������: " << time_span_6.count() << " ������" << endl << endl;

	summ_time = summ_time + time_span_5.count();

	//cout << "������� �������� " << (digits_array[0] + digits_array[n - 1]) / 2 << " ��������� � ���������� ������� " << digits_array[index_1] << " .... " << digits_array[index_2] << endl;

	count = 0; // �������� "�������" ��� ���������� �������������
	auto start_7 = sc.now(); // ������������� ������ ������� ������� �������
	for (int i = index_1; i < index_2; i++)
	{
		if (digits_array[i] == (digits_array[0] + digits_array[n - 1]) / 2)
		{
			count++;
		}
	}
	auto end_7 = sc.now();      // ������������� ����� ������� ������� �������
	auto time_span_7 = static_cast<chrono::duration<double>>(end_7 - start_7);   // ����������� �����, ����������� �� �������
	summ_time = summ_time + time_span.count();
	cout << "���������� ��������� ������ �������� �������� ("<< middle - 1 << "): " << count << endl;
	cout << "����� ����������� �� ����� ���������� �������� � ������� (����� �������� �����): " << summ_time << " ������" << endl << endl;

	///// �������� ������ ��������� /////////
	value_a = (digits_array[0] + digits_array[n - 1]) / 2;
	auto start_8 = sc.now(); // ������������� ������ ������� ������� �������
	count = count_if(digits_array, value_a, param = 2);
	auto end_8 = sc.now();     // ������������� ����� ������� ������� �������
	auto time_span_8 = static_cast<chrono::duration<double>>(end_8 - start_8);   // ����������� �����, ����������� �� �������
	cout << "���������� ��������� ������ �������� �������� (" << middle - 1 << "): " << count << endl;
	cout << "����� ����������� �� ����� ���������� �������� � ������� (������ ��������): " << time_span_8.count() << " ������" << endl << endl;
	
																										//---------------- 2 ������� ----------------

	cout << "_________________������� 2_________________" << endl;
	system("pause"); // ������� ����� ������������

	cout << "�������� �������� + ��������� " << endl;
	for (int i = 0; i < n; i++) // ��������� ������ � ��������� �������� (������� �������� = ������� �������� + ��������� (� ������ � ��������� ���������: ��������� �������� = ��������� �������� + ������))
	{
		if (i != n - 1)
			digits_array[i] = digits_array[i] + digits_array[i + 1];
		else
			digits_array[i] = digits_array[i] + digits_array[0];
		cout << digits_array[i] << " ";
	}
	cout << endl;
	system("pause"); // ������� ����� ������������
	cout << endl;
	cout << "�������� ���������� �������" << endl;
	for (int i = 0; numbers_alt_array.size() < n; i++) // ������� ���������� ��������� �������: �������� �������� ����� �� n, �������� � set(���� �������� ����� ���� - �� �������), ���� ����������� ������� ����������, �� �������� ����� � ����� ������
	{
		temp_2 = numbers_alt_array.size(); // ����������� ���������� ����������� �������
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
	system("pause"); // ������� ����� ������������
	cout << endl;
																	//---------------- �����, ����������, ��������, ����� ----------------

	//////�����
	har = 1;
	cout << "������� �����, ������� ������ � �������, ������� � ������, � ����� ������ (��������� ������� - ������: 10, 42, 54, 10000): ";
	key = checkdigit();
	auto start_9 = sc.now(); // ������������� ������ ������� ������� �������
	index_1 = Search_Binary(digits_array, 0, n, key, har);
	if (index_1 >= 0)
		cout << "������� �������� ��������� � ������� �� ������� " << index_1 << endl;
	else
		cout << "�������� �������� ��� � �������!" << endl;
	auto end_9 = sc.now();     // ������������� ����� ������� ������� �������
	auto time_span_9 = static_cast<chrono::duration<double>>(end_9 - start_9);   // ����������� �����, ����������� �� �������
	print_array_color(digits_array, key, n + 1, 0);
	cout << "�����, ����������� �� �����: " << time_span_9.count() << " ������" << endl << endl;


	///// ����������
	system("pause"); // ������� ����� ������������
	cout << "���������� � ������ ����� " << key << endl;
	auto start_10 = sc.now(); // ������������� ������ ������� ������� �������
	digits_array.push_back(key);
	auto end_10 = sc.now();   // ������������� ����� ������� ������� �������
	print_array_color(digits_array, key, n + 1, 1);
	auto time_span_10 = static_cast<chrono::duration<double>>(end_10 - start_10);   // ����������� �����, ����������� �� �������
	cout << endl << "�����, ������������ �� ����������: " << time_span_10.count() << " ������" << endl << endl;


	//// ��������
	system("pause"); // ������� ����� ������������
	cout << "�������� �� ������� ����� " << key << endl;
	auto start_11 = sc.now(); // ������������� ������ ������� ������� �������
	digits_array.pop_back();
	auto end_11 = sc.now();       // ������������� ����� ������� ������� �������
	print_array(digits_array);
	auto time_span_11 = static_cast<chrono::duration<double>>(end_11 - start_11);   // ����������� �����, ����������� �� �������
	cout << endl << "�����, ����������� �� ��������: " << time_span_11.count() << " ������" << endl << endl;


	//// �����
	system("pause"); // ������� ����� ������������
	cout << "����� ��������� �������� ������������� "<< endl;
	cout << "������� ������ ������� �������� (������� ����� �� ����������� ����������� ������� - �� 0 �� "<< n -1 << " )" << endl;
	index_1 = checkdigit();
	cout << "������� ������ ������� �������� (������� ����� �� ����������� ����������� ������� - �� 0 �� " << n - 1 << " )" << endl;
	index_2 = checkdigit();
	auto start_12 = sc.now(); // ������������� ������ ������� ������� �������
	temp_1 = digits_array[index_1];
	digits_array[index_1] = digits_array[index_2];
	digits_array[index_2] = temp_1;
	auto end_12 = sc.now();       // ������������� ����� ������� ������� �������
	print_array_color(digits_array, index_1, index_2, 2);
	auto time_span_12 = static_cast<chrono::duration<double>>(end_12 - start_12);   // ����������� �����, ����������� �� �������
	cout << endl << "�����, ����������� �� �����: " << time_span_12.count() << " ������" << endl << endl;
	system("pause");

	return 0;
}