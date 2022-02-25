#include "gw_lcd.h"

uint8_t emulator_framebuffer[(256 + 8 + 8) * 240];
uint16_t framebuffer1[320 * 240 * 2];
uint16_t framebuffer2[320 * 240 * 2];
