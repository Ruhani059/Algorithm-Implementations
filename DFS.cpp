#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

#define MAX 501

vector<int>edges[MAX];
vector<int>weights[MAX];

int color[MAX];
int distance[MAX];

void dfs_Visit (int u)
{
    color[u]=1;
    for(int i=0;i<edges[u].size();i++)
    {
        int v=edges[u][i];
        if(color[v]==0)
        {
            dfs_Visit(v);
        }
    }
    color[u]=2;
}

void dfs (int V, int source)
{
    for(int i=0;i<V;i++)
    {
        color[i]=0;
        distance[i]=-1;
    }
    for(int i=0;i<V;i++)
    {
        if(color[i]==0)
        {
            dfs_Visit(i);
        }
    }
}

int main()
{
    /*
    int testCase,caseno=1;
    scanf("%d",&testCase);
    while(testCase--)
    {
    */
        for(int i=0;i<MAX;i++)
        {
            edges[i].clear();
            weights[i].clear();
        }
        int V,E,u,v,w;
        scanf("%d %d",&V,&E);
        for(int i=0;i<E;i++)
        {
            scanf("%d %d %d",&u,&v,&w);
            edges[u].push_back(v);
            edges[v].push_back(u);
            weights[u].push_back(w);
            weights[v].push_back(w);
        }
        /*
        for(int i=0;i<V;i++){cout<<i<<"  : ";for(int j=0;j<edges[i].size();j++){cout<<edges[i][j]<<" ";}cout<<endl;}cout<<endl;
        */
        printf("Case %d:\n",caseno++);
//    }
    return 0;
}

