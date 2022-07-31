#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int triangle(int n, vector<int> straw) {
    int result = -1;
    for(int i = n-3; i >= 0; i--) {
        // 삼각형 만족하지 않음 : 한 변의 길이가 다른 두 변의 길이의 합과 같거나 큼
        if(straw[i] + straw[i+1] <= straw[i+2]) continue;
        // 삼각형 만족
        result = straw[i] + straw[i+1] + straw[i+2]; break;
    }
    return result;
}

int main() {
    int n;
    cin >> n;

    vector<int> straw(n, 0);
    for(int i = 0; i < n; i++)
        cin >> straw[i];
    sort(straw.begin(), straw.end());

    cout << triangle(n, straw);
    return 0;
}