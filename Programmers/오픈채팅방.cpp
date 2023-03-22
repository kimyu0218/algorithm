#include <string>
#include <vector>
#include <map>

using namespace std;

vector<string> split(string s) { // 문자열 공백 기준으로 split
    vector<string> result;

    string tmp = "";
    for(int i = 0; i < s.length(); i++) {
        if(s[i] == ' ') { // split 지점
            result.push_back(tmp);
            tmp = "";
            continue;
        }
        tmp += s[i];
    }
    result.push_back(tmp);

    return result;
}

map<string, string> matchNickname(int n, vector<string> &record) { // uid와 닉네임 매핑
    map<string, string> nickname; // uid : 닉네임

    for(int i = 0; i < n; i++) {
        vector<string> r = split(record[i]);
        string action = r[0], uid = r[1];

        if(action == "Enter") {
            string nick = r[2];
            nickname[uid] = nick;
        }
        else if(action == "Change") {
            string nick = r[2];
            nickname[uid] = nick;
        }
    }
    return nickname;
}

vector<string> chatMessage(int n, vector<string> &record, map<string, string> &nickname) { // 채팅방에 출력되는 메시지 반환
    vector<string> message;

    for(int i = 0; i < n; i++) {
        vector<string> r = split(record[i]);
        string action = r[0], uid = r[1];

        if(action == "Enter") {
            message.push_back(nickname[uid] + "님이 들어왔습니다.");
        }
        else if(action == "Leave") {
            message.push_back(nickname[uid] + "님이 나갔습니다.");
        }
    }

    return message;
}

vector<string> solution(vector<string> record) {
    int n = record.size();
    map<string, string> nickname = matchNickname(n, record);
    return chatMessage(n, record, nickname);
}