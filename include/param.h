#ifndef PARAM_H
#define PARAM_H
//#include <stm32f103xe.h>
#include <Arduino.h>
//============================================================================
struct SpecialInt_s
{
    int integer;
    uint8_t cheksum;
};
#define EEPROM_BASE 0
#define EEPROM_ADDRESS_HOURS0 (EEPROM_BASE)
#define EEPROM_ADDRESS_HOURS1 (EEPROM_ADDRESS_HOURS0 + sizeof(SpecialInt_s))
#define EEPROM_ADDRESS_MINUTES0 (EEPROM_ADDRESS_HOURS1 + sizeof(SpecialInt_s))
#define EEPROM_ADDRESS_MINUTES1 (EEPROM_ADDRESS_MINUTES0 + sizeof(int))
//============================================================================

    #define RX_PIN PA10//1
    #define TX_PIN PA15//2
    #define VBAT 1      //3
    //====== port C =====//
    #ifdef __STM32F103xE_H
        #define segA PC0    //4
        #define segB PC1    //5
        #define segC PC2    //6
        #define segD PC3    //7
        #define segE PC4    //8
        #define segF PC5    //9
        #define segG PC6    //10
        #define segH PC7    //11
    #else
    #endif
    #define TM1640_CLK PB8
    #define TM1640_DIO PB9

    //PC8 FREE
    //PC9 FREE
    //PC10 FREE
    //PC11 FREE    
    #define MOSI PC13    //13
    #define MISO PC14    //14
    #define SCK PC15     //15
    //======================//    
    //     Left side pins   //
    //======================//

    #define SleepMode_INPUT PB12
    #define Inizier_INPUT PB13
    //x
    //x
    #define INT1_INPUT_PIN  PA8
    #define INT1            PA8
    #define SENSOR_DO_RX    PA10
    #define Sensor_ADC_TX   PA9
    #define BUZZER_OUT      PA11
    #define OnOff_INTPUT    PA12
    #define ChildLock_INPUT PA15
    #define FAN_PLUS_INPUT  PB3
    #define FAN_MINUS_INPUT PB4
    #define FILTER_INPUT    PB5
    #define TIMER_INPUT     PB6
    #define AutoMode_INPUT  PB7
    #define TM1640_CLK      PB8
    #define TM1640_DIO      PB9
    
    //======================//    
    //    right side pins   //
    //======================//
    #define BLUE2           PB11
    #define GREEN2          PB10
    #define RED2            PB1
    #define RED1            PB0
    #define GREEN1          PA7
    #define BLUE1           PA6
    #define RemoteRxPin     PA5
    #define NC1             PA4
    #define PWM             PA3
    #define AUTO_LED        PA2
    #define CHILD_LED       PA1
    #define IONIZER_LED     PA0
    //X
    //X
    //X

    //======================//    
    //          ALIAS       //
    //======================//
    #define RED2_HEALTH     RED2
    #define GREEN2_HEALTH   GREEN2
    #define BLUE2_HEALTH    BLUE2
    
    #define RED1_FILTER_STATUS      RED1
    #define GREEN1_FILTER_STATUS    GREEN1
    #define BLUE1_FILTER_STATUS     BLUE1

    #define FAN_PWM PWM
    //====================//
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
        KEY_H
    }keyCode_t;
#endif