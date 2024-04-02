#include <string>
#include <vector>

using namespace std;

int dfs(int idx, int sum, int target, vector<int> numbers) {
    if(idx == numbers.size()) {
        return (sum == target);
    }
    int num = numbers[idx];
    return dfs(idx + 1, sum + num, target, numbers) + dfs(idx + 1, sum - num, target, numbers);
}

int solution(vector<int> numbers, int target) {
    return dfs(0, 0, target, numbers);
}