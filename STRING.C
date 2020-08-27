#include<stdio.h>
#include<conio.h>
#include<string.h>
void main()
{
char s1[20],s2[20],s3[20];
int m,n,len1,len2,c,c1,c2,a=0,b=0,d,i,j,k,s,count,temp;
clrscr();
do
{
	printf("****VARIOUS STRING OPERATION****"
		   "\n1.using library function"
		   "\n2.without using library function");
	printf("\n ENTER YOUR CHOICE ");
	scanf("%d",&c);
switch(c)
{
	do

	{
	case 1:
		printf("WITH USING LIBRARY FUNCTION");
		printf("\n1.length");
		printf("\n2.copy");
		printf("\n3.concat");
		printf("\n4.substring");
		printf("\n5.compare");
		printf("\n6.reverse");
		printf("\nENTER YOUR CHOICE: ");
		scanf("%d",&c1);
switch(c1)
{
	case 1:
		printf("\nenter the string ");
		scanf("%s",&s1);
		len1=strlen(s1);
		printf("The length of the string is:");
		printf("%d",len1);
		break;
	case 2:
		printf("\nenter the string ");
		scanf("%s",&s1);
		strcpy(s3,s1);
		printf("the copied string is: ");
		printf("%s",s3);
		break;
	case 3:
		printf("\nenter the 1st string ");
		scanf("%s",&s1);
		printf("enter the 2nd string ");
		scanf("%s",&s2);
		strcat(s1,s2);
		printf("\n %s",s1);
		break;
	case 4:
		printf("\n enter the 1st string ");
		scanf("%s",&s1);
		printf("\n enter the 2nd string ");
		scanf("%s",&s2);
		a=strstr(s1,s2);
		if (a==0)
		{
			printf("string is not substring");
		}
		else
		{
			printf("string is substring");
		}
		break;
	case 5:
		printf("\nenter the 1st string ");
		scanf("%s",&s1);
		printf("\nenter the second string ");
		scanf("%s",&s2);
		b=strcmp(s1,s2);
		if (b==0)
		{
			printf("strings are equal");
		}
		else
		{
			printf("strings are not equal");
		}
		break;
	case 6:
		printf("\n enter the string ");
		scanf("%s",&s1);
		strrev(s1);
		printf("reversed string is :");
		printf("%s",s1);
		break;
	default:
		printf("***INVALID CHOICE***");
		break;
}
printf("\ndo u want to continue");
scanf("%d", &m);
}while(m==1);
	break;
	case 2:
		printf("\nenter the 1st string: ");
		scanf("%s",s1);
		printf("\nenter the 2nd string: ");
		scanf("%s",s2);
		printf("\n WITHOUT USING LIBRARY FUNCYION ");
		printf("\n1.length");
		printf("\n2.copy");
		printf("\n3.concat");
		printf("\n4.substring");
		printf("\n5.compare");
		printf("\n6.reverse");
		printf("\n7.pelindrom");
		printf(" ENTER THE CHOICE :");
		scanf("%d", &c2);
switch(c2)
{
	case 1:
		i=0;
		while(s1[i]!='\0')
		{
		i++;
		}
		printf("length of the string is: %d",i);
		break;
	case 2:
		i=0;
		while(s1[i]!='\0')
		{
		s3[i]=s1[i];
		i++;
		}
		s3[i]='\0';
		printf("copy of the string is %s",s3);
		break;
	case 3:
		i=0;
		while(s1[i]!='\0')
		{
			i++;
		}
		j=0;
		while(s2[j]!='\0')
		{
		s1[i]=s2[j];
		i++;
		j++;
		}
		printf("concatination is %s",s1);
		break;
	case 4:
		while(s1[i]!='\0')
		{
			i++;
		}
		j=0;
		while(s2[j]!='\0')
		{
			j++;
		}
		count=0;
		if(i>j)
		{
			for(k=0;k<i;k++)
			{
				temp=1;
				if(s2[0]==s1[k])
				{
					for(s=0;s<j;s++)
					{
						if(s2[s]!=s1[k+s])
						{
							temp=0;
							break;
						}
					}

					if(temp==1)
					{
					count=count+1;
					}
				}
			}
			if(count!=0)
			{
				printf("substring is PRESENT");
			}
			else
			{
			printf("substring is NOT PRESENT");
			}
			break;

}
	break;

	case 5:
		if(s1[i]!='\0'&& s2[i]!='\0'&&s1[i]==s2[i])
		{
			i++;
		}
		if(s1[i]=='\0'&&s2[i]=='\0')
		{
			printf("\nstrings are equal");
		}
		else
		{
		printf("\nstrings are not equal");
		}
		break;
	case 6:
		i=0;
		while(s1[i]!='\0')
		{
		i++;
		}
		i--;
		k=i;
		for(j=0;j<=k;j++)
		{
			s3[j]=s1[i];
			i--;
		}
		s3[j]='\0';
		printf("revers of the string is %s",s3);
		break;
	case 7:
		i=0;
		while(s1[i]!='\0')
		{
		i++;
		}
		i--;
		k=i;
		for(j=0;j<=k;j++)
		{
			s3[j]=s1[i];
			i--;
		}
		s3[j]='\0';
		i=0;
		j=0;
		while(s1[i]!='\0'&& s3[j]!='\0'&&s1[i]==s3[j])
		{
			i++;
			j++;
		}
		if(s1[i]=='\0'&&s3[j]=='\0')
		{
		printf("given st	ring is palindrom");
		}
		else
		{
		printf("given string is not palindrom");
		}
		break;





}
}
printf("\n\ndo u want to conti.");
scanf("%d", &n);
}while(n==1);
getch();
}
