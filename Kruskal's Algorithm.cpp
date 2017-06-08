#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<fstream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
#define MAX 100

int parent[MAX];

struct edge {
    int u,v,w;
    bool operator < (const edge &p) const
    {
        return w<p.w;
    }
};

int find (int r)
{
    if(parent[r]==r) return r;
    else
    {
        return find(parent[r]);
    }
}

vector<edge>e;

int mst (int V)
{
    //initialization
    sort(e.begin(),e.end());
    cout<<"Edges : \n";
    for(int i=0;i<e.size();i++)
    {
        cout<<e[i].u<<"\t"<<e[i].v<<"\t"<<e[i].w<<endl;
    }
    for(int i=1;i<=V;i++)
    {
        parent[i]=i;
    }

    //main frame

    int count=0,sum=0;
    for(int i=0;(int)i<e.size();i++)
    {
        int u = find(e[i].u);
        int v = find(e[i].v);
        if(u!=v)
        {
            parent[u]=v;
            count++;
            sum+=e[i].w;
            if(count==V-1)
                break;
        }
    }
    return sum;
}

int main()
{
    freopen("Kruskal's Algorithm.txt","r",stdin);
    int V,E;
    cin>>V>>E;
    for(int i=0;i<E;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        struct edge new_edge;
        new_edge.u = u;
        new_edge.v = v;
        new_edge.w = w;
        e.push_back(new_edge);
    }
    cout<<"mst length = "<<mst(V)<<endl;
    return 0;
}
