#include<stdio.h>
#include<conio.h>
#include<string.h>
struct node
{
	int roll;
	char name[20];
	float per;
	//int per;
	struct node *link;
}a,*p,*q,*first;

int rect,m,ch,size;
int b=1,cn=0,rl,flag=0;
void main()
{
	FILE *fp,*ft;

	clrscr();

	fp=fopen("D:/other/aaaastud.DAT","wb+");
	size=sizeof(struct node);
do
{
		printf("****MENU****"
			"\n1.Creat"
			"\n2.Display Record"
			"\n3.Modify"
			"\n4.Search"
			"\n5.Delete");
	scanf("%d",&ch);
switch(ch)
{
	case 1:
		while(b==1)
		{
		p=(struct node *)malloc(sizeof(struct node));
	 //	p->link=NULL;
		cn++;
		printf("\nEnter\nRoll No.\nName\nPercentage\n");
		scanf("%d%s%f",&p->roll,p->name,&p->per);
			if(first==0)
			{
				first=p;
				p->link=NULL;
			}
			else
			{
				q=first;
				while(q->link!=NULL)
				{
					q=q->link;
				}
				q->link=p;
				p->link=NULL;

			  }

		printf("\nDo you want to add another record(1.y/2.n)");
		scanf("%d", &b);
		}

		fseek(fp,0,SEEK_END);
		p=first;
		while(p!=NULL)
		{
			fwrite(p,size,1,fp);
			p=p->link;
		}

		break;
	case 2:
		rewind(fp);
		p=first;
		while(fread(p,size,1,fp)>0)
		{
			 printf("\nNAME::%s",p->name);
			 printf("\nROLL NO.::%d",p->roll);
			printf("\nPERCENTAGE::%0.2f\n",p->per);
		}

		break;
	case 3:
			b=1;
		while(b==1)
		{
			printf("\nEnter Roll No. to modify the record:: ");
			scanf("%d",&rl);
			rewind(fp);
			p=first;
			while(fread(p,size,1,fp)>0)
			{
				flag=0;
				if(p->roll==rl)
				{
				flag=1;
				break;
				}
				p=p->link;
			}
			if(flag==1)
			{
				printf("Enter new record\nRoll No.\nName\npercentage:: ");
				scanf("%d %s %f",&p->roll,p->name,&p->per);
				fseek(fp,-size,SEEK_CUR);
				fwrite(p,size,1,fp);

			}
			else
			{
			printf("\nNOT found");

			}
		printf("\n\nDo you want to Modify another record(1.y/2.n)");
		scanf("%d", &b);
		}

		break;
	case 4:
			b=1;
		while(b==1)
		{

			printf("\nEnter Roll No. to Search the record:: ");
			scanf("%d",&rl);
			rewind(fp);
			p=first;
			while(fread(p,size,1,fp)>0)
			{
				if(p->roll==rl)
				{
				printf("\nRECORD FOUND...!");
				break;
				}
				else
				{
					printf("\nRECORD NOT FOUND...!");
				}
			}
		printf("\n\nDo you want to Search another record(1.y/2.n)");
		scanf("%d", &b);
		}

		break;
	case 5:
			rewind(fp);
		b=1;
		p=first;
		do
		{
			printf("\nEnter Roll No. to Delete the record:: ");
			scanf("%d",&rl);
			ft=fopen("temp.dat","wb+");
			while(fread(p,size,1,fp)==1)
			{
				if(p->roll!=rl)
				{
					fwrite(p,size,1,ft);
				}

			}
				p=first;
				fclose(fp);
				fclose(ft);
				remove("stud.dat");
				rename("temp.dat","stud.dat");
				fp=fopen("stud.dat","rb+");
				printf("\nRECORD DELETED");
				rewind(ft);
			printf("\n\nDo you want to Delete another record(1.y/2.n)");
			scanf("%d", &b);
		}while(b==1);
		break;



}
printf("\n\nDO YOU WANT TO CONTINUE....!");
scanf("%d", &m);
}while(m==1);

return;
}









float dhiraj()
{
	float x=7.2f;
	float *ptr=&x;
	(*ptr)++;
	x--;
	return x;

}