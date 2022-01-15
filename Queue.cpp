#include <stdio.h>
#include <stdlib.h>
#define MaxSize 5
typedef int ElemType;
typedef struct Queue
{
    int data[MaxSize];
    int front, rear;
} Queue;
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
    if ((Q.rear+ 1) % MaxSize == Q.front)
    {
        return true;
    }
    return false;
}
bool EnQueue(Queue &Q, ElemType e)
{
    if (FullQueue(Q))
    {
        return false; //����
    }
    Q.data[Q.rear] = e;
    Q.rear = (Q.rear + 1) % MaxSize;
    return true;
}
bool DeQueue(Queue &Q, ElemType &e)
{
    if (isempty(Q))
    {
        return false; //�ӿ�
    }
    e = Q.data[Q.front];
    Q.front = (Q.front + 1) % MaxSize;
    return true;
}
int main()
{
    Queue Q;
    //���ӵ�Ԫ��
    ElemType e;
    bool ret;
    //��ʼ��ѭ������
    InitQueue(Q);
    //�ж϶����Ƿ�Ϊ��
    isempty(Q);
    //�ж϶����Ƿ�Ϊ��
    FullQueue(Q);
    //���
    EnQueue(Q, 3);
    //����
    ret = DeQueue(Q, e);
    if (ret)
    {
        printf("%2d", e);
    }
   
}