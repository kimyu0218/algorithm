#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int p_sum(int start, int end, vector<int> arr) {
    int result = 0;
    int idx = end;

    while(idx > start) {
        int a = arr[idx--];
        int b = arr[idx--];
        if(a == 1 || b == 1) {
            result += (a + b);
            continue;
        }
        result += (a * b);
    }
    if(idx == start) {
        result += arr[idx];
    }
    return result;
}

int n_sum(int start, int end, vector<int> arr) {
    int result = 0;
    int idx = start;

    while(idx < end) {
        int a = arr[idx++];
        int b = arr[idx++];
        result += (a * b);
    }
    if(idx == end) {
        result += arr[idx];
    }
    return result;
}

int get_split_point(int n, vector<int> arr) {
    for(int i = 0; i < n; i++) {
        if(arr[i] > 0) {
            return i - 1;
        }
    }
    return n - 1;
}

int solution(vector<int> arr) {
    int result = 0;
    int n = arr.size();

    sort(arr.begin(), arr.end());

    int mid = get_split_point(n, arr);
    return n_sum(0, mid, arr) + p_sum(mid + 1, n - 1, arr);
}

int main() {
    int n;
    vector<int> arr;

    cin >> n;

    arr.assign(n, 0);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << solution(arr);
    return 0;
}