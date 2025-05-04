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
/*
## 🧠 **Problem Scenario**

You are given two sorted arrays:

* `nums1` has enough space at the end to store all elements from `nums2`.
* Your task is to merge them **into `nums1` itself**, **without creating a new array**.

### Example:

```cpp
nums1 = [1, 3, 5, 0, 0, 0], m = 3
nums2 = [2, 4, 6], n = 3
```

Here:

* `m = 3` → First 3 elements in `nums1` are valid: `[1, 3, 5]`
* `n = 3` → All 3 elements in `nums2` are valid
* Extra 3 zeros in `nums1` are placeholders for `nums2`'s elements.

---

## ✅ Goal:

After merging `nums2` into `nums1`, it should look like:

```cpp
nums1 = [1, 2, 3, 4, 5, 6]
```

---

## 🔍 How It Works (Step-by-Step)

Instead of merging from the **front**, we merge from the **back**.

### Why from back?

Because if we merge from the front, we will overwrite `nums1`'s values.

---

## ✅ Code:

```cpp
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int i = m - 1;             // Last valid element in nums1
    int j = n - 1;             // Last element in nums2
    int k = m + n - 1;         // Last position in nums1 (end of buffer)

    while (i >= 0 && j >= 0) {
        if (nums1[i] > nums2[j]) {
            nums1[k--] = nums1[i--];   // Put bigger one at the end
        } else {
            nums1[k--] = nums2[j--];
        }
    }

    // If nums2 still has elements left
    while (j >= 0) {
        nums1[k--] = nums2[j--];
    }
}
```

---

## 📈 Dry Run with Example:

```cpp
nums1 = [1, 3, 5, 0, 0, 0], m = 3
nums2 = [2, 4, 6], n = 3
```

Initial pointers:

* i = 2 (pointing to 5)
* j = 2 (pointing to 6)
* k = 5 (last index of nums1)

Steps:

* 5 < 6 → nums1\[5] = 6, j--, k--
* 5 > 4 → nums1\[4] = 5, i--, k--
* 3 < 4 → nums1\[3] = 4, j--, k--
* 3 > 2 → nums1\[2] = 3, i--, k--
* 1 < 2 → nums1\[1] = 2, j--, k--
* nums1\[0] = 1 already in place

✅ Result: `[1, 2, 3, 4, 5, 6]`

---

## 🧠 Time and Space:

* **Time Complexity:** `O(n + m)` (each element visited once)
* **Space Complexity:** `O(1)` → No new array created!
*/

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