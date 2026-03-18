/**
 * @file main.c
 * @brief This is the main file for the Age Calculator Project
 * This program calculates the age of a person based on their birth year and the current year.
 */

#include "inc/Age_Calculator_interface.h"
#include <stdio.h>
#include <stdlib.h>
int main()
{

    /**
     * @var Present_Date
     * @brief A Date_t structure that holds the current date (day, month, year)
     */
    Date_t Present_Date = {0};

    /**
     * @var Date_Of_Birth
     * @brief A Date_t structure that holds the birth date of the person (day, month, year)
     */
    Date_t Date_Of_Birth = {0};

    /**
     * @var Age_Result
     * @brief A Date_t structure that holds the calculated age of the person (day, month, year)
     */

    Date_t Age_Result = {0};
    /**
     * @var Continue_Choice
     * @brief A string that holds the user's choice to continue calculating ages (yes/no)
     */
    char Continue_Choice[] = keep_Run;

    while (Compare_Strings(Continue_Choice, keep_Run) == Matches)
    {
        system("cls");

        printf("Welcome to the Age Calculator!\n");
        printf("This program will calculate your age based on the current date and your birth date.\n");

        if (Scan_Date(&Present_Date, &Date_Of_Birth))
        {
            Calculate_Age(Present_Date, Date_Of_Birth, &Age_Result);

            printf("You're %d Years , %d Months , %d Days", Age_Result.Year, Age_Result.Month, Age_Result.Day);
        }

        printf("\nDo you want to calculate another age? (yes/no): ");
        scanf("%s", Continue_Choice);
    }
    return Success;
}