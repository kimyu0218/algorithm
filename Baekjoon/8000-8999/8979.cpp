#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct info {
    int num, gold, silver, bronze;
};

bool cmp(info &i1, info &i2) {
    if(i1.gold != i2.gold) {
        return i1.gold > i2.gold;
    }
    if(i1.silver != i2.silver) {
        return i1.silver > i2.silver;
    }
    return i1.bronze > i2.bronze;
}

int solution(int k, vector<info> nation) {
    sort(nation.begin(), nation.end(), cmp);

    if(k == nation[0].num) {
        return 1;
    }

    int answer = 1;
    int n = nation.size();

    for(int i = 1; i < n; i++) {
        if(nation[i].gold != nation[i - 1].gold
           || nation[i].silver != nation[i - 1].silver
           || nation[i].bronze != nation[i - 1].bronze) {
            answer = i + 1;
        }
        if(k == nation[i].num) {
            break;
        }
    }
    return answer;
}

int main() {
    int n, k;
    vector<info> nation;

    cin >> n >> k;

    nation.assign(n, {0, 0, 0, 0});
    for(int i = 0; i < n; i++) {
        cin >> nation[i].num >> nation[i].gold >> nation[i].silver >> nation[i].bronze;
    }

    cout << solution(k, nation);
    return 0;
}