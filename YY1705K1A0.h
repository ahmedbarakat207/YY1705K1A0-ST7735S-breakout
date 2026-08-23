#pragma once
#ifndef YY1705K1A0_H
#define YY1705K1A0_H

#include <Arduino.h>
#include <SPI.h>

#define TFT_WIDTH           128
#define TFT_HEIGHT          160
#define TFT_SPI_FREQ        32000000UL

#define INITR_GREENTAB      0x00
#define INITR_REDTAB        0x01
#define INITR_BLACKTAB      0x02
#define INITR_GREENTAB2     0x03
#define INITR_MINI160x80    0x04

#define ST7735_NOP          0x00
#define ST7735_SWRESET      0x01
#define ST7735_RDDID        0x04
#define ST7735_RDDST        0x09
#define ST7735_SLPIN        0x10
#define ST7735_SLPOUT       0x11
#define ST7735_PTLON        0x12
#define ST7735_NORON        0x13
#define ST7735_INVOFF       0x20
#define ST7735_INVON        0x21
#define ST7735_GAMSET       0x26
#define ST7735_DISPOFF      0x28
#define ST7735_DISPON       0x29
#define ST7735_CASET        0x2A
#define ST7735_RASET        0x2B
#define ST7735_RAMWR        0x2C
#define ST7735_RAMRD        0x2E
#define ST7735_PTLAR        0x30
#define ST7735_VSCRDEF      0x33
#define ST7735_TEOFF        0x34
#define ST7735_TEON         0x35
#define ST7735_MADCTL       0x36
#define ST7735_VSCRSADD     0x37
#define ST7735_IDMOFF       0x38
#define ST7735_IDMON        0x39
#define ST7735_COLMOD       0x3A
#define ST7735_FRMCTR1      0xB1
#define ST7735_FRMCTR2      0xB2
#define ST7735_FRMCTR3      0xB3
#define ST7735_INVCTR       0xB4
#define ST7735_DISSET5      0xB6
#define ST7735_PWCTR1       0xC0
#define ST7735_PWCTR2       0xC1
#define ST7735_PWCTR3       0xC2
#define ST7735_PWCTR4       0xC3
#define ST7735_PWCTR5       0xC4
#define ST7735_VMCTR1       0xC5
#define ST7735_VMOFCTR      0xC7
#define ST7735_WRID2        0xD1
#define ST7735_WRID3        0xD2
#define ST7735_RDID1        0xDA
#define ST7735_RDID2        0xDB
#define ST7735_RDID3        0xDC
#define ST7735_RDID4        0xDD
#define ST7735_GMCTRP1      0xE0
#define ST7735_GMCTRN1      0xE1
#define ST7735_EXTCTRL      0xF0

#define MADCTL_MY           0x80
#define MADCTL_MX           0x40
#define MADCTL_MV           0x20
#define MADCTL_ML           0x10
#define MADCTL_BGR          0x08
#define MADCTL_MH           0x04

#define TFT_BLACK           0x0000
#define TFT_WHITE           0xFFFF
#define TFT_RED             0xF800
#define TFT_GREEN           0x07E0
#define TFT_BLUE            0x001F
#define TFT_CYAN            0x07FF
#define TFT_MAGENTA         0xF81F
#define TFT_YELLOW          0xFFE0
#define TFT_ORANGE          0xFD20
#define TFT_PINK            0xFC18
#define TFT_PURPLE          0x8010
#define TFT_NAVY            0x000F
#define TFT_DARKGREEN       0x03E0
#define TFT_DARKCYAN        0x03EF
#define TFT_MAROON          0x7800
#define TFT_OLIVE           0x7BE0
#define TFT_DARKGREY        0x7BEF
#define TFT_LIGHTGREY       0xC618
#define TFT_GREENYELLOW     0xB7E0
#define TFT_GOLD            0xFEA0
#define TFT_SILVER          0xC618
#define TFT_SKYBLUE         0x867D
#define TFT_VIOLET          0x915C
#define TFT_TRANSPARENT     0x0120

#define TFT_COLOR(r,g,b) \
    ((uint16_t)(((uint16_t)((r)&0xF8)<<8)|(((g)&0xFC)<<3)|((b)>>3)))

