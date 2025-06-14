#include <iostream>
#include <vector>

using namespace std;

void move_zeros_t(vector<int> nums)
{
    int counter = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] != 0)
        {
            swap(nums[i], nums[counter]);
            counter++;
        }
    }

    cout << "After move_zeros_t: ";
    for (int num : nums)
    {
        cout << num << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> nums = {0, 1, 0, 3, 12};

    cout << "Before move_zeros_t: ";
    for (int num : nums)
    {
        cout << num << " ";
    }
    cout << endl;

    move_zeros_t(nums);

    cout << "In main after move_zeros_t: ";
    for (int num : nums)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}