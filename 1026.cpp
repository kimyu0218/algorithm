#include <iostream>
#include <vector>

using namespace std;
vector<int> a,b;

void ascending(int n) { // 오름차순 버블 정렬
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n-1-i; j++) {
            if(a[j] > a[j+1])
                swap(a[j], a[j+1]);
        }
    }
}

void descending(int n) { // 내림차순 버블 정렬
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n-1-i; j++) {
            if(b[j] < b[j+1])
                swap(b[j], b[j+1]);
        }
    }
}

int computeMin(int n) { // 최솟값 계산
    int result = 0;
    for(int i = 0; i < n; i++)
        result += a[i] * b[i];
    return result;
}

int main() {
    int n;
    cin >> n;
    a.assign(n, 0);
    b.assign(n, 0);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int i = 0; i < n; i++)
        cin >> b[i];

    ascending(n); // 오름차순 정렬
    descending(n); // 내림차순 정렬
    cout << computeMin(n); // 최솟값 계산
    return 0;
}