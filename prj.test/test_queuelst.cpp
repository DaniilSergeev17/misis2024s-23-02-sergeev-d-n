#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#define DOCTES_CONFIG_THROWS
#include "doctest.h"

#include <queuelst/queuelst.hpp>

TEST_CASE("queuelst existance") {
	QueueLst x;
	CHECK_EQ(x.get_size(), 0);
}

TEST_CASE("queuelst push") {
	Complex a;
	QueueLst queuelst_s;
	queuelst_s.push(a);
	CHECK_EQ(queuelst_s.get_size(), 1);
	queuelst_s.push(a);
	queuelst_s.push(a);
	CHECK_EQ(queuelst_s.get_size(), 3);
}

TEST_CASE("queuelst pop") {
	Complex a;
	QueueLst queuelst_s;
	queuelst_s.push(a);
	queuelst_s.push(a);
	queuelst_s.push(a);
	queuelst_s.pop();
	CHECK_EQ(queuelst_s.get_size(), 2);
}

TEST_CASE("queuelst top") {
	Complex a(3, 3);
	QueueLst queuelst_s;
	queuelst_s.push(a);
	queuelst_s.push(a);
	CHECK_EQ(queuelst_s.top(), a);
	queuelst_s.pop();
	CHECK_EQ(queuelst_s.top(), a);
}

TEST_CASE("queuelst is_empty") {
	QueueLst queuelst_s;
	CHECK_EQ(queuelst_s.is_empty(), true);
}
