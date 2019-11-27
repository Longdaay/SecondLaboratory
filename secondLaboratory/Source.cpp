#include <iostream>
#include <Windows.h>
#include <stdio.h>
#include <conio.h>
#include <vector>
#include <string>
#include <fstream>
#include <ctime>
#include <chrono>

using namespace std;
const int NotUsed = system("color 70");

int m_count = 0;
int t_reg = 0;
string user_name = "������������ N";
int qual = 32;
int qual_ch = 8;

void menu_choice();

void SetColor(int text, int bg) //������� ����� �����, ������ �� ���������
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)((bg << 4) | text));
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

void digit()
{
	vector<int> revers_array(qual);
	int dig = 9894;
	bool result;
	bool counter = false;

	for (int number_of_bit = 0; number_of_bit < qual; number_of_bit++) // ����� ���� ��� ������, ���������� ����� ���� � ���������� ��������� ��������� �������, ��������� 1 ����� ������ ��������
	{
		result = dig & (1U << number_of_bit); // ���������� ����� ����� � ���������� ��� � ����������
		revers_array[number_of_bit] = result; // ���������� � ������ ���������� �������� 
	}
	for (int i = qual - 1; i >= 0; i--)
	{
		if (revers_array[i] == 0 and counter == false) // ��������� ������� ��� �������� �� �������� � ������ � ��� ����� �� �������� ����. ���������� ��� ����, ����� ����� �������� ���� � �������� �� ������
		{
			cout << revers_array[i]; // ����� �������� ����
		}
		else
		{
			counter = true; // ������������� � ������, ��� ������ �������� ������ �������� ������
			SetColor(14, 7); // ������������� ���� ������ � ������
			cout << revers_array[i]; //����� �������� ����
		}
	}
	SetColor(0, 7);
}
void ch_digit(int digit)
{
	vector<int> revers_array(qual_ch);
	bool result;
	bool counter = false;

	for (int number_of_bit = 0; number_of_bit < qual_ch; number_of_bit++) // ����� ���� ��� ������, ���������� ����� ���� � ���������� ��������� ��������� �������, ��������� 1 ����� ������ ��������
	{
		result = digit & (1U << number_of_bit); // ���������� ����� ����� � ���������� ��� � ����������
		revers_array[number_of_bit] = result; // ���������� � ������ ���������� �������� 
	}
	for (int i = qual_ch - 1; i >= 0; i--)
		cout << revers_array[i];
	cout << " ";
}

void second_name()
{
	char ch;
	string s_names = "Leushkin";
	vector<char> s_name;

	for (int i = 0; i < s_names.size(); i++)
		s_name.push_back(s_names[i]);
	for (int i = 0; i < s_name.size(); i++)
		ch_digit((int)(s_name[i]));

}

int checkparam() // ������� �������� ���������� ��������
{
	int par;
	char value[256]; // ����������, ������� ������ ��������� ��������
	cin >> value; // ������ ��������� �������� 
	if (strlen(value) == 1) // ��������� ���������� ��������� ��������. ���� �����, �� ������ ������ ��� ���, ����� �������� ������
	{
		switch (value[0]) // ��������, ���� ������ ������ ���������� value
		{
		case 'y': // ���� �����������
			par = 1;
			return par;
			break;
		case 'n': // ���� ������������
			par = 0;
			return par;
			break;
		default: // ���� ����� �� �������� �� � ������ ��
			cout << "�������� ������� �������. ������� ������" << endl;
			checkparam();
			break;
		}
	}
	else // ���� ������� �������� ������ ������������
	{
		cout << "���������� ������ ���� ������. ���������� ������ ������" << endl;
		checkparam();
	}
}

void registration()
{
	system("cls");
	ofstream fout;
	string s1;
	cout << "�����������" << endl;
	cout << "������� ��� ������������: ";
	fout.open("data.txt");
	getline(cin, s1);
	fout << s1;
	fout << '\n';
	s1.clear();
	cout << "������� ������: ";
	getline(cin, s1);
	fout << s1;
	fout << '\n';
	fout.close();
	cout << "����������� ���������, �����������!" << endl;
	system("pause");
	menu_choice();
}

