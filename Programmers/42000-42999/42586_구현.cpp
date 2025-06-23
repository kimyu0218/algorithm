#include <string>
#include <vector>

using namespace std;

struct info {
    int d_day;
    int cnt;
};


vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;

    int n = progresses.size();
    info deploy = { 0, 0 };
    for(int i = 0; i < n; i++) {
        int speed = speeds[i];
        int r = 100 - progresses[i];
        int d_day = (r / speed) + (r % speed != 0);

        if(d_day <= deploy.d_day) {
            deploy.cnt++;
            continue;
        }

        if(deploy.d_day) {
            answer.push_back(deploy.cnt);
        }
        deploy = { d_day, 1 };
    }
    answer.push_back(deploy.cnt);
    return answer;
}