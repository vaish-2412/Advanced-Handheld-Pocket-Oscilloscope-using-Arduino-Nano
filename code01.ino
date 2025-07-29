#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
//#include <Adafruit_SH1106.h>            // https://github.com/wonho-maker/Adafruit_SH1106
#include <EEPROM.h>

#define SCREEN_WIDTH   128              // OLED display width
#define SCREEN_HEIGHT   64              // OLED display height
#define REC_LENG       200              // size of wave data buffer
#define DISP_LENG      100              // size of display data
#define MIN_TRIG_SWING   5              // minimum trigger swing.(Display "Unsync" if swing smaller than this value
#define DOTS_DIV        25

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET     -1              // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 oled(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);   // device name is oled
//Adafruit_SH1106 oled(OLED_RESET);        // use this when SH1106

#define R_12k   4        //  12k ohm
#define R_820k  16       //  820k ohm  for AC low range
#define R_82k   17       //  82k omm for AC Hi range

// Range name table (those are stored in flash memory)
const char vRangeName[10][5] PROGMEM = {"A50V", "A 5V", " 50V", " 20V", " 10V", "  5V", "  2V", "  1V", "0.5V", "0.2V"}; // Vertical display character (number of characters including \ 0 is required)
const char * const vstring_table[] PROGMEM = {vRangeName[0], vRangeName[1], vRangeName[2], vRangeName[3], vRangeName[4], vRangeName[5], vRangeName[6], vRangeName[7], vRangeName[8], vRangeName[9]};
const char hRangeName[22][6] PROGMEM = {"200ms", "100ms", " 50ms", " 20ms", " 10ms", "  5ms", "  2ms", "  1ms", "500us", "200us", "100us", " 50us", " 81us", " 41us", " 20us", "156us", " 78us", " 31us", "15.6u", "7.8us", "3.1us", "1.56u"};  //  Hrizontal display characters
const char * const hstring_table[] PROGMEM = {hRangeName[0], hRangeName[1], hRangeName[2], hRangeName[3], hRangeName[4], hRangeName[5], hRangeName[6], hRangeName[7], hRangeName[8], hRangeName[9],
    hRangeName[10], hRangeName[11], hRangeName[12], hRangeName[13], hRangeName[14], hRangeName[15], hRangeName[16], hRangeName[17], hRangeName[18], hRangeName[19], hRangeName[20], hRangeName[21]};
const float hRangeValue[] PROGMEM = { 0.2, 0.1, 0.05, 0.02, 0.01, 0.005, 0.002, 0.001, 0.5e-3, 0.2e-3, 0.2e-3, 0.2e-3, 81.3e-6, 81.3e-6, 81.3e-6, 156.25e-6, 78.125e-6, 31.25e-6, 15.625e-6, 7.8125e-6, 3.125e-6, 1.5625e-6}; // record speed in second. ( = 25pix on screen) this value used for freq calc.

int waveBuff[REC_LENG];        // wave form buffer (RAM remaining capacity is barely)
char chrBuff[8];               // display string buffer
char hScale[] = "xxxAs";       // horizontal scale character
char vScale[] = "xxxx";        // vartical scale

float lsb5V    = 0.00563965;   // (5V)sensivity coefficient of 5V range. std=0.00563965 1.1*630/(1024*120)
float lsb50V   = 0.0512939;    // (50V)sensivity coefficient of 50V range. std=0.0512939 1.1*520.91/(1024*10.91)

float lsb5Vac  = 0.00630776;   //  std=0.00630776 V/LSB
float lsb50Vac = 0.0579751;    //  std=0.0579751 V/LSB

volatile int vRange;           // V-range number                   2:50V,  3:20V,  4:10V,  5:5V,  6:2V,  7:1V,  8:0.5V,  9:0.2V
volatile int hRange;           // H-range nubmer 0:200ms, 1:100ms, 2:50ms, 3:20ms, 4:10ms, 5:5ms, 6;2ms, 7:1ms, 8:500us, 9:200us, 10:100us, 11:50us, 12:
volatile int trigD;            // trigger slope flag,     0:positive 1:negative
volatile int scopeP;           // operation scope position number. 0:Veratical, 1:Hrizontal, 2:Trigger slope, 3:DC/AC/FFT
volatile boolean hold = false; // hold flag
volatile boolean switchPushed = false; // flag of switch pusshed !
volatile int saveTimer;        // remaining time for saving EEPROM
int timeExec;                  // approx. execution time of current range setting (ms)
