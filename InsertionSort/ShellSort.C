#include <stdio.h>
#include <stdlib.h>
void ShellSort(int *a, int size)
{
    register int i, j, tmp,n = size;
    int step;

    for(step = n/2; step > 0;step /= 2)/*增量步长,每次减半*/
    {
        /*step = 4 2 1*/
        for(i = step; i < n; i++)
        {
            tmp = a[i];/*交换筹码*/
            j = i - step;/*从i向前step的第一个数*/
            while(j >= 0 && tmp < a[j])/*向后寻找，不断比较可以交换的数字*/
            {
                a[j + step] = a[j];
                j -= step;
            }
            a[j + step] = tmp;

        }
    }
}
int main()
{
    int a[] = {5, 9, 2, 7, 3, 4, 1, 6, 0, 8};
    int size = sizeof(a) / sizeof(int);
    ShellSort(a, size);
    for (int i = 0; i < size; i++)
    {
        printf("%d\n", a[i]);
    }
    return 0;
}