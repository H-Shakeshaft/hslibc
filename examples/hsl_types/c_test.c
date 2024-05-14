#include <stdio.h>

#include "hsl_types.h"

int main(void)
{
#if __STDC_VERSION__ >= 199901L
    printf("sizeof uint64 = %lu \n", sizeof(uint64));
    printf("sizeof int64 = %li \n", sizeof(int64));
#else
    printf("sizeof uint64 = %lu \n", sizeof(uint32));
#endif
    return 0;
}
