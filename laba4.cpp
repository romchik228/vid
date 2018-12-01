#include "pch.h"
#include <iostream>
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>

using namespace std;

/**
*\brief Функция проверяет вводимое значение пользователем, и пропускает только числа больше нуля.
* Используется в функции main()
*\return Вводимое пользователем значение переменной.
*/
int checkup();
/**
*\brief Функция создает матрицу, в которой записываются оценки студентов,
возвращает указатель на массив указателей.
* Используется в функции main()
*\param[in] students Количество студентов
*\param[in] lessons  Количество предметов
*\param[in] choice   Параметр выбора ввода(1-ввод с консоли, 2- ввод случайных значений)
*\return             Средний балл студента.
*/
int** create(int , int , int );
/**
*\brief Функция считает средний балл выбранного студента и возврщает его.
* Используется в функции main()
*\param[in] mas      Указатель на массив указателей.
*\param[in] students Количество студентов
*\param[in] lessons  Количество предметов
*\param[in] num      Номер студента
*\return             Средний балл студента.
*/
int process1(int** , int , int , int );
/**
*\brief Функция считает количество студентов без троек и возврщает его.
* Используется в функции main()
*\param[in] mas      Указатель на массив указателей.
*\param[in] students Количество студентов
*\param[in] lessons  Количество предметов
*\return             Количество студентов без троек.
*/
int process2(int **, int, int);

int checkup() {
	int i = 0;
	int a = 0;
	char c = '\0';

	while (i == 0) {
		while (scanf_s("%d%c", &a, &c, 1) != 2 || c != '\n') {
			cout << "Ошибка ввода.Введите снова: " << endl;
			while (getchar() != '\n');
		}
		if (a <= 0) {
			cout << "Ошибка ввода. Введите снова: " << endl;
		}
		else {
			i = 1;
		}
	}
	return a;
}

int** create(int a, int b, int c) {
	int **mas = NULL;
	mas = new int *[a];

	for (int i = 0; i < a; i++) {
		mas[i] = new int[b];
	}

	if (c == 1) {
		for (int i = 0; i < a; i++) {
			for (int j = 0; j < b; j++) {
				cout << "array[" << i << "][" << j << "]=" << endl;
				mas[i][j] = checkup();
				if (mas[i][j] < 1 || mas[i][j]>5) {
					cout << "Ошибка ввода. Введите снова: " << endl;
					j--;
				}
			}
		}
	}
	else if (c == 2) {
		for (int i = 0; i < a; i++) {
			for (int j = 0; j < b; j++) {
				mas[i][j] = rand() % 5 + 1;
				cout << "array[" << i << "][" << j << "]=" << mas[i][j] << endl;
			}
		}

	}
	return mas;
}

int process1(int** mas, int a, int b, int num) {
	float result = 0;

	for (int j = 0; j < b; j++) {
		result += (float)mas[num - 1][j];
	}
	result /= b;
	return result;
}

int process2(int **mas, int a, int b) {
	int result = a;
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < b; j++) {
			if (mas[i][j] < 4) {
				result--;
				break;
			}
		}
	}
	return result;
}
void printProcess(int check, int choice, float srbal, int studs, int number)
{
	switch (check) {
	case 0:
		cout << "Вы не ввели массив." << endl;
		system("pause");
		system("cls");
		break;

	case 1:
		cout << "Вы не обработали массив." << endl;
		system("pause");
		system("cls");
		
		break;
	case 2:
		if (choice == 1) cout << "Cреднйи бал " << number << "-ого ученика равен:" << srbal << endl;
		else if (choice == 2) cout << "Количество студентов без троек равно: " << studs << endl;
		system("pause");
		system("cls");
		check = 1;
		
	}
}
int main() {                                  ////////////////////////////////////////////////////////////////////////////////////
	setlocale(LC_ALL, "RUS");

	int **array = NULL;
	char c = '\0';
	int menu = 0;
	int check = 0;
	int choice = 0;
	int size1 = 0;
	int size2 = 0;
	int number = 0;
	int flag = 0;
	int studs = 0;
	float srbal = 0;

	while (menu != 4) {
		cout << "Выберите пункт." << endl;
		cout << "1.Ввод элементов массива." << endl;
		cout << "2.Обработка массива." << endl;
		cout << "3.Вывод результата на экран." << endl;
		cout << "4.Выход." << endl;
		int error = 1;

		while (error == 1) {

			menu = checkup();
			switch (menu) {

			case 1:               /////////////////////////////////////////////////////////////////
				system("cls");
				cout << "Введите кол-во студентов: " << endl;
				size1 = checkup();
				cout << "Введите кол-во предметов: " << endl;
				size2 = checkup();

				system("cls");
				cout << "1.Самостоятельный ввод.\n2.Ввод произвольных значений." << endl;

				choice = checkup();

				while (choice < 1 || choice>2) {
					cout << "Ошибка ввода. Введите снова: " << endl;
					choice = checkup();
				}

				switch (choice) {
				case 1:
					system("cls");
					flag = 1;
					array = create(size1, size2, flag);
					break;
				case 2:
					flag = 2;
					array = create(size1, size2, flag);
					break;
				}
				error = 0;
				check = 1;
				system("pause");
				system("cls");

				break;

			case 2:
				system("cls"); /////////////////////////////////////////////////////////////////////////////////////
				if (check < 1) {
					cout << "Вы не ввели массив." << endl;
					system("pause");
					system("cls");
					error = 0;
					break;
				}
				cout << "1.Найти средний бал студента." << endl;
				cout << "2.Найти количество студентов без троек." << endl;
				choice = 0;
				choice = checkup();

				while (choice < 1 || choice>2) {
					cout << "Ошибка ввода. Введите снова: " << endl;
					choice = checkup();
				}
				
				if (choice == 1) {
					system("cls");
					cout << "Введите номер студента:" << endl;
					number = checkup();
					while (number > size1) {
						cout << "Ошибка ввода. Введите снова: " << endl;
						number = checkup();
					}
					srbal = process1(array, size1, size2, number);
				}
				else if (choice == 2) {
					studs = process2(array, size1, size2);
				}


				system("pause");
				system("cls");
				error = 0;
				check = 2;
				break;


			case 3:
				system("cls");//////////////////////////////////////////////////////////////
				printProcess(check, choice, srbal, studs, number);
				break;


			case 4:
				for (int i = 0; i < size1; i++) {
					delete(array[i]);
				}
				delete(array);
				_CrtDumpMemoryLeaks();
				error = 0;
				break;

			default: cout << "Ошибка ввода. Введите снова: " << endl;

			}

		}

	}
	return 0;
}









