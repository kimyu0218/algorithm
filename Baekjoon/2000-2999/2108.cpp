#include <iostream>
#include <map>
#include <cmath>

using namespace std;
map<int, int> m;

int median(int std) { // 중앙값
    int idx = 0;
    for(auto iter = m.begin(); iter != m.end(); iter++) {
        int tmp = idx;
        idx += iter->second;
        if(tmp <= std && std <= idx) return iter->first;
    }
    return -1;
}

int highest_freq() { // 최빈값
    int freq = 0, result;

    bool second = false;
    for(auto iter = m.begin(); iter != m.end(); iter++) {
        if(iter->second > freq) { // 최빈값 갱신
            freq = iter->second;
            result = iter->first;
            second = false;
        }
        else if(iter->second == freq && !second) { // 두번째로 작은 최빈값 찾음
            result = iter->first;
            second = true;
        }
    }
    return result;
}

int range() { // 범위
    int max = (--m.end())->first;
    int min = m.begin()->first;
    return max-min;
}

int main() {
    int n, num, sum = 0;
    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> num;
        m[num]++;
        sum += num;
    }

    int avg = round((double)sum/n);
    cout << (!avg ? 0 : avg) << '\n';
    cout << median((n%2 == 0) ? n/2 : n/2 + 1) << '\n';
    cout << highest_freq() << '\n';
    cout << range();
    return 0;
}