#include<bits/stdc++.h>
#include<iostream>
using namespace std;
#define MAX 1000
int pi[MAX];

void copute_prifix_function(string P)
{
    int m = P.length();
    pi[0]=0;
    int k = -1;
    for(int q=1;q<m;q++)
    {
        while(k>0 && P.at(k+1)!=P.at(q))
        {
            cout<<P.at(k+1)<<"\t"<<P.at(q)<<endl;
            k=pi[k];
        }
        if(P.at(k+1)==P.at(q))
        {
            cout<<P.at(k+1)<<"\t"<<P.at(q)<<endl;
            k=k+1;
        }
        pi[q]=k;
    }
}

void kmp_matcher(string T,string P)
{
    int n = T.length();
    int m = P.length();
    copute_prifix_function(P);
    cout<<"hello"<<endl;
    for(int i=1;i<=m;i++)
        cout<<pi[i]<<"\t";
    cout<<endl;
    int q =0;
    for(int i=0;i<n;i++)
    {
        while(q>0 && P.at(q+1)!=T.at(i))
            q=pi[q];
        if(P.at(q+1)==T.at(i))
            q=q+1;
        if(q==m)
        {
            cout<<"Pattern Occurs in "<<i-m<<" to "<<i<<endl;
            q=pi[q];
        }
    }
}

void copute_prifix_function(int m,char P[])
{
    pi[1]=0;
    int k = 0;
    for(int q=2;q<=m;q++)
    {
        while(k>0 && P[k+1]!=P[q])
            k=pi[k];
        if(P[k+1]==P[q])
            k=k+1;
        pi[q]=k;
    }
}

void kmp_matcher(int n,int m, char T[],char P[])
{
    copute_prifix_function(m,P);
    int q = 0;
    for(int i=1;i<=n;i++)
    {
        while(q>0 && P[q+1]!=T[i])
            q=pi[q];
        if(P[q+1]==T[i])
            q=q+1;
        if(q==m)
        {
            cout<<"Pattern Occurs in "<<i-m<<" to "<<i<<endl;
            q=pi[q];
        }
    }

}

int main()
{
    freopen("input.txt","r",stdin);
    string  P,T;
    while(cin>>T>>P)
    {
        int i=0;
        int n = T.length();
        int m = P.length();
        char A[n+1], B[m+1];
        for(i=0;i<n;i++)
            A[i+1]=T[i];
        A[i+1]='\0';
        for(i=0;i<m;i++)
            B[i+1]=P[i];
        B[i+1]='\0';

        cout<<T<<endl<<P<<endl;
        kmp_matcher(n,m,A,B);
        for(int i=1;i<=m;i++)
            cout<<pi[i]<<"   ";
        cout<<endl;
    }
    return 0;
}
