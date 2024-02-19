#include "algorithm.h"
TEST(TestAlgorithm, TestCountTarget)
{
    printf("TestCountTarget Running\n");
    std::vector<int> vec{2, 2, 3, 4, 4, 4, 5, 6, 6, 8};
    ASSERT_TRUE(Algorithm::countTarget(vec, 4) == 3);
}

TEST(TestAlgorithm, TestQuickSort)
{
    printf("TestQuickSort Running\n");
    std::vector<int> vec{8, 7, 9, 7, 10, 4, 11, 7, 12, 4, 14, 5, 15, 5, 15};
    Algorithm::QuickSort(vec);
    ASSERT_TRUE(vec[0] == 15 && *--vec.end() == 4);
}