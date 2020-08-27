#include<stdio.h>
#include<conio.h>
void accept(int[],int);
void display(int[],int);
void lin(int[],int,int);
void bin(int[],int,int);
int fibo(int [],int,int);
int fib(int);

void main()
{
	int ch,n,e,pos,nos[20],key,a[10],i,ans,p,q,mid,k;
	clrscr();
	do
	{
		printf("\n\t***** MENU *****");
		printf("\n1.LINEAR SEARCH");
		printf("\n2.BINARY SEARCH");
		printf("\n3.FABONACCI SEARCH");
		printf("\nENTER YOUR CHOICE : ");
		scanf("%d",&ch);
		printf("\n\n\t***** OUTPUT *****");
		switch(ch)
		{
			case 1:
			printf("\nENTER  NO. OF ELENMENTS :");
			scanf("%d",&n);
			printf("\nENTER  ELENMENTS:\n");
			accept(nos,n);
			display(nos,n);
			printf("\nENTER ELENMENTS TO BE SEARCHED :");
			scanf("%d",&e);
			lin(nos,n,e);
			break;

			case 2:
			printf("\nENTER  NO. OF ELENMENTS::");
			scanf("%d",&n);
			printf("\nENTER ELENMENTS:\n");
			accept(nos,n);
			display(nos,n);
			printf("\nENTER ELENMENTS TO BE SEARCHED:: ");
			scanf("%d",&e);
			bin(nos,n,e);
				break;


			case 3:
	 printf("\nEnter the limit::");
	 scanf("%d",&n);
	 printf("Enter the elements of array in Sorted Form::");
	 for(i=0;i<n;i++)
	 {
	   scanf("%d",&a[i]);
	 }
	 printf("Elements of array are::");

	 for(i=0;i<n;i++)
	  printf("\t %d",a[i]);

	 printf("\nEnter the number to be searched::");
	 scanf("%d",&key);
	 for(k=1;fib(k)<=n;k++)
	  ans=fibo(a,n,key);
  if(ans==-1)
   printf("\n\t%d IS NOT PRESENT IN LIST",key);
  else
  printf("\n\t%d IS FOUND AT %d LOCATION",a[ans],ans+1);

		}
		printf("\ndo you want to cont...");
	scanf("%d",&ch);

	}while(ch==1);
	getch();
}







void accept(int s[],int n)
{
	int i;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&s[i]);
	}
}

void display(int s[],int n)
{
	int i;
	for(i=1;i<=n;i++)
		printf("%d\t",s[i]);
}
void lin(int s[],int n,int e)
{
	int i,temp=0;
	for(i=1;i<=n;i++)
	{
		if(s[i]==e)
		{
			temp=1;
		}
	}
		if(temp==1)
			printf("/nELEMENT FOUND");
		else
			printf("/nELEMENT NOT FOUND");



}

void bin(int s[],int n,int e)
{
	int low,high,mid,temp=0,i,j;
	low = 0;
	high = n-1;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-i;j++)
		{
			if(s[j]>=s[j+1])
			{
				temp=s[j];
				s[j]=s[j+1];
				s[j+1]=temp;
			}
		}
	}
	display(s,n);
	temp=0;
	while(low<=high)
	{
		mid=(low+high)/2;
		if(s[mid]==e)
		{
			temp=1;
			break;
		}
		else
		{
			if(s[mid]>e)
			{
				high = mid-1;
			}
			else
			{
				low = mid+1;
			}
		}
	}

	if(temp==1)
		printf("\nELEMENT FOUND AT POS. %d",mid);
	else
		printf("\nNOT FOUND");


}

int fib(int n)
 {
  if(n==0) return(0);
  if(n==1) return(1);
  return(fib(n-1)+fib(n-2));

 }
 int fibo(int a[20],int n,int key)
 {
  int i=1,p=1,q=0;
  int temp;
  while(i+p<n+1)
   {
    temp=i+p;
    q=p;
    p=i;
    i=temp;
   }

  i=n+1-p;

  while(i!=0)
   {
    if(key<a[i])
     {
      if(q==0)
       return(-1);
      else
       {
	i=i-q;
	temp=p;
	p=q;
	q=temp-q;
	continue;
       }
     }

     if(key==a[i])
      return(i);

     if(key>a[i])
      {
       if(p==0)
	return(-1);
	else
	 {
	  i=i+q;
	  p=p-q;
	  q=q-p;
	 }
    }
 }
       return(-1);

}




