#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void HeadAdjust(int a[], int k, int len){
    a[0] = a[k];
    for(int i = 2*k; i <= len; i *= 2){
        if(i<len&&a[i]<a[i+1]){//比较两个子节点的大小，让i指向最大的那个节点
            i++;
        }
        if(a[0]>=a[i]){//如果待排序节点比大的子节点还大，那么循环结束，k所指向的位置为该数应在的位置
            break;
        }else{
            a[k] = a[i];//如果待排序节点比大的节点小，那么需要换节点，而后再次循环检查新的位置是否符合要求
            k = i;
        }
    }
    a[k] = a[0];//将待排序节点赋值到正确的位置。
}
void buildHeap(int a[], int len){//建堆，从最后的非叶子节点开始不断调整
    for(int i = len/2; i>0; i--){
        HeadAdjust(a, i, len);
    }
}
void heapsort(int *a,int size)
{   
    buildHeap(a,size-1);

    for(int i = size-1; i > 0; i--){//堆排序的过程就是将末尾元素和堆顶元素互换，然后开始调整，这样每次就可以确定一个元素应该在的位置。
        int temp = a[i];
        a[i] = a[1];
        a[1] = temp;
        HeadAdjust(a, 1, i-1);
    }
}

int main()
{
    int a[] = {-1, 1, 9, 2, 7, 3, 4, 6, 5, 0, 8};//使用第一个元素为空的数组，使得下标从1开始，这样方便计算子节点的位置
    int size = sizeof(a)/sizeof(int);
    heapsort(a,size);
    for(int i = 0; i < size; i++){
        printf("%d", a[i]);
    }

    return 0;
}