#include <iostream>
#include <string>

using namespace std;

bool is_java(string s) {
    if(!islower(s[0])) return false; // 1. 첫 문자는 소문자
    // 2. 소문자, 대문자만 가능
    if(s.find('_') != string::npos) return false;
    for(int i = 1; i < s.length()-1; i++) {
        if(!islower(s[i]) && !isupper(s[i])) return false;
    }
    return true;
}

bool is_cpp(string s) {
    if(!islower(s[0])) return false; // 1. 첫 문자는 소문자
    if(s[s.length()-1] == '_') return false; // 2. 끝 문자 소문자만 가능
    if(s.find("__") != string::npos) return false; // 3. 연속된 _ 불가능
    for(int i = 1; i < s.length(); i++) { // 4. 첫 문자, 끝 문자 제외 소문자나 _만 가능
        if(!islower(s[i]) && s[i] != '_') return false;
    }
    return true;
}

string java_to_cpp(string s) { // java (camel code) -> cpp (snake code)
    string result = "";
    for(int i = 0; i < s.length(); i++) {
        if(isupper(s[i])) {
            result += '_';
            result += tolower(s[i]);
        }
        else result += s[i];
    }
    return result;
}

string cpp_to_java(string s) { // cpp (snake code) -> java (camel code)
    string result = "";
    for(int i = 0; i < s.length(); i++) {
        if(s[i] == '_') {
            result += toupper(s[++i]);
        }
        else result += s[i];
    }
    return result;
}

int main() {
    string s;
    cin >> s;

    bool java = is_java(s), cpp = is_cpp(s);
    if(!java && !cpp) cout << "Error!";
    else if(java) cout << java_to_cpp(s);
    else if(cpp) cout << cpp_to_java(s);
    return 0;
}