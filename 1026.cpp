#include <iostream>
#include <vector>

using namespace std;
vector<int> a, b, sorted;

void mergeAscending(int left, int mid, int right) { // 합병 정렬 오름차순
    int p1 = left, p2 = mid+1, p3 = left;
    while(p1 <= mid && p2 <= right) {
        if(a[p1] <= a[p2]) sorted[p3++] = a[p1++];
        else sorted[p3++] = a[p2++];
    }
    while(p1 <= mid) sorted[p3++] = a[p1++];
    while(p2 <= right) sorted[p3++] = a[p2++];

    for(int i = left; i <= right; i++)
        a[i] = sorted[i];
}

void mergeDescending(int left, int mid, int right) { // 합병 정렬 내림차순
    int p1 = left, p2 = mid+1, p3 = left;
    while(p1 <= mid && p2 <= right) {
        if(b[p1] >= b[p2]) sorted[p3++] = b[p1++];
        else sorted[p3++] = b[p2++];
    }
    while(p1 <= mid) sorted[p3++] = b[p1++];
    while(p2 <= right) sorted[p3++] = b[p2++];

    for(int i = left; i <= right; i++)
        b[i] = sorted[i];
}

void mergeSort(int left, int right) {
    if(left < right) {
        int mid = (left+right)/2;
        mergeSort(left, mid);
        mergeSort(mid+1, right);
        mergeAscending(left, mid, right);
        mergeDescending(left, mid, right);
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
    sorted.assign(n, 0);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int i = 0; i < n; i++)
        cin >> b[i];

    mergeSort(0, n-1);
    cout << computeMin(n); // 최솟값 계산
    return 0;
}