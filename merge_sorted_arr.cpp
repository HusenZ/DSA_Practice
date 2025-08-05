#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
{
    int i = m - 1;     // pointer for nums1's actual elements
    int j = n - 1;     // pointer for nums2
    int k = m + n - 1; // pointer for final position in nums1

    while (i >= 0 && j >= 0)
    {
        if (nums1[i] > nums2[j])
        {
            nums1[k--] = nums1[i--];
        }
        else
        {
            nums1[k--] = nums2[j--];
        }
    }

    // Copy any remaining nums2 elements (if any)
    while (j >= 0)
    {
        nums1[k--] = nums2[j--];
    }
}

int main()
{
    vector<int> nums1 = {
        1,
        2,
        3 };
    vector<int> nums2 = { 2, 5, 6 };
    int m = 3, n = 3;
    merge(nums1, m, nums2, n);
    cout << "hello" << endl;
    for (auto val : nums1)
    {
        cout << val << ", ";
    }
    return 0;
}