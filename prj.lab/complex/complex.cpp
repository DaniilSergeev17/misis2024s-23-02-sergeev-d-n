#include <complex/complex.hpp>
#include<limits>
#include <iostream>
Complex Complex::operator-() const noexcept {
	return Complex(-re, -im); 
}
 
Complex operator+(const Complex& x, const Complex& y) noexcept {
	return Complex(x) += y;
}
Complex operator+(const Complex& x, const double& y) noexcept {
	return Complex(x) += Complex(y);
}
Complex operator+(const double& x, const Complex& y) noexcept {
	return Complex(x) += Complex(y);
}


Complex operator-(const Complex& x, const Complex& y) noexcept {
	return Complex(x) -= y;
}
Complex operator-(const Complex& x, const double& y) noexcept {
	return Complex(x) -= Complex(y);
}
Complex operator-(const double& x, const Complex& y) noexcept {
	return Complex(x) -= Complex(y);
}

Complex operator*(const Complex& x, const Complex& y) noexcept {
	return Complex(x) *= y;
}
Complex operator*(const Complex& x, const double& y) noexcept {
	return Complex(x) *= Complex(y);
}
Complex operator*(const double& x, const Complex& y) noexcept {
	return Complex(x) *= Complex(y);
}


Complex operator/(const Complex& x, const Complex& y) {
	return Complex(x) /= y;
}
Complex operator/(const Complex& x, const double& y) {
	return Complex(x) /= Complex(y);
}
Complex operator/(const double& x, const Complex& y) {
	return Complex(x) /= Complex(y);
}
Complex::Complex(const double real, const double imaginary) :re(real), im(imaginary) {}
Complex::Complex(const double real) : re(real) {}

Complex& Complex::operator+=(const Complex& x) noexcept {
	re += x.re;
	im += x.im;
	return *this;
}

Complex& Complex::operator+=(const double x) noexcept {
	re += x;
	return *this;
}

Complex& Complex::operator-=(const Complex& x) noexcept {
	re -= x.re;
	im -= x.im;
	return *this;
}
Complex& Complex::operator-=(const double x) noexcept {
	re -= x;
	return *this;
}
Complex& Complex::operator*=(const Complex& x) noexcept {
	double re1(this->re);
	double im1(this->im);

	re = re1 * x.re - im1 * x.im;
	im = re1 * x.im + im1 * x.re;
	return *this;
}
Complex& Complex::operator*=(const double x) noexcept {
	//re *= x;
	//im *= x;
	return (*this *= Complex(x));
}

Complex& Complex::operator/=(const Complex& x) {
	if (x.re*x.re == 0 && x.im*x.im == 0) {
		throw std::exception("Division by zero is not allowed");
	}
	double re1(this->re);
	double im1(this->im);
	re = (re1 * x.re + im1 * x.im) / (x.re * x.re + x.im * x.im);
	im = (im1 * x.re - re1 * x.im) / (x.re * x.re + x.im * x.im);
	return *this;
}
Complex& Complex:: operator/=(const double x) {
	return (*this /= Complex(x));
}
//bool Complex::operator==(const Complex& x) const noexcept {
	//return ((std::abs(re - x.re) <= 2 * std::numeric_limits<double>::epsilon()) && (std::abs(im - x.im) <= 2 * std::numeric_limits<double>::epsilon()));
//}
//bool Complex::operator!=(const Complex& x) const noexcept{
	//return !(operator==(x));
//}
std::ostream& Complex::WriteTo(std::ostream& ostrm) const noexcept{
ostrm << leftBrace << re << separator << im << rightBrace;
return ostrm;
}
std::istream& Complex::ReadFrom(std::istream& istrm) noexcept{ 
	char leftBrace(0);
	double real(0.0);
	char comma(0);
	double imaganary(0.0);
	char rightBrace(0);

	istrm >> leftBrace >> real >> comma >> imaganary >> rightBrace;

	if (istrm.good()) {
		if ((Complex::leftBrace == leftBrace) && (Complex::separator == comma)
			&& (Complex::rightBrace == rightBrace)) {
			re = real;
			im = imaganary;
		}
		else {
			istrm.setstate(std::ios_base::failbit);
		}
	}
	return istrm;
}
