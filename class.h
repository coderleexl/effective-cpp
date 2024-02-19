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
};

class SonCallonFunc : public BaseCallSonFunc
{
private:
    /* data */
public:
    SonCallonFunc(/* args */) = default;
    ~SonCallonFunc() = default;
    virtual void SayHello() final;
};
