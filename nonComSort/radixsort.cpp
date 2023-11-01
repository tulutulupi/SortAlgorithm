#include<iostream>
#include<vector>
#define radix 10;
using namespace std;

//基数排序适合
void radixSort(int a[], int size){
    vector<vector<int>> bulk(size, vector<int>(0,0));//使用动态数组来存储每一趟排序的关键字，这里是二维数组10*1
    int max = a[0];
    for (int i = 0; i < size; i++)//选出最大的关键字，以确定最大排序趟数
    {
        if(max<a[i]){
            max = a[i];
        }
    }
    
    int pix = 1;
    while(max % pix != max){//确定最大趟数，如果max=999,则有1，10，100三趟排序，当pix为1000时，退出循环
        
        for (int i = 0; i < size; i++)
        {
            int wei = (a[i] / pix) % radix;//得到关键字的个十百位
            bulk[wei].push_back(a[i]);//将相同的数位存在一个位置下
        }
        int indix = 0;
        for(auto tem : bulk){
            if(tem.size() > 0){
                for(auto b : tem){
                    a[indix++] = b;//按照从小到大的顺序将一趟排序的结果写回原数组
                }
            }
        }
        for (int i = 0; i < size; i++){
            bulk[i].clear();//将处理完的一趟存储的元素清空
        }
        pix = pix*radix;//从后往前处理关键字的不同位置的数
    }
    
}
int main(){
    int a[] = {278, 886, 996, 700, 975, 985, 211, 863, 521, 857};
    int size = sizeof(a)/sizeof(int);
    radixSort(a, size);
    for(int i = 0; i < size; i++){
        cout<<a[i]<<endl;
    }
    return 0;
}

