#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct node
{
  int data;
  struct node *link;
}*first,*p,*q;

struct node creat();
struct node display();
struct node insert();
struct node del();
struct node search();
struct node rev();

int x,y,temp,cn,ch,ans;

void main()
{

   clrscr();
 do
 {
      printf("\n********MENU********\n1.creat\n2.display\n3.insert\n4.delete"\
	     " \n5.search\n6.reverse\nENTER YOUR CHOICE...! ::");
      scanf("%d",&ch);

     switch(ch)
	{
	     case 1:
		creat();
		break;
	     case 2:
		display:
		display();
		break;
	     case 3:
		insert();
		break;
	     case 4:
		del();
		break;
	     case 5:
		search();
		break;
	     case 6:
		rev();
		break;
     }
      printf("\nDo you want to continue(1.y/2.n)");
      scanf("%d",&ans);
   }while(ans==1);

}

//functions

struct node creat()
{
p=malloc(sizeof(struct node));
		printf("\nEnter data of node");
		scanf("%d",&x);
		p->data=x;
		p->link=NULL;
		first=p;
}

struct node display()
{
	printf("\n");
	p=first;
	while(p!=NULL)
	{
		printf("%d ",p->data);
		p=p->link;
	}
}
struct node insert()
{
do
{
	printf("\n1.Insert in begining\n2.Insert at end\n"
		"3.Insert in middle\n"
		"ENTER YOUR CHOICE ::");
	scanf("%d",&ch);

	switch(ch)
	{
	case 1:
		q=malloc(sizeof(struct node));
		printf("\nEnter number for node::");
		flushall();
		scanf("%d",&x);
		q->data=x;
		q->link=first;
		first=q;
	break;
	case 2:
		q=malloc(sizeof(struct node));
		printf("\nEnter number for node::");
		scanf("%d",&x);
		q->data=x;
		p=first;
		while(p->link!=NULL)
		{
			p=p->link;
		}
			p->link=q;
			q->link=NULL;
	break;
	case 3:
		q=malloc(sizeof(struct node));
		printf("\nEnter number for node::");
		scanf("%d",&x);
		printf("\nAfter which node(DATA) do you"
			"want to add this one::");
		scanf("%d",&y);
		q->data=x;
		p=first;
		while(p->data!=y && p->link!=NULL)
		{
			p=p->link;
		}
		if(p->data==y)
		{
			q->link=p->link;
			p->link=q;
		}
		else
		{
			printf("\nThis node is not present");
		}
	break;
	}
	printf("\nDo you want to insert more node(1.y/2.n)");
	scanf("%d",&ans);
}while(ans==1);
}

struct node del()
{
	printf("\nEnter data you want to delete::");
	scanf("%d",&y);
	p=first;
	if(p->data==y)
	{
		first=p->link;
		free(p);
		printf("\nData deleted succsesfuly");
	}
	  else
	  {
		while(p->link!=NULL)
		{
			if(p->link->data==y)
			{
			    q=p->link;
			    p->link=p->link->link;
			    free(q);
			    printf("\nData deleted succsesfuly");
			    temp=1;
			    break;
			}
			p=p->link;
		}
		if(temp!=1)
		{
			printf("\nData not present in list");
		}
	  }
}
struct node search()
{
	cn=1;
	printf("\nEnter Node Data which you want to search::");
	scanf("%d",&y);
	p=first;
	while(p->data!=y && p!=NULL)
	{
		p=p->link;
		cn++;
	}
	if(p->data==y)
	{
		printf("\nData found in %d node",cn);
	}
	else
	{
		printf("\nData not present in list");
	}
}
struct node rev()
{
	p=first;
	   while(p->link!=NULL)
	   {
		 q=p->link;
		 p->link=p->link->link;
		 q->link=first;
		 first=q;
	   }
	   printf("\nLinklist Reversed successfully");
	   display();
}