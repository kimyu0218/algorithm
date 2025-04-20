#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct person {
    int dd, mm, yyyy;
    string name;
};

bool cmp(person &p1, person &p2) {
    if(p1.yyyy != p2.yyyy) {
        return p1.yyyy < p2.yyyy;
    }
    if(p1.mm != p2.mm) {
        return p1.mm < p2.mm;
    }
    return p1.dd < p2.dd;
}

vector<string> solution(vector<person> students) {
    int n = students.size();

    sort(students.begin(), students.end(), cmp);

    return { students[n - 1].name, students[0].name };
}

int main() {
    int n;
    vector<person> students;

    cin >> n;

    students.assign(n, {0, 0, 0, ""});
    for(int i = 0; i < n; i++) {
        cin >> students[i].name >> students[i].dd >> students[i].mm >> students[i].yyyy;
    }

    vector<string> answer = solution(students);

    cout << answer[0] << '\n' << answer[1];
    return 0;
}