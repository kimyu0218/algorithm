#include <iostream>
#include <set>

using namespace std;

struct Compare {
    bool operator() (const string &p1, const string &p2) const {
        if(p1.length() == p2.length()) return p1 < p2;
        return p1.length() < p2.length();
    }
};

int main() {
    int n;
    cin >> n;

    string word;
    set<string, Compare> word_set;

    while(n--) {
        cin >> word;
        word_set.insert(word);
    }

    for(auto iter = word_set.begin(); iter != word_set.end(); iter++)
        cout << *iter << '\n';

    return 0;
}