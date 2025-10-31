#ifndef STRUCT_S_HPP
#define STRUCT_S_HPP

/// @brief tells which pin is pressed
typedef struct
{
    bool fanPlusStatus_b;
    bool fanMinusStatus_b;
    bool timerStatus_b;
    bool filterStatus_b;
    bool childLockStatus_b;
    uint8_t childLockSeconds;
    bool childLockActivated;
    bool onOffStatus_b;
    bool autoModeStatus_b;
    bool inizierStatus_b;
    bool sleepStatus_b;
    ushort pm10;
    ushort pm1;
    ushort pm2p5;
}TouchpadStatus_s;
typedef struct
{
    int pm1;
    int pm2p5;
    int pm10;
}AQI_s;
#endif