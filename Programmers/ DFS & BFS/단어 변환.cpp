#include <string>
#include <vector>
#include <queue>

using namespace std;

bool can_change(string prev, string next, int len) { // 단어 변환 가능 여부 반환
    int diff = 0;
    for(int i = 0; i < len; i++) {
        if(prev[i] != next[i]) diff++;
    }
    return (diff == 1);
}

int solution(string begin, string target, vector<string> words) {
    int size = words.size(), len = words[0].length(); // 단어 개수, 단어 길이
    vector<int> step(size, 0); // 단계 저장
    vector<bool> visited(size, false); // 방문 여부 저장
    queue<int> q;

    for(int i = 0; i < size; i++) { // begin에서 words[i]로 변환 가능한 단어 찾기
        if(can_change(begin, words[i], len)) {
            visited[i] = true;
            step[i] = 1;
            q.push(i);
        }
    }

    while(!q.empty()) {
        int idx = q.front();
        q.pop();

        if(words[idx] == target) return step[idx]; // 변환 완료

        for(int i = 0; i < size; i++) {
            if(visited[i]) continue; // 이미 방문한 단어 pass

            if(can_change(words[idx], words[i], len)) {
                visited[i] = true;
                step[i] = step[idx] + 1;
                q.push(i);
            }
        }
    }
    return 0;
}