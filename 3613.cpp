#include <iostream>

using namespace std;

bool isJava(string &arg) {
    // 1. 첫문자 반드시 소문자
    // 2. 소문자, 대문자 외에 다른 문자 불가
    if(!islower(arg[0])) return false;     // (1번)
    if(arg.find('_') != string::npos) return false; // (2번)
    for(int i = 1; i < arg.length(); i++) {
        if (!isupper(arg[i]) && !islower(arg[i])) // (2번)
            return false;
    }
    return true;
}

bool isCpp(string &arg) {
    // 1. 첫문자 반드시 소문자
    // 2. 마지막 문자 _ 불가
    // 3. 연속으로 _ 불가
    if(!islower(arg[0])) return false;      // (1번)
    if(arg[arg.length()-1] == '_') return false;        // (2번)
    if(arg.find("__") != string::npos) return false; // (3번)
    for(int i = 1; i < arg.length(); i++) {
        if (!islower(arg[i]) && arg[i] != '_')
            return false;
    }
    return true;
}

string java(string &arg) { // 자바 변수명 만들기
    string temp = "";
    for(int i = 0; i < arg.length(); i++) {
        if(arg[i] == '_') {
            temp += toupper(arg[i+1]);
            i++;
            continue;
        }
        temp += arg[i];
    }
    return temp;
}

string cpp(string &arg) { // c++ 변수명 만들기
    string temp = "";
    for(char ch : arg) {
        if(ch >= 'A' && ch <= 'Z') {
            temp += '_';
            temp += tolower(ch);
            continue;
        }
        temp += ch;
    }
    return temp;
}

string makeIdentifier(string &arg) { // 변수명 만들기
    bool is_java = isJava(arg);
    bool is_cpp = isCpp(arg);

    if(!is_java && !is_cpp) return "Error!";
    if(is_java) return cpp(arg); // 자바 -> 씨쁠쁠
    else return java(arg);      // 씨쁠쁠 -> 자바
}

int main() {
    string argument;
    cin >> argument;

    cout << makeIdentifier(argument);
    return 0;
}