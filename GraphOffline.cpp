#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<fstream>
#include<queue>
#define SIZE 100
using namespace std;

int nodeNumber=0;       //number of Node.
int time = 0;           //represents time of dfs visit.
struct node;

struct adjacencyList
{
    node *nodeName;
    adjacencyList *nextName;
};

struct node
{
    char element;
    adjacencyList *list;
    node *nextElement;
};

class Graph
{
public:
    node *nodeList;
    Graph();
    node *search(char v);
    void insertNode(char v);
    void createAdjacencyList(char nodeName, char nodeConnected);
    void show();
};

Graph::Graph()
{
    nodeList = NULL;
}

node* Graph::search(char v)
{
    node *temp = nodeList;

    while(temp!=NULL)
    {
        if(temp->element == v)
        {
            return temp;
        }
        temp = temp->nextElement;
    }
    return NULL;
}

void Graph::insertNode(char v)
{
    if(!search(v))
    {
        node *temp = nodeList;

        node *newNode = new node;
        newNode->element = v;
        newNode->list = new adjacencyList;
        newNode->list = NULL;
        newNode->nextElement = NULL;

        if(nodeList==NULL)
        {
            nodeList = newNode;
        }

        else
        {
            while(temp->nextElement != NULL)
            {
                temp = temp->nextElement;
            }
            temp->nextElement = newNode;
        }
    }
}

void Graph::createAdjacencyList(char searchedElement, char connectedElement)
{
    node *temp = nodeList;
    node *searchedNode = search(searchedElement);
    node *connectedNode = search(connectedElement);

    adjacencyList *tempList = searchedNode->list;

    adjacencyList *newList = new adjacencyList;
    newList->nodeName = connectedNode;
    newList->nextName = NULL;

    if(searchedNode->list == NULL)
    {
        searchedNode->list = newList;
    }
    else
    {
        while(tempList->nextName != NULL)
        {
            tempList = tempList->nextName;
        }
        tempList->nextName = newList;
    }
}

void Graph::show()
{
    node *temp = nodeList;
    while(temp!=NULL)
    {
        adjacencyList *tempList = temp->list;
        cout<<temp->element<<" : \t";
        while(tempList!=NULL)
        {
            cout<<tempList->nodeName->element<<"\t";
            tempList = tempList->nextName;
        }
        cout<<endl<<endl;
        temp = temp->nextElement;
    }
}

class BFS : public Graph
{
    int size;
public:
    char nodesArray[SIZE];
    int isTaken[SIZE];
    int distance[SIZE];
    char parent[SIZE];
    queue<char>Q;
    void initiatization (Graph &G);
    void bfs(Graph &G,char v);
    void bfsVisit(char v);
    int search(char v);
};

void BFS::initiatization(Graph &G)
{
    int count = 0;
    node *temp = G.nodeList;
    while(temp!=NULL)
    {
        isTaken[count] = 0;
        distance[count] = 0;
        parent[count] = NULL;
        nodesArray[count++] = temp->element;
        temp = temp->nextElement;
    }
    size = count;
/*
    for(int i=0;i<size;i++)
    {
        cout<<nodesArray[i]<<"\t";
    }
    cout<<endl;
*/
}

void BFS::bfs(Graph &G, char source)
{
    initiatization(G);
    int i = search(source);
    isTaken[i] =  true;
    distance[i] = 0;
    parent[i] = NULL;
    Q.push(source);
    cout<<endl<<source<<"\t";
    while(!Q.empty())
    {
        char u = Q.front();
        int uIndex = search(u);
        //out<<"uIndex = "<<uIndex<<endl;
        node *temp = G.search(u);
        for(    adjacencyList *tempList = temp->list ;  tempList!=NULL  ;   tempList = tempList->nextName)
        {
            char v = tempList->nodeName->element;
            int vIndex = search(v);
            //cout<<"vIndex = "<<vIndex<<endl;
            if(!isTaken[vIndex])
            {
                distance[vIndex]=distance[uIndex]+1; //From source distance of v = distance of u + 1
                isTaken[vIndex]=1;
                parent[vIndex]=u;
                cout<<v<<"\t";
                Q.push(v);
            }
        }
        Q.pop();
    }
    cout<<endl;
}

void BFS::bfsVisit(char v)
{

}

