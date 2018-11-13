#include <iostream>

using namespace std;

void quick_sort(int[],int,int);
int partition(int[],int,int);

int main()
{
    int a[50],n,i;
    cout<<"How many elements?";
    cin>>n;
    cout<<"\nEnter array elements:";

    for(i=0;i<n;i++)
        cin>>a[i];

    quick_sort(a,0,n-1);
    cout<<"\nArray after sorting:";

    for(i=0;i<n;i++)
        cout<<a[i]<<" ";

    return 0;
}

void quick_sort(int a[],int l,int h)
{
    int j;
    if(l<h)
    {
        j=partition(a,l,h);
        quick_sort(a,l,j-1);
        quick_sort(a,j+1,h);
    }
}

int partition(int a[],int l,int h)
{
    int p,i,j,temp;
    p=a[l];
    i=l;
    j=h;

            while(i<=j)
        {
            while(a[i]<=p)
                i++;
            while(a[j]>p)
                j--;


        if(i<j)
        {
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }

    }
 //  while(i<j);

    a[l]=a[j];
    a[j]=p;

    return(j);
    }

