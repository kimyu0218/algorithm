#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
vector<int> result;

int fashionCheck(map<string, int> &kinds) {
    int day = 1;
    for(auto & kind : kinds)
        day *= (kind.second + 1); // (해당 의상 가짓수 + 해당 의상을 안 입는 경우)
    return day - 1; // (-1 : 아무것도 입지 않는 경우)
}

int main() {
    int t, n;
    string kind, cloth; // 의상 종류, 의상 이름
    cin >> t;

    result.assign(t, 0);
    for(int i = 0; i < t; i++) {
        cin >> n;

        map<string, int> kinds; // (의상 종류, 해당 의상 종류 개수)
        for(int j = 0; j < n; j++) {
            cin >> cloth >> kind;
            if(kinds.find(kind) == kinds.end()) kinds.insert({kind, 1});
            else kinds[kind]++;
        }
        result[i] = fashionCheck(kinds);
    }

    for(int i = 0; i < t; i++) // 결과 출력
        cout << result[i] << '\n';
    return 0;
}