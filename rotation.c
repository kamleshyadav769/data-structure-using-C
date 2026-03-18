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

     printf("ll apllied");
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

void Inorder(struct Node *p){
    if(p){
        Inorder(p->lchild);
        printf("%d ", p->data);
        Inorder(p->rchild);
    }
}





int main (){
 /*ll rotation
  root=RInsert(root,30);
  RInsert(root,20);
  RInsert(root,10);
  RInsert(root,5);
  RInsert(root,4);
  RInsert(root,15);
  RInsert(root,25);
  RInsert(root,28);
  RInsert(root,40);
  RInsert(root,50);
Inorder(root);*/

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
root=RInsert(root,10);
RInsert(root,30);
RInsert(root,20);
Inorder(root);
    return 0;
}