#include<stdio.h>
#define size 1045
int main ()
{
    int N;
    while(scanf("%d",&N)==1)
    {
        if(N==0) printf("The Fibonacci number for 0 is 0\n");
        else if(N==1) printf("The Fibonacci number for 1 is 1\n");
        else
        {
            int num1[size], num2[size], ans[size], i, j, k, temp;
            for(i=0;i<size;i++)
            {
                num1[i] = 0;
                num2[i] = 0;
            }
            num2[size-1]=1;
            for(k=2;k<=N;k++)
            {
                int c = 0 , d;
                for(i=size-1;i>=0;i--)
                {
                    d = num1[i]+num2[i]+c;
                    c = 0;
                    if( d > 9)
                    {
                        d = d - 10 ;
                        c = 1 ;
                    }
                    ans[i]=d;
                }
                for(i=0;i<size;i++)
                {
                    temp=num2[i];
                    num2[i]=ans[i];
                    num1[i]=temp;
                }
            }
            for(i=0;;i++)
                if(ans[i]!=0)
                    break;
            printf("The Fibonacci number for %d is ",N);
            for(;i<size;i++)
                printf("%d",ans[i]);
            printf("\n");
        }
    }
    return 0;
}
