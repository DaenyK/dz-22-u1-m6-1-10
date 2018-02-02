#include <stdio.h>
#include <locale.h>
#include <iostream>
#include <stdint.h>
#include <time.h>

using namespace std;

int q;

void ShiftRight3(int*a, int *b, int *c);

void ShiftLeft3(int*a, int *b, int *c);

int IsLeapYear(int year);

int MonthDays(int month, int year);

void PrevDate(int year, int month, int day);

void NextDate(int year, int month, int day);


double f(double x, double y);

double F(double x1, double y1, double x2, double y2);

int ff(int m2, int m1, int m0);

int Altitudes(int xA, int yA, int xB, int yB, int xC, int yC);

void main()

{
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));

	int nz;

	do
	{
		cout << "Введите номер задания: ";
		cin >> nz;
		switch (nz)
		{
		case 1:
		{
			cout << "Описать процедуру ShiftRight3(A, B, C), выполняющую правый циклический" << endl
				<< "сдвиг: значение A переходит в B, значение B — в C, значение C — в A " << endl
				<< "(A, B, C — вещественные параметры, являющиеся одновременно входными " << endl
				<< "и выходными). С помощью этой процедуры выполнить правый циклический " << endl
				<< "сдвиг для двух данных наборов из трех чисел: (A1, B1, C1) и (A2, B2, C2).\n\n";

			int a = rand() % 50, b = rand() % 50, c = rand() % 50;
			cout << "значения будут сгенерированы рандомно:\n";
			cout << "a = " << a << "; b = " << b << "; c = " << c << endl;
			cout << "\nпосле действия функции: \n";

			ShiftRight3(&a, &b, &c);
			cout << "a = " << a << "; b = " << b << "; c = " << c << endl << endl;


		}break;

		case 2:
		{
			cout << "Описать процедуру ShiftLeft3(A, B, C), выполняющую левый циклический" << endl
				<< "сдвиг : значение A переходит в C, значение C — в B, значение B — в A" << endl
				<< "(A, B, C — вещественные параметры, являющиеся одновременно входными" << endl
				<< "и выходными).С помощью этой процедуры выполнить левый циклический" << endl
				<< "сдвиг для двух данных наборов из трех чисел : (A1, B1, C1) и(A2, B2, C2).\n\n";

			int a = rand() % 50, b = rand() % 50, c = rand() % 50;
			cout << "значения будут сгенерированы рандомно:\n";
			cout << "a = " << a << "; b = " << b << "; c = " << c << endl;
			cout << "\nпосле действия функции: \n";

			ShiftLeft3(&a, &b, &c);
			cout << "a = " << a << "; b = " << b << "; c = " << c << endl << endl;
		}break;

		case 3:
		{
			cout << "Описать функцию IsLeapYear(Y) логического типа, которая возвращает True," << endl
				<< "если год Y(целое положительное число) является високосным, и False" << endl
				<< "в противном случае.Вывести значение функции IsLeapYear для пяти данных " << endl
				<< "значений параметра Y.Високосным считается год, делящийся на 4, за" << endl
				<< "исключением тех годов, которые делятся на 100 и не делятся на 400.\n\n";
			int y;
			do
			{
				cout << "введите год для того, чтобы узнать является ли он високосным: ";
				cin >> y;
			} while (y < 1);


			IsLeapYear(y);
			if (IsLeapYear(y) == 1)
				cout << "true\n\n";
			else
				cout << "false\n\n";

		}break;

		case 4:
		{
			cout << "Используя функцию IsLeapYear из задания 3, описать функцию MonthDays(M, Y)" << endl
				<< "целого типа, которая возвращает количество дней для M - го месяца года Y" << endl
				<< "(1 ≤ M ≤ 12, Y > 0 — целые числа).Вывести значение функции MonthDays для" << endl
				<< "данного года Y и месяцев M1, M2, M3.\n\n";
			int month, year;
			do {
				cout << "Введите год: ";
				cin >> year;
			} while (year < 1);
			do {
				cout << "Введите номер месяца (1-12): ";
				cin >> month;
			} while ((month < 1) || (month > 12));

			cout << "кол-во дней: " << MonthDays(month, year) << endl;
		}break;

		case 5:
		{
			cout << "Используя функцию MonthDays из задания 4, описать процедуру" << endl
				<< "PrevDate(D, M, Y), которая по информации о правильной дате, " << endl
				<< "включаю - щей день D, номер месяца M и год Y, определяет предыдущую " << endl
				<< "дату(пара - метры целого типа D, M, Y являются одновременно входными" << endl
				<< "и выходными).Применить процедуру PrevDate к трем исходным датам и " << endl
				<< "вывести полученные значения предыдущих дат\n\n";

			int month, year, day;
			do
			{
				cout << "Введите год: ";
				cin >> year;
			} while (year < 1);

			do
			{
				cout << "Введите месяц: ";
				cin >> month;
			} while ((month < 1) || (month > 12));

			if (month == 4 || month == 6 || month == 9 || month == 11)
			{
				do
				{
					cout << "Введите день: ";
					cin >> day;
				} while ((day < 1) || (day > 30));
			}

			if ((month == 2) && (IsLeapYear(year) == 1))
			{
				do
				{
					cout << "Введите день: ";
					cin >> day;
				} while ((day < 1) || (day > 29));
			}
			else if ((month == 2) && (IsLeapYear(year) == 0))
			{
				do
				{
					cout << "Введите день: ";
					cin >> day;
				} while ((day < 1) || (day > 28));
			}

			else
			{
				do
				{
					cout << "Введите день: ";
					cin >> day;
				} while ((day < 1) || (day > 31));
			}
			PrevDate(year, month, day);

		}break;

		case 6:
		{
			cout << "Используя функцию MonthDays из задания 4, описать процедуру" << endl
				<< "NextDate(D, M, Y), которая по информации о правильной дате, " << endl
				<< "включаю - щей день D, номер месяца M и год Y, определяет следующую " << endl
				<< "дату(пара - метры целого типа D, M, Y являются одновременно входными" << endl
				<< "и выходными).Применить процедуру NextDate к трем исходным датам и " << endl
				<< "вывести полученные значения следующих \n\n";


			int month, year, day;
			do
			{
				cout << "Введите год: ";
				cin >> year;
			} while (year < 1);

			do
			{
				cout << "Введите месяц: ";
				cin >> month;
			} while ((month < 1) || (month > 12));

			if (month == 4 || month == 6 || month == 9 || month == 11)
			{
				do
				{
					cout << "Введите день: ";
					cin >> day;
				} while ((day < 1) || (day > 30));
			}

			if ((month == 2) && (IsLeapYear(year) == 1))
			{
				do
				{
					cout << "Введите день: ";
					cin >> day;
				} while ((day < 1) || (day > 29));
			}
			else if ((month == 2) && (IsLeapYear(year) == 0))
			{
				do
				{
					cout << "Введите день: ";
					cin >> day;
				} while ((day < 1) || (day > 28));
			}

			else
			{
				do
				{
					cout << "Введите день: ";
					cin >> day;
				} while ((day < 1) || (day > 31));
			}

			NextDate(year, month, day);
		}break;

		case 7:
		{
			cout << "Используя функцию Dist из задания Proc59, описать процедуру" << endl
				<< "Altitudes(xA, yA, xB, yB, xC, yC, hA, hB, hC), находящую высоты " << endl
				<< "hA, hB, hC треугольника ABC(выходные параметры), проведенные " << endl
				<< "соответственно из вершин A, B, C(их координаты являются входными " << endl
				<< "параметрами).С помощью этой процедуры найти высоты треугольников " << endl
				<< "ABC, ABD, ACD, если даны координаты точек A, B, C, D.\n\n"; 

			//в этом задании везде использовала int, чтобы не было длинных цифр

			int xa = -15 + rand() % 12, ya = 3 + rand() % 12;
			int xb = -15 + rand() % 12, yb = -15 + rand() % 12;
			int xc = 3 + rand() % 12, yc = 3 + rand() % 12;
			int xd = 3 + rand() % 12, yd = -15 + rand() % 12;
			cout << "координаты точек будут сгенерированы рандомно: " << endl
				<< "A(" << xa << "," << ya << "); \n"
				<< "B(" << xb << "," << yb << ");\n"
				<< "C(" << xc << "," << yc << "); \n"
				<< "D(" << xd << "," << yd << ");\n\n";

			cout << "высоты для треугольника ABC\n";
			Altitudes(xa, ya, xb, yb, xc, yc);

			cout << "высоты для треугольника ABD\n";
			Altitudes(xa, ya, xb, yb, xd, yd);

			cout << "высоты для треугольника ACD\n";
			Altitudes(xa, ya, xc, yc, xd, yd);

		}break;

		case 8:
		{
			cout << "Определите функцию double f(double x, double y), которая вычисляет" << endl
				<< "и возвращает длину гипотенузы прямоугольного треугольника, две другие" << endl
				<< "стороны x и y которого известны\n\n";

			double x = 5 + rand() % 5, y = 6 + rand() % 5;
			cout << "стороны будут сгенерированы рандомно: " << x << " и " << y << endl << endl;
			f(x, y);

		}break;

		case 9:
		{
			cout << "Напишите функцию double f(double x1, double y1, double x2, double y2)," << endl
				<< "которая вычисляет расстояние между двумя точками(xl, yl) и(x2, y2)\n\n";
			double x1 = -5 + rand() % 11, y1 = -5 + rand() % 11;
			double x2 = -5 + rand() % 11, y2 = -5 + rand() % 11;
			cout << "координаты точек будут сгенерированы рандомно: " << endl
				<< "A(" << x1 << "," << y1 << "); " << "B(" << x2 << "," << y2 << ");\n\n";

			F(x1, y1, x2, y2);

		}break;

		case 10:
		{
			cout << "Напишите функцию int f(int m2, int m1, int m0), которая вычисляет" << endl
				<< "и возвращает натуральное число, первая (сотни), вторая (десятки) " << endl
				<< "и третья (единицы) цифры которого равны соответственно m2, m1, m0\n\n";
			int a = 1 + rand() % 9, b = 1 + rand() % 9, c = rand() % 9;
			cout << "значения будут сгенерированы рандомно: " << a << ", " << b << ", " << c << "\n\n";
			ff(a, b, c);

		}break;

		}


		cout << "Хотите продолжить 1/0?";
		cin >> q;


		switch (q)
		{
		case 1:
			system("cls");
			break;
		default:
		{
			cout << "ошибка" << endl;
		}
		}
	} while (nz > 0);


}

