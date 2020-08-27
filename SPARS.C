#include<stdio.h>
#include<conio.h>
struct sparse
{
	int row;
	int col;
	int val;
}a[20],b[20],c[20];

void creat(struct sparse[]);
void display(struct sparse[]);
void sort(struct sparse[]);
void add(struct sparse[],struct sparse[],struct sparse[]);
void trans(struct sparse[],struct sparse[]);
void fast(struct sparse[],struct sparse[]);

void main()
{
	int ch,z;
	clrscr();
do
{
	printf("****MENU****\n1.Creat Sparse Matrix\n2.Add\n3.Trans");
	printf("\n\nEnter Your Choice");
	scanf("%d",&ch);

switch(ch)
{
case 1:
	printf("\nCreat 1st Sparse Matrix");
	creat(a);
	printf("\nCreat 2nd Sparse Matrix");
	creat(b);
	break;
case 2:
	printf("\nAddition is");
	add(a,b,c);
	break;
case 3:
	printf("\nTranspose is");
	trans(a,c);
	break;

}

printf("\nDO YOU WANT TO CONT..!");
scanf("%d",&z);
}while(z==1);

}

void creat(struct sparse a[])
{
	int i,j;
	printf("\nEnter total number of Rows");
	scanf("%d",&a[0].row);
	printf("\nEnter total number of Columns");
	scanf("%d",&a[0].col);
	printf("\nEnter total number of Values");
	scanf("%d",&a[0].val);

	for(i=1;i<=a[0].val;i++)
	{
		printf("\nEnter Row No.");
		scanf("%d",&a[i].row);
		printf("\nEnter Column No.");
		scanf("%d",&a[i].col);
		printf("\nEnter Value");
		scanf("%d",&a[i].val);
	}
	sort(a);
	display(a);

}

void display(struct sparse a[])
{
	int i,j;

	printf("\nRow\tCol\tVal\n");
	for(i=0;i<=a[0].val;i++)
	{
		printf("%d\t",a[i].row);
		printf("%d\t",a[i].col);
		printf("%d\n",a[i].val);
		if(i==0)
		{
			printf("\n");
		}
	}
}
void sort(struct sparse a[])
{
	int i,j,k,t1,t2,t3;
	for(i=1;i<=a[0].val;i++)
	{
	for(j=i+1;j<=a[0].val;j++)
	{
	if(a[i].row > a[j].row)
	{
		t1=a[i].row;
		t2=a[i].col;
		t3=a[i].val;
		a[i].row=a[j].row;
		a[i].col=a[j].col;
		a[i].val=a[j].val;
		a[j].row=t1;
		a[j].col=t2;
		a[j].val=t3;

	}
}
	}
}

void add(struct sparse a[],struct sparse b[],struct sparse c[])
{
	int i,j,k,m,n,l=0,temp;
	for(i=0;i<=a[0].val;i++)
	{
		c[i].row=a[i].row;
		c[i].col=a[i].col;
		c[i].val=a[i].val;
		l++;
	}

	for(i=1;i<=b[0].val;i++)
	{
		temp=1;
	for(j=1;j<=c[0].val;j++)
	{
		if(c[j].row==b[i].row && c[j].col==b[i].col)
		{
		c[j].val=c[j].val+b[i].val;
		temp=0;
		break;
		}


		}
		if(temp==1)
		{
		c[l].row=b[i].row;
		c[l].col=b[i].col;
		c[l].val=b[i].val;
		l++;
		}
	}
	c[0].val=l-1;
	sort(c);
	display(c);

}
void trans(struct sparse a[],struct sparse c[])
{
	int i;
	for(i=0;i<=a[0].val;i++)
	{
		c[i].row=a[i].col;
		c[i].col=a[i].row;
		c[i].val=a[i].val;
	}
	sort(c);
	display(c);
}
