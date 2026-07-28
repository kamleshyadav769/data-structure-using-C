#include <stdio.h>
#include <stdlib.h>

struct Node{
    struct Node *lchild;
    int data;
    int height;
    struct Node *rchild;
}*root=NULL;


int NodeHeight(struct Node *p){
    int hl,hr;
    hl=p&& p->lchild? p->lchild->height:0;
     hr=p&& p->rchild? p->rchild->height:0;
    
     return hl>hr?hl+1:hr+1;
} 

int BalanceFactor(struct Node*p){
      int hl,hr;
    hl=p&& p->lchild? p->lchild->height:0;
     hr=p&& p->rchild? p->rchild->height:0;
     
     return hl-hr;
}
struct Node * LLRotation(struct Node *p){
  struct Node *pl=p->lchild;
   struct Node *plr=pl->rchild;
   pl->rchild=p;
   p->lchild=plr;
   p->height=NodeHeight(p);
    pl->height=NodeHeight(pl);
if(root==p){
    root=pl;
}

return pl;
}
struct Node * RRRotation(struct Node *p){
  struct Node *pr=p->rchild;
   struct Node *prl=pr->lchild;
   pr->lchild=p;
   p->rchild=prl;
   p->height=NodeHeight(p);
    pr->height=NodeHeight(pr);
if(root==p){
    root=pr;
}

return pr;
}


struct Node * LRRotation(struct Node *p){
  struct Node *pl=p->lchild;
   struct Node *plr=pl->rchild;
   pl->rchild=plr->lchild;
   p->lchild=plr->rchild;

plr->lchild=pl;
plr->rchild=p;

 pl->height=NodeHeight(pl);
    p->height=NodeHeight(p);
     plr->height=NodeHeight(plr);
   
     if(root==p){
    root=plr;
}
     
     return plr;
}

struct Node * RLRotation(struct Node *p){
  struct Node *pr=p->rchild;
   struct Node *prl=pr->lchild;
   pr->lchild=prl->rchild;
   p->rchild=prl->lchild;

prl->rchild=pr;
prl->lchild=p;


   p->height=NodeHeight(p);
    pr->height=NodeHeight(pr);
    prl->height=NodeHeight(prl);

if(root==p){
    root=prl;
}

return prl;
}


struct Node *RInsert(struct Node *p,int key){
    struct Node*t=NULL;
    if(p==NULL){
        t=(struct Node*)malloc(sizeof(struct Node));
        t->data=key;
        t->height=1;
        t->lchild=t->rchild=NULL;
        return t;

    }

 if(key<p->data){
     p->lchild=RInsert(p->lchild,key);
 }
 else if(key>p->data) {
     p->rchild=RInsert(p->rchild,key);
 }  
p->height=NodeHeight(p);
if(BalanceFactor(p)==2&&BalanceFactor(p->lchild)==1){

     printf("ll apllied\n");
    return LLRotation(p);
   
}
else if(BalanceFactor(p)==2&&BalanceFactor(p->lchild)==-1){
     printf("lr apllied \n");
   return LRRotation(p);
}
else if(BalanceFactor(p)==-2&&BalanceFactor(p->rchild)==-1){
     printf("rr apllied \n");
      return RRRotation(p);
    
}
else if(BalanceFactor(p)==-2&&BalanceFactor(p->rchild)==1){
     printf("rl apllied \n");
    return RLRotation(p);
}

 return p;
}

struct Node*InPre(struct Node*p){
    while(p&&p->rchild){
        p=p->rchild;
    }
    return p;
}
struct Node*InSucc(struct Node*p){
    while(p&&p->lchild){
        p=p->lchild;
    }
    return p;
}

struct Node *RDelete(struct Node *p,int key){
    struct Node*q;
    if(p==NULL){
        return NULL;
    }
if(p->lchild==NULL && p->rchild==NULL ){
    if(p==root){
        root=NULL;
    }
    free(p);
    return NULL;
}

