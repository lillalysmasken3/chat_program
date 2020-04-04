# Chattprogramm.

## Beskrivning.
* Programmet ska ansvara för att läsa (från användaren), skicka (via UART seriell kommunikation), ta emot (från UART), och pressentera text.
* Programmet skall initiera seriell komunikation för både Serial1(aka UART), och Serial (AKA USB) med en bitrate på 9600 bit/s.

### Läsa.
* Programmet skall ha ett interface mot användaren som möjliggör inmatning av text från användaren.
* Texten skall sparas i block om max 64 bytes.
* När tecknet som matas in är newline (\n) skall texten sparas o anses färdig att skicka.

### Skicka.
* Programmet skall skicka textblocken via Serial1 (UART).
* Programmet skall göra detta för alla textblock ett i taget, med en fördröjning på 100ms; fram tills det inte finns mer data att skicka.

### Ta emot.
* Programmet skall med hjälp av en hårdvarutimer,var 50ms kolla om det finns något i seriebuffern att läsa.
* Om seriebuffern har något skall det sparas i en mottagande sträng, o buffern skall rensas.
* Programmet skall repetera detta, och lägga till nästkommande textblock efter sista tecknet i strängen.
* När tecknet newline (\n) tas emot skall sändningen anses som klar och strängen skall nu innehålla all text (\n inkluderat).

### Pressentera
* När användaren matar in ett tecken skall det direkt skrivas ut i terminalen.
* När programmet tagit emot ett meddelande skall det skrivas ut i terminalen.

### Övrigt.
* *(optional) Programmet skall vara medvetet om när det håller på att ta emot ett meddelande, och inga nya meddelanden skall skickas under tiden.*
* *(optional) Det ska gå att "sudda" tecken som blivit fel vid inmatning.*
