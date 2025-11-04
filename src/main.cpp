#include "main.h"
TouchPad inputs;
void setup() 
{
	Serial.begin(9600);
	Serial.println("ready");
}
keyCode_t ke;
void loop()
{
	inputs.Loop();
	ke = inputs.GetKeyCode();
	if(ke != KEY_NONE)
	{
		Serial.println(ke,HEX);
	}
}
