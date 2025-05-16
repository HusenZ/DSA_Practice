#include <iostream>
#include <vector>
using namespace std;

vector<int> selectionSort(vector<int> nums)
{
    int length = nums.size();

    for (int i = 0; i < length - 1; i++)
    {
        int minIndex = i;

        for (int j = i + 1; j < length; j++)
        {
            if (nums[j] < nums[minIndex])
            {
                minIndex = j;
            }
        }

        if (minIndex != i)
        {
            swap(nums[i], nums[minIndex]);
        }
    }
    return nums;
}

int main()
{
    vector<int> nums = {5, 3, 1, 7};
    vector<int> sorted = selectionSort(nums);
    for (int i = 0; i < sorted.size(); i++)
    {
        cout << sorted[i] << " ";
    }
    cout << endl;
    return 0;
}