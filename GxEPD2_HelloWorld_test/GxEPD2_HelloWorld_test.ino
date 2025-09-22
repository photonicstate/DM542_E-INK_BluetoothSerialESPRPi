#define ESP32

#include <GxEPD2_3C.h>
#include <Fonts/FreeMonoBold9pt7b.h>

// SDA (MOSI) 23
// SCLK 18
#define EPD_SS 17
#define EPD_DC 26
#define EPD_RST 25
#define EPD_BUSY 33

#define MAX_DISPLAY_BUFFER_SIZE 65536ul
#define MAX_HEIGHT_3C(EPD) (EPD::HEIGHT <= (MAX_DISPLAY_BUFFER_SIZE / 2) / (EPD::WIDTH / 8) ? EPD::HEIGHT : (MAX_DISPLAY_BUFFER_SIZE / 2) / (EPD::WIDTH / 8))

GxEPD2_3C<GxEPD2_290_C90c, MAX_HEIGHT_3C(GxEPD2_290_C90c)>
display(GxEPD2_290_C90c(EPD_SS, EPD_DC, EPD_RST, EPD_BUSY));

SPIClass hspi(HSPI);

void setup()
{
  display.init(5000000);
  helloWorld();
  display.hibernate();
}
const char HelloWorld[] = "hello, world!";

void helloWorld()
{
  display.setRotation(1);
  display.setFont(&FreeMonoBold9pt7b);
  display.setTextColor(GxEPD_BLACK);
  int16_t tbx, tby; uint16_t tbw, tbh;
  display.getTextBounds(HelloWorld, 0, 0, &tbx, &tby, &tbw, &tbh);
  // center the bounding box by transposition of the origin:
  uint16_t x = ((display.width() - tbw) / 2) - tbx - 20;
  uint16_t y = ((display.height() - tbh) / 2) - tby;
  display.setFullWindow();
  display.firstPage();

  do
  {
    display.fillScreen(GxEPD_WHITE);
    display.setCursor(x, y);
    display.print(HelloWorld);
  }

  while (display.nextPage());
}

void loop(){

};


