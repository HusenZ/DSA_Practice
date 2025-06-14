#include <iostream>
#include <vector>
using namespace std;

void bubbleSort(vector<int> &arr)
{
    int n = arr.size();

    for (int i = 0; i < n - 1; i++)
    {
        bool swapped = false;

        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                // Swap elements using std::swap
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }

        // If no elements were swapped, break early
        if (!swapped)
            break;
    }
}

void printVector(const vector<int> &arr)
{
    for (int num : arr)
        cout << num << " ";
    cout << endl;
}

int main()
{
    vector<int> arr = {5, 1, 4, 2, 8};

    cout << "Original vector: ";
    printVector(arr);

    bubbleSort(arr);

    cout << "Sorted vector: ";
    printVector(arr);

    return 0;
}
