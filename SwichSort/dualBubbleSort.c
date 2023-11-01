#include <stdio.h>
#include <stdlib.h>
//双端冒泡排序
void bubblesort(int *a, int size)
{
    int low = 0, heigh = size - 1;
    bool flag = true;
    while(low < heigh&&flag){
        //判断这一趟排序是否还存在交换，如果没有交换，那么说明已经有序，可以提前结束算法
        flag = false;
        //从前向后冒泡
        for(int i = low; i < heigh; i++){
            if(a[i]>a[i+1]){
                int temp = a[i];
                a[i] = a[i + 1];
                a[i + 1] = temp;
                flag = true;
            }
        }
        //已经确定了一个最高位的数字，所以冒泡上限--
        heigh--;
        //从后向前冒泡
        for(int i = heigh; i > low; i--){
            if(a[i] < a[i - 1]){
                int temp = a[i];
                a[i] = a[i - 1];
                a[i - 1] = temp;
                flag = true;
            }
        }
        low++;
    }
}

int main()
{
    int a[10] = {1, 9, 2, 7, 3, 4, 5, 6, 0, 8};
    int size = sizeof(a) / sizeof(int);
    bubblesort(a, size);
    for (int i = 0; i < size; i++)
    {
        printf("%d", a[i]);
    }

    return 0;
}