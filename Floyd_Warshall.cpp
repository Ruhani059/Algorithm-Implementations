#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<fstream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
#define MAX 100                                             //vertices starts with 1;

int graph[MAX][MAX];
int D[MAX][MAX];
int P[MAX][MAX];

void printD(int V);
void printP(int V);

void Floyd_Warshall(int V)
{
    for(int i=1;i<=V;i++)                   //initialization
    {
        for(int j=1;j<=V;j++)
        {
            D[i][j] = graph[i][j];
            P[i][j] = i;
            if(graph[i][j]==0 && i!=j)
            {
                D[i][j]=99999;
            }
            if(graph[i][j]==0 || i==j)
            {
                P[i][j] = NULL;
            }
        }
    }
//    cout<<"D(0)"<<endl;
//    printD(V);
//    cout<<"P(0)"<<endl;
//    printP(V);

    for(int k=1;k<=V;k++)
    {
        for(int i=1;i<=V;i++)
        {
            for(int j=1;j<=V;j++)
            {
                if(D[i][j] > D[i][k]+D[k][j]  && ( D[i][k]!=99999 && D[k][j] !=99999) )
                {
                    D[i][j] = D[i][k]+D[k][j];
                    P[i][j] = P[k][j];
                }
            }
        }
//        cout<<"D("<<k<<")"<<endl;
//        printD(V);
//        cout<<"P("<<k<<")"<<endl;
//        printP(V);
    }

}

void printD (int V)
{
    for(int i=1;i<=V;i++)
    {
        for(int j=1;j<=V;j++)
        {
            cout<<D[i][j]<<"\t";
        }
        cout<<endl;
    }
    cout<<endl<<endl;
}

void printP (int V)
{
    for(int i=1;i<=V;i++)
    {
        for(int j=1;j<=V;j++)
        {
            cout<<P[i][j]<<"\t";
        }
        cout<<endl;
    }
    cout<<endl<<endl;
}

void print_path (int V,int s,int t)
{
   // cout<<"path("<<s<<","<<t<<")"<<endl;
    if(P[s][t]==0)
    {
        cout<<"Sorry! No Path Exists.\n\n";
        return;
    }
    if(P[s][t] == s)
        cout<<s<<"  ->  ";
    else
    {
        print_path(V,s,P[s][t]);
        print_path(V,P[s][t],t);
    }
}

int main ()
{
    freopen("Floyd_Warshall.txt","r",stdin);
    int V,E,u,v,w;
    cin>>V>>E;
    for(int i=0;i<E;i++)
    {
        cin>>u>>v>>w;
        graph[u][v]=w;
//    graph[v][u]=w;
    }
    for(int j=1;j<=V;j++)
    {
        for(int i=1;i<=V;i++)
        {
            cout<<graph[j][i]<<"\t";
//            cout<<temp.u<<"\t"<<temp.v<<"\t"<<temp.w<<endl;
        }
        cout<<"\n";
    }
    cout<<endl;

    Floyd_Warshall(V);

//    print_path(V,1,5);
//    cout<<"5";
    return 0;
}
