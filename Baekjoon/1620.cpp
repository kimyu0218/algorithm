#include <iostream>
#include <map>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    map<string, int> dic1; // (이름, 번호)
    map<int, string> dic2; // (번호, 이름)

    string name;
    for(int i = 0; i < n; i++) { // 도감 입력
        cin >> name;
        dic1[name] = i+1;
        dic2[i+1] = name;
    }

    string key;
    while(m--) { // 문제 풀기
        cin >> key;
        if(key[0] >= 'A' && key[0] <= 'Z') cout << dic1[key] << '\n'; // 포켓몬 번호 출력
        else cout << dic2[stoi(key)] << '\n'; // 포켓몬 이름 출력
    }
    return 0;
}