static const uint8_t PROGMEM _font5x7[][5] = {
    {0x00,0x00,0x00,0x00,0x00},{0x00,0x00,0x5F,0x00,0x00},
    {0x00,0x07,0x00,0x07,0x00},{0x14,0x7F,0x14,0x7F,0x14},
    {0x24,0x2A,0x7F,0x2A,0x12},{0x23,0x13,0x08,0x64,0x62},
    {0x36,0x49,0x55,0x22,0x50},{0x00,0x05,0x03,0x00,0x00},
    {0x00,0x1C,0x22,0x41,0x00},{0x00,0x41,0x22,0x1C,0x00},
    {0x08,0x2A,0x1C,0x2A,0x08},{0x08,0x08,0x3E,0x08,0x08},
    {0x00,0x50,0x30,0x00,0x00},{0x08,0x08,0x08,0x08,0x08},
    {0x00,0x60,0x60,0x00,0x00},{0x20,0x10,0x08,0x04,0x02},
    {0x3E,0x51,0x49,0x45,0x3E},{0x00,0x42,0x7F,0x40,0x00},
    {0x42,0x61,0x51,0x49,0x46},{0x21,0x41,0x45,0x4B,0x31},
    {0x18,0x14,0x12,0x7F,0x10},{0x27,0x45,0x45,0x45,0x39},
    {0x3C,0x4A,0x49,0x49,0x30},{0x01,0x71,0x09,0x05,0x03},
    {0x36,0x49,0x49,0x49,0x36},{0x06,0x49,0x49,0x29,0x1E},
    {0x00,0x36,0x36,0x00,0x00},{0x00,0x56,0x36,0x00,0x00},
    {0x00,0x08,0x14,0x22,0x41},{0x14,0x14,0x14,0x14,0x14},
    {0x41,0x22,0x14,0x08,0x00},{0x02,0x01,0x51,0x09,0x06},
    {0x32,0x49,0x79,0x41,0x3E},{0x7E,0x11,0x11,0x11,0x7E},
    {0x7F,0x49,0x49,0x49,0x36},{0x3E,0x41,0x41,0x41,0x22},
    {0x7F,0x41,0x41,0x22,0x1C},{0x7F,0x49,0x49,0x49,0x41},
    {0x7F,0x09,0x09,0x09,0x01},{0x3E,0x41,0x49,0x49,0x7A},
    {0x7F,0x08,0x08,0x08,0x7F},{0x00,0x41,0x7F,0x41,0x00},
    {0x20,0x40,0x41,0x3F,0x01},{0x7F,0x08,0x14,0x22,0x41},
    {0x7F,0x40,0x40,0x40,0x40},{0x7F,0x02,0x04,0x02,0x7F},
    {0x7F,0x04,0x08,0x10,0x7F},{0x3E,0x41,0x41,0x41,0x3E},
    {0x7F,0x09,0x09,0x09,0x06},{0x3E,0x41,0x51,0x21,0x5E},
    {0x7F,0x09,0x19,0x29,0x46},{0x46,0x49,0x49,0x49,0x31},
    {0x01,0x01,0x7F,0x01,0x01},{0x3F,0x40,0x40,0x40,0x3F},
    {0x1F,0x20,0x40,0x20,0x1F},{0x3F,0x40,0x38,0x40,0x3F},
    {0x63,0x14,0x08,0x14,0x63},{0x07,0x08,0x70,0x08,0x07},
    {0x61,0x51,0x49,0x45,0x43},{0x00,0x7F,0x41,0x41,0x00},
    {0x02,0x04,0x08,0x10,0x20},{0x00,0x41,0x41,0x7F,0x00},
    {0x04,0x02,0x01,0x02,0x04},{0x40,0x40,0x40,0x40,0x40},
    {0x00,0x01,0x02,0x04,0x00},{0x20,0x54,0x54,0x54,0x78},
    {0x7F,0x48,0x44,0x44,0x38},{0x38,0x44,0x44,0x44,0x20},
    {0x38,0x44,0x44,0x48,0x7F},{0x38,0x54,0x54,0x54,0x18},
    {0x08,0x7E,0x09,0x01,0x02},{0x0C,0x52,0x52,0x52,0x3E},
    {0x7F,0x08,0x04,0x04,0x78},{0x00,0x44,0x7D,0x40,0x00},
    {0x20,0x40,0x44,0x3D,0x00},{0x7F,0x10,0x28,0x44,0x00},
    {0x00,0x41,0x7F,0x40,0x00},{0x7C,0x04,0x18,0x04,0x78},
    {0x7C,0x08,0x04,0x04,0x78},{0x38,0x44,0x44,0x44,0x38},
    {0x7C,0x14,0x14,0x14,0x08},{0x08,0x14,0x14,0x18,0x7C},
    {0x7C,0x08,0x04,0x04,0x08},{0x48,0x54,0x54,0x54,0x20},
    {0x04,0x3F,0x44,0x40,0x20},{0x3C,0x40,0x40,0x20,0x7C},
    {0x1C,0x20,0x40,0x20,0x1C},{0x3C,0x40,0x30,0x40,0x3C},
    {0x44,0x28,0x10,0x28,0x44},{0x0C,0x50,0x50,0x50,0x3C},
    {0x44,0x64,0x54,0x4C,0x44},{0x00,0x08,0x36,0x41,0x00},
    {0x00,0x00,0x7F,0x00,0x00},{0x00,0x41,0x36,0x08,0x00},
    {0x08,0x08,0x2A,0x1C,0x08},{0x08,0x1C,0x2A,0x08,0x08},
};

