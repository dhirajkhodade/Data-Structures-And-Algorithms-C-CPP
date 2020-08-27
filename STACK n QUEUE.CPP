#include<iostream.h>
#include<conio.h>
#include<stdlib.h>



class stack
   {
	int data;
	stack *up;
	static stack*top;

	public:
			 stack()
				  {
				   up=NULL;
				  }
			 void push(int x);
			 int pop();
			 int empty();
   };


class queue
	{
		int data;
		queue *left;
		static queue*front,*rear;

		public:
			  queue()
				 {
				  left=NULL;
				 }
			  void enq(int x);
			  int deq();
			  int empty();
	};



queue* queue::rear;
queue* queue::front;
stack* stack::top;



int queue::empty()
  {
   if (front==NULL)
		return 1;
	 return 0;
  }



void queue::enq(int x)
  {
	queue*p;
	if(empty())
		 rear=front=new queue;
	else
		{
		  rear->left=new queue;
		  rear=rear->left;
		}
	  rear->left=NULL;
	  rear->data=x;
  }



int queue::deq()
  {
	queue*p;
	int x;
	if(!empty())
		 {
			x=front->data;
			p=front->left;
			delete front;
			front=p;
		 }
	else
		 {
		   cout<<" Queue is empty";
		   front=NULL;
		   x=0;
		 }
	 return x;
  }



int stack::empty()
  {
   if(top==NULL)
	  return 1;
	return 0;
  }


void stack::push(int x)
   {
	stack*p;
	if(empty())
	  {
	   top=new stack;
	   top->up=NULL;
	  }
	else
	  {
	   p=new stack;
	   p->up=top;
	   top=p;
	  }
	top->data=x;
   }


int stack::pop()
   {
	 stack*p;
	 int x;
	 if(!empty())
	  {
	   x=top->data;
	   p=top;
	   top=top->up;
	   delete p;
	  }
	 else
	  {
	   cout<<"Stack is empty";
	   x=0;
	  }
	 return x;
   }



int main()
	{
	  stack c1;
	  queue c2;
	  int i;
	  char ch;
	  clrscr();
	  while(1)
	   {
		cout<<"\n\t\t Stack and Queue operation";
		cout<<"\n1.Push\n2.Pop\n3.Enqueue\n4.Dequeue\n5.Exit";
		cout<<"\nEnter your choice=";
		cin>>i;

		switch(i)
			{
			 case 1:
					cout<<"\n Enter no. you want to push in to Stack=>";
					cin>>i;
					c1.push(i);
				 break;
			 case 2:
					 i=c1.pop();
					 if(i!=0)
					 cout<<"\n Top  of stack value is=>"<<i;
					 getch();
				 break;
			 case 3:
					 cout<<"\n Enter no. you want to Insert in Queue=>";
					 cin>>i;
					 c2.enq(i);
				 break;
			 case 4:
					 i=c2.deq();
					 if(i!=0)
					 cout<<"Front of queue value is =>"<<i;
					 getch();
				 break;
			 case 5:
					 exit(0);
			}
	   }
   }
