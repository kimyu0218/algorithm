#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

const int MAX = 8;
bool visited[MAX];
int col[MAX]; // (항상 오름차순으로 정렬된 상태)
set<string> key; // 후보키 집합

set<string> makeSubset(int n) { // 부분집합 만들기
    set<string> subset;

    // 원소 1개짜리 부분집합 만들기
    for(int i = 0; i < n; i++) {
        subset.insert(to_string(col[i]));
    }

    // 원소들이 오름차순으로 정렬된 부분집합 만들기
    for(int i = 1; i < n; i++) {
        set<string> tmp;
        char ch = col[i]-'0'; // 추가하려는 속성

        for(auto iter = subset.begin(); iter != subset.end(); iter++) {
            string str = *iter;
            // 1. 속성 추가 불가 : 추가하려는 속성이 str[0]보다 뒷순서 -> str의 오름차순 정렬상태를 해침
            if(ch >= str[0]) {
                break;
            }
            // 2. 속성 추가 가능
            tmp.insert(str + to_string(col[i]));
        }

        for(auto iter = tmp.begin(); iter != tmp.end(); iter++) { // subset에 추가
            subset.insert(*iter);
        }
    }
    return subset;
}

bool isMinimal(int n) { // 1. 최소성을 만족하는가
    set<string> subset = makeSubset(n); // col의 부분집합 구하기
    for(auto iter = subset.begin(); iter != subset.end(); iter++) {
        if(key.find(*iter) != key.end()) { // col의 부분집합이 이미 후보키임 -> 최소성 불만족
            return false;
        }
    }
    return true;
}

bool isUnique(int n, vector<vector<string>> &relation) { // 2. 유일성을 만족하는가
    int card = relation.size(); // 차수 (= 튜플의 개수)
    set<string> tuples;

    for(int i = 0; i < card; i++) { // i : 튜플 가리킴
        string tuple = "";
        for(int j = 0; j < n; j++) { // j : 속성 가리킴
            tuple += relation[i][col[j]] + '-';
        }
        tuples.insert(tuple);
    }
    return card == tuples.size(); // col의 속성들로 이루어진 튜플들이 차수와 같은가
}

bool isCandidateKey(int n, vector<vector<string>> &relation) { // col이 후보키가 될 수 있는가
    if(!isMinimal(n)) { // 1. 최소성 검사
        return false;
    }
    return isUnique(n, relation); // 2. 유일성 검사
}

void backtracking(int cnt, int idx, int n, int degree, vector<vector<string>> &relation) {
    if(cnt == n) { // 기저조건 : n개의 속성 고르기 완료
        if(isCandidateKey(n, relation)) { // col에 들어있는 n개의 속성들이 후보키가 될 수 있음
            string k = "";
            for(int i = 0; i < n; i++) {
                k += to_string(col[i]);
            }
            key.insert(k); // 후보키에 해당 속성 인덱스 추가
        }
        return;
    }

    for(int i = idx; i < degree; i++) { // i : 속성 가리킴
        visited[i] = true; // i번째 속성 후보키에 사용
        col[cnt] = i;
        backtracking(cnt+1, i+1, n, degree, relation);
        visited[i] = false; // i번째 속성 후보키에 사용 취소
    }
}

int solution(vector<vector<string>> relation) {
    int degree = relation[0].size(); // 차수 (= 속성의 개수)

    for(int i = 1; i <= degree; i++) { // (후보키는 속성 1~n개의 조합으로 만들 수 있음)
        backtracking(0, 0, i, degree, relation);
    }
    return key.size(); // 후보키 개수 리턴
}