class YY1705K1A0 : public Print {
public:

    YY1705K1A0(int8_t cs, int8_t dc, int8_t rst = -1)
        : _cs(cs), _dc(dc), _rst(rst), _mosi(-1), _sck(-1),
          _cursor_x(0), _cursor_y(0),
          _textColor(TFT_WHITE), _bgColor(TFT_BLACK),
          _textScale(1), _wrap(true),
          _width(TFT_WIDTH), _height(TFT_HEIGHT), _rotation(0),
          _colOffset(0), _rowOffset(0), _invertOnInit(true)
    {}

    YY1705K1A0(int8_t cs, int8_t dc, int8_t rst, int8_t mosi, int8_t sck)
        : _cs(cs), _dc(dc), _rst(rst), _mosi(mosi), _sck(sck),
          _cursor_x(0), _cursor_y(0),
          _textColor(TFT_WHITE), _bgColor(TFT_BLACK),
          _textScale(1), _wrap(true),
          _width(TFT_WIDTH), _height(TFT_HEIGHT), _rotation(0),
          _colOffset(0), _rowOffset(0), _invertOnInit(true)
    {}

    void begin(uint8_t tabcolor = INITR_BLACKTAB) {
        switch (tabcolor) {
            case INITR_GREENTAB:
                _colOffset = 2; _rowOffset = 1; _invertOnInit = false; break;
            case INITR_GREENTAB2:
                _colOffset = 2; _rowOffset = 3; _invertOnInit = false; break;
            case INITR_REDTAB:
                _colOffset = 0; _rowOffset = 0; _invertOnInit = false; break;
            case INITR_MINI160x80:
                _colOffset = 26; _rowOffset = 1; _invertOnInit = false; break;
            case INITR_BLACKTAB:
            default:
                _colOffset = 0; _rowOffset = 0; _invertOnInit = true; break;
        }

        pinMode(_cs, OUTPUT);
        pinMode(_dc, OUTPUT);
        digitalWrite(_cs, HIGH);

        if (_mosi < 0) {
            SPI.begin();
        } else {
            pinMode(_mosi, OUTPUT);
            pinMode(_sck,  OUTPUT);
            digitalWrite(_sck,  LOW);
            digitalWrite(_mosi, LOW);
        }

        if (_rst >= 0) {
            pinMode(_rst, OUTPUT);
            digitalWrite(_rst, HIGH); delay(5);
            digitalWrite(_rst, LOW);  delay(20);
            digitalWrite(_rst, HIGH); delay(150);
        }

        _initST7735S();
    }

    void sleepIn()    { _writeCommand(ST7735_SLPIN);  delay(5);   }
    void sleepOut()   { _writeCommand(ST7735_SLPOUT); delay(120); }
    void displayOn()  { _writeCommand(ST7735_DISPON);             }
    void displayOff() { _writeCommand(ST7735_DISPOFF);            }
    void softReset()  { _writeCommand(ST7735_SWRESET); delay(150);}

    void setRotation(uint8_t r) {
        _rotation = r & 3;
        uint8_t madctl = 0;
        switch (_rotation) {
            case 0: madctl = MADCTL_MX | MADCTL_BGR;
                    _width = TFT_WIDTH;  _height = TFT_HEIGHT; break;
            case 1: madctl = MADCTL_MV | MADCTL_BGR;
                    _width = TFT_HEIGHT; _height = TFT_WIDTH;  break;
            case 2: madctl = MADCTL_MY | MADCTL_BGR;
                    _width = TFT_WIDTH;  _height = TFT_HEIGHT; break;
            case 3: madctl = MADCTL_MX | MADCTL_MY | MADCTL_MV | MADCTL_BGR;
                    _width = TFT_HEIGHT; _height = TFT_WIDTH;  break;
        }
        _writeCommand(ST7735_MADCTL);
        _writeData(madctl);
    }

