#include <iostream>
#include <vector>
#include <map>

using namespace std;

const string ENTER = "ENTER";

int solution(vector<string> chat) {
    int answer = 0;
    int n = chat.size();
    map<string, int> nickname;

    for(int i = 1; i < n; i++) {
        if(chat[i] == ENTER) {
            nickname.clear();
            continue;
        }
        answer += (++nickname[chat[i]] == 1);
    }
    return answer;
}

int main() {
    int n;
    vector<string> chat;

    cin >> n;

    chat.assign(n, "");
    for(int i = 0; i < n; i++) {
        cin >> chat[i];
    }

    cout << solution(chat);
    return 0;
}