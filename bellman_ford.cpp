#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<fstream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
#define MAX 100                     // vertices are numbered from 1 to n

struct weight
{
    int u,v,w;
    weight(int a,int b,int c){u=a;v=b;w=c;}
};

vector<weight>vv[MAX];

int color[MAX];
int d[MAX];
int p[MAX];

int bellman_ford(int V,int s)
{
    for(int i=0;i<=MAX;i++){color[i]=0;d[i]=9999999;p[i]=-1;} //initialization

    d[s]=0;
    p[s]=NULL;

    for(int count=0;count<V-1;count++)
    {
        cout<<"Phase : "<<count<<endl<<endl;
        for(int j=1;j<=V;j++)
        {
            for(int i=0;i<vv[j].size();i++)
            {
                weight temp = vv[j][i];
                int u = temp.u;
                int v = temp.v;
                cout<<u<<" to "<<v<<" =\t"<<d[v]<<endl;
                if(d[v]>d[u]+temp.w)
                {
                    d[v]=d[u]+temp.w;
                    p[v]=u;
                    cout<<u<<" to "<<v<<" =\t"<<d[v]<<endl;
                }
            }
        }
    }

    cout<<"\nChecking -ve cycle\n";

    for(int j=1;j<=V;j++)
    {
        for(int i=0;i<vv[j].size();i++)
        {
            weight temp = vv[j][i];
            int u = temp.u;
            int v = temp.v;
            cout<<u<<" to "<<v<<" =\t"<<d[v]<<endl;
            if(d[v]>d[u]+temp.w)
            {
                cout<<u<<" to "<<v<<" =\t"<<d[v]<<endl<<"mara khao!\n\n";
                return 0;
            }
        }
    }

    return 1;
}

int main ()
{
    freopen("bellman_ford.txt","r",stdin);
    int V,E,u,v,w;
    cin>>V>>E;
    for(int i=0;i<E;i++)
    {
        cin>>u>>v>>w;
        weight temp(u,v,w);
        vv[u].push_back(temp);
//        weight[v].push_back(w);
    }
    for(int j=1;j<=V;j++)
    {
        for(int i=0;i<vv[j].size();i++)
        {
            weight temp = vv[j][i];
            cout<<temp.u<<"\t"<<temp.v<<"\t"<<temp.w<<endl;
        }
    }
   // for(int j=1;j<=V;j++)
    //{
        cout<<"\n"<<bellman_ford(V,2)<<endl;
    //}

    return 0;
}
