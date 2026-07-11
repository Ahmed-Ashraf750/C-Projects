#include "HAL/LCD/LCD_Interface.h"
#include "SingleLinkedList/SingleLinkedList.h"
#include <util/delay.h>
#define NULL ((void *)0)
uint32_t NumOfNodes = 0;

extern Node_t *Start;
extern Node_t *Last;
// void Copy_String(uint8_t *Dest, uint8_t *Source, uint8_t Length)
// {
//      if (Dest == NULL || Source == NULL)
//      {
//           return;
//      }

//      for (uint8_t i = 0; i < Length; i++)
//      {
//           Dest[i] = Source[i];
//      }
// }

int main(void)
{

     mDIO_SetDirectionForGroup(GroupD, Input);
     mDIO_WriteGroup(GroupD, 0xff);
     hLCD_Init();
     uint8_t InputValue = 0;
     Node_t *Element_1 = CreateElement();
     Node_t *Element_2 = CreateElement();
     Node_t *Element_3 = CreateElement();
     Node_t *Element_4 = CreateElement();
     Start = Element_1;
     Element_1->Next = Element_2;
     Element_2->Next = Element_3;
     Element_3->Next = Element_4;
     Element_4->Next = Null;
     uint8_t input = 255;
     // list starts with initially 4 elements
     Last = Element_4; // last element in the list
     while (1)
     {
          hLCD_SendCommand(0x01);
          NumOfNodes = CountNode();
          hLCD_WriteString("Num of Nodes :");
          hLCD_WriteNumber(NumOfNodes);
          mDIO_ReadGroup(GroupD, &input); // 1 , 4 , 7 -> 1111 1101 , 0111 1111 , 1110 1111
          if (input == 0xFD)
          {
               InsertAtEnd();
          }
          else if (input == 0xEF)
          {
              Delete_LastNode();
          }
          else if (input == 0x7F)
          {
               Delete_List();
          }

          _delay_ms(1000);
     }
}