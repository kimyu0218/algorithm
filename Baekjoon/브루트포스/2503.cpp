#include <iostream>
#include <vector>

using namespace std;

const int MIN = 123;
const int MAX = 987;

struct info {
    string num;
    int strike, ball;
};

bool is_valid_answer(string answer) {
    if(answer.find('0') != string::npos) {
        return false;
    }
    return answer[0] != answer[1] && answer[0] != answer[2] && answer[1] != answer[2];
}

bool is_possible_answer(string answer, vector<info> minhyuk) {
    for(int i = 0; i < minhyuk.size(); i++) {
        int strike = 0;
        int ball = 0;

        string minhyuk_answer = minhyuk[i].num;
        for(int j = 0; j < 3; j++) {
            if(answer[j] == minhyuk_answer[j]) {
                strike++;
            }
            else if(minhyuk_answer.find(answer[j]) != string::npos) {
                ball++;
            }
        }

        if(strike != minhyuk[i].strike || ball != minhyuk[i].ball) {
            return false;
        }
    }
    return true;
}

int solution(vector<info> minhyuk) {
    int result = 0;
    for(int i = MIN; i <= MAX; i++) {
        string answer = to_string(i);
        if(!is_valid_answer(answer)) {
            continue;
        }
        result += is_possible_answer(answer, minhyuk);
    }
    return result;
}

int main() {
    int n;
    vector<info> minhyuk;

    cin >> n;

    minhyuk.assign(n, {"", 0, 0});
    for(int i = 0; i < n; i++) {
        cin >> minhyuk[i].num >> minhyuk[i].strike >> minhyuk[i].ball;
    }

    cout << solution(minhyuk);
    return 0;
}