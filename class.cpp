#include "class.h"

CPrivateDestructor::CPrivateDestructor(const char *str)
{
    m_pStr = new char[256];
    strcpy(m_pStr, str);
}

CPrivateDestructor::~CPrivateDestructor()
{
    delete[] m_pStr;
}

BaseCallSonFunc::BaseCallSonFunc()
{
}

void BaseCallSonFunc::SayHello()
{
    std::cout << "Hello, I am Base Class" << std::endl;
}

void SonCallonFunc::SayHello()
{
    printf("Current function address: %p\n", &SonCallonFunc::SayHello);
    void (BaseCallSonFunc::*parentSayPtr)() = &BaseCallSonFunc::SayHello;
    printf("Current function address: %p\n", parentSayPtr);

    printf("Current function address: %p\n", __FUNCTION__);
    std::cout << "Hello, I am Son Class" << std::endl;
}
