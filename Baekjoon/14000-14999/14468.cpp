#include <iostream>
#include <vector>

using namespace std;

const int COW = 26;
const int POINT = 52;

struct info {
  int start, end;
};

int solution(string input) {
    int answer = 0;
    vector<info> path (COW, {-1, -1});

    for(int i = 0; i < POINT; i++) {
        int ch = input[i] - 'A';

        if(path[ch].start == -1) {
            path[ch].start = i;
        }
        else {
            path[ch].end = i;
        }
    }

    for(int i = 0; i < COW; i++) {
        for (int j = 0; j < COW; j++) {
            if (i == j) {
                continue;
            }
            if(path[i].start < path[j].start && path[j].start < path[i].end && path[i].end < path[j].end) {
                answer++;
            }
        }
    }
    return answer;
}

int main() {
  string input;

  cin >> input;

  cout << solution(input);
  return 0;
}