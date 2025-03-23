#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int N = 50;
const int K = 50;
const int INF = 1e2 * 5;

double matrix[N][N];
double weights[N][K];

struct info {
    double w;
    int v, k;
};

struct cmp {
    bool operator() (info &i1, info &i2) {
        if(i1.w != i2.w) {
            return i1.w > i2.w;
        }
        return true;
    }
};

void initialize(int n, int k) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= k; j++) {
            weights[i][j] = INF;
        }
    }
}

double dijkstra(int n, int k) {
    double answer = INF;
    priority_queue<info, vector<info>, cmp> pq;

    weights[0][0] = 0;
    pq.push({0, 0, 0});

    while(!pq.empty()) {
        double w = pq.top().w;
        int v = pq.top().v;
        int curr_k = pq.top().k;
        pq.pop();

        if(v == 1) {
            answer = min(answer, w);
            continue;
        }
        if(w > weights[v][curr_k]) {
            continue;
        }

        for(int i = 0; i < n; i++) {
            if(v == i) {
                continue;
            }
            double next_w = matrix[v][i];
            double w1 = w + next_w / 2;
            double w2 = w + next_w;
            if(curr_k < k && weights[i][curr_k + 1] > w1) {
                weights[i][curr_k + 1] = w1;
                pq.push({w1, i, curr_k + 1});
            }
            if(weights[i][curr_k] > w2) {
                weights[i][curr_k] = w2;
                pq.push({w2, i, curr_k});
            }
        }
    }
    return answer;
}

double solution(int n, int k) {
    initialize(n, k);
    return dijkstra(n, k);
}

int main() {
    cout << fixed;
    cout.precision(1);

    int n, k;
    string input;

    cin >> n >> k;

    for(int i = 0; i < n; i++) {
        cin >> input;
        for(int j = 0; j < n; j++) {
            matrix[i][j] = input[j] - '0';
        }
    }

    cout << solution(n, k);
    return 0;
}