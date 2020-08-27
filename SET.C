#include<stdio.h>
#include<conio.h>
void display(int [],int);
void search(int [],int);
void uni(int[],int[],int,int);
void inter(int[],int[],int,int);
void diff(int[],int[],int,int);

void main()
{
	int set1[50],set2[50],i,j,c,k,l,l1,e,f,p,temp;
clrscr();
	printf("\nenter the limit of the set A :: ");
	scanf("%d",&l);

		temp=1;
	for(i=0;i<l;i++)
		{  temp=1;
		printf("\nenter the elements");
		scanf("%d",&e);
			for(j=0;j<i;j++)
				{
					if(set1[j]==e)
					{
					temp=0;
					printf("\nelement is already present");
					i--;
					break;
					}
				}
				if(temp==1)
				{
				set1[i]=e;
				}
		}

printf("\nenter the limit of the set B :: ");
	scanf("%d",&l1);

		temp=1;
for(i=0;i<l1;i++)
		{  temp=1;
		printf("\nenter the elements");
		scanf("%d",&f);
			for(j=0;j<i;j++)
				{
					if(set2[j]==f)
					{
					temp=0;
					printf("\nelement is already present");
					i--;
					break;
					}
				}
				if(temp==1)
				{
				set2[i]=f;
				}
}
do
{
		printf("\n****MENU****");
		printf("\n1.Display"
			   "\n2.Search"
			   "\n3.Union"
			   "\n4.Intersection"
			   "\n5.Difference"
			   "\n\nENTER YOUR CHOICE:: ");
		scanf("%d",&c);
switch(c)
{
		case 1:
		   printf("\nA=");
		   display(set1,l);
		   printf("\nB=");
		   display(set2,l1);
			break;
		case 2:
			search(set1,l);
			printf("A");
			search(set2,l1);
			printf("B");
			break;
		case 3:
			uni(set1,set2,l,l1);
			break;
		case 4:
			inter(set1,set2,l,l1);
			break;
		case 5:
			diff(set1,set2,l,l1);
			break;
}
printf("\nDO YOU WANT TO CONTINUE...!\n(1.YES)::");
flushall();
scanf("%d",&p);
}while(p=='1');
getch();
}

void display(int arr[],int n )
{
   int k;
   printf("{");
   for(k=0;k<n;k++)
   {
	printf("%d",arr[k]);
	if(k<n-1)
	{
		printf(",");
	}
   }
   printf("}");

}

void search(int arr[],int n)
{
	int x,y,temp=1;
	printf("\nEnter the element to search:: ");
	scanf("%d",&x);
	for(y=0;y<n;y++)
	{
	  if(arr[y]==x)
	  {
		temp=0;
		break;
	  }
	  else
	   temp=1;
	}
	if(temp==0)
		printf("\nELEMENT IS PRESENT IN SET");
	else
		printf("\nELEMENT IS NOT PRESENT");
}
void uni(int set1[],int set2[],int l,int l1)
{
	int i,j,k=0,set3[50],temp;

		for(i=0;i<l1;i++)
		{
			temp=1;
			for(j=0;j<l;j++)
			{
				if(set1[j]==set2[i])
				{
					temp=0;
					break;
				}
			}

			if(temp==1)
			{
			set3[k]=set2[i];
			k++;
			}

		}
		for(i=0;i<l;i++)
		{
			set3[k]=set1[i];
			k++;
		}

		printf("Union is ={");
	   for(i=0;i<k;i++)
		{
			printf("%d",set3[i]);
				if(i<k-1)
					{
					printf(",");
					}
		 }
		 printf("}");

}
void inter(int set1[],int set2[],int l,int l1)
{
	int i,j,k=0,set3[50],temp;

		for(i=0;i<l1;i++)
		{
			temp=1;
			for(j=0;j<l;j++)
			{
				if(set1[j]==set2[i])
				{
					temp=0;
					break;
				}
			}

			if(temp==0)
			{
			set3[k]=set2[i];
			k++;
			}

		}

		printf("Intersection is ={");
	   for(i=0;i<k;i++)
		{
			printf("%d",set3[i]);
				if(i<k-1)
					{
					printf(",");
					}
		 }
		 printf("}");

}
void diff(int set1[],int set2[],int l,int l1)
{
	int i,j,k=0,set3[50],temp;

		for(i=0;i<l;i++)
		{

			for(j=0;j<l1;j++)
			{
				temp=1;
				if(set2[j]==set1[i])
				{
					temp=0;
					break;
				}
			}

			if(temp==1)
			{
			set3[k]=set1[i];
			k++;
			}

		}
	   printf("Difference A-B is ={");
	   for(i=0;i<k;i++)
		{
			printf("%d",set3[i]);
				if(i<k-1)
					{
					printf(",");
					}
		 }
		 printf("}");

}





