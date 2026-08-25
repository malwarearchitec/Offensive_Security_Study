#include<stdio.h>

int main(void)
{

	signed char data_signed = -128;

	// Testing what happens when you move left to a signed data and the MSB on
	

	 signed undefined_behavior = data_signed << 1;
	 printf("Displacement to the letf %d << 1 = %d\n", data_signed, undefined_behavior);

	 // The compiler forces it to be a larger datum, it goes from char to int -256
	 
	int bit;
	int big_data = 0xffff;

	for (int i = 0; i <= big_data;i ++)
	{
	   // capturar bit a bit para reconstruir el dato en binario		
		
		bit = (undefined_behavior << i) &1; 
		printf("%d", bit);
 
		/* This is an almost infinite bug, it print 0s thousands of times. scrolling to the
		 * left of a signed data and the MSB on is undefined behavior 
	         */	
	}


return 0;
}
