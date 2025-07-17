#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<vector<string>> suggestedProducts(vector<string> &products, string searchWord)
{
    vector<vector<string>> result;
    sort(products.begin(), products.end());
    string prefix = "";

    for (char c : searchWord)
    {
        prefix += c;
        // lower_bound gives first element >= prefix
        auto it = lower_bound(products.begin(), products.end(), prefix);
        vector<string> suggestions;

        // Check next 3 elements (max)
        for (int i = 0; i < 3 && (it + i) != products.end(); ++i)
        {
            if ((*(it + i)).substr(0, prefix.size()) == prefix)
            {
                suggestions.push_back(*(it + i));
            }
        }

        result.push_back(suggestions);
    }

    return result;
}

int main()
{
    vector<string> products = {"mobile", "mouse", "moneypot", "monitor", "mousepad"};
    string searchWord = "mouse";

    vector<vector<string>> suggestions = suggestedProducts(products, searchWord);

    for (const auto &list : suggestions)
    {
        for (const auto &word : list)
        {
            cout << word << " ";
        }
        cout << endl;
    }

    return 0;
}
