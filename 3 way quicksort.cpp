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
        for(int i=0;i<size;i++) a[i] = arr[i];
        sort( a , 0 , size-1);
    }
    void sort( int a[], int lo, int hi )
    {
        if (hi <= lo)   return;
        int lt = lo , gt = hi , v = a[lo] , i = lo;
        while(i<=gt)
        {
            if      (v > a[i])      swap ( a[i++] , a[lt++] );
            else if ( v < a[i] )    swap ( a[i] , a[gt--] );
            else                    i++;
        }
        sort ( a , lo , lt-1 );
        sort ( a , gt+1 , hi );
    }
    void show ()
    {
        for(int i=0;i<size;i++) cout<<a[i]<<" ";
        cout<<endl;
    }
};

int main ()
{
    int array[size],i;
    for(i=0;i<size;i++) array[i]=rand()%97;
/*
    for(i=0;i<size;i++) cout<<array[i]<<" ";
    cout<<endl;
*/
    quicksort m(array);
    m.show();
    return 0;
}

