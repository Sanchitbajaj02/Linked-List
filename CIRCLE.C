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
struct node *prev;
int count=0;
int loc=0;

//function to insert data at beginning
void insert_at_beg()
{ new1=(struct node*)malloc(sizeof(struct node));
  printf("\n Enter data : ");
  scanf("%d",&new1->info);
  if(last==NULL)
  {  new1->next=new1;
     last=new1;
  }
  else
  {  new1->next=last->next;
     last->next=new1;
  }
}

//function to insert data at end
void insert_at_end()
{ new1=(struct node*)malloc(sizeof(struct node));
  printf("\n Enter data : ");
  scanf("%d",&new1->info);
  if(last==NULL)
  {  new1->next=new1;
     last=new1;
  }
  else
  {  new1->next=last->next;
     last->next=new1;
     last=new1;
  }
}

//function to insert data at specific position
void insert_at_spc()
{ new1=(struct node*)malloc(sizeof(struct node));
  printf("\n Enter data : ");
  scanf("%d",&new1->info);
  printf("\n Enter the location : ");
  scanf("%d",&loc);
  if(loc==1)
  { new1->next=last->next;
    last->next=new1;
  }
  else
  { prev=last->next;
    count=1;
    while(count<loc-1)
    { prev=prev->next;
      count++;
    }
    if(prev==last)
    { new1->next=last->next;
      last->next=new1;
      last=new1;
    }
    else
    { new1->next=prev->next;
      prev->next=new1;
    }
  }
}

//function to delete data at beginning
void del_at_beg()
{ if(last==NULL)
  { printf("\n Underflow condition");	}
  else if(last->next==last)
  { printf("\n Item deleted : %d",last->info);
    free(last);
    last=NULL;
  }
  else
  { current=last->next;
    last->next=current->next;
    current->next=NULL;
    printf("\n Item deleted : %d",current->info);
    free(current);
  }
}

//function to delete data at end
void del_at_end()
{ if(last==NULL)
  { printf("\n Underflow condition");	}
  else if(last->next==last)
  { free(last);
    last=NULL;
  }
  else
  { current=last->next;
    while(current->next!=last)
    { current=current->next;
    }
    current->next=last->next;
    last->next=NULL;
    printf("\n Item deleted : %d",last->info);
    free(last);
    last=current;
  }
}

//function to delete data at specific position
void del_at_spc()
{ int i=-1;
  printf("\n Enter the location : ");
  scanf("%d",&loc);
  current=last->next;
  prev=NULL;
  if(last==NULL)
  { printf("\n Underflow condition");	}
  else if(loc==1)
  { last->next=current->next;
    current->next=NULL;
    printf("\n Item deleted : %d",current->info);
    free(current);
  }
  else
  { for(i=1; i<loc; i++)
     { prev=current;
       current=current->next;
     }
    if(current==last)
     { prev->next=current->next;
       last=prev;
     }
    else
     { prev->next=current->next;	}
    current->next=NULL;
    free(current);
  }
}

//function to traverse the circular linked list
void traverse()
{ new1=last->next;
  while(new1!=last)
  { printf("%d \t",new1->info);
    new1=new1->next;
  }
  printf("%d",last->info);
}

void main()
{ int x;

do{    clrscr();
printf("\n Main Menu");
printf("\n 1.Insertion at beginning");
printf("\n 2.Insertion at end");
printf("\n 3.Insertion at specific position");
printf("\n 4.Deletion at beginning");
printf("\n 5.Deletion at end");
printf("\n 6.Deletion at specific position");
printf("\n 7.Traversing");
printf("\n 8.Exit");
printf("\n Enter your choice : ");
scanf("%d",&x);

 switch(x)
 { case 1:
    insert_at_beg();
   break;
   case 2:
    insert_at_end();
   break;
   case 3:
    insert_at_spc();
   break;
   case 4:
    del_at_beg();
   break;
   case 5:
    del_at_end();
   break;
   case 6:
    del_at_spc();
   break;
   case 7:
    traverse();
   break;
   case 8:
    exit(0);
   break;
 }
 getch();
}while(1);
}