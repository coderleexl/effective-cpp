#include <iostream>
#include <gtest/gtest.h>

#include "const.h"
#include "memory.h"
#include "algorithm.h"

int main(int argc, char **argv)
{
    std::cout << "Hello, from effective-cpp!\n";
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
