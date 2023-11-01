#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//桶排序，类似于基数排序
void bucketSort(vector<int>& arr, int bucketSize) {
    if (arr.empty()) {
        return;
    }

    int minValue = arr[0];
    int maxValue = arr[0];

    // 找到数组中的最小值和最大值
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] < minValue) {
            minValue = arr[i];
        }
        else if (arr[i] > maxValue) {
            maxValue = arr[i];
        }
    }

    int bucketCount = (maxValue - minValue) / bucketSize + 1;
    vector<vector<int>> buckets(bucketCount);

    // 将元素放入桶中
    for (int i = 0; i < arr.size(); i++) {
        int bucketIndex = (arr[i] - minValue) / bucketSize;
        buckets[bucketIndex].push_back(arr[i]);
    }

    arr.clear();

    // 对每个桶进行排序，并合并到原始数组中
    for (int i = 0; i < bucketCount; i++) {
        sort(buckets[i].begin(), buckets[i].end());//偷个小懒
        for (int j = 0; j < buckets[i].size(); j++) {
            arr.push_back(buckets[i][j]);
        }
    }
}

int main() {
    vector<int> arr = { 54, 46, 83, 66, 95, 92, 43 };
    bucketSort(arr, 10);
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}