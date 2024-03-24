#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int max_w = 0;
    int max_h = 0;

    for(int i = 0; i < sizes.size(); i++) {
        int w = max(sizes[i][0], sizes[i][1]);
        int h = min(sizes[i][0], sizes[i][1]);
        max_w = max(max_w, w);
        max_h = max(max_h, h);
    }
    return max_w * max_h;
}