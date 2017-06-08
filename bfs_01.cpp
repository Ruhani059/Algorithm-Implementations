#include<iostream>
#include<cstdio>
#include<vector>
#define MAX 100000 //maximum node
using namespace std;
vector<int>edges[MAX];
vector<int>cost [MAX]; //parallel vector to store costs;
vector<int>G [100];
void bfs (int n,int source);
int main()
{
    int N,E,i;
    scanf ("%d%d",&N,&E);
    for (i=1;i<=E;i++)
    {
        int x,y;
        scanf ("%d%d",&x,&y);
        edges[x].push_back (y);
        edges[y].push_back (x);
        cost [x].push_back (1);
        cost [y].push_back (1);
    }
    return 0;
}
void bfs (int n,int source)
{
    vector<int>V1,V2;
    V1.push_back (source);
    int taken [100]={0};
    int taken1=1;

    printf("Level 0::%d\n",source);
    for (int loop=1;loop<n;loop++) //loop is not greater than n-1
    {
        printf("Level %d::",loop);
        for (int i=0;i<V1.size ();i++)
        {
            int u=V1[i];
            for (int j=0;j<G [u].size ();j++)
            {
                int v=G [u][j];     //u theke v te edge peyesi.
                if(!taken [v])      //same node duibar visit korbo na.
                {
                    printf("%d ",v);
                    taken [v]=1;
                    V2.push_back (v);   //V1 theke je son node e jaoa jai ta V2 te push koresi.
                }
            }
        }
        if(V2.empty ())     //new node nai.
        {
            puts ("EMPTY");
            break;
        }
        else                //V2 er node gulo v1 e copy kora
        {
            puts ("");
            V1.clear ();
            V1=V2;
            V2.clear ();
        }
    }
}
