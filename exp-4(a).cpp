/* Q: Write a menu driven program that implements the following operations on a   
      doubly linked list :
	  -> Insert a new element at the beginning ,end and in-between the given list
	  -> Delete an existing element
	  -> Search an element
	  -> Display all the elements 
*/
#include<iostream>
using namespace std;
struct node
{
	int data;
	node *next;
	node *prev;
}*save;
static int a;
struct 	node *head,*tail;
void create_node()
{
	a++;
	int i;
	cout<<"enter the data : ";
	cin>>i;
	node *temp=new node;
	temp->data=i;
	temp->next=NULL;
	if(head==NULL)
	{
	   	temp->prev=NULL;
	    head=temp;	
	}
	else
	{
		save=head;
		while(save->next!=NULL)
		{
			save=save->next;
		}
		save->next=temp;
		temp->prev=save;
	}
}
void add_beg_node()
{
	int i;
	if(head==NULL)
	{
		create_node();
	}
	else
	{
			a++;
	cout<<"enter the data : ";
	cin>>i;
	node *temp=new node;
	temp->data=i;
	temp->prev=NULL;
	temp->next=head;
	head->prev=temp;
	head=temp;
	}
}
void add_mid_node()
{
	if(head==NULL)
	{
		create_node();
	}
	a++;
	int i,n;
	cout<<"enter the data : ";
	cin>>i;
    node *temp=new node;
	node *temp1=new node;
	temp->data=i;
	temp->next=NULL;
	cout<<"enter the node after which u want to insert : ";
	cin>>n;
	temp1=head;
    while(temp1->data!=n)
    {
      temp1=temp1->next;
    }
	  temp->next=temp1->next;
	  temp1->next=temp;
	  temp->prev=temp1;
	  temp1->next->prev=temp;
  }
void add_end_node()
{
	if(head==NULL)
	{
	   create_node();
	}
	else
	{
		int i;
	   cout<<"enter the data : ";
	   cin>>i;
	   node *temp=new node;
	   temp->data=i;
	   temp->next=NULL;
		a++;
		save=head;
		while(save->next!=NULL)
		{
			save=save->next;
		}
		save->next=temp;
		temp->prev=save;
	}
}
void delete_beg()
{
	a--;
	node *temp=new node;
	 if(head==NULL)
        {
            cout<<"\nList is Empty:\n";
        }
     else
        {
            temp=head;
	        head=head->next;
	        head->prev=NULL;
	        delete temp;	
		}	
}
void delete_end()
{
	a--;
	 struct node *temp,*ptr;
     if(head==NULL)
        {
    	    cout<<"\nList is Empty:\n";
	    }
	 else if(head->next==NULL)
	    {
	 	    ptr=head;
	 	    head=NULL;
	 	    delete ptr;
	    }
	 else
	    {
	 	   ptr=head;
	 	   while(ptr->next!=NULL)
	 	   {
	 	    	temp=ptr;
			   ptr=ptr->next;
	   	   }
		   temp->next=NULL;
		   delete ptr;
	    }
}
void delete_mid()
{
	int pos;
	node *temp,*ptr;
	 if(head==NULL)
        {
            cout<<"\nList is Empty:\n";
        }
     cout<<"enter the position of the node to be deleted : ";
     cin>>pos;
     if(pos==0)
       delete_beg();
     else if(pos==a-1)
       delete_end();
     else
     {
     	a--;
     	ptr=head;
     	for(int i=0;i<pos;i++)
     	{
     		temp=ptr;
     		ptr=ptr->next;
     		if(ptr==NULL)
     		   cout<<"Location not found"<<endl;
		 }
		 if(ptr->next->data==pos)
		 {
		 	temp=ptr->next;
		 	delete temp;
		 	ptr->next=NULL;
		 }
		 else
		 {
		    temp->next=ptr->next;
		 ptr->next->prev=temp;
		 delete ptr;	
		 }
		 
	 }
}
void search()
{
	int e,flag=0;
	node *ptr;
	ptr=head;
	cout<<"enter element to be searched : ";
	cin>>e;
	while(ptr!=NULL)
	{
		if(ptr->data==e)
		 flag=1;
		 ptr=ptr->next;
	}
	if(flag==1)
	  cout<<"Found"<<endl;
	else
	  cout<<"Not Found"<<endl;
}
void display()
{
	if(head==NULL)
        {
    	    cout<<"\nList is Empty:\n";
    	     exit(0);
	    }
	node *temp;
	temp=head;
	while(temp!=NULL)
	{
		cout<<temp->data<<"->";
		temp=temp->next;
	}
	cout<<endl; 
}
int main()
{
	int i,n,c;
	
    cout<<" 1  -> create node \n 2  -> Insertion at beginning \n 3  -> Insertion at any position \n 4  -> Insertion at end \n 5  -> Delete from beginning \n 6  -> Delete at any position \n 7  -> Delete from end \n 8  -> Search \n 9  -> Display \n 10 -> Exit "<<endl;
	while (1)
	{
		cout<<"enter the choice : ";
		cin>>c;
	switch(c)
	{
		case 1:
		    {
			    create_node();
			    break;
	        }
		case 2:
			{
			    add_beg_node();
				 break;	
		    }
		case 3:
			{
		        add_mid_node();
             	break;
		    }
		case 4:
			{
			     add_end_node();
				 break;	
		    }
		case 5:
		  	{
		    	 delete_beg();
		    		break;
			}
		case 6:
		  	{
		    	 delete_mid();
		    		break;
			}
		case 7:
		  	{
		    	 delete_end();
		    		break;
			}
		case 8:
		  	{
		    	 search();
		    		break;
			}
		case 9:
		    {
		         display();
		         break;
			}
		case 10:
			{
				 cout<<endl;
	    		 cout<<"- - - - - - - - - - - - - - - - - - - - - - - - - - - T H A N K S !!!- - - - - - - - - - - - - - - - - - - - - - - - - - - - "<<endl;
				 exit(0);	
			}
	            	
			}
	}
	return 0;
}
