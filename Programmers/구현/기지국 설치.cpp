#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int solution(int n, vector<int> stations, int w)
{
    // n : 아파트 개수
    // stations : 기지국의 위치
    // w : 전파 도달 거리 (양쪽으로 w만큼)
    int answer = 0, start = 1;
    int s = stations.size(), cover = 2*w+1;

    for(int i = 0; i < s; i++) {
        int end = stations[i]-w;
        answer += ceil((float) (end - start) / cover);

        start = stations[i]+w+1;
        if(start > n) { // 모든 아파트에 전달 완료 -> 바로 답 리턴
            return answer;
        }
    }

    answer += ceil((float)(n+1 - start) / cover);
    return answer;
}