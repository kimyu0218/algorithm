#include <iostream>

using namespace std;

bool result;

void divide(int left, int right, string paper) {
    if(left >= right) return;

    int l = left, r = right;
    while(l < r) { // mid 중심으로 left와 right 비교
        if(paper[l++] == paper[r--]) {
            result = false;
            return;
        }
    }
    // l == r 시점 : mid
    divide(left, l-1, paper); // left 부터 mid-1까지 비교
}

int main() {
    int t;
    cin >> t;

    string paper;
    while(t--) {
        cin >> paper;

        result = true;
        divide(0, paper.length()-1, paper);
        cout << (result ? "YES\n" : "NO\n");
    }
    return 0;
}