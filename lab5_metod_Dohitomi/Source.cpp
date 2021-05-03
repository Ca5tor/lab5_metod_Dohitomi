#include <iostream>
#include <iomanip>

double f(double x) {
	return -cos(2 * x + 1) * log(2 / x) + 3;
}

double D(double a, double b, double E) {
	double x1, x2, f1, f2;
	double d = 0.1 * E, n = 0;

	std::cout << "n\t a\t b\t x1\t x2\t f(x1)\t f(x2)\n\n";

	while (b - a > E) {
		x2 = x1 = (a + b) / 2;
		x1 -= d;
		x2 += d;
		f1 = f(x1);
		f2 = f(x2);

		// Вывод промежуточных результатов
		std::cout << std::setprecision(5) << n << "\t";
		std::cout << a  << "\t" << b  << "\t";
		std::cout << x1 << "\t" << x2 << "\t";
		std::cout << f1 << "\t" << f2 << "\n";

		n++;

		//Если f1 меньше f2 то b = x2 иначе a = x1
		f1 < f2 ? b = x2 : a = x1;
	}
	return ((a + b) / 2);
}

void main() {
	double a = 3.5, b = 4.5, E = 0.0001;
	double x = D(a, b, E);
	double y = f(x);

	std::cout << "\nX= " << x << "\nY= " << y << std::endl;
	std::cin.get();
}