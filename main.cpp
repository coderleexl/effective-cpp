#include <iostream>
#include <gtest/gtest.h>

#include "const.h"
#include "memory.h"
#include "algorithm.h"
#include "class.h"

int main(int argc, char** argv)
{
	std::cout << "Hello, from effective-cpp!\n";
	::testing::InitGoogleTest(&argc, argv);
	(void)RUN_ALL_TESTS();

#ifdef _WIN32
	system("pause");
#endif // _WIN32

	return 0;
}
