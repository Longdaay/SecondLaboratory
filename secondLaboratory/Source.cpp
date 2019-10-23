/////////// ����������� �������� � �������� ���������:
//////////	1)	������� ������� ������ ����������� N, ����������� ���������� ������� � ��������� �� 0 �� 99;
/////////	2)	��������� �������� ������� ����������� - ��������� (insertion sort);
////////	3)	������ ������������ � ����������� ������� �������;
///////		4)	������� ���������� ���������, ������ �������� �������� max � min;
//////		5)	������� ���������� ���������, ������� ������ ����� a;
/////		6)	������� ���������� ���������, ������� ������ ����� b;
////		7)	������� �������� ��������, ������� � ������ ��������;
///			9)  ������� ������ ������� ������� ������ �������� �������� �������� � ���������� (��������� = ��������� + ������). ������� ���������� ���������� � ������� �������� ��������� ��������� ����� � �������;
//			8)	������� �������� ������ ��������� �������, ������ �������������.


#include <iostream>
#include <chrono>
#include <vector>
#include <set>

using namespace std;

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

void print_array(vector<int>& digits_array) // ������� ������ �������
{
	for (int i = 0; i < digits_array.size(); i++)
	{
		cout << digits_array[i] << " ";
	}
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
void min_middle_max(vector<int>& digits_array)
{
	// ��������� �����������, ������� � ������������ �������� �������
	cout << "����������� �������� � �������: " << digits_array[0] << endl;
	cout << "������������ �������� � �������: " << digits_array[digits_array.size() - 1] << endl << endl;
	cout << "������� �������� � �������: " << digits_array[digits_array.size() / 2] << endl;
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

	// ������ �������� ����������� �������
	cout << "������� ����������� ������� N (N >= 4, ��������� ������� - ������: 10, 42, 54, 10000)" << endl;
	n = checkdigit();

	vector<int> digits_array(n); // �������� ������ ������
	set <int> numbers_alt_array; // ��������������� ������ ��������� ��� �������� ������� ��������������� �������� ��������
	vector<int> numbers_array; // �������������� ������ �������� ��� ���������� 2-�� �������

	random_array(digits_array); // ��������� �������

	auto start = sc.now();     // ������������� ������ ������� ������� �������
	insertion_sort(digits_array); // ���������� ������� ���������
	auto end = sc.now();       // ������������� ����� ������� ������� �������
	auto time_span = static_cast<chrono::duration<double>>(end - start);   // ����������� �����, ����������� �� �������

	print_array(digits_array); // ������� ��������������� ������
	cout << endl << endl;
	cout << "�����, ����������� �� ����������: " << time_span.count() << " ������" << endl << endl;
	min_middle_max(digits_array); // ������� ������ ���, ����, ��� ��������
	

																////////////////����� ���������� ������� � ������� �������� � ������������ � �������� ������////////////////

	cout << "������� �������� � (������� ���������� ��������� �������, ������� ������ �������� � (��������� ������� - ������: 10, 42, 54, 10000)): "; // ������ �������� 
	min_max_counts(digits_array, param);

	cout << "������� �������� � (������� ���������� ��������� �������, ������� ������ �������� � (��������� ������� - ������: 10, 42, 54, 10000)): "; // ������� �������� ��� �������� ���������� ���������, ����������� �������� ��������
	min_max_counts(digits_array, param = 1); // ���������, ������� �������� ������


																	////////////////������� ���������� ��������� ������ �������� �������� �������////////////////

	middle = (digits_array[0] + digits_array[n - 1]) / 2;
	middle--; // ��������� ������� �������� �� 1, ��� � ����� ����� ������� ��� ������� ���������
	start = sc.now(); // ������������� ������ ������� ������� �������
	index_1 = Search_Binary(digits_array, 0, n, middle, har) - 1; // ������� ����� �������
	end = sc.now();       // ������������� ����� ������� ������� �������
	time_span = static_cast<chrono::duration<double>>(end - start);   // ����������� �����, ����������� �� �������
	//cout << "��������� ����� ��������� � ������ � �������� (�����): " << index_1<< "\n\n";
	//cout << "�����, ����������� �� ����� ����� �������: " << time_span.count() << " ������" << endl << endl;

	summ_time = summ_time + time_span.count();

	middle = middle + 2; // ����������� ������� �������� �� 2, ��� � ����� ������ ������� ��� ������� ���������
	start = sc.now(); // ������������� ������ ������� ������� �������
	index_2 = Search_Binary(digits_array, 0, n, middle, har) + 1;  // ������� ������ �������
	end = sc.now();       // ������������� ����� ������� ������� �������
	time_span = static_cast<chrono::duration<double>>(end - start);   // ����������� �����, ����������� �� �������
	//cout << "��������� ����� ��������� � ������ � �������� (������): " << index_2 << "\n\n";
	//cout << "�����, ����������� �� ����� ������ �������: " << time_span.count() << " ������" << endl << endl;

	summ_time = summ_time + time_span.count();

	//cout << "������� �������� " << (digits_array[0] + digits_array[n - 1]) / 2 << " ��������� � ���������� ������� " << digits_array[index_1] << " .... " << digits_array[index_2] << endl;

	count = 0; // �������� "�������" ��� ���������� �������������
	start = sc.now(); // ������������� ������ ������� ������� �������
	for (int i = index_1; i < index_2; i++)
	{
		if (digits_array[i] == (digits_array[0] + digits_array[n - 1]) / 2)
		{
			count++;
		}
	}
	end = sc.now();      // ������������� ����� ������� ������� �������
	time_span = static_cast<chrono::duration<double>>(end - start);   // ����������� �����, ����������� �� �������
	summ_time = summ_time + time_span.count();
	cout << "���������� ��������� ������ �������� �������� ("<< middle << "): " << count << endl;
	cout << "����� ����������� �� ����� ���������� �������� � ������� (����� �������� �����): " << summ_time << " ������" << endl << endl;

	///// �������� ������ ��������� /////////

	value_a = (digits_array[0] + digits_array[n - 1]) / 2;
	start = sc.now(); // ������������� ������ ������� ������� �������
	count = count_if(digits_array, value_a, param = 2);
	end = sc.now();     // ������������� ����� ������� ������� �������
	time_span = static_cast<chrono::duration<double>>(end - start);   // ����������� �����, ����������� �� �������
	cout << "���������� ��������� ������ �������� �������� (" << middle << "): " << count << endl;
	cout << "����� ����������� �� ����� ���������� �������� � ������� (������ ��������): " << time_span.count() << " ������" << endl << endl;


																										///////////// 2 ������� //////////////

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
																											////////////�����, ����������, ��������, ����� ////////////////
	//////�����
	har = 1;
	cout << "������� �����, ������� ������ � �������, ������� � ������, � ����� ������ (��������� ������� - ������: 10, 42, 54, 10000): ";
	key = checkdigit();
	start = sc.now(); // ������������� ������ ������� ������� �������
	index_1 = Search_Binary(digits_array, 0, n, key, har);
	if (index_1 >= 0)
		cout << "������� �������� ��������� � ������� �� ������� " << index_1 << endl;
	else
		cout << "�������� �������� ��� � �������!" << endl;
	end = sc.now();     // ������������� ����� ������� ������� �������
	time_span = static_cast<chrono::duration<double>>(end - start);   // ����������� �����, ����������� �� �������
	cout << "�����, ����������� �� �����: " << time_span.count() << " ������" << endl << endl;


	///// ����������
	system("pause"); // ������� ����� ������������
	cout << "���������� � ������ ����� " << index_1 << endl;
	start = sc.now(); // ������������� ������ ������� ������� �������
	digits_array.push_back(key);
	end = sc.now();       // end timer (starting & ending is done by measuring the time at the moment the process started & ended respectively)
	print_array(digits_array);
	time_span = static_cast<chrono::duration<double>>(end - start);   // ����������� �����, ����������� �� �������
	cout << endl << "�����, ������������ �� ����������: " << time_span.count() << " ������" << endl << endl;


	//// ��������
	system("pause"); // ������� ����� ������������
	cout << "�������� �� ������� ����� " << index_1 << endl;
	start = sc.now(); // ������������� ������ ������� ������� �������
	digits_array.pop_back();
	end = sc.now();       // ������������� ����� ������� ������� �������
	print_array(digits_array);
	time_span = static_cast<chrono::duration<double>>(end - start);   // ����������� �����, ����������� �� �������
	cout << endl << "�����, ����������� �� ��������: " << time_span.count() << " ������" << endl << endl;

	//// �����
	system("pause"); // ������� ����� ������������
	cout << "����� ��������� �������� ������������� "<< endl;
	cout << "������� ������ ������� �������� (������� ����� �� ����������� ����������� ������� - �� 0 �� "<< n -1 << " )" << endl;
	index_1 = checkdigit();
	cout << "������� ������ ������� �������� (������� ����� �� ����������� ����������� ������� - �� 0 �� " << n - 1 << " )" << endl;
	index_2 = checkdigit();
	start = sc.now(); // ������������� ������ ������� ������� �������
	temp_1 = digits_array[index_1];
	digits_array[index_1] = digits_array[index_2];
	digits_array[index_2] = temp_1;
	end = sc.now();       // ������������� ����� ������� ������� �������
	print_array(digits_array);
	time_span = static_cast<chrono::duration<double>>(end - start);   // ����������� �����, ����������� �� �������
	cout << endl << "�����, ����������� �� �����: " << time_span.count() << " ������" << endl << endl;
	return 0;
}