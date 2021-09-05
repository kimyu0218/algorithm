#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
struct info {
    string name;
    int kor, eng, math;
};
vector<info> student;

bool cmp(const info &i1, const info &i2) {
    if(i1.kor != i2.kor) return i1.kor > i2.kor;
    if(i1.eng != i2.eng) return i1.eng < i2.eng;
    if(i1.math != i2.math) return i1.math > i2.math;
    return i1.name < i2.name;
}

int main() {
    int n;
    cin >> n;
    student.assign(n, {});

    for(int i = 0; i < n; i++)
        cin >> student[i].name >> student[i].kor >> student[i].eng >> student[i].math;

    sort(student.begin(), student.end(), cmp);
    for(int i = 0; i < n; i++)
        cout << student[i].name << '\n';
    return 0;
}