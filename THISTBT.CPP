#include<stdio.h>
#include<iostream.h>
#include<conio.h>
#include<ctype.h>
#include<stdlib.h>

class tbt
{
	//public :

	int data;
	tbt *lc;
	tbt *rc;
	int lt;
	int rt;
	int dir;
	public:
		void creat();
		void pre();
		void in();
		void post();
		tbt *postsucc(tbt *);
		tbt *presucc(tbt *);
};

void main()
{
	int ch,z;
	tbt *head;
  //	head=new tbt;
 /*	head->data=0;
	head->lc=head;
	head->rc=head;
	head->lt=1;
	head->rt=0;   */
	clrscr();
	do
	{
	cout<<"1]Creat\n"
		  "2]Preorder\n"
		  "3]Inorder\n"
		  "4]Postorder\n"
		  "5]Exit";
	cout<<"\nENTER YOUR CHOICE::";
	cin>>ch;

	switch(ch)
	{
		case 1:
			head->creat();
		break;
		case 2:
			head->pre();
		break;
		case 3:
			head->in();
		break;
		case 4:
			head->post();
		break;
		case 5:
			exit(0);
		break;
	}
	cout<<"\nCONTINUE TO MENU..::";
	cin>>z;
	}while(z==1);

return;
}

void tbt::creat()
{
	int z;
	char ch;
	tbt *p,*cur;
	this->lt=1;
	this->rt=0;
	this->rc=this;
	this->lc=this;
	this->data=0;

	do
	{
		p=new tbt;
		p->lc=NULL;
		p->rc=NULL;
		p->data=0;
		p->lt=1;
		p->rt=1;
		clrscr();
		cout<<"\nEnter Data for NODE::";
		cin>>p->data;

		if(this->lt==1)
		{

			this->lt=0;
			p->lc=this;
			p->rc=this;
			p->lt=1;
			p->rt=1;
			p->dir=0;
			this->lc=p;
		}
		else
		{
				cur=this->lc;
			while(1)
			{
				cout<<"\nENTER DIRECTION::";
				cin>>ch;


				if(tolower(ch)=='l')
				{
					if(cur->lt==1)
						break;
					cur=cur->lc;

				}
				if(tolower(ch)=='r')
				{
					if(cur->rt==1)
						break;
					cur=cur->rc;

				}
			}

		}

		if('l'==tolower(ch))
		{
			p->lc=cur->lc;
			p->rc=cur;
			p->lt=1;
			p->rt=1;
			p->dir=0;
			cur->lc=p;
			cur->lt=0;
		}
		if('r'==tolower(ch))
		{
			p->rc=cur->rc;
			p->lc=cur;
			p->lt=1;
			p->rt=1;
			p->dir=1;
			cur->rc=p;
			cur->rt=0;

		}


	 cout<<"\n\n ADD MORE..::";
	 cin>>z;
	}while(z==1);

}

void tbt::pre()
{
	tbt *curr,*p;

	curr=this->lc;

	while(curr!=this)
	{
		cout<<" "<<curr->data;
		curr=presucc(curr);
	}

}
tbt *tbt::presucc(tbt *curr)
{
	if(curr->lt==0)
		return(curr->lc);

	while(curr->rt==1 && curr!=this)
	{
		curr=curr->rc;
	}
	return(curr->rc);

}

void tbt::in()
{
	tbt *curr;
	curr=this->lc;

	while(curr!=this)
	{
		while(curr->lt==0)
			curr=curr->lc;

		cout<<" "<<curr->data;

		while(curr->rt==1 && curr->rc!=this)
		{
			curr=curr->rc;
		//	if(curr->data!=NULL)
			cout<<" "<<curr->data;
		}

		curr=curr->rc;
	}

}

void tbt::post()
{
	tbt *curr;

	curr=this->lc;

	while(curr->lt==0 || curr->rt==0)
	{
		if(curr->lt==0)
			curr=curr->lc;
		else
			curr=curr->rc;
	}

	while(curr!=this)
	{
		cout<<" "<<curr->data;
		curr=postsucc(curr);
	}

}

tbt *tbt::postsucc(tbt *curr)
{
	if(curr->dir==1)
	{
		while(curr->lt==0)
		{
			curr=curr->lc;
		}
		return(curr->lc);
	}
	else
	{

		while(curr->rt==0)
			curr=curr->rc;

		curr=curr->rc;

		if(curr->rt==1)
			return(curr->rc);
		else
		{
			if(curr==this)
			 return curr;
			curr=curr->rc;
			while(curr->lt==0 || curr->rt==0)
			{
				if(curr->lt==0)
					curr=curr->lc;
				else
					curr=curr->rc;
			}

		}

		return(curr);
	}
}











