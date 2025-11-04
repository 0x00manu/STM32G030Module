#ifndef PARAM_H
#define PARAM_H
#include <stm32f0xx.h>
//#include <Arduino.h>
//============================================================================
struct SpecialInt_s
{
    int integer;
    uint8_t cheksum;
};    //====================//
    // Function pointer type definition
    typedef void (*PatternFunction)();
    //ir hex codes
    #define IR_HEX_A (unsigned long)0xB946FF00UL
    #define IR_HEX_B (unsigned long)0xBB44FF00UL
    #define IR_HEX_C (unsigned long)0xBC43FF00UL
    #define IR_HEX_D (unsigned long)0xBF40FF00UL
    #define IR_HEX_E (unsigned long)0xEA15FF00UL
    #define IR_HEX_F (unsigned long)0xE916FF00UL
    #define IR_HEX_G (unsigned long)0xE619FF00UL
    #define IR_HEX_H (unsigned long)0xF20DFF00UL
    typedef enum
    {
        KEY_NONE,
        KEY_A,
        KEY_B,
        KEY_C,
        KEY_D,
        KEY_E,
        KEY_F,
        KEY_G,
        KEY_H,
        KEY_NONE
    }keyCode_t;
#endif