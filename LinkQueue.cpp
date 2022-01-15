#include <stdio.h>
#include <stdlib.h>
typedef int ELemType;
typedef struct LinkNode
{
    ELemType data;
    LinkNode *next;
} LinkNode;
typedef struct
{
    struct LinkNode *front, *rear;

} LinkQueue;

bool isLinkQueueempty(LinkQueue L)
{
    if (L.front == L.rear)
    {
        return true;
    }
    return false;
}
void EnQueue(LinkQueue &L, ELemType e)
{
    LinkNode *p = (LinkNode *)calloc(1, sizeof(LinkNode));
    p->data = e;
    L.rear->next = p;
    L.rear = p;
}
void InitLinkQueue(LinkQueue &L)
{
    L.front = L.rear = (LinkNode *)calloc(1, sizeof(LinkNode));
}
bool DeQueue(LinkQueue &L, ELemType &x)
{
    if (isLinkQueueempty(L))
    {
        return false;
    }
    LinkNode *p = L.front->next;
    x = p->data;
    L.front->next = p->next;
    if (L.rear == p)
    { //ɾ���������һ��Ԫ�أ�������Ϊ��
        L.front = L.rear;
    }
    free(p);
    return true;
}
int main()
{
    LinkQueue L;
    ELemType i;
    bool ret;
    //��ʼ������
    InitLinkQueue(L);
    //�ж϶����Ƿ�Ϊ��
    isLinkQueueempty(L);
    //��ӣ�β�巨
    EnQueue(L, 1);
    EnQueue(L, 2);
    EnQueue(L, 3);
    EnQueue(L, 4);
    //���ӣ�ͷ��ɾ����
    ret = DeQueue(L, i);
    if (ret)
    {
        printf("����Ԫ��Ϊ%d", i);
    }
}