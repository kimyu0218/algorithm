#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> get_positive(int n, vector<int> books) {
    vector<int> result;
    for(int i = n - 1; i >= 0; i--) {
        if(books[i] < 0) {
            break;
        }
        result.push_back(books[i]);
    }
    sort(result.begin(), result.end(), greater<>());
    return result;
}

vector<int> get_negative(int n, vector<int> books) {
    vector<int> result;
    for(int i = 0; i < n; i++) {
        if(books[i] > 0) {
            break;
        }
        result.push_back(abs(books[i]));
    }
    sort(result.begin(), result.end(), greater<>());
    return result;
}

vector<int> get_dist(int m, vector<int> arr) {
    vector<int> result;

    int idx = 0;
    int n = arr.size();

    while(idx + m < n) {
        result.push_back(arr[idx]);
        idx += m;
    }
    if(idx < n) {
        result.push_back(arr[idx]);
    }
    return result;
}

int solution(int m, vector<int> books) {
    int result = 0;

    sort(books.begin(), books.end());

    int n = books.size();
    vector<int> positive = get_dist(m, get_positive(n, books));
    vector<int> negative = get_dist(m, get_negative(n, books));

    vector<int> dist;
    for(int i = 0; i < positive.size(); i++) {
        dist.push_back(positive[i]);
    }
    for(int i = 0; i < negative.size(); i++) {
        dist.push_back(negative[i]);
    }

    sort(dist.begin(), dist.end());

    int last_idx = dist.size() - 1;
    for(int i = 0; i < last_idx; i++) {
        result += dist[i] * 2;
    }
    return result + dist[last_idx];
}

int main() {
    int n, m;
    vector<int> books;

    cin >> n >> m;

    books.assign(n, 0);
    for(int i = 0; i < n; i++) {
        cin >> books[i];
    }

    cout << solution(m, books);
    return 0;
}