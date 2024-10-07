#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solution(vector<int> arr) {
    if(!next_permutation(arr.begin(), arr.end())) {
        cout << -1;
        return;
    }
    for(int i = 0; i < arr.size(); i++) {
        cout << arr[i] << ' ';
    }
}

int main() {
    int n;
    vector<int> arr;
    
    cin >> n;
    
    arr.assign(n, 0);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    solution(arr);
    return 0;
}