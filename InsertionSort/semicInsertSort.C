#include <stdlib.h>
#include <stdio.h>
void semicInsertSort(int a[],int size){
    int i=0,j=0,low=0,high=0,mid=0,temp=0;
    for(i=2;i<size;i++){
        temp = a[i];
        low = 0;high = i-1;
        while(low<=high){
            mid = (low+high)/2;
            if(a[mid]>temp){
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        for(j=i-1;j>=high+1;--j){
            a[j+1] = a[j];
        }
        a[high+1] = temp;
    }
}
int main()
{
    int a[] = {5, 9, 2, 7, 3, 4, 1, 6, 0, 8};
    int size = sizeof(a) / sizeof(int);
    semicInsertSort(a, size);
    for (int i = 0; i < size; i++)
    {
        printf("%d\n", a[i]);
    
    }
    return 0;
}