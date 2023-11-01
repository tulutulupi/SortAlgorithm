#include <iostream>
#include <stack>
#include <cstdio>
using namespace std;
int partition(int *num, int low, int high){
    int random = low+rand()%(high - low + 1);
    swap(num[random],num[low]);
    int temp = num[low];
    while(low < high){
        while (low < high && num[high] >= temp)
        {
            high--;
        }
        num[low] = num[high];
        while(low < high && num[low] <= temp){
            low++;
        }
        num[high] = num[low];
    }
    num[low] = temp;
    return low;
}
void quick_sort(int num[], int low, int high )
{
    stack<int> st;
    st.push(low);
    st.push(high);
    while(!st.empty()){
        int high = st.top();
        int i = high;
        st.pop();
        int low = st.top();
        int j = low;
        st.pop();

        if(low == high){
            continue;
        }

        low = partition(num, low, high);
       
        if(low != i){
            st.push(low + 1);
            st.push(i);
        }
        if(low != j){
            st.push(j);
            st.push(low - 1);
        }
    }
}

void quicksort(int *a, int size)
{
    quick_sort(a, 0, size - 1);
}
int main()
{
    int a[] = {5, 9, 2, 7, 3, 4, 1, 6, 0, 8};
    int size = sizeof(a)/sizeof(int);
    quicksort(a, size);
    for (int i = 0; i < size; i++)
    {
        printf("%d\n", a[i]);
    
    }
    return 0;
}