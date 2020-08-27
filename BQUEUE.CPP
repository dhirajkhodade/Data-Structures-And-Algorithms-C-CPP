
#include<iostream.h>
#include<conio.h>




class myQueue
{
	 struct node
	{
	    int data;
	    node *link;
	}*head;

       public:
       myQueue()
       {
	 head=new node;
	 head->link=NULL;

       }
       ~ myQueue();
       void add(int n);
       void add(int n,char side);
       void display();
       int pop();
       int pop(char side);
       void menu();
       void queue();
       void queue1();
};
     myQueue:: ~myQueue()
       {
	   node*cur=head;
	   while(cur)
	   {       head=cur;
		   delete head;
		   cur=cur->link;
	   }
       }

void myQueue::add(int n)
{
    node* temp=new node;
    temp->data=n;
    temp->link=NULL;
    node *cur=head;

    while(cur->link!=NULL)
     cur=cur->link;

    cur->link=temp;
    cout<<"\nNo is inserted SuccessFully...";
}
void myQueue::add(int n,char side)
{
    node* temp=new node;
    temp->data=n;
    temp->link=NULL;
    node *cur;

   if(side=='R'||side=='r')
   {
	cur=head;
	while(cur->link!=NULL)
	     cur=cur->link;

	cur->link=temp;
   }
   if(side=='f'||side=='F')
   {
     temp->link=head->link;
     head->link=temp;
   }
    cout<<"\nNo is inserted SuccessFully...";
}

int myQueue::pop()
{
    node* cur;
    int n;

    if(head->link==NULL)
      return(-99);

    cur=head->link;
    head->link=cur->link;
    n=cur->data;
    delete cur;
    return(n);
}
int myQueue::pop(char side)
{
    node* cur,*prev;
    int n;

    if(head->link==NULL)
      return(-99);

    if(side=='f'||side=='F')
    {
	    cur=head->link;
	    head->link=cur->link;
	    n=cur->data;
    }
     if(side=='r'||side=='R')
    {
	    prev=head;
	    cur=head->link;

	    while(cur->link!=NULL)
	    {
	       prev= cur;
	       cur=cur->link;
	    }
	    prev->link=NULL;
	    n=cur->data;
    }

    delete cur;
    return(n);
}


void myQueue::menu()
{
    cout<<"\n***   Queue Operation   *************";
    cout<<"\n1:Push ";
    cout<<"\n2:Pop";
    cout<<"\n3:Display";
    cout<<"\n4:Return To Main Program";
}


void  myQueue::display()
{
  node *cur;
  cur=head->link;

  cout<<"\nYour Queue is:=\n";

  while(cur!=NULL)
  {
      cout<<"    "<<cur->data;
      cur=cur->link;
  }

}



void myQueue::queue()
{
       int ch,n;
  while(1)
  {
       menu();
       cout<<"\nEnter Your Choice:";
       cin>>ch;
    switch(ch)
    {
      case 1:
	     cout<<"\nEnter No To be Push ";
	     cin>>n;
	     add(n);
	     break;
      case 2:
	     n=pop();
	     if(n==-99)
	     {
		 cout<<"\nQueue is Empty";
	     }
	     else
	      cout<<"\nDeleted No is  "<<n;

		 break;
      case 3: display();
		break;
      case 4:return;

      default:
	       cout<<"\nYou have Entered Wrong Choice....";

     }
     getch();
   }
}

void myQueue::queue1()
{
       int ch,n;

       char side;
 while(1)
 {
       menu();
       cout << "\nEnter Your Choice:";
       cin>>ch;
    switch(ch)
    {
      case 1:
	     cout<<"\nEnter No To be Push ";
	     cin>>n;
	     cout<<"\nEnter side (Front/Rear)";
	     cin>>side;
	     add(n,side);
	     break;
      case 2:
	     cout<<"\nEnter side (Front/Rear)";
	     cin>>side;

	     n=pop(side);
	     if(n==-99)
	     {
		 cout<<"\nQueue is Empty";
	     }
	     else
	      cout<<"\nDeleted No is  "<<n;

		 break;
      case 3: display();
		break;
      case 4:return;
      default:
	       cout<<"\nYou have Entered Wrong Choice....";

     }
  getch();
  }
 }

int  main()
{
     myQueue A;
     myQueue DQ;

     int ch,n;
     clrscr();


   while(1)
   {
     cout<<"\n1:Simple Queue\n2:Double Endend Queue\n3:Exit";
     cout<<"\nEnter Your Choice::";
     cin>>ch;
     switch(ch)
     {
	case 1:A.queue();
		  break;

	case 2: DQ.queue1();

		  break;
	case 3:   return 0;

	default:
	       cout<<"\nYou have Entered Wrong Choice....";

    }

     getch();
   }
}



