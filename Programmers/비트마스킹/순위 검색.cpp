#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <algorithm>

using namespace std;

const int CAT = 4;
map<string, int> cat01 = {{"cpp", 1}, {"java", 2}, {"python", 3}};
map<string, int> cat02 = {{"backend", 1}, {"frontend", 2}};
map<string, int> cat03 = {{"junior", 1}, {"senior", 2}};
map<string, int> cat04 = {{"chicken", 1}, {"pizza", 2}};

vector<int> vec[4][3][3][3];

vector<int> solution(vector<string> info, vector<string> query) {
    int n1 = info.size(), n2 = query.size();

    for(int i = 0; i < n1; i++) {
        istringstream ss(info[i]);
        string language, position, career, food;
        int score;

        ss >> language >> position >> career >> food >> score;
        int arr[CAT] = {cat01[language], cat02[position], cat03[career], cat04[food]};

        // 조합 구하기 (1 << CAT : 16개의 조합 == 2 * 2 * 2 * 2)
        for(int j = 0; j < (1 << CAT); j++) {
            int idx[CAT] = {0, };
            for(int k = 0; k < CAT; k++) { // j와 & 연산하여 0~3까지 비교
                if(j & (1 << k)) { // k가 포함되어 있는가
                    idx[k] = arr[k];
                }
            }
            vec[idx[0]][idx[1]][idx[2]][idx[3]].push_back(score);
        }
    }


    // 정렬
    for(int i = 0; i < 4; i++) { // i : 개발언어
        for(int j = 0; j < 3; j++) { // j : 지원직군
            for(int k = 0; k < 3; k++) { // k : 경력구분
                for(int l = 0; l < 3; l++) { // l : 소울푸드
                    sort(vec[i][j][k][l].begin(), vec[i][j][k][l].end());
                }
            }
        }
    }

    vector<int> answer (n2, 0);
    for(int i = 0; i < n2; i++) {
        istringstream ss(query[i]);
        string language, position, career, food, tmp;
        int score;

        ss >> language >> tmp >> position >> tmp >> career >> tmp >> food >> score;
        auto& start = vec[cat01[language]][cat02[position]][cat03[career]][cat04[food]];
        auto low = lower_bound(start.begin(), start.end(), score);
        answer[i] = start.end()-low;
    }
    return answer;
}