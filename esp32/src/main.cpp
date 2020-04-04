#include <Arduino.h>

#define UART Serial1

void setup(void)
{
    UART.begin(9600);
    Serial.begin(9600);
    delay(2000);
}
void loop(void)
{
    while (!UART.available())
    {
    }
    char mychar = UART.read();

    Serial.print((char)mychar);

    mychar = toupper(mychar);
    while (!UART.availableForWrite())
    {
    }
    UART.write(mychar);
    UART.flush();
}