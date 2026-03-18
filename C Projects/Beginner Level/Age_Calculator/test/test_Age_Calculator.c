
#ifdef TEST

#include "unity.h"

#include "Age_Calculator_interface.h"


TEST_SOURCE_FILE("Age_Calculator.c") // ceedling demands the header and source be named the same , this line only for ceedling

void setUp(void)
{
}

void tearDown(void)
{
}

void test_Age_Calculator(void)
{
    // Arrange
   uint8_t string1[] = "Hello, World!";
    uint8_t string2[] = "Hello, World!";

    // Act
    uint8_t Result = Compare_Strings(string1, string2);

    // Assert
    TEST_ASSERT_EQUAL_UINT8(1, Result); // Assuming the current year is 2023
}

#endif // TEST
