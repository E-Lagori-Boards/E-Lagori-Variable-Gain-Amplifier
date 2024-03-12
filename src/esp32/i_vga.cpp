#include "i_vga.h"

void ivga_init(struct i_vga *p, float maxR, int address, i2c_port_t *i2c){
    p->R1 = 1000;
    p->maxR = 100000;
    digipot_init(&(p->d), address, i2c);
}

void ivga_setgain(struct i_vga *p, bool channo,float gain){
    gain = (gain > (1+(p->maxR+3340)/p->R1))?(1+(p->maxR+3340)/p->R1):gain;
    gain = (gain < 4.34)?4.34:gain; //(3340/1000+1) current limiting resistor of 3.3k

    float R = 0;
    R = p->R1*(gain-1);
    // ESP_LOGI("Setgain","%f, %d",R,(int)(R/p->maxR*256.0));
    digipot_Write_RDAC(&(p->d),channo, (int)(R/(p->maxR+3340)*256.0));
}

float ivga_presentgain(struct i_vga *p, bool channo){
    float R = digipot_Readback_RDAC(&(p->d),channo)/256.0*(p->maxR+3340);
    return((1+R/p->R1));
}