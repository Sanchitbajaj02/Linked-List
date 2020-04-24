#include<stdio.h>
#include<conio.h>
#include<process.h>

struct node
{ int info;
  struct node *next;
  struct node *prev;
};
struct node *start;
struct node *last;
struct node *new1;
struct node *current;
struct node *previous;

// function to insert at beginning
void insert_at_beg()
{
  new1=(struct node*)malloc(sizeof(struct node));
  printf("\n Enter data : ");
  scanf("%d",&new1->info);
  if(start==NULL)
  {
    new1->next=NULL;
    new1->prev=NULL;
    last=new1;
    start=new1;
  }
  else
  {
    new1->next=start;
    start->prev=new1;
    new1->prev=NULL;
    start=new1;
  }
}

//function to insert at end
void insert_at_end()
{ new1=(struct node*)malloc(sizeof(struct node));
  printf("\n Enter data : ");
  scanf("%d",&new1->info);
  if(start==NULL)
  { new1->next=NULL;
    new1->prev=NULL;
    last=new1;
    start=new1;
  }
  else
  { last->next=new1;
    new1->prev=last;
    new1->next=NULL;
    last=new1;
  }
}

// function to insert at specific location
void insert_at_spc()
{
  int loc=0,count;
  new1=(struct node*)malloc(sizeof(struct node));
  printf("\n Enter data : ");
  scanf("%d",&new1->info);
  printf("\n Enter location : ");
  scanf("%d",&loc);
  if(loc==1)
  {
    new1->next=start;
    start->prev=new1;
    new1->prev=NULL;
    start=new1;
  }
  else
  {
    previous = start;
    count=1;
    while(count<=loc-1 && previous!=NULL)
    {
      previous=previous->next;
      count++;
    }
    new1->prev=previous;
    if(previous->next==NULL)
    {
      new1->next=NULL;
      previous->next=new1;
      last=new1;
    }
    else
    {
      new1->next=previous->next;
      previous->next->prev=new1;
      previous->next=new1;
    }
  }
}

// function to delete at beginning
void delete_at_beg()
{
  if(start==NULL)
  {
    printf("\n Underflow");
  }
  else
  {
    current=start;
    start=start->next;
    start->prev=NULL;
    current->next=NULL;
    current->prev=NULL;
    free(current);
    printf("\n Element deleted");
  }
}

// function to delete at end
void delete_at_end()
{ if(start==NULL)
  { printf("\n Underflow");
  }
  else if(start->next==NULL)
  { free(start);
    start=NULL;
    last=NULL;
  }
  else {
    current=last->prev;
    current->next=NULL;
    last->prev=NULL;
    free(last);
    last=current;
    printf("\n Element deleted");
  }
}

// function to delete at specific position
void delete_at_spc()
{
  int loc,i;
  printf("\n Enter location to delete element : ");
  scanf("%d",&loc);
  current=start;
  previous=NULL;
  if(start==0)
  {
    printf("\n Underflow");
  }
  else if(loc==1)
  {
    start=start->next;
    start->prev=NULL;
    current->next=NULL;
    free(current);
  }
  else
  {
    for(i=1; i<loc; i++)
    {
      previous=current;
      current=current->next;
    }
    if(current->next==NULL)
    {
      previous->next=NULL;
      last=previous;
    }
    else
    {
      previous->next=current->next;
      current->next->prev=previous;
      current->next=NULL;
      current->prev=NULL;
      free(current);
    }
  }
  printf("\n Element deleted");
}

// function to traverse in Forward direction
void fwdtraverse()
{ new1=start;
  while(new1!=NULL)
  { printf("%d \t",new1->info);
    new1=new1->next;
  }
}

// function to traverse in Backward direction
void bwdtraverse()
{ new1=last;
  while(new1!=NULL)
  { printf("%d \t",new1->info);
    new1=new1->prev;
  }
}

void main()
{ int x;

do{    clrscr();
printf("\n Main Menu");
printf("\n 1.Insertion at beginning");
printf("\n 2.Insertion at end");
printf("\n 3.Insertion at specific postion");
printf("\n 4.Deletion at beginning");
printf("\n 5.Deletion at end");
printf("\n 6.Deletion at specific position");
printf("\n 7.Forward Traversing");
printf("\n 8.Backward Traversing");
printf("\n 9.Exit");
printf("\n Enter your choice : ");
scanf("%d",&x);

 switch(x)
 {
   case 1: insert_at_beg();
   break;
   case 2: insert_at_end();
   break;
   case 3: insert_at_spc();
   break;
   case 4: delete_at_beg();
   break;
   case 5: delete_at_end();
   break;
   case 6: delete_at_spc();
   break;
   case 7: fwdtraverse();
   break;
   case 8: bwdtraverse();
   break;
   case 9: exit(0);
   break;
 }
 getch();
 }while(1);
}