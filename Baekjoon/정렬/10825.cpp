#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct student {
    string name;
    int korean, math, english;
};

bool cmp(student &s1, student &s2) {
    if(s1.korean != s2.korean) {
        return s1.korean > s2.korean;
    }
    if(s1.english != s2.english) {
        return s1.english < s2.english;
    }
    if(s1.math != s2.math) {
        return s1.math > s2.math;
    }
    return s1.name < s2.name;
}

vector<string> solution(vector<student> students) {
    vector<string> result;

    int n = students.size();
    sort(students.begin(), students.end(), cmp);

    for(int i = 0; i < n; i++) {
        result.push_back(students[i].name);
    }
    return result;
}

int main() {
    int n;
    vector<student> students;

    cin >> n;

    students.assign(n, {"", 0, 0, 0});
    for(int i = 0; i < n; i++) {
        cin >> students[i].name >> students[i].korean >> students[i].english >> students[i].math;
    }

    vector<string> sorted = solution(students);
    for(int i = 0; i < n; i++) {
        cout << sorted[i] << '\n';
    }
    return 0;
}