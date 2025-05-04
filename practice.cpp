/*
🟢 Question 1: Find the Median of a Single Sorted Array
Problem:
Given a sorted array, return its median.

// Example
nums = [1, 2, 3, 4]
Output = 2.5

nums = [5, 8, 12]
Output = 8
Goal: Learn how to calculate median (middle element or average of two middles)

🟢 Question 2: Merge Two Sorted Arrays (Without Sorting)
Problem:
Given two sorted arrays, merge them into a single sorted array.

nums1 = [1, 3, 5]
nums2 = [2, 4, 6]

Merged: [1, 2, 3, 4, 5, 6]
Goal: Use two pointers to merge without using .sort(). This teaches you how arrays are merged.

🟡 Question 3: Find Kth Element in Two Sorted Arrays (Brute Force)
Problem:
Given two sorted arrays and an integer k, find the kth element in the merged array.

nums1 = [1, 3, 5]
nums2 = [2, 4, 6]
k = 4

Merged = [1, 2, 3, 4, 5, 6] → 4th element is 4
Goal: Learn how to build the merged array manually and extract the kth element.
This logic will help later when we want to avoid merging.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

double getMedian(vector<int> nums)
{
    int low = 0, high = nums.size() - 1;
    cout << "size of the array: " << high << endl;
    int mid = (low + high) / 2;
    if (high % 2 == 0)
    {
        cout << "the array is even " << nums[mid] << " + " << nums[mid - 1] << endl;
        double medain = (nums[mid] + nums[mid - 1]) / 2.0;
        cout << "floating point variable: " << medain << endl;
        return medain;
    }
    return nums[mid];
}

int binarySearch(vector<int> array, int target)
{
    int i = 0, j = array.size();
    while (i <= j)
    {
        int mid = (i + j) / 2;
        if (array[mid] == target)
        {
            return mid;
        }
        else if (array[mid] < target)
        {
            i = mid + 1;
        }
        else
        {
            j = mid - 1;
        }
    }
    return -1;
}

vector<int> mergeArrays(vector<int>& nums1, vector<int>& nums2) {
    int i = 0, j = 0;  // Pointers for nums1 and nums2
    vector<int> newArray;

    // Merge the two arrays while maintaining order
    while (i < nums1.size() && j < nums2.size()) {
        if (nums1[i] < nums2[j]) {
            newArray.push_back(nums1[i]);
            i++;
        } else {
            newArray.push_back(nums2[j]);
            j++;
        }
    }

    // Append remaining elements from nums1 (if any)
    while (i < nums1.size()) {
        newArray.push_back(nums1[i]);
        i++;
    }

    // Append remaining elements from nums2 (if any)
    while (j < nums2.size()) {
        newArray.push_back(nums2[j]);
        j++;
    }

    return newArray;
}

int findKElement(vector<int> nums1, vector<int> nums2, int k){
    vector<int> newArray = mergeArrays(nums1 , nums2);
    
    return newArray[k];
}

int main()
{
    vector<int> nums = {1, 3, 2, 4};
    vector<int> nums2  = {5, 8, 7};
    vector<int> median = mergeArrays(nums, nums2);
    cout << median.size() << endl;
    for(int i = 0; i<= median.size()-1 ;i++){
        cout << median[i] << " ";
    }
    cout<<endl;
   cout<< findKElement(nums, nums2, 5);
    return 0;
}