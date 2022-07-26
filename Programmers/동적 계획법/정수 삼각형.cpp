#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;

    int size = triangle.size();
    int dp[size][size]; dp[0][0] = triangle[0][0]; // 정수 삼각형 합 저장하는 배열

    for(int i = 1; i < size; i++) { // (i행)
        dp[i][0] = dp[i-1][0] + triangle[i][0]; // (0번째 열은 우상향 대각선 값만 받아옴)
        for(int j = 1; j < i; j++)
            dp[i][j] = max(dp[i-1][j-1], dp[i-1][j]) + triangle[i][j]; // 좌상향, 우상향 중 큰 값 가져옴
        dp[i][i] = dp[i-1][i-1] + triangle[i][i]; // (i번째 열은 좌상향 대각선 값만 받아옴)
    }

    for(int i = 0; i < size; i++)
        answer = max(answer, dp[size-1][i]);
    return answer;
}