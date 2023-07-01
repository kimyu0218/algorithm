#include <string>
#include <vector>

using namespace std;
typedef long long ll;
const int EMPTY = -1;

int deliver(int n, int cap, vector<int> &deliveries) { // 1. 가장 먼 곳부터 택배 배달하기
    int truck = 0; // 트력이 실은 상자 개수
    for(int i = n-1; i >= 0; i--) {
        if(truck + deliveries[i] <= cap) { // 1. i집 상자를 모두 배달할 수 있는 경우
            truck += deliveries[i];
            deliveries[i] = 0;
        }
        else { // 2. i집 상자를 다 배달할 수 없는 경우
            deliveries[i] -= (cap - truck); // 최대한 배달하기
            return i+1; // i+1집까지 배달 완료
        }
    }
    if(!truck) { // 트럭이 아무것도 싣지 않은 경우
        return EMPTY;
    }
    return 0; // 모든 집까지 배달 완료
}

int pickup(int n, int cap, vector<int> &pickups) { // 2. 가장 먼 곳부터 택배 수거하기
    int truck = 0; // 트럭이 실은 상자 개수
    for(int i = n-1; i >= 0; i--) {
        if(truck + pickups[i] <= cap) { // 1. i집 상자를 모두 수거할 수 있는 경우
            truck += pickups[i];
            pickups[i] = 0;
        }
        else { // 2. i집 상자를 다 수거할 수 없는 경우
            pickups[i] -= (cap - truck); // 최대한 수거하기
            return i+1; // i+1집까지 수거 완료
        }
    }
    if(!truck) { // 트럭이 아무것도 싣지 않은 경우
        return EMPTY;
    }
    return 0; // 모든 집까지 수거 완료
}

ll solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    ll answer = 0;

    while(n > 0) { // n : 가장 먼 곳
        int pos1 = deliver(n, cap, deliveries); // 가장 먼 곳부터 pos1 지점까지 배달 완료
        int pos2 = pickup(n, cap, pickups); // 가장 먼 곳부터 pos2 지점까지 수거 완료

        if(pos1 == EMPTY && pos2 == EMPTY) { // 아무것도 배달하지 않았고, 아무것도 수거하지 않은 경우, 이동할 필요가 없음
            return answer;
        }
        answer += (n*2); // 물류창고부터 n번째 집까지 왕복
        n = max(pos1, pos2); // 가장 먼 곳 갱신
    }
    return answer;
}