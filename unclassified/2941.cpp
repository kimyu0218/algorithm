#include <iostream>
#include <queue>
#include <string>

using namespace std;

int howMany(string str) { // 크로아티아 알파벳 개수 세기
    queue<string> croatia; // 크로아티아 알파벳 저장하는 큐

    queue<string> q; // 입력한 문자열의 문자 저장하는 큐
    for(int i = 0; i < str.length(); i++) {
        string tmp; tmp += str[i];
        q.push(tmp);
    }

    while(!q.empty()) {
        string tmp = q.front(); q.pop(); // 현재 문자
        if(tmp == "c" && !q.empty()) {
            if(q.front() == "=" || q.front() == "-") { // "c=" or "c-"
                tmp += q.front();
                croatia.push(tmp);
                q.pop();
            }
            else croatia.push(tmp);
        }
        else if(tmp == "d" && !q.empty()) {
            if(q.front() == "-") { // "d-"
                tmp += q.front();
                croatia.push(tmp);
                q.pop();
            }
            else if(q.front() == "z") {
                string tmp2 = q.front(); q.pop();
                if(!q.empty()) {
                    if(q.front() == "=") { // "dz="
                        tmp += (tmp2 + q.front());
                        croatia.push(tmp);
                        q.pop();
                    }
                    else {
                        croatia.push(tmp);
                        croatia.push(tmp2);
                    }
                }
                else {
                    croatia.push(tmp);
                    croatia.push(tmp2);
                }
            }
            else croatia.push(tmp);
        }
        else if((tmp == "n" || tmp == "l") && !q.empty()) {
            if(q.front() == "j") { // "nj" or "lj"
                tmp += q.front();
                croatia.push(tmp);
                q.pop();
            }
            else croatia.push(tmp);
        }
        else if((tmp == "s" || tmp == "z") && !q.empty()) {
            if(q.front() == "=") { // "s=" or "z="
                tmp += q.front();
                croatia.push(tmp);
                q.pop();
            }
            else croatia.push(tmp);
        }
        else croatia.push(tmp);
    }
    return croatia.size(); // 크로아티아 알파벳 개수 반환
}

int main() {
    string str;
    cin >> str;

    cout << howMany(str);
    return 0;
}