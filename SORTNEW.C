#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct node
{
  int data;
  struct node *link;
}*first1,*p1,*q1,*l1,*l2,*l3,*l,*first2,*first;


struct node *creat();
struct node *creatun();
void display(struct node *);
struct node *merge(/*struct node *,struct node *,struct node * */);
void sort(struct node *);

int x,y,z,temp=0,ch,ans;

void main()
{

   clrscr();
 do
 {
      printf("\n********MENU********\n1.Creat\n2.Display\n3.Merge\nENTER YOUR CHOICE...! ::");
      scanf("%d",&ch);

     switch(ch)
	{
	     case 1:
	     do
	     {
		printf("FOR FIRST LINK LIST(sort while creation)");
		l1=creat();
		printf("\nDo you want to add more...");
		scanf("%d",&z);
	     }while(z==1);

		printf("FOR SECOND LINK LIST(unsorted)");
		l2=creatun();
		printf("\nUnsorted list is");
		display(l2);
		sort(l2);
		break;
	     case 2:
		display(l1);
		printf("\nsorted list is::");
		display(l2);
		break;
	     case 3:
		l3=merge(l1,l2);
		display(l3);
		break;
	  }
      printf("\nDo you want to continue(1.y/2.n)");
      scanf("%d",&ans);
}while(ans==1);

}

	//functions

struct node *creat()
{
	p1=malloc(sizeof(struct node));
		printf("\nEnter data of node");
		flushall();
		scanf("%d",&x);
	       //	first1=NULL;
		q1=NULL;

	if(first==0)
	 {
		p1->data=x;
		p1->link=q1;
		first=p1;
	 }
	 else
	 {
		q1=first;
		if(q1->data > x )
		{
			p1->data=x;
			p1->link=q1;
			first=p1;

		}
		if(q1->data < x)
		{

		while(x > q1->link->data && q1->link->data!=NULL)
		   {
			q1=q1->link;
		   }
			p1->data=x;
			p1->link=q1->link;
			q1->link=p1;
		}
	 }
return(first);
}

void display(struct node *first)
{
	printf("\n");
	p1=first;
	while(p1!=NULL)
	{
		printf("%d ",p1->data);
		p1=p1->link;
	}

}

struct node *merge(struct node *l1,struct node *l2)
{
l=NULL;
	while(l1!=NULL && l2!=NULL)
       { if(l1->data < l2->data)
	   { if(l==NULL)
	      { l=p1=l1;
		l1=l1->link;
	      }
	     else
	      { p1->link=l1;
		l1=l1->link;
		p1=p1->link;
	      }
	   }
	 else
	   { if(l==NULL)
	      { l=p1=l2;
		l2=l2->link;
	      }
	     else
	      { p1->link=l2;
		l2=l2->link;
		p1=p1->link;
	      }
	   }
      }
      if(l1!=NULL)
       { if(l==NULL)
	   l=l1;
	 else
	   p1->link=l1;
       }
      if(l2!=NULL)
       { if(l==NULL)
	   l=l2;
	 else
	   p1->link=l2;
       }
    return(l);

/*	q1=first1;
	r1=q1->link;
while(first2!=NULL || r1->link!=NULL)
{
	while(r1->link!=NULL)
	{
		p1=first2;
		if(p1->data >= q1->data&&p1->data <= r1->data)
		{
			first2=first2->link;
			q1->link=p1;
			p1->link=r1;
			r1=p1;
		}
		else
		{
			q1=q1->link;
			r1=r1->link;
		}
	}
	if(r1->link==NULL)
	{
		r1->link=p1;
		first2=first2->link;
		p1->link=NULL;
	}
}
return(first1); */
}

struct node *creatun(struct node *first2)
{
first2=NULL;
	do{
	if(first2==NULL)
	{
	p1=malloc(sizeof(struct node));
		printf("\nEnter data of node");
		scanf("%d",&x);
		p1->data=x;
		p1->link=NULL;
		first2=p1;
	 }
	q1=malloc(sizeof(struct node));
		printf("\nEnter data of node::");
		scanf("%d",&x);
		q1->data=x;
		p1=first2;
		while(p1->link!=NULL)
		{
			p1=p1->link;
		}
			p1->link=q1;
			q1->link=NULL;
	printf("\n Do you want to  add more...");
	scanf("%d",&y);
	   }while(y==1);
 return(first2);
}
void sort(struct node *first)
  { int i,j,n,temp;
       for(n=0,p1=first;p1!=NULL;p1=p1->link)
       {
       n++;
       }
    for(i=1;i<n;i++)
     {p1=first;
      for(j=0;j<n-i;j++)
       {if(p1->data > p1->link->data)
	  { temp=p1->data;
	    p1->data=p1->link->data;
	    p1->link->data=temp;
	  }
	p1=p1->link;
       }
      }
}


