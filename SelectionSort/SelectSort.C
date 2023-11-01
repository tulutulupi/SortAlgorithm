#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void selectsort(int *a,int size)
{   
    for(int i=0;i<size;i++){
        int min = a[i],temp = 0;
        for(int j=i;j<size;j++){
            if(min>=a[j]){
                temp = min;
                min = a[j];
                a[j] = temp;
            }
        }
        a[i] = min;
    }
}

int main()
{
    int a[10] = {1, 9, 2, 7, 3, 4, 5, 6, 0, 8};
    int size = sizeof(a)/sizeof(int);
    selectsort(a,size);
    for(int i = 0; i < size; i++){
        printf("%d", a[i]);
    }

    return 0;
}