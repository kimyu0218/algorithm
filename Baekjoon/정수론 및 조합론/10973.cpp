#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr) {
    if(prev_permutation(arr.begin(), arr.end())) {
        return arr;
    }
    return { -1 };
}

int main() {
    int n;
    vector<int> arr;
    
    cin >> n;
    
    arr.assign(n, 0);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    vector<int> result = solution(arr);
    
    for(int i = 0; i < result.size(); i++) {
        cout << result[i] << ' ';
    }
    return 0;
}