void ShiftRight3(int*a, int *b, int *c)
{
	int z = *c;
	*c = *b;
	*b = *a;
	*a = z;
}

void ShiftLeft3(int*a, int *b, int *c)
{
	//значение A переходит в C, значение C — в B, значение B — в A
	int z = *a;
	*a = *b;
	*b = *c;
	*c = z;
}

int IsLeapYear(int year)
{
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
		return 1;
	else
		return 0;
}

int MonthDays(int month, int year)
{
	if (month == 4 || month == 6 || month == 9 || month == 11)
		return 30;
	else if (month == 2)
	{
		if (IsLeapYear(year) == 1)
			return 29;
		else
			return 28;
	}
	else
		return 31;
}

void PrevDate(int year, int month, int day)
{
	if (day == 1)
	{
		if (day == 1 && month == 1)
			year = year - 1;
		if (month == 1)
			month = 12;
		else
			month = month - 1;

		day = MonthDays(month, year);

	}
	else
		day = day - 1;

	cout << "дата предыдущего дня(ДД.ММ.ГГГГ): " << day << "." << month << "." << year << endl;
}

void NextDate(int year, int month, int day)
{
	if (day == 31 && month == 12)
	{
		year = year + 1;
		day = 1;
		month = 1;
	}
	else if (month == 4 || month == 6 || month == 9 || month == 11)
	{
		if (day == 30)
		{
			day = 1;
			month = month + 1;
		}
		else
			day = day + 1;

	}
	else if (month == 2)
	{
		if (IsLeapYear(year) == 1)
		{
			if (day == 28)
				day = day + 1;

			else if (day == 29)
			{
				day = 1;
				month = month + 1;
			}
		}
		else if (IsLeapYear(year) == 0)
		{
			if (day == 28)
			{
				day = 1;
				month = month + 1;
			}
		}
	}

	else
	{
		if (day == 31)
		{
			day = 1;
			month = month + 1;
		}
		else
			day = day + 1;
	}

	cout << "дата следующего дня(ДД.ММ.ГГГГ): " << day << "." << month << "." << year << endl;
}


