# YY1705K1A0 ST7735S 1-Layer Breakout & Driver Library

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
[![KiCad](https://img.shields.io/badge/KiCad-v8%20%2F%20v9-blue.svg)](https://kicad.org/)
[![Arduino](https://img.shields.io/badge/Arduino-Compatible-teal.svg)](https://www.arduino.cc/)
[![PlatformIO](https://img.shields.io/badge/PlatformIO-Registry-orange.svg)](https://platformio.org/)

An open-source, **1-layer single-sided PCB breakout board** and **high-performance C++ driver** for the **YY1705K1A0** 1.8-inch TFT LCD SPI display (ST7735S controller, 128×160 RGB).

---

## Features

- **100% Single-Sided (1-Layer F.Cu)**: Designed specifically for home etching (toner transfer / photoresist). Zero jumpers or bottom vias required.
- **Through-Hole Passives (no SMD soldering)**: R1, R2, R3, C1, C2 are all standard through-hole parts — solder them with any basic iron. The only SMD part is the J2 FPC ZIF connector (required by the display flex cable).
- **Zero DRC Violations**: Optimized trace widths (0.35 mm signals, 0.60 mm power/GND) with 0.30 mm minimum clearances.
- **Clean Silkscreen**: Professional component labeling with open routing corridors.
- **Header-Only C++ Driver (`YY1705K1A0.h`)**:
  - Hardware SPI (fast DMA-capable) and Software bit-bang SPI constructors.
  - Complete 23-color RGB565 palette + `TFT_COLOR(r,g,b)` macro.
  - Fast graphic primitives (pixels, lines, rects, rounded rects, circles, triangles).
  - Built-in 5×7 ASCII font with scaling and Arduino `Print` interface (`print`/`println`).
  - Pre-built UI widgets (`drawProgressBar`).
  - Native support for display sleep, vertical scrolling, rotation (0°–270°), and partial mode.

---

## Hardware Overview

| Parameter | Specification |
|---|---|
| **Display Model** | YY1705K1A0 (1.8" TFT, 128×160) |
| **Driver IC** | Sitronix ST7735S |
| **Board Dimensions** | 34.0 mm × 53.0 mm |
| **Layers** | 1-Layer (Top Copper `F.Cu` Only) |
| **Interface** | 4-Wire SPI (3.3V Logic) |
| **Connectors** | `J1`: 7-Pin 2.54mm Header, `J2`: 12-Pin 0.5mm FPC |

---

## Pinout & Wiring

> **IMPORTANT**: This board and display operate strictly on **3.3V logic**. When interfacing with 5V microcontrollers (e.g. Arduino Uno / Mega), use a logic level shifter.

| J1 Pin | Label | Function | FPC Pin (J2) | MCU Connection (e.g., ESP32 / Arduino) |
|:---:|:---:|---|:---:|---|
| **1** | `+3V3` | +3.3V Power Supply | Pin 10 (`VDD`) | 3.3V Power Out |
| **2** | `GND` | Ground | Pins 2, 4, 11 | GND |
| **3** | `RST` | Reset (Active LOW) | Pin 5 (`RES`) | GPIO (e.g., D8) |
| **4** | `DC` | Data / Command Select | Pin 6 (`A0`) | GPIO (e.g., D9) |
| **5** | `MOSI` | SPI Data (SDA) | Pin 7 (`SDA`) | SPI MOSI (e.g., D11 / GPIO 23) |
| **6** | `SCK` | SPI Clock (SCL) | Pin 8 (`SCL`) | SPI SCK (e.g., D13 / GPIO 18) |
| **7** | `CS` | Chip Select (Active LOW) | Pin 9 (`CS`) | GPIO (e.g., D10 / GPIO 5) |

---

## Bill of Materials (BOM)

| Designator | Description | Package / Footprint | Quantity |
|---|---|---|:---:|
| **J1** | 7-Pin 2.54mm Header Male/Female | 1×07 Pin Header (0.1") THT | 1 |
| **J2** | 12-Pin 0.5mm Pitch Bottom-Contact FPC Connector | SMD 12-Pin 0.5mm **(only SMD part)** | 1 |
| **R1** | 22 Ω Backlight Current Limiter | Axial 1/4W THT, 7.62mm pitch (lying flat) | 1 |
| **R2, R3** | 10 kΩ Pull-up Resistors (`RESET`, `CS`) | Axial 1/4W THT, 5.08mm pitch (vertical mount) | 2 |
| **C1** | 10 µF 10V Ceramic/Electrolytic (Bulk Decoupling) | Disc/Radial THT, 5mm pitch | 1 |
| **C2** | 100 nF (0.1 µF) Ceramic Disc (HF Bypass) | Disc THT, 5mm pitch | 1 |

---

## Quick Start (Arduino / PlatformIO)

### Installation

1. Copy `YY1705K1A0.h` into your Arduino sketch folder or PlatformIO project `include/` directory.
2. In your sketch:

```cpp
#include <SPI.h>
#include "YY1705K1A0.h"

// Define pins
#define TFT_CS    10
#define TFT_DC    9
#define TFT_RST   8

// Hardware SPI instance (Fastest)
YY1705K1A0 tft(TFT_CS, TFT_DC, TFT_RST);

void setup() {
    // Initialize display with standard black-tab profile
    tft.begin(INITR_BLACKTAB);
    tft.fillScreen(TFT_BLACK);

    // Print text
    tft.setTextColor(TFT_WHITE, TFT_BLACK);
    tft.drawString(10, 20, "Hello World!", TFT_YELLOW, TFT_BLACK, 2);

    // Draw UI shapes
    tft.drawRoundRect(10, 60, 108, 30, 4, TFT_CYAN);
    tft.drawProgressBar(10, 100, 108, 14, 75, TFT_GREEN, TFT_DARKGREY, TFT_WHITE);
}

void loop() {
}
```

---

## DIY PCB Fabrication (Toner Transfer)

Print-ready vector PDF files scaled at 1:1 for DIY etching:

- **[YY1705K1A0_breakout_scaled_landscape.pdf](YY1705K1A0_breakout_scaled_landscape.pdf)**: 2 scaled boards per A4 page.
- **[YY1705K1A0_breakout_scaled_landscape_mirrored.pdf](YY1705K1A0_breakout_scaled_landscape_mirrored.pdf)**: Mirrored for direct iron-on toner transfer.

> **Printing Note**: Print with **Scale: 100% / Actual Size** enabled in your PDF viewer.

---

## Repository Structure

```
├── README.md                                          # Project documentation
├── LICENSE                                            # MIT Open-Source License
├── library.properties                                 # Arduino Library descriptor
├── library.json                                       # PlatformIO Library descriptor
├── YY1705K1A0.h                                       # Display driver header library
├── YY1705K1A0_breakout.kicad_pro                      # KiCad project file
├── YY1705K1A0_breakout.kicad_sch                      # KiCad schematic
├── YY1705K1A0_breakout.kicad_pcb                      # KiCad 1-layer PCB layout
├── BOM.csv                                            # Bill of Materials
├── display_connector_pinout.csv                       # FPC 12-pin reference sheet
├── WIRING_GUIDE.md                                    # Detailed wiring instructions
├── YY1705K1A0_breakout_scaled_landscape.pdf           # Printable A4 etching mask
├── YY1705K1A0_breakout_scaled_landscape_mirrored.pdf  # Mirrored etching mask
└── examples/
    └── GraphicTest/
        └── GraphicTest.ino                            # Complete demo sketch
```

---

## License

This project is open-source hardware and software licensed under the [MIT License](LICENSE).
