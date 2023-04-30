#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

typedef pair<int, int> pi;

pi hhmmToInteger(string time) { // 시간 형태 : 문자열 -> 정수
    int hh = stoi(time.substr(0, 2));
    int mm = stoi(time.substr(3, 2));
    return {hh, mm};
}

string hhmmToString(string hh, string mm) { // 시간 형태 : 정수 -> 문자열
    string hhmm = "";
    hhmm += (hh.length() < 2) ? ("0" + hh + ":") : hh + ":";
    hhmm += (mm.length() < 2) ? ("0" + mm) : mm;
    return hhmm;
}

vector<pi> shuttleTimeTable(int n, int t) { // 셔틀버스 시간표 만들기
    vector<pi> shuttle; // 셔틀버스 시간표 (first : hh, second : mm)
    int hh = 9, mm = 0; // 셔틀 시작시간 09:00
    shuttle.push_back({hh, mm});
    for(int i = 0; i < n; i++) { // n회 t분 간격 도착
        mm += t;
        if(mm >= 60) {
            mm -= 60;
            hh++;
        }
        shuttle.push_back({hh, mm});
    }
    return shuttle;
}

vector<stack<pi>> makeWaitingLine(int n, int m, vector<pi> &shuttle, vector<string> &timetable) { // 시간대별 셔틀버스 대기줄 만들기
    vector<stack<pi>> waiting_line (n, stack<pi>()); // 시간대별 셔틀버스 대기줄
    int c_idx, s_idx = 0; // 크루원 인덱스, 셔틀 인덱스
    for(c_idx = 0; c_idx < timetable.size(); c_idx++) {
        pi crew = hhmmToInteger(timetable[c_idx]); // 크루원의 대기열 도착시간

        // 1. 크루원이 탈 수 있는 시간대 찾기 (== 크루원 도착시간이 셔틀 도착시간 이후인 경우, 다음 셔틀 탑승)
        // 2. 크루원이 탈 수 있는 셔틀 찾기 (== 크루원이 타려는 셔틀 버스가 만석인 경우, 다음 셔틀 탑승)
        while(s_idx < n && (crew > shuttle[s_idx] || waiting_line[s_idx].size() == m)) {
            s_idx++;
        }
        if(s_idx == n) { // 3. 탈 수 있는 셔틀 없는 경우 break
            break;
        }
        waiting_line[s_idx].push(crew); // 크루원 셔틀 탑승
    }
    return waiting_line;
}

string solution(int n, int t, int m, vector<string> timetable) {
    sort(timetable.begin(), timetable.end()); // 타임테이블 오름차순 정렬

    vector<pi> shuttle = shuttleTimeTable(n, t); // 셔틀버스 시간표
    vector<stack<pi>> waiting_line = makeWaitingLine(n, m, shuttle, timetable); // 시간대별 셔틀버스 대기줄

    int s_idx = n-1; // 콘이 탑승하려는 셔틀 인덱스
    if(waiting_line[s_idx].size() < m) { // 1. 셔틀 도착시간에 탑승할 수 있는 경우
        return hhmmToString(to_string(shuttle[s_idx].first), to_string(shuttle[s_idx].second));
    }

    pi con, next; // 콘의 대기열 도착시간, 콘 다음 사람의 대기열 도착시간
    while(s_idx >= 0 && waiting_line[s_idx].size() >= m) {  // 2. 셔틀 대기줄이 만석이라 도착시간에 탑승할 수 없는 경우
        if(waiting_line[s_idx].size() > m || s_idx != n-1) {
            while(waiting_line[s_idx].size() > m) { // 콘 다음 사람의 대기열 도착시간 찾기
                next = waiting_line[s_idx].top();
                waiting_line[s_idx].pop();
            }
            while(!waiting_line[s_idx].empty() && next == waiting_line[s_idx].top()) { // 콘 다음 사람과 같은 시간에 도착한 사람은 없는가
                waiting_line[s_idx].pop(); // 콘 다음 사람과 같은 시간에 도착한 사람들 제거
            }
            if(waiting_line[s_idx].empty()) { // 해당 셔틀버스 탑승 불가
                s_idx--;
                continue;
            }
        }

        con = waiting_line[s_idx].top();
        if(--con.second < 0) {
            con.second += 60;
            con.first--;
        }
        return hhmmToString(to_string(con.first), to_string(con.second));
    }

    // 3. 셔틀 대기줄의 사람들보다 더 빨리 도착해야 하는 경우
    con = next;
    if(--con.second < 0) {
        con.second += 60;
        con.first--;
    }
    return hhmmToString(to_string(con.first), to_string(con.second));
}