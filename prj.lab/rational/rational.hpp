#ifndef RATIONAL_HPP
#define RATIONAL_HPP

#include <iosfwd>
#include <cstdint>

class Rational {
public:
  Rational() = default;
  explicit Rational(const int64_t rhs);
  Rational(const Rational& rhs);
  Rational(const int64_t num, const int64_t den);
  Rational& operator=(const Rational& rhs) = default;
  ~Rational() = default;

  bool operator==(const Rational& rhs) const;
  bool operator!=(const Rational& rhs) const;
  bool operator>(const Rational& rhs) const;
  bool operator<(const Rational& rhs) const;

  Rational& operator+=(const Rational& rhs);
  Rational& operator+=(const int64_t rhs) {
    return operator+= (Rational(rhs));
  }

  Rational& operator-=(const Rational& rhs);
  Rational& operator-=(const int64_t rhs) {
    return operator-= (Rational(rhs));
  }

  Rational& operator*= (const Rational& rhs);
  Rational& operator*= (const int64_t rhs) {
    return operator*= (Rational(rhs));
  }

  Rational& operator/= (const Rational& rhs);
  Rational& operator/= (const int64_t rhs) {
    return operator/= (Rational(rhs));
  }

  std::ostream& writeTo(std::ostream& ostrm) const;
  std::istream& readFrom(std::istream& istrm);

  Rational operator-();

private:
  int64_t num_{ 0 };
  int64_t den_{ 1 };

  static const char slash{ '/' };

  int NOD(int64_t a, int64_t b);
  Rational& round();
};

inline Rational operator+ (const Rational& lhs, const Rational& rhs) { //inline 
  return Rational(lhs) += rhs;
}

inline Rational operator+ (const Rational& lhs, const int64_t rhs) {
  return Rational(lhs) + Rational(rhs);
}

inline Rational operator+ (const int64_t lhs, const Rational& rhs) {
  return Rational(lhs) + Rational(rhs);
}

inline Rational operator- (const Rational& lhs, const Rational& rhs) {
  return Rational(lhs) -= rhs;
}
inline Rational operator- (const Rational& lhs, const int64_t rhs) {
  return Rational(lhs) - Rational(rhs);
}
inline Rational operator- (const int64_t lhs, const Rational& rhs) {
  return Rational(lhs) - Rational(rhs);
}

inline Rational operator* (const Rational& lhs, const Rational& rhs) {
  return Rational(lhs) *= rhs;
}
inline Rational operator* (const Rational& lhs, const int64_t rhs) {
  return Rational(lhs) * Rational(rhs);
}
inline Rational operator* (const int64_t lhs, const Rational& rhs) {
  return Rational(lhs) * Rational(rhs);
}

inline Rational operator/ (const Rational& lhs, const Rational& rhs) {
  return Rational(lhs) /= rhs;
}
inline Rational operator/ (const Rational& lhs, const int64_t rhs) {
  return Rational(lhs) / Rational(rhs);
}
inline Rational operator/ (const int64_t lhs, const Rational& rhs) {
  return Rational(lhs) / Rational(rhs);
}

std::ostream& operator<<(std::ostream& ostrm, const Rational& rhs);
std::istream& operator>>(std::istream& istrm, Rational& rhs);

#endif
