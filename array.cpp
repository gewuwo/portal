#include <iostream>
#include <cstring>

using namespace std;

typedef struct
{
    int *data;
    int MaxSize, length;
} SqList;

void Expand(SqList &L, int ex)
{
    int *p = L.data;
    L.data = new int[L.length + ex];
    for (int i = 0; i < L.length; i++)
    {
        p[i] = L.data[i];
    }
    delete[] p;
    cout << "complete" << endl;
}

/**
 * 初始化表，构造一个空的线性表
 */
void InitList(SqList &L, int initSize)
{
    L.data = new int[initSize];
    L.MaxSize = initSize;
    L.length = 0;
}

void Length(SqList L)
{
    cout << L.length << endl;
}

void LocateElem(SqList L, int e)
{
    for (int i = 0; i < L.length; i++)
    {
        if (L.data[i] == e)
        {
            cout << i;
            return;
        }
    }
    cout << "not found" << endl;
}

void GetElem(SqList L, int i)
{
    if (i < 1 || i > L.length)
    {
        cout << "超出界限" << endl;
        return;
    }
    cout << L.data[i - 1] << endl;
}

void add(SqList &L, int e)
{
    if (L.length == L.MaxSize)
    {
        Expand(L, 5);
    }
    L.data[L.length] = e;
    L.length++;
}

void ListInsert(SqList &L, int i, int e)
{
    if (i < 1 || i > L.length + 1)
    {
        cout << "超出界限" << endl;
        return;
    }
    if (L.length >= L.MaxSize)
    {
        Expand(L, 5);
    }
    for (int j = L.length; j >= i; j--)
    {
        L.data[j] = L.data[j - 1];
    }
    L.data[i - 1] = e;
    L.length++;
    cout << "complete" << endl;
}

bool Empty(SqList L)
{
    if (L.length == 0)
    {
        return true;
    }
    return false;
}

void ListDelete(SqList &L, int i, int &e)
{
    if (Empty(L))
    {
        cout << "顺序表为空" << endl;
        return;
    }
    e = L.data[i - 1];
    for (int j = i; j <= L.length; j++)
    {
        L.data[j - 1] = L.data[j];
    }
    L.length--;
}

void PrintList(SqList L)
{
    for (int i = 0; i < L.length; i++)
    {
        cout << L.data[i] << " ";
    }
    cout << endl;
}

void Destroy(SqList &L)
{
    delete[] L.data;
    L.length = 0;
    L.MaxSize = 0;
    cout << "complete" << endl;
}

void DeleteSmallest(SqList &L)
{
    if (Empty(L))
    {
        cout << "SqList is NULL!" << endl;
        return;
    }
    int a = L.data[0];
    int id = 0;
    int *pid = &id;
    for (int i = 0; i < L.length; ++i)
    {
        if (a > L.data[i])
        {
            *pid = i;
            a = L.data[i];
        }
    }
    L.data[id] = L.data[L.length - 1];
    L.length--;
    cout << a << "delete" << endl;
}

void Turn(SqList &L)
{
    if (Empty(L))
    {
        cout << "SqList is NULL!" << endl;
        return;
    }
    int i = 0;
    int j = L.length - 1;
    while (i < j)
    {
        swap(L.data[i], L.data[j]);
        i++;
        j--;
    }
}

void DeleteX(SqList &L, int x)
{
    if (Empty(L))
    {
        cout << "SqList is NULL!" << endl;
        return;
    }
    int k = 0;
    int *pk = &k;
    for (int i = 0; i < L.length; i++)
    {
        if (L.data[i] == x)
        {
            *pk += 1;
        }
        else
        {
            L.data[i - *pk] = L.data[i];
        }
    }
    L.length = L.length - *pk;
}

void inXAndY(SqList &L, int x, int y)
{
    if (Empty(L))
    {
        cout << "SqList is Empty!" << endl;
        return;
    }
    if (x > y)
    {
        swap(x, y);
    }
    int k = 0;
    int *pk = &k;
    for (int i = 0; i < L.length; i++)
    {
        if (L.data[i] >= x && L.data[i] <= y)
        {
            *pk += 1;
        }
        else
        {
            L.data[i - k] = L.data[i];
        }
    }
    L.length = L.length - *pk;
}

void Unique(SqList &L)
{
    int *p = L.data;
    L.data = new int[L.MaxSize];
    bool *flag = new bool[100];
    int j = 0;
    memset(flag, false, 10);
    for (int i = 0; i < L.length; i++)
    {
        if (!flag[p[i]])
        {
            L.data[j] = p[i];
            flag[p[i]] = true;
            j++;
        }
    }
    L.length = j;
    delete[] p;
}

void Merge(SqList &L, SqList &R)
{
    while (L.MaxSize < R.length)
    {
        Expand(L, R.length);
    }
    int *p = L.data;
    int i = 0, j = 0, id = 0;
    while (i < L.length && j < R.length)
    {
        if (p[i] <= R.data[j])
        {
            L.data[id] = p[i];
            i++;
        }
        else
        {
            L.data[id] = R.data[j];
            j++;
        }
        id++;
    }
    if (i < L.length)
    {
        for (; i < L.length; i++, id++)
        {
            L.data[id] = p[i];
        }
    }
    if (j < R.length)
    {
        for (; j < R.length; j++, id++)
        {
            L.data[id] = R.data[j];
        }
    }
    L.length = R.length + L.length;
}

void TurnInArray(SqList &L, int m)
{
    int *p = L.data;
    L.data = new int[L.MaxSize];
    int j = 0;
    for (int i = m; i < L.length; ++i, j++)
    {
        L.data[j] = p[i];
    }
    for (int i = 0; i < m; i++, j++)
    {
        L.data[j] = p[i];
    }
}

void SearchInDouble(SqList &L, int x)
{
    int left = 0;
    int right = L.length - 1;
    int m;
    while (left < right)
    {
        m = (left + right) / 2;
        if (L.data[m] < x)
        {
            left = m + 1;
        }
        else if (L.data[m] > x)
        {
            right = m - 1;
        }
        else
        {
            swap(L.data[m], L.data[m + 1]);
            return;
        }
    }
    ListInsert(L, left + 2, x);
}

int main()
{
    SqList L;
    int initSize = 10;
    int show = 0;
    InitList(L, initSize);

    add(L, 1);
    add(L, 2);
    add(L, 3);
    add(L, 4);

    cout << L.length << endl;
    PrintList(L);
}
