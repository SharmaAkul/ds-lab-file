/* Q. write a programto accept N numbers from user and stores them in array.Then accept another number from user
and search that using linear search.*/
#include<iostream>
using namespace std;

int main(){
int arr[10],a,flag=0,n;
cout<<"enter the elements of array"<<endl;
cin>>n;
cout<<"enter elements of array"<<endl;
for(int i=0;i<n;i++){
cin>>arr[i];
}
cout<<"enter element to find"<<endl;
cin>>a;
for(int i=0;i<n;i++){
if(a==arr[i]){
        flag=1;
cout<<arr[i]<<"at position "<<i<<endl;

}
}
if(flag==0){
        cout<<"not found";
}
return 0;
}
