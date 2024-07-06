#include <iostream>

using namespace std;

typedef long long ll;

int gcd(int a, int b) {
    while(b > 0) {
        int c = a % b;
        a = b;
        b = c;
    }
    return a;
}

ll solution(int w,int h) {
    if(w == h) {
        return (ll) w * h - w;
    }
    int g = gcd(max(w, h), min(w, h));
    return (ll) w * h - (w/g + h/g - 1) * g;
}