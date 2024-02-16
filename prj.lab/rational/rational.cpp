#include <rational/rational.hpp>

#include <algorithm>
#include <iostream>
#include <stdexcept>

int Rational::NOD(int64_t a, int64_t b) {
  a = std::abs(a);
  b = std::abs(b);
  if (a == b || a == 0) {
    return b;
  }
  if (a > b) {
    return NOD(a - b, b);
  }
  return NOD(a, b - a);
}

Rational& Rational::round() {
  if (den_ < 0) {
    num_ *= -1;
    den_ *= -1;
  }
  int nod = Rational::NOD(num_, den_);
  num_ /= nod;
  den_ /= nod;
  return *this;
}

bool Rational::operator==(const Rational& rhs) const {
  return (num_ == rhs.num_ && den_ == rhs.den_);
}

bool Rational::operator!=(const Rational& rhs) const {
  return !operator==(rhs);
}

Rational::Rational(const int64_t num, const int64_t den) {
  if (den == 0)
    throw std::invalid_argument("Creating Rational with 0 denum");
  num_ = num;
  den_ = den;
  round();
}

Rational::Rational(const int64_t rhs) {
  num_ = rhs;
  den_ = 1;
  round();
}

Rational::Rational(const Rational& rhs) {
  num_ = rhs.num_;
  den_ = rhs.den_;
  round();
}

bool Rational::operator>(const Rational& rhs) const {
  if (num_* rhs.num_ < 0) {
    return num_ > 0;
  }
  return num_ * rhs.den_ > rhs.num_ * den_;
}

bool Rational::operator<(const Rational& rhs) const {
  if (num_ * rhs.num_ < 0) {
    return num_ < 0;
  }
  return num_ * rhs.den_ < rhs.num_ * den_;
}

Rational& Rational::operator+=(const Rational& rhs) {
  int nod = NOD(den_, rhs.den_);
  num_ = (num_ * rhs.den_) / nod + rhs.num_ * den_ / nod;
  den_ = (den_ * rhs.den_) / nod;
  round();
  return *this;
}

Rational& Rational::operator-=(const Rational& rhs) {
  int nod = NOD(den_, rhs.den_);
  num_ = (num_ * rhs.den_) / nod - rhs.num_ * den_ / nod;
  den_ = (den_ * rhs.den_) / nod;
  this->round();
  return *this;
}

Rational& Rational::operator*= (const Rational& rhs) {
  num_ *= rhs.num_;
  den_ *= rhs.den_;
  this->round();
  return *this;
}

Rational& Rational::operator/= (const Rational& rhs) {
  den_ *= rhs.num_;
  if (den_ == 0 || rhs.den_ == 0) {
    throw std::invalid_argument("division by zero");
  }
  num_ *= rhs.den_;
  this->round();
  return *this;
}

Rational Rational::operator-() {
  return Rational(-num_, den_);
}

std::ostream& operator<< (std::ostream& ostrm, const Rational& rhs)
{
  return rhs.writeTo(ostrm);
}
std::istream& operator>> (std::istream& istrm, Rational& rhs)
{
  return rhs.readFrom(istrm);
}
std::ostream& Rational::writeTo(std::ostream& ostrm) const
{
  ostrm << num_ << slash << den_;
  return ostrm;
}
std::istream& Rational::readFrom(std::istream& istrm)
{
  int64_t num1(0);
  char slash(0);
  int64_t den1(1);
  istrm >> num1;
  istrm.get(slash);
  int trash = istrm.peek();
  istrm >> den1;
  if (!istrm || trash > '9' || trash < '0') {
    istrm.setstate(std::ios_base::failbit);
    return istrm;
  }
  if (istrm.good() || istrm.eof()) {
    if (Rational::slash == slash && den1 > 0) {
      *this = Rational(num1, den1);
    } else {
      istrm.setstate(std::ios_base::failbit);
    }
  }
  return istrm;
}
