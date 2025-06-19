#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const char WALL = '#';
const char EMPTY = ' ';

string to_binary(int num) {
    string answer = "";

    while(num) {
        answer += to_string(num % 2);
        num /= 2;
    }
    reverse(answer.begin(), answer.end());
    return answer;
}

vector<string> make_map(int n, vector<int> arr) {
    vector<string> map (n, "");

    for(int i = 0; i < n; i++) {
        string bin = to_binary(arr[i]);

        while(bin.length() < n) {
            bin = '0' + bin;
        }
        map[i] = bin;
    }
    return map;
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer (n, "");
    vector<string> map1 = make_map(n, arr1);
    vector<string> map2 = make_map(n, arr2);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(map1[i][j] == '1' || map2[i][j] == '1') {
                answer[i] += WALL;
            }
            else {
                answer[i] += EMPTY;
            }
        }
    }
    return answer;
}