#include <vector>
#include <string>
#include <algorithm>

using namespace std;
const int NUM = 65536;

vector<string> multiSet(string s) {
    vector<string> set;
    for(int i = 0; i <= s.length()-2; i++) {
        // 두 글자 모두 특수문자가 아닌 경우
        if(((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z'))
           && ((s[i+1] >= 'A' && s[i+1] <= 'Z') || (s[i+1] >= 'a' && s[i+1] <= 'z'))) {
            if(s[i] >= 'A' && s[i] <= 'Z') { // 대문자인 경우 소문자로 변환
                s[i] += ('a' - 'A');
            }
            if(s[i+1] >= 'A' && s[i+1] <= 'Z') { // 대문자인 경우 소문자로 변환
                s[i+1] += ('a' - 'A');
            }
            set.push_back(s.substr(i, 2));
        }
    }
    sort(set.begin(), set.end()); // 오름차순 정렬
    return set;
}

int cntIntersection(vector<string> &set1, vector<string> &set2) { // 교집합 원소 개수 구하기
    int cnt = 0;
    int idx1 = 0, idx2 = 0;
    int len1 = set1.size(), len2 =  set2.size();

    while(idx1 < len1 && idx2 < len2) {
        if(set1[idx1] > set2[idx2]) {
            idx2++;
        }
        else if(set1[idx1] < set2[idx2]) {
            idx1++;
        }
        else { // 같은 문자열 발견
            string word = set1[idx1];
            int cnt1 = 0, cnt2 = 0;
            while(idx1 < len1 && word == set1[idx1]) {
                cnt1++;
                idx1++;
            }
            while(idx2 < len2 && word == set2[idx2]) {
                cnt2++;
                idx2++;
            }
            cnt += min(cnt1, cnt2);
        }
    }
    return cnt;
}

int solution(string str1, string str2) {
    vector<string> set1 = multiSet(str1);
    vector<string> set2 = multiSet(str2);

    int inter_cnt = cntIntersection(set1, set2); // 교집합 원소 개수
    int union_cnt = set1.size() + set2.size() - inter_cnt; // 합집합 원소 개수

    if(union_cnt == 0) {
        return 1 * NUM;
    }
    return inter_cnt * NUM / union_cnt;
}