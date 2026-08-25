#include<stdio.h>

int main(void)
{


	unsigned char byte = 0xA5;

	// Mask to extract the high levels of the data
	
	unsigned char high = (byte >> 4) & 0x0F;
	printf("high nibble = 0x%X (%d)\n", high, high);


	// Mask to extract low levels of the data
	
	unsigned char low = byte & 0x0F;
	printf("bajos = 0x%X (%d)\n", low, low);

return 0;
}
