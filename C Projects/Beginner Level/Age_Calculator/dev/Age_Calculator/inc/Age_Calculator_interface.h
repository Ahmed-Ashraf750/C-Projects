/**
 * @file Age_Calculator_interface.h
 * @brief This File holds the Interfacing modules for the Age Calculator Project
 * @author Ahmed Ashraf   (ahmedashraf2022222@gmail.com)
 * @author Reviewer : Eng. Hesham Ahmed (Hisham4Ahmed@gmail.com)
 * @date 18/3/2026
 * @version 1.0
 * @copyright Copyright (c) 2026 Ahmed Ashraf. All rights reserved.
 */

#ifndef _AGE_CALCULATOR_H_
#define _AGE_CALCULATOR_H_

#include "Age_Calculator_config.h"
#include "Age_Calculator_private.h"

/**
 * @struct Date_t
 * @brief This structure holds the Date information (Day, Month, Year)
 * {@
 */
typedef struct
{
   unsigned char Day;
   unsigned char Month;
   short unsigned int Year;
} Date_t;
/**@} */




/**
 * @fn calculate_Age
 * @brief A Function that calculates the Age of a person based on the current date and birth date
 * @param Today_Date A Date_t structure that holds the current date (day, month, year)
 * @param Birth_Date A Date_t structure that holds the birth date of the person (day, month, year)
 * @param Age A pointer to a Date_t structure where the calculated age will be stored (day, month, year)
 */
void Calculate_Age(Date_t Today_Date, Date_t Birth_Date, Date_t *Age);

/**
 * @fn Scan_Date
 * @brief A Function that scans the current date and birth date from the user and stores them in the provided Date_t structures
 * @param Present_Date A pointer to a Date_t structure where the scanned current date will be stored (day, month, year)
 * @param Date_Of_Birth A pointer to a Date_t structure where the scanned birth date will be stored (day, month, year)
 */
char Scan_Date(Date_t *Present_Date, Date_t *Date_Of_Birth);

/**
 * @fn Compare_Strings
 * @brief A Function that compares two strings and returns 1 if they are equal, otherwise returns 0
 * @param str1 A pointer to the first string
 * @param str2 A pointer to the second string
 * @return Matches if the strings are equal, Mismatch otherwise
 */
unsigned char Compare_Strings(const char *str1, const char *str2);

/**
 * @def Continue_Choice
 * @brief A Macro that holds a string representing the user's choice to continue calculating ages (yes/no)
 */
#define keep_Run "yes"
#endif
