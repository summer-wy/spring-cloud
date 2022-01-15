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
        return false; //栈满
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
    //初始化栈
    InitStack(S);
    //判断栈是否为空
    ret = isempty(S);
    if (ret)
    {
        printf("栈为空\n");
    }
    else
    {
        printf("栈不为空\n");
    }
    //入栈
    push(S, 3);
    push(S, 4);
    push(S, 5);
    //获取栈顶元素
    ret = GetTop(S, x);
    if (ret)
    {
        printf("栈顶元素为%d\n", x);
    }

    //出栈
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