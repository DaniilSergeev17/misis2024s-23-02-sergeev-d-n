#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#define DOCTES_CONFIG_THROWS
#include "doctest.h"

#include <queuelst/queuelst.hpp>

TEST_CASE("queuelst existance") {
	QueueLst x;
	CHECK_EQ(x.Size(), 0);
}

TEST_CASE("queuelst push") {
	Complex a;
	QueueLst queuelst_s;
	queuelst_s.Push(a);
	CHECK_EQ(queuelst_s.Size(), 1);
	queuelst_s.Push(a);
	queuelst_s.Push(a);
	CHECK_EQ(queuelst_s.Size(), 3);
}

TEST_CASE("queuelst pop") {
	Complex a;
	QueueLst queuelst_s;
	queuelst_s.Push(a);
	queuelst_s.Push(a);
	queuelst_s.Push(a);
	queuelst_s.Pop();
	CHECK_EQ(queuelst_s.Size(), 2);
}

TEST_CASE("queuelst top") {
	Complex a(3, 3);
	QueueLst queuelst_s;
	queuelst_s.Push(a);
	queuelst_s.Push(a);
	CHECK_EQ(queuelst_s.Top(), a);
	queuelst_s.Pop();
	CHECK_EQ(queuelst_s.Top(), a);
}

TEST_CASE("queuelst is_empty") {
	QueueLst queuelst_s;
	CHECK_EQ(queuelst_s.IsEmpty(), true);
}
