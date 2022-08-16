#include <iostream>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";

    int len = number.length(), start = 0;
    for(int i = 1; i <= len-k; i++) {
        if(number[start] < number[i])
            start = i;
    }

    return answer;
}

int main() {
    // 예제 1
    /*string number = "1924";
    int k = 2;*/

    // 예제 2
    /*string number = "1231234";
    int k = 3;*/

    // 예제 3
    string number = "4177252841";
    int k = 4;

    cout << solution(number, k);
    return 0;
}