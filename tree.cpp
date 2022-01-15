#include <stdio.h>
#include <stdlib.h>
typedef char BiElemType;
//���������ݽṹ
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
//�������ݽṹ
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
    { //ɾ���������һ��Ԫ�أ�������Ϊ��
        L.rear = L.front;
    }
    free(p);
    return true;
}
void LevelOrder(BiTree T)
{
    LinkQueue Q;      //��������
    InitLinkQueue(Q); //��ʼ������
    BiTree p;
    EnQueue(Q, T); //�������
    while (!isLinkQueueempty(Q))
    {
        DeQueue(Q, p); //���ӵ�ǰ��㲢��ӡ
        putchar(p->data);
        if (p->lchild != NULL) //�������
            EnQueue(Q, p->lchild);
        if (p->rchild != NULL) //����Һ���
            EnQueue(Q, p->rchild);
    }
}
int main()
{
    BiTree tree = NULL; //����
    BiTree pnew;
    ptag_t phead = NULL, ptail = NULL, pcur, listpnew; //���ף���βָ��
    char c;
    while (scanf("%c", &c) != EOF)
    {
        if (c == '\n')
        {
            break;
        }
        //���������µĽڵ�
        pnew = (BiTree)calloc(1, sizeof(BiTNode));
        //�����ݷ���ڵ���
        pnew->data = c;
        //�����������µĽڵ�
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
            //�������
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
    //ǰ�����
    preOrder(tree);
    printf("\n");
    //�������
    midOrder(tree);
    printf("\n");
    //�������
    posOrder(tree);
    printf("\n");
    //��α���
    LevelOrder(tree);
    printf("\n");
}
