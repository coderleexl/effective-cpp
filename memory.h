#include "variant.h"

namespace Coderleex
{
    struct Info
    {
        uint8_t a;
        uint16_t b;
        uint8_t c;
    };
    struct alignas(4) Info2
    {
        uint8_t a;
        uint16_t b;
        uint8_t c;
    };
    struct Info3
    {
        uint8_t a;
        uint8_t c;
        uint32_t b;
    };
    struct alignas(2) Info4
    {
        uint8_t a;
        uint32_t b;
        uint8_t c;
    };
    struct Info5
    {
        uint8_t a;
        uint32_t b;
        uint8_t c;
    };
    struct Info6
    {
        uint32_t b;
        uint8_t c;
        uint8_t a;
    };
    struct Info7
    {
        char b;
        int c;
        double a;
    };
    struct Info8
    {
        char b;
        double a;
        int c;
    };
}