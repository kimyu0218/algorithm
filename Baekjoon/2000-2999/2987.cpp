#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct coord {
    int x, y;
};

double compute_area(coord a, coord b, coord c) {
    double sum = a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y);
    return abs(sum) / 2;
}

void solution(coord a, coord b, coord c, vector<coord> trees) {
    double area = compute_area(a, b, c);
    int cnt = 0;

    int n = trees.size();
    for(int i = 0; i < n; i++) {
        coord tree = trees[i];

        double tmp = compute_area(a, b, tree) + compute_area(b, c, tree) + compute_area(c, a, tree);
        cnt += (tmp == area);
    }

    cout << area << '\n' << cnt;
}

int main() {
    cout << fixed;
    cout.precision(1);

    int n;
    coord a, b, c;
    vector<coord> trees;

    cin >> a.x >> a.y;
    cin >> b.x >> b.y;
    cin >> c.x >> c.y;
    cin >> n;

    trees.assign(n, {0, 0});
    for(int i = 0; i < n; i++) {
        cin >> trees[i].x >> trees[i].y;
    }

    solution(a, b, c, trees);
    return 0;
}