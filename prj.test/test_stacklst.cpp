#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#define DOCTES_CONFIG_THROWS
#include "doctest.h"

#include <stacklst/stacklst.hpp>

TEST_CASE("stacklst existance") {
	StackLst x;
	CHECK_EQ(x.get_size(), 0);
}

TEST_CASE("stacklst push") {
	Complex a;
	StackLst stacklst_s;
	stacklst_s.push(a);
	CHECK_EQ(stacklst_s.get_size(), 1);
	stacklst_s.push(a);
	stacklst_s.push(a);
	CHECK_EQ(stacklst_s.get_size(), 3);
}

TEST_CASE("stacklst pop") {
	Complex a;
	StackLst stacklst_s;
	stacklst_s.push(a);
	stacklst_s.push(a);
	stacklst_s.push(a);
	stacklst_s.pop();
	CHECK_EQ(stacklst_s.get_size(), 2);
}

TEST_CASE("stacklst top") {
	Complex a; // how to fix it: Complex a(3, 3)
	StackLst stacklst_s;
	stacklst_s.push(a);
	stacklst_s.push(a);
	//CHECK_EQ(stacklst_s.top(), a);
	stacklst_s.pop();
	//CHECK_EQ(stacklst_s.top(), a);
}

TEST_CASE("stacklst is_empty") {
	StackLst stacklst_s;
	CHECK_EQ(stacklst_s.is_empty(), true);
}
