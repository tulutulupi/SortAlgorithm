#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void insertionSort1(int *a,int size){
    int i=0,j=0,temp=0;
    // 从 第二个元素开始看起，每一个循环增加一个新元素到数组
    for(i=1;i<size;i++){
        if(a[i-1]>a[i]){
            temp = a[i];
            for(j = i-1;a[j]>temp;j--){
                a[j+1] = a[j];
            }
            a[j+1] = temp;
        }
    }
}
int main()
{
    int a[] = {1, 9, 2, 7, 3, 4, 5, 6, 0, 8};
    int size = sizeof(a) / sizeof(int);
    insertionSort1(a, size);
    for (int i = 0; i < size; i++)
    {
        printf("%d\n", a[i]);
    }

    return 0;
}