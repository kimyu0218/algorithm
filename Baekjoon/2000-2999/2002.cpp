#include <iostream>
#include <map>
#include <vector>

using namespace std;

int cnt_overtaking(int n, vector<int> seq) { // 추월 차량 세기
    int cnt = 0;
    for(int i = 0; i < n; i++) { // i번째로 터널을 빠져나간 차량
        for(int j = i+1; j < n; j++) { // j : i보다 뒤에 터널을 빠져나간 차량
            // j차량이 i번째 보다 먼저 터널에 들어간 경우 == 추월
            if(seq[j] < seq[i]) { cnt++; break; }
        }
    }
    return cnt;
}

int main() {
    int n;
    cin >> n;

    map<string, int> in;
    string num;
    for(int i = 0; i < n; i++) { // 들어가는 차량 기록
        cin >> num;
        in[num] = i;
    }

    // vector[i] = j
    // i번째로 터널을 빠져 나간 차량의 들어온 순서
    vector<int> out;
    for(int i = 0; i < n; i++) { // 나가는 차량 기록
        cin >> num;
        out.push_back(in[num]);
    }

    cout << cnt_overtaking(n, out);
    return 0;
}