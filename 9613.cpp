#include <iostream>
#include <vector>

using namespace std;

int gcdRecursion(int a, int b) { // gcd ±¸ÇÏ±â
    if(b == 0) return a;
    return gcdRecursion(b, a%b);
}

long long gcdSum(vector<int> &num) { // gcd ÇÕ ±¸ÇÏ±â
    long long result = 0;
    for(int i = 0; i < num.size()-1; i++) {
        for(int j = i+1; j < num.size(); j++)
            result += gcdRecursion(max(num[i], num[j]), min(num[i], num[j]));
    }
    return result;
}

int main() {
    int t, n;
    vector<int> num;
    cin >> t;

    while(t--) {
        cin >> n;
        num.assign(n, 0);
        for(int i = 0; i < n; i++)
            cin >> num[i];
        cout << gcdSum(num) << '\n';
    }
    return 0;
}