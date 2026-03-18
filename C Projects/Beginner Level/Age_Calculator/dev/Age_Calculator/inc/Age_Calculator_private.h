/**
 * @file Age_Calculator_private.h
 * @brief This File holds the private declarations for the Age Calculator Project
 * @author Ahmed Ashraf   (ahmedashraf2022222@gmail.com)
 * @author Reviewer : Eng. Hesham Ahmed (Hisham4Ahmed@gmail.com)
 * @date 18/3/2026
 * @version 1.0
 * @copyright Copyright (c) 2026 Ahmed Ashraf. All rights reserved.
 */

#ifndef _AGE_CALCULATOR_PRIVATE_H_
#define _AGE_CALCULATOR_PRIVATE_H_

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


/**
 * @def Matches
 * @brief A Macro Indicates that two strings match
 */
#define Matches 1
/**
 * @def Mismatch
 * @brief A Macro Indicates that two strings do not match
 */
#define Mismatch 0

/**
 * @def NullChar
 * @brief A Macro Represents the Null Character
 */
#define NullChar '\0'
/**
 * @def Null
 * @brief A Macro Represents the Null Pointer
 */
#define Null ((void *)0)

#endif /* _AGE_CALCULATOR_PRIVATE_H_ */