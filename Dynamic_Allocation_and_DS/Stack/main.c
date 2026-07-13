/**
 * @file main.c
 * @brief This file contains the implementation of a stack data structure using both linked list and array.
 * The stack supports operations such as push, pop, peek, and size.
 * @author Ahmed Ashraf (ahmedashraf2022222@gmail.com)
 * @date 7/13/2026
 * @version   1.0.0
 * @copyright Copyright (c) 2026 Gestell Company. All rights reserved.
 */

#include "SingleLinkedList/SingleLinkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#define info_size 8
#define NULL ((void *)0)

#define Answer_By_LL 0
#define Answer_By_Array 1
extern Node_t *Start;
Node_t *End = NULL;

int32_t Size = 0; // to keep track of the number of elements in the list

#if 0
void Copy_String(uint8_t *Dest, uint8_t *Source, uint8_t Length)
{
 if (Dest == NULL || Source == NULL)
     {
          return;
     }

     for (uint8_t i = 0; i < Length; i++)
     {
          Dest[i] = Source[i];
     }
}
#endif
/*Tasks : Implement Funcs : Pop , push , peek/top , Size with dynamic allocation and array */

#if Answer_By_LL

// Stack = LIFO (Last in First out) , place the last element in the top of the stack and remove it first

void Push(uint8_t *Data) // insert at beginning
{
     Node_t *NewElement = CreateElement();
     if (NewElement == NULL)
     {
          printf("Memory Allocation Failed");
          return;
     }

     for (uint8_t i = 0; i < info_size; i++)
     {
          NewElement->Info[i] = Data[i];
     }

     NewElement->Next = Start;
     Start = NewElement;
     Size++;
}

Node_t *Pop() // remove from beginning
{
     if (Start == NULL)
     {
          printf("Stack is Empty");
          return NULL;
     }

     Node_t *Temp = Start;
     Start = Start->Next;
     free(Temp);
     Size--;
     return Temp;
}

uint32_t Size()
{
     return Size;
}

Node_t *Peek() // return the top element without removing it
{
     if (Start == NULL)
     {
          printf("Stack is Empty");
          return NULL;
     }

     return Start;
}

int main(void)
{
     int choice = 0;

     uint8_t Dummy_Data[8] = {0, 1, 2, 3, 4, 5, 6, 7};
     while (1)
     {
          printf("Choose an option:\n");
          printf("1. Push\n");
          printf("2. Pop\n");
          printf("3. Peek\n");
          printf("4. Size\n");
          scanf("%d", &choice);
          if (choice == 1)
          {

               Push(Dummy_Data);
          }
          else if (choice == 2)
          {
               Pop();
          }
          else if (choice == 3)
          {
               Node_t *top = Peek();
               if (top != NULL)
               {
                    printf("Top element: ");
                    for (uint8_t i = 0; i < info_size; i++)
                    {
                         printf("%u", top->Info[i]);
                    }
                    printf("\n");
               }
          }
          else if (choice == 4)
          {
               printf("Size of stack: %d\n", Size());
          }
          else
          {
               printf("Invalid choice\n");
          }

          Sleep(3000); // Wait for 3 second
          system("cls");
     }

     return 0;
}

#endif

#if Answer_By_Array
// implement stack using array (push , pop , peek , size)

// Stack = LIFO (Last in First out) , place the last element in the top of the stack and remove it first

int Stack[100] = {0};
int Top = -1;

void Push(uint8_t *Data, uint8_t Length) // pushing data to the stack
{

     for (uint8_t i = 0; i < info_size; i++)
     {
          if (Top == 99)
          {
               printf("Stack is Full");
               return;
          }
          Top++;

          Stack[Top] = Data[i];
          Size++;
          printf("Pushed element: %u\n", Data[i]);
     }
}

void Pop(uint8_t *StoredData, uint8_t Length) // popping data from the stack
{

     for (uint8_t i = 0; i < Length; i++)
     {
          if (Top == -1)
          {
               printf("Stack is Empty");
               return;
          }

          StoredData[i] = Stack[Top];
          Top--;
          Size--;
     }
}

void Peek(uint8_t *StoredData, uint8_t Length) // peeking data from the stack
{
     if (Top == -1 || Top - Length < -1)
     {
          printf("Not enough elements to peek\n");
          return;
     }

     for (uint8_t i = 0; i < Length; i++)
     {
          StoredData[i] = Stack[Top - i];
     }
}

int32_t Size_Check() // i named the func Size_Check to avoid conflict with the global variable ' Size '
{
     return Size;
}

int main()
{
     int choice = 0;

     uint8_t Dummy_Data[8] = {0, 1, 2, 3, 4, 5, 6, 7};
     uint8_t StoredData[8] = {0};
     while (1)
     {
          printf("Choose an option:\n");
          printf("1. Push\n");
          printf("2. Pop\n");
          printf("3. Peek\n");
          printf("4. Size\n");
          scanf("%d", &choice);
          if (choice == 1)
          {
               Push(Dummy_Data, info_size); // each push will push 8 elements to the stack
          }
          else if (choice == 2)
          {
               Pop(StoredData, info_size);
               printf("Popped elements: ");
               for (uint8_t i = 0; i < info_size; i++)
               {
                    printf("%u ", StoredData[i]);
               }
               printf("\n");
          }
          else if (choice == 3)
          {
               Peek(StoredData, info_size);
               printf("Peeked elements: ");
               for (uint8_t i = 0; i < info_size; i++)
               {
                    printf("%u ", StoredData[i]);
               }
               printf("\n");
          }
          else if (choice == 4)
          {
               printf("Size of stack: %d\n", Size_Check());
          }
          else
          {
               printf("Invalid choice\n");
          }

          Sleep(3000); // Wait for 3 second
          system("cls");
     }

     return 0;
}

#endif

/* expecting to push 0,1,2,3,4,5,6,7 */

/* expecting to pop 7,6,5,4,3,2,1,0 */