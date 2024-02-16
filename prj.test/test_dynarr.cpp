#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#define DOCTES_CONFIG_THROWS
#include "doctest.h"

#include <dynarr/dynarr.hpp>

TEST_CASE("dynarr ctor") {
  DynArr x;
  CHECK_EQ(x.Size(), 0);

  const int size = 5;
  DynArr arr_s(size);
  CHECK_EQ(arr_s.Size(), size);

  CHECK_THROWS(void(DynArr(0)));
  CHECK_THROWS(void(DynArr(-size)));
}

TEST_CASE("dynarr resize") {
  const int size_y = 10;
  DynArr y(size_y);
  y.Resize(5);
  CHECK_EQ(y.Size(), 5);

  y.Resize(7);
  CHECK_EQ(y.Size(), 7);

  y.Resize(15);
  CHECK_EQ(y.Size(), 15);

  CHECK_THROWS(void(y.Resize(-1)));
  CHECK_THROWS(void(y.Resize(0)));
}

TEST_CASE("dynarr op[]") {
  const int size = 5;
  DynArr arr(size);
  CHECK_EQ(arr[0], 0);
  CHECK_EQ(arr[arr.Size() - 1], 0);

  CHECK_THROWS(arr[arr.Size()]);
  CHECK_THROWS(arr[-1]);
}
TEST_CASE("Coping") {
  DynArr x(1);
  x.Resize(5);
  DynArr y(2);
  CHECK_NE(x.Size(), y.Size());

  x = y;
  CHECK_EQ(x.Size(), y.Size());
  CHECK_EQ(x[0], y[0]);

  y.Resize(5);
  CHECK_NE(x.Size(), y.Size());
  CHECK_EQ(x.Size(), 2);

  x.Resize(10);
  CHECK_EQ(y.Size(), 5);
}
/*TEST_CASE("dynarr opp[]") {
  std::ptrdiff_t a = 1;
  std::ptrdiff_t b = 1; 
  std::ptrdiff_t c = 1;
  std::ptrdiff_t d = 1;
  DynArr arr[]={ a, b, c, d };

  CHECK_EQ(arr[0], 1);
}
TEST_CASE("dynarr ssize < 0") {
  CHECK_EQ(arr.ssize()>0);
}


  CHECK_THROWS_AS(void(DynArr(0)));
  CHECK_THROWS_AS(void(DynArr(-size)));
}

TEST_CASE("dynarr op[]") {
  const int size = 5;
  DynArr arr(size);
  CHECK_EQ(arr[0], 0);
  CHECK_EQ(arr[arr.Size() - 1], 0);
  CHECK_THROWS(arr[-1]);
  CHECK_THROWS(arr[arr.Size()]);
}*/