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
#include "Age_Calculator.h"

/**
 * @fn Calculate_Age
 * @brief This Function calculates the age of a person based on their birth date and the current date
 * @param Today_Date A Date_t structure that holds the current date (day, month, year)
 * @param Birth_Date A Date_t structure that holds the birth date of the person (day, month, year)
 * @param Age A pointer to a Date_t structure where the calculated age will be stored (day, month, year)
 */

void Calculate_Age(Date_t Today_Date, Date_t Birth_Date, Date_t *Age)
{
    if (Today_Date.Day<Birth_Date.Day){
        Today_Date.Month-=1;
       Today_Date.Day+=Max_Days_Per_Month;
    }
    if (Today_Date.Month<Birth_Date.Month){
        Today_Date.Year-=1;
        Today_Date.Month+=Max_Months_Per_Year;
    }
    Age->Day=Today_Date.Day-Birth_Date.Day;
    Age->Month=Today_Date.Month-Birth_Date.Month;
    Age->Year=Today_Date.Year-Birth_Date.Year;
}

int main()
{
    Date_t Present_Date = {0};
    Date_t Date_Of_Birth = {0};
    Date_t Age_Result = {0};
    /*Scanning Present Date {@** */
    printf("\nEnter Today's Year: \n");
    scanf("%hd", &Present_Date.Year);
    printf("\nEnter Today's Month: \n");
    scanf("%hhd", &Present_Date.Month);
    printf("\nEnter Today's Day:  \n");
    scanf("%hhd", &Present_Date.Day);
    /**@} */

    /*Scanning Date of Birth {@** */
    printf("\nEnter Birth's Year: \n");
    scanf("%hd", &Date_Of_Birth.Year);
    printf("\nEnter Birth's Month: \n");
    scanf("%hhd", &Date_Of_Birth.Month);
    printf("\nEnter Birth's Day:  \n");
    scanf("%hhd", &Date_Of_Birth.Day);
    /**@} */

    /*Handling Edge Cases {@** */
    if (Present_Date.Year < Date_Of_Birth.Year || Date_Of_Birth.Year < Least_Valid_Year)
    {
   
        printf("Wrong Year Entered Try Again");
        return Fail;
    }
    else if (Present_Date.Month > Max_Months_Per_Year || Present_Date.Month < Zero || Date_Of_Birth.Month > Max_Months_Per_Year || Date_Of_Birth.Month < Zero)
    {
        printf("Wrong Month Entered Try Again");
        return Fail;
    }
    else if (Present_Date.Day > Max_Days_Per_Month || Present_Date.Day < Zero || Date_Of_Birth.Day > Max_Days_Per_Month || Date_Of_Birth.Day < Zero)
    {
        printf("Wrong Day Entered Try Again");
        return Fail;
    }
    /**@} */

    Calculate_Age(Present_Date, Date_Of_Birth, &Age_Result);

    printf("You're %d Years , %d Months , %d Days", Age_Result.Year, Age_Result.Month, Age_Result.Day);

    return Success;
}
