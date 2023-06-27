#include <iostream>
#include <map>

using namespace std;
const int W = 3, H = 5, NUM = 10;
int nums[NUM][H][W] = { // 숫자별 발광다이오드
        {{1,1,1}, {1,0,1}, {1,0,1}, {1,0,1}, {1,1,1}},
        {{0,0,1}, {0,0,1}, {0,0,1}, {0,0,1}, {0,0,1}},
        {{1,1,1}, {0,0,1}, {1,1,1}, {1,0,0}, {1,1,1}},
        {{1,1,1}, {0,0,1}, {1,1,1}, {0,0,1}, {1,1,1}},
        {{1,0,1}, {1,0,1}, {1,1,1}, {0,0,1}, {0,0,1}},
        {{1,1,1}, {1,0,0}, {1,1,1}, {0,0,1}, {1,1,1}},
        {{1,1,1}, {1,0,0}, {1,1,1}, {1,0,1}, {1,1,1}},
        {{1,1,1}, {0,0,1}, {0,0,1}, {0,0,1}, {0,0,1}},
        {{1,1,1}, {1,0,1}, {1,1,1}, {1,0,1}, {1,1,1}},
        {{1,1,1}, {1,0,1}, {1,1,1}, {0,0,1}, {1,1,1}}
};
int bits[NUM];

void transformToBit() { // 발광다이오드 배열 -> 비트
    for(int i = 0; i < NUM; i++) { // i : 시계 숫자
        for(int j = 0; j < H*W; j++) {
            int row = j / W;
            int col = j % W;
            if(nums[i][row][col]) { // 발광 다이오드가 켜진 경우
                bits[i] |= (1 << j);
            }
        }
    }
}

void transformToBit2(int clock[][4*W], int bit_clock[]) {
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < H*W; j++) {
            int row = j / W;
            int col = j % W;
            if(clock[row][col+i*W]) { // 발광 다이오드가 켜진 경우
                bit_clock[i] |= (1 << j);
            }
        }
    }
}

int closeNum(int num) {
    for(int i = 0; i < NUM; i++) {
        int all = bits[i] | num;
        if(all != bits[i]) { // i를 만들 수 없는 경우 (== 켜지지 않아야 하는 발광다이오드가 켜진 경우 pass)
            continue;
        }
        return i;
    }
}

string earlyTime(int clock[][4*W]) { // 가능한 가장 빠른 시간 반환
    int bit_clock[4] = {0, }; // (i번째 숫자의 비트값)

    transformToBit(); // 0~9까지의 숫자 배열에서 비트로 변환
    transformToBit2(clock, bit_clock); // 입력받은 시계 비트로 변환

    string answer = "";
    for(int i = 0; i < 4; i++) { // 숫자 4자리
        int num = closeNum(bit_clock[i]);
        answer += to_string(num);
        if(i == 1) {
            answer += ":";
        }
    }
    return answer;
}

int main() {
    char ch;
    string input;
    int clock[H][4*W];
    map<char, int> m = {{'#', 1}, {'.', 0}}; // on (#/1) & off (./0)

    for(int i = 0; i < H; i++) { // 디지털 시계 입력
        for(int j = 0; j < 4*W; j++) {
            cin >> ch;
            clock[i][j] = m[ch];
        }
    }

    cout << earlyTime(clock);
    return 0;
}