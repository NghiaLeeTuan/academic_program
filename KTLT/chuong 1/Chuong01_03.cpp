#include <stdio.h>
#include <conio.h>
 
typedef struct
{
    int h;
    int m;
    int s;
}TIME, *PTIME;
 
 void xuat(TIME time)
{
    printf("hh:mm:ss = %.2d:%.2d:%.2d\n", time.h, time.m, time.s);
}
 

void nhap(PTIME time)
{
    int h,m,s;
    printf("\n nhap thoi gian:");
    // Hour
    do
    {
        printf("\nGio: ");
        scanf("%d", &h);
    } while (h < 0 || h > 23);
    // Minute
    do
    {
        printf("\nPhut: ");
        scanf("%d", &m);
    } while (m < 0 || m > 59);
    // Sencond
    do
    {
        printf("\nGiay: ");
        scanf("%d", &s);
    } while (s < 0 || s > 59);
 
    //save this time to struct
    time->h = h;
    time->m = m;
    time->s = s; 
}
 
TIME tinh(TIME time1, TIME time2)
{
    int s1 = 0, s2 = 0;
    int s;
    TIME time;
    s1 = 60*60*time1.h + 60*time1.m + time1.s;
    s2 = 60*60*time2.h + 60*time2.m + time2.s;
    s = s1 - s2;
    if(s < 0)
    {
        s = (-1)*s;
    }
    time.m = s/60;
    time.s = s%60;
    time.h = time.m/60;
    time.m = time.m%60;
 
    return time;
}

int main()
{
    TIME time1,time2,time;
    //time1
    nhap(&time1);
    printf("\n(Time 1) ");
    xuat(time1);
    //time2
    nhap(&time2);
    printf("\n(Time 2) ");
    xuat(time2);
    // time = |tim1 - time2|;
    printf("\n(Time 2 - Time 1) ");
    time = tinh(time1, time2);
    xuat(time);
    getch();
    return 0;
}
 


