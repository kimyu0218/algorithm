#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int LEN = 10;

bool cmp(int &a1, int &a2) {
    int q1 = a1 % LEN;
    int q2 = a2 % LEN;

    if(!q1 && q2) {
        return true;
    }
    if(q1 && !q2) {
        return false;
    }
    return a1 < a2;
}

vector<int> longer_than_10(vector<int> a) {
    vector<int> result;

    for(int i = 0; i < a.size(); i++) {
        if(a[i] <= LEN) {
            continue;
        }
        result.push_back(a[i]);
    }
    sort(result.begin(), result.end(), cmp);
    return result;
}

int solution(int m, vector<int> a) {
    int result = 0;

    for(int i = 0; i < a.size(); i++) {
        result += (a[i] == LEN);
    }

    vector<int> cutting = longer_than_10(a);

    for(int i = 0; i < cutting.size(); i++) {
        int piece = cutting[i] / LEN;
        int cut = (cutting[i] % LEN) ? piece : piece - 1;
        if(m < cut) {
            return result + m;
        }
        result += piece;
        m -= cut;
    }
    return result;
}

int main() {
    int n, m;
    vector<int> a;

    cin >> n >> m;

    a.assign(n, 0);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    cout << solution(m, a);
    return 0;
}