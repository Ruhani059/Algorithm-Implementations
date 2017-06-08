#include<iostream>
using namespace std;
int main()
{
    int matrix[100][100];
    int V,E;
    for(int i=0;i<100;i++)
    {
        for(int j=0;j<100;j++)
        {
            matrix[i][j]=0;
        }
    }
    cin>>V>>E;
    for(int i=1;i<=E;i++)
    {
        int v1,v2;
        cin>>v1>>v2;
        matrix[v1][v2]=1;
        matrix[v2][v1]=1;
    }
    for(int i=1;i<=V;i++)
    {
        for(int j=1;j<=V;j++)
        {
            cout<<matrix[i][j]<<' ';
        }
        cout<<endl;
    }
    cout<<endl;
//task 2
    int v1,v2;
    cin>>v1>>v2;
    while(v1!=0 && v2!=0)
    {
        if(matrix[v1][v2]==1) cout<<"YES\n";
        else cout<<"NO\n";
        cin>>v1>>v2;
    }

//task 3

    int v3;
    while(1)
    {
        cin>>v3;
        if(v3==0) break;
        int count=0;
        for(int i=1;i<=V;i++)
        {
            if(matrix[v3][i]==1)
            {
                cout<<i<<' ';
                count++;
            }
        }
        cout<<": "<<count<<endl;
    }
//task 4
    int v4,v5;
    cin>>v4>>v5;
    int count =0;
    while(v4!=0 && v5!=0)
    {
        int check=0;
        for(int i=1;i<=V;i++)
        {
            if(matrix[v4][i]==1)
            {
                if(matrix[i][v5]==1)
                {
                    count++;
                    check =1;
                }
            }
        }
        if(check==1) cout<<"YES\n";
        else cout<<"NO\n";
        cin>>v4>>v5;
    }
//task 5
    count=0;
    for(int k=1;k<=V;k++)
    {
        for(int i=k+1;i<=V;i++)
        {
            for(int j=1;j<=V;j++)
            {
                if(matrix[k][j]==1 && matrix[i][j]==1)
                {
                        count++;
                        break;
                }
            }
        }
    }
    cout<<endl;
    if(count==V*(V-1)/2) cout<<"YES\n";
    else cout<<"NO\n";





    return 0;


}