 if(key<p->data){
     p->lchild=RDelete(p->lchild,key);
 }
 else if(key>p->data) {
     p->rchild=RDelete(p->rchild,key);
 } 
 else{
    
    if(NodeHeight(p->lchild)>NodeHeight(p->rchild)){
        q=InPre(p->lchild);
        p->data=q->data;
         p->lchild=RDelete(p->lchild,q->data); 
    }else{
         q=InSucc(p->rchild);
        p->data=q->data;
         p->rchild=RDelete(p->rchild,q->data); 
    }
 } 
p->height=NodeHeight(p);
if(BalanceFactor(p)==2&&BalanceFactor(p->lchild)>=0){

     printf("ll apllied\n");
    return LLRotation(p);
   
}
else if(BalanceFactor(p)==2&&BalanceFactor(p->lchild)==-1){
     printf("lr apllied \n");
   return LRRotation(p);
}
else if(BalanceFactor(p)==-2&&BalanceFactor(p->rchild)<=0){
     printf("rr apllied \n");
      return RRRotation(p);
    
}
else if(BalanceFactor(p)==-2&&BalanceFactor(p->rchild)==1){
     printf("rl apllied \n");
    return RLRotation(p);
}

 return p;
}



void Inorder(struct Node *p){
    if(p){
        Inorder(p->lchild);
        printf("%d ", p->data);
        Inorder(p->rchild);
    }
  
}
void PrintTree(struct Node*p,int space){
    if(p==NULL)return;
    space+=8;

    PrintTree(p->rchild,space);
    printf("\n");
    int i;
    for(i=8;i<space;i++){
        printf(" ");

    }
 if(p== root){
        printf("%d---------------------------------------------------------------------------------------------",p->data);
    }else{
    printf("%d\n",p->data);
    }
    printf("\n");

    PrintTree(p->lchild,space);
}

void PrintSearch(struct Node*p,int key) {
      while(p!=NULL){
    if(key==p->data){
        printf("%d is present in tree\n",key);
        return;  /// very very important
    }
      if(key < p->data){
       p=p->lchild;
    }else{
        p=p->rchild; 
    }
}
 printf("%d is not present in tree\n",key);
}

struct Node *Search(struct Node*p,int key) {
      while(p!=NULL){
    if(key==p->data){
        return p;
    }
      if(key < p->data){
       p=p->lchild;
    }else{
        p=p->rchild; 
    }
}
return NULL;
}

struct Node *Update(struct Node*p,int oldkey,int newkey) {
if(Search(p,oldkey)==NULL){
    printf("%d is not present in tree\n",oldkey); 
    return p;
}
p=RDelete(p,oldkey);
p=RInsert(p,newkey);
return p;
}
int gcd(int a,int b){
    if(b==0){
        return a;
    }
     gcd(b,a%b);
}

int Gcd(int a,int b){
    while(b!=0){
        int temp=b;
        b=a%b;
        a=temp;
    }
    return a;
}
int main (){
 //ll rotation
  /*root=RInsert(root,30);
  RInsert(root,20);
  RInsert(root,10);
  RInsert(root,5);
  RInsert(root,4);
  RInsert(root,15);
  RInsert(root,25);
  RInsert(root,28);
  RInsert(root,40);
  RInsert(root,50);
  RInsert(root,38);
  RInsert(root,45);*/
 // Inorder(root);
// RDelete(root,28);
//PrintSearch(root,30);  //METHOD1

/*METHOD2 TO SEARCH
struct Node *t;
int key=80;
t=Search(root,key);
if(t){
    printf("%d is present in tree\n",t->data);  
}else{
    printf("%d is not present in tree\n",key);  
}
*/

// printf("BEFORE UPDATE\n");
// Inorder(root);
// printf("\n");
// Update(root,25,35);
// printf("AFTER UPDATE\n");
// Inorder(root);
// PrintTree(root,0);

/*rr rotation
root=RInsert(root,30);
RInsert(root,10);
RInsert(root,40);
  RInsert(root,35);
  RInsert(root,50);
  RInsert(root,60);
Inorder(root);*/

/*lr rotation
root=RInsert(root,50);
RInsert(root,10);
RInsert(root,20);
Inorder(root);*/
/*rl rotation*/
/*root=RInsert(root,10);
RInsert(root,30);
RInsert(root,20);
Inorder(root);*/

printf("%d\n",Gcd(7,9));

    return 0;
}