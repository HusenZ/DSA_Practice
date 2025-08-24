#include <iostream>
#include <vector>

using namespace std;

int partition(vector<int>& arr, int start, int end) {
    int idx = start - 1, pivot = arr[end];

    for (int j = start; j < end; j++) {
        if (arr[j] < pivot) {
            idx++;
            swap(arr[j], arr[idx]);
        }
    }
    idx++;
    swap(arr[end], arr[idx]);
    return idx;
}


void quickSort(vector<int>& arr, int start, int end) {
    if (start < end) {
        int pivIdx = partition(arr, start, end);

        quickSort(arr, start, pivIdx - 1);
        quickSort(arr, pivIdx + 1, end);
    }
}


int main() {
    vector<int> nums = { 5, 2, 6, 4, 1 ,3 };
    quickSort(nums, 0, nums.size() - 1);
    for (int num : nums) {
        cout << num << " ";
    }
    return 0;
}