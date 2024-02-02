#include "const.h"
const double CostEstimate::FudgeFactor = 1.35;

TEST(TestConst, TestDefine)
{
    int a = 5, b = 0;
    // ++a < b  ++a exec two times
    CALL_WITH_MAX(++a, b);
    // std::cout << "a=" << a << std::endl;
    //  ++a > b  ++a exec one times
    CALL_WITH_MAX(++a, b + 10);
    // std::cout << "a=" << a << std::endl;
    ASSERT_TRUE(a == 5 + 3);
}

TEST(TestConst, TestIterator)
{
    std::vector<int> vec{0, 1, 2};
    const auto iter = vec.begin();
    // bad iter const ++iter;
    *iter = 10; // good

    auto const_iter = vec.cbegin();
    // bad *const_iter = 20;
    ++const_iter; // good
}

TEST(TestConst, TestConstFuncOverride)
{
    TextBlock tb("Hello");
    // funcPrint(tb[0]);

    const TextBlock ctb("World");
    // funcPrint(tb[0]);

    const auto &crtb = tb;
    // funcPrint(crtb[0]);
}

TEST(TestConst, TestBitWiseConst)
{
    CTextBlock ctb("Hello");
    // std::cout << ctb[0] << std::endl;
    char *pc = &ctb[0];
    *pc = 'J';
    // std::cout << ctb[0] << std::endl;
    ASSERT_TRUE(true);
}
