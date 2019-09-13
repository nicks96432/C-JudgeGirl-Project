#include <stdio.h>
int main(void)
{
    int s, f, t, rabbit = 0, chicken = 0, crab = 0;
    scanf("%d %d %d", &s, &f, &t);
    rabbit = f / 2 - 4 * s + 3 * t;
    chicken = 4 * s - 2 * t - f / 2;
    crab = s - t;
    if (s - t < 0 || f % 2)
    {
        printf("0");
    }
    else
    {
        printf("%d\n%d\n%d", chicken, rabbit, crab);
    }
    return 0;
}
//s=rabbit+chicken+crab
//f=4*rabbit+2*chicken+8*crab
//t=rabbit+chicken
//crab=s-t
//f=4*rabbit+2*chicken+8*s-8*t
//4*rabbit+2*chicken=f-8*s+8*t
//2*rabbit+2*chicken=2*t
//2*rabbit=f-8*s+6*t
//rabbit=f/2-4*s+3*t
//chicken=4*s-2*t-f/2