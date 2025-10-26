#include<iostream>
using namespace std;

typedef struct DNode{
    int data;
    struct DNode *prior,*next;
}DNode,*DLinkList;
bool InitDLinkList(DLinkList &L)
{
    L=new DNode;
    if(L==NULL)
    return false;
    L->prior=NULL;
    L->next=NULL;
    return true;
}
bool InsertNextDNode(DNode *p,DNode *s)//结点s插到p之后
{
    if(p==NULL||s==NULL)
    return false;
   s->next=p->next;
   if(p->next!=NULL)
   p->next->prior=s;
   s->prior=p;  
   p->next=s;
   return true;
}
bool DeleteNextDNode(DNode *p)
{
    if(p==NULL)
    return false;
    DNode *q=p->next;
    if(q==NULL)
    return false;
    p->next=q->next;
    if(q->next!=NULL)
    q->next->prior=p;
    delete q;
    return true;
}
void DestoryList(DLinkList &L)
{
    while(L->next!=NULL)
    DeleteNextDNode(L);
    delete L;
    L=NULL;
}