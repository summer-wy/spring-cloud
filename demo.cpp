#include <stdio.h>
#include <stdlib.h>

#define MaxSize 50
typedef int ElemType;
typedef struct
{
    ElemType data[MaxSize];
    ElemType top;
} Stack;
typedef struct Queue
{
    int data[5];
    int front, rear;
} Queue;
void InitStack(Stack &S)
{

    S.top = -1;
}
bool push(Stack &S, ElemType e)
{
    if (S.top == MaxSize - 1)
    {
        return false; //栈满
    }
    S.data[++S.top] = e;
    return true;
}
bool pop(Stack &S, ElemType &x)
{
    if (S.top==-1)
    {
        return false;
    }
    x = S.data[S.top--];
    return true;
}
void InitQueue(Queue &Q)
{
    Q.front = Q.rear = 0;
}
bool isempty(Queue Q)
{
    if (Q.front == Q.rear)
    {
        return true;
    }
    return false;
}
bool FullQueue(Queue Q)
{
    if ((Q.rear+ 1) % 5 == Q.front)
    {
        return true;
    }
    return false;
}
bool EnQueue(Queue &Q, ElemType e)
{
    if (FullQueue(Q))
    {
        return false; //队满
    }
    Q.data[Q.rear] = e;
    Q.rear = (Q.rear + 1) % 5;
    return true;
}
bool DeQueue(Queue &Q, ElemType &e)
{
    if (isempty(Q))
    {
        return false; //队空
    }
    e = Q.data[Q.front];
    Q.front = (Q.front + 1) % 5;
    return true;
}
int main()
{
    Stack S;
    bool ret1;
    ElemType x;
    int num;
    //初始化栈
    InitStack(S);
 
    //入栈
    for (int  i = 0; i < 3; i++)
    {
        scanf("%d",&num);
        push(S,num);
    }
    
    //出栈
    for (int i = 0; i < 3; i++)
    {
         pop(S, x);
         printf("%2d",x);
    }
    
   printf("\n");
   
  Queue Q;
    //出队的元素
    ElemType e;
    bool ret;
    //初始化循环队列
    InitQueue(Q);
    //入队
    for (int i = 0; i < 5; i++)
    {
       scanf("%d",&num);
        ret=EnQueue(Q, num);
        if (!ret)
        {
          printf("false");
          printf("\n");
        }
        
    } 
    //出队
    for (int i = 0; i < 4; i++)
    {
         DeQueue(Q, e);
         printf("%2d",e);
    }
}