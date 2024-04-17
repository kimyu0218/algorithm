#include <string>
#include <vector>
#include <map>

using namespace std;

const int TERM = 10;

map<string, int> make_wish_list(vector<string> want, vector<int> number) {
    map<string, int> m;
    for(int i = 0; i < want.size(); i++) {
        m[want[i]] = number[i];
    }
    return m;
}

bool can_register(map<string, int> items, map<string, int> wish_list) {
    for(auto iter = wish_list.begin(); iter != wish_list.end(); iter++) {
        string item = iter->first;
        int cnt = iter->second;

        if(items[item] != cnt) {
            return false;
        }
    }
    return true;
}

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    map<string, int> wish_list = make_wish_list(want, number);

    for(int i = 0; i <= discount.size() - TERM; i++) {
        map<string, int> items;
        for(int j = i; j < i + TERM; j++) {
            items[discount[j]]++;
        }

        answer += can_register(items, wish_list);
    }
    return answer;
}