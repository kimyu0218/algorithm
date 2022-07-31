#include <iostream>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;

    vector<int> clothes(n+1, 1); // 체육복 수 세팅
    for(int i = 0; i < lost.size(); i++) clothes[lost[i]]--;
    for(int i = 0; i < reserve.size(); i++) clothes[reserve[i]]++;

    for(int i = 1; i <= n; i++) {
        if(clothes[i]) continue;
        // i가 체육복이 없는 경우
        if(clothes[i-1] == 2) { // 앞번호가 여벌 체육복이 있는 경우
            clothes[i-1]--;
            clothes[i]++;
        }
        else if(clothes[i+1] == 2) { // 뒷번호가 여벌 체육복이 있는 경우
            clothes[i+1]--;
            clothes[i]++;
        }
    }

    for(int i = 1; i <= n; i++) {
        if(clothes[i]) answer++;
    }
    return answer;
}

int main() {
    // 예제 1
    int n = 5;
    vector<int> lost = {2, 4};
    vector<int> reserve = {1, 3, 5};

    // 예제 2
    /*int n = 5;
    vector<int> lost = {2, 4};
    vector<int> reserve = {3};*/

    // 예제 3
    /*int n = 3;
    vector<int> lost = {3};
    vector<int> reserve = {1};*/

    cout << solution(n, lost, reserve);
    return 0;
}