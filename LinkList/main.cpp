#include<iostream>
using namespace std;
typedef struct LNode{
    int data;
    struct  LNode *next;
}LNode,*LinkList;//LinkList：等同于 struct LNode*（链表头指针类型)
/*
定义头节点
LNode *L=LinkList L   LinkList强调是链表,LNode*强调是结点
*/
bool InitList(LinkList &L)
{
    L=new LNode;
    if(L==NULL)
      return false;
      L->next=NULL;
      return true;
}//根据链表的初始化逻辑，初始化一个链表通常意味着创建一个头节点
bool ListInsert(LinkList &L,int i,int e)
{
    if(i<1)
    {
        return false;
    }
    LNode *p;//指针p指向当前扫描到的结点
    int j=0;//当前p指向的是第几个结点
    p=L;//L指向头节点,头节点是第0个节点
    while(p!=NULL&&j<i-1)//循环找到第i-1个结点
    {
        p=p->next;
        j++;
    }
    if(p==NULL)
    {
        return false;
    }
    LNode *s=new LNode;
    s->data=e;
    s->next=p->next;
    p->next=s;//顺序不能颠倒
    return true;
}
bool InsertNextNode(LNode *p,int e)//在p结点后插入元素e
{
    if(p==NULL)
    {
        return false;
    }
    LNode *s=new LNode;
    if(s==NULL)
    {
        return false;
    }
    s->data=e;
    s->next=p->next;
    p->next=s;
    return true;
}
bool InsertPriorNode(LNode *p,int e)//前插
{
   if(p==NULL)
   return false;
   LNode *s=new LNode;
   if(s==NULL)
   return false;
   s->next=p->next;
   p->next=s;
   s->data=p->data;
   p->data=e;   
}
bool ListDelete(LinkList &L,int i,int &e)
{
    if(i<1)
    return false;
    LNode *p;//指针p指向当前扫描到的结点
    int j=0;
    p=L;
    while(p!=NULL&&j<i-1)
    {
        p=p->next;
        j++;
    }
    if(p==NULL)
    return false;
    if(p->next==NULL)
    return false;
    LNode *q=p->next;
    e=q->data;
    p->next=q->next;
    delete q;
    return true;
}
bool DeleteNode(LNode *p)//删除指定结点,若p为最后一个结点,则只能用从表头找前驱的方法
{
    if(p==NULL)
    return false;
    LNode *q=p->next;
    p->data=p->next->data;
    p->next=q->next;
    delete q;
    return true;
}
LNode *GetElem(LinkList L,int i)//按位查找
{
    if(i<0)
    return NULL;
    LNode *p;
    int j=0;
    p=L;
    while(p!=NULL&&j<i)
    {
        p=p->next;
        j++;
    }
    return p;
}
LNode *LocateElem(LinkList L,int e)//按值查找
{
    LNode *p=L->next;
    while(p!=NULL&&p->data!=e)
       p=p->next;
    return p;
}
int length(LinkList L)
{
    int len=0;
    LNode *p=L;
    while(p->next!=NULL)
    {
        p=p->next;
        len++;
    }
    return len;
}
LinkList List_TailInsert(LinkList &L)//尾插法
{
    int x;
    L=new LNode;
    LNode *r,*s=L;
    cin>>x;
    while(x!=9999)
    {
        s=new LNode;
        s->data=x;
        r->next=s;
        r=s;
        cin>>x;
    }
    r->next=NULL;
    return L;
}
LinkList List_HeadInsert(LinkList &L)//头插法
{
    LNode *s;
    int x;
    L=new LNode;
    L->next=NULL;
    cin>>x;
    while(x!=9999)
    {
        s=new LNode;
        s->data=x;
        s->next=L->next;
        L->next=s;
        cin>>x;
    }
    return L;
}