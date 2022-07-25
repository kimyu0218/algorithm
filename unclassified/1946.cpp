#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> testNum, passNum; // 테스트 케이스 수, 테스트 케이스별 합격자 수
struct grade { // 성적 구조체
    int document;
    int interview;
};
vector<grade> test;

bool cmp(const grade &t1, const grade &t2) { // 서류 점수 오름차순
    return t1.document < t2.document;
}

void findPass(int index) { // 합격자 찾기
    int pass = 1; // 서류 점수 1등 무조건 합격
    int cmp = test[0].interview;
    for(int i = 1 ; i < testNum[index]; i++) {
        if(cmp > test[i].interview) {
            pass += 1;
            cmp = test[i].interview;
        }
    }
    passNum[index] = pass;
}

int main() {
    int t;
    cin >> t;

    testNum.assign(t , 0);
    passNum.assign(t , 0);
    for(int i = 0; i < t; i++) {
        cin >> testNum[i];
        test.assign(testNum[i], {0,0});
        for(int j = 0; j < testNum[i]; j++)
            cin >> test[j].document >> test[j].interview;

        sort(test.begin(), test.end(), cmp); // 서류 점수 오름차순
        findPass(i); // 합격자 찾기
    }
    for(int i = 0; i < t; i++) // 테스트 케이스별 합격자 수 출력
        cout << passNum[i] << '\n';
    return 0;
}