void sign()
{
	system("cls");
	fstream fin;
	string c;
	vector<char> password;
	char ch;
	int param = 1;
	fin.open("data.txt", ios::in);
	fin.seekg(0, ios::beg);
	fin >> c;
	cout << "����" << endl;
	cout << endl << "������� ��� ������������: ";
	cin >> user_name;
	if (c != user_name)
	{
		cout << "������������ �� ������. ���������� ������ ��� ���" << endl;
		system("pause");
		sign();
	}
	fin >> c;
	cout << "������� ������: ";
	while ((ch = _getch()) != '\r')
	{
		password.push_back(ch);
		_putch('*');
	}
	for (int i = 0; i < c.size(); i++)
	{
		if (c[i] != password[i])
		{
			param = 0;
			break;
		}
	}
	if (param == 1)
	{
		cout << endl << "���� ������� ��������!" << endl;
		t_reg = 1;
	}
	else
	{
		cout << endl << "������ �� ���������. ���������� ������ ��� ���" << endl;
		system("pause");
		sign();
	}
	fin.close();
	system("pause");
}

void say_hello()
{
	system("cls");
	if (t_reg != 1)
	{
		cout << "������, �� �� ��������� ����. ������������ ����������� ��� �������?" << endl;
		cout << "������� � ������ ����? (y/n) ";
		if (checkparam() == 1)
			sign();
	}
	cout << "����������� ����, " << user_name << "! ��� ���� ������, �������, ������������." << endl << endl;
	cout << "��� ��������� ������� ������� ������ 9894 ������� ������. ������, � ������ ����� ���������� ����� ���� ������ �������� ���: ";
	digit();
	cout << ", � ������� ��� ";
	second_name();
	cout << endl;
	system("pause");

	return;
}
void print_array(vector<int> arr)
{
	cout << endl << "__������__" << endl;
	for (int i = 0; i < arr.size(); i++)
		cout << arr[i] << " ";
	cout << endl;
}
void fill_random_mat(vector<int>& arr) // ������� ��� ���������� ���������� ������� � ����������� �� ��� �����������
{
	srand(time(0));
	for (int i = 0; i < arr.size(); i++)
	{
		arr[i] = rand() % 50; // �������� �������� ������� 20
	}
}
void fill_mat(vector<int>& arr) // ������� ��� ������� ���������� ������� � ����������� �� �����������
{
	for (int i = 0; i < arr.size(); i++)
	{
		cout << "arr[" << i << "]= ";
		arr[i] = checkdigit();
	}
}
void fill_mat_via_file(vector<int>& tab_2)
{
	ifstream in("input.txt"); // ��������� ��������� ���������� � ������ �������� ���������� �����. �� ������ ��������� � �������� ��������� ����

	if (in.is_open()) //���� �������� ����� ������ �������
	{
		//������� ��������� ������� ����� � �����
		int count = 0; // ����� ����� � �����
		int temp; //��������� ����������

		//������� ��c��� �� �����
		for (int i = 0; i < tab_2.size(); i++)
			in >> tab_2[i];
		in.close(); //��� ����� ������� �����
	}
	else
	{
		//���� �������� ����� ������ �� �������
		cout << "���� �� ������." << endl;
		cout << "���� �������� �� �������� ��������� ����. �������� ���� ���� � �������� ���������� ��������� " << endl;
		system("pause");
		fill_mat_via_file(tab_2);
	}

}

