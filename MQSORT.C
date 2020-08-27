#include<stdio.h>
#include<conio.h>
void accept(int[],int);
void display(int[],int);
void merges(int[],int,int);
void merge(int[],int,int,int);
void quick(int[],int,int,int);
void exchange(int[],int,int);

void main()
{
	int set1[50],n,ch,d,left,right,lo,hi;
clrscr();
do
{
	printf("\n*****SORT MENU*****"
		   "\n1.Merge sort"
		   "\n2.Quick sort"
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
		lo=0;
		hi=n-1;
		merges(set1,lo,hi);
		display(set1,n);
		break;
		case 2:
		printf("\nEnter limit of set::");
		scanf("%d",&n);
		accept(set1,n);
		printf("\nEntered elements of array are\n{");
		display(set1,n);
		printf("\nSORTED ARRAY IS\n{");
					left=0;
		right=n-1;
		quick(set1,left,right,n);
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




void merges(int a[],int lo,int hi)
{
int m;
 if(lo<hi)
 {
 m=((lo+hi)/2);
 merges(a,lo,m);
 merges(a,m+1,hi);
 merge(a,lo,m,hi);
}

}
void merge(int a[],int lo,int m,int hi)
 {
  int h,j,i,k,b[20];
  h=lo;i=lo;j=m+1;
  while((h<=m)&&(j<=hi))
  {
	 if(a[h]<=a[j])
	 {
		b[i]=a[h];
		h=h+1;
	  }
	  else
	  {
		 b[i]=a[j];
		 j=j+1;
	   }
	i=i+1;
   }
   if(h>m)
   {
	  for(k=j;k<=hi;k++)
		{
		 b[i]=a[k];
		 i=i+1;
		}
   }
   else

	for(k=h;k<=m;k++)
	{
	 b[i]=a[k];
	 i=i+1;
	}

	for(k=lo;k<=hi;k++)
	{
	a[k]=b[k];
	}


}

void quick(int c[],int left,int right,int n1)
{
int i,j,pivot;
i=left;
j=(right+1);
pivot=c[left];
 if(left<right)
 {
   do
   {
	do
	  {
	  i++;
	  }while((c[i]<pivot)&&(i<right));
	do
	 {
	  j--;
	 }while((c[j]>pivot)&&(j>=0));
	  if(i<j)
		exchange(c,i,j);
   }while(i<j);
	 exchange(c,left,j);
	 quick(c,left,j-1,n1);
	 quick(c,j+1,right,n1);
 }

}

void exchange(int c[],int i,int j)
{
 int temp;
 temp=c[i];
 c[i]=c[j];
 c[j]=temp;
}

