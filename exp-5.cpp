/* Q: Write a menu driven program that implements the following operations on a   
      circular linked list :
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
};
struct node *head=NULL;
void create_node()
{
   node *temp=new node;
   cout<<"enter the data : ";
   cin>>temp->data;
   temp->next=NULL;
   if(head==NULL)
   {
   	 head=temp;
   	 temp->next=head;
   }
   else
   {
   	node *p=head;
   	while(p->next!=head)
   	{
   	    p=p->next;	
    }
       p->next=temp;
       temp->next=head;
   }	
}
void insert_beg()
{
    if(head==NULL)
	{
       create_node(); 
    }
    else
	{
	node *temp=new node;
	node *t;
    cout<<"enter the data : " ;
    cin>>temp->data;
    t=head;
    while(t->next!=head)
       t=t->next;
       temp->next=head;
       head=temp;
       t->next=head;
    }
}
void insert_mid()
{
   if(head==NULL)
   {
   	create_node();
   }
   else
   {
   	int n;
   	node *temp=new node;
    cout<<"enter the data : ";
    cin>>temp->data;
    temp->next=NULL;
    cout<<"enter the node after which u want to insert : ";
	cin>>n;
	node *t=head;
	while(t->data!=n)
	  t=t->next;
	  temp->next=t->next;
	  t->next=temp;
   }	
}
void insert_end()
{
   if(head==NULL)
   {
   	create_node();
   }
   else
   {
   	node *temp=new node;
   cout<<"enter the data : ";
   cin>>temp->data;
   temp->next=NULL;
   	node *p=head;
   	while(p->next!=head)
   	{
   	    p=p->next;	
    }
       p->next=temp;
       temp->next=head;
   }	
}
void delete_beg()
{
   node *temp=new node;
	 if(head==NULL)
        {
            cout<<"\nList is Empty:\n";
        }
     else
        {
        	node *p;
            p = head;
        while (p -> next != head)
            p = p -> next;
        head = head->next;
        p->next = head;
		}		
}
void delete_mid()
{
	int pos;
	if(head==NULL)
    {
       cout<<"\nList is Empty:\n";
    }
    else
    {
      node *temp=new node;
     cout<<"enter the position of the node to be deleted : ";
     cin>>pos;
     if(pos==0)
       delete_beg();
     else
       {
       	 node *p;
       	 p=head;
       	  for(int i=0;i<pos;i++)
	      {
	 	    temp=p;
	 	    p=p->next;
		  }	
		  temp->next=p->next;
		  delete p;
	   }
	}
}
void delete_end()
{
	 node *temp=new node;
	 if(head==NULL)
        {
            cout<<"\nList is Empty:\n";
        }
     else
     {
     	node *p;
     	p=head;
     	while(p->next!=head)
     	{
     		temp=p;
     		p=p->next;
		}
		 temp->next=head;
		 delete p;
	 }
}
void search()
{
	int e,flag=0;
	node *ptr;
	ptr=head;
	cout<<"enter element to be searched : ";
	cin>>e;
	while(ptr->next!=head)
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
  node *temp;
  temp=head;
 do {
       cout<<temp->data<<"->";
	   temp = temp->next;
    }while(temp!=head);
  cout<<head->data;
  cout<<endl;
}

int main()
{
	cout<<" 1. Create node \n 2. Insertion at beginning \n 3. Insertion at middle \n 4. Insertion at end \n 5. Delete from beginning \n 6. Delete from middle \n 7. Delete from end \n 8. Search \n 9. Display \n 10. Exit"<<endl;
	int choice;
	while(1)
	{
		cout<<"enter the choice : ";
		cin>>choice;
		switch(choice)
		{
			case 1:
				{
					create_node();
					break;
				}
		    case 2:
		    	{
		    		insert_beg();
		    		break;
				}
			case 3:
				{
					insert_mid();
					break;
				}
			case 4:
				{
					insert_end();
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
					cout<<" - - - -  - - - - - - - - - - - - - - - - - T H A N K S - - - - - - - - - - - - - - - - - - - - -  - - - -- - - - "<<endl;
					exit(1);
				}
		}
	}
	return 0;
}
