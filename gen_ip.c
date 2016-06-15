#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>

int main()
{
uint32_t ul_dst;
init_rand(time(NULL));
uint32_t random_num = rand_cmwc();

ul_dst = (random_num >> 24 & 0xFF) << 24 | 
         (random_num >> 16 & 0xFF) << 16 | 
         (random_num >> 8 & 0xFF) << 8 | 
         (random_num & 0xFF);

printf("%u\n",ul_dst);
return 0;
}
