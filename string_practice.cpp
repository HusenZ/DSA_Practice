#include <iostream>
#include <string>
#include <vector>

using namespace std;

// longest common prefix
string longestCommonPrefix(vector<string> &strs)
{
    if (strs.empty())
        return "";

    string prefix = strs[0]; // take first word as prefix

    for (int i = 1; i < strs.size(); i++)
    {
        string current = strs[i];
        int j = 0;

        // compare characters of prefix and current word
        while (j < prefix.size() && j < current.size() && prefix[j] == current[j])
        {
            j++;
        }

        // cut the prefix to the matched part
        prefix = prefix.substr(0, j);

        // early exit if no prefix is left
        if (prefix == "")
            return "";
    }

    return prefix;
}

int main()
{
    string name = "Mohammadhusen789@$";
    int count = 0;
    int vowelsCount = 0;
    int consonantCount = 0;

    for (char c : name)
    {
        c = tolower(c);

        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
        {
            vowelsCount++;
        }
        else
        {
            consonantCount++;
        }
    }
    cout << "count of vowels in the string: " << vowelsCount << endl;
    cout << "count of consonants in the string: " << consonantCount << endl;
    return 0;
}
