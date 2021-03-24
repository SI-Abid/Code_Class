#include "bits/stdc++.h"
using namespace std;

void insertion_sort(int *, int);
void merge_sort(int *, int);
void merge(int *, int *, int *, int, int, int);
void quick_sort(int *, int, int);
int divide(int *, int, int);
void SWAP(int *, int *);
void _terminate();

int main()
{
    int *ar, size, des;
    string opt = "Press 1: Insertion Sort\nPress 2: Merge Sort\nPress 3: Quick Sort\nPress 4: Exit\nChoose your option: ";
    cout << "Enter Array Size: ";
    cin >> size;
    ar = new int[size];
    for (int i = 0; i < size; i++)
    {
        cin >> ar[i];
    }
    while (true)
    {
        /////
        int b[size];
        for (int i = 0; i < size; i++)
        {
            b[i] = ar[i];
        }
        /////
        cout << opt;
        cin >> des;
        switch (des)
        {
        case 1:
            insertion_sort(b, size);
            cout << "According to Insertion Sort, sorted data is: ";
            break;
        case 2:
            merge_sort(b, size);
            cout << "According to Merge Sort, sorted data is: ";
            break;
        case 3:
            quick_sort(b, 0, size);
            cout << "According to Quick Sort, sorted data is: ";
            break;
        case 4:
            _terminate();
            break;
        default:
            break;
        }
        for (int i = 0; i < size; i++)
        {
            cout << b[i] << " ";
        }
        cout << endl;
    }
    return 0;
}

void insertion_sort(int *b, int n)
{
    for (int i = 1; i < n; i++)
    {
        int tmp = b[i];
        int pos = i;
        while (pos > 0 && b[pos - 1] > tmp)
        {
            b[pos] = b[pos - 1];
            pos--;
        }
        b[pos] = tmp;
    }
}

void merge(int *l, int *r, int *b, int nl, int nr, int nb)
{
    int i, j, k;
    i = j = k = 0;
    while (i < nl && j < nr)
    {
        if (l[i] <= r[j])
            b[k++] = l[i++];

        else
            b[k++] = r[j++];
    }
    while (i < nl)
        b[k++] = l[i++];

    while (j < nr)
        b[k++] = r[j++];
}

void merge_sort(int *a, int n)
{
    if (n < 2)
        return;

    int mid = n / 2;
    int left[mid], right[n - mid];
    for (int i = 0; i < mid; i++)
        left[i] = a[i];

    for (int i = mid, j = 0; i < n; i++, j++)
        right[j] = a[i];

    merge_sort(left, mid);
    merge_sort(right, n - mid);
    merge(left, right, a, mid, n - mid, n);
}

void quick_sort(int *ar, int left, int right)
{
    if (left < right)
    {
        int mid = divide(ar, left, right);
        quick_sort(ar, left, mid - 1);
        quick_sort(ar, mid + 1, right);
    }
}

int divide(int *a, int l, int r)
{
    int piv, i, j;
    piv = a[l];
    i = l;
    j = r;
    while (i < j)
    {
        while (a[i] <= piv && i <= r)
        {
            i++;
        }
        while (a[j] > piv)
        {
            j--;
        }
        if (i < j)
        {
            SWAP(&a[i], &a[j]);
        }
    }
    SWAP(&a[l], &a[j]);
    return j;
}

void _terminate()
{
    cout << "Program terminated." << endl;
    exit(1);
}
void SWAP(int *x, int *y)
{
    int t = *x;
    *x = *y;
    *y = t;
}