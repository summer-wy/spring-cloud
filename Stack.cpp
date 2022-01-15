#include <stdio.h>
#include <stdlib.h>

#define MaxSize 50
typedef int ElemType;
typedef struct
{
    ElemType data[MaxSize];
    ElemType top;
} Stack;
void InitStack(Stack &S)
{

    S.top = -1;
}
bool isempty(Stack S)
{
    if (S.top == -1)
    {
        return true;
    }
    return false;
}
bool push(Stack &S, ElemType e)
{
    if (S.top == MaxSize - 1)
    {
        return false; //ջ��
    }
    S.data[++S.top] = e;
    return true;
}
bool GetTop(Stack S, ElemType &x)
{
    if (isempty(S))
    {
        return false;
    }
    x = S.data[S.top];
    return true;

    return true;
}
bool pop(Stack &S, ElemType &x)
{
    if (isempty(S))
    {
        return false;
    }
    x = S.data[S.top--];
    return true;
}
int main()
{
    Stack S;
    bool ret;
    ElemType x;
    //��ʼ��ջ
    InitStack(S);
    //�ж�ջ�Ƿ�Ϊ��
    ret = isempty(S);
    if (ret)
    {
        printf("ջΪ��\n");
    }
    else
    {
        printf("ջ��Ϊ��\n");
    }
    //��ջ
    push(S, 3);
    push(S, 4);
    push(S, 5);
    //��ȡջ��Ԫ��
    ret = GetTop(S, x);
    if (ret)
    {
        printf("ջ��Ԫ��Ϊ%d\n", x);
    }

    //��ջ
    ret = pop(S, x);
    if (ret)
    {
            printf("%2d", x);
    }
     ret = pop(S, x);
    if (ret)
    {
            printf("%2d", x);
    }
     ret = pop(S, x);
    if (ret)
    {
            printf("%2d", x);
    }
}