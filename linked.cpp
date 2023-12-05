//
// Created by PrimeChuJiang on 2022/11/12.
//
#include <iostream>

using namespace std;

typedef struct LNode
{
    int data;
    struct LNode *ptr;
} LNode, *LinkList;

bool InitList(LinkList &L)
{
    //    LNode a ;
    L = new LNode;
    if (L == nullptr)
        return false;
    L->ptr = nullptr;
    return true;
}

int Length(LinkList L)
{
    LNode *p = L;
    int i = 0;
    for (; p->ptr != nullptr; p = p->ptr)
    {
        i++;
    }
    return i;
}

LNode *LocateElem(LinkList L, int e)
{
    LNode *p = L;
    while (p->ptr != nullptr)
    {
        if (p->data == e)
        {
            return p;
        }
        else
        {
            continue;
        }
    }
    return nullptr;
}

LNode *GetElem(LinkList L, int i)
{
    LNode *p = L->ptr;
    if (i == 0)
    {
        return L;
    }
    if (i < 0)
        return nullptr;
    for (int j = 1; j < i && p; ++j)
    {
        p = p->ptr;
    }
    return p;
}

void ListInsert(LinkList &L, int i, int e)
{
    LNode *p = GetElem(L, i);
    auto s = new LNode;
    s->data = p->data;
    s->ptr = p->ptr;
    p->ptr = s;
    p->data = e;
}

bool ListDelete(LinkList &L, int i, int &e)
{
    LNode *p = GetElem(L, i - 1);
    LNode *d = p->ptr;
    p->ptr = d->ptr;
    delete d;
    return true;
}

void PrintList(LinkList L)
{
    //    LNode *p = L;
    for (LNode *p = L->ptr; p != nullptr; p = p->ptr)
    {
        cout << p->data;
    }
}

bool Empty(LinkList L)
{
    return L->ptr == nullptr;
}

void DestroyList(LinkList &L)
{
    if (!L->ptr)
    {
        delete L;
        return;
    }
    LNode *p = L->ptr;
    LNode *d = L;
    while (p->ptr)
    {
        delete d;
        d = p;
        p = p->ptr;
    }
    delete d;
    delete p;
}

LinkList List_HeadInsert(LinkList &L, int e)
{
    auto *p = new LNode;
    p->data = e;
    p->ptr = L->ptr;
    L->ptr = p;
    return L;
}

LinkList List_TailInsert(LinkList &L, int e)
{
    auto *p = new LNode;
    for (; p->ptr != nullptr; p = p->ptr)
    {
    }
    auto *s = new LNode;
    s->data = e;
    p->ptr = s;
    s->ptr = nullptr;
    return L;
}

int main()
{
    LinkList L;
    InitList(L);
    cout << "a" << endl;
}
