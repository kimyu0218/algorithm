#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;

vector<int> split(string s) {
    vector<int> result;

    string tmp = "";
    for(int i = 0; i < s.length(); i++) {
        if(s[i] == ' ') {
            result.push_back(stoi(tmp));
            tmp = "";
            continue;
        }
        tmp += s[i];
    }
    result.push_back(stoi(tmp));
    return result;
}

bool cmp(pi &p1, pi &p2) {
    return p1.second > p2.second;
}

ll solution(int w, int n, vector<pi> metal) {
    ll answer = 0;

    sort(metal.begin(), metal.end(), cmp);

    for(int i = 0; i < n; i++) {
        if(w <= 0) {
            return answer;
        }

        int m = metal[i].first;
        int p = metal[i].second;

        answer += p * min(w, m);
        w -= m;
    }
    return answer;
}

int main() {
    int w, n;
    vector<pi> metal;

    string input;

    getline(cin, input);

    vector<int> v = split(input);
    w = v[0];
    n = v[1];

    for(int i = 0; i < n; i++) {
        getline(cin, input);

        vector<int> v = split(input);
        metal.push_back({v[0], v[1]});
    }

    cout << solution(w, n, metal);
    return 0;
}