void choosefill(vector<int>& arr) // ������� ������ ���������� �������
{
	int m;
	char value[256]; // ����������, ������� ������ ��������� ��������
	cin >> value; // ��������� ��������� ��������
	if (strlen(value) == 1) // ��������� ���������� ��������� ��������. ���� �����, �� ������ ������ ��� ���, ����� �������� ������
	{
		switch (value[0]) // ��������, ���� ������ ������ ���������� value
		{
		case '1': // ��������� ����������
			fill_random_mat(arr);
			print_array(arr);
			break;

		case '2': // ������ ����������
			fill_mat(arr);
			print_array(arr);
			break;
		case '3': // ���������� ����� ��������� ����
			fill_mat_via_file(arr);
			print_array(arr);
			break;
		default: // ���� ����� �� �������� �� � ������ ��
			cout << "����� ������� �������. ������� ������" << endl;
			choosefill(arr);
		}
	}
	else // ���� ������� �������� ������ ������������
	{
		cout << "���������� ������ ���� ������. ���������� ������ ������" << endl;
		choosefill(arr);
	}
}

void swap(int* first_p, int* second_p)
{
	int temp = *first_p;
	*first_p = *second_p;
	*second_p = temp;
}

void BubbleSort(vector<int>& arr)
{
	int temp;
	for (int i = 0; i < arr.size() - 1; i++)
		for (int j = 0; j < arr.size() - 1; j++)
			if (arr[j] > arr[j + 1])
			{
				swap(arr[j], arr[j + 1]); // ������ �������, ���� ������� �������� ������ ���������� 
			}
}

void ShakerSort(vector<int>& arr)
{
	int i, j, k;
	int m = arr.size();
	for (i = 0; i < m;) {
		for (j = i + 1; j < m; j++) {
			if (arr[j] < arr[j - 1])
				swap(arr[j], arr[j - 1]);
		}
		m--;
		for (k = m - 1; k > i; k--) {
			if (arr[k] < arr[k - 1])
				swap(arr[k], arr[k - 1]);
		}
		i++;
	}
}

int getNextGap(int gap)
{
	// Shrink gap by Shrink factor 
	gap = (gap * 10) / 13;

	if (gap < 1)
		return 1;
	return gap;
}

void CombSort(vector<int>& arr)
{
	int gap = arr.size();

	// Initialize swapped as true to make sure that 
	// loop runs 
	bool swapped = true;

	// Keep running while gap is more than 1 and last 
	// iteration caused a swap 
	while (gap != 1 || swapped == true)
	{
		// Find next gap 
		gap = getNextGap(gap);

		// Initialize swapped as false so that we can 
		// check if swap happened or not 
		swapped = false;

		// Compare all elements with current gap 
		for (int i = 0; i < arr.size() - gap; i++)
		{
			if (arr[i] > arr[i + gap])
			{
				swap(arr[i], arr[i + gap]);
				swapped = true;
			}
		}
	}
}