    uint8_t getRotation() const { return _rotation; }
    int16_t width()       const { return (int16_t)_width;  }
    int16_t height()      const { return (int16_t)_height; }

    void invertDisplay(bool inv) {
        _writeCommand(inv ? ST7735_INVON : ST7735_INVOFF);
    }

    void idleMode(bool en) {
        _writeCommand(en ? ST7735_IDMON : ST7735_IDMOFF);
    }

    void tearingEffect(bool en) {
        if (en) { _writeCommand(ST7735_TEON); _writeData(0x00); }
        else      _writeCommand(ST7735_TEOFF);
    }

    void setGamma(uint8_t curve) {
        _writeCommand(ST7735_GAMSET);
        _writeData(curve & 0x0F);
    }

    void defineScrollArea(uint16_t topFixed, uint16_t scrollArea, uint16_t bottomFixed) {
        _writeCommand(ST7735_VSCRDEF);
        _writeData(topFixed    >> 8); _writeData(topFixed    & 0xFF);
        _writeData(scrollArea  >> 8); _writeData(scrollArea  & 0xFF);
        _writeData(bottomFixed >> 8); _writeData(bottomFixed & 0xFF);
    }

    void setScrollStart(uint16_t vsp) {
        _writeCommand(ST7735_VSCRSADD);
        _writeData(vsp >> 8);
        _writeData(vsp & 0xFF);
    }

    void setPartialArea(uint16_t startRow, uint16_t endRow) {
        _writeCommand(ST7735_PTLAR);
        _writeData(startRow >> 8); _writeData(startRow & 0xFF);
        _writeData(endRow   >> 8); _writeData(endRow   & 0xFF);
        _writeCommand(ST7735_PTLON);
    }

    void normalMode() { _writeCommand(ST7735_NORON); }

    void drawPixel(int16_t x, int16_t y, uint16_t color) {
        if (x < 0 || x >= _width || y < 0 || y >= _height) return;
        _setAddrWindow(x, y, x, y);
        _writeColor(color, 1);
    }

    void fillScreen(uint16_t color) {
        fillRect(0, 0, _width, _height, color);
    }

    void drawFastHLine(int16_t x, int16_t y, int16_t w, uint16_t color) {
        if (y < 0 || y >= _height || x >= _width || w <= 0) return;
        if (x < 0)          { w += x; x = 0; }
        if (x + w > _width)   w = _width - x;
        _setAddrWindow(x, y, x + w - 1, y);
        _writeColor(color, w);
    }

    void drawFastVLine(int16_t x, int16_t y, int16_t h, uint16_t color) {
        if (x < 0 || x >= _width || y >= _height || h <= 0) return;
        if (y < 0)           { h += y; y = 0; }
        if (y + h > _height)   h = _height - y;
        _setAddrWindow(x, y, x, y + h - 1);
        _writeColor(color, h);
    }

    void drawLine(int16_t x0, int16_t y0, int16_t x1, int16_t y1, uint16_t color) {
        if (x0 == x1) { drawFastVLine(x0, _min(y0,y1), _abs(y1-y0)+1, color); return; }
        if (y0 == y1) { drawFastHLine(_min(x0,x1), y0, _abs(x1-x0)+1, color); return; }
        bool steep = _abs(y1-y0) > _abs(x1-x0);
        if (steep)   { _swap(x0,y0); _swap(x1,y1); }
        if (x0 > x1) { _swap(x0,x1); _swap(y0,y1); }
        int16_t dx = x1-x0, dy = _abs(y1-y0), err = dx >> 1;
        int16_t ystep = (y0 < y1) ? 1 : -1;
        for (; x0 <= x1; x0++) {
            steep ? drawPixel(y0, x0, color) : drawPixel(x0, y0, color);
            err -= dy;
            if (err < 0) { y0 += ystep; err += dx; }
        }
    }

    void drawRect(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color) {
        drawFastHLine(x,     y,     w, color);
        drawFastHLine(x,     y+h-1, w, color);
        drawFastVLine(x,     y,     h, color);
        drawFastVLine(x+w-1, y,     h, color);
    }

    void fillRect(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color) {
        if (x >= _width || y >= _height || w <= 0 || h <= 0) return;
        if (x < 0)          { w += x; x = 0; }
        if (y < 0)          { h += y; y = 0; }
        if (x + w > _width)   w = _width  - x;
        if (y + h > _height)  h = _height - y;
        _setAddrWindow(x, y, x+w-1, y+h-1);
        _writeColor(color, (uint32_t)w * h);
    }

