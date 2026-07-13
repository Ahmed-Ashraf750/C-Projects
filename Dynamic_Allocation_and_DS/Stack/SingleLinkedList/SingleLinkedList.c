/**
 * @file SingleLinkedList.h
 * @brief A header file Holds the declaration of Functions Related to Single linked list
 * @author Developer : Ahmed Ashraf (ahmedashraf2022222@gmail.com)
 * @date 6-26-2026
 * @copyright Copyright (c) 2026 , Gestell Company
 * @version 1.0.0
 */

#include "SingleLinkedList.h"

Node_t *Start = NULL;
Node_t Failure ; // to return in case of failure
// uint32_t CountNode()
// {
//     if (Start == NULL)
//     {
//         return 0;
//     }
//     else
//     {
//         Node_t *Temp = Start;
//         uint32_t count;
//         while (Temp != NULL)
//         {
//             count++;
//             Temp = Temp->Next;
//         }
//         printf("Number of Nodes is %d\n", count);
//         return count;
//     }
// }

Node_t *CreateElement()
{
    // Node_t* NewElement = NULL;
    // NewElement = (Node_t*)malloc(sizeof(Node_t));
    // return NewElement;

    return ((Node_t *)malloc(sizeof(Node_t)));
}

// void DisplayList()
// {
//     if (Start != NULL)
//     {
//         Node_t *Temp = Start;
//         while (Temp != NULL)
//         {
//             printf("%d\t", Temp->Info);
//             Temp = Temp->Next;
//         }
//         printf("\n");
//     }
//     else
//     {
//         printf("Not List found");
//     }
// }

// int search(uint8_t SearchVal)
// {
//     if (Start == NULL)
//     {
//         printf("no list found");
//         return 0;
//     }
//     else
//     {
//         Node_t *Temp = Start;
//         int pos = 1;
//         while (Temp != NULL)
//         {
//             if (Temp->Info == SearchVal)
//             {
//                 printf("%d", pos);
//                 return pos;
//             }
//             else
//             {
//                 pos++;
//                 Temp = Temp->Next;
//             }
//         }

//         printf("the value not found");
//         return -1;
//     }
// }

// Node_t InsertAtBeginning()
// {
//     if (Start == NULL)
//     {
//         printf("this Element is the first in the list");
//     }
//     else
//     {

//         printf("A list is found , Inserting an element in it's beginning");
//     }

//     Node_t *Temp = Start;
//     Start = CreateElement();
//     Start->Next = Temp;

//     return *Start;
// }

// Node_t InsertAtEnd()
// {
//     if (Start == NULL)
//     {
//         printf("the list has no elements , element inserted will be the first and last at the list");
//     }
//     else
//     {
//         printf("inserting Element at the end is in progress");
//     }

//     Node_t *Temp = Start;
//     while (Temp->Next != NULL)
//     {
//         Temp = Temp->Next;
//     }

//     Temp->Next = CreateElement();
//     return *Temp->Next;
// }

// Node_t InsertAfterNode(int AfterVal)
// {
//     Node_t *New_element = NULL;
//     if (Start == NULL)
//     {
//         printf("No list found ");
//         return Failure;
//     }
//     else
//     {
//         printf("List Found , Starting Insertion");
//     }
//     Node_t *Temp = Start;

//     // moving Temp into the element that we need to insert after
//     for (int address_seeker = 1; address_seeker < AfterVal; address_seeker++)
//     {
//         Temp = Temp->Next;
//     }
//     if (Temp == NULL)
//     {
//         return Failure;
//     }
//     New_element = CreateElement(); // new element created with next = null , we need to make the element we are at has it's address
//     Node_t *Temp2 = Temp->Next;    // points towards the old element after the specific node
//     Temp->Next = New_element;      // we assign the new.next to hold the address of next element in list , hold on we lost the address ?? -> store the address before assigning to new elem
//     New_element->Next = Temp2;

//     return *New_element;
// }

// Node_t InsertBeforeNode(int BeforeVal) // needs fix of using search
// {

//     if (BeforeVal == 1)
//     {
//         return InsertAtBeginning();
//     }
//     Node_t *New_element = NULL;
//     if (Start == NULL || BeforeVal < 1)
//     {
//         printf("No list found ");
//         return Failure;
//     }
//     else
//     {
//         printf("List Found , Starting Insertion");
//     }
//     InsertAfterNode((BeforeVal - 1));
// }
