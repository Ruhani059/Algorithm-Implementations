#include<iostream>
#include<cstdio>
#include<algorithm>
#define size 12
using namespace std;

class heapsort
{
    int heap[size];
    int N;
public:
    heapsort( )
    {
        N = 0;
    }
    void insert ( int x )
    {
        heap[++N] = x;
        swim ( N );
    }
    void swim ( int k)
    {
        while( k>1 && heap[k/2] < heap[k] )
        {
            swap ( heap[k/2] , heap[k] );
            k = k / 2;
        }
    }
    void sink ( int k )
    {
        while(2*k<=N)
        {
            int j = 2 * k;
            if ( j <= N && heap[j] < heap[j+1] ) j++;
            if ( heap[k] > heap[j] ) break;
            swap ( heap[k] , heap[j] );
            k = j;
        }
    }
    int delete_max ( )
    {
        int max = heap[1];
        swap ( heap[1] , heap[N--] );
        sink (1);
        //heap[N+1]=NULL;
        return max;
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
    int i,j,k;
    heapsort h;
    for(i = 1;i<size;i++)
        h.insert( rand() % 97 );
    h.show();
    for(i = 1;i<size;i++)
        h.delete_max();
    h.show();
    return 0;
}

