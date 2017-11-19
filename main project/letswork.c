#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct choice {
	char *clg;
	char *brh;
	struct choice *next_choice;
	struct choice *prev_choice;
	struct student *cur_stu;
}CHOICE;

typedef struct student {
	char *id;
	int marks;
	struct choice *choice_begin;
	struct student *left_stu;
	struct student *right_stu;
}STUDENT;

typedef struct student_list{
	STUDENT* root;
}STUDENT_LIST;
void init_student(STUDENT_LIST* s){
	s->root=NULL;
}
STUDENT* create_new_student(char *name,int rank){
	//printf("before ");
	STUDENT* new=(STUDENT*)malloc(sizeof(STUDENT));
	//printf("after");
	new->id=(char*)malloc(sizeof(char)*100);
	strcpy(new->id,name);
	new->marks=rank;
	new->choice_begin=NULL;
	new->left_stu=NULL;
	new->right_stu=NULL;
	//printf("in create=%s\n",new->id);
	//printf("created=%d\n",rank);
	return(new);
}
STUDENT* find_student(STUDENT* r,char *id,int marks){
	if((r==NULL)||(strcmp(r->id,id)==0)){
		return(r);
	}
	else if(r->marks>marks){
		return(find_student(r->left_stu,id,marks));
	}
	else{
		return(find_student(r->right_stu,id,marks));
	}
}
int addStudent(STUDENT_LIST* s,char *name,int rank){
	STUDENT* r=create_new_student(name,rank);
	STUDENT* p=s->root;
	STUDENT* q=NULL;
	while(p!=NULL){
		q=p;
		if(p->marks<r->marks){
			p=p->right_stu;
		}
		else{
			p=p->left_stu;
		}
	}
	//printf("after while");
	if(q==NULL){
		s->root=r;
		//printf("root changed");
	}

	else{
		if(q->marks>r->marks){
			q->left_stu=r;
		}
		else{
			q->right_stu=r;
		}
	}
	//printf("in add=%s\n",r->id);
	return(1);
}
int add_choice(STUDENT_LIST* s,char *id,int marks,char* clg_name,char* brh_name){
	STUDENT* cur=find_student(s->root,id,marks);
	if(cur==NULL){
		return(0);
	}
	//printf("%s\n",cur->id);
	CHOICE* p=cur->choice_begin;
	CHOICE* q=NULL;
	while(p!=NULL){
		q=p;
		p=p->next_choice;
	}
	//printf("do");
	CHOICE* new=(CHOICE*)malloc(sizeof(CHOICE));
	new->clg=(char*)malloc(sizeof(char)*100);
	strcpy(new->clg,clg_name);
	new->brh=(char*)malloc(sizeof(char)*100);
	strcpy(new->brh,brh_name);
	new->cur_stu=cur;
	new->next_choice=NULL;
	//printf("to");
	if(q==NULL){
		cur->choice_begin=new;
		new->prev_choice=NULL;
	}
	else{
		q->next_choice=new;
		new->prev_choice=q;
	}
	//printf("root=%s\n",s->root->id);
	return(1);
}
/*int Display_my_choice(STUDENT_LIST* s,int rank){
	STUDENT* cur=find_student(s->root,rank);
	if(cur==NULL){
		return(-1);
	}
	printf("Student name:%s \tStudent rank:%d\n",cur->id,cur->marks);
	CHOICE* p=cur->choice_begin;
	if(p==NULL){
		return(0);
	}
	int i=1;
	printf("%-4s %-40s %-40s\n","rank","college","branch");
	while(p!=NULL){
		printf("%-4d %-40s %-40s\n",i,p->clg,p->brh);
		p=p->next_choice;
	}
}*/

void print_inorder(STUDENT* r){
	if(r!=NULL){
		print_inorder(r->right_stu);
		//printf("%s,",r->id);
		//printf("%d\n",r->marks);
		CHOICE* p=r->choice_begin;
		//printf("choice header=%p",p);
		while(p!=NULL){
			printf("%s,%s,%s\n",r->id,p->clg,p->brh);
			p=p->next_choice;
		}
		print_inorder(r->left_stu);
	}
}
void in_order(STUDENT_LIST* s){
	//printf("\nroot=%d\n",s->root->rank);
	printf("root=%s",s->root->id);
	print_inorder(s->root);
	printf("\n");
}
/*void main(){
	STUDENT_LIST s;
  init_student(&s);
  int ch,check;
  char ch_y;
  int rank;
  char *name,*clg_name,*brh_name;
  int ch_no;
  do{
    printf("Please enter your option:\n");
    printf("1.I have not yet registered\n");
    printf("2.I have registered and want to add a new choice\n");
    printf("3.Let me see my choices\n");
		printf("4.see students in order\n");
    scanf("%d",&ch);
    switch(ch){
      case 1:printf("Enter your name:\n");
			       name=(char*)malloc(100*sizeof(char));
						 //printf("ok\n");
						 fflush(stdin);
             gets(name);
             printf("Enter your cet rank:\n");
             scanf("%d",&rank);
             check=addStudent(&s,name,rank);
             if(check==0){
               printf("Sorry, you have already registered\n");
							 free(name);
             }

						 //in_order(&s);
						 break;
		 case 4:in_order(&s);
		        break;
      case 2:printf("Enter your cet rank number:");
             scanf("%d",&rank);
             printf("Enter the college name:");
						 clg_name=(char*)malloc(100*sizeof(char*));
             fflush(stdin);
             gets(clg_name);
             printf("Enter the branch name:");
						 brh_name=(char*)malloc(100*sizeof(char*));
             fflush(stdin);
             gets(brh_name);
             check=add_choice(&s,rank,clg_name,brh_name);
             if(check==0){
               printf("Sorry, you have not yet registered. First register and then add your choices\n");
             }
             break;
      case 3:printf("Enter your cet rank number:");
             scanf("%d",&rank);
             check=Display_my_choice(&s,rank);
             if(check==0){
               printf("Sorry, you have not yet given your choices\n");
             }
             if(check==-1){
               printf("Sorry, you have not yet registered\n");
             }
             break;
    }
    printf("Do you want to continue?...y/n:");
    fflush(stdin);
    scanf("%c",&ch_y);
    //printf("%c\n",ch_y);
  }while(ch_y=='y');
  //printf("The end");
  //return(0);
}*/
