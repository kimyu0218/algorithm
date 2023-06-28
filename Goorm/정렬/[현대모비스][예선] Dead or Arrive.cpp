#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct info {
    int num, v, w;
};

bool cmp(const info &i1, const info &i2) {
    if(i1.v != i2.v) { // 1. 속도 빠른 순
        return i1.v > i2.v;
    }
    if(i1.w != i2.w) { // 2. 내구도 강한 순
        return i1.w > i2.w;
    }
    return i1.num > i2.num; // 3. 차량 번호가 큰 순
}

int sumOfAlive(int n, vector<info> &cars) {
    int sum = 0;
    for(int i = 0; i < n;) {
        sum += cars[i].num;
        int v = cars[i].v;
        while(cars[i].v == v) {
            i++;
        }
    }
    return sum;
}
int main() {
    int n, v ,w;
    vector<info> cars;

    cin >> n;
    cars.assign(n, {});
    for(int i = 0; i < n; i++) { // v & w 입력
        cin >> v >> w;
        cars[i] = {i+1, v, w};
    }

    sort(cars.begin(), cars.end(), cmp);

    cout << sumOfAlive(n, cars);
    return 0;
}