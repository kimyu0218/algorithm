#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> straws) {
    sort(straws.begin(), straws.end());

    for(int i = straws.size() - 1; i >= 2; i--) {
        int a = straws[i - 2];
        int b = straws[i - 1];
        int c = straws[i];

        if(c < a + b) {
            return a + b + c;
        }
    }
    return -1;
}

int main() {
    int n;
    vector<int> straws;

    cin >> n;

    straws.assign(n, 0);
    for(int i = 0; i < n; i++) {
        cin >> straws[i];
    }

    cout << solution(straws);
    return 0;
}