#include<iostream>
using namespace std;
#define MaxSize 10
typedef struct{
    int data[MaxSize];
    int top;
}SqStack;
void InitStack(SqStack &S){
    S.top=-1;
}
bool Push(SqStack &S,int x)
{
    if(S.top==MaxSize-1)
    return false;
    S.top=S.top+1;
    S.data[S.top]=x;
    return true;//S.data[++S.top]=x;
}
bool Pop(SqStack &S,int &x)
{
    if(S.top==-1)
    return false;
    x=S.data[S.top];
    S.top=S.top-1;
    return true;
}