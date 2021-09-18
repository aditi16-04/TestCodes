#include <time.h>
#include <math.h>
int r=25,i,q,c,i,q,b[999];
void v(float a,int f,int m)
{
	b[(r/2+(int)(sin(a)*f))*r+r/2+(int)(cos(a)*f)]=m;
}
void main()
{
	float a,p=6.28,z=1.57,h,m,s;
	for(;;)
	{
		time_t u=time(0);
		struct tm*l=localtime(&u);
		s=l->tm_sec;
		m=l->tm_min+s/60.;
		h=l->tm_hour+m/60.;
		system("@cls||clear");
		q=r*r;
		c=r/2;
		memset(b,32,q*4);
		for(i=0,a=p;a>0;a-=0.52,i++)
			v(a,c,i%3?46:i%6?124:45);
			v(0,0,79);
			v(p*s/60.-z,c-4,83);
			v(p*m/60.-z,c-5,77);
			v(p*h/12.-z,c-6,72);
		for(i=0;i<q;i++)
		{
			c=b[i];
			putchar(c);
			if(i%r==r-1)
				putchar(10);
		}
		for(c=0;c<2000000;c++)
			hypot(3,.4);
	}
}