#include "variant.h"
class CostEstimate
{
    // c++17
    // static inline const double FudgeFactor = 1.35;

    // C++11
protected:
    static const double FudgeFactor;
};

class GamePlayer : public CostEstimate
{
    enum
    {
        NumTurns = 5,
    };

    int scores[NumTurns];

    // int scores[] bad
    char className[]; // good
};

class TextBlock
{
public:
    TextBlock(const char *text)
    {
        this->text = text;
    }
    // const override
    const char &
    operator[](std::size_t position) const
    {
        return text[position];
    }

    // call   const char &operator[](std::size_t position) const
    char &operator[](std::size_t position)
    {
        return const_cast<char &>(static_cast<const TextBlock &>(*this)[position]);
    }

private:
    std::string text;
    char *pText;
};

class CTextBlock
{
public:
    CTextBlock(const char *text)
    {
        pText = new char[strlen(text) + 1];
        memcpy(pText, text, strlen(text) + 1);
    }
    // const override
    char &operator[](std::size_t position) const
    {
        return pText[position];
    }
    ~CTextBlock()
    {
        if (pText)
        {
            delete[] pText;
        }
    }

private:
    char *pText;
};

#define CALL_WITH_MAX(a, b) funcPrint((a) > (b) ? (a) : (b))