#include "algorithm.h"
TEST(Algorithm, CountTarget)
{
    std::vector<int> vec{2, 2, 3, 4, 4, 4, 5, 6, 6, 8};
    ASSERT_TRUE(Algorithm::countTarget(vec, 4) == 3);
}

TEST(Algorithm, QuickSort)
{
    std::vector<int> vec{8, 7, 9, 7, 10, 4, 11, 7, 12, 4, 14, 5, 15, 5, 15};
    Algorithm::QuickSort(vec);
    ASSERT_TRUE(vec[0] == 15 && *--vec.end() == 4);
}

TEST(Algorithm, findTargetIn2DPlants)
{
    std::vector<int> vec{2, 3, 6, 8};
    std::vector<int> vec1{4, 5, 8, 9};
    std::vector<int> vec2{5, 9, 10, 12};
    std::vector<std::vector<int>> arr{vec, vec1, vec2};

    std::vector<int> vec3{5};
    std::vector<int> vec4{6};
    std::vector<std::vector<int>> arr1{vec3, vec4};

    ASSERT_FALSE(Algorithm::findTargetIn2DPlants(arr, 11));
    // ASSERT_TRUE(Algorithm::findTargetIn2DPlants(arr1, 6));
}

TEST(Algorithm, dismantlingAction)
{
    std::string arr1 = "aabbccd";
    std::string arr2 = "aaccddaa";

    ASSERT_TRUE((Algorithm::dismantlingAction(arr1) != ' ') && Algorithm::dismantlingAction(arr2) == ' ');
}

TEST(Algorithm, decorateRecord)
{
    std::vector<std::optional<int>> values = {8, 17, 21, 18, std::nullopt, std::nullopt, 6};
    TreeNode *root = TreeNode::CreateTree(values);
    auto ret = Algorithm::decorateRecord(root);
    std::vector<int> ExpectedResults{8, 17, 21, 18, 6};
    ASSERT_TRUE(ExpectedResults == ret);
}

TEST(Algorithm, decorateRecordV2)
{
    std::vector<std::optional<int>> values = {8, 17, 21, 18, std::nullopt, std::nullopt, 6};
    TreeNode *root = TreeNode::CreateTree(values);
    auto ret = Algorithm::decorateRecordV2(root);
    std::vector<std::vector<int>> ExpectedResults{
        {8}, {17, 21}, {18, 6}};
    ASSERT_TRUE(ExpectedResults == ret);
}

TEST(Algorithm, decorateRecordV3)
{
    std::vector<std::optional<int>> values = {8, 17, 21, 18, std::nullopt, std::nullopt, 6};
    TreeNode *root = TreeNode::CreateTree(values);
    auto ret = Algorithm::decorateRecordV3(root);
    std::vector<std::vector<int>> ExpectedResults{
        {8}, {17, 21}, {6, 18}};
    ASSERT_TRUE(ExpectedResults == ret);
}
TEST(Algorithm, isSubStructure)
{
    std::vector<std::optional<int>> values = {3, 6, 7, 1, 8};
    std::vector<std::optional<int>> values2 = {6, 1};
    std::vector<std::optional<int>> values3 = {1, 6};
    TreeNode *A = TreeNode::CreateTree(values);
    TreeNode *B = TreeNode::CreateTree(values2);
    TreeNode *C = TreeNode::CreateTree(values3);
    ASSERT_TRUE(Algorithm::isSubStructure(A, B) && !Algorithm::isSubStructure(A, C));
}

TEST(Algorithm, CalcFactorial)
{
    ASSERT_TRUE(Algorithm::CalcFactorial(3)==6);
}


TEST(Algorithm, mirrorTree)
{
    std::vector<std::optional<int>> values = {5, 7, 9, 8, 3, 2, 4};
    std::vector<int> values2 = {5, 9, 7, 4, 2, 3, 8};
    TreeNode *root = TreeNode::CreateTree(values);
    // 反转
    root = Algorithm::mirrorTree(root);
    // 广度遍历数组
    auto ret = Algorithm::decorateRecord(root);

    ASSERT_TRUE(ret == values2);
}

TEST(Algorithm, checkSymmetricTree)
{
    std::vector<std::optional<int>> values = {5, 7, 9, 8, 3, 2, 4};
    std::vector<std::optional<int>> values2 = {6, 7, 7, 8, 9, 9, 8};
    TreeNode *root = TreeNode::CreateTree(values);
    TreeNode *root2 = TreeNode::CreateTree(values2);

    ASSERT_TRUE(Algorithm::checkSymmetricTree(root2) && !Algorithm::checkSymmetricTree(root));
}

TEST(Algorithm, fib)
{
    ASSERT_TRUE(Algorithm::fib(2) == 1 && Algorithm::fib(3) == 2 && Algorithm::fib(4) == 3);
}

TEST(Algorithm, bestTiming)
{
    std::vector<int> values = {3, 6, 2, 9, 8, 5};
    std::vector<int> values1 = {8, 12, 15, 7, 3, 10};
    ASSERT_TRUE(Algorithm::bestTiming(values) == 7 && Algorithm::bestTiming(values1));
}