void InsertSort(vector<int>& arr)
{
	// ��������� ������ ��������� --  insertion sort
	int min_value;	// ����������, ����������� ����������� �������� ����������� ��������
	int j = 0; // ���������� ����������, �������� ������������ ��� ������ ����� �� i �������� �������
	for (int i = 1; i < arr.size(); i++)
	{
		min_value = arr[i]; // ������ �������� ������������ �������� ������� ������� ������� �������
		j = i - 1; // ������ �������� j �� 1 ������, ��� i, ��� ����, ����� �������� � ���������� ��������� ������� 
		while (j >= 0 and arr[j] > min_value) //���� ������� ������� ������ ����������� � j �� �����������
		{									// ������������� ��������, ����������� ���������� �������� ���������� 
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = min_value; // ����������� ���������� �������� ����������� �������� �������
	}
}

int partition(vector<int> &arr, int low, int high)
{
	int pivot = arr[high];    // pivot
	int i = (low - 1);
	for (int j = low; j <= high - 1; j++)
	{
		//if current element is smaller than pivot, increment the low element
		//swap elements at i and j
		if (arr[j] <= pivot)
		{
			i++;    // increment index of smaller element
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[i + 1], arr[high]);
	return (i + 1);
}

void QuickSort(vector<int>& arr, int low, int high)
{
	if (low < high)
	{
	//partition the array
		int pivot = partition(arr, low, high);

		//sort the sub arrays independently
		QuickSort(arr, low, pivot - 1);
		QuickSort(arr, pivot + 1, high);
	}
}

void choosesort(vector<int>& arr)
{
	chrono::steady_clock sc;   // create an object of `steady_clock` class
	double seconds; // ����������, ������� ������ � ���� ����� ���������� �������

	int m;
	char value[256]; // ����������, ������� ������ ��������� ��������
	cin >> value; // ��������� ��������� ��������

	if (strlen(value) == 1) // ��������� ���������� ��������� ��������. ���� �����, �� ������ ������ ��� ���, ����� �������� ������
	{
		switch (value[0]) // ��������, ���� ������ ������ ���������� value
		{
		case '1': // ���������� ���������
		{
			auto start = sc.now();     // ������������� ������ ������� ������� �������
			BubbleSort(arr);
			auto end = sc.now();       // ������������� ����� ������� ������� �������
			auto time_span = static_cast<chrono::duration<double>>(end - start);   // ����������� �����, ����������� �� �������
			print_array(arr);
			cout << "�����, ����������� �� ���������� ���������: " << time_span.count() << " ������" << endl;
			break;
		}
		case '2': // ���������� ���������
		{
			auto start_1 = sc.now();     // ������������� ������ ������� ������� �������
			ShakerSort(arr);
			auto end_1 = sc.now();       // ������������� ����� ������� ������� �������
			auto time_span_1 = static_cast<chrono::duration<double>>(end_1 - start_1);   // ����������� �����, ����������� �� �������
			print_array(arr);
			cout << "�����, ����������� �� ��������� ����������: " << time_span_1.count() << " ������" << endl;
			break;
		}
		case '3': // ���������� ���������������
		{
			auto start_2 = sc.now();     // ������������� ������ ������� ������� �������
			CombSort(arr);
			auto end_2 = sc.now();       // ������������� ����� ������� ������� �������
			auto time_span_2 = static_cast<chrono::duration<double>>(end_2 - start_2);   // ����������� �����, ����������� �� �������
			print_array(arr);
			cout << "�����, ����������� �� ���������� ���������������: " << time_span_2.count() << " ������" << endl;
			break;
		}
		case '4': // ���������� ���������
		{
			auto start_3 = sc.now();     // ������������� ������ ������� ������� �������
			InsertSort(arr);
			auto end_3 = sc.now();       // ������������� ����� ������� ������� �������
			auto time_span_3 = static_cast<chrono::duration<double>>(end_3 - start_3);   // ����������� �����, ����������� �� �������
			print_array(arr);
			cout << "�����, ����������� �� ���������� ���������: " << time_span_3.count() << " ������" << endl;
			break;
		}
		case '5': // ���������� �������
		{
			auto start_4 = sc.now();     // ������������� ������ ������� ������� �������
			QuickSort(arr, 0, arr.size() - 1);
			auto end_4 = sc.now();       // ������������� ����� ������� ������� �������
			auto time_span_4 = static_cast<chrono::duration<double>>(end_4 - start_4);   // ����������� �����, ����������� �� �������
			print_array(arr);
			cout << "�����, ����������� �� ������� ����������: " << time_span_4.count() << " ������" << endl;
			break;
		}
		default: // ���� ����� �� �������� �� � ������ ��
		{
			cout << "����� ������� �������. ������� ������" << endl;
			choosefill(arr);
			break;
		}
		}
	}
	else // ���� ������� �������� ������ ������������
	{
		cout << "���������� ������ ���� ������. ���������� ������ ������" << endl;
		choosefill(arr);
	}
}
int fib(int digit)
{
	int f1 = 1, f2 = 1, it = 2;
	while (f2 < digit) {
		int tmp = f2;
		f2 += f1;
		f1 = tmp;
		it++;
	}
	if (f2 == digit)
		return 1;
	else
		return -1;
}
void work_array()
{
	system("cls");
	vector<int> arr;
	vector<int> arr_fib;
	int size;
	int n;
	int middle, middle_i, med, mod;
	int tmp;
	int res = 0;
	int max_index = 0;
	int max_value = 0;

	cout << "__������ � ������������� ��������__" << endl << endl;
	cout << "������� ����������� ������� (������������� ����� ��������� ������� - ������: 10, 3, 5): ";
	n = checkdigit();
	arr.resize(n);
	cout << "��� �� ������ ��������� ������ ������:" << endl;
	cout << "1 - �������� ��������� ����� ������ �������� (������ 20)" << endl;
	cout << "2 - �������������� ��������� �������� ��������� �������" << endl;
	cout << "3 - ��������� ������ � ������� ���������� ����� (����������� ������� � ����� ������ ��������� � ��������� ���� ������������)" << endl << endl;
	cout << "������� ����� ������ �� ���������: ";

	choosefill(arr); // ������� ��� ������ �������� ���������� �������

	cout << "����� ����������� �� ������ ������������� ������ ������:" << endl;
	cout << "1 - Bubble Sort" << endl;
	cout << "2 - Shaker Sort" << endl;
	cout << "3 - Comb Sort" << endl;
	cout << "4 - Insert Sort" << endl;
	cout << "5 - Quick Sort" << endl << endl;
	cout << "������� ����� ������ �� ���������: ";

	choosesort(arr);
	/// ���������
	if (arr.size() > 15)
		size = 15;
	else
		size = arr.size();

	for (int i = 0; i < size; i++)
		if (fib(arr[i]) == 1)
		{
			arr_fib.push_back(arr[i]);
		}
	cout << endl << "����� ���������, �������������� � �������";
	print_array(arr_fib);
	
	// ������� �������� �������� �������
	middle = (arr[0] + arr[arr.size() - 1]) / 2;
	cout << endl << "������� �������� �������� ������� = " << middle;
	//������� �������
	middle_i = arr.size() / 2;
	if (arr.size() % 2 == 0)
	{
		med = (arr[middle_i - 1] + arr[middle_i + 1]) / 2;
	}
	else
		med = arr[middle_i];
	cout << endl << "������� ������� = " << med;

	// ���� �������
	int max = arr[0];
	int cmax = 0;
	int rmax = 0;
	for (int i = 0; i < arr.size(); i++) 
	{
		if (cmax > rmax) 
		{
			rmax = cmax;
			max = arr[i - 1];
		}
		cmax = 0;
		for (int j = i; j < arr.size(); j++)
			if (arr[j] == arr[i])
				cmax++;
	}
	//����� ����������� ������
	cout << endl << "���� ������� = " << max << " ����������� � ������� " << rmax << " ���" << endl;

	system("pause");
	return;
}

void print_flag()
{
	system("cls");
	unsigned int n = 10;
	unsigned int m = 30;
	vector<vector <int> > flag(m);
	for (int i = 0; i < m; i++)
	{
		flag[i].resize(n);
		for (int j = 0; j < n; j++)
		{
			flag[i][j] = 0;
		}
	}
	SetColor(0, 7);
	cout << "���� ������ (������� 18)" << endl << endl;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i <= 14 and j >= 5)
			{
				SetColor(4, 4); // ������� ������ ���
				cout << flag[i][j] << " " << '\t';
			}
			else if (i >= 15 and j <= 4)
			{
				SetColor(1, 1);// ����� ����� ���
				cout << flag[i][j] << " " << '\t';
			}
			else if (((j == 1 or j == 3) and (i >= 6 and i <= 8)) or ((i >= 2 and i <= 12) and j == 2))
			{
				SetColor(1, 1); // ����� ���������
				cout << flag[i][j] << " " << '\t';
			}
			else if (((j == 6 or j == 8) and (i >= 21 and i <= 23)) or ((i >= 17 and i <= 27) and j == 7))
			{
				SetColor(4, 4); // ������� ���������
				cout << flag[i][j] << " " << '\t';
			}
			else
			{
				SetColor(7, 7);
				cout << flag[i][j] << " " << '\t';
			}


		}
		cout << endl;
	}
	SetColor(0, 7);

	cout << endl << "���� ���������� ��������� " << endl << endl;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i <= 10)
			{
				SetColor(15, 15);// ,����� ������
				cout << flag[i][j] << " " << '\t';
			}
			else if (i <= 20 and i >= 11)
			{
				SetColor(1, 1);// ����� ������
				cout << flag[i][j] << " " << '\t';
			}
			else
			{
				SetColor(4, 4);// ������� ������
				cout << flag[i][j] << " " << '\t';
			}
		}
		cout << endl;
	}
	SetColor(0, 7);
}

