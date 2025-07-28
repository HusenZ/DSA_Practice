#include <iostream>
#include <vector>
#include <numeric>   // for accumulate
#include <algorithm> // for max_element
using namespace std;

bool isValid(vector<int> &stalls, int cows, int minDist)
{
    int count = 1; // Place the first cow in the first stall
    int lastPos = stalls[0];

    for (int i = 1; i < stalls.size(); i++)
    {
        if (stalls[i] - lastPos >= minDist)
        {
            count++;
            lastPos = stalls[i];
            if (count == cows)
                return true;
        }
    }
    return false;
}
int aggressiveCows(vector<int> &stalls, int cows)
{
    sort(stalls.begin(), stalls.end());

    int low = 1;
    int high = stalls.back() - stalls.front();
    int result = 0;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (isValid(stalls, cows, mid))
        {
            result = mid;  // valid distance found
            low = mid + 1; // try to maximize
        }
        else
        {
            high = mid - 1; // try smaller distance
        }
    }

    return result;
}

int main()
{

    vector<int> nums = {1, 2, 8, 4, 9};
    int k = 3;

    cout << "Minimum largest subarray sum: " << aggressiveCows(nums, k) << endl;

    return 0;

    return 0;
}