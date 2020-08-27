#include<conio.h>
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
struct poly
{
 int coeff;
 int exp;
 struct poly *link;
}*head1,*head2,*head,*head3,*head4,*p,*q,*r,*s,*n,*m;
struct poly *create(struct poly *);
void display(struct poly *);
void eva(struct poly *);
void add(struct poly *,struct poly *,struct poly *);
void multi(struct poly *,struct poly*,struct poly*);

void main()
{
 int g,m;
 clrscr();
 head1=(struct poly *)malloc(sizeof(struct poly));
 head1->coeff=9999;
 head1->exp=-1;
 head1->link=head1;
 head2=(struct poly *)malloc(sizeof(struct poly));
 head2->coeff=9999;
 head2->exp=-1;
 head2->link=head2;
 head3=(struct poly *)malloc(sizeof(struct poly));
 head3->coeff=9999;
 head3->exp=-1;
 head3->link=head3;


 do
 {
 printf("\n1.Create\n2.Display\n3.Add\n4.Multiply\n5.Evaluation");
 printf("\nENTER YOUR CHOICE::");
 scanf("%d",&m);
 switch(m)
 {
  case 1:
  printf("\nFOR FIRST polynomial:");
  head1=create(head1);
  printf("\nFOR SECOND polynomial:");
  head2=create(head2);

  break;
  case 2:
  printf("\nfirst polynomial is\n");
  display(head1);
  printf("\nsecond polynomial is\n");
  display(head2);

  break;
  case 3:

  add(head1,head2,head3);
  break;
  case 4:

  multi(head1,head2,head3);
  break;

  case 5:
  eva(head1);
  break;

 }
  printf("\nDo You Want to continue(1.y2.n)::");
  scanf("%d",&g);
}while(g==1);
 getch();
}
  struct poly *create(struct poly *head1)
  {
   int x,y,temp,c;
   do
   {
   p=(struct poly*)malloc(sizeof(struct poly));
   printf("enter the coefficient and exponent");
   scanf("%d%d",&x,&y);
   p->coeff=x;
   p->exp=y;

   if(head1->link==head1)
   {
	head1->link =p;
	p->link=head1;
   }
   else
   {
	temp=1;
	r=head1;
	q=head1->link;
	while(q!=head1)
	{
	  if(p->exp>q->exp)
	  {
	   temp=0;
	   break;
	  }
	 else
	 {
	 r=q;
	 q=q->link;
	 }
	}
	if(temp==0)
	{
	 r->link=p;
	 p->link=q;
	}
	else
	{
	 r->link=p;
	 p->link=head1;
	}
   }
   printf("\ndo you want to add more term(1.y/2.n)::");
   scanf("%d",&c);
  }while(c==1);
  return(head1);
}
 void display(struct poly *head4)
 {

  p=head4->link;
  while(p!=head4)
  {
   printf("(%dx^%d)",p->coeff,p->exp);
   if(p->link!=head4)
   {
	printf("+");
   }
   p=p->link;
  }
 }
  void eva(struct poly * n)
  {
   int x,a1,a2,sum=0;
   p=n;
   n=n->link;
   printf("\nenter the value of x:");
   scanf("%d",&x);
   while(n!=p)
   {
   a1=pow(x,n->exp);
   a2=n->coeff*a1;
   sum=sum+a2;
   n=n->link;
  }
  printf("\nthe value of polynomial is:%d",sum);
 }
  void add(struct poly *head1,struct poly *head2,struct poly *head3)
   {

   p=head1->link;
   q=head2->link;
   s=head3;
   while(p!=head1||q!=head2)
   {
	if(p->exp==q->exp)
	{
	 r=(struct poly*)malloc(sizeof(struct poly));
	 r->coeff=p->coeff+q->coeff;
	 r->exp=p->exp;
	 s->link=r;
	 r->link=head3;
	 p=p->link;
	 q=q->link;
	 s=s->link;
	 }
	 else
	 {
	  if(p->exp>q->exp)
	  {
	   r=(struct  poly*)malloc(sizeof(struct poly));
	   r->coeff=p->coeff;
	   r->exp=p->exp;
	   p=p->link;
	   s->link=r;
	   r->link=head3;
	   s=s->link;
	  }
	  else
	  {
	   r=(struct poly*)malloc(sizeof(struct poly));
	   r->coeff=q->coeff;
	   r->exp=q->exp;
	   q=q->link;
	   s->link=r;
	   r->link=head3;
	   s=s->link;
	  }
	 }
	}
	display(head3);
   }



 void multi(struct poly *head1,struct poly *head2,struct poly *head3)
{
 int temp,temp1;
 p=head1->link;
 q=head2->link;
 s=head3;

 while(p!=head1)
 {
  q=head2->link;
  while(q!=head2)
  {
   r=(struct poly*)malloc(sizeof(struct poly));
   s->link=r;
   r->coeff=p->coeff*q->coeff;
   r->exp=p->exp+q->exp;
	r->link=head3;
   q=q->link;
   //s=r;
   s=s->link;
  }
  p=p->link;
 }
 s=head3->link;
 while(s!=head3)
  {
   p=s->link;
   while(p!=head3)
   {
	q=p;
	n=p;
	if(s->exp==p->exp)
	{
	 n=n->link;
	 s->coeff=s->coeff+q->coeff;
	 s->exp=s->exp;
	 s->link=q->link;
	 free(q);
	 p=n;
	}
	p=p->link;
   }
   s=s->link;
  }
  s=head3->link;
  while(s!=head3)
  {
   p=s->link;
   while(p!=head3)
   {
	if(p->exp>s->exp)
	{
	 temp=s->exp;
	 temp1=s->coeff;
	 s->exp=p->exp;
	 s->coeff=p->coeff;
	 p->exp=temp;
	 p->coeff=temp1;
	}
	p=p->link;
   }
   s=s->link;
  }
 printf("\nmultiplication of the two polynomials is:");
 display(head3);
}