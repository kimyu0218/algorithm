#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = 0, n = A.size();
    sort(A.begin(), A.end()); // A 오름차순 정렬
    sort(B.begin(), B.end()); // B 오름차순 정렬

    int idx = 0; // idx : B팀의 수를 가리키는 인덱스
    for(int i = 0; i < n; i++) { // i : A팀의 수를 가리킴
        if(idx == n) { // idx가 n이라는 것은 A[i]를 이길 수 있는 수가 없다는 의미
            break;
        }
        // B팀이 이길 수 있을 때까지(A[i]보다 큰 수를 발견할 때까지) 큰 수를 가진 선수 탐색
        while(A[i] >= B[idx] && idx < n) {
            idx++;
        }
        if(idx < n) { // A팀을 이길 수 있는 경우
            answer++; // 승점 확보
            idx++; // idx 팀원은 A[i] < B[idx]를 이기는 데 사용했기 때문에 다른 선수 출전하도록 증가
        }
    }
    return answer;
}