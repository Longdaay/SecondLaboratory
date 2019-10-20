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

int main()
{
	setlocale(0, "");
	unsigned short n; // ����������, ������� ������ ����������� �������;
	int temp; // ����������, �������, �� ����� ���������� �������, ������ ��������� �������� ��������
	int min_value; // ����������, ������� ��������� ����������� �������� �� ����� ����������
	int j = 0; // ���������� ����������, ������� ������������ ��� ������ ����� �� i �������� �������
	short value_a; // ����������, � ������� ������������ ������ �������� ��� ��������
	int count = 0; // ����������, ������� ������ ���������� ����� ��������������� �������
	chrono::steady_clock sc;   // create an object of `steady_clock` class
	int index_1 = 0;
	int index_2 = 0;
	int middle = 0;
	double seconds; // ����������, ������� ������ � ���� ����� ���������� �������
	int key = 0;
	bool har = 0;
	
	// ������ �������� ����������� �������
	cout << "������� ����������� ������� N" << endl;
	cin >> n;
	vector<int> digits_array(n);
	vector<int> numbers_array(n);
	// ������� ������������ ������
	/*cout << endl << "������������ ������:" << endl;
	// 
	srand(time(0)); // ������������� ������������ ������������� �������� � �������� ����������. �������� �� ���� � ���� ��������� ��������� �����, ������� ��� ������ ������� ��������� ����� ������. ��������� rand() ������ ��� ������������ ��������� �����

	for (int i = 0; i < n; i++) // ���� ��� ��������� ���� � ������ �
	{
		digits_array[i] = rand() % 100; // ���������� ������� ������� � �������� �������� � �������� �� 0 �� 99
		cout << digits_array[i] << " "; // ������� ����� ������
	}
	cout << endl << "����������!" << endl << endl;
	cout << "��������������� ������: " << endl;
	auto start = sc.now();     // start timer // ������������� ������ ������� ������� �������
	// ��������� ������ ��������� insertion sort
	for (int i = 1; i < n; i++)
	{
		min_value = digits_array[i]; // ������ �������� ������������ �������� ������� ������� ������� �������
		j = i - 1; // ������ �������� j �� 1 ������, ��� i, ��� ����, ����� �������� � ���������� ���������� ������� 
		while (j >= 0 and digits_array[j] > min_value) //���� ������� ������� ������ ����������� � j �� ��������� ������������� ��������, ����������� ������������ �������� ���������� ???
		{
			digits_array[j + 1] = digits_array[j];
			j = j - 1;
		}
		digits_array[j + 1] = min_value; // ����������� ???
	}
// ������������� ����� ������� ������� �������
// ����������� �������� �����, ����������� �� ���������� �������
	auto end = sc.now();       // end timer (starting & ending is done by measuring the time at the moment the process started & ended respectively)
	auto time_span = static_cast<chrono::duration<double>>(end - start);   // measure time span between start & end
	// ������� ��������������� ������
	for (int i = 0; i < n; i++)
	{
		cout << digits_array[i] << " ";
	}
	cout << endl << endl;
	cout << "�����, ����������� �� ����������: " << time_span.count() << " ������" << endl << endl;
	// ��������� ����������� � ������������ �������� �������
	cout << "manimum value in array: " << digits_array[0] << endl;
	cout << "maximum value in array: " << digits_array[n - 1] << endl << endl;
	cout << "medium value: " << digits_array[digits_array.size()/2] << endl;
	cout << "medium value (min + max) / 2: " << (digits_array[0] + digits_array[n - 1]) / 2 << endl;
	*/
	cout << "������ ������: " << endl;
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
	////////////////������� � ������� �������� � �������� ��������
	/*
	// ������ �������� ��� �������� ���������� ��������� �������, �� ����������� �������� ��������
	cout << "������� �������� � (������� ���������� ��������� �������, ������� ������ �������� �): ";
	cin >> value_a; // ������� ������ �� ������
	for (int i = 0; i < n; i++) // ��������� ���� ������ � ������������ ���������� ���������
	{
		if (digits_array[i] < value_a)
		{
			count++;
		}
	}
	// ������� ���������� ����������
	cout << "���������� ��������� < " << value_a << ": " << count << endl;

	// ������ �������� ��� �������� ���������� ���������, ����������� �������� ��������
	cout << "������� �������� � (������� ���������� ��������� �������, ������� ������ �������� �): ";

	cin >> value_a; // ���������� ����� � ����
	count = 0; // �������� "�������" ��� ���������� ������������� 
	for (int i = 0; i < n; i++) // ��������� ���� ������ � ������������ ���������� ���������
	{
		if (digits_array[i] > value_a)
		{
			count++;
		}
	}
	// ������� ���������� ����������
	cout << "���������� ��������� > " << value_a << ": " << count << endl;






	//////////////////// ������� ���������� �������� �������� ����� �������
	*/
	/*middle = (digits_array[0] + digits_array[n - 1]) / 2;
	middle--;
	start = sc.now();
	index_1 = Search_Binary(digits_array, 0, n, middle, har) - 1;
	end = sc.now();       // end timer (starting & ending is done by measuring the time at the moment the process started & ended respectively)
	time_span = static_cast<chrono::duration<double>>(end - start);   // measure time span between start & end
	cout << "��������� ����� ��������� � ������ � �������� (�����): " << index_1<< "\n\n";
	cout << "�����, ����������� �� �����: " << time_span.count() << " ������" << endl << endl;
	middle = middle + 2;
	 start = sc.now();
	index_2 = Search_Binary(digits_array, 0, n, middle, har) + 1 ;
	end = sc.now();       // end timer (starting & ending is done by measuring the time at the moment the process started & ended respectively)
	time_span = static_cast<chrono::duration<double>>(end - start);   // measure time span between start & end
	cout << "��������� ����� ��������� � ������ � �������� (������): " << index_2 << "\n\n";
	cout << "�����, ����������� �� �����: " << time_span.count() << " ������" << endl << endl;

	cout << "������� �������� " << (digits_array[0] + digits_array[n - 1]) / 2 << " ��������� � ���������� ������� " << digits_array[index_1] << " .... " << digits_array[index_2] << endl;
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
	cout << "���������� ���������, ������ �������� ��������: " << count << endl;
	cout << "�����, ����������� �� ����� ���������� ������� �������� � ������� (����� �������� �����): " << time_span.count() << " ������" << endl << endl;








	///// �������� ������ ��������
	count = 0; // �������� "�������" ��� ���������� �������������
	start = sc.now();
	for (int i = 0; i < n; i++) // ��������� ���� ������ � ������������ ���������� ���������
	{
		if (digits_array[i] == (digits_array[0] + digits_array[n - 1]) / 2)
		{
			count++;
		}
	}
	end = sc.now();       // end timer (starting & ending is done by measuring the time at the moment the process started & ended respectively)
	time_span = static_cast<chrono::duration<double>>(end - start);   // measure time span between start & end
	cout << "���������� ���������, ������ �������� ��������: " << count << endl;
	cout << "�����, ����������� �� ����� ���������� ������� �������� � ������� (������ ��������): " << time_span.count() << " ������" << endl << endl;
	/////// �������� ������ ��������
	// ��� � ������ ��������� ��������������� ����� �������� �������, ���� �������� ������ ���������� ������� � ���������� �, ���� �� �� ��������, �� ������������ ������ 
	*/

	/*

	///////////// 2 zadanie //////////////
	cout << "_________________������ 2_________________" << endl;
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
	cout << "�������� ���������� " << endl;
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
	////////////�����, �������, �������� ////////////////
	//////�����
	har = 1;
	cout << "������� �����, ������� ������ � �������, ������� � ������ � ������: ";
	cin >> key;
	start = sc.now();
	index_1 = Search_Binary(digits_array, 0, n, key, har);
	if (index_1 >= 0)
		cout << "������� �������� ��������� � ������� �� ������� " << index_1 << endl;
	else
		cout << "�������� �������� ��� � �������!" << endl;
	end = sc.now();       // end timer (starting & ending is done by measuring the time at the moment the process started & ended respectively)
	time_span = static_cast<chrono::duration<double>>(end - start);   // measure time span between start & end
	cout << "�����, ����������� �� ����� �����: " << time_span.count() << " ������" << endl << endl;
	///// �������
	
	start = sc.now();
	digits_array.push_back(key);
	end = sc.now();       // end timer (starting & ending is done by measuring the time at the moment the process started & ended respectively)
	for (int i = 0; i < digits_array.size(); i++)
	{
		cout << digits_array[i] << " ";
	}
	time_span = static_cast<chrono::duration<double>>(end - start);   // measure time span between start & end
	cout << endl << "�����, ����������� �� ���������� �����: " << time_span.count() << " ������" << endl << endl;

	//// ��������
	start = sc.now();
	digits_array.pop_back();
	end = sc.now();       // end timer (starting & ending is done by measuring the time at the moment the process started & ended respectively)
	for (int i = 0; i < digits_array.size(); i++)
	{
		cout << digits_array[i] << " ";
	}
	time_span = static_cast<chrono::duration<double>>(end - start);   // measure time span between start & end
	cout << endl << "�����, ����������� �� �������� �����: " << time_span.count() << " ������" << endl << endl;
	*/
	return 0;
}