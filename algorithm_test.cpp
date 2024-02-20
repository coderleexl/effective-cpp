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

TEST(TestAlgorithm, findTargetIn2DPlants)
{
    std::vector<int> vec{2, 3, 6, 8};
    std::vector<int> vec1{4, 5, 8, 9};
    std::vector<int> vec2{5, 9, 10, 12};
    std::vector<std::vector<int>> arr{vec, vec1, vec2};

    std::vector<int> vec3{5};
    std::vector<int> vec4{6};
    std::vector<std::vector<int>> arr1{vec3, vec4};

    ASSERT_TRUE(Algorithm::findTargetIn2DPlants(arr, 11));
    // ASSERT_TRUE(Algorithm::findTargetIn2DPlants(arr1, 6));
}