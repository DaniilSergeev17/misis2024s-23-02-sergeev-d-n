#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#define DOCTES_CONFIG_THROWS
#include "doctest.h"

#include <stackarr/stackarr.hpp>

TEST_CASE("stackarr existance") {
	StackArr x;
	CHECK_EQ(x.Size(), 0);

	const int size = 5;
	StackArr stackarr_s(size);
	CHECK_EQ(stackarr_s.Size(), 0);

	Complex a(3, 3);
}

TEST_CASE("stackarr push") {
	Complex a;
	StackArr stackarr_s;
	stackarr_s.Push(a);
	CHECK_EQ(stackarr_s.Size(), 1);
	stackarr_s.Push(a);
	stackarr_s.Push(a);
	CHECK_EQ(stackarr_s.Size(), 3);
}

TEST_CASE("stackarr pop") {
	Complex a;
	StackArr stackarr_s;
	stackarr_s.Push(a);
	stackarr_s.Push(a);
	stackarr_s.Push(a);
	stackarr_s.Pop();
	CHECK_EQ(stackarr_s.Size(), 2);
}

TEST_CASE("stackarr top") {
	Complex a(3, 3);
	StackArr stackarr_s;
	stackarr_s.Push(a);
	stackarr_s.Push(a);
	CHECK_EQ(stackarr_s.Top(), a);
	stackarr_s.Pop();
	CHECK_EQ(stackarr_s.Top(), a);
}

TEST_CASE("stackarr is_empty") {
	StackArr stackarr_s;
	CHECK_EQ(stackarr_s.IsEmpty(), true);
}
