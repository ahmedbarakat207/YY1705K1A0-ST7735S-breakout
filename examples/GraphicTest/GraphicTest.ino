#include <SPI.h>
#include "YY1705K1A0.h"

// Pin definitions (change according to your microcontroller wiring)
#define TFT_CS    10
#define TFT_DC    9
#define TFT_RST   8

// Instantiate driver with Hardware SPI
YY1705K1A0 tft(TFT_CS, TFT_DC, TFT_RST);

void setup() {
    Serial.begin(115200);

    // Initialize display with standard black tab profile (YY1705K1A0)
    tft.begin(INITR_BLACKTAB);
    tft.setRotation(0);
    tft.fillScreen(TFT_BLACK);

    // Title text
    tft.setTextColor(TFT_YELLOW, TFT_BLACK);
    tft.setTextSize(1);
    tft.drawString(10, 10, "YY1705K1A0 DEMO", TFT_YELLOW, TFT_BLACK, 1);

    // Drawing geometric shapes
    tft.drawRect(10, 25, 108, 40, TFT_CYAN);
    tft.fillRoundRect(15, 30, 98, 30, 4, TFT_NAVY);
    tft.drawString(25, 40, "ST7735S 1.8\"", TFT_WHITE, TFT_NAVY, 1);

    // Circles & triangles
    tft.drawCircle(30, 90, 15, TFT_RED);
    tft.fillCircle(30, 90, 10, TFT_GREEN);
    tft.fillTriangle(70, 75, 55, 105, 85, 105, TFT_MAGENTA);
    tft.drawTriangle(105, 75, 90, 105, 120, 105, TFT_GOLD);

    // Progress bar
    for (int p = 0; p <= 100; p += 5) {
        tft.drawProgressBar(10, 130, 108, 14, p, TFT_GREEN, TFT_DARKGREY, TFT_WHITE);
        delay(30);
    }
}

void loop() {
    // Rotation test cycle
    for (uint8_t r = 0; r < 4; r++) {
        tft.setRotation(r);
        tft.fillScreen(TFT_BLACK);
        tft.drawString(10, 10, "Rotation Test", TFT_GREENYELLOW, TFT_BLACK, 1);
        tft.setCursor(10, 30);
        tft.setTextColor(TFT_WHITE, TFT_BLACK);
        tft.print("Mode: ");
        tft.print(r);
        delay(1000);
    }
}
