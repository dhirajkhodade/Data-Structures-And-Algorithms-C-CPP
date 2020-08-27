#include<stdio.h>
#include<conio.h>
void accept(int[],int);
void display(int[],int);
void bubble(int[],int);
void sel(int[],int);
void ins(int[],int);
void shell(int[],int);

void main()
{
	int set1[50],n,ch,d;
clrscr();
do
{
	printf("\n*****SORT MENU*****"
		   "\n1.Bubble sort"
		   "\n2.Selection sort"
		   "\n3.Insertion sort"
		   "\n4.Shell sort"
		   "\nENTER YOUR CHOICE::");

	scanf("%d",&ch);
switch(ch)
{
	case 1:
		printf("\nEnter limit of set::");
		scanf("%d",&n);
		accept(set1,n);
		printf("\nEntered elements of array are\n{");
		display(set1,n);
		printf("\nSORTED ARRAY IS\n{");
		bubble(set1,n);
		display(set1,n);
		break;
	case 2:
		printf("\nEnter limit of set::");
		scanf("%d",&n);
		accept(set1,n);
		printf("\nEntered elements of array are\n{");
		display(set1,n);
		printf("\nSORTED ARRAY IS\n{");
		sel(set1,n);
		display(set1,n);
		break;
	case 3:
		printf("\nEnter limit of set::");
		scanf("%d",&n);
		accept(set1,n);
		printf("\nEntered elements of array are\n{");
		display(set1,n);
		printf("\nSORTED ARRAY IS\n{");
		ins(set1,n);
		display(set1,n);
		break;
	case 4:
		printf("\nEnter limit of set::");
		scanf("%d",&n);
		accept(set1,n);
		printf("\nEntered elements of array are\n{");
		display(set1,n);
		printf("\nSORTED ARRAY IS\n{");
		shell(set1,n);
		display(set1,n);
		break;

}
printf("\nDo you want to continue..!");
scanf("%d",&d);
}while(d==1);

getch();
}

void accept(int set1[50],int n)
{
	int i,j,e;
	printf("\nEnter the elements\n");

	for(i=0;i<n;i++)
	{
		scanf("%d",&e);
		set1[i]=e;
	}

}

void display(int set1[50],int n)
{
	int i;

	for(i=0;i<n;i++)
	{
		printf("%d",set1[i]);
		if(i<n-1)
		{
			printf(",");
		}
	}
	printf("}");
}
void bubble(int set1[50],int n)
{
	int i,j,temp;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-i;j++)
		{
			if(set1[j]>set1[j+1])
			{
				temp=set1[j];
				set1[j]=set1[j+1];
				set1[j+1]=temp;
			}
		}
	}
}

void sel(int set1[50],int n)
{
	int i,j,k,temp;
	for(i=0;i<n;i++)
	{
		j=i;
		for(k=i+1;k<n;k++)
		{
			if(set1[k]<set1[j])
			{
				j=k;
			}

		}
				temp=set1[i];
				set1[i]=set1[j];
				set1[j]=temp;
	}

}

void ins(int a[],int n)
{
	int temp,i,j;
	for(i=1;i<n;i++)
	 {
	 temp=a[i];
		for(j=i-1;j>=0&&temp<a[j];j--)
			{
			  a[j+1]=a[j];
			}
		 a[j+1]=temp;
		}
}

void shell(int set1[50],int n)
{
 int gap,i,j,temp;
 for(gap=n/2;gap>0;gap=gap/2)
 {
   for(i=gap;i<n;i++)
   {
		temp=set1[i];

	   for(j=i;j>=gap;j=j-gap)
		if(temp<set1[j-gap])
			set1[j]=set1[j-gap];
		else
			break;
		set1[j]=temp;

   }

 }
}


