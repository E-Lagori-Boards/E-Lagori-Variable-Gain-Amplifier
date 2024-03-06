// Untested
#include <d_esp_wrv.h>
#include <d_adc.h>
// #include <digipot.h>
#include <i_vga.h>


#define MEMLEN 1024

struct d_esp_wvr proc;
struct boardconf b;
struct i_vga vga;



void setup() {
  Serial.begin(115200);
  Serial.println("Initial Board");
  // extern "C"
  dewvr_init(&proc, 0x81, 6);

  // put your setup code here, to run once:
}

void loop() {
  Serial.print("Board Information :");

  dewvr_whoami(&proc, &b);

  Serial.print(b.reserved);
  Serial.print(" ");
  Serial.print(b.brdtype);
  Serial.print(" ");
  Serial.print(b.brdno);
  Serial.print(" \n");

  dewvr_i2cBegin(&proc, 100000);





  Serial.println("---------------------------------");

  delay(2000);
}
