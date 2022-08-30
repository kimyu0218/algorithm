#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct student{
    string name;
    int kor, eng, math;
}s;
vector<s> students;

bool cmp(s &s1, s &s2) {
    // 1. 국어 점수 감소하는 순서
    if(s1.kor != s2.kor) return s1.kor > s2.kor;
    // 2. 영어 점수 증가하는 순서
    if(s1.eng != s2.eng) return s1.eng < s2.eng;
    // 3. 수학 점수 감소하는 순서
    if(s1.math != s2.math) return s1.math > s2.math;
    // 4. 이름 사전순 증가
    return s1.name < s2.name;
}

int main() {
    int n;
    cin >> n;

    students.assign(n, {"", 0, 0, 0});
    for(int i = 0; i < n; i++)
        cin >> students[i].name >> students[i].kor >> students[i].eng >> students[i].math;

    sort(students.begin(), students.end(), cmp);
    for(int i = 0; i < n; i++)
        cout << students[i].name << '\n';
    return 0;
}