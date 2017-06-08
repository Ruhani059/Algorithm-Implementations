#include<iostream>
#include<cstdio>
#include<algorithm>
#define size 17
using namespace std;

class heapsort
{
    int heap[size];
    int N;
public:
    heapsort( int arr[] )
    {
        for(int i=1;i<size;i++)
            heap[i] = arr[i];
        N = size-1;
        sort();
    }
    void sink ( int k , int N)
    {
        while(2*k <= N)
        {
            int j = 2 * k;
            if ( j <= N && heap[j] < heap[j+1] ) j++;
            if ( heap[k] >= heap[j] ) break;
            swap ( heap[k] , heap[j] );
            k = j;
        }
    }
    void sort ()
    {
        for ( int k = N/2; k>=1; k--)
            sink ( k , N );
        show();
        while( N > 2)
        {
            swap ( heap[1] , heap[N] );
            sink ( 1 , --N );
        }
    }
    void show ()
    {
        for(int i=1;i<size;i++)
            cout<<heap[i]<<" ";
        cout<<endl;
    }
};

int main ()
{
    int array[size],i,j,k;
    for(i = 1;i<size;i++)
        array[i] = rand()%97;
    for(i = 1;i<size;i++)
        cout<<array[i]<<" ";
    cout<<endl;
    heapsort h(array);
    h.show();
    return 0;
}
