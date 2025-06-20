#include <string>
#include <vector>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    int n = goal.size();
    int p1 = 0;
    int p2 = 0;

    for(int i = 0; i < n; i++) {
        if(cards1[p1] == goal[i]) {
            p1++;
        }
        else if(cards2[p2] == goal[i]) {
            p2++;
        }
        else {
            return "No";
        }
    }
    return "Yes";
}