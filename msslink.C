#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

typedef struct node
 { int data;
   struct node *next;
 }node;
node *merge(node *l1,node *l2);
node *create_normal();
node *create_sorted();
void print(node *head);
void sort(node *head);
void main()
 { node *head1,*head2,*head3;
   printf("\nCreating Normal(unsortrd) linked list \n");
   head1=create_normal();
   printf("\nCreating sorted linked list \n");
   head2=create_sorted();
   printf("\nFirst LInked list(Before Sorting):");
   print(head1);
   sort(head1);
   printf("\nFirst Linked list(After Sorting):");
   print(head1);
   printf("\nSecond Linked list:");
   print(head2);
   head3=merge(head1,head2);
   printf("\nFinal List:");
   print(head3);
   getch();
 }
node *merge(node *l1,node *l2)
   { 
	node *l,*p;
     l=NULL;
     while(l1!=NULL && l2!=NULL)
       { 
	if(l1->data < l2->data)
	   { if(l==NULL)
	      { l=p=l1;
		l1=l1->next;
	      }
	     else
	      { p->next=l1;
		l1=l1->next;
		p=p->next;
	      }
	   }
	 else
	   { if(l==NULL)
	      { l=p=l2;
		l2=l2->next;
	      }
	     else
	      { p->next=l2;
		l2=l2->next;
		p=p->next;
	      }
	   }
      }
      if(l1!=NULL)
       { if(l==NULL)
	   l=l1;
	 else
	   p->next=l1;
       }
      if(l2!=NULL)
       { if(l==NULL)
	   l=l2;
	 else
	   p->next=l2;
       }
    return(l);
  }
 node *create_normal()
  { node *head=NULL,*p;
    int n,x,i;
    printf("\nNumber of nodes:");
    scanf("%d",&n);
    printf("\nEnter data:");
    for(i=1;i<=n;i++)
     { scanf("%d",&x);
       if(head==NULL)
	 { p=head=(node*)malloc(sizeof(node));
	   p->next=NULL;
	 }
       else
	{p->next=(node*)malloc(sizeof(node));
	p=p->next;
	p->next=NULL;
	}
       p->data=x;
    }
   return(head);
 }
node *create_sorted()
  { node *head=NULL,*p,*q;
    int n,x,i;
    printf("\nNumber of nodes:");
    scanf("%d",&n);
    printf("\nEnter data:");
    for(i=1;i<=n;i++)
     { scanf("%d",&x);
       p=(node*)malloc(sizeof(node));
       p->data=x;
       p->next=NULL;
       if(head==NULL || x<head->data)
	  { p->next=head;
	    head=p;
	  }
       else
	{ q=head;
	  while(q->next !=NULL && x>q->next->data)
	    q=q->next;
	  p->next=q->next;
	  q->next=p;
	}
     }
   return(head);
 }
 void print(node *head)
  { printf("\n");
   while(head != NULL)
    { printf("%5d",head->data);
      head=head->next;
    }
  }
void sort(node *head)
  { int i,j,n,temp;
    node *p;
   /*counting number of nodes*/
    for(n=0,p=head;p!=NULL;p=p->next)
       n++;
    for(i=1;i<n;i++)
     {p=head;
      for(j=0;j<n-i;j++)
       {if(p->data > p->next->data)
	  { temp=p->data;
	    p->data=p->next->data;
	    p->next->data=temp;
	  }
	p=p->next;
       }
      }
    }