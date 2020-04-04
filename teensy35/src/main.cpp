#include <Arduino.h>

#define UART Serial1 // bara ett namnbute så det är tydligare vilken serial vi använder.

void setup(void)
{
    Serial.begin(9600); //Starta Serial AKA USB kommunikationen med en bitrate på 9600 bit/sekund.
    UART.begin(9600);   //starta Serial1 AKA UART kommunikationen med en bitrate på 9600 bit/sekund.
    delay(2000);        // chilla 2 sek tills de startat.
}

void loop(void)
{
    char mychar = 'a' + random(26); //för en char som är lill a + ?? för att slumpa fram en liten bokstav

    while (!UART.availableForWrite()) // om inte UART buffern är tom...
    {                                 //gör inget
    }
    UART.write(mychar); // annars skriv tecknet till buffern.
    UART.flush();       //tvångsvänta tills den skickat iväg buffern. AKA tvinga den att skicka iväg buffern.

    while (!UART.available()) // Om det inte finns något i UART buffern...
    {                         // gör inget
    }
    Serial.print((char)UART.read()); //printa tecknet som läses från UART buffern.
    UART.clear();                    //rensar buffern
    delay(1000);
}