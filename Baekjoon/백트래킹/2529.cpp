#include <iostream>
#include <vector>

using namespace std;

int k;
int arr[10]; // 수열 저장하는 배열
bool check[10] = { false, }; // 사용 여부 저장하는 배열
vector<char> op; // 부등호 저장하는 배열
vector<string> result;

void backtracking(int cnt, int start, int end) { // (start, end : 탐색 범위)
    if(cnt == k+1) { // k+1 문자열 완성
        string temp = "";
        for(int i = 0; i < cnt; i++)
            temp += to_string(arr[i]);
        result.push_back(temp);
        return;
    }

    for(int i = start; i <= end; i++) {
        if(check[i]) continue; // 이미 사용된 숫자 pass
        arr[cnt] = i; check[i] = true;
        if(op[cnt] == '<') backtracking(cnt+1, i+1, 9); // 부등호가 < 인 경우 : 현재값보다 큰 수부터 탐색
        else backtracking(cnt+1, 0, i-1); // 부등호가 > 인 경우 : 현재값보다 작은 수까지 탐색
        check[i] = false;
    }
}

int main() {
    cin >> k;

    op.assign(k, '\0');
    for(int i = 0; i < k; i++) // 부등호 입력
        cin >> op[i];

    backtracking(0,0,9);
    cout << result[result.size()-1] << '\n';
    cout << result[0];
    return 0;
}