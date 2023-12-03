#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int temp[20];

const int optSize = 4;

void insert_sort(int *list, int l, int r);
void merge(int *list, int l, int r);
void merge_sort(int *list, int l, int mid, int r);

int main(){
    int a[] = {1, 9, 2, 7, 3, 4, 6, 5, 0, 8, 11, 10, 88, 99, 77, 44, 32};
    int size = sizeof(a)/sizeof(int);
    merge(a, 0, size);
    for(int i = 0; i < size; i++){
        printf("%d ", a[i]);
    }
    return 0;
}
void insert_sort(int *list, int l, int r){
    cout<<"进入插入排序"<<endl;
    int j;
    for(int i = l+1; i < r; i++){
        if(list[i-1] > list[i]){
            int temp = list[i];
            for(j= i - 1; list[j] > temp; j--){
                list[j+1] = list[j];
            }
            list[j+1] = temp;
        }
    }
}
void merge(int *list, int l, int r){
    if(l < r){
        if(r - l > optSize){
            int mid = (l + r) / 2;
            merge(list, l, mid);
            merge(list, mid, r);
            merge_sort(list, l, mid, r);
        }else{
            insert_sort(list, l, r);
        }
    }
}
void merge_sort(int *list, int l, int mid, int r){
    int i = l, j = mid, k = 0;
    while (i < mid && j < r)
    {
        if(list[i] < list[j]){
            temp[k++] = list[i++];
        }else{
            temp[k++] = list[j++];
        }
    }
    while(i < mid){
        temp[k++] = list[i++];
    }
    while(j < r){
        temp[k++] = list[j++];
    }
    for(int t = 0; t < k; t++){
        list[l+t] = temp[t];
    }
    
}