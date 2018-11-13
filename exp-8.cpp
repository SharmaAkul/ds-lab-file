#include<iostream>
using namespace std;

int main()
{

	int n, arr[50], i, j, temp,num;
	cout<<"Enter Array Size : ";
	cin>>n;
	cout<<"Enter Array Elements : ";
	for(i=0; i<n; i++)
	{
		cin>>arr[i];
	}
	cout<<"Sorting array using insertion sort ... \n";
    for(i=1; i<n; i++)
	{
		temp=arr[i];
		j=i-1;
		while((arr[j]>temp) && (j>=0))
		{
			arr[j+1]=arr[j];
			j=j-1;
		}
		arr[j+1]=temp;
	}
	cout<<"Array after sorting : \n";
	for(i=0; i<n; i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl<<"enter  the number to insert :";
	cin>>num;
	for(i=0;i<n;i++){
        if(num>arr[i] && num<=arr[i+1] && i<n){
            j=i+1;
            break;
        }
	}

	for(i=n;i>=j;i--){
       arr[i]=arr[i-1];
       if(i==j){
        arr[i]=num;
       }
	}
	for(i=0; i<n+1; i++)
	{
		cout<<arr[i]<<" ";
	}

return 0;
}
