#include <iostream>
#include <vector>
#include <set>

using namespace std;

const string CHONG_CHONG = "ChongChong";

int solution(vector<string> a, vector<string> b) {
    int n = a.size();
    set<string> dancer;

    dancer.insert(CHONG_CHONG);
    for(int i = 0; i < n; i++) {
        if(dancer.find(a[i]) != dancer.end()) {
            dancer.insert(b[i]);
        }
        else if(dancer.find(b[i]) != dancer.end()) {
            dancer.insert(a[i]);
        }
    }
    return dancer.size();
}

int main() {
    int n;
    vector<string> a, b;

    cin >> n;

    a.assign(n, "");
    b.assign(n, "");
    for(int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }

    cout << solution(a, b);
    return 0;
}