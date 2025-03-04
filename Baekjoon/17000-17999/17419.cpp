#include <iostream>

using namespace std;

int main() {
    int n, answer = 0;
    string binary;

    cin >> n;
    cin >> binary;
    for(int i = 0; i < n; i++) {
        if(binary[i] == '1') {
            answer++;
        }
    }

    cout << answer;
    return 0;
}