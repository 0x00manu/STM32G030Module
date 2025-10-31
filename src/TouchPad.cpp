#include "TouchPad.hpp"
//==================//
#include <IRremote.h>
#include <Struct_s.hpp>
//==================//

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

/// @brief Global Variable
TouchpadStatus_s status;

/// @brief C type method (global)
void fanplusMethod()
{
    status.fanPlusStatus_b = true;
}

/// @brief C type method (global)
void fanMinusMethod()
{
    status.fanMinusStatus_b = true;
}

/// @brief C type method (global)
void timerMethod()
{
    status.timerStatus_b = true;
}

/// @brief C type method (global)
void filterMethod()
{
//filter life red/green/blue 10%/50%/90%
    status.filterStatus_b = true;
}

/// @brief C type method (global)
void childLockMethod()
{
    status.childLockStatus_b = true;
}

/// @brief C type method (global)
void onOffMethod()
{
        status.onOffStatus_b ^= true;
}

/// @brief C type method (global)
void autoModeMethod()
{
    status.autoModeStatus_b ^= true;
}

/// @brief C type method (global)
void inizierMethod()
{
        status.inizierStatus_b ^= true;
}

/// @brief C type method (global)
void sleepMethod()
{
    status.sleepStatus_b ^= true;
}
/// @brief constructor
/// @param fanPlus_ button pin
/// @param fanMinus_ button pin
/// @param timer_ button pin
/// @param filter_ button pin
/// @param childLock_ button pin
/// @param onOff_ button pin
/// @param autoMode_ button pin
/// @param inizier_ button pin
/// @param sleep_ button pin
TouchPad::TouchPad(
    int fanPlus_,
    int fanMinus_,        
    int timer_,
    int filter_,
    int childLock_,
    int onOff_,
    int autoMode_,
    int inizier_,
    int sleep_
    //int remote_
):
    fanplusBtn(fanPlus_,fanplusMethod),
    fanMinusBtn(fanMinus_,fanMinusMethod),
    timerBtn(timer_,timerMethod),
    filterBtn(filter_,filterMethod),
    childLockBtn(childLock_,childLockMethod),
    onOffBtn(onOff_,onOffMethod),
    autoModeBtn(autoMode_,autoModeMethod),
    inizierBtn(inizier_,inizierMethod),
    sleepBtn(sleep_,sleepMethod)
    //remote(remote_)
{
    status.autoModeStatus_b = false;
    status.childLockStatus_b = false;
    status.filterStatus_b = false;
    status.inizierStatus_b = false;
    status.onOffStatus_b = false;
    status.sleepStatus_b = false;
    status.timerStatus_b = false;
    status.childLockActivated = false;
    status.childLockSeconds = 0;
}
/// @brief call in 1 sec to detect long press
void TouchPad::callMe1Sec()
{
    childLockBtn.CallMe1Sec();
}
TouchPad::~TouchPad()
{
}

/// @brief gives falling edge info
bool TouchPad::GetFanPlus()
{
    if(status.fanPlusStatus_b)
    {
        status.fanPlusStatus_b = false;
        return true;
    }
    return false;
}

/// @brief gives falling edge info
bool TouchPad::GetFanMinus()
{
    if(status.fanMinusStatus_b)
    {
        status.fanMinusStatus_b = false;
        return true;
    }
    return false;
}

/// @brief gives falling edge info
bool TouchPad::GetautoModeStatus()
{
    if(status.autoModeStatus_b)
    {
        status.autoModeStatus_b = false;
        return true;
    }
    return false;
}

/// @brief gives falling edge info
bool TouchPad::GetchildLockStatus()
{
    return childLockBtn.GetLongPressActivation();
}

/// @brief gives falling edge info
bool TouchPad::GetfilterStatus()
{
    if(status.filterStatus_b)
    {
        status.filterStatus_b = false;
        return true;
    }
    return false;
}

/// @brief gives falling edge info
bool TouchPad::GetinizierStatus()
{
    if(status.inizierStatus_b)
    {
        status.inizierStatus_b = false;
        return true;
    }
    return false;
}

/// @brief gives falling edge info
bool TouchPad::onOffStatus()
{
    if(status.onOffStatus_b)
    {
        status.onOffStatus_b = false;
        return true;
    }
    return false;
}

/// @brief gives falling edge info
bool TouchPad::GetsleepStatus()
{
    if(status.sleepStatus_b)
    {
        status.sleepStatus_b = false;
        return true;
    }
    return false;
}

/// @brief gives falling edge info
bool TouchPad::GettimerStatus()
{
    if(status.timerStatus_b)
    {
        status.timerStatus_b = false;
        return true;
    }
    return false;
}

/// @brief Only IRremote can set
void TouchPad::SetFanPlus(){status.fanPlusStatus_b = true;}

/// @brief Only IRremote can set
void TouchPad::SetFanMinus(){status.fanMinusStatus_b = true;}

/// @brief Only IRremote can set
void TouchPad::SetautoModeStatus(){status.autoModeStatus_b = true;}

/// @brief Only IRremote can set
void TouchPad::SetchildLockStatus(){status.childLockActivated = true;}

/// @brief Only IRremote can set
void TouchPad::SetfilterStatus(){status.filterStatus_b = true;}

/// @brief Only IRremote can set
void TouchPad::SetinizierStatus(){status.inizierStatus_b = true;}

/// @brief Only IRremote can set
void TouchPad::SetonOffStatus(){status.onOffStatus_b = true;}

/// @brief Only IRremote can set
void TouchPad::SetsleepStatus(){status.sleepStatus_b = true;}

/// @brief Only IRremote can set
void TouchPad::SettimerStatus(){status.timerStatus_b = true;}

void TouchPad::Loop()
{
    LoopIR();
    /*
    if(IrReceiver.decode())
    {
        switch (IrReceiver.decodedIRData.decodedRawData)
        {
            case IR_HEX_A:SetFanPlus(); break;
            case IR_HEX_B:SetFanMinus(); break;
            default:break;
        }
        IrReceiver.resume(); // Receive the next value
    }
    */
}
void TouchPad::Setup()
{
    //IrReceiver.begin(remotePin);

}