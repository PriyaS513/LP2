#include <iostream>
#include <vector>
#include <queue>
#define max 10
using namespace std;

class node
{
    public:
    int vertex;
    node *next;
};

class graph
{
    int n;
    int visited[max];
    node *arr[max];
    vector <int> vis;

    public:
    graph()
    {
        for(int i=0;i<max;i++)
        {
            arr[i]=new node;
            arr[i]->vertex=0;
            arr[i]->next=NULL;
        }
    }
    void read_graph();
    void initvisited();
    void dfs(int v);
    void recursiveBFS(queue <int> &que);
};

void graph::read_graph()
{
    int v;
    char ans;
    cout<<"Enter number of vertices:";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        node *temp = arr[i];
        do
        {
            cout<<"Enter the vertex to join to "<<i<<":-";
            cin>>v;
            node *curr=new node;
            curr->vertex=v;
            curr->next=NULL;
            temp->next=curr;
            temp=curr;
            cout<<"Do you want to add more(Y/N)??";
            cin>>ans;
        } while (ans=='Y' || ans=='y');
    }
}

void graph::initvisited()
{
    for(int i=0;i<n;i++)
    {
        visited[i]=0;
    }
}

void graph::dfs(int v)
{
    node *temp;
    temp=arr[v]->next;
    visited[v]=1;
    cout<<v<<" "<<" ";
    while(temp!=NULL)
    {
        if(!visited[temp->vertex])
        dfs(temp->vertex);
        temp=temp->next;
    }
}



void graph::recursiveBFS(queue <int> &que)
{
    if(que.empty())
    return;

    int current_node=que.front();
    cout<<current_node<<"";
    que.pop();

    visited[current_node]=1;
    node *first=arr[current_node]->next;
    while(first!=NULL)
    {
        if(!visited[first->vertex])
        {
            que.push(first->vertex);
            visited[first->vertex]=1;
        }
        first=first->next;
    }
    recursiveBFS(que);
}

int main()
{
     
    graph g;
    int m;
    queue <int> bfsq;
    do
    {
        cout<<"\n---------MAIN MENU------------\n";
        cout<<"1)INSERT\n";
        cout<<"2)BFS\n";
        cout<<"3)DFS\n";
        cout<<"4)EXIT\n";
        cout<<"Enter your choice:\n";
        cin>>m;
        switch(m)
        {
            case 1:
            g.read_graph();
            break;

            case 2:
            int a;
            cout<<"Enter the vertex to start bfs from ";
            cin>>a;
            g.initvisited();
            bfsq.push(a);
            g.recursiveBFS(bfsq);
            break;

            case 3:
            int b;
            cout<<"Enter the vertex to start dfs from ";
            cin>>b;
            g.initvisited();
            g.dfs(b);
            break;

            case 4:
            
            break;
        }
    } while (m!=5);
    return 0;
}

/*

---------MAIN MENU------------
1)INSERT
2)BFS
3)DFS
4)EXIT
Enter your choice:
1
Enter number of vertices:5
Enter the vertex to join to 0:-1
Do you want to add more(Y/N)??y
Enter the vertex to join to 0:-2
Do you want to add more(Y/N)??n
Enter the vertex to join to 1:-2
Do you want to add more(Y/N)??y
Enter the vertex to join to 1:-3
Do you want to add more(Y/N)??n
Enter the vertex to join to 2:-4
Do you want to add more(Y/N)??n
Enter the vertex to join to 3:-4
Do you want to add more(Y/N)??n
Enter the vertex to join to 4:-3
Do you want to add more(Y/N)??n

---------MAIN MENU------------
1)INSERT
2)BFS
3)DFS
4)EXIT
Enter your choice:
2
Enter the vertex to start bfs from 0
01234
---------MAIN MENU------------
1)INSERT
2)BFS
3)DFS
4)EXIT
Enter your choice:
3
Enter the vertex to start dfs from 0
0  1  2  4  3
---------MAIN MENU------------
1)INSERT
2)BFS
3)DFS
4)EXIT
Enter your choice:
4

---------MAIN MENU------------
1)INSERT
2)BFS
3)DFS
4)EXIT
Enter your choice:
1
Enter number of vertices:5
Enter the vertex to join to 0:-1
Do you want to add more(Y/N)??y
Enter the vertex to join to 0:-2
Do you want to add more(Y/N)??n
Enter the vertex to join to 1:-0
Do you want to add more(Y/N)??y
Enter the vertex to join to 1:-2
Do you want to add more(Y/N)??y
Enter the vertex to join to 1:-3
Do you want to add more(Y/N)??n
Enter the vertex to join to 2:-0
Do you want to add more(Y/N)??y
Enter the vertex to join to 2:-1
Do you want to add more(Y/N)??y
Enter the vertex to join to 2:-4
Do you want to add more(Y/N)??n
Enter the vertex to join to 3:-1
Do you want to add more(Y/N)??y
Enter the vertex to join to 3:-4
Do you want to add more(Y/N)??n
Enter the vertex to join to 4:-2
Do you want to add more(Y/N)??y
Enter the vertex to join to 4:-3
Do you want to add more(Y/N)??n

---------MAIN MENU------------
1)INSERT
2)BFS
3)DFS
4)EXIT
Enter your choice:
2
Enter the vertex to start bfs from 0
01234
---------MAIN MENU------------
1)INSERT
2)BFS
3)DFS
4)EXIT
Enter your choice:
3
Enter the vertex to start dfs from 0
0  1  2  4  3
---------MAIN MENU------------
1)INSERT
2)BFS
3)DFS
4)EXIT
Enter your choice:
4
*/