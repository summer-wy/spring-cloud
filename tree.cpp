#include <stdio.h>
#include <stdlib.h>
typedef char BiElemType;
//二叉树数据结构
typedef struct BiTNode
{
    BiElemType data;
    BiTNode *lchild;
    BiTNode *rchild;
} BiTNode, *BiTree;
typedef struct tag
{
    BiTree p;
    struct tag *pnext;
} tag_t, *ptag_t;
typedef BiTree ELemType;
//队列数据结构
typedef struct LinkNode
{
    ELemType data;
    LinkNode *next;
} LinkNode;
typedef struct
{
    struct LinkNode *front, *rear;

} LinkQueue;
void preOrder(BiTree tree)
{
    if (tree != NULL)
    {
        putchar(tree->data);
        preOrder(tree->lchild);
        preOrder(tree->rchild);
    }
}
void midOrder(BiTree tree)
{
    if (tree != NULL)
    {

        midOrder(tree->lchild);
        putchar(tree->data);
        midOrder(tree->rchild);
    }
}
void posOrder(BiTree tree)
{
    if (tree != NULL)
    {

        posOrder(tree->lchild);
        posOrder(tree->rchild);
        putchar(tree->data);
    }
}
void InitLinkQueue(LinkQueue &L)
{
    L.front = L.rear = (LinkNode *)calloc(1,sizeof(LinkNode));
    
}
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
    { //删除的是最后一个元素，队列置为空
        L.rear = L.front;
    }
    free(p);
    return true;
}
void LevelOrder(BiTree T)
{
    LinkQueue Q;      //辅助队列
    InitLinkQueue(Q); //初始化队列
    BiTree p;
    EnQueue(Q, T); //树根入队
    while (!isLinkQueueempty(Q))
    {
        DeQueue(Q, p); //出队当前结点并打印
        putchar(p->data);
        if (p->lchild != NULL) //入队左孩子
            EnQueue(Q, p->lchild);
        if (p->rchild != NULL) //入队右孩子
            EnQueue(Q, p->rchild);
    }
}
int main()
{
    BiTree tree = NULL; //树根
    BiTree pnew;
    ptag_t phead = NULL, ptail = NULL, pcur, listpnew; //队首，队尾指针
    char c;
    while (scanf("%c", &c) != EOF)
    {
        if (c == '\n')
        {
            break;
        }
        //给树申请新的节点
        pnew = (BiTree)calloc(1, sizeof(BiTNode));
        //把数据放入节点中
        pnew->data = c;
        //给队列申请新的节点
        listpnew = (ptag_t)calloc(1, sizeof(tag_t));
        listpnew->p = pnew;
        if (tree == NULL)
        {
            tree = pnew;
            phead = listpnew;
            ptail = listpnew;
            pcur = listpnew;
            continue;
        }
        else
        {
            //数据入队
            ptail->pnext = listpnew;
            ptail = listpnew;
        }
        if (pcur->p->lchild == NULL)
        {
            pcur->p->lchild = pnew;
        }
        else if (pcur->p->rchild == NULL)
        {
            pcur->p->rchild = pnew;
            pcur = pcur->pnext;
        }
    }
    //前序遍历
    preOrder(tree);
    printf("\n");
    //中序遍历
    midOrder(tree);
    printf("\n");
    //后序遍历
    posOrder(tree);
    printf("\n");
    //层次遍历
    LevelOrder(tree);
    printf("\n");
}
