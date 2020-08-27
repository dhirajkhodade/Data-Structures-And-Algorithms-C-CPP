#include<iostream.h>
#include<fstream.h>
#include<string.h>
#include<conio.h>

struct hash
{
	int key;
	int chain;
	int vis;
};
class student
{
 public:
	char name[20];
	int roll_no;
	float per;
	student()
	{
	 strcpy(name,"");
	 per=111;
	 roll_no=1;
	}
	friend lwr;
};


class lwr
{
	student s;
	struct hash h[20];
	int n;
public:
	void init()
	{	cout<<"\n enter size of bucket:: ";
		cin>>n;
		for(int i=0;i<n;i++)
		{
			h[i].chain=-1;
			h[i].vis=0;
		}

	}
	void insert()
	{


		int x, flag=0;
		 cout<<"\n Enter the following details about the student";
		 cout<<"\n1:name:";
		 cin>>s.name;
		 cout<<"\n2:roll number:";
		 cin>>s.roll_no;
		 cout<<"\n3:percentage:";
		 cin>>s.per;
		 x=s.roll_no;

		int in,j=-1,i=0,temp=1;
		in=x%n;
		while(h[in].vis!=0 && i<n)
		{
			if((h[in].key%n)==(x%n))
			{
				j=in;
				temp=0;
			}
			in=(in+1)%n;
			i++;
		}
		if(temp==0)
			h[j].chain=in;
		h[in].key=x;
		h[in].vis=1;

		insert2(in,s);

	}
	void insert1()
	{

		int in,j=-1,i=0,temp=1,k;
		int x;
		int flag=0;
		 cout<<"\n Enter the following details about the student";
		 cout<<"\n1:name:";
		 cin>>s.name;
		 cout<<"\n2:roll number:";
		 cin>>s.roll_no;
		 cout<<"\n3:percentage:";
		 cin>>s.per;
		 x=s.roll_no;

		in=x%n;
		while(h[in].vis!=0 && i<n)
		{
			if((h[in].key%n)==(x%n))
			{
				j=in;
				temp=0;
			}
			if(in==(x%n) && (h[in].key%n)!=(x%n))
			{
				k=h[in].key;
				h[in].key=x;
				x=k;
				in=k-1;
				i=-1;
			}
			in=(in+1)%n;
			i++;
		}
		if(temp==0)
			h[j].chain=in;
		h[in].key=x;
		h[in].vis=1;

		insert2(in,s);

	}

	int search()
	{
		int rn,x;
		int flag=0;
		cout<<"\nEnter roll number you want to search for:";
		cin>>rn;
		x=rn;
		int in,i=0;
		in=x%n;
		while(h[in].vis!=0 && i<n && (h[in].key%n)!=(x%n))
		{
			in=(in+1)%n;
			i++;
		}
		if(i==n)
			return(-1);
		while(in!=-1)
		{
		     if(h[in].key==x)
			     return(in);
		     in=h[in].chain;
		}
	       return(-1);
	}
	void print()
	{
		for(int i=0;i<n;i++)
		{
			if(h[i].vis==1)
				cout<<"\n[ "<<h[i].key<<" | "<<h[i].chain<<" ]\t";
			else
				cout<<"\n[ --| "<<h[i].chain<<" ]\t";
		      display(i);
		      cout<<"\n";
		}
	}
	void insert2(int ,student);
	void display(int );
};
void main()
{
  clrscr();
	int z,l;
	lwr p;
	p.init();
	do
	{
	cout<<"\n \n 1:insert\n2:print\n3:search\n4:insert with replacement \nenter ur choice:: ";
	int ch,y;
	cin>>ch;
	switch(ch)
	{
		case 1:
		       p.init();
		       do
		       {

				p.insert();
				cout<<"\nwant to insert another key \n1:y|2:n:: ";
				cin>>z;

		       }while(z==1);
		       break;
	       case 2:
		      p.print();
		      break;
	       case 3:
		      do
		       {

				l=p.search();
				if(l==-1)
					cout<<"\n key not found \n";
				else
				       {
					cout<<"\n key found at location:: ";
					cout<<"\nIndex:"<<l;
					cout<<"\n\tROLL NO.\tNAME\tPERCENTAGE\n";
					p.display(l);
				       }

				cout<<"\nwant to search another key \n1:y|2:n:: ";
				cin>>z;

		       }while(z==1);
		       break;
		case 4:
		       p.init();
		       do
		       {

				p.insert1();
				cout<<"\nwant to insert another key \n1:y|2:n:: ";
				cin>>z;

		       }while(z==1);
		       break;


	}
	cout<<"\nwant to continue \n1:y|2:n:: ";
	cin>>z;
	}while(z==1);

  getch();

}




void lwr::insert2(int m,student s)
{
 fstream file;
// student s;
 char nam[20];
 file.open("hash.txt",ios::in|ios::out|ios::binary);
 if(!file)
 {
  cout<<"\nCannot open file hash.txt";
  return;
 }
 file.seekp(m*sizeof(student),ios::beg);
 file.write((char*)&s,sizeof(student));
 file.close();
}
void lwr::display(int m)
{
 student s;
 fstream file;
 file.open("hash.txt",ios::in|ios::out|ios::binary);
 if(!file)
 {
  cout<<"\nCannot open file hash.txt";
  return;
 }
 file.seekg(m*sizeof(student),ios::beg);
 file.read((char*)&s,sizeof(student));
 cout<<"\t"<<s.roll_no<<"\t\t"<<s.name<<"\t"<<s.per;
 file.close();
}