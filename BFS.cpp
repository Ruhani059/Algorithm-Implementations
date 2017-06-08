#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

#define MAX 501

vector<int>edges[MAX];
vector<int>weights[MAX];

int bfs (int V, int source)
{
    queue<int>Q;
    int color[MAX];
    int distance[MAX];
    int parent[MAX];
    for(int i=0;i<MAX;i++)
    {
        color[i]=0;
        distance[i]=999999;
        parent[i]=-1;
    }
    color[source]=1;
    distance[source]=0;
    parent[source]=NULL;
    Q.push(source);
    while(!Q.empty())
    {
        int u = Q.front();
        for(int i=0;i<edges[u].size();i++)
        {
            int v = edges[u][i];
            if(color[v]==0)
            {
                color[v]=1;
                distance[v]=distance[u]+1;
                parent[v]=u;
                partition[v] = 3 - partition[u];
//                cout<<u<<" "<<v<<endl;
//                cout<<partition[u]<<"\t"<<partition[v]<<endl;
                Q.push(v);
            }
        }
        color[u]=2;
        Q.pop();
    }
    return 1;
    /*
    for(int i=0;i<V;i++)
    {
        cout<<"i = "<<i<<' '<<color[i]<<' '<<distance[i]<<' '<<parent[i]<<endl;
    }
    */
}

int main()
{
    int testCase,caseno=1;
    scanf("%d",&testCase);
    while(testCase--)
    {
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
    }
    return 0;
}
