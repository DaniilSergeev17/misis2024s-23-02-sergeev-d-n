#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#define DOCTES_CONFIG_THROWS
#include "doctest.h"

#include <stackarr/stackarr.hpp>

TEST_CASE("stackarr existance") {
	StackArr x;
	CHECK_EQ(x.get_size(), 0);

	const int size = 5;
	StackArr stackarr_s(size);
	CHECK_EQ(stackarr_s.get_size(), 0);

		
	Complex a(3, 3);
}

TEST_CASE("stackarr push") {
	Complex a;
	StackArr stackarr_s;
	stackarr_s.push(a);
	CHECK_EQ(stackarr_s.get_size(), 1);
	stackarr_s.push(a);
	stackarr_s.push(a);
	CHECK_EQ(stackarr_s.get_size(), 3);
}

TEST_CASE("stackarr pop") {
	Complex a;
	StackArr stackarr_s;
	stackarr_s.push(a);
	stackarr_s.push(a);
	stackarr_s.push(a);
	stackarr_s.pop();
	CHECK_EQ(stackarr_s.get_size(), 2);
}

TEST_CASE("stackarr top") {
	Complex a(3, 3);
	StackArr stackarr_s;
	stackarr_s.push(a);
	stackarr_s.push(a);
	CHECK_EQ(stackarr_s.top(), a);
	stackarr_s.pop();
	CHECK_EQ(stackarr_s.top(), a);
}

TEST_CASE("stackarr is_empty") {
	StackArr stackarr_s;
	CHECK_EQ(stackarr_s.is_empty(), true);
}
