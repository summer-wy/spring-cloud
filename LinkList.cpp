#include <stdio.h>
#include <stdlib.h>
typedef int ElemType;
typedef struct LNode
{
    ElemType data;
    struct LNode *next;
} LNode, *LinkList;
LinkList CreatLinkList(LinkList &L)
{
    L = (LinkList)malloc(sizeof(LNode));
    LinkList s, r = L;
    ElemType x;
    scanf("%d", &x);
    while (x != 9999)
    {
        s = (LNode *)malloc(sizeof(LNode));
        s->data = x;
        r->next = s;
        r = s;
        scanf("%d", &x);
    }
    r->next = NULL;
    return L;
}
LinkList CreatLinkList1(LinkList &L){
L=(LinkList)calloc(1,sizeof(LNode));
ElemType x;
    scanf("%d", &x);
    while (x!=9999)
    {
        LinkList s=(LinkList)calloc(1,sizeof(LNode));
        s->data=x;
        s->next=L->next;
        L->next=s;
        scanf("%d",&x);
    }
    return L;
    
}
LinkList GetLocaLinkList(LinkList L, ElemType i)
{
    int j = 1;
    LinkList p = L->next; //指向第一个节点
    if (i == 0)
    {
        return L;
    }
    if (i < 1)
    {
        return NULL;
    }
   while (p && j < i)
    {
        p = p->next;
        j++;
    }

    return p;
}
LinkList FromtInsertLinkList(LinkList L, ElemType i, ElemType e)
{

    LinkList r = GetLocaLinkList(L, i - 1);
    if (r == NULL)
    {
        return NULL;
    }

    LinkList s = (LinkList)malloc(sizeof(LNode));
    s->data = e;
    s->next = r->next;
    r->next = s;
    return L;
}
bool FromDelLinkList(LinkList L,ElemType i){
    LinkList r=GetLocaLinkList(L,i-1);
    if (r==NULL)
    {
        return false;
    }
    LinkList p=r->next;
    if (p==NULL)
    {
        return false;
    }
    r->next=p->next;
    free(p);
    p=NULL;
    return true;
}
void PrintLinkList(LinkList L)
{
    L = L->next;
    while (L != NULL)
    {
        printf("%3d", L->data);
        L = L->next;
    }
    printf("\n");
}
int main()
{
    LinkList L;
    LinkList s;
    // //尾插法创建链表
    // CreatLinkList(L);
    //头插法创建链表
    CreatLinkList1(L);
    // //查找第i个位置的元素
    // s = GetLocaLinkList(L, 2);
    // printf("%3d\n", s->data);
    // // //在第i个位置插入元素
    // FromtInsertLinkList(L, 2, 99);
    // PrintLinkList(L);
    // // //在第i个位置删除元素
    // FromDelLinkList(L,4);
     PrintLinkList(L);
}