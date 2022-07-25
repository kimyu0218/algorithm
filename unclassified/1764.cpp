#include <iostream>
#include <set>
#include <algorithm>

using namespace  std;
set<string> nonListen, result;

int main() {
    int n, m, num = 0;
    char input[21];
    cin >> n >> m;

    while(n--) { // 듣도 못한 사람 입력
        scanf("%s", input);
        nonListen.insert(input);
    }

    while(m--) {
        scanf("%s", input); // 보도 못한 사람 입력
        if(nonListen.find(input) != nonListen.end()) { // 듣도 보도 못한 사람 구하기
            num++;
            result.insert(input);
        }
    }

    cout << num << '\n';
    for(const auto & iter : result) // 듣도 보도 못한 사람 출력
        cout << iter << '\n';
    return 0;
}