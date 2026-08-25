#include<stdio.h>

/* The goal is to take the high nibble of one piece data and the low nibble of another piece data
 * and combine them into a single 16-bit piece of data
*/ 


int main(void)
{

	unsigned char high = 0x12;
	unsigned char low = 0x34;

	printf("\nThe data of a byte is:  %x, %x\n", high, low);
	

	printf("The data parsed into a single 16-bit data\n");
	
	unsigned short parsed_data = (high << 8) | low; 
	printf("Decimal data: %d\nHexadecimal data: 0x%X\n", parsed_data, parsed_data);

return 0;
}
