#include<iostream.h>
#include<stdio.h>
#include<conio.h>

int x,e,d,y,s,op1;

class list
 {
  public:
		int data;
		list *link;

		void create();
		void insert(list*);
		void display(list *);
		void del();
		void revers();
		void search();

 }*first,*p,*q,*r;


void main()
   {
	list s;
	first=NULL;
	clrscr();
	do
	  {
	   cout<<"\n\t\t\t!!!Menu!!!\n1:Create\n2:Insert\n3:Delete\n4:Revers\n5:Search";
	   cout<<"\n What you Want From Menu = ";
	   cin>>d;
	   switch(d)
		{
		  case 1:
			  cout<<"\n\t\t!!!Create!!!";
			  if(first==NULL)
				 s.create();
			  else
				 {
				  cout<<"\n Head Node is Already Present";
				 }
			 break;
		  case 2:
			  cout<<"\n\t\t!!!Insert!!!";
			  if(first!=NULL)
				  s.insert(first);
			  else
				cout<<"\n List is Empty";
			 break;
		  case 3:
			  cout<<"\n\t\t!!!Delete!!!";
			  if(first!=NULL)
				  s.del();
			  else
				cout<<"\n List is Empty";
			 break;
		  case 4:
			  cout<<"\n\t\t!!!Reverse!!!";
			  if(first!=NULL)
				s.revers();
			  else
				cout<<"\n List is Empty";
			 break;
		  case 5:
			  cout<<"\n\t\t!!!Search!!!\n";
			   if(first!=NULL)
				s.search();
			  else
				cout<<"\n List is Empty";
			 break;

		  default:
			  cout<<"Wrong Choice";
		 }
		cout<<"\nDo you Want to Continue  <1:Yes> :: <2:No>=";
		cout<<e;

	   }while(e==1);
	getch();
 }


void list :: create()
	  {
		int x;
		p=new list;
		cout<<"\n Enter the Data = ";
		cout<<p->data;

		p->link=NULL;
		first=p;
	  }


void list :: insert(list *first)
	  {
		 int y,y1;
		 cout<<"\n\t"<<p->data;
			do
			 {
				q=new list;
				cout<<"\n Enter the Data = ";
				cin>>y;

				q->data=y;
				q->link=NULL;

				cout<<"\nInsert At\n\t1=Start\t\t2=Middle\t\t3=Last \n =";
				cin>>op1;
				switch(op1)
				  {
					case 1:
							q->link=first;
							first=q;
					   break;
					case 2:
							cout<<"\nEnter the Data to be  after  insert = ";
							cin>>y1;

							q->data=y;
							q->link=NULL;

							for(p=first;p->data!=y1;p=p->link);
								  q->link=p->link;
								  p->link=q;
					   break;
					case 3:
							q->data=y;
							q->link=NULL;
							for(p=first;p->link!=NULL;p=p->link);
							  p->link=q;
					   break;
				  }
					 cout<<"\n Do You Want To Add Another Record <1:Yes> || <2:No> =>";
					 cin>>s;
					 display(first);
			 }while(s==1);
	   }


void list :: display(list *p)
	  {
		for(p=first;p!=NULL;p=p->link)
		   {
			cout<<" "<<p->data;
				if(p->link!=NULL)
					 cout<<"->";
		   }
	  }


void list :: del()
	  {
		int op1,x,y,a;
		  do
			{
			 p=first;

			 cout<<"\nDelete at \n\t1:first \t2:Middle\t3:Last";
			 cout<<"\nEnter your choice = ";
			 cout<<" "<<op1;
			  switch(op1)
				 {
					case 1:
						  first=first->link;
						  p=first;
					   break;
					case 2:

						 cout<<"Enter the Node to be Delete= ";
						 cin>>y;
						 while(p->data!=y)
							{
							 q=p;
							 p=p->link;
							}
							q->link=p->link;
						  delete p;
						break;
					case 3:
						 while(p->link!=NULL)
							{
							 q=p;
							 p=p->link;
							}
							q->link=p->link;
						  delete p;
					 break;
				 }
			  display(first);
			  cout<<"\nDo you Want to delete another data <1:Yes> || <2:No>=>";
			  cin>>a;
		  }while(a==1);
	  }

void list :: revers()
	   {
		  cout<<"\n\n Reversed LInklist = \t";
		  p=first;
		  q=NULL;
		  while(p->link!=NULL)
			  {
			   r=q;
			   q=p;
			   p=p->link;
			   q->link=r;
			  }
			p->link=q;
			first=p;
		  display(p);
	   }

void list :: search()
	  {
		int x,t=0;

		cout<<"\nEnter data to be search=";
		cin>>x;

		for(p=first;p->data!=NULL;p=p->link)
			{
			  t=0;
			  if(p->data==x)
				{
				  t=1;
				  break;
				}
			}
		if(t==1)
		  {
		   cout<<"\nData is Present";
		  }
		else
		 {
		   cout<<"\nData is Absent";
		 }
	 }





