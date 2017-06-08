#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<fstream>
#include<queue>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;
#define MAX 100                     // vertices are numbered from 1 to n

struct weight
{
    int u,v,w;
    weight(int a,int b,int c){u=a;v=b;w=c;}
};

vector<weight>vv[MAX];
stack<int>topology;

int color[MAX];
int d[MAX];
int p[MAX];

void dfs_Visit (int u)
{
    color[u]=1;
    for(int i=0;i<vv[u].size();i++)
    {
        weight temp=vv[u][i];
        int v = temp.v;
        if(color[v]==0)
        {
            dfs_Visit(v);
        }
    }
    cout<<u<<" ";
    topology.push(u);
    color[u]=2;
}

void dfs (int V)
{
    for(int i=1;i<=V;i++)
    {
        color[i]=0;
        d[i]=-1;
    }
    for(int i=1;i<=V;i++)
    {
        if(color[i]==0)
        {
            dfs_Visit(i);
        }
    }
}

void DAG_shortest_path(int V,int s)
{
    for(int i=0;i<=V;i++){color[i]=0;d[i]=999999;p[i]=-1;}  //initialization

    d[s]=0;
    p[s]=NULL;

    while(!topology.empty())
    {
        int u = topology.top();
        color[u]=1;
        cout<<"u = "<<u<<endl;
        for(int i=0;i<vv[u].size();i++)
        {
            weight temp=vv[u][i];
            int v=temp.v;
            cout<<u<<" to "<<v<<" =\t"<<d[v]<<endl;

            if(d[v]>d[u]+temp.w)
            {
                d[v]=d[u]+temp.w;
                p[v]=u;
                cout<<u<<" to "<<v<<" =\t"<<d[v]<<endl;
            }
        }
        topology.pop();
    }
}

int main ()
{
    freopen("DAG_shortest_path.txt","r",stdin);
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

    dfs(V);
    cout<<endl;
    DAG_shortest_path(V,2);
    return 0;
}