    void drawRoundRect(int16_t x, int16_t y, int16_t w, int16_t h,
                       int16_t r, uint16_t color) {
        drawFastHLine(x+r,   y,     w-2*r, color);
        drawFastHLine(x+r,   y+h-1, w-2*r, color);
        drawFastVLine(x,     y+r,   h-2*r, color);
        drawFastVLine(x+w-1, y+r,   h-2*r, color);
        _drawCorner(x+r,     y+r,     r, 1, color);
        _drawCorner(x+w-r-1, y+r,     r, 2, color);
        _drawCorner(x+w-r-1, y+h-r-1, r, 4, color);
        _drawCorner(x+r,     y+h-r-1, r, 8, color);
    }

    void fillRoundRect(int16_t x, int16_t y, int16_t w, int16_t h,
                       int16_t r, uint16_t color) {
        fillRect(x+r, y, w-2*r, h, color);
        _fillCorner(x+w-r-1, y+r, r, 1, h-2*r-1, color);
        _fillCorner(x,       y+r, r, 2, h-2*r-1, color);
    }

    void drawCircle(int16_t x0, int16_t y0, int16_t r, uint16_t color) {
        int16_t f=1-r, ddx=1, ddy=-2*r, x=0, y=r;
        drawPixel(x0,   y0+r, color); drawPixel(x0,   y0-r, color);
        drawPixel(x0+r, y0,   color); drawPixel(x0-r, y0,   color);
        while (x < y) {
            if (f >= 0) { y--; ddy+=2; f+=ddy; }
            x++; ddx+=2; f+=ddx;
            drawPixel(x0+x,y0+y,color); drawPixel(x0-x,y0+y,color);
            drawPixel(x0+x,y0-y,color); drawPixel(x0-x,y0-y,color);
            drawPixel(x0+y,y0+x,color); drawPixel(x0-y,y0+x,color);
            drawPixel(x0+y,y0-x,color); drawPixel(x0-y,y0-x,color);
        }
    }

    void fillCircle(int16_t x0, int16_t y0, int16_t r, uint16_t color) {
        drawFastVLine(x0, y0-r, 2*r+1, color);
        int16_t f=1-r, ddx=1, ddy=-2*r, x=0, y=r;
        while (x < y) {
            if (f >= 0) { y--; ddy+=2; f+=ddy; }
            x++; ddx+=2; f+=ddx;
            drawFastVLine(x0+x, y0-y, 2*y+1, color);
            drawFastVLine(x0-x, y0-y, 2*y+1, color);
            drawFastVLine(x0+y, y0-x, 2*x+1, color);
            drawFastVLine(x0-y, y0-x, 2*x+1, color);
        }
    }

    void drawTriangle(int16_t x0, int16_t y0,
                      int16_t x1, int16_t y1,
                      int16_t x2, int16_t y2, uint16_t color) {
        drawLine(x0,y0,x1,y1,color);
        drawLine(x1,y1,x2,y2,color);
        drawLine(x2,y2,x0,y0,color);
    }

    void fillTriangle(int16_t x0, int16_t y0,
                      int16_t x1, int16_t y1,
                      int16_t x2, int16_t y2, uint16_t color) {
        if (y0 > y1) { _swap(y0,y1); _swap(x0,x1); }
        if (y1 > y2) { _swap(y1,y2); _swap(x1,x2); }
        if (y0 > y1) { _swap(y0,y1); _swap(x0,x1); }
        if (y0 == y2) {
            int16_t a = _min(x0, _min(x1, x2));
            int16_t b = _max(x0, _max(x1, x2));
            drawFastHLine(a, y0, b-a+1, color);
            return;
        }
        int16_t dx01=x1-x0, dy01=y1-y0, dx02=x2-x0, dy02=y2-y0;
        int16_t dx12=x2-x1, dy12=y2-y1;
        int32_t sa=0, sb=0;
        int16_t last = (y1 == y2) ? y1 : y1-1;
        for (int16_t y=y0; y<=last; y++) {
            int16_t a=x0+sa/dy01, b=x0+sb/dy02;
            sa+=dx01; sb+=dx02;
            if (a > b) _swap(a,b);
            drawFastHLine(a, y, b-a+1, color);
        }
        sa = (int32_t)dx12*(y0-y1);
        sb = (int32_t)dx02*(y0-y1);
        for (int16_t y=last+1; y<=y2; y++) {
            int16_t a=x1+sa/dy12, b=x0+sb/dy02;
            sa+=dx12; sb+=dx02;
            if (a > b) _swap(a,b);
            drawFastHLine(a, y, b-a+1, color);
        }
    }

