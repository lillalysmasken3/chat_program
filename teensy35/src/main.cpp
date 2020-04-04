#include <Arduino.h>

#define UART Serial1

void setup(void)
{
    Serial.begin(9600);
    UART.begin(9600);

    delay(2000);
}

void loop(void)
{
    char mychar = 'a' + random(26);

    while (!UART.availableForWrite())
    {
    }
    UART.write(mychar);
    UART.flush();

    while (!UART.available())
    {
    }
    Serial.print((char)UART.read());
    UART.clear();
    delay(1000);
}