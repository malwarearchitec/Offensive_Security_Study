#include<stdio.h>

int main(void)
{
	
	unsigned char data = 0xA5;
	unsigned char nibble = data & 0xF0 >> 4;

	printf("nibble = 0X%X\n", nibble);
	
	/* The objective is to extract A from the data, but the execution logic is wrong, because
	 * it is not specified which operation should be performed first, so the displacement is
	 * executed first and then the mask.
	*/
	

	printf("\nWith the correct logic, first move and then apply the mask :\n");

	/* You have to specify that the operation taht must be done first is the shift to the right, not
	 * the mask
	 */

	unsigned char nibble2 = (data & 0xF0) >> 4;
	printf("nibble = 0X%X\n", nibble2);
	

return 0;
}
