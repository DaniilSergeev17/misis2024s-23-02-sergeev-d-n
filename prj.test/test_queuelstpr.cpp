#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#define DOCTES_CONFIG_THROWS
#include "doctest.h"

#include <queuelstpr/queuelstpr.hpp>

TEST_CASE("queuelstpr existance") {
	QueueLstPr x;
	CHECK_EQ(x.Size(), 0);
}

TEST_CASE("queuelstpr push") {
	double a(3.4);
	QueueLstPr queuelstpr_s;
	queuelstpr_s.Push(a);
	CHECK_EQ(queuelstpr_s.Size(), 1);
	queuelstpr_s.Push(a);
	queuelstpr_s.Push(a);
	CHECK_EQ(queuelstpr_s.Size(), 3);
}

TEST_CASE("queuelstpr pop") {
	double a(3.4);
	QueueLstPr queuelstpr_s;
	queuelstpr_s.Push(a);
	queuelstpr_s.Push(a);
	queuelstpr_s.Push(a);
	queuelstpr_s.Pop();
	CHECK_EQ(queuelstpr_s.Size(), 2);
}

TEST_CASE("queuelstpr top") {
	double a(3.4);
	double b(2.8);
	QueueLstPr queuelstpr_s;
	queuelstpr_s.Push(a);
	queuelstpr_s.Push(b);
	CHECK_EQ(queuelstpr_s.Top(), b);
	queuelstpr_s.Pop();
	CHECK_EQ(queuelstpr_s.Top(), a);
}

TEST_CASE("queuelstpr is_empty") {
	QueueLstPr queuelstpr_s;
	CHECK_EQ(queuelstpr_s.IsEmpty(), true);
}
