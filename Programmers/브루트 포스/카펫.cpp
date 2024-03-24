#include <string>
#include <vector>

using namespace std;

const int MAX = 5 * 1e3;

vector<int> solution(int brown, int yellow) {
    int sum = brown + yellow;

    for(int h = 3; h <= MAX; h++) {
        int w = sum / h;
        if(sum != w * h) {
            continue;
        }

        int b = (w + h) * 2 - 4;
        if(b == brown) {
            return {w, h};
        }
    }
}