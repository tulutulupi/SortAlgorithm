#include<stdio.h>
#include<malloc.h>

//计数排序的时间复杂度为O(n),但是空间复杂度为O(n),其适合用于重复关键字多，且关键字极差小的的情况。

void countsort(int a[], int size){
    int min = a[0], max = a[0];
    for (int i = 0; i < size; i++)//找到最大和最小值
    {
        if(min > a[i]){
            min = a[i];
        }
        if(max < a[i]){
            max = a[i];
        }
    }
    int bsize = max - min + 1;//映射数组的大小
    
    // int *b = (int *)malloc((bsize)*sizeof(int));
    int b[bsize];//初始化新数组
    for(int j = 0; j < bsize; j++){
        b[j] = 0;
    }
    for (int i = 0; i < size; i++)//将原来的关键字作为下标映射到新数组中，
    {
        b[a[i]-min]++;//如果有相同的关键字，++
    }
    int index = 0;
    for (int i = 0; i < bsize; i++)//从小到大遍历存储数组，将存储的值重新赋回原数组
    {
        for(int k = 0; k < b[i]; k++){
            a[index++] = i + min;
        }
    }
}

int main(){
    int a[] = {5,5,3,-2,1,1,2,3,4,5,7,8,7,9,9,1,-2};
    int size = sizeof(a)/sizeof(int);
    countsort(a, size);
    for (int i = 0; i < size; i++)
    {
        printf("%d ",a[i]);
    }
    
    return 0;
}