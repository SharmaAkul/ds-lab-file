/* Q: Write a program to accept N integers from the user and store them in an array. Sort the array in ascending order using 
      Bubble sort. Then accept another number from the user, search whether that number exists in the array using Binary 
      Search. If it does, display its index and if it doesn't, then print that the number is not found in the array.*/
#include<iostream>
using namespace std;
void bubblesort(int arr[],int size)
{
   int temp,i,j;
   for(i=0;i<size-1;i++)
   {
 	 for(j=0;j<size-1-i;j++)
 	 {
 		if(arr[j]>arr[j+1])
 		{
 			temp=arr[j];
 			arr[j]=arr[j+1];
 			arr[j+1]=temp;
		 }
	 }
   } 	
}
void binarysearch(int arr[],int size,int ele)
{
    int  low=0;
    int high=size-1;
    int mid,b,flag=0;
	while(low<=high)
	{
		mid=(low+high)/2;
		if(ele==arr[mid])
		{
		     b=mid;
		     cout<<"Element "<<ele<<" is at "<<b<<" position"<<endl;
			 flag=1;	
		     break;
		}
		else if(ele>arr[mid])
		{
			low=mid+1;
		}
		else
			high=mid-1;
	}
	if(flag==0)
	{
		cout<<"element not found in the above array";
	}	
}
int main()
{
	int size,ele;
	cout<<"Enter the size of array : ";
	cin>>size;
	int arr[size];
	cout<<"Enter elements ->"<<endl;
	for(int i=0;i<size;i++)
	   cin>>arr[i];
	bubblesort(arr,size);
	cout<<"Array after sorting ->"<<endl;
	for(int i=0;i<size;i++)
	   cout<<arr[i]<<" ";
	cout<<endl;
	cout<<"Enter the element to be searched : ";
	cin>>ele;
	binarysearch(arr,size,ele);
}
