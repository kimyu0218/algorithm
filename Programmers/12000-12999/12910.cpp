#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr, int divisor) {
    vector<int> answer;
    int n = arr.size();

    for(int i = 0; i < n; i++) {
        if(arr[i] % divisor == 0) {
            answer.push_back(arr[i]);
        }
    }
    sort(answer.begin(), answer.end());
    if(answer.size() == 0) {
        return { -1 };
    }
    return answer;
}