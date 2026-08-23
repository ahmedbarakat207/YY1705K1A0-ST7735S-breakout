# YY1705K1A0 TFT Breakout — Wiring & Software Guide

## Board Overview

| Parameter | Value |
|---|---|
| Display Driver | ST7735S |
| Resolution | 128 × 160 px |
| Interface | 4-wire SPI |
| Logic voltage | **3.3 V only** |
| Board size | 35 × 30 mm |
| Layers | 2 (ENIG finish recommended) |
| FPC connector | 12-pin, 0.5 mm pitch ZIF (top-contact) |

---

## J1 Pin Header — Signal Map

| J1 Pin | Signal | ESP32 GPIO | Arduino Uno | Arduino Nano | Notes |
|--------|--------|------------|-------------|--------------|-------|
| 1 | **+3V3** | 3V3 | 3.3V | 3.3V | ⚡ **3.3 V only — do NOT connect 5 V** |
| 2 | **GND** | GND | GND | GND | |
| 3 | **RESET** | GPIO4 | D8 | D8 | 10 kΩ pull-up on board |
| 4 | **DC / A0** | GPIO2 | D9 | D9 | Data/Command select |
| 5 | **SDA / MOSI** | GPIO23 | D11 (MOSI) | D11 | Hardware SPI |
| 6 | **SCL / SCK** | GPIO18 | D13 (SCK) | D13 | Hardware SPI |
| 7 | **CS** | GPIO5 | D10 (SS) | D10 | 10 kΩ pull-up on board |

> **Arduino 5V Note:** Arduino Uno/Nano GPIOs are 5 V tolerant outputs but the display requires 3.3 V logic. You must add a **level shifter** (e.g. 74AHCT125) or a **resistor voltage divider** (1 kΩ + 2 kΩ) on MOSI, SCK, CS, DC, RESET lines when using a 5 V Arduino. The ESP32 is natively 3.3 V and needs no level shifting.

---

## On-board Passive Components

| Ref | Value | Function |
|-----|-------|----------|
| R1 | 22 Ω | LEDA backlight current limit (~50 mA at 3.3 V) |
| R2 | 10 kΩ | RESET line pull-up to 3.3 V |
| R3 | 10 kΩ | CS line pull-up to 3.3 V |
| C1 | 10 µF | VDD bulk decoupling |
| C2 | 100 nF | VDD high-frequency bypass |

---

## Arduino (5 V) — With Level Shifter

```
Arduino Uno               Breakout J1
──────────────────────────────────────
3.3V  ──────────────────► Pin 1 (+3V3)
GND   ──────────────────► Pin 2 (GND)
D8    ─── [Level shift] ► Pin 3 (RESET)
D9    ─── [Level shift] ► Pin 4 (DC/A0)
D11   ─── [Level shift] ► Pin 5 (MOSI)
D13   ─── [Level shift] ► Pin 6 (SCK)
D10   ─── [Level shift] ► Pin 7 (CS)
```

## ESP32 — Direct Connection (no level shifter needed)

```
ESP32                     Breakout J1
──────────────────────────────────────
3V3   ──────────────────► Pin 1 (+3V3)
GND   ──────────────────► Pin 2 (GND)
GPIO4 ──────────────────► Pin 3 (RESET)
GPIO2 ──────────────────► Pin 4 (DC/A0)
GPIO23──────────────────► Pin 5 (MOSI)
GPIO18──────────────────► Pin 6 (SCK)
GPIO5 ──────────────────► Pin 7 (CS)
```

---

## Software — Arduino / ESP32

Install via Arduino Library Manager: **Adafruit ST7735 and ST7789 Library** + **Adafruit GFX Library**

### ESP32 Example Sketch

```cpp
#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>
#include <SPI.h>

// Pin definitions matching J1 header
#define TFT_CS    5   // GPIO5
#define TFT_RST   4   // GPIO4
#define TFT_DC    2   // GPIO2
// MOSI = GPIO23 (hardware SPI)
// SCK  = GPIO18 (hardware SPI)

Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);

void setup() {
  Serial.begin(115200);
  tft.initR(INITR_BLACKTAB);   // Init ST7735S with black tab
  tft.setRotation(1);           // Landscape
  tft.fillScreen(ST77XX_BLACK);
  tft.setCursor(10, 40);
  tft.setTextColor(ST77XX_WHITE);
  tft.setTextSize(2);
  tft.println("Hello TFT!");
}

void loop() {}
```

### Arduino Uno Example Sketch

```cpp
#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>
#include <SPI.h>

#define TFT_CS   10
#define TFT_RST   8
#define TFT_DC    9
// MOSI = D11, SCK = D13 (hardware SPI)

Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);

void setup() {
  tft.initR(INITR_BLACKTAB);
  tft.fillScreen(ST77XX_BLUE);
  tft.setCursor(5, 30);
  tft.setTextColor(ST77XX_WHITE);
  tft.setTextSize(1);
  tft.println("YY1705K1A0 OK");
}

void loop() {}
```

---

## Gerber Export Settings (KiCad)

For JLCPCB / PCBWay fabrication:

| Setting | Value |
|---------|-------|
| Layers | F.Cu, B.Cu, F.Mask, B.Mask, F.Paste, F.SilkS, B.SilkS, Edge.Cuts |
| Format | Gerber RS-274X |
| Drill files | Excellon, separate file |
| Copper finish | ENIG (recommended for FPC connector pads) |
| Board thickness | 1.6 mm |
| Min track/space | 0.2 / 0.2 mm |
| Min hole | 0.3 mm |

---

## Troubleshooting

| Symptom | Likely cause | Fix |
|---------|-------------|-----|
| White/blank screen | Wrong `initR()` tab colour | Try `INITR_GREENTAB` or `INITR_REDTAB` |
| Garbled/shifted image | Wrong rotation | Call `tft.setRotation(0–3)` |
| No display at all | SPI not reaching display | Check 3.3V power and all SPI lines with oscilloscope |
| Backlight off | R1 open or LEDA not connected | Verify R1 22Ω continuity; LEDA should see ~3.1V |
| Display resets randomly | RESET pull-up missing | R2 10kΩ on board; verify soldering |
| High current draw | LEDA shorted | Verify R1 in series with LEDA; check not bypassed |
