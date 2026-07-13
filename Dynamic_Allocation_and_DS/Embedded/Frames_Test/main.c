#include "HAL/LCD/LCD_Interface.h"
#include "SingleLinkedList/SingleLinkedList.h"
#include <util/delay.h>
#define NULL ((void *)0)

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

int main(void)
{

     // Creating the elements in the list
     Node_t *Executioner_ptr;
     Node_t *Element_1;
     Element_1 = CreateElement();
     Node_t *Element_2 = CreateElement();
     Node_t *Element_3 = CreateElement();
     // assigning the circle
     Executioner_ptr = Element_1;
     Element_1->Next = Element_2;
     Element_2->Next = Element_3;
     Element_3->Next = Element_1; // Closing the circle

     /* Creating LCD Frames */

     uint8_t Frame1[8] = {0x00, 0x00, 0x0C, 0x1E, 0x12, 0x1E, 0x1E, 0x1E};
     uint8_t Frame2[8] = {0x00, 0x00, 0x0C, 0x1E, 0x1E, 0x1E, 0x1E, 0x1E};
     uint8_t Frame3[8] = {0x00, 0x00, 0x0C, 0x1E, 0x12, 0x12, 0x12, 0x1E};

     // assigning the frames to the elements
     Copy_String(Element_1->Info, Frame1, 8);
     Copy_String(Element_2->Info, Frame2, 8);
     Copy_String(Element_3->Info, Frame3, 8);

     hLCD_Init();
     hLCD_WriteString("Linked List Test");
     _delay_ms(1000);

     while (Executioner_ptr != NULL)
     {
          hLCD_SendCommand(0x01);
          hLCD_StoreSpecialChar(Executioner_ptr->Info, 0); // storing the pattern in CGRAM location 0

          hLCD_WriteChar(0); // printing the pattern stored in CGRAM location 0

          _delay_ms(1000);
          Executioner_ptr = Executioner_ptr->Next; //next frame
     }
}