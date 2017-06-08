#include<stdio.h>

int main()
{
    int n,i,j,k,a[10][10];
    scanf("%d",&n);
    i=0;
    j=n/2;
    for(k=1;k<=n*n;k++)
    {
        a[i][j]=k;
        j++;
        i--;
        if(k%n==0)
        {
            i=i+2;
            j--;
        }
        else if (j == n) j =0;
        else if (i < 0) i=n-1;
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
