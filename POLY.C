#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<math.h>
struct poly
{
int cf;
int ex;
}p1[20],p2[20],p3[20];

void creat(struct poly [],int);
void display(struct poly [],int);
void eval(struct poly [],int);
void add(struct poly [],struct poly [],struct poly [],int,int);
void multi(struct poly [],struct poly [],struct poly [],int,int);

void main()
{
int m1,m2,ch,a;
clrscr();
do
{
printf("*****MENU*****");
printf("\n1:Creat\n2:Add\n3:Evaluation\n4:Multiply");
printf("\nENTER YOUR CHOICE::");
scanf("%d",&ch);
switch(ch)
{
case 1:
	printf("\nEnter No. of terms for 1)::");
	scanf("%d",&m1);
	creat(p1,m1);
	display(p1,m1);
	printf("\nEnter No. of terms for 2)::");
	scanf("%d",&m2);
	creat(p2,m2);
	display(p2,m2);
	break;
case 2:
	add(p1,p2,p3,m1,m2);
	break;
case 3:
	eval(p1,m1);
	break;
case 4:
	multi(p1,p2,p3,m1,m2);
	break;



}
printf("\nDo you want to continue::");
scanf("%d",&a);
}while(a==1);

getch();
}

void creat(struct poly p1[],int m1)
{
int i,j;
for(i=0;i<m1;i++)
{
	printf("\nEnter coff.&exp.");
	scanf("%d %d",&p1[i].cf,&p1[i].ex);
}
}

void display(struct poly p1[],int m1)
{
int i,j,t1,t2;
for(i=0;i<m1;i++)
{
for(j=i+1;j<m1;j++)
{
	if(p1[i].ex < p1[j].ex)
	{
		t1=p1[i].ex;
		t2=p1[i].cf;
		p1[i].ex=p1[j].ex;
		p1[i].cf=p1[j].cf;
		p1[j].ex=t1;
		p1[j].cf=t2;

	}

}
}
for(i=0;i<m1;i++)
{
	if(p3[i].ex!=0 && p3[i].cf!=0)
	{
	printf("(%dX^%d)",p1[i].cf,p1[i].ex);
	if(i<m1-1 && p3[i+1].cf!=0)
	{
		printf("+");
	}
	}
	}
}

void eval(struct poly p1[],int m1)
{
	int i,j,x,a,sum=0;
	printf("\n     Enter the value of X::");
	scanf("%d",&x);
	for(i=0;i<m1;i++)
	{
		a=p1[i].cf *(pow(x,p1[i].ex));
		sum=sum+a;
	}
	printf("ANSWER::%d",sum);

}

void add(struct poly p1[],struct poly p2[],struct poly p3[],int m1,int m2)
{
	int i,j,l,t=0;
	for(i=0;i<m1;i++)
	{
		p3[i].cf=p1[i].cf;
		p3[i].ex=p1[i].ex;

	}
	l=i;


for(j=0;j<m2;j++)
{
t=0;
for(i=0;i<m1;i++)
{
	if(p3[i].ex==p2[j].ex)
	{
		t=1;
		p3[i].cf=p3[i].cf+p2[j].cf;
		p3[i].ex=p3[i].ex;
		break;
	}
		}
		if(t==0)
		{
		p3[l].ex=p2[j].ex;
		p3[l].cf=p2[j].cf;
		l++;
		}


	}

display(p3,l);
}

void multi(struct poly p1[],struct poly p2[],struct poly p3[],int m1,int m2)
{
	int i,j,k=0,l=0,n=0;


	for(i=0;i<m1;i++)
	{
		for(j=0;j<m2;j++)
		{
		p3[k].cf = p1[i].cf * p2[j].cf;
		p3[k].ex = p1[i].ex + p2[j].ex;
		k++;
		}

	}

display(p3,k);
printf("\n SIMPLIFIED ANSWER IS");

for(i=0;i<k;i++)
{

	for(j=i+1;j<k;j++)
	{

	if(p3[i].ex==p3[j].ex)
	{

		p3[i].cf=p3[i].cf+p3[j].cf;
		p3[j].cf=0;
		p3[j].ex=0;

	/*  for(l=j;l<k;l++)
	{
		p3[l].ex=p3[l+1].ex;
		p3[l].cf=p3[l+1].cf;

	}
	 k--;  */

	}

}
}

   /*	if(p3[k-1].ex==p3[k-2].ex)
	{
		p3[k-2].cf=p3[k-1].cf+p3[k-2].cf;
		k--;
	} */

display(p3,k);

}