int BFS::search(char v)
{
    for(int i=0;i<size;i++)
    {
        if(nodesArray[i]==v)
            return i;
    }
    return -1;
}

class DFS : public Graph
{
    int size;
    int time;
public:
    char nodesArray[SIZE];
    int color[SIZE];
    int startingTime[SIZE];
    int finishingTime[SIZE];
    char parent[SIZE];
    queue<char>Q;
    void initiatization (Graph &G);
    void dfs(Graph &G,char v);
    void dfsVisit(Graph &G, char v);
    int search(char v);
};

void DFS::initiatization(Graph &G)
{
    int count = 0;
    time = 0;
    node *temp = G.nodeList;
    while(temp!=NULL)
    {
        color[count] = 0;
        startingTime[count] = 0;
        finishingTime[count] = 0;
        parent[count] = NULL;
        nodesArray[count++] = temp->element;
        temp = temp->nextElement;
    }
    size = count;
/*
    for(int i=0;i<size;i++)
    {
        cout<<nodesArray[i]<<"\t";
    }
    cout<<endl;
*/
}

void DFS::dfs(Graph &G, char source)
{
    initiatization(G);
    int sourceIndex = search(source);

    //swap Source to first element on the list.
    char ch = nodesArray[sourceIndex];
    nodesArray[sourceIndex] = nodesArray[0];
    nodesArray[0] = ch;
    time = 0;
    cout<<endl;
    for(int index = 0; index <size ; index++)
    {
        char v = nodesArray[index];
        if(color[index] == 0)
        {
            dfsVisit(G,v);
        }
    }
    cout<<endl;
}

void DFS::dfsVisit(Graph &G, char v)
{
    int vIndex = search(v);
    cout<<v<<"\t";
    color[vIndex] = 1;
    time++;
    startingTime[vIndex]=time;
    node *temp = G.search(v);
    for(adjacencyList *tempList = temp->list;   tempList!=NULL; tempList = tempList->nextName)
    {
        char u = tempList->nodeName->element;
        int uIndex = search(u);
        if(color[uIndex]==0)
        {
            parent[uIndex] = u;
            dfsVisit(G,u);
        }
    }
    color[vIndex]=2;
    time++;
    finishingTime[vIndex]=time;
}

int DFS::search(char v)
{
    for(int i=0;i<size;i++)
    {
        if(nodesArray[i]==v)
            return i;
    }
    return -1;
}

class operationGraph
{
public:
    static void inputGraph();
    static void readFromFile(Graph &G);
};

void operationGraph::inputGraph()
{
        ofstream fout ("GraphOfflineInput.txt");

        if(!fout)
        {
            cout<<"Can't open.\n";
            exit(-1);
        }

        cin>>nodeNumber;
        fout<<nodeNumber<<endl;
        string str;
        cin>>str;

        while(str!="end")
        {
            fout<<str;
            fout<<"\n";
            cin>>str;
        }

        fout.close();
}

void operationGraph::readFromFile(Graph &G)
{
    ifstream fin ("GraphOfflineInput.txt");
    if(!fin)
    {
        cout<<"cannot open GraphOfflineInput.txt\n";
        exit(-1);
    }

    string str;
    fin>>nodeNumber;

    for(int i=0;i<nodeNumber;i++)
    {
        fin>>str;
        G.insertNode(str[0]);
    }

    while(!fin.eof())
    {
        fin>>str;
        for(int i=2;i<str.size();i+=2)
        {
            G.createAdjacencyList(str[0],str[i]);               //str[0] == main node, str[i] == connected to  main node.
        }
    }

    fin.close();
}

int main()
{
    Graph G;
    operationGraph::readFromFile(G);
    G.show();
    BFS B;
    for(char i = 'a';i<'a'+nodeNumber;i++)
    {
        B.initiatization(G);
        cout<<"Bfs Search on the node "<<i<<endl;
        B.bfs(G,i);
        cout<<endl;
    }
    DFS D;
    for(char i = 'a';i<'a'+nodeNumber;i++)
    {
        cout<<"Dfs Search on the node "<<i<<endl;
        D.dfs(G,i);
        cout<<endl;
    }
    G.insertNode('a');
    G.createAdjacencyList('a','h');
    B.bfs(G,'a');
    D.dfs(G,'a');
    G.show();
    return 0;
}
