#ifndef I_VGA_H
#define  I_VGA_H

#include "esp_err.h"
#include "digipot.h"
#include "esp_log.h"

struct i_vga{
    float R1, maxR;
    struct digipot d;
};

extern "C" void ivga_init(struct i_vga *p, float maxR, int address, i2c_port_t *i2c);
extern "C" void ivga_setgain(struct i_vga *p, bool channo,float gain);
extern "C" float ivga_presentgain(struct i_vga *p, bool channo);

#endif