#include<stdio.h>
#include<conio.h>
#include<string.h>
struct stud
{
	int roll;
	char name[50];
	float per;
}e;

void main()
{
	FILE *fp,*ft;
	int rect,m,ch,size;
	int b=1,erl;
	char name[20];
	clrscr();

	fp=fopen("C:/aaaaaaaaaaaaaaaaaaaaaa.DAT","wb+");
	size=sizeof(e);
do
{
		printf("****MENU****"
			"\n1.Creat"
			"\n2.Display Record"
			"\n3.Modify"
			"\n4.Delete");
	scanf("%d",&ch);
switch(ch)
{
	case 1:
		fseek(fp,0,SEEK_END);
		while(b==1)
	{
		printf("\nEnter\nRoll No.\nName\nPercentage\n");
		scanf("%d%s%f",&e.roll,e.name,&e.per);
		fwrite(&e,size,1,fp);
		printf("\n\nDo you want to add another record(1.y/2.n)");
		scanf("%d", &b);
	}
		break;
	case 2:
				rewind(fp);
				while(fread(&e,size,1,fp)==1)
				{
				 printf("\nNAME::%s",e.name);
				 printf("\nROLL NO.::%d",e.roll);
				 printf("\nPERCENTAGE::%.2f\n",e.per);

				 }
				 getch();
		break;
	case 3:
			b=1;
		while(b==1)
		{
			printf("\nEnter Name No. to modify the record:: ");
			scanf("%s",name);
			rewind(fp);
			while(fread(&e, size,1,fp)==1)
			{
			if(strcmp(e.name,name)==0)
			{
				printf("Enter new record\nRoll No.\nName\npercentage:: ");
				scanf("%d %s %f",&e.roll,e.name,&e.per);
				fseek(fp,-size,SEEK_CUR);
				fwrite(&e,size,1,fp);
				break;
			}
			}
		printf("\n\nDo you want to Modify another record(1.y/2.n)");
		scanf("%d", &b);

		}
		break;
	case 4:
		rewind(fp);
				b=1;
		while(b==1)
		{
			printf("\nEnter Roll No. to Delete the record:: ");
			scanf("%d",&erl);
			ft=fopen("temp.dat","wb");
				if(e.roll!=erl)
				{
					fwrite(&e,size,1,ft);
				}
				fclose(fp);
				fclose(ft);
				remove("stud.DAT");
				rename("temp.dat","stud.dat");
				fp=fopen("stud.dat","rb+");
				printf("\nRECORD DELETED");
			printf("\n\nDo you want to Delete another record(1.y/2.n)");
		scanf("%d", &b);
		}
		break;



}
printf("\n\nDO YOU WANT TO CONTINUE....!");
scanf("%d", &m);
}while(m==1);


getch();
}

