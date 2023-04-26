#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> split(string input) { // split 함수
    vector<string> result;
    int pos = 0, len = input.length(); // (pos : split 시작위치)
    string tmp = "";

    for(int i = 0; i < len; i++) {
        if(input[i] == ',') {
            result.push_back(input.substr(pos, i-pos));
            pos = i+1; // (새로운 split 시작위치는 콤마 뒤)
        }
    }
    result.push_back(input.substr(pos, len-pos));
    return result;
}

int playTime(string start, string end) { // 재생시간 반환
    int mm = stoi(end.substr(3, 2)) - stoi(start.substr(3, 2));
    int hh = stoi(end.substr(0, 2)) - stoi(start.substr(0, 2));
    return hh * 60 + mm;
}

vector<string> toneComposition(string melody) { // 멜로디 음 구성 반환
    vector<string> tone;
    int idx = 0, len = melody.length();

    while(idx < len) {
        if(idx+1 < len && melody[idx+1] == '#') { // #이 붙어있는 음
            tone.push_back(melody.substr(idx, 2));
            idx += 2;
        }
        else { // #이 붙어있지 않은 음
            tone.push_back(melody.substr(idx, 1));
            idx++;
        }
    }
    return tone;
}

// '방금그곡' 서비스 : 네오가 찾으려는 곡과 music의 구성이 일치하는가
bool justNowService(int play_time, int neo_len, string music, vector<string> &neo_tone) {
    vector<string> music_tone = toneComposition(music); // music의 음 구성
    int music_len = music_tone.size(); // music 길이

    int idx = 0, cnt = play_time - music_len;
    vector<string> radio_tone = music_tone; // 라디오에서 재생된 구간
    while(cnt > 0) {
        radio_tone.push_back(music_tone[idx]);
        cnt--;
        idx = (idx+1) % music_len;
    }

    // 라디오에서 재생된 구간에 네오가 들은 멜로디가 있는가
    int check_range = play_time - neo_len;
    for(int i = 0; i <= check_range; i++) {
        if(neo_tone[0] == radio_tone[i]) {
            bool match = true;
            for(int j = 1; j < neo_len; j++) {
                if(neo_tone[j] != radio_tone[i+j]) {
                    match = false;
                    break;
                }
            }
            if(match) { // 일치하는 구간 발견
                return true;
            }
        }
    }
    return false;
}

string solution(string m, vector<string> musicinfos) { // (musicinfos : 시작시각, 끝난시각, 음악제목, 악보정보)
    string answer = "(None)"; // (초기값 == 일치하는 음악이 없는 경우)
    int time = 0;

    vector<string> neo_tone = toneComposition(m); // 네오가 들은 멜로디의 음 구성
    int neo_len = neo_tone.size(); // 네오가 들은 멜로디 길이

    for(int i = 0; i < musicinfos.size(); i++) {
        vector<string> info = split(musicinfos[i]); // split
        int play_time = playTime(info[0], info[1]); // 음악 재생시간

        if(neo_len > play_time) { // 네오가 들은 멜로디 길이가 재생시간보다 긴 경우
            continue;
        }

        if(justNowService(play_time, neo_len, info[3], neo_tone) && play_time > time) { // 멜로디가 일치하고, 재생시간이 가장 긴 곡 발견
            answer = info[2];
            time = play_time;
        }
    }
    return answer;
}