#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#define DOCTES_CONFIG_THROWS
#include "doctest.h"

#include <stacklst/stacklst.hpp>

TEST_CASE("stacklst existance") {
	StackLst x;
	CHECK_EQ(x.Size(), 0);
}

TEST_CASE("stacklst push") {
	Complex a;
	StackLst stacklst_s;
	stacklst_s.Push(a);
	CHECK_EQ(stacklst_s.Size(), 1);
	stacklst_s.Push(a);
	stacklst_s.Push(a);
	CHECK_EQ(stacklst_s.Size(), 3);
}

TEST_CASE("stacklst pop") {
	Complex a;
	StackLst stacklst_s;
	stacklst_s.Push(a);
	stacklst_s.Push(a);
	stacklst_s.Push(a);
	stacklst_s.Pop();
	CHECK_EQ(stacklst_s.Size(), 2);
}

TEST_CASE("stacklst top") {
	Complex a(3, 3);
	StackLst stacklst_s;
	stacklst_s.Push(a);
	stacklst_s.Push(a);
	CHECK_EQ(stacklst_s.Top(), a);
	stacklst_s.Pop();
	CHECK_EQ(stacklst_s.Top(), a);
}

TEST_CASE("stacklst is_empty") {
	StackLst stacklst_s;
	CHECK_EQ(stacklst_s.IsEmpty(), true);
}
