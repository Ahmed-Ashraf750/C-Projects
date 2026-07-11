/**
 * @file ATmega1284p_Addr.h
 * @brief Header file for ATmega1284P DIO address definitions
 * @author Ahmed Ashraf
 * @version 1.0.0
 * @copyright Copyright (c) 2026, Gestell Company
 */

#ifndef ATMEGA1284P_ADDR_H
#define ATMEGA1284P_ADDR_H
#include <stdint.h>

#define PINA_Reg  (*(volatile uint8_t *)0x39) //ok
#define DDRA_Reg  (*(volatile uint8_t *)0x3A) //ok
#define PORTA_Reg (*(volatile uint8_t *)0x3B) //ok
#define PINB_Reg  (*(volatile uint8_t *)0x36) //ok
#define DDRB_Reg  (*(volatile uint8_t *)0x37) //ok
#define PORTB_Reg (*(volatile uint8_t *)0x38) //ok
#define PINC_Reg  (*(volatile uint8_t *)0x33) //ok
#define DDRC_Reg  (*(volatile uint8_t *)0x34) //ok
#define PORTC_Reg (*(volatile uint8_t *)0x35) //ok
#define PIND_Reg  (*(volatile uint8_t *)0x30) //ok
#define DDRD_Reg  (*(volatile uint8_t *)0x31) //ok
#define PORTD_Reg (*(volatile uint8_t *)0x32) //ok

#endif // ATMEGA1284P_ADDR_H