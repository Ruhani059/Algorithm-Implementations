#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main ()
{
    int a,b;
    while(scanf("%d %d",&a,&b)==2)
    {
        if (a==0 && b==0)
        {
            break;
        }
        else
        {
            a = ceil(sqrt(a));
            b = floor(sqrt(b));
            cout<<b-a+1<<endl;
        }
    }
    return 0;
}

