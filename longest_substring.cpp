#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>

using namespace std;

// optimiezed solution
int lengthOfLongestSubstringMap(string s)
{
    unordered_map<char, int> lastSeen;
    int maxLen = 0, left = 0;

    for (int right = 0; right < s.length(); ++right)
    {
        if (lastSeen.find(s[right]) != lastSeen.end() && lastSeen[s[right]] >= left)
        {
            // Duplicate found in current window
            left = lastSeen[s[right]] + 1;
        }
        lastSeen[s[right]] = right;
        maxLen = max(maxLen, right - left + 1);
    }

    return maxLen;
}

// using unordered set
int lengthOfLongestSubstringSet(string s)
{
    unordered_set<char> seen;
    int left = 0, right = 0;
    int maxLen = 0;

    while (right < s.length())
    {
        if (seen.find(s[right]) == seen.end())
        {
            seen.insert(s[right]);
            maxLen = max(maxLen, right - left + 1);
            right++;
        }
        else
        {
            seen.erase(s[left]);
            left++;
        }
    }

    return maxLen;
}

int main()
{
    string s = "abcabcbb";
    cout << lengthOfLongestSubstringMap("abcabcbb");
    return 0;
}