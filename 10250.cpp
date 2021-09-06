#include <iostream>
#include <vector>

using namespace std;
vector<int> roomNo;

void roomNumber(int h, int w, int n, int i) { // 호텔 룸넘버 찾기
    int floor, room;
    if(n%h) {
        floor = n%h;
        room = (int) n/h + 1;
    }
    else {
        floor = h;
        room = n/h;
    }
    roomNo[i] = floor*100 + room;
}

int main() {
    int t, h, w, n;
    cin >> t;

    roomNo.assign(t, 0);
    for(int i = 0; i < t; i++) {
        cin >> h >> w >> n;
        roomNumber(h, w, n, i); // 호텔 룸넘버 찾기
    }
    for(int i = 0; i < t; i++) // 호텔 룸넘버 출력
        cout << roomNo[i] << '\n';
    return 0;
}