#include <iostream>

using namespace std;

const string ASC = "ascending";
const string DESC = "descending";
const string MIX = "mixed";

string solution(string input) {
    int pre = input[0] - '0';
    if(pre != 1 && pre != 8) {
        return MIX;
    }

    bool is_asc = pre == 1;
    for(int i = 2; i < input.length(); i += 2) {
        int curr = input[i] - '0';
        if((is_asc && curr < pre) || (!is_asc && curr > pre)) {
            return MIX;
        }
        pre = curr;
    }
    return is_asc ? ASC : DESC;
}

int main() {
    string input;

    getline(cin, input);

    cout << solution(input);
    return 0;
}