#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
vector<string> word; // 영어 단어장
map<string, int> temp; // 영단어 빈도 저장하는 맵

bool cmp(string &w1, string &w2) { // 정렬 기준
    if(temp[w1] != temp[w2]) return temp[w1] > temp[w2];     // 1. 자주 나오는 단어일수록 앞에 배치
    if(w1.size() != w2.size()) return w1.size() > w2.size(); // 2. 단어의 길이가 길수록 앞에 배치
    return w1 < w2; // 3. 사전순
}

int main() {
    int n, m;
    string input;
    cin >> n >> m;

    while(n--) {
        cin >> input;
        if(input.length() < m) continue; // 길이가 m 미만인 경우 단어장에 저장하지 않음
        if(!temp[input]) word.push_back(input); // 새로운 단어 추가
        temp[input]++; // 단어 빈도수 변경
    }
    sort(word.begin(), word.end(), cmp); // 정렬

    for(auto & i : word) // 단어장 출력
        cout << i << '\n';
    return 0;
}