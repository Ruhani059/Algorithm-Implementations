#include<iostream>
#include<cstdio>
#include<vector>
#include<fstream>
#include<queue>
using namespace std;
#define MAX 100 //maximum node

vector<int>edges[MAX];

int dfsColor[MAX];
int dfsTime;
int dfsStartTime[MAX];
int dfsFinishTime[MAX];
int dfsParent[MAX];
void bfs(int V,int source)
{
    queue<int>Q;
    int taken[MAX]={0};
    int distance[MAX];
    int parent[MAX];
    taken[source]=1;
    distance[source]=0;
    parent[source]=NULL;
    Q.push(source);
    cout<<source<<" ";
    while(!Q.empty())
    {
        int u=Q.front();
        for(int i=0;i<edges[u].size();i++)
        {
            int v=edges[u][i];
            if(!taken[v])
            {
                distance[v]=distance[u]+1; //From source distance of v = distance of u + 1
                taken[v]=1;
                parent[v]=u;
                cout<<v<<" ";
                Q.push(v);
            }
        }
        Q.pop();
    }
    //bfs completed. do ypur own job.
    for(int i=1;i<=V;i++)
    {
        cout<<source<<" to "<<i<<" distance "<<distance[i]<<endl;
    }
    for(int i=1;i<=V;i++)
    {
        cout<<"parent of "<<i<<" :"<<parent[i]<<endl;
    }
    cout<<endl;
}

void dfsVisit(int u)
{
    cout<<u<<" ";
    dfsColor[u] = 1;
    dfsTime++;
    dfsStartTime[u]=dfsTime;
    for(int i=0;i<edges[u].size();i++)
    {
        int v = edges[u][i];
        if(dfsColor[v]==0)
        {
            dfsParent[v]=u;
            dfsVisit(v);
        }
    }
    dfsColor[u]=2;
    dfsTime++;
    dfsFinishTime[u]=dfsTime;
}

void dfs(int V)
{
    for(int i=1;i<=V;i++)
    {
        dfsColor[i]=0;
        dfsFinishTime[i]=0;
        dfsStartTime[i]=0;
        dfsParent[i]=0;
    }
    dfsTime = 0;
    for(int i=V;i>=0;i--)
    {
        int u=i;
        if(dfsColor[u]==0)
        {
            dfsVisit(u);
        }
    }
}

int main()
{
    int input = 0;
    cin>>input;
    if(input)
    {
        ofstream fout ("GraphInput.txt");
        if(!fout)
        {
            cout<<"Can't open GraphInput.txt.\n";
            return -1;
        }
        int vertice,edge;
        cin>>vertice>>edge;
        fout<<vertice<<endl<<edge<<endl;
        for(int i=0;i<edge;i++)
        {
            int x,y;
            cin>>x>>y;
            fout<<x<<" "<<y<<endl;
        }
        fout.close();
    }
    ifstream fin ("GraphInput.txt");
    if(!fin)
    {
        cout<<"cannot open GraphInput.txt\n";
        return -1;
    }
    int V,E;
    fin>>V;
    cout<<"Number of Vertices : "<<V<<endl<<endl;
    fin>>E;
    cout<<"Number of Edges : "<<E<<endl<<endl;
    for(int i=0;i<E;i++)
    {
        int x,y;
        fin>>x>>y;
        edges[x].push_back(y);
    }
    fin.close();
    for(int i=1;i<=V;i++)
    {
        cout<<"Vertice "<<i<<" : \t";
        for(int j=0;j<edges[i].size();j++)
        {
            cout<<edges[i][j]<<"\t";
        }
        cout<<endl;
    }
    bfs(V,8);
    dfs(V);
    for(int i=1;i<=V;i++)
    {
        cout<<"parent of "<<i<<" :"<<dfsParent[i]<<endl;
    }
    return 0;
}
