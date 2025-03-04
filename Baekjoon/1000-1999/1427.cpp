#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    string num;
    cin >> num;

    vector<int> digit; // 자릿수 저장하는 배열
    for(int i = 0; i < num.length(); i++)
        digit.push_back(num[i] - '0');

    sort(digit.begin(), digit.end(), greater<> ()); // 내림차순 정렬

    for(int i = 0; i < digit.size(); i++)
        cout << digit[i];

    return 0;
}