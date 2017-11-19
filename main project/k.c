#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct branch{
    char name_of_branch[50];
    int no_of_seats;
    struct branch *next;
    struct branch *prev;
}BRANCH;

typedef struct branch1{
    BRANCH *head;
    BRANCH *tail;
    int no_of_branch;
}BRANCH_DLL;

typedef struct college{
    char college_name[100];
    BRANCH_DLL *link;
    struct college *next;
    struct college *prev;
}COLLEGE;

typedef struct collegeno{
      COLLEGE *head;
      COLLEGE *tail;
      int college_no;
}COLLEGE_DLL;

void college_initialize(COLLEGE_DLL *dll)
 {
     dll->head = NULL;
     dll->tail = NULL;
     dll->college_no = 0;
  }


void college_add_new(COLLEGE_DLL *list, char college_name[])
 {
     COLLEGE *temp;
     temp = (COLLEGE *)malloc(sizeof(COLLEGE));
     strcpy(temp->college_name,college_name);
     temp->prev = NULL;
     temp->link =NULL;
     temp->next = list ->head;
     if(list ->head == NULL)
     {
        list->head=temp;
        list ->tail = temp;
     }
     else
        (list->head)->prev = temp;
     list->head = temp;
     list->college_no++;
 }

void branch_add_new(COLLEGE_DLL *list,char college_name[],char name_of_branch[],int seats)
{
     COLLEGE *temp;
     BRANCH *temp2 = (BRANCH *)malloc(sizeof(BRANCH));
     temp = list -> head;

     while(temp != NULL)
      {
         if(strcmp(temp->college_name,college_name)==0)
         {
               strcpy(temp2->name_of_branch,name_of_branch);
               temp2->no_of_seats=seats;
               temp2->prev = NULL;
               if(temp->link==NULL)
               {
                 temp->link=(BRANCH_DLL*)malloc(sizeof(BRANCH_DLL));
                 temp->link->head=temp2;
                 temp->link->tail=temp2;
                 temp2->next=NULL;
                 temp->link->no_of_branch=1;
               }
               else
               {
                temp2->next=temp->link->head;
                temp2->prev=NULL;
                temp->link->head=temp2;
                temp->link->no_of_branch+=1;
               }
                //temp ->link -> no_of_branch++;
                break;
         }
            temp = temp-> next;
    }
}
void print(COLLEGE_DLL *s){
  COLLEGE* p=s->head;
  BRANCH* brh;
  while(p!=NULL){
    printf("%s\n",p->college_name);
    if(p->link){
      brh=p->link->head;
      while(brh!=NULL){
      printf("%s,%d\n",brh->name_of_branch,brh->no_of_seats);
      brh=brh->next;
      }
    }
    p=p->next;
  }
}

/*void college_add_branch_seats(COLLEGE_DLL *list,char college_name[])
{
     COLLEGE *temp;
     BRANCH *temp2;
     temp = list -> head;
     int i;
     //printf("Hello");
     //printf("new");
     //printf("head in brh add=%p,%p\n",temp,list->head);
     while(temp != NULL)
      {
         //printf("%s vs %s \n",temp->college_name,college_name);
         if(strcmp(temp->college_name,college_name)==0)
         {
           for(i = 0;i < temp ->link -> no_of_branch;i++)
           {
             temp2 = (BRANCH *)malloc(sizeof(BRANCH));
             printf("Enter the branch name:");
             //fflush(stdin);
             //gets(temp2 -> name_of_branch);
             scanf("%[^\n]s",temp2 ->name_of_branch);
             printf("Enter the number of seats that you want to allocate for that branch:");
             scanf("%d",&(temp2 ->no_of_seats));
             temp2->prev=NULL;
             temp2->next=temp->link->head;
             if(temp->link -> head == NULL){
                temp->link -> head = temp2;
             }
             else{
                temp ->link -> head ->prev=temp2;
                temp->link -> head = temp2;
             }
           }
           break;
         }

        temp = temp-> next;
      }

}
*/
void modify(COLLEGE_DLL *list, char college_name[], char name_of_branch[])
{
  COLLEGE *c = list ->head;
  BRANCH* b;
  char r;
  int j;
  while(c != NULL)
  {   if((strcmp(c ->college_name,college_name)==0)&&(c->link))
      {
        b=c->link->head;
        while(b!=NULL){
          if(strcmp(b->name_of_branch,name_of_branch)==0){

        printf("The present number of seats alloted are:%d\n",b->no_of_seats);
        printf("Do you want to change it?...y/n");
        fflush(stdin);
        scanf("%c",&r);
        if(r=='y'){
        printf("Enter the no. of seats that you want to give for this branch:");
        scanf("%d",&(b->no_of_seats));
      }
      }
      b=b->next;
      }
    }
    c=c->next;
  }
}
/*

int main(){
  COLLEGE_DLL dll;
  college_initialize(&dll);
  int ch,check;
  int branchno;
  int seats;
  char ch_y;
  char clg_name[100];
  char brh_name[100];
  do{
    printf("Please enter your option:\n");
    printf("1.You want to add a new college\n");
    printf("2.You want to allocate the number of seats for a particular branch\n");
    printf("3.You want to modify the number of seats for a particular branch\n");
    printf("4.display\n");
    scanf("%d",&ch);
    switch(ch){
      case 1:printf("Enter the college name:");
            printf("correct");
             fflush(stdin);
             gets(clg_name);
             //scanf("%s",clg_name);
             //printf("hai\n");
             college_add_new(&dll,clg_name);
             printf("printing1");
             printf("Enter the branch name:");
             fflush(stdin);
             gets(brh_name);
             printf("Enter the number of seats you want to add:");
             scanf("%d",&seats);
             branch_add_new(&dll,clg_name,brh_name,seats);
             printf("printing2");
             break;
    case 2:printf("Enter the college name:");
          printf("correct");
           fflush(stdin);
           gets(clg_name);
           //scanf("%s",clg_name);
           printf("printing1");
           printf("Enter the branch name:");
           fflush(stdin);
           gets(brh_name);
           printf("Enter the number of seats you want to add:");
           scanf("%d",&seats);
           branch_add_new(&dll,clg_name,brh_name,seats);
           printf("printing2");
           break;
    case 4:print(&dll);
            break;

      case 3:printf("Enter the college name:");
             fflush(stdin);
             gets(clg_name);
             printf("Enter the branch name:");
             fflush(stdin);
             gets(brh_name);
             modify(&dll,clg_name,brh_name);
             break;
    }
    printf("Do you want to continue?...y/n:");
    fflush(stdin);
    scanf("%c",&ch_y);
  }while(ch_y=='y');

  return(0);
}*/
