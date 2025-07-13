#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main()
{
    unordered_map<int, string> name_history;

    // Adding data
    name_history[1] = "Ali";
    name_history[2] = "Zara";
    name_history.insert({3, "Ahmed"});
    name_history.emplace(4, "Fatima");

    cout << name_history.at(3) << endl;

    // Printing all entries
    for (auto &entry : name_history)
    {
        cout << "ID: " << entry.first << " => Name: " << entry.second << endl;
    }

    return 0;
}
