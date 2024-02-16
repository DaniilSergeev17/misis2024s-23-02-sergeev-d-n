#ifndef COMPLEX_COMPLEX_HPP
#define COMPLEX_COMPLEX_HPP
#include <iostream>
#include <sstream>

struct Complex{
	double re{ 0.0 };
	double im{ 0.0 };
	[[nodiscard]] Complex operator-() const noexcept;
	[[nodiscard]] Complex(const Complex&) = default;
	[[nodiscard]] Complex(const double real, const double imaginary);
	[[nodiscard]] explicit Complex(const double real);
	[[nodiscard]] Complex() = default;
	 ~Complex() = default;
	[[nodiscard]] bool operator==(const Complex& x) const noexcept {
		return ((std::abs(re - x.re) <= 2 * std::numeric_limits<double>::epsilon()) && (std::abs(im - x.im) <= 2 * std::numeric_limits<double>::epsilon()));
	}
	[[nodiscard]] bool operator!=(const Complex& x) const noexcept {
		return !(operator==(x));
	}
	
Complex& operator=(const Complex&) = default;
Complex& operator+=(const Complex& x) noexcept;
Complex& operator+=(const double x) noexcept;
Complex& operator-=(const Complex& x) noexcept;
Complex& operator-=(const double x) noexcept;
Complex& operator*=(const Complex& x) noexcept;
Complex& operator*=(const double x) noexcept;
Complex& operator/=(const Complex& x);
Complex& operator/=(const double x);
[[nodiscard]] std::ostream& WriteTo(std::ostream& ostrm) const noexcept;
[[nodiscard]] std::istream& ReadFrom(std::istream& istrm) noexcept;
static const char leftBrace{ '{' };
static const char separator{ ',' };
static const char rightBrace{ '}' };
};
inline std::ostream& operator<<(std::ostream& ostrm, const Complex& rhs) noexcept  {
	return rhs.WriteTo(ostrm);
}
inline std::istream& operator>>(std::istream& istrm, Complex& rhs) noexcept {
	return rhs.ReadFrom(istrm);
}

[[nodiscard]] Complex operator+(const Complex& x, const Complex& y) noexcept;
[[nodiscard]] Complex operator+(const Complex& x, const double& y) noexcept;
[[nodiscard]] Complex operator+(const double& x, const Complex& y) noexcept;

[[nodiscard]] Complex operator-(const Complex& x, const Complex& y) noexcept;
[[nodiscard]] Complex operator-(const Complex& x, const double& y) noexcept;
[[nodiscard]] Complex operator-(const double& x, const Complex& y) noexcept;

[[nodiscard]] Complex operator*(const Complex& x, const Complex& y) noexcept;
[[nodiscard]] Complex operator*(const Complex& x, const double& y) noexcept;
[[nodiscard]] Complex operator*(const double& x, const Complex& y) noexcept;

[[nodiscard]] Complex operator/(const Complex& x, const Complex& y);
[[nodiscard]] Complex operator/(const Complex& x, const double& y);
[[nodiscard]] Complex operator/(const double& x, const Complex& y);

#endif
