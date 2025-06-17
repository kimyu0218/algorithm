#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(char &ch1, char &ch2) {
    bool is_upper1 = isupper(ch1);
    bool is_upper2 = isupper(ch2);

    if(is_upper1 == is_upper2) {
        return ch1 > ch2;
    }
    return is_upper1 ? false : true;
}

string solution(string s) {
    string answer = "";
    int n = s.length();
    vector<char> arr (n, '\0');

    for(int i = 0; i < n; i++) {
        arr[i] = s[i];
    }
    sort(arr.begin(), arr.end(), cmp);

    for(int i = 0; i < n; i++) {
        answer += arr[i];
    }
    return answer;
}