double f(double x, double y)
{
	cout << "длина гипотенузы треугольника составляет: " << sqrt(x*x + y*y) << "см\n\n";
	return 0;
}

double F(double x1, double y1, double x2, double y2)
{
	cout << "расстояние между точками составляет: " << sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2)) << " см\n\n";
	return 0;
}

int ff(int m2, int m1, int m0)
{
	cout << "итоговое число: " << m2 * 100 + m1 * 10 + m0 << endl << endl;
	return 0;
}

int Altitudes(int xA, int yA, int xB, int yB, int xC, int yC)
{
	//для начала найти длину каждой стороны
	//sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2))
	int C = sqrt(pow((xB - xA), 2) + pow((yB - yA), 2)); //длина ab точка напротив C
	int A = sqrt(pow((xC - xB), 2) + pow((yC - yB), 2)); //длина bc точка напротив А
	int B = sqrt(pow((xA - xC), 2) + pow((yA - yC), 2)); //длина ca точка напротив B
	
	int p = (C + A + B)/2; // находим длину половины периметра для того, чтобы дальше
	                             // использовать в формуле для нахождения высоты треугольника

	int hA = (2 * (sqrt(p*(p - A)*(p - B)*(p - C)))) / A; // высота, опущенная на сторону А
	int hB = (2 * (sqrt(p*(p - A)*(p - B)*(p - C)))) / B; // высота, опущенная на сторону B
	int hC = (2 * (sqrt(p*(p - A)*(p - B)*(p - C)))) / C; // высота, опущенная на сторону C
	cout << "высоты треугольника: " << hA << ", " << hB << ", " << hC << "\n\n";

	if ((hA == 0) || (hB == 0) || (hC == 0))
		cout << "высота равна нулю, так как рандомный треугольник вышел сплющенным (Т-Т) \n\n";

	return 0;
}