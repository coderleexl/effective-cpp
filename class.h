#include "variant.h"

class CPrivateDestructor
{
public:
    explicit CPrivateDestructor(const char *str);
    inline void Destroy()
    {
        delete this;
    }

private:
    ~CPrivateDestructor();

private:
    char *m_pStr;
};

class BaseCallSonFunc
{
private:
    /* data */
public:
    BaseCallSonFunc(/* args */);
    ~BaseCallSonFunc() = default;
    virtual void SayHello();
    virtual void PrintMemory();
    virtual void NoImplFunc();
    void **GetVtable();

    void PrintMemoryV2();
};

class SonCallonFunc : public BaseCallSonFunc
{
private:
    /* data */
public:
    SonCallonFunc(/* args */) = default;
    ~SonCallonFunc() = default;
    virtual void SayHello() final;
    virtual void PrintMemory() final;
    void PrintMemoryV2();
    void **GetVtable();
};

class SonGetVtable : public BaseCallSonFunc
{
private:
    /* data */
public:
    SonGetVtable(/* args */) = default;
    ~SonGetVtable() = default;

    void **GetVtable();
};
