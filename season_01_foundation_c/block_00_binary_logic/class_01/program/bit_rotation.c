#include<stdio.h>


/* Bit rotation, the bits that come out enter from the right.
 * (x >> 3) | x << (8 - 3)
 *
 * (0100 1011 >> 3) | 0100 1011 << (5)
 *
 * 0000 1001 | 
 * 0110 0000
 * ---------
 * 0110 1001 = (9) 0x69
 */
 

unsigned char ror8(unsigned char x, char n)
{
	return (unsigned char)((x >> n) | (x << (8 - n)));
}

int main (void)
{
	unsigned char x = 0x4B; 
	printf("ror(0x4B, 3) = 0x%X\n", ror8(x, 3));

return 0;
}

