#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
long long int gcd ( long long int a, long long int b)
{
    if ( b == 0) return a;
    else  return gcd ( b , a%b );
}
long long int lcm ( long long int a, long long int b)
{
    return (a * b)/gcd (a,b);
}
int main ()
{
    int T;
    cin>>T;
    while(T--)
    {
        long long int i,j,k,a,b,c,sqrtN,min = 1000000000000000;
        cin>>a>>c;
        sqrtN = sqrt(c);
        for(i=1;i<=sqrtN;i++)
        {
            if (c % i == 0 )
            {
                if ( lcm (a,i)==c && i < min)
                {
                    min = i;
                }
                else if ( lcm (a,c/i)==c && i < min)
                {
                    min = c/i;
                }
            }
        }
        if (min == 1000000000000000)
            cout<<"NO SOLUTION"<<endl;
        else
            cout<<min<<endl;

    }
    return 0;
}


