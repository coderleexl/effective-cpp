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

TEST(TestClass, TestPrintMemory)
{
    BaseCallSonFunc *pC = new SonCallonFunc;

    BaseCallSonFunc *pBase = new BaseCallSonFunc;
    SonCallonFunc *pSonImpl = new SonCallonFunc;
    SonGetVtable *pSonNotImpl = new SonGetVtable;
    // pC->PrintMemory();

    auto pS = dynamic_cast<SonCallonFunc *>(pC);

    if (!pS)
    {
        ASSERT_TRUE(false);
    }

    pS->PrintMemoryV2();
    pSonImpl->PrintMemoryV2();

    auto BaseVPtr = *reinterpret_cast<void ***>(pBase);
    auto SonImplPtr = *reinterpret_cast<void ***>(pSonImpl);
    auto SonNoImplPtr = *reinterpret_cast<void ***>(pSonNotImpl);
    ASSERT_TRUE(true);
}