#include <iostream>

using namespace std;

typedef long long ll;

int gcd(int a, int b) { // 최대 공약수 구하기
    while(b > 0) {
        int c = a % b;
        a = b;
        b = c;
    }
    return a;
}

ll solution(int w,int h) {
    if(w == h) { // 1. 가로 세로 길이가 같은 경우
        return (ll) w * h - w;
    }
    // 2. 가로 세로 길이가 다른 경우
    int g = gcd(max(w, h), min(w, h));
    return (ll) w * h - (w/g + h/g - 1) * g;
}