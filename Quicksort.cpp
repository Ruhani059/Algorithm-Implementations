#include<iostream>
#include<cstdio>
#include<algorithm>
#define size 27
using namespace std;

class quicksort
{
    int a[size];
public:
    quicksort( int arr[])
    {
        for(int i=0;i<size;i++)
            a[i] = arr[i];
        sort( a , 0 , size-1);
    }
    int partition ( int a[], int lo, int hi )
    {
        int i = lo, j = hi+1;
        while(1)
        {
            while ( a[++i] < a[lo] )
                if (i == hi) break;
            while ( a[--j] > a[lo])
                if (j == lo) break;
            if (i>=j) break;
            swap(a[i],a[j]);
        }
        swap(a[lo],a[j]);
        return j;
    }
    void sort( int a[], int lo, int hi )
    {
        //cout<<"begin: \tsort ( "<<lo<<" , "<<hi<<" )"<<endl;
        if (hi <= lo)   return;
        int j = partition(a,lo,hi);
        sort ( a , lo , j-1);
        sort ( a , j+1 , hi);
        //cout<<"end: \tsort ( "<<lo<<" , "<<hi<<" )"<<endl;
    }
    void show ()
    {
        for(int i=0;i<size;i++)
            cout<<a[i]<<" ";
        cout<<endl;
    }
};

int main ()
{
    int array[size],i,j,k;
    for(i=0;i<size;i++)
        array[i]=rand()%97;
/*
    for(i=0;i<size;i++)
        cout<<array[i]<<" ";
    cout<<endl;
*/
    quicksort m(array);
    m.show();
    return 0;
}
