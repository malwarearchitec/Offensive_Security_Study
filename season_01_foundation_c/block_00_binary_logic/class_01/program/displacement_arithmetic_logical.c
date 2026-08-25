#include<stdio.h>

int main(void)
{

	unsigned char data_unsigned = 0x80; 
	signed char data_signed = -128;

	// Logical shift to the right (SHR)
	
	printf("unsigned: %u >> 1 = %u\n", data_unsigned, data_unsigned >> 1);

	// Arithmetic shift to the right (SAR)
	
	printf("unsigned: %d >> 1 = %d\n", data_signed, data_signed >> 1);

return 0;
}
