#include <iostream>
#include <string>

using namespace std;

string removeOccurrences(string s, string part) {
    int n = s.length();
    for (int i = n; i >= 0; i--) {

        int position = s.find(part);
        if (position < s.length()) {
            s.erase(position, part.length());
        }

    }
    return s;
}

//optimized
string removeOccurrencesOPT(string s, string part) {
    while (s.length() > 0 && s.find(part) < s.length()) {
        s.erase(s.find(part), part.length());
    }
    return s;
}

int main() {
    string s = "daabcbaabcbc";
    cout << removeOccurrences(s, "abc") << endl;
    return 0;
}