#include<iostream>
#include<sstream>
#include<limits>
#include <complex/complex.hpp>
void TestAdd(Complex x, Complex y, double z) {
	std::cout << x << "-=" << y << ":";
	x -= y;
	std::cout << x << std::endl;
	std::cout << x << " - " << y << " = " << (x - y) << std::endl;
	std::cout << y << " - " << z << " = " << (y - z) << std::endl;
	std::cout << z << " - " << x << " = " << (z - x) << std::endl;
}
void TestSub(Complex x, Complex y, double z) {
	std::cout << x << " -= " << y << ": ";
	x -= y;
	std::cout << x << std::endl;
	std::cout << x << " - " << y << " = " << (x - y) << std::endl;
	std::cout << y << " - " << z << " = " << (y - z) << std::endl;
	std::cout << z << " - " << x << " = " << (z - x) << std::endl;
}
void TestMul(Complex x, Complex y, double z) {
	std::cout << x << " *= " << y << ": ";
	x *= y;
	std::cout << x << std::endl;
	std::cout << x << " * " << y << " = " << (x * y) << std::endl;
	std::cout << y << " * " << z << " = " << (y * z) << std::endl;
	std::cout << z << " * " << x << " = " << (z * x) << std::endl;
}

void TestDiv(Complex x, Complex y, double z) {
	std::cout << x << " /= " << y << ": ";
	if (y == Complex(0)) {
		std::cout << "Denominator can't be zero" << '\n';
	}
	else {
		x /= y;
		std::cout << x << '\n';
	}

	std::cout << x << " / " << y << " = ";
	if (y == Complex(0)) {
		std::cout << "Denominator can't be zero" << '\n';
	}
	else {
		std::cout << (x / y) << '\n';
	}

	std::cout << y << " / " << z << " = ";
	if (z == 0) {
		std::cout << "Denominator can't be zero" << '\n';
	}
	else {
		std::cout << (y / z) << '\n';
	}

	std::cout << z << " / " << x << " = ";
	if (y == Complex(0)) {
		std::cout << "Denominator can't be zero" << '\n';
	}
	else {
		std::cout << (z / x) << '\n';
	}
}
void TestComparison(Complex x, Complex y,  double z) {
	if (x == y) {
		std::cout << x << "=" << y << std::endl;
	}
	else {
		std::cout << x << "!=" << y << std::endl;
	}
	double delta_zx = abs(z - x.re);
	if (delta_zx <= std::numeric_limits<float>::epsilon() && x.im==0) {
		std::cout << x << "=" << z << std::endl;
	}
	else {
		std::cout << x << "!=" << z << std::endl;
	}
	double delta_zy = abs(z - y.re);
	if (delta_zy <= std::numeric_limits<float>::epsilon() && x.im == 0) {
		std::cout << y << "=" << z << std::endl;
	}
	else {
		std::cout << y << "!=" << z << std::endl;
	}
}
int main() {
	Complex x(3, 1);
	Complex y(7, 3);
	double z = 3;
	std::cout << "Addition test: " << std::endl;
	TestAdd(x, y, z);
	std::cout << std::endl;
	std::cout << "Subtraction test: " << std::endl;
	TestSub(x, y, z);
	std::cout << std::endl;
	std::cout << "Multiplication test: " << std::endl;
	TestMul(x, y, z);
	std::cout << std::endl;
	std::cout << "Division test: " << std::endl;
	TestDiv(x, y, z);
	std::cout << std::endl;
	//y{3, 0};
	std::cout << "Comparison test :" << std::endl;
	TestComparison(x, y, z);
}
