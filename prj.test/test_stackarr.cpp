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

		
	Complex a(3, 3); // idk how to fix
}

