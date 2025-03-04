#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool chooseOne(int n, int c, vector<int> &w) { // 1개의 물건 선택
    for(int i = 0; i < n; i++) {
        if(w[i] == c) {
            return true;
        }
    }
    return false;
}

bool chooseTwo(int n, int c, vector<int> &w) { // 2개의 물건 선택
    int left = 0, right = n-1;
    while(left < right) {
        int sum = w[left] + w[right];
        if(sum == c) {
            return true;
        }
        if(sum > c) {
            right--;
        }
        else {
            left++;
        }
    }
    return false;
}

bool chooseThree(int n, int c, vector<int> &w) { // 3개의 물건 선택
    for(int i = 0; i < n-2; i++) {
        int left = i+1, right = n-1;
        while(left < right) {
            int sum = w[i] + w[left] + w[right];
            if(sum == c) {
                return true;
            }
            if(sum > c) {
                right--;
            }
            else {
                left++;
            }
        }
    }
    return false;
}

bool makeC(int n, int c, vector<int> &w) {
    if(chooseOne(n, c, w)) {
        return true;
    }
    if(chooseTwo(n, c, w)) {
        return true;
    }
    return chooseThree(n, c, w);
}

int main() {
    int n, c;
    vector<int> w;

    cin >> n >> c;
    w.assign(n, 0);
    for(int i = 0; i < n; i++) {
        cin >> w[i];
    }
    sort(w.begin(), w.end());

    cout << makeC(n, c, w);
    return 0;
}