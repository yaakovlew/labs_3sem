//
// Created by andre on 02.10.2021.
//

#ifndef LAB21_ALGORITHMS_H
#define LAB21_ALGORITHMS_H
#include <iostream>


template <typename T>
void BubbleSort(std::vector<T>& m, int p,  int n)
{
    for(int i = n - 1; i >= 1; i--)
        for(int j = 0; j < i; j++)
        {
            if(m[j] > m[j+1])
            {
                int foo = m[j];
                m[j] = m[j+1];
                m[j+1] = foo;
            }
        }
}

template <typename T>
void QuickSortCall(std::vector<T>& numbers, int left, int right)
{
    int pr;
    int l_h = left;
    int r_h = right;
    pr = numbers[left];
    while (left < right)
    {
        while ((numbers[right] >= pr) && (left < right))
            right--;
        if (left != right)
        {
            numbers[left] = numbers[right];
            left++;
        }
        while ((numbers[left] <= pr) && (left < right))
            left++;
        if (left != right)            {
            numbers[right] = numbers[left];
            right--;
        }
    }
    numbers[left] = pr;
    pr = left;
    left = l_h;
    right = r_h;
    if (left < pr)
        QuickSortCall(numbers, left, pr - 1);
    if (right > pr)
        QuickSortCall(numbers, pr + 1, right);
}

template <typename T>
void QuickSort(std::vector<T>& A, int first, int last){
    QuickSortCall(A, first, last - 1);
}



template <typename T>
void MergeCall(std::vector<T>& A, int first, int last) {
    int middle, start, final, j;
    int *mas = new int[100];
    middle = (first + last) / 2;
    start = first;
    final = middle + 1;
    for (j = first; j <= last; j++)
        if ((start <= middle) && ((final > last) || (A[start] < A[final]))) {
            mas[j] = A[start];
            start++;
        } else {
            mas[j] = A[final];
            final++;
        }
    for (j = first; j <= last; j++)
        A[j] = mas[j];
    delete[] mas;
}


template <typename T>
void MergeSort(std::vector<T>& A, int first, int last) {
    if (first < last) {
        MergeSort(A, first, (first + last) / 2);
        MergeSort(A, (first + last) / 2 + 1, last);
        MergeCall(A, first, last);
    }
}


template <typename T>
void Merge(std::vector<T>& A, int first, int last){
    MergeSort(A, first, last - 1);
}

template <typename T>
void CtrlV(std::vector<T>& arr, int p, int n){
    for(int i=1;i<n;i++){
        for(int j=i; j>0 && arr[j-1]>arr[j];j--){
            int tmp=arr[j-1];
            arr[j-1]=arr[j];
            arr[j]=tmp;
        }
    }
}


#endif //LAB21_ALGORITHMS_H
