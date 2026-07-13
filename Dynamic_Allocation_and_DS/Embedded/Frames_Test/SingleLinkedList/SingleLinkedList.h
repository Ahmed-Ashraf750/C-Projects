/**
 * @file SingleLinkedList.h
 * @brief A header file Holds the declaration of Functions Related to Single linked list
 * @author Developer : Ahmed Ashraf (ahmedashraf2022222@gmail.com)
 * @date 6-26-2026
 * @copyright Copyright (c) 2026 , Gestell Company
 * @version 1.0.0
 */

#ifndef SINGLE_lINKED_LIST_H_
#define SINGLE_lINKED_LIST_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

/**
 * @struct {@
 * @var Info : variable holds the data acquired it each element in the list
 * @var *Next : Pointer var with type (Node_t) points towards the next element in list
 * @warning : any element created it's element->Next should equal Null
 */

typedef struct Node
{
    uint8_t Info[8];
    struct Node *Next;

} Node_t;

/** @} */

/**
 * @fn Create Element
 * @brief a function that creates an element in the list by dynamic allocating it 
 * @return Return a Node_t pointer to the created element address
 */
Node_t *CreateElement();
/**
 * @fn DisplayList
 * @brief Display all the data in the list 
 */
void DisplayList();

/**
 * @fn CountNode
 * @brief A Function to Count Num of elements in the list
 * @return Returns number of element inside list as uint32_t
 */
uint32_t CountNode();

/**
 * @fn search
 * @brief a Function To Search about an element index according to info it holds
 * @param SearchVal : variables holds the data we need to search about 
 * @return return index_Number in the list (starting from 1) as int
 */
int search(uint8_t SearchVal);

/**
 * @fn InsertAtBeginning
 * @brief Creates an element at the start of the list
 * @return Struct pointing towards start of the list
 */
Node_t InsertAtBeginning();
/**
 * @fn InsertAtEnd
 * @brief Creates an element at the end of the list
 * @return Struct pointing towards the end of the list
 */
Node_t InsertAtEnd();
/**
 * @fn InsertAfterNode
 * @brief Function that creates an element after a specific Node (Element)
 * @param AfterVal : Number representes index of the Element we want to insert after
 * @return Returns a struct of the new element 
 */
Node_t InsertAfterNode(int AfterVal);
/**
 * @fn InsertBeforeNode
 * @brief Function that creates an element Before a specific Node (Element)
 * @param AfterVal : Number representes index of the Element we want to insert Before
 * @return Returns a struct of the new element 
 */
Node_t InsertBeforeNode(int BeforeVal);

#endif