#include "TouchPad.hpp"
//==================//
#include <IRremote.h>
//==================//
#define RemoteRxPin 12
keyCode_t keycode;
/// @brief Call from Setup        
void setupIR(void)
{
    //irrecv.enableIRIn(); // Start the receiver
    IrReceiver.begin(RemoteRxPin);
}

/// @brief Call from Loop
void LoopIR(void)
{
    if(IrReceiver.decode())
    {
        switch (IrReceiver.decodedIRData.decodedRawData)
        {
            case IR_HEX_A:
            keycode = KEY_A;
            break;
            case IR_HEX_B:
            keycode = KEY_B;
            break;
            case IR_HEX_C:
            keycode = KEY_C;
            break;
            case IR_HEX_D:
            keycode = KEY_D;
            break;
            case IR_HEX_E:
            keycode = KEY_E;
            break;
            case IR_HEX_F:
            keycode = KEY_F;
            break;
            case IR_HEX_G:
            keycode = KEY_G;
            break;
            case IR_HEX_H:
            keycode = KEY_H;
            break;
            default:
            keycode = KEY_NONE;
            break;
        }
        //delay(200);
        IrReceiver.resume(); // Receive the next value
    }
}

/// @brief constructor
TouchPad::TouchPad()
{
    setupIR();
}

TouchPad::~TouchPad()
{}

void TouchPad::Loop()
{
    LoopIR();
} 