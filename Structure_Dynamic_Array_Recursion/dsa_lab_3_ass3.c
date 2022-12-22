#include <stdio.h>

typedef struct distance
{
    int km;
    int m;
}st;
int adddis(st dis1, st dis2);

int main()
{
    st dis1, dis2;
    
    printf("Enter first distance in km & mes:");
    scanf("%d%d", &dis1.km, &dis1.m);

    printf("Enter second distance in km & mes:");
    scanf("%d%d", &dis2.km, &dis2.m);
    
    adddis(dis1, dis2);
    
    return 0;
}


int adddis(st dis1, st dis2)
{
    st dis3;
    dis3.km = dis1.km + dis2.km;
    dis3.m = dis1.m + dis2.m;

    dis3.km = dis3.km + dis3.m / 1000;
    dis3.m = dis3.m % 1000;

    printf("\nTotal distance in km: %d, meter: %d", dis3.km, dis3.m);
    return 0;
}