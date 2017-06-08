#include<iostream>
using namespace std;
int taken[10] = {0};

bool consistancy (int A[],int r);

void permutation(int A[],int n,int c,int r)
{
//    cout<<A[r+1]<<endl;
    if(r==c+1)
    {
        for(int i=1;i<=c;i++)   cout<<A[i];
        cout<<endl;
        return;
    }

    for(int i=1;i<=n;i++)
    {
        if(taken[i]==0 && A[r-1]<i)
        {
            A[r]=i;
            taken[i]=1;
            permutation(A,n,c,r+1);
            taken[i]=0;
        }
    }

}

int main()
{
    int n=5,A[10];
    permutation(A,n,3,1);

    return 0;
}
