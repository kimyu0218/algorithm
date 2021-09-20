#include <iostream>

using namespace std;

void ignore(int W0, int l0, int D, int l, int A) { // 기초 대사량 변화 무시
    int weight = W0;
    bool safe = true;
    while(D--) {
        weight += l - (A+l0);
        if(weight <= 0 || l0 <= 0) {
            cout << "Danger Diet";
            safe = false;
            break;
        }
    }
    if(safe) cout << weight << ' ' << l0 << ' ';
}

int consider(int W0, int l0, int T, int D, int l, int A) { // 기초 대사량 변화 고려
    int tmp, weight = W0;
    while(D--) {
        tmp = l - (A+l0);
        if(abs(tmp) > T) {// 기초 대사량 변화
            l0 += (int) tmp / 2;
            if(tmp % 2 && tmp < 0) l0--;
        }
        weight += tmp;
        if(weight <= 0 || l0 <= 0) {
            return 0;
        }
    }
    cout << weight << ' ' << l0 << ' ';
    return l0;
}

void diet(int W0, int l0, int T, int D, int l, int A) { // 다이어트
    int change_rate;
    ignore(W0, l0, D, l, A); // 기초 대사량 변화 무시
    cout << '\n';
    change_rate = consider(W0, l0, T, D, l, A); // 기초 대사량 변화 고려
    if(change_rate) {
        if(l0 - change_rate > 0) cout << "YOYO";
        else cout << "NO";
    }
    else cout << "Danger Diet";
}

int main() {
    int W0, l0, T, D, l, A;
    cin >> W0 >> l0 >> T; // 전 체중, 전 기초 대사량, 기초 대사량 변화
    cin >> D >> l >> A;   // 기간, 에너지 섭취량, 활동 대사량

    diet(W0, l0, T, D, l, A);
    return 0;
}