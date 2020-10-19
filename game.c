#include<stdio.h>
int main(){
    long long int x,i,a,b,t,h,arm;
    scanf("%d",&x);
    while(x--)
    {
        scanf("%d %d", &a, &b);
        
        if(a==0||b==0)
            puts("0");
        
        else
        {
            t=1;
            h=a+3;
            arm=b+2;
            while(1)
            {
                if(h>5&&arm>10)
                {
                    h-=2;
                    arm-=8;
                    t+=2;
                }
                else if(h>20&&arm<=10)
                {
                    h-=17;
                    arm+=7;
                    t+=2;
                }
                else 
                {
                    printf("%d\n",t);
                    break;
                }
            }
        }
    }
    return 0;
}