#include<stdio.h>
#include<conio.h>
#include<process.h>

struct node
{ int info;
  struct node *next;
};
struct node *start;
struct node *last;
struct node *new1;
struct node *current;
struct node *previous;

// function to insert node at beginning
void insert_at_beg()
{
  new1=(struct node*)malloc(sizeof(struct node));
  printf("\n Enter data : ");
  scanf("%d",&new1->info);
  if(start==NULL)
  {
    new1->next=NULL;
    last=new1;
    start=new1;
  }
  else
  {
    new1->next=start;
    start=new1;
  }
}

// function to insert node at end
void insert_at_end()
{ new1=(struct node*)malloc(sizeof(struct node));
  printf("\n Enter data : ");
  scanf("%d",&new1->info);
  if(start==NULL)
  { last=new1;
    start=new1;
  }
  else
  { last->next=new1;
    last=new1;
  }
  last->next=NULL;
}

// function to insert at specific position
void insert_at_spc()
{ int loc,count;
  new1=(struct node*)malloc(sizeof(struct node));
  printf("\n Enter data : ");
  scanf("%d",&new1->info);
  printf("\n Enter Location : ");
  scanf("%d",&loc);
  if(loc==1)
  {
    new1->next=start;
    start=new1;
  }
  else
  {
    previous=start;
    count=1;
    while(count<=loc-1 && previous->next!=NULL)
    {
      previous=previous->next;
      count++;
    }
    new1->next=previous->next;
    previous->next=new1;
  }
}
// function to insert in a sorted list
void insert_at_sort()
{
  new1=(struct node*)malloc(sizeof(struct node));
  printf("\n Enter data : ");
  scanf("%d",&new1->info);
  if(new1->info<=start->info)
  {
    new1->next=start;
    start=new1;
  }
  else
  {
    current=start;
    previous=NULL;
    while(new1->info>=current->info && current!=NULL)
    {
      previous=current;
      current=current->next;
    }
    new1->next=current;
    previous->next=new1;
  }
}

//function to delete node from beginning
void del_at_beg()
{ if(start==NULL)
  { printf("\n Underflow");
  }
  else {
    current=start;
    start=start->next;
    current->next=NULL;
    free(current);
  }
}

// function to delete node from end
void del_at_end()
{
  if(start==NULL)
  { printf("\n Underflow condition"); }
  else if(start->next==NULL)
  {
    free(start);
    start=NULL;
  }
  else
  {
    current=start;
    while(current->next!=last)
    {
      current=current->next;
    }
    current->next=NULL;
    free(last);
    last=current;
  }
}

// function to delete node from a specific position
void del_at_spc()
{ int loc,i;
  printf("\n Enter the location : ");
  scanf("%d",&loc);
  current=start;
  previous=NULL;
  if(start==NULL)
  { printf("\n Underflow"); }
  else if(loc==1)
  {
    start=start->next;
    current->next=NULL;
    free(current);
  }
  else
  {
    for(i=1; i<=loc-1; i++)
    {
      previous=current;
      current=current->next;
    }
    previous->next=current->next;
    current->next=NULL;
    free(current);
  }
}

//function to traverse the array
void traverse()
{ new1=start;
  while(new1!=NULL)
  { printf("%d \t",new1->info);
    new1=new1->next;
  }
}

void main()
{ int x;

do{    clrscr();
printf("\n Main Menu");
printf("\n 1.Insertion at beginning");
printf("\n 2.Insertion at end");
printf("\n 3.Insertion at specific position");
printf("\n 4.Insertion in sorted linked list");
printf("\n 5.Deletion at beginning");
printf("\n 6.Deletion at end");
printf("\n 7.Deletion at specific position");
printf("\n 8.Traversing");
printf("\n 9.Exit");
printf("\n Enter your choice : ");
scanf("%d",&x);

 switch(x)
 {
   case 1:
   insert_at_beg();
   break;
   case 2:
   insert_at_end();
   break;
   case 3:
   insert_at_spc();
   break;
   case 4:
   insert_at_sort();
   break;
   case 5:
   del_at_beg();
   break;
   case 6:
   del_at_end();
   break;
   case 7:
   del_at_spc();
   break;
   case 8:
   traverse();
   break;
   case 9:
   exit(0);
 }
 getch();
 }while(1);
}