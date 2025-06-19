#include <string>
#include <vector>
#include <queue>

using namespace std;

typedef long long ll;

int gcd(int a, int b) {
    while(b) {
        int c = a % b;
        a = b;
        b = c;
    }
    return a;
}

int solution(vector<int> arr) {
    int n = arr.size();
    queue<int> q;

    for(int i = 0; i < n; i++) {
        q.push(arr[i]);
    }

    while(q.size() >= 2) {
        int a = q.front();
        q.pop();

        int b = q.front();
        q.pop();

        int g = gcd(max(a, b), min(a, b));
        q.push((ll) a * b / g);
    }
    return q.front();
}