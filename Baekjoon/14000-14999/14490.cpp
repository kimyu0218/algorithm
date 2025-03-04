#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> split(string s) { // n과 m 배열 형태로 리턴
    vector<int> v;
    int idx;
    for(idx = 0; idx < s.length(); idx++) { // : 위치 파악
        if(s[idx] == ':') break;
    }
    v.push_back(stoi(s.substr(0, idx))); // n
    v.push_back(stoi(s.substr(idx+1, s.length()-1-idx))); // m
    return v;
}

int gcd(int a, int b) { // 최대 공약수 구하기
    while(b) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main() {
    string s;
    cin >> s;

    vector<int> v = split(s);
    int g = gcd(max(v[0], v[1]), min(v[0], v[1]));
    cout << v[0]/g << ':' << v[1]/g;
    return 0;
}