    void drawBitmap(int16_t x, int16_t y, const uint16_t* bitmap,
                    int16_t w, int16_t h) {
        _setAddrWindow(x, y, x+w-1, y+h-1);
        _csLow(); _dcHigh();
        for (int32_t i=0; i<(int32_t)w*h; i++) {
            uint16_t c = bitmap[i];
            _spiWrite(c>>8); _spiWrite(c&0xFF);
        }
        _csHigh();
    }

    void drawBitmapPGM(int16_t x, int16_t y, const uint16_t* bitmap,
                       int16_t w, int16_t h) {
        _setAddrWindow(x, y, x+w-1, y+h-1);
        _csLow(); _dcHigh();
        for (int32_t i=0; i<(int32_t)w*h; i++) {
            uint16_t c = pgm_read_word(&bitmap[i]);
            _spiWrite(c>>8); _spiWrite(c&0xFF);
        }
        _csHigh();
    }

    void drawBitmap1bpp(int16_t x, int16_t y, const uint8_t* bitmap,
                        int16_t w, int16_t h,
                        uint16_t fgColor, uint16_t bgColor = TFT_BLACK) {
        for (int16_t j=0; j<h; j++) {
            for (int16_t i=0; i<w; i++) {
                uint8_t byte = pgm_read_byte(&bitmap[(j*w+i)/8]);
                bool bit = (byte >> (7-(i&7))) & 1;
                if (bit) {
                    drawPixel(x+i, y+j, fgColor);
                } else if (bgColor != TFT_TRANSPARENT) {
                    drawPixel(x+i, y+j, bgColor);
                }
            }
        }
    }

    void    setCursor(int16_t x, int16_t y)          { _cursor_x=x; _cursor_y=y; }
    int16_t getCursorX() const                        { return _cursor_x; }
    int16_t getCursorY() const                        { return _cursor_y; }
    void    setTextColor(uint16_t fg)                 { _textColor=fg; _bgColor=fg; }
    void    setTextColor(uint16_t fg, uint16_t bg)    { _textColor=fg; _bgColor=bg; }
    void    setTextSize(uint8_t s)                    { _textScale=(s>0)?s:1; }
    void    setTextWrap(bool wrap)                    { _wrap=wrap; }
    int16_t textWidth(const char* str)                { return (int16_t)(strlen(str)*6*_textScale); }
    int16_t textHeight()                              { return (int16_t)(8*_textScale); }

    size_t write(uint8_t c) override {
        if (c == '\n') {
            _cursor_x  = 0;
            _cursor_y += 8 * _textScale;
        } else if (c == '\r') {
            _cursor_x = 0;
        } else {
            if (_wrap && (_cursor_x + 6*_textScale > _width)) {
                _cursor_x  = 0;
                _cursor_y += 8*_textScale;
            }
            _drawChar(_cursor_x, _cursor_y, c, _textColor, _bgColor, _textScale);
            _cursor_x += 6*_textScale;
        }
        return 1;
    }

    void drawString(int16_t x, int16_t y, const char* str,
                    uint16_t fg, uint16_t bg, uint8_t scale=1) {
        setCursor(x,y); setTextColor(fg,bg); setTextSize(scale); print(str);
    }

    void drawProgressBar(int16_t x, int16_t y, int16_t w, int16_t h,
                         uint8_t pct,
                         uint16_t fgColor,
                         uint16_t bgColor = TFT_DARKGREY,
                         uint16_t border  = TFT_WHITE) {
        pct = _constrain(pct, (uint8_t)0, (uint8_t)100);
        drawRect(x, y, w, h, border);
        int16_t fill = (int16_t)((long)(w-2)*pct/100);
        if (fill > 0)   fillRect(x+1,      y+1, fill,     h-2, fgColor);
        if (fill < w-2) fillRect(x+1+fill, y+1, w-2-fill, h-2, bgColor);
    }

    void sendCommand(uint8_t cmd, const uint8_t* args=nullptr, uint8_t nargs=0) {
        _writeCommand(cmd);
        for (uint8_t i=0; i<nargs; i++) _writeData(args[i]);
    }

    void setAddrWindow(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1) {
        _setAddrWindow(x0, y0, x1, y1);
    }

    void startWrite() { _csLow(); _dcHigh(); }
    void endWrite()   { _csHigh(); }

    void pushColor(uint16_t color) {
        _spiWrite(color>>8); _spiWrite(color&0xFF);
    }

    void pushColor(uint16_t color, uint32_t count) {
        _csLow(); _dcHigh();
        uint8_t hi=color>>8, lo=color&0xFF;
        while (count--) { _spiWrite(hi); _spiWrite(lo); }
        _csHigh();
    }

