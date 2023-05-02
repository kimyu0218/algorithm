#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, num;
    cin >> n;

    priority_queue<int> small; // 작은 수 (top이 가장 큰 수 가리킴)
    priority_queue<int, vector<int>, greater<>> large; // 큰 수 (top이 가장 작은 수 가리킴)

    while(n--) {
        cin >> num;
        
        if(small.size() == large.size()) {
            small.push(num);
        }
        else {
            large.push(num);
        }

        // large의 가장 작은 값이 small의 가장 큰 값보다 큰 경우
        if(!small.empty() && !large.empty() && small.top() > large.top()) {
            int max = small.top(); small.pop();
            int min = large.top(); large.pop();
            
            small.push(min);
            large.push(max);
        }
        cout << small.top() << '\n';
    }
    return 0;
}