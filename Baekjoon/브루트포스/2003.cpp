#include <iostream>
#include <vector>

using namespace std;

vector<int> make_sum(int n, vector<int> a) {
    vector<int> sum(n + 1, 0);
    
    sum[1] = a[0];
    for(int i = 1; i < n; i++) {
        sum[i + 1] = sum[i] + a[i];
    }
    return sum;
}

int solution(int m, vector<int> a) {
    int result = 0;
    int n = a.size();
    vector<int> sum = make_sum(n, a);
    
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j <= n; j++) {
            int partial_sum = sum[j] - sum[i];
            if(partial_sum >= m) {
                result += (partial_sum == m);
                break;
            }
        }
    }
    return result;
}

int main() {
    int n, m;
    vector<int> a;
    
    cin >> n >> m;
    
    a.assign(n, 0);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    cout << solution(m, a);
    return 0;
}