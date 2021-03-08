#include <BatteryPictogram.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128  // OLED display width, in pixels
#define SCREEN_HEIGHT 32  // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
// The pins for I2C are defined by the Wire-library.
// On an arduino UNO:       A4(SDA), A5(SCL)
// On an arduino MEGA 2560: 20(SDA), 21(SCL)
// On an arduino LEONARDO:   2(SDA),  3(SCL), ...

// Reset pin # (or -1 if sharing Arduino reset pin)
#define OLED_RESET     4
// See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32
#define SCREEN_ADDRESS 0x3C

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
BatteryPictogram batteryPictogram(20, 10, SSD1306_WHITE, SSD1306_BLACK);

int batteryLevel = 100;

void setup()
{
  Serial.begin(115200);

  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;) {}  // Don't proceed, loop forever
  }
  display.clearDisplay();
  batteryPictogram.draw(0, 0, batteryLevel, &display);
  display.display();
}

void loop()
{
  Serial.println(String("Level = " + String(batteryLevel, DEC)));
  batteryLevel = (batteryLevel + 10) % 100;
  batteryPictogram.draw(batteryLevel, &display);
  display.display();
  ::delay(500);
}
