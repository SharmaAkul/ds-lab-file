#include <iostream>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;
class bfs{
int v;
int *A;
int arr[10][10];
int x,y;
public:
bfs()
{
    cout<<"enter total vertices: ";
    cin>>v;

    int i,j;
   A=new int[v];
    //int *arr=(int *)malloc(v*v*sizeof(int));
    for(i=0;i<v;i++)
    {

        A[i]=0;

    }
    for(i=0;i<v;i++)
    {
        for(j=0;j<v;j++)
        {
            arr[i][j]=0;//adjancey matrix;
        }
    }
}

    void create(int ed)
    {
        for(int i=1;i<=ed;i++)
        {
           cout<<"enter directed: ";
            cin>>x>>y;
            arr[x][y]=1;
        }
    }
    void logic()
    {
        int source;
    cout<<"enter source: ";
        cin>>source;
    queue<int>q;

    A[source]=1;
    q.push(source);
//cout<<source<<" ";

    while(!q.empty())
    {
    int res=q.front();
    cout<<res<<" ";
    q.pop();

    for(int i=0;i<v;i++)//to check the neighbors;
    {
        if(arr[res][i]==1)
        {
            if(A[i]!=1)
            {
                A[i]=1;
                q.push(i);
            }
        }
    }
    }
    }
};

int main()
{
    bfs b;
    int edge;
    cout<<"enter no. of edges: ";
    cin>>edge;
    b.create(edge);
    b.logic();
  return 0;
}
