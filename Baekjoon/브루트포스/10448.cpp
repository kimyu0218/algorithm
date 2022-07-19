#include <iostream>
#include <vector>

using namespace std;

const int MAX = 1000;
vector<int> t;

void init_triangular() { // 삼각수 세팅
    int n = 1;
    while(true) {
        int tmp = n*(n+1)/2;
        if(tmp > MAX) break;
        t.push_back(tmp); n++;
    }
}

int is_triangular(int n) { // 삼각수 여부 판별
    int size = t.size();

    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            for(int k = 0; k < size; k++)
                if(n == t[i] + t[j] + t[k]) return 1;
        }
    }
    return 0;
}

int main() {
    int t, k;
    cin >> t;

    init_triangular();
    while(t--) {
        cin >> k;
        cout << is_triangular(k) << '\n';
    }
    return 0;
}