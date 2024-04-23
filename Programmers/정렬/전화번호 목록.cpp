#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
    int n = phone_book.size();

    sort(phone_book.begin(), phone_book.end());

    for(int i = 0; i < n - 1; i++) {
        string s1 = phone_book[i];
        string s2 = phone_book[i + 1];

        string prefix = s1.length() < s2.length() ? s1 : s2;
        string non_prefix = prefix == s1 ? s2 : s1;

        if(prefix == non_prefix.substr(0, prefix.length())) {
            return false;
        }
    }
    return true;
}