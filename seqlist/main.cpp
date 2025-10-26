#include<iostream>
using namespace std;
#define InitSize 10//动态分配
typedef struct
{
      int *data;
      int MaxSize;
      int length;
}SeqList;//key:动态申请和释放内存空间 malloc(申请一整片连续空间) free  
void InitList(SeqList &L)
{
   L.data=(int *)malloc(InitSize*sizeof(int));//L.data=new int[Initsize];
   L.length=0;
   L.MaxSize=InitSize;
}
void IncreaseSize(SeqList &L,int len)
{
  int *p=L.data;//复制原来数据
  L.data=new int[InitSize+len];
  for(int i=0;i<L.length;i++)
  {
    L.data[i]=p[i];//将数据分配到新区域
  }
  L.MaxSize=L.MaxSize+len;
  delete []p;
}
int GetPositionElem(SeqList L,int i)
{
  if(i<1||i>L.length)
  {
    return false;
  }
  return L.data[i-1]; 
}
int main()
{
    SeqList L;
    InitList(L);
    IncreaseSize(L,5);
    return 0;
}