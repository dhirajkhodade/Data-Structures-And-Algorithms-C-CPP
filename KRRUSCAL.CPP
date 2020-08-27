#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
#define MAX 20

class graph;
class node
{
 int data;
 int wt;
 node *link;
 friend class graph;
};

class graph
{
  node *arr[MAX];

  public:
	graph()
	{
	  int i;
	  for(i=0;i<MAX;i++)
	  {
	   arr[i]=NULL;
	  }
	}
   int ver;
   void creat();
   void krus(graph);
};
int present(int,int *,int);


void main()
{
	int ans,ch;
	graph g;

	clrscr();

	do
	{
	clrscr();
	cout<<"****MENU****\
		\n1].Creat\
		\n2].Kruscal algo\
		\n3].exit";

	cout<<"\nENTER YOUR CHOICE::";
	cin>>ch;

	switch(ch)
	{
	case 1:
			cout<<"Enter total number of vertex of graph";
	cin>>g.ver;

	  g.creat();
	break;
	case 2:
	  g.krus(g);
	break;
	case 3:
	  exit(1);
	default:
	cout<<"INVALID CHOICE...";
	}
	cout<<"\nDo you want to conitinue to main menu";
	cin>>ans;
	}while(ans==1);
}


void graph::creat()
{
  int i=1,ans,adj;
  node *p,*q;

	do
	{
	 clrscr();

		 cout<<"\nEnter vertex number whose adjecent to be insert::";
		 cin>>i;
		if(i<=ver)
		{
		 do
		 {
		  cout<<"\nEnter adjecent vertices of:"<<i<<"->";
		  cin>>adj;
			if(adj<=ver)
			{
			 p=new node;
			 p->link=NULL;
			 p->data=adj;
			 cout<<"\nEnter weight of edge("<<i<<","<<adj<<")::";
			 cin>>p->wt;
			 if(arr[i]==NULL)
			 {
			  arr[i]=p;
			 }
			 else
			 {
			   q=arr[i];
			   while(q->link!=NULL)
			   {
				q=q->link;
			   }
			   q->link=p;
			 }
		   }
		   else
		   {
			cout<<"\nInvalid choice of adjecent vertex";
		   }

		  cout<<"\nDo you want to enter more adjecent vertex of:"<<i<<"press(1/2)";
		  cin>>ans;
		 }while(ans==1);
		}
		else
		{
		  cout<<"\nInvalid choice of vertex";
		}

		 cout<<"\nDo you want to enter adjecent of more vertex:";
		 cin>>ans;
   }while(ans==1);

   clrscr();
   cout<<"ADJECENCY LIST FOR THE GIVEN GRAPH IS::\n\n";
   for(i=1;i<=ver;i++)
   {
	 cout<<"\n\n"<<i<<"adjecents->";
	 q=arr[i];
	 while(q!=NULL)
	 {
	  cout<<"["<<q->data<<"-"<<q->wt<<"]"<<"->";
	  q=q->link;
	 }
	 cout<<"NULL";
   }
   getch();
}


void graph::krus(graph g)
{

 int t[MAX];
 int i=1,j;
 int v,v1,v2;
 int min=999;
 int cn=1;
 node *curr;
 int edge[MAX][MAX]={0};
 int sum=0;
 cout<<"\nENTER STARTING VERTEX::";
 cin>>v;
 t[1]=v;
cn=g.ver;
   while(i<ver)
   {
		  min=9999;  //imp
		  for(j=1;j<=cn;j++)
		  {

			  v=t[j];
			 curr=arr[v];

			while(curr)
			{
			  if(!present(curr->data,t,cn)&&curr->wt< min)
			  {
				min=curr->wt;
				v1=v;
				v2=curr->data;
			  }
			  curr=curr->link;
			}
		  }
			edge[v1][v2]=edge[v2][v1]=1;   //adding edge to min spanig tree
			sum=sum+min;
			t[++cn]=v2;
		i++;

	  }

	  clrscr();
	  for(i=1;i<=ver;i++)
	  {
		for(j=1;j<=ver;j++)
		{
		  cout<<" "<<edge[i][j];
		}
		cout<<endl;
	  }

	  cout<<"\nMinimum weight::"<<sum;

	  getch();

}

int present(int v,int *t,int cn)
{
  int i;
  for(i=1;i<=cn;i++)
  {
	if(t[i]==v)
	 return 1;
  }
  return 0;
}
