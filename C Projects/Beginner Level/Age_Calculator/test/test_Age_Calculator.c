/**
 * @file test_Age_Calculator.c
 * @brief This File Holds the Unit Tests for the Age Calculator C Project
 *
 * @author Ahmed Ashraf (ahmedashraf2022222@gmail.com)
 * @date 3/19/2026
 */

#ifdef TEST

#include "unity.h"

#include "Age_Calculator_interface.h"

TEST_SOURCE_FILE("Age_Calculator.c") // ceedling demands the header and source be named the same , this line only for ceedling
/**
 * Test Cases
 * this project has 3 funcs
 * 1-Calculate_Age
 * 2-Compare_Strings
 * 3-Scan_Date
 * Test cases for Calculate_Age:
 * edge case1: if the birth date is the same as the current date, the age should be 0 years, 0 months, and 0 days. (done)
 * edge case2 : passing a Null pointer to the Age parameter should not cause a crash and should be handled gracefully. (done)
 * Logical case1: if the birth date is before the current date, the age should be calculated correctly. (done)
 * ----------------------------------------------------------------------------------------------------------------------------
 * Test cases for Compare_Strings:
 * edge case1: comparing two empty strings should return a match. (done)
 * edge case2 : Passing a null pointer should return a fail status instead of causing a crash. (done)
 * Logical case1: comparing two identical strings should return a match. (done)
 * Logical case2: comparing two different strings should return a mismatch. (done)
 * ----------------------------------------------------------------------------------------------------------------------------
 * Test cases for Scan_Date:
 * edge case1: entering an invalid date format should be handled gracefully without crashing the program. (done)
 * edge case2 : entering a date with out-of-range values (e.g., month > 12, day > 31) should be handled appropriately. (done)
 * edge case3 : passing a null pointer for either Present_Date or Date_Of_Birth should be handled gracefully.
 * Logical case1: entering a valid date should be processed correctly and stored in the provided structures
 *
 */
void setUp(void)
{
}

void tearDown(void)
{
}

// Tests for Calculate_Age

void test_Calculate_Age_Same_Day_Should_Store_Zero(void)
{
    Date_t today = {15, 8, 2023};
    Date_t birth = {15, 8, 2023};
    Date_t age;

    Calculate_Age(today, birth, &age);

    TEST_ASSERT_EQUAL_UINT8(0, age.Day);
    TEST_ASSERT_EQUAL_UINT8(0, age.Month);
    TEST_ASSERT_EQUAL_UINT16(0, age.Year);
}

void test_calculate_Age_Null_Pointer_Should_Handle_Correctly(void)
{
    Date_t today = {15, 8, 2023};
    Date_t birth = {15, 8, 1990};

    // Passing a null pointer for age
    Calculate_Age(today, birth, NULL);

    // If the function handles it gracefully, it should not crash and we can check for no exceptions
    TEST_PASS();
}

void test_calculate_Age_Birth_Before_Today_Should_Calculate_Correctly(void)
{
    Date_t today = {15, 8, 2023};
    Date_t birth = {10, 5, 1990};
    Date_t age;

    Calculate_Age(today, birth, &age);

    TEST_ASSERT_EQUAL_UINT8(5, age.Day);
    TEST_ASSERT_EQUAL_UINT8(3, age.Month);
    TEST_ASSERT_EQUAL_UINT16(33, age.Year);
}
// Tests for Compare_Strings
void test_Compare_Strings_Empty_Strings_Should_Return_Match(void) // Compare two empty strings should return a match. 
{
    const char *str1 = "";
    const char *str2 = "";

    unsigned char result = Compare_Strings(str1, str2);

    TEST_ASSERT_EQUAL_UINT8(Matches, result);
}

void test_Compare_Strings_Null_Pointer_Should_Return_Fail(void) // Passing a null pointer should return a fail status instead of causing a crash. it fails because the function does not check for null pointers -> Compare_Strings should check for null pointers and return Fail if either is null
{
    const char *str1 = NULL;
    const char *str2 = "Hello";

    unsigned char result = Compare_Strings(str1, str2);

    TEST_ASSERT_EQUAL_UINT8(Fail, result);
}

void test_Compare_Strings_Identical_Strings_Should_Return_Match(void) // comparing two identical strings should return a match. it fails because the function does not handle identical strings correctly -> Compare_Strings should return Matches if the strings are identical
{
    const char *str1 = "Hello, World!";
    const char *str2 = "Hello, World!";

    unsigned char result = Compare_Strings(str1, str2);

    TEST_ASSERT_EQUAL_UINT8(Matches, result);
}
void test_Compare_Strings_Different_Strings_Should_Return_Mismatch(void) // comparing two different strings should return a mismatch. it fails because the function does not handle different strings correctly -> Compare_Strings should return Mismatch if the strings are different
{
    const char *str1 = "Hello, World!";
    const char *str2 = "Hello, Universe!";

    unsigned char result = Compare_Strings(str1, str2);

    TEST_ASSERT_EQUAL_UINT8(Mismatch, result);
}

// Tests for Scan_Date
void test_Scan_Date_Invalid_Format_Should_Handle_Correctly(void) // entering an invalid date format should be handled gracefully without crashing the program. it fails because the function does not handle invalid formats correctly -> Scan_Date should validate the input format and return Fail if it's invalid
{
    Date_t present_date;
    Date_t date_of_birth;

    char result = Scan_Date(&present_date, &date_of_birth);

    TEST_ASSERT_EQUAL_CHAR(Fail, result);
}

void test_Scan_Date_Out_Of_Range_Values_Should_return_Fail(void) // entering a date with out-of-range values (e.g., month > 12, day > 31) should be handled appropriately. it fails because the function does not handle out-of-range values correctly -> Scan_Date should validate the input values and return Fail if they are out of range
{
    Date_t present_date;
    Date_t date_of_birth;

    date_of_birth.Day = 32;    // Invalid day
    date_of_birth.Month = 13;  // Invalid month
    date_of_birth.Year = 2100; // Invalid year
    char result = Scan_Date(&present_date, &date_of_birth);

    TEST_ASSERT_EQUAL_CHAR(Fail, result);
}

void test_Scan_Date_Null_Pointer_Should_Handle_Correctly(void) // passing a null pointer for either Present_Date or Date_Of_Birth should be handled gracefully. it fails because the function does not check for null pointers -> Scan_Date should check for null pointers and return Fail if either is null
{
    Date_t present_date;
    Date_t date_of_birth;

    char result = Scan_Date(NULL, &date_of_birth);

    TEST_ASSERT_EQUAL_CHAR(Fail, result);
}

// for scan_date the logical case of entering a valid date idk how to do it

void test_Scan_Date_Valid_Date_Should_Process_Correctly(void) // entering a valid date should be processed correctly and stored in the provided structures. it fails because the function does not handle valid dates correctly -> Scan_Date should process valid dates and store them in the provided structures
{
    /** @todo Implement test for valid date processing */
}

#endif // TEST
