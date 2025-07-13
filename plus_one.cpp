#include <iostream>
#include <vector>
#include <string>

using namespace std;
vector<int> plusOne(vector<int> &digits)
{
    int n = digits.size();

    for (int i = n - 1; i >= 0; i--)
    {
        if (digits[i] < 9)
        {
            digits[i]++;
            return digits;
        }
        digits[i] = 0; // carry over
    }

    // If all digits were 9, like 999 → result = 1000
    digits.insert(digits.begin(), 1);
    return digits;
}
int main()
{
    vector<int> nums = {4, 9};
    vector<int> result = plusOne(nums);
    for (int digit : result)
    {
        cout << digit << ", ";
    }
    return 0;
}