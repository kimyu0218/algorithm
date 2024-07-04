#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    int sr = left / n + 1;
    int er = right / n + 1;
    int sc = left % n + 1;
    int ec = right % n + 1;

    if(sr == er) {
        for(int j = sc; j <= ec; j++) {
            answer.push_back(max(sr, j));
        }
        return answer;
    }

    for(int j = sc; j <= n; j++) {
        answer.push_back(max(sr, j));
    }
    for(int i = sr + 1; i < er; i++) {
        for(int j = 1; j <= n; j++) {
            answer.push_back(max(i, j));
        }
    }
    for(int j = 1; j <= ec; j++) {
        answer.push_back(max(er, j));
    }
    return answer;
}