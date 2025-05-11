#include <iostream>
#include <vector>
using namespace std;

bool isThreeConsi(vector<int> arr)
{
    int n = arr.size();
    for (int i = 0; i <= n - 3; i++)
    {
        if (arr[i] % 2 != 0 && arr[i + 1] % 2 != 0 && arr[i + 2] % 2 != 0)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    vector<int> arr = {1, 2, 34, 3, 4, 5, 7, 23, 12};
    cout << isThreeConsi(arr) << endl;
}