    void pushColors(const uint16_t* colors, uint32_t len) {
        _csLow(); _dcHigh();
        for (uint32_t i=0; i<len; i++) {
            _spiWrite(colors[i]>>8); _spiWrite(colors[i]&0xFF);
        }
        _csHigh();
    }

private:
    int8_t   _cs, _dc, _rst, _mosi, _sck;
    int16_t  _cursor_x, _cursor_y;
    uint16_t _textColor, _bgColor;
    uint8_t  _textScale;
    bool     _wrap;
    uint16_t _width, _height;
    uint8_t  _rotation;
    uint8_t  _colOffset;
    uint8_t  _rowOffset;
    bool     _invertOnInit;

    inline void _csLow()  { digitalWrite(_cs, LOW);  }
    inline void _csHigh() { digitalWrite(_cs, HIGH); }
    inline void _dcLow()  { digitalWrite(_dc, LOW);  }
    inline void _dcHigh() { digitalWrite(_dc, HIGH); }

    void _spiWrite(uint8_t b) {
        if (_mosi < 0) {
            SPI.transfer(b);
        } else {
            for (uint8_t bit=0x80; bit; bit>>=1) {
                digitalWrite(_mosi, (b & bit) ? HIGH : LOW);
                digitalWrite(_sck, HIGH);
                digitalWrite(_sck, LOW);
            }
        }
    }

    void _writeCommand(uint8_t cmd) {
        if (_mosi < 0) SPI.beginTransaction(SPISettings(TFT_SPI_FREQ, MSBFIRST, SPI_MODE0));
        _csLow(); _dcLow();
        _spiWrite(cmd);
        _csHigh();
        if (_mosi < 0) SPI.endTransaction();
    }

    void _writeData(uint8_t data) {
        if (_mosi < 0) SPI.beginTransaction(SPISettings(TFT_SPI_FREQ, MSBFIRST, SPI_MODE0));
        _csLow(); _dcHigh();
        _spiWrite(data);
        _csHigh();
        if (_mosi < 0) SPI.endTransaction();
    }

    void _setAddrWindow(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1) {
        x0 += _colOffset; x1 += _colOffset;
        y0 += _rowOffset; y1 += _rowOffset;
        if (_mosi < 0) SPI.beginTransaction(SPISettings(TFT_SPI_FREQ, MSBFIRST, SPI_MODE0));
        _csLow();
        _dcLow();  _spiWrite(ST7735_CASET);
        _dcHigh(); _spiWrite(x0>>8); _spiWrite(x0); _spiWrite(x1>>8); _spiWrite(x1);
        _dcLow();  _spiWrite(ST7735_RASET);
        _dcHigh(); _spiWrite(y0>>8); _spiWrite(y0); _spiWrite(y1>>8); _spiWrite(y1);
        _dcLow();  _spiWrite(ST7735_RAMWR);
        _dcHigh();
        _csHigh();
        if (_mosi < 0) SPI.endTransaction();
    }

    void _writeColor(uint16_t color, uint32_t count) {
        if (_mosi < 0) SPI.beginTransaction(SPISettings(TFT_SPI_FREQ, MSBFIRST, SPI_MODE0));
        _csLow(); _dcHigh();
        uint8_t hi=color>>8, lo=color&0xFF;
        while (count--) { _spiWrite(hi); _spiWrite(lo); }
        _csHigh();
        if (_mosi < 0) SPI.endTransaction();
    }

