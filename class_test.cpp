#include "class.h"

#define TEST_CPrivateDestructor
#ifdef TEST_CPrivateDestructor
TEST(TestClass, TestCPrivateDestructor)
{
    // error
    // CPrivateDestructor cc;

    CPrivateDestructor *pC = new CPrivateDestructor("123");
    pC->Destroy();
    ASSERT_TRUE(true);
}
#endif

TEST(TestClass, TestBaseCallSonFunc)
{
    BaseCallSonFunc *pC = new SonCallonFunc;
    pC->SayHello();
    ASSERT_TRUE(true);
}