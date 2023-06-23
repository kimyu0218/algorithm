#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
const int MAX = 7;

int discount[MAX];
vector<vector<int>> cases;

bool cmp(const vector<int> &arr1, const vector<int> &arr2) {
    if(arr1[0] != arr2[0]) { // 1. 플러스 가입자 많은 순
        return arr1[0] > arr2[0];
    }
    return arr1[1] > arr2[1]; // 2. 판매액 많은 순
}

vector<int> buyEmoticons(int n, int m, vector<vector<int>> &users, vector<int> &emoticons) {
    int join = 0, sales = 0;

    for(int i = 0; i < n; i++) { // i : 사용자
        int rate = users[i][0]; // 일정 비율
        int price = users[i][1]; // 일정 가격
        int sum = 0; // i 사용자의 이모티콘 구매액

        for(int j = 0; j < m; j++) { // j : 이모티콘
            if(discount[j] >= rate) { // 1. 이모티콘 구매하기
                sum += emoticons[j] * ((double)1 - (double) discount[j]/100);
            }
            if(sum >= price) { // 2. 이모티콘 플러스 가입하기
                sum = 0; // 이전에 구매한 이모티콘 구매 모두 취소
                join++;
                break;
            }
        }
        sales += sum;
    }

    return {join, sales};
}

void backtracking(int idx, int m, int n, vector<int> &emoticons, vector<vector<int>> &users) {
    if(idx == m) { // m개의 이모티콘 할인율 설정 완료
        // m개의 이모티콘 할인율이 정해졌을 때, 이모티콘 플러스 가입자 수와 이모티콘 판매액 계산하기
        vector<int> result = buyEmoticons(n, m, users, emoticons);
        cases.push_back(result);
        return;
    }

    for(int i = 10; i <= 40; i += 10) {
        discount[idx] = i;
        backtracking(idx+1, m, n, emoticons, users);
    }
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    int n = users.size(), m = emoticons.size();
    backtracking(0, m, n, emoticons, users);

    sort(cases.begin(), cases.end(), cmp);
    return cases[0];
}