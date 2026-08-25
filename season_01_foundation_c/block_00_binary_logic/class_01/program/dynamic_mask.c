#include<stdio.h>


int main(void)
{

unsigned char key  = 0x4B;
unsigned int n = 3;



// Mask to check if the bit is on

unsigned char mask = (1 << n) & key;

unsigned char bit_on = (key & mask) != 0;
printf("Status: %d %s\n", n, bit_on ? "ON" : "OFF");


return 0; 
}