    void _initST7735S() {
        _writeCommand(ST7735_SWRESET); delay(150);
        _writeCommand(ST7735_SLPOUT);  delay(500);
        _writeCommand(ST7735_FRMCTR1);
        _writeData(0x01); _writeData(0x2C); _writeData(0x2D);
        _writeCommand(ST7735_FRMCTR2);
        _writeData(0x01); _writeData(0x2C); _writeData(0x2D);
        _writeCommand(ST7735_FRMCTR3);
        _writeData(0x01); _writeData(0x2C); _writeData(0x2D);
        _writeData(0x01); _writeData(0x2C); _writeData(0x2D);
        _writeCommand(ST7735_INVCTR); _writeData(0x07);
        _writeCommand(ST7735_PWCTR1); _writeData(0xA2); _writeData(0x02); _writeData(0x84);
        _writeCommand(ST7735_PWCTR2); _writeData(0xC5);
        _writeCommand(ST7735_PWCTR3); _writeData(0x0A); _writeData(0x00);
        _writeCommand(ST7735_PWCTR4); _writeData(0x8A); _writeData(0x2A);
        _writeCommand(ST7735_PWCTR5); _writeData(0x8A); _writeData(0xEE);
        _writeCommand(ST7735_VMCTR1); _writeData(0x0E);
        _writeCommand(_invertOnInit ? ST7735_INVON : ST7735_INVOFF);
        _writeCommand(ST7735_MADCTL); _writeData(MADCTL_MX | MADCTL_BGR);
        _writeCommand(ST7735_COLMOD); _writeData(0x05);
        _writeCommand(ST7735_GMCTRP1);
        _writeData(0x0F); _writeData(0x1A); _writeData(0x0F); _writeData(0x18);
        _writeData(0x2F); _writeData(0x28); _writeData(0x20); _writeData(0x22);
        _writeData(0x1F); _writeData(0x1B); _writeData(0x23); _writeData(0x37);
        _writeData(0x00); _writeData(0x07); _writeData(0x02); _writeData(0x10);
        _writeCommand(ST7735_GMCTRN1);
        _writeData(0x0F); _writeData(0x1B); _writeData(0x0F); _writeData(0x17);
        _writeData(0x33); _writeData(0x2C); _writeData(0x29); _writeData(0x2E);
        _writeData(0x30); _writeData(0x30); _writeData(0x39); _writeData(0x3F);
        _writeData(0x00); _writeData(0x07); _writeData(0x03); _writeData(0x10);
        _writeCommand(ST7735_NORON);  delay(10);
        _writeCommand(ST7735_DISPON); delay(100);
        setRotation(0);
    }

    void _drawChar(int16_t x, int16_t y, uint8_t c,
                   uint16_t fg, uint16_t bg, uint8_t sz) {
        if (c < 0x20 || c > 0x7F) c = '?';
        const uint8_t* glyph = _font5x7[c - 0x20];
        for (uint8_t col=0; col<5; col++) {
            uint8_t bits = pgm_read_byte(&glyph[col]);
            for (uint8_t row=0; row<7; row++) {
                uint16_t color = (bits & (1<<row)) ? fg : bg;
                if (sz == 1) drawPixel(x+col,    y+row,    color);
                else         fillRect (x+col*sz,  y+row*sz, sz, sz, color);
            }
        }
        for (uint8_t row=0; row<7; row++) {
            if (sz == 1) drawPixel(x+5,    y+row,    bg);
            else         fillRect (x+5*sz,  y+row*sz, sz, sz, bg);
        }
    }

    void _drawCorner(int16_t x0, int16_t y0, int16_t r, uint8_t mask, uint16_t color) {
        int16_t f=1-r, ddx=1, ddy=-2*r, x=0, y=r;
        while (x < y) {
            if (f >= 0) { y--; ddy+=2; f+=ddy; }
            x++; ddx+=2; f+=ddx;
            if (mask & 0x4) { drawPixel(x0+x,y0+y,color); drawPixel(x0+y,y0+x,color); }
            if (mask & 0x2) { drawPixel(x0+x,y0-y,color); drawPixel(x0+y,y0-x,color); }
            if (mask & 0x8) { drawPixel(x0-y,y0+x,color); drawPixel(x0-x,y0+y,color); }
            if (mask & 0x1) { drawPixel(x0-y,y0-x,color); drawPixel(x0-x,y0-y,color); }
        }
    }

    void _fillCorner(int16_t x0, int16_t y0, int16_t r, uint8_t mask,
                     int16_t delta, uint16_t color) {
        int16_t f=1-r, ddx=1, ddy=-2*r, x=0, y=r;
        while (x < y) {
            if (f >= 0) { y--; ddy+=2; f+=ddy; }
            x++; ddx+=2; f+=ddx;
            if (mask & 0x1) {
                drawFastVLine(x0+x, y0-y, 2*y+delta, color);
                drawFastVLine(x0+y, y0-x, 2*x+delta, color);
            }
            if (mask & 0x2) {
                drawFastVLine(x0-x, y0-y, 2*y+delta, color);
                drawFastVLine(x0-y, y0-x, 2*x+delta, color);
            }
        }
    }

    template<typename T> static void _swap(T& a, T& b) { T t=a; a=b; b=t; }
    template<typename T> static T _min(T a, T b) { return (a < b) ? a : b; }
    template<typename T> static T _max(T a, T b) { return (a > b) ? a : b; }
    template<typename T> static T _abs(T a) { return (a < 0) ? -a : a; }
    template<typename T> static T _constrain(T x, T low, T high) {
        return (x < low) ? low : ((x > high) ? high : x);
    }
};

#endif