void conf_val()
{
	switch (m_count)
	{
	case 0:
		registration();
		break;
	case 1:
		sign();
		break;
	case 2:
		say_hello();
		break;
	case 3:
		work_array();
		break;
	case 4:
		print_flag();
		break;
	case 5:
		SetColor(7, 7);
		exit(0);
		break;
	default:
		break;
	}
}

void menu()
{
	system("cls");

	if (m_count == 0)
	{
		
		cout.width(15);
		cout << right << "__����__" << endl;
		SetColor(5, 7);
		cout << "�����������" << endl;
		SetColor(0, 7);
		cout << "����" << endl;
		cout << "�����������" << endl;
		cout << "������ � �������������� ���������" << endl;
		cout << "����" << endl;
		cout << "�����" << endl;
		menu_choice();

	}
	if (m_count == 1)
	{
		cout.width(15);
		cout << right << "__����__" << endl;
		cout << "�����������" << endl;
		SetColor(5, 7);
		cout << "����" << endl;
		SetColor(0, 7);
		cout << "�����������" << endl;
		cout << "������ � �������������� ���������" << endl;
		cout << "����" << endl;
		cout << "�����" << endl;
		menu_choice();

	}
	if (m_count == 2)
	{
		cout.width(15);
		cout << right << "__����__" << endl;
		cout << "�����������" << endl;
		cout << "����" << endl;
		SetColor(5, 7);
		cout << "�����������" << endl;
		SetColor(0, 7);
		cout << "������ � �������������� ���������" << endl;
		cout << "����" << endl;
		cout << "�����" << endl;
		menu_choice();

	}
	if (m_count == 3)
	{
		cout.width(15);
		cout << right << "__����__" << endl;
		cout << "�����������" << endl;
		cout << "����" << endl;
		cout << "�����������" << endl;
		SetColor(5, 7);
		cout << "������ � �������������� ���������" << endl;
		SetColor(0, 7);
		cout << "����" << endl;
		cout << "�����" << endl;
		menu_choice();

	}
	if (m_count == 4)
	{
		cout.width(15);
		cout << right << "__����__" << endl;
		cout << "�����������" << endl;
		cout << "����" << endl;
		cout << "�����������" << endl;
		cout << "������ � �������������� ���������" << endl;
		SetColor(5, 7);
		cout << "����" << endl;
		SetColor(0, 7);
		cout << "�����" << endl;
		menu_choice();

	}
	if (m_count == 5)
	{
		cout.width(15);
		cout << right << "__����__" << endl;
		cout << "�����������" << endl;
		cout << "����" << endl;
		cout << "�����������" << endl;
		cout << "������ � �������������� ���������" << endl;
		cout << "����" << endl;
		SetColor(5, 7);
		cout << "�����" << endl;
		SetColor(0, 7);
		menu_choice();

	}
}

void menu_choice()
{
	int k1;
	k1 = _getch();
	if (k1 == 0xE0)
	{
		switch (k1)
		{
		case 0x48: // ������� �����
			m_count--;
			if (m_count < 0) m_count = 0;
			menu();
			break;

		case 0x50: // ������� ����
			m_count++;
			if (m_count > 5) m_count = 5;
			menu();
			break;
		case 0xD: // �����������
			conf_val();
			break;
		default:
			menu_choice();
		}
	}
	switch (k1)
	{
	case 0x48: // ������� �����
		m_count--;
		if (m_count < 0) m_count = 0;
		menu();
		break;

	case 0x50: // ������� ����
		m_count++;
		if (m_count > 5) m_count = 5;
		menu();
		break;
	case 0xD: // �����������
		conf_val();
		break;
	default:
		menu_choice();
	}
}

int main()
{
	setlocale(0, "");

	menu();
	
	cout << "����� �������!." << endl;

	return 0;
}