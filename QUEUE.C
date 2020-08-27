#include<stdio.h>
#include<conio.h>
struct node
{
	int data;
	struct node *link;
}*p,*q,*first,*head;
struct node *creat();
void display();
void del();

int ch,x,z,y;
void main()
{
	do
	{
	printf("*****MENU*****\n1.Creat\n2.Display\n3.Delete");
	printf("\nENTER YOUR CHOICE::");
	scanf("%d",&ch);
switch(ch)
	{
	case 1:
	   head=creat();
		break;
	case 2:
		display(head);
		break;
	case 3:
		del(head);
		break;
	}
	printf("\nDo You Want To Continue::");
	scanf("%d",&z);
	}while(z==1);
	return;
}

struct node *creat()
{
	do
	{
	printf("\nEnter data for node");
	scanf("%d",&x);
	p=(struct node *)malloc(sizeof(struct node));
	if(first==0)
	{
		p->data=x;
		p->link=p;
		first=p;
	}
	else
	{   q=first;
		while(q->link!=first)
		{
			q=q->link;
		}
		p->data=x;
		q->link=p;
		p->link=first;
	 }
	 printf("\nDo you want to add more...");
	 scanf("%d",&y);
	 }while(y==1);
	return(first);
}
void display(struct node *first)
{
	p=first;
	printf("\nEntered queue is as follows\n");
	do
	{
		printf("%d ",p->data);
		p=p->link;
	}while(p!=first);
return;
}
void del(struct node *head)
{
	q=head;
	while(q->link!=head)
	{
		q=q->link;
	}

	while(head->link!=head)
	{
		p=head;
		head=head->link;
		free(p);
		q->link=head;
	}
	free(head);
printf("\nQueue DELETED Successfully");
}