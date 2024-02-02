#include "algorithm.h"
TEST(TestAlgorithm, TestCountTarget)
{
    printf("TestCountTarget Running\n");
    std::vector<int> vec{2, 2, 3, 4, 4, 4, 5, 6, 6, 8};
    ASSERT_TRUE(Algorithm::countTarget(vec, 4) == 3);
}