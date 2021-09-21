#include <time.h>
#include <math.h>
#include <conio.h>

int rad=25, i, sq, c, arr[999];

void analogClock(float a, int f, int m)
{
    arr[(rad / 2 + (int)(sin(a)* f)) * rad + rad / 2 + (int)(cos(a) * f)] = m;
    
}

void main()
{
    float a, p=6.28, z=1.57, h, m, s;
    
    for(;;)
    {
        time_t u = time(0);
        struct tm * l = localtime(&u);
        s = l -> tm_sec;
        m = l -> tm_min + s / 60. + 30;
        h = l -> tm_hour + s / 60. + 5;
        clrscr();
        sq = rad * rad;
        c = rad / 2;
        memset(arr, 32, sq * 4);
        
        for(i = 0, a = p; a > 0; a -= 0.52, i++)
            analogClock(a, c, i % 3 ? 46 : i % 6 ? 124 : 45);
            
        analogClock(0, 0, 79);
        analogClock(p * s / 60.-z, c -4, 83);
        analogClock(p * m / 60.-z, c -5, 77);
        analogClock(p * h / 12.-z, c -6, 72);
        
        for(i = 0; i < sq; i++)
        {
            c = arr[i];
            putchar(c);
            if(i % rad == rad -1)
            putchar(10);
        }
        
        for(c=0; c<2000000; c++)
            hypot(3,.4);
            
        fflush(stdout);
    	sleep(1);
    }
getch();   
}