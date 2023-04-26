#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const int MENU_CNT = 26;
vector<int> total_cnt; // 메뉴별 총 주문횟수
vector<vector<bool>> receipt; // 손님 영수증

string translate(string input) { // 숫자로 표현된 코스요리 문자 형태로 전환
    string result = "";
    for(int i = 0; i < input.length(); i++) {
        result += (char) (input[i] + 'A');
    }
    return result;
}

void backtracking(string combi, int idx, int cnt, vector<string> &combis) { // cnt개의 단품요리 조합 구하기
    if(combi.length() == cnt) { // cnt개 조합 완성
        combis.push_back(combi);
        return;
    }
    if(idx == MENU_CNT) { // cnt개 조합 만들 수 없음
        return;
    }

    for(int i = idx; i < MENU_CNT; i++) {
        if(total_cnt[i] >= 2) {
            backtracking(combi + (char)i, i+1, cnt, combis);
        }
    }
}

bool isOrdered(string combi, int g, int m_cnt) { // g번째 손님은 combi 조합을 주문했는가
    for(int i = 0; i < m_cnt; i++) {
        if(!receipt[g][combi[i]]) {
            return false;
        }
    }
    return true;
}

vector<string> bestCombi(int m_cnt, int g_cnt) {
    int max_cnt = 0; // 주문 횟수 최댓값
    vector<string> best_combis; // 가장 많이 함께 주문된 단품메뉴 조합

    vector<string> combis;
    backtracking("", 0, m_cnt, combis); // 가능한 단품메뉴 조합 구하기

    for(int i = 0; i < combis.size(); i++) {
        int tmp_cnt = 0; // i번째 단품메뉴 조합의 주문 횟수
        for(int j = 0; j < g_cnt; j++) {
            tmp_cnt += isOrdered(combis[i], j, m_cnt);
        }

        if(tmp_cnt < 2) { // "최소 2명 이상의 손님으로부터 주문되어야 한다" 조건 만족하지 못함
            continue;
        }
        if(tmp_cnt > max_cnt) { // 주문 횟수 최댓값 갱신 -> 단품메뉴 조합 갱신
            max_cnt = tmp_cnt;
            best_combis = {translate(combis[i])};
        }
        else if(tmp_cnt == max_cnt) { // 단품메뉴 조합 추가
            best_combis.push_back(translate(combis[i]));
        }
    }
    return best_combis;
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    int g_cnt = orders.size(); // 손님 수

    // 초기화
    total_cnt.assign(MENU_CNT, 0);
    receipt.assign(g_cnt, vector<bool> (MENU_CNT, false));

    for(int i = 0; i < g_cnt; i++) { // i번째 손님
        string g_order = orders[i];
        for(int j = 0; j < g_order.length(); j++) { // i번째 손님의 주문내역 확인
            int menu = g_order[j] - 'A';
            total_cnt[menu]++;
            receipt[i][menu] = true;
        }
    }

    for(int i = 0; i < course.size(); i++) {
        vector<string> best_combis = bestCombi(course[i], g_cnt); // course[i]개의 코스요리 구성 후보 구하기
        for(int j = 0; j < best_combis.size(); j++) {
            answer.push_back(best_combis[j]);
        }
    }

    sort(answer.begin(), answer.end()); // 오름차순 정렬
    return answer;
}