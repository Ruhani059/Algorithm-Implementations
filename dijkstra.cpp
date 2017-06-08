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

struct weight
{
    int u,v,w;
    weight(int a,int b,int c){u=a;v=b;w=c;}
};
vector<weight>vv[MAX];

int color[MAX];
int d[MAX];
int p[MAX];

struct node
{
    int u,w;
    node(int a,int b){u=a;w=b;}
    bool operator < ( const node &p ) const{return w > p.w;}
};

int dijkstra(int V,int s,int f)
{
    priority_queue<node>Q;
    for(int i=0;i<=MAX;i++){color[i]=0;d[i]=9999999;p[i]=-1;} //initialization

    color[s]=1;
    d[s]=0;
    p[s]=NULL;
    Q.push(node(s,d[s]));

    while(!Q.empty())
    {
        node top = Q.top();
        Q.pop();
        int u = top.u;
        color[u]=1;
        cout<<"u = "<<u<<endl;
        if(u==f) return d[u];
        for(int i=0;i<vv[u].size();i++)
        {
            weight temp=vv[u][i];
            int v=temp.v;
            cout<<u<<" to "<<v<<" =\t"<<d[v]<<endl;
            if(d[v]>d[u]+temp.w)
            {
                d[v]=d[u]+temp.w;
                p[v]=u;
                Q.push(node(v,d[v]));
                cout<<u<<" to "<<v<<" =\t"<<d[v]<<endl;
            }
        }
    }
    return -1;
}

int main ()
{
    freopen("dijkstra.txt","r",stdin);
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
    for(int j=1;j<=V;j++)
    {
        cout<<dijkstra(V,1,j)<<endl;
    }

    return 0;
}
