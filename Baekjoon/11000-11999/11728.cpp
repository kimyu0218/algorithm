#include <iostream>
#include <vector>

using namespace std;
vector<int> a, b;

vector<int> mergeSort(int n, int m) {
    vector<int> result;

    int p1 = 0, p2 = 0; // 각각 배열 A와 B의 원소를 가리키는 포인터
    while(p1 < n && p2 < m) {
        if(a[p1] < b[p2]) result.push_back(a[p1++]);
        else result.push_back(b[p2++]);
    }
    while(p1 < n) result.push_back(a[p1++]);
    while(p2 < m) result.push_back(b[p2++]);

    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    a.assign(n, 0);
    b.assign(m, 0);

    for(int i = 0; i < n; i++) // A 배열 입력받기
        cin >> a[i];

    for(int i = 0; i < m; i++) // B 배열 입력받기
        cin >> b[i];

    vector<int> result = mergeSort(n, m);
    for(int i = 0; i < result.size(); i++)
        cout << result[i] << ' ';
    return 0;
}