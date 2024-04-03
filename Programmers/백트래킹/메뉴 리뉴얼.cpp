#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

const int SIZE = 10;
const int MIN_ORDER = 2;

char menu[SIZE];
char combi[SIZE];

map<string, int> courses;

void backtracking(int idx, int size, int start, int n) {
    if(idx == size) {
        string course = "";
        for(int i = 0; i < size; i++) {
            course += combi[i];
        }
        courses[course]++;
        return;
    }

    for(int i = start; i < n; i++) {
        combi[idx] = menu[i];
        backtracking(idx + 1, size, i + 1, n);
    }
}

void make_course(string order) {
    int n = order.length();

    sort(order.begin(), order.end());
    for(int i = 0; i < n; i++) {
        menu[i] = order[i];
    }

    for(int i = 2; i <= n; i++) {
        backtracking(0, i, 0, n);
    }
}

map<int, int> cnt_popular_course(vector<int> course) {
    map<int, int> result;
    for(int i = 0; i < course.size(); i++) {
        int m_cnt = course[i];
        int o_cnt = 0;

        for(auto iter = courses.begin(); iter != courses.end(); iter++) {
            string course_name = iter->first;
            int course_cnt = iter->second;

            if(m_cnt != course_name.length()) {
                continue;
            }
            o_cnt = max(o_cnt, course_cnt);
        }
        result[m_cnt] = o_cnt;
    }
    return result;
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;

    for(int i = 0; i < orders.size(); i++) {
        make_course(orders[i]);
    }

    map<int, int> popular_cnt = cnt_popular_course(course);

    for(auto iter = courses.begin(); iter != courses.end(); iter++) {
        string course_name = iter->first;
        int course_cnt = course_name.length();
        int order_cnt = iter->second;

        if(popular_cnt[course_cnt] == order_cnt && order_cnt >= MIN_ORDER) {
            answer.push_back(course_name);
        }
    }
    return answer;
}