#include <stdio.h>
int main(void)
{
    char a[3];
    a[0] = getchar();
    a[1] = getchar();
    a[2] = getchar();
    printf("%c\n%c\n%c", a[0], a[1], a[2]);
    return 0;
}