#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;
class dfs{
int *A;
int arr[10][10];
int v;
public:
    dfs()
    {
        int i,j;
        cout<<"enter no. of vertices: ";
        cin>>v;
        A=new int[v];
        for(i=1;i<=v;i++)
        {
            A[i]=0;
        }

        for(i=1;i<=v;i++)
        {
            for(j=1;j<=v;j++)
            {
                arr[i][j]=0;
            }
        }

    }
    void create(int ed)
    {
        int x,y;
        for(int i=1;i<=ed;i++)
        {
            cout<<"directed : ";
            cin>>x>>y;
            arr[x][y]=1;
        }

    }
    void logic()
    {
        stack<int>s;
        int source;
        cout<<"enter source: ";
        cin>>source;

        A[source]=1;
        s.push(source);
        int res;
        while(!s.empty())
        {
        res=s.top();
        cout<<res<<" ";
        s.pop();

        for(int i=1;i<=v;i++)
        {
            if(arr[res][i]==1)
            {
                if(A[i]!=1)
                {
                    A[i]=1;
                    s.push(i);
                    break;//to exit the loop;
                }
            }
        }
        }
    }
};
int main()
{
 dfs d;
 int ed;
 cout<<"enter edges: ";
 cin>>ed;
 d.create(ed);
    d.logic();
    return 0;
}
