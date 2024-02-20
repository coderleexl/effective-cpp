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

void BaseCallSonFunc::PrintMemory()
{
    printf("BaseCallSonFunc address: %p\n", this);
    printf("BaseCallSonFunc Sizeof: %d\n", *this);
}

void BaseCallSonFunc::NoImplFunc()
{
    printf("BaseCallSonFunc NoImplFunc\n");
}

void **BaseCallSonFunc::GetVtable()
{
    void *objPtr = reinterpret_cast<void *>(this);
    void **vtablePtr = *reinterpret_cast<void ***>(objPtr);
    return vtablePtr;
}

void BaseCallSonFunc::PrintMemoryV2()
{
    void *objPtr = reinterpret_cast<void *>(this);
    void **vtablePtr = *reinterpret_cast<void ***>(objPtr);
    printf("Current vtablePtr address func: %p\n", vtablePtr);

    // 打印虚函数表中的函数指针
    for (int i = 0; vtablePtr[i] != nullptr; ++i)
    {
        // 将函数指针转换为 void* 类型，然后再转换为函数指针类型
        void *funcPtr = reinterpret_cast<void *>(vtablePtr[i]);
        using FunctionPtr = void (*)();
        FunctionPtr func = reinterpret_cast<FunctionPtr>(funcPtr);

        std::cout << "虚函数表索引 " << i << ": ";
        func(); // 调用虚函数

        printf("Current function address func: %p\n", func);
        printf("Current function address funcPtr: %p\n", funcPtr);
        // printf("Current function address *func: %p\n", *func);
    }
}

void SonCallonFunc::SayHello()
{
    printf("Current function address: %p\n", &SonCallonFunc::SayHello);
    void (BaseCallSonFunc::*parentSayPtr)() = &BaseCallSonFunc::SayHello;
    printf("Current function address: %p\n", parentSayPtr);

    printf("Current function address: %p\n", __FUNCTION__);
    std::cout << "Hello, I am Son Class" << std::endl;
}

void SonCallonFunc::PrintMemory()
{
    printf("BaseCallSonFunc address: %p\n", this);
    // printf("BaseCallSonFunc Sizeof: %d\n", sizeof(SonCallonFunc));

    // int k = 100;
    // printf("k address func: %p\n", &k);
    // printf("*k address func: %p\n", *(&k));

    // 这里调用会崩溃 不知道为啥会这里的this不是第一次执行PrintMemoryV2的this地址
    // dynamic_cast<SonCallonFunc *>(this)->PrintMemoryV2();
}

void SonCallonFunc::PrintMemoryV2()
{

    void *objPtr = reinterpret_cast<void *>(this);
    void **vtablePtr = *reinterpret_cast<void ***>(objPtr);
    printf("Current vtablePtr address func: %p\n", vtablePtr);

    // 打印虚函数表中的函数指针
    for (int i = 0; vtablePtr[i] != nullptr; ++i)
    {
        // 将函数指针转换为 void* 类型，然后再转换为函数指针类型
        void *funcPtr = reinterpret_cast<void *>(vtablePtr[i]);
        using FunctionPtr = void (*)();
        FunctionPtr func = reinterpret_cast<FunctionPtr>(funcPtr);

        std::cout << "虚函数表索引 " << i << ": ";
        func(); // 调用虚函数

        printf("Current function address func: %p\n", func);
        printf("Current function address funcPtr: %p\n", funcPtr);
        // printf("Current function address *func: %p\n", *func);
    }
}

void **SonCallonFunc::GetVtable()
{
    void *objPtr = reinterpret_cast<void *>(this);
    void **vtablePtr = *reinterpret_cast<void ***>(objPtr);
    return vtablePtr;
}

void **SonGetVtable::GetVtable()
{
    void *objPtr = reinterpret_cast<void *>(this);
    void **vtablePtr = *reinterpret_cast<void ***>(objPtr);
    return vtablePtr;
}
