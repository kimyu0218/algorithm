#include<iostream>
#include<vector>

using namespace std;
vector<int> atm, sorted;

void merge(int left, int mid, int right) { // 합병 정렬 오름차순
    int p1 = left, p2 = mid+1, p3 = left;
    while(p1 <= mid && p2 <= right) {
        if(atm[p1] <= atm[p2]) sorted[p3++] = atm[p1++];
        else sorted[p3++] = atm[p2++];
    }
    while(p1 <= mid) sorted[p3++] = atm[p1++];
    while(p2 <= right) sorted[p3++] = atm[p2++];

    for(int i = left; i <= right; i++)
        atm[i] = sorted[i];
}

void mergeSort(int left, int right) {
    if(left < right) {
        int mid = (left+right)/2;
        mergeSort(left, mid);
        mergeSort(mid+1, right);
        merge(left, mid, right);
    }
}

long long computeMin(int n) {
    long long sum = 0, tmp = 0;
    for(int i = 0; i < n; i++) {
        tmp += atm[i]; // i번째 사람
        sum += tmp;
    }
    return sum; // 모든 사람
}

int main() {
    int n;
    cin >> n;

    atm.assign(n, 0);
    sorted.assign(n, 0);
    for(int i = 0; i < n; i++)
        cin >> atm[i];
    mergeSort(0, n-1);
    cout << computeMin(n); // 최솟값 계산
    return 0;
}