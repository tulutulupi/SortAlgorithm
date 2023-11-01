#include <stdio.h>
#include <stdlib.h>

void bubblesort(int *a, int size)
{
    for (int i = size - 1; i >= 0; i--)
    {
        bool flag = false;
        for (int j = i - 1; j >= 0; j--)
        {
            if (a[i] < a[j])
            {
                int temp = 0;
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
                flag = true;
            }
        }
        if (!flag)
        {
            break;
        }
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