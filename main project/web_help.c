#include <stdio.h>
#include<stdlib.h>
#include "letswork.c"
#include "k.c"
void Allocate(STUDENT* cur,COLLEGE_DLL* clg_list){
  if(cur!=NULL){
    Allocate(cur->right_stu,clg_list);
    FILE* fp=fopen("C:\\xampp\\htdocs\\main project\\allocate.txt","a");
    int al=0;
    CHOICE* ch=cur->choice_begin;
    COLLEGE* clg;
    BRANCH* brh;
    //printf("%s\n",cur->id);
    while((ch!=NULL)&&(al==0)){
      clg=clg_list->head;
      while((clg!=NULL)&&(al==0)){
      //printf("college=%s vs %s,%d\n",clg->college_name,ch->clg,strcmp(clg->college_name,ch->clg));
      if((strcmp(clg->college_name,ch->clg)==0)&&(clg->link)){
        brh=clg->link->head;
        while((brh!=NULL)&&(al==0)){
          //printf("branch=%s vs %s",brh->name_of_branch,ch->brh);
          if(strncmp(brh->name_of_branch,ch->brh,strlen(brh->name_of_branch))==0)
          {
            if(brh->no_of_seats>0){
              printf("allocating=");
              printf("%s,%s,%s\n",cur->id,clg->college_name,brh->name_of_branch);
              fprintf(fp,"%s,%s,%s\n",cur->id,clg->college_name,brh->name_of_branch);
              brh->no_of_seats-=1;
              al=1;
            }
          }
          brh=brh->next;
        }
      }
        clg=clg->next;
      }
      ch=ch->next_choice;
    }
    fclose(fp);
    Allocate(cur->left_stu,clg_list);
  }
}
void main(){
  FILE* fp1,*fp2;
  char id[100],id_check[100];
  char clg_name[100],brh_name[100];
  STUDENT_LIST s;
  init_student(&s);
  int m;
  char str[1000];
  fp1=fopen("C:\\xampp\\htdocs\\main project\\choice_entry.txt","r");
  fp2=fopen("C:\\xampp\\htdocs\\main project\\test_marks.txt","r");
  //fseek(fp2,0,0);
  while(fgets(str,sizeof(str),fp2)!=NULL){
    //printf("here");

    //printf("%s",str);
    strcpy(id,strtok(str,","));
    m=atoi(strtok(NULL,","));
    //printf("bang");
    //printf("%s,%d\n",id,m);
    addStudent(&s,id,m);
    //printf("after");
    fseek(fp1,0,0);
    while(fgets(str,sizeof(str),fp1)){
      //printf("%s",str);
      strcpy(id_check,strtok(str,","));
      //printf("%s\n",str);
      if(strcmp(id,id_check)==0){
         strcpy(clg_name,strtok(NULL,","));
         strcpy(brh_name,strtok(NULL,","));
         //printf("%s,%s\n",id,id_check);
         add_choice(&s,id,m,clg_name,brh_name);

      }
      //printf("end");
    }
  //  printf("end");
  }
  fclose(fp1);

  fclose(fp2);
  //in_order(&s);
  COLLEGE_DLL dll;
  college_initialize(&dll);
  fp1=fopen("C:\\xampp\\htdocs\\main project\\no_of_seats.txt","r");
  int ch,check;
  int branchno;
  int seats;
  //printf("here");
  while(fgets(str,sizeof(str),fp1)!=NULL){
      //printf("%s",str);
      strcpy(clg_name,strtok(str,","));
      //printf("why");
      strcpy(brh_name,strtok(NULL,","));
    //  printf("0");
      seats=atoi(strtok(NULL,","));
      //printf("-1");
      college_add_new(&dll,clg_name);
      branch_add_new(&dll,clg_name,brh_name,seats);
      //printf("one");
      while((fgets(str,sizeof(str),fp1)!=NULL)&&(strcmp(str,"\n")!=0)){
        //printf("%s\n",str);
        strcpy(clg_name,strtok(str,","));
        strcpy(brh_name,strtok(NULL,","));
        seats=atoi(strtok(NULL,","));
        branch_add_new(&dll,clg_name,brh_name,seats);
      }
  }
  printf("entered=\n");
  print(&dll);
  fp1=fopen("C:\\xampp\\htdocs\\main project\\allocate.txt","w");
  fclose(fp1);
  Allocate(s.root,&dll);
}
