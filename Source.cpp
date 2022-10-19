#include <iostream>
#include "matrix.h"

int main()
{
	setlocale(LC_ALL, "Russian");
	int n;
	std::cin >> n;
	Matrix m1(n), m2(n), m3(n);
	m1.read_random();
	std::cout << m1 << endl;
	m2.read_random();
	std::cout << m2 << endl;

	m3=m1*m2;
	std::cout << "Умножение двух матриц равно:\n" << m3 << endl;

	m3 = m1 + m2;
	std::cout << "Сложение двух матриц равно:\n" << m3 << endl;

	m3 = m1 - m2;
	std::cout << "Вычитание двух матриц равно:\n" << m3 << endl;

	m3 = m1 * 2;
	std::cout << "Умножение матрицы на число равно:\n" << m3 << endl;

	m3 = m2 - 2;
	std::cout << "Вычитание из матрицы числа равно:\n" << m3 << endl;

	m3 = 1 + m2;
	std::cout << "Сложение матрицы и числа равно:\n" << m3 << endl;

	return 0;
}
