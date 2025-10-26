#include<iostream>
using namespace std;
#define MaxSize 10//静态分配顺序表
typedef struct{
  int data[MaxSize];
  int length;
}SqList;

void InitList(SqList &L)
{
    for(int i=0;i<MaxSize;i++)
    {
        L.data[i]=0;
    }
    L.length=0;
}
bool InsertSqlist(SqList &L,int Position,int n)//position是位序,从1开始,所以在下标为Position-1的地方插入
{
    if(Position<1||Position>L.length+1)
    {
        return false;
    }
    if(L.length>=MaxSize)
    {
        return false;
    }
   for(int j=L.length;j>=Position;j--)
    {
    L.data[j]=L.data[j-1];
    L.data[Position-1]=n;
    L.length++;
    return true;
   }
}
bool DeleteList(SqList &L,int i,int &e)//用e把删除的元素返回
{
    if(i<1||i>L.length)
    {
        return false;
    }
    e=L.data[i-1];
    for(int j=i;j<L.length;j++)
    {
        L.data[j-1]=L.data[j];
    }
    L.length--;
    return true;
}   
int GetPositionElem(SqList L,int i)//按位置查找
{
    if(i<1||i>L.length)
    {
        return false;
    }
    return L.data[i-1];
}
int LocateElem(SqList L,int e)//按值查找
{
  for(int i=0;i<L.length;i++)
  {
    if(L.data[i]==e)
    {
        return i+1;
    }
  } 
}
int main()
{
    SqList L;
    InitList(L);
    InsertSqlist(L,3,3);
    return 0;
}