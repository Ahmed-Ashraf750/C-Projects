/**
 * @file Age_Calculator.h
 * @brief This File holds the Interfacing modules for the Age Calculator Project
 */
#ifndef _AGE_CALCULATOR_H_
#define _AGE_CALCULATOR_H_
/**
 * @struct Date_t
 * @brief This structure holds the Date information (Day, Month, Year)
 * {@
 */
typedef struct
{
   unsigned char Day;
   unsigned char Month;
   short unsigned Year;
} Date_t;
/**@} */

/**
 * @def Today_Year
 * @brief A Macro Presents the Year We are on
 */

#define Today_Year 2026

/**
 * @def Max_Months_Per_Year
 * @brief Macro Shows max months Per Year
 */

#define Max_Months_Per_Year 12
/**
 * @def Zero
 * @brief Macro Indicates Zero Number
 * @details this macro is created to avoid Magic Numbers
 */

#define Zero 0
/**
 * @def Max_Days_Per_Month
 * @brief A Macro Holds the Max Days Per Month
 */

#define Max_Days_Per_Month 30

/**
 * @def Fail
 * @brief A Macro Indicates Failure
 */
#define Fail 0
/**
 * @def Success
 * @brief A Macro Indicates Success
 */
#define Success 1
#endif
