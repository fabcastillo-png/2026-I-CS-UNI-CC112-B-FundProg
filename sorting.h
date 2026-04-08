#ifndef __SORTING_H__
#define __SORTING_H__
#include <iostream>
#include "types.h"
#include <string>
 void DemoMergeSort();

void DemoSorting() ;

//#endif // __SORTING_H__// #include "compareFunc.h"
using namespace std;
using ContainerRange    = int;

template <typename Q, typename R> 
void Test(Q q, R r, string s, Q *pQ, R *pR){
    cout << q << " " << r << endl;
    cout << s << endl;
    cout << *pQ << " " << *pR << endl;
}

template <typename Q, typename R> 
auto suma(Q q, R r){
    return q + r;
}

template <typename T> 
void intercambiar(T& a, T& b){
    T temp = a;
    a = b;
    b = temp;
}

template <typename T> 
void PrintArray(T arr[], ContainerRange n){
    for (auto i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << endl;
}

// Bubble 
template <typename T, typename Func> 
void BurbujaClasico(T arr[], ContainerRange n, Func func) {
    if (n <= 1)
        return;
    for (auto i = 0; i < n - 1; ++i)
        for (auto j = i+1; j < n; ++j)
            if( func(arr[i], arr[j]) )
                intercambiar(arr[i], arr[j]);
}

// Bubble
template <typename T, typename Func> 
void BurbujaRecursivo(T arr[], ContainerRange n, Func func) {
    if (n <= 1)
        return;
    for (auto j = 1; j < n; ++j)
        if ( func(arr[j], arr[0]) )
            intercambiar(arr[0], arr[j]);
    BurbujaRecursivo(arr+1, n-1, func);
}
void DemoBurbuja();


// ContainerRange  particionar(ContainerElemType1* arr, ContainerRange first, ContainerRange last, CompFunc pComp);
// void QuickSort  (ContainerElemType1* arr, ContainerRange first, ContainerRange last, CompFunc pComp);  

//void DemonQuickStor();
// --- MERGE SORT ---
template <typename T, typename Func>
void merge(T arr[], ContainerRange l, ContainerRange m, ContainerRange r, Func func) {
    ContainerRange n1 = m - l + 1;
    ContainerRange n2 = r - m;
    T* L = new T[n1];
    T* R = new T[n2];

    for (ContainerRange i = 0; i < n1; i++) L[i] = arr[l + i];
    for (ContainerRange j = 0; j < n2; j++) R[j] = arr[m + 1 + j];

    ContainerRange i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (func(L[i], R[j])) { arr[k] = L[i]; i++; }
        else { arr[k] = R[j]; j++; }
        k++;
    }
    while (i < n1) { arr[k] = L[i]; i++; k++; }
    while (j < n2) { arr[k] = R[j]; j++; k++; }
    delete[] L; delete[] R;
}

template <typename T, typename Func>
void MergeSort(T arr[], ContainerRange l, ContainerRange r, Func func) {
    if (l < r) {
        ContainerRange m = l + (r - l) / 2;
        MergeSort(arr, l, m, func);
        MergeSort(arr, m + 1, r, func);
        merge(arr, l, m, r, func);
    }
}

// --- QUICK SORT ---
template <typename T, typename Func>
void QuickSort(T arr[], ContainerRange low, ContainerRange high, Func func) {
    if (low < high) {
        T pivot = arr[high];
        ContainerRange i = (low - 1);
        for (ContainerRange j = low; j <= high - 1; j++) {
            if (func(arr[j], pivot)) {
                i++;
                intercambiar(arr[i], arr[j]);
            }
        }
        intercambiar(arr[i + 1], arr[high]);
        ContainerRange pi = i + 1;
        QuickSort(arr, low, pi - 1, func);
        QuickSort(arr, pi + 1, high, func);
    }
}
#endif
// void Merge(ContainerElemType1* arr, const ContainerRange left, const ContainerRange mid, const ContainerRange right, CompFunc pComp); 
// void MergeSort(ContainerElemType1* arr, const ContainerRange begin, const ContainerRange end, CompFunc pComp);
//