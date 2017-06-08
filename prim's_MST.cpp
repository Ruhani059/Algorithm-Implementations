#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<fstream>
#include<queue>
#include<vector>
#include<algorithm>
#include<string>
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

int MST_prim(int V,int s)
{
    int min=0;
    priority_queue<node>Q;
    for(int i=1;i<=V;i++){color[i]=0;d[i]=99999;p[i]=-1;} //initialization

    color[s]=1;
    d[s]=0;
    p[s]=NULL;
    Q.push( node ( s , d[s] ) );

    while(!Q.empty())
    {
        node top = Q.top();
        Q.pop();
        int u = top.u;
        min+= top.w;
        color[u]=1;
        cout<<"u = "<<u<<endl;
        for(int i=0;i<vv[u].size();i++)
        {
            weight temp1=vv[u][i];
            int v=temp1.v;
//            cout<<u<<" to "<<v<<" =\t"<<d[v]<<endl;
            if( color[v]==0 && d[v] > temp1.w)
            {
                d[v]=temp1.w;
                p[v]=u;
                Q.push( node ( v , d[v] ) );
                cout<<u<<" to "<<v<<" =\t"<<d[v]<<endl;
            }
        }
    }
    return min;
}

int main ()
{
    freopen("prim's_MST.txt","r",stdin);
    int V,E,u,v,w;
    cin>>V>>E;

    for(int i=0;i<E;i++)
    {
        cin>>u>>v>>w;
        weight temp1(u,v,w);
        weight temp2(v,u,w);
        vv[u].push_back(temp1);
        vv[v].push_back(temp2);
    }
    for(int j=1;j<=V;j++)
    {
        for(int i=0;i<vv[j].size();i++)
        {
            weight temp = vv[j][i];
        }
    }
    int sum=0;
    cout<<MST_prim(V,4)<<endl;
    for(int i=1;i<=V;i++)
    {
        sum+=d[i];
    }
    cout<<endl<<sum<<endl;
    return 0;
}
