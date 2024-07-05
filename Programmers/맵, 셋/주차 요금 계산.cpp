#include <string>
#include <vector>
#include <map>
#include <cmath>

using namespace std;

const string LAST_TIME = "23:59"; // 마지막 출차 시간

vector<string> recordInfo(string record) { // 차량 기록 반환
    vector<string> info; // {시각, 차량 번호, 내역}

    string tmp = "";
    for(int i = 0; i < record.length(); i++) {
        if(record[i] == ' ') { // split 지점
            info.push_back(tmp);
            tmp = "";
            continue;
        }
        tmp += record[i];
    }
    info.push_back(tmp); // 내역 정보 push
    return info;
}

int computeTime(int hh, int mm) {
    return hh * 60 + mm;
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    map<string, int> bill; // 주차이력 {차량 번호, 누적 주차시간}
    map<string, string> parking; // 주차장

    for(int i = 0; i < records.size(); i++) {
        vector<string> info = recordInfo(records[i]);

        string time = info[0], num = info[1], flag = info[2];
        if(flag == "IN") { // IN : 입차기록인 경우
            parking[num] = time; // 입차시간 기록
        }
        else { // OUT : 출차기록인 경우
            string in_time = parking[num];
            int park_time = computeTime(stoi(time.substr(0, 2)), stoi(time.substr(3, 2)))
                    - computeTime(stoi(in_time.substr(0, 2)), stoi(in_time.substr(3, 2)));
            bill[num] += park_time; // 누적 주차시간 갱신
            parking.erase(num); // 출차
        }
    }

    // 아직 출차하지 않은 차가 있다면 출차
    for(auto iter = parking.begin(); iter != parking.end(); iter++) {
        string num = iter->first, in_time = iter->second;
        int park_time = computeTime(stoi(LAST_TIME.substr(0, 2)), stoi(LAST_TIME.substr(3, 2)))
                        - computeTime(stoi(in_time.substr(0, 2)), stoi(in_time.substr(3, 2)));
        bill[num] += park_time; // 누적 주차시간 갱신
    }

    // 정산
    for(auto iter = bill.begin(); iter != bill.end(); iter++) {
        int time = iter->second; // 누적 주차시간
        int basic_time = fees[0], basic_cost = fees[1];
        int unit_time = fees[2], unit_cost = fees[3];
        if (time >= basic_time) {
            answer.push_back(basic_cost + ceil((double) (time - basic_time) / unit_time) * unit_cost);
        }
        else { // 기본 요금만 적용
            answer.push_back(basic_cost);
        }
    }
    return answer;
}