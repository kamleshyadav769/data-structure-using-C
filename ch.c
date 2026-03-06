#include <stdio.h>
#include<stdlib.h>
struct Node
{
  
    struct Node*prev;
int data;
struct Node*next;
}*head;
 // struct Node* head = NULL;
void create(int A[],int n ){
 // struct Node* head = NULL;

    int i;
    struct Node*t,*last;
    head=(struct Node*)malloc(sizeof(struct Node));
    head->data=A[0];
    head->prev=head->next=head;
    last =head;
    for(i=1;i<n;i++){
        t=(struct Node*)malloc(sizeof(struct Node));
        t->data=A[i];
       // t->next=head->prev;//wrong
         t->next=head;//correct
        t->prev=last;
        last->next=t;
        head->prev=t;
        last=t;
    }
  // ✅ Final circular connection to ensure proper loop
  
  //  last->next = head;  
 //head->prev = last;
}
void display(struct Node*p){
     if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
   do{
        printf("%d ",p->data);
        p=p->next;
    } while(p!=head);
printf("\n");
}
int length(struct Node*p){
    if (head == NULL) return 0; 
    int len=0;
   do{
      len++;
        p=p->next;
    } while(p!=head);
   return len;
}
void insert(struct Node*p,int index,int x){
    int i;
    struct Node*t;
    t=(struct Node*)malloc(sizeof(struct Node));
    t->data=x;
    if(index<0||index>length(p)){
        return;
    }
    
if(index==0){
   if(head==NULL){
        printf("List isinsert empty.\n");
         head=t;
        head->next=head->prev=head;
       return ;
    }
    else{
      printf("skemnfr");
        t->next=head;
        t->prev=head->prev;
         
        head->prev->next=t;
         head->prev=t;
        head=t;
    }
}
else{
     struct Node* p = head;
    for(i=0;i<index-1;i++){
     p=p->next;
    }
   t->next=p->next;
   t->prev=p;
   p->next=t; 
  // p->next->prev=t->next; //wrong
   t->next->prev=t;
}
}
int delete(struct Node*p,int index){
    int i,x=-1;
    if(index<1||index>length(p)){
        printf( "invalid index");
        return x;
    }
    if(index==1){
        if(head->next==head){
            x=head->data;
            free(head);
            head=NULL;
  // printf( "no node present");
        }
        else{
       head=head->next;
       p->prev->next=head;
       head->prev=p->prev;
       x=p->data;
      free(p);
     //printf( "first node success fully deleted\n");
        } 
    }
 else{
    for(i=0;i<index-1;i++){
     p=p->next;
    }
    p->prev->next=p->next;
    if(p->next){
        p->next->prev=p->prev;
    } 
    x=p->data;
    free(p);
 }   
   printf(" the element you delete %d\n",x); // return x;
}
int main() {
 int A[]={9,7,6};
//struct Node* head = NULL;
 // int A[5];  
create(A,3);
 // printf("\n%d\n",length(head));
 //delete(head,1);
//  insert(head,0,44);
 // printf( "before deletion\n");
 // display(head);
  delete(head,3);
  // printf( "after deletion\n");
display(head);
    return 0;
}

https://chatgpt.com/?utm_source=google&utm_medium=paidsearch_brand&utm_campaign=GOOG_C_SEM_GBR_Core_CHT_BAU_ACQ_PER_MIX_ALL_APAC_IN_EN_032525&utm_term=chatgpt&utm_content=177344203135&utm_ad=744003610701&utm_match=e&gad_source=1&gad_campaignid=22370388714&gbraid=0AAAAA-IW-UUrnOd6jX9mdZQBgorYfg-jH&gclid=CjwKCAjwv5zEBhBwEiwAOg2YKL-356fj9Mqd7l3Md_4hQgFQUZgWEzh3s2dUk1_Vd3_E73QA7YZNYhoCnQAQAvD_BwE
