#include<iostream.h>
#include<conio.h>
#include<ctype.h>
#include<stdlib.h>
class tree
{
	public:

	int data;
	tree *lc;
	tree *rc;

	void creat();
	void r_pre(tree *);
	void r_in(tree *);
	void r_post(tree *);
	void wr_pre(tree *);
	void wr_in(tree *);
	void wr_post(tree *);

}*root;

	tree obj;

void main()
{
	int ch,z;

	clrscr();
	do
	{
	clrscr();
	cout<<"*****MENU*****\n"
		  "1]CREAT\\ADD NODES\n";
	cout<<"A]With Recurtion\n"
		  "		2.Preorder\n"
		  "		3.Inorder\n"
		  "		4.postorder\n"
		  "B]Without Recurtion\n"
		  "		5.Preorder\n"
		  "		6.Inorder\n"
		  "		7.postorder\n"
		  "8. EXIT"
		  "ENTER YOUR CHOICE::";
	cin>>ch;
	switch(ch)
	{
		case 1:
			root=NULL;
			obj.creat();
		break;
		case 2:
			cout<<"PREORDER IS::";
			obj.r_pre(root);
		break;
		case 3:
			cout<<"INORDER IS::";
			obj.r_in(root);
		break;
		case 4:
			cout<<"POSTORDER IS::";
			obj.r_post(root);
		break;
		case 5:
			cout<<"PREORDER IS::";
			obj.wr_pre(root);
		break;
		case 6:
			cout<<"INORDER IS::";
			obj.wr_in(root);
		break;
		case 7:
			cout<<"POSTORDER IS::";
			obj.wr_post(root);
		break;
		case 8:
			exit(0);
		break;

	}


	cout<<"\n\nCONT. TO MAIN MENU...!";
	cin>>z;
	}while(z==1);

//getch();
}

void tree:: creat()
{
	tree *cur,*p,*q;
	int ch1;
	char ans;
	do
	{
		p=new tree;
		cur=root;
		clrscr();
		cout<<"\nEnter DATA For Node:: ";
		cin>>p->data;
		p->lc=NULL;
		p->rc=NULL;

		if(root==NULL)
		{
			root=p;
		}
		else
		{
			cur=root;
			while(cur!=NULL)
			{
				cout<<"\nWhere Do You Want To Enter ( l \\ r ) :: ";
				cin>>ans;
				if('l'==tolower(ans))
				{
					q=cur;
					cur=cur->lc;
				}
				else
				{
					q=cur;
					cur=cur->rc;
				}

			}

		if(ans=='l')
		{
			q->lc=p;
		}
		else
		{
			q->rc=p;
		}

	}
	cout<<"ADD MORE...! :: ";
	cin>>ch1;
	}while(ch1==1);

}

void tree::r_pre(tree *cur)
{

	if(cur!=NULL)
	{
		cout<<"\t"<<cur->data;
		obj.r_pre(cur->lc);
		obj.r_pre(cur->rc);
	}
}

void tree::r_in(tree *cur)
{

	if(cur!=NULL)
	{
		obj.r_in(cur->lc);
		cout<<"\t"<<cur->data;
		obj.r_in(cur->rc);
	}
}

void tree::r_post(tree *cur)
{

	if(cur!=NULL)
	{
		obj.r_post(cur->lc);
		obj.r_post(cur->rc);
		cout<<"\t"<<cur->data;
	}
}

//WITHOUT RECURTION

void tree::wr_pre(tree *cur)
{

	if(cur!=NULL)
	{
		cout<<"\t"<<cur->data;
		obj.r_pre(cur->lc);
		obj.r_pre(cur->rc);
	}
}

void tree::wr_in(tree *cur)
{

	if(cur!=NULL)
	{
		obj.r_in(cur->lc);
		cout<<"\t"<<cur->data;
		obj.r_in(cur->rc);
	}
}

void tree::wr_post(tree *cur)
{

	if(cur!=NULL)
	{
		obj.r_post(cur->lc);
		obj.r_post(cur->rc);
		cout<<"\t"<<cur->data;
	}
}

