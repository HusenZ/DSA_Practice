#include <iostream>
#include <vector>

using namespace std;

char nextGreatestLetter(vector<char> &letters, char target)
{
    int st = 0, end = letters.size() - 1;
    char result = letters[0]; // default wrap-around

    while (st <= end)
    {
        int mid = st + (end - st) / 2;
        if (letters[mid] > target)
        {
            result = letters[mid]; // possible answer
            end = mid - 1;         // try to find smaller > target
        }
        else
        {
            st = mid + 1;
        }
    }

    return result;
}

int main()
{
    vector<char> letters = {'c', 'f', 'j'};
    char ans = nextGreatestLetter(letters, 'z');
    cout << ans << endl;
    return 0;
}