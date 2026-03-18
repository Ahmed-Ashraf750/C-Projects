/**
 * @file Age_Calculator.c
 * @brief This File Holds the implementation Program Of an Age Calculator C Project
 * This program calculates the age of a person based on their birth year and the current year.
 * It takes the birth year and current year as input from the user and then computes the age
 * This Project Shall use Least amount of memory and be as fast as possible
 * @author Ahmed Ashraf
 * @date 3/7/2026
 * @note This Project Counts Month As 30 Days For simplicity and does not account for leap years or varying month lengths
 */

#include <stdio.h>
#include "../inc/Age_Calculator_interface.h"

/**
 * @fn Calculate_Age
 * @brief This Function calculates the age of a person based on their birth date and the current date
 * @param Today_Date A Date_t structure that holds the current date (day, month, year)
 * @param Birth_Date A Date_t structure that holds the birth date of the person (day, month, year)
 * @param Age A pointer to a Date_t structure where the calculated age will be stored (day, month, year)
 */

void Calculate_Age(Date_t Today_Date, Date_t Birth_Date, Date_t *Age)
{

    if (Today_Date.Day < Birth_Date.Day)
    {
        Today_Date.Month -= 1;
        Today_Date.Day += Max_Days_Per_Month;
    }
    if (Today_Date.Month < Birth_Date.Month)
    {
        Today_Date.Year -= 1;
        Today_Date.Month += Max_Months_Per_Year;
    }
    Age->Day = Today_Date.Day - Birth_Date.Day;
    Age->Month = Today_Date.Month - Birth_Date.Month;
    Age->Year = Today_Date.Year - Birth_Date.Year;
}

unsigned char Compare_Strings(const char *str1, const char *str2)
{
    if (*str1 == Null || *str2 == Null)
    {
        return Fail;
    }

    while (*str1 == *str2)
    {
        if (*str1 == NullChar)
        {
            return Matches;
        }
        else
        {
            str1++;
            str2++;
        }
    }
    return Mismatch;
}

char Scan_Date(Date_t *Present_Date, Date_t *Date_Of_Birth)
{
    printf("Enter the current date (day month year): ");
    scanf("%hhu %hhu %hu", &Present_Date->Day, &Present_Date->Month, &Present_Date->Year);
    if (Present_Date->Day > Max_Days_Per_Month || Present_Date->Day < Zero)
    {
        printf("Invalid Day. Please enter a value between 1 and %d.\n", Max_Days_Per_Month);
        return Fail;
    }

    if (Present_Date->Month > Max_Months_Per_Year || Present_Date->Month < Zero)
    {
        printf("Invalid Month. Please enter a value between 1 and %d.\n", Max_Months_Per_Year);
        return Fail;
    }

    if (Present_Date->Year < Least_Valid_Year)
    {
        printf("Invalid Year. Please enter a value greater than or equal to %d.\n", Least_Valid_Year);
        return Fail;
    }
    printf("Enter your birth date (day month year): ");
    scanf("%hhu %hhu %hu", &Date_Of_Birth->Day, &Date_Of_Birth->Month, &Date_Of_Birth->Year);
    if (Date_Of_Birth->Day > Max_Days_Per_Month || Date_Of_Birth->Day < Zero)
    {
        printf("Invalid Day. Please enter a value between 1 and %d.\n", Max_Days_Per_Month);
        return Fail;
    }
    if (Date_Of_Birth->Month > Max_Months_Per_Year || Date_Of_Birth->Month < Zero)
    {
        printf("Invalid Month. Please enter a value between 1 and %d.\n", Max_Months_Per_Year);
        return Fail;
    }
    if (Date_Of_Birth->Year < Least_Valid_Year)
    {
        printf("Invalid Year. Please enter a value greater than or equal to %d.\n", Least_Valid_Year);
        return Fail;
    }
    return Success;
}
