#include<stdio.h>
#include<conio.h>
void creat(int *,int,int);
void display(int *,int,int);
void add(int *,int *,int *,int,int);
void mult(int *,int *,int *,int,int,int,int);
void trans(int *,int *,int,int);
void sadd(int *,int,int);

void main()
{
	int a[20][20],b[20][20],c[20][20],d,m,n,p,q,ch;
	clrscr();
	flushall();

do
{
	printf("\n****MENU****"
			"\n1.Creat"
			"\n2.Add"
			"\n3.Multiply"
			"\n4.Transpose"
			"\n5.Saddle");
	printf("\nEnter your choice::");
	scanf("%d",&ch);
switch(ch)
{
	case 1:
		printf("\nEnter number of Rows and Colums for MAT A::");
		scanf("%d%d",&m,&n);
		creat(a,m,n);
		printf("\nEnter number of Rows and Colums for MAT B::");
		scanf("%d%d",&p,&q);
		creat(b,p,q);
		break;
	case 2:
		add(a,b,c,m,n);
		break;
	case 3:
		if(n==p)
		mult(a,b,c,m,n,p,q);
		else
		printf("Invalid Matrix dimentions for multiplication...!");
		break;
	case 4:
		trans(a,c,m,n);
		break;
	case 5:
	flushall();
		sadd(a,m,n);
		break;
}
printf("\nDo you want to continue..!");
scanf("%d",&d);
}while(d==1);

getch();
}

void creat(int *a,int m,int n)
{
	int i,j;
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("\nEnter [%d][%d] Element::",i,j);
			scanf("%d",&(*(a+i*n+j)));
		}

	}
	display(a,m,n);
}
void display(int *a,int m,int n)
{
	int i,j;
	printf("\nMatrix is");
	for(i=0;i<m;i++)
	{
		printf("\n");
		for(j=0;j<n;j++)
		{
			printf("\t%d",*(a+i*n+j));
		}

	}
}
void add(int *a,int *b,int *c,int m,int n)
{
	int i,j;
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			*(c+i*n+j)=*(a+i*n+j) + *(b+i*n+j);
		}
	}
	display(c,m,n);
}
void mult(int *a,int *b,int *c,int m,int n,int p,int q)
{
	int i,j,k;
	for(i=0;i<m;i++)
	{
		for(j=0;j<q;j++)
		{
			*(c+((i*q)+j))=0;
			for(k=0;k<n;k++)
			{
				*(c+((i*q)+j))=*(c+((i*q)+j)) + (*(a+((i*n)+k)) * *(b+((k*q)+j)));
			}
		}
	}
	display(c,m,q);
}
void trans(int *a,int *c,int m,int n)
{
	int i,j;
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			*(c+n*j+i)= *(a+n*i+j);
		}
	}
	display(c,n,m);

}
void sadd(int *a,int m,int n)
{
	int min[10],max[10],mn,mx,i,j=0,k,mir=0,mac=0;
	for(i=0;i<m;i++)
	{
		mx=*(a+i*n+j);
		for(j=1;j<n;j++)
		{
			if( mx < *(a+i*n+j) )
			{
				mx= *(a+i*n+j);
			}
		}
		max[i]=mx;
		j=0;
	}

	i=0;

	for(j=0;j<n;j++)
	{
		mn=*(a+i*m+j);
		for(i=1;i<m;i++)
		{
			if( mn > *(a+i*m+j) )
			{
				mn= *(a+i*m+j);
			}
		}
		min[j]=mn;
		i=0;
	}

	i=0;

		mir=max[i];
		for(i=1;i<n;i++)
		{
		   if(mir > max[i])
		   {
				mir=max[i];
		   }

		}

		i=0;
		mac=min[i];
		for(i=1;i<n;i++)
		{
		   if(mac < min[i])
		   {
				mac=min[i];
		   }

		}

		if(mir==mac)
		{
			printf("\nSaddle point is PRESENT");
		}
		else
		{
			printf("\nSaddle point is NOT present ");
		}


}
