#include "swap.h"

void swap(char *src, char *dest, int number)
{
    int count = number;
    int iconst = count;
    char tmp;
    while (count-- >= iconst/2 + 1)
    {
        tmp = dest[count];
        dest[count] = src[iconst - count - 1];
        src[iconst - count - 1] = tmp;
    }
}
