#include <iostream>

using namespace std;

const int WEEKDAY = 5;

string week[WEEKDAY][2];

int solution() {
    int answer = 0;
    for(int i = 0; i < WEEKDAY; i++) {
        string start = week[i][0];
        string end = week[i][1];

        int sh = stoi(start.substr(0, 2));
        int sm = stoi(start.substr(3, 2));
        int eh = stoi(end.substr(0, 2));
        int em = stoi(end.substr(3, 2));

        int hour = eh - sh;
        int min = em - sm;
        answer += (hour * 60) + min;
    }
    return answer;
}

int main() {
    for(int i = 0; i < WEEKDAY; i++) {
        cin >> week[i][0] >> week[i][1];
    }

    cout << solution();
    return 0;
}