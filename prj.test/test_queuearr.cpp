#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#define DOCTES_CONFIG_THROWS
#include "doctest.h"

#include <queuearr/queuearr.hpp>

TEST_CASE("queuearr existance") {
	QueueArr x;
	CHECK_EQ(x.Size(), 0);
}

TEST_CASE("queuearr push") {
	Complex a;
	QueueArr queuearr_s;
	queuearr_s.Push(a);
	CHECK_EQ(queuearr_s.Size(), 1);
	queuearr_s.Push(a);
	queuearr_s.Push(a);
	CHECK_EQ(queuearr_s.Size(), 3);
}

TEST_CASE("queuearr pop") {
	Complex a;
	QueueArr queuearr_s;
	queuearr_s.Push(a);
	queuearr_s.Push(a);
	queuearr_s.Push(a);
	queuearr_s.Pop();
	CHECK_EQ(queuearr_s.Size(), 2);
}

TEST_CASE("queuearr top") {
	Complex a(3, 3);
	QueueArr queuearr_s;
	queuearr_s.Push(a);
	queuearr_s.Push(a);
	CHECK_EQ(queuearr_s.Top(), a);
	queuearr_s.Pop();
	CHECK_EQ(queuearr_s.Top(), a);
}

TEST_CASE("queuearr is_empty") {
	QueueArr queuearr_s;
	CHECK_EQ(queuearr_s.IsEmpty(), true);
}
