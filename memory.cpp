#include "memory.h"
#include <gtest/gtest.h>

#include <cstddef>
#include <algorithm>

#include "base64.h"

TEST(TestMemory, TestAlignment)
{
    size_t infoSize = sizeof(Coderleex::Info);
    size_t oneSize = alignof(Coderleex::Info);

    printf("info size: %d, oneSzie: %d", infoSize, oneSize);
    ASSERT_TRUE(infoSize == oneSize * 3); // 3 * 2 %4!=0  then  find 8
}

TEST(TestMemory, TestAlignment2)
{
    size_t infoSize = sizeof(Coderleex::Info2);
    size_t oneSize = alignof(Coderleex::Info2);

    printf("info size: %d, oneSzie: %d", infoSize, oneSize);
    ASSERT_TRUE(infoSize == oneSize * 2); // 3 * 2 %4!=0  then  find 8
}

TEST(TestMemory, TestAlignment3)
{
    size_t infoSize = sizeof(Coderleex::Info3);
    size_t oneSize = alignof(Coderleex::Info3);

    printf("info size: %d, oneSzie: %d", infoSize, oneSize);
    ASSERT_TRUE(infoSize == oneSize * 2); // sizeof(uint32) * 3
}

TEST(TestMemory, TestAlignment4)
{
    size_t infoSize = sizeof(Coderleex::Info4);
    size_t oneSize = alignof(Coderleex::Info4);

    printf("info size: %d, oneSzie: %d", infoSize, oneSize);
    ASSERT_TRUE(infoSize == sizeof(uint32_t) * 3); //  oneSize < sizeof(uint32)  onesize is invaild
}

TEST(TestMemory, TestAlignment5)
{
    size_t infoSize = sizeof(Coderleex::Info5);
    size_t oneSize = alignof(Coderleex::Info5);

    printf("info size: %d, oneSzie: %d", infoSize, oneSize);
    ASSERT_TRUE(infoSize == sizeof(uint32_t) * 3);
}

TEST(TestMemory, TestAlignment6)
{
    size_t infoSize = sizeof(Coderleex::Info6);
    size_t oneSize = alignof(Coderleex::Info6);

    printf("info size: %d, oneSzie: %d", infoSize, oneSize);
    ASSERT_TRUE(infoSize == sizeof(uint32_t) * 2);
}

TEST(TestMemory, TestAlignment7)
{
    size_t infoSize = sizeof(Coderleex::Info7);
    size_t oneSize = alignof(Coderleex::Info7);

    printf("info size: %d, oneSzie: %d", infoSize, oneSize);
    ASSERT_TRUE(infoSize == sizeof(double) * 2);
}

TEST(TestMemory, TestAlignment8)
{
    size_t infoSize = sizeof(Coderleex::Info8);
    size_t oneSize = alignof(Coderleex::Info8);

    printf("info size: %d, oneSzie: %d", infoSize, oneSize);
    ASSERT_TRUE(infoSize == sizeof(double) * 3);
}