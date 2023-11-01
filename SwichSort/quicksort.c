#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void quick_sort(int num[], int low, int high )
{
    int i,j,temp;
    int tmp;
 
    i = low;
    j = high;
    tmp = num[low];                     //任命为中间分界线，左边比他小，右边比他大,通常第一个元素是基准数
 
    if(i > j)                           //如果下标i大于下标j，函数结束运行
    {
        return;
    }
 
    while(i != j)                       //保证两者的下标不重叠
    {
        while(num[j] >= tmp && j > i)   //>=是为了保证有相同数字的情况下，还可以顺利排序。并且一定要先高位的j进行--，原因在下
        {
            j--;                        //不断寻找比标兵小的数字的下标
        }
 
        while(num[i] <= tmp && j > i)   //寻找比标兵大的数字下标
        {
            i++;
        }
 
        if(j > i)                       //两者下标找到以后，互换位置，保证在i=j时左边的数除了第一个数以外都小于标兵
        {
            temp = num[j];
            num[j] = num[i];
            num[i] = temp;
        }
    }
 
    num[low] = num[i];                  //此时标兵还在第一个数的位置，并没有改变
    num[i] = tmp;                       //将i=j时其所指的数字和标兵互换，此时一定注意，要先将j左移，否则就会将比标兵大的数字换到数组头上，导致整个排序出错
 
    quick_sort(num,low,i-1);
    quick_sort(num,i+1,high);
}

void quicksort(int *a, int size)
{
    quick_sort(a, 0, size - 1);
}
int main()
{
    int a[] = {5, 9, 2, 7, 3, 4, 1, 6, 0, 8};
    int size = sizeof(a) / sizeof(int);
    quicksort(a, size);
    for (int i = 0; i < size; i++)
    {
        printf("%d\n", a[i]);
    
    }
    return 0;
}