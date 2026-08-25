#include<stdio.h>


int main(void)
{

unsigned char x = 0x4B;

printf("The data x = %d, (0x%x)\n", x,x);

printf("Move x one position to the left ( x << 1) = %d\n", x << 1);
printf("Move x one position to the right ( x >> 1) = %d\n", x >> 1);
printf("Move x two position to the right ( x >> 2) = %d\n", x >> 2);



// Building Masks with displacement

unsigned char mask_1 =  x & (1 << 0);
printf("\nApplying mask 0x01, mask made only with left shift: 0x%x\n", mask_1);

unsigned char mask_3 = x & (1 << 3);
printf("Applying mask 0x03, mask made only with left shift: 0x%x\n", mask_3);

unsigned char mask_7 = x & (1 << 7);
printf("Applying mask 0x07, mask made only with left shift: 0x%x\n", mask_7);

return 0; 
}
