#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include <rational/rational.hpp>
#include <sstream>

TEST_CASE("[Rational] - Rational ctor") {
  CHECK(Rational() == Rational(0, 1));
  CHECK(Rational(3) == Rational(3, 1));
  CHECK(Rational(-3) == Rational(-3, 1));
  CHECK(Rational(10, 6) == Rational(5, 3));
  CHECK(Rational(-10, 6) == Rational(-5, 3));
  CHECK(Rational(10, -6) == Rational(-5, 3));
  CHECK(Rational(-10, -6) == Rational(5, 3));
  CHECK_THROWS(Rational(1, 0));
}

TEST_CASE("addsub") {
  CHECK((Rational(1, 2) + Rational(1, 2)) == Rational(1, 1));
  CHECK((Rational(11, 3) + Rational(1, 2)) == Rational(25, 6));
  CHECK((Rational(-8, 3) + Rational(1, 5)) == Rational(-37, 15));
  CHECK((Rational(13, 5) - Rational(1, 2)) == Rational(21, 10));
}

TEST_CASE("multdiv") {
  CHECK((Rational(14, 36) * Rational(81, 193)) == Rational(63, 386));
  CHECK((Rational(13, 36) * Rational(0, 193)) == Rational(0, 1));
  CHECK_THROWS(Rational(64, 95) / Rational(0, 0));
}



TEST_CASE("lessmore") {
  CHECK(Rational(1, 2) > Rational(1, 4));
  CHECK(Rational(-1, 2) < Rational(1, 6));
}

TEST_CASE("[rational] - Rational division") {
  CHECK(Rational(5, 2) / Rational(5, 2) == Rational(1, 1));
  CHECK(Rational(3, 2) / Rational(9, 8) == Rational(4, 3));
  CHECK_THROWS(Rational(3, 2) / Rational(5, 0));
}

TEST_CASE("[rational] - Rational minus") {
  CHECK(-Rational() == Rational());
  CHECK(Rational(-5, 3) == -Rational(5, 3));
  CHECK(Rational(25, 7) == -(-(Rational(25, 7))));
  CHECK(Rational(29, 41) == -Rational(-29, 41));
}

TEST_CASE("[rational] - Rational ctor") {
  CHECK(Rational() == Rational(0, 1));
  CHECK(Rational(3) == Rational(3, 1));
  CHECK(Rational(-3) == Rational(-3, 1));
  CHECK(Rational(10, 6) == Rational(5, 3));
  CHECK(Rational(-10, 6) == Rational(-5, 3));
  CHECK(Rational(10, -6) == Rational(-5, 3));
  CHECK(Rational(-10, -6) == Rational(5, 3));
  CHECK_THROWS(Rational(1, 0));
}
