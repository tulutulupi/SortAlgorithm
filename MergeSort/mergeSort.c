#include <stdio.h>
#include<malloc.h>

void mergesort(int *a,int low,int high);
void merge(int *a, int *b, int low, int mid, int high);

int main(void)
{
    int a[] = {1, 9, 2, 7, 3, 4, 6, 5, 0, 8};
    int size = sizeof(a)/sizeof(int);
    mergesort(a, 0, size-1);
    for(int i = 0; i < size; i++){
        printf("%d", a[i]);
    }

    return 0;
}

void mergesort(int *a,int low,int high){
    int *b = (int *)malloc((high+1)*sizeof(int));//申请一个和原来数组一样大的新内存空间，所以算法空间复杂度为O(n)
    if(low < high){//如果满足该条件，则不断的分割数组
        int mid = (low + high) / 2;
        mergesort(a, low, mid);//向下递归分组，此处是时间复杂度O(nlog(n))的原因之一
        mergesort(a, mid + 1, high);
        merge(a, b, low, mid, high);//将low和high所夹的数组进行
        
        //归并操作
    }
}
void merge(int *a,int *b, int low, int mid, int high){//每趟归并排序的时间复杂度为O(n),是时间复杂度O(nlog(n))的原因之一
    int k;
    for (k = low; k <= high; k++){//先将两个归并段都复制到新空间上
        b[k] = a[k];
    }
    int i = low;//第一个归并段的起始位置
    int j = mid + 1;//第二个归并段的起始位置
    for (k = i; i <= mid && j <= high; k++){
        if(b[i] < b[j]){//从两个归并段中挑选最小的元素赋值回原来的数组
            a[k] = b[i];
            i++;
        }else{
            a[k] = b[j];
            j++;
        }
    }
    while(i <= mid){//如果其中一个归并段提前结束而跳出for循环，则直接将未完归并段直接赋值到原来位置即可
        a[k++] = b[i++];
    }
    while(j <= high){
        a[k++] = b[j++];
    }
}