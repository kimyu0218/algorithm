#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct Member { // 회원 정보 구조체
    int age;     // 회원 이름
    int order;   // 가입 순서
    string name; // 회원 이름
} member;

bool compare (const member &p1, const member &p2) { // 정렬 기준
    if(p1.age != p2.age) return p1.age < p2.age; // 1. 나이순
    return p1.order < p2.order;                  // 2. 가입순
}

int main() {
    int n, age;
    string name;
    cin >> n;

    vector<member> mem;

    for(int i = 0; i < n; i++) {
        cin >> age >> name;
        mem.push_back({age, i, name});
    }

    sort(mem.begin(), mem.end(), compare);

    for(auto & iter : mem)
        cout << iter.age << ' ' << iter.name << '\